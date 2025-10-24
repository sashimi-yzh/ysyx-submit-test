// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbooth_wallace_multiplier__Syms.h"


void Vbooth_wallace_multiplier___024root__trace_chg_sub_1(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root__trace_chg_sub_1\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 2392);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 0xdU) 
                                     & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1bU] >> 0xcU)) 
                                    | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 0xcU) 
                                        | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 0xdU)) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 0xbU))))));
        bufp->chgBit(oldp+1,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xdU))));
        bufp->chgBit(oldp+3,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xcU))));
        bufp->chgBit(oldp+4,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xbU))));
        bufp->chgCData(oldp+5,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] >> 8U))),3);
        bufp->chgBit(oldp+6,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
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
        bufp->chgBit(oldp+7,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+8,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 0xaU))));
        bufp->chgBit(oldp+9,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x1bU] >> 9U))));
        bufp->chgBit(oldp+10,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 8U))));
        bufp->chgCData(oldp+11,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] >> 5U))),3);
        bufp->chgBit(oldp+12,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] >> 7U) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 6U)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 6U) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1bU] 
                                            >> 7U)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 5U))))));
        bufp->chgBit(oldp+13,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+14,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 7U))));
        bufp->chgBit(oldp+15,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 6U))));
        bufp->chgBit(oldp+16,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 5U))));
        bufp->chgCData(oldp+17,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] >> 2U))),3);
        bufp->chgBit(oldp+18,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] >> 4U) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 3U)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 3U) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1bU] 
                                            >> 4U)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 2U))))));
        bufp->chgBit(oldp+19,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+20,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 4U))));
        bufp->chgBit(oldp+21,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 3U))));
        bufp->chgBit(oldp+22,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 2U))));
        bufp->chgCData(oldp+23,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+24,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s)) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+26,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s) 
                                             << 1U) 
                                            | (1U & 
                                               (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                [0x1bU] 
                                                >> 1U))))),3);
        bufp->chgBit(oldp+27,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s)) 
                                  & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 1U)))));
        bufp->chgBit(oldp+28,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+29,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1bU] >> 1U))));
        bufp->chgCData(oldp+30,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1bU] << 2U)) 
                                 | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                          >> 3U)))),3);
        bufp->chgBit(oldp+31,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1bU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                 >> 4U)) 
                                     | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                          >> 4U) | 
                                         vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU]) & 
                                        ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                         >> 3U))))));
        bufp->chgBit(oldp+32,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+33,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x1bU])));
        bufp->chgBit(oldp+34,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 4U))));
        bufp->chgBit(oldp+35,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 3U))));
        bufp->chgCData(oldp+36,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+37,((1U & ((IData)((6U == 
                                              (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                     | ((IData)((0U 
                                                 != 
                                                 (6U 
                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+38,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+39,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 2U))));
        bufp->chgBit(oldp+40,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 1U))));
        bufp->chgBit(oldp+41,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+42,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+43,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s)) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+44,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+45,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s) 
                                  << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                  >> 5U)))),3);
        bufp->chgBit(oldp+46,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s) 
                                      & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                         >> 6U)) | 
                                     ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                        >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s)) 
                                      & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                         >> 5U))))));
        bufp->chgBit(oldp+47,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+48,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 6U))));
        bufp->chgBit(oldp+49,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 5U))));
        bufp->chgCData(oldp+50,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s) 
                                             << 1U) 
                                            | (1U & 
                                               ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                >> 0xaU))))),3);
        bufp->chgBit(oldp+51,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s)) 
                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 0xaU)))));
        bufp->chgBit(oldp+52,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+53,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 0xaU))));
        bufp->chgCData(oldp+54,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                       >> 7U))),3);
        bufp->chgBit(oldp+55,((1U & ((IData)((0x300U 
                                              == (0x300U 
                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                     | ((IData)((0U 
                                                 != 
                                                 (0x300U 
                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                           >> 7U))))));
        bufp->chgBit(oldp+56,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+57,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 9U))));
        bufp->chgBit(oldp+58,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 8U))));
        bufp->chgBit(oldp+59,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 7U))));
        bufp->chgCData(oldp+60,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s) 
                                             << 1U) 
                                            | (1U & 
                                               ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                >> 0xbU))))),3);
        bufp->chgBit(oldp+61,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s)) 
                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 0xbU)))));
        bufp->chgBit(oldp+62,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 0xbU))));
        bufp->chgCData(oldp+63,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s) 
                                  << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                  >> 0xcU)))),3);
        bufp->chgBit(oldp+64,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 0xdU))));
        bufp->chgBit(oldp+65,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                     >> 0xcU))));
        bufp->chgIData(oldp+66,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x1cU]),17);
        bufp->chgSData(oldp+67,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+68,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout));
        bufp->chgBit(oldp+69,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                     ^ VL_REDXOR_16(
                                                    (0x3000U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+70,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 3U) 
                                            | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s) 
                                                << 2U) 
                                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+71,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                                  << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                             << 2U) 
                                            | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s) 
                                                << 1U) 
                                               | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+72,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                                  << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+73,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                                  << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+74,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+75,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 0xeU))),3);
        bufp->chgBit(oldp+76,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 0x10U) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 0xfU)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 0xfU) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1cU] 
                                            >> 0x10U)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0xeU))))));
        bufp->chgBit(oldp+77,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+78,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 0x10U))));
        bufp->chgBit(oldp+79,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 0xfU))));
        bufp->chgBit(oldp+80,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 0xeU))));
        bufp->chgCData(oldp+81,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 0xbU))),3);
        bufp->chgBit(oldp+82,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 0xdU) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 0xcU)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 0xcU) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1cU] 
                                            >> 0xdU)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 0xbU))))));
        bufp->chgBit(oldp+83,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+84,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 0xdU))));
        bufp->chgBit(oldp+85,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 0xcU))));
        bufp->chgBit(oldp+86,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 0xbU))));
        bufp->chgCData(oldp+87,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 8U))),3);
        bufp->chgBit(oldp+88,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 0xaU) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 9U)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 9U) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1cU] 
                                            >> 0xaU)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 8U))))));
        bufp->chgBit(oldp+89,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+90,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 0xaU))));
        bufp->chgBit(oldp+91,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 9U))));
        bufp->chgBit(oldp+92,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 8U))));
        bufp->chgCData(oldp+93,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 5U))),3);
        bufp->chgBit(oldp+94,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 7U) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] >> 6U)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 6U) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1cU] 
                                            >> 7U)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 5U))))));
        bufp->chgBit(oldp+95,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+96,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 7U))));
        bufp->chgBit(oldp+97,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 6U))));
        bufp->chgBit(oldp+98,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x1cU] >> 5U))));
        bufp->chgCData(oldp+99,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] >> 2U))),3);
        bufp->chgBit(oldp+100,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1cU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1cU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1cU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+101,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+102,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 4U))));
        bufp->chgBit(oldp+103,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 3U))));
        bufp->chgBit(oldp+104,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 2U))));
        bufp->chgCData(oldp+105,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+106,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+107,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+108,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x1cU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+109,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 1U)))));
        bufp->chgBit(oldp+110,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+111,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1cU] >> 1U))));
        bufp->chgCData(oldp+112,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+113,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1cU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+114,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+115,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x1cU])));
        bufp->chgBit(oldp+116,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+117,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+118,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+119,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+120,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+121,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+122,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+123,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+124,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+125,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+126,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+127,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+128,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+129,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+130,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+131,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+132,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+133,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+134,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+135,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+136,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+137,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+138,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+139,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+140,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+141,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+142,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+143,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+144,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+145,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+146,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+147,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+148,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x1dU]),17);
        bufp->chgSData(oldp+149,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+150,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout));
        bufp->chgBit(oldp+151,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+152,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+153,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+154,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+155,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+156,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+157,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 0xeU))),3);
        bufp->chgBit(oldp+158,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1dU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1dU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+159,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+160,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0x10U))));
        bufp->chgBit(oldp+161,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xfU))));
        bufp->chgBit(oldp+162,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xeU))));
        bufp->chgCData(oldp+163,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 0xbU))),3);
        bufp->chgBit(oldp+164,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1dU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1dU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+165,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+166,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xdU))));
        bufp->chgBit(oldp+167,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xcU))));
        bufp->chgBit(oldp+168,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xbU))));
        bufp->chgCData(oldp+169,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 8U))),3);
        bufp->chgBit(oldp+170,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1dU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+171,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+172,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 0xaU))));
        bufp->chgBit(oldp+173,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 9U))));
        bufp->chgBit(oldp+174,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 8U))));
        bufp->chgCData(oldp+175,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 5U))),3);
        bufp->chgBit(oldp+176,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1dU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+177,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+178,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 7U))));
        bufp->chgBit(oldp+179,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 6U))));
        bufp->chgBit(oldp+180,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 5U))));
        bufp->chgCData(oldp+181,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 2U))),3);
        bufp->chgBit(oldp+182,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1dU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1dU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1dU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+183,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+184,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 4U))));
        bufp->chgBit(oldp+185,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 3U))));
        bufp->chgBit(oldp+186,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 2U))));
        bufp->chgCData(oldp+187,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+188,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+189,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+190,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x1dU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+191,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 1U)))));
        bufp->chgBit(oldp+192,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+193,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1dU] >> 1U))));
        bufp->chgCData(oldp+194,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1dU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+195,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1dU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+196,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+197,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x1dU])));
        bufp->chgBit(oldp+198,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+199,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+200,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+201,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+202,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+203,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+204,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+205,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+206,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+207,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+208,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+209,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+210,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+211,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+212,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+213,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+214,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+215,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+216,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+217,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+218,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+219,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+220,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+221,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+222,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+223,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+224,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+225,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+226,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+227,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+228,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+229,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+230,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x1eU]),17);
        bufp->chgSData(oldp+231,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+232,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout));
        bufp->chgBit(oldp+233,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+234,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+235,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+236,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+237,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+238,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+239,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 0xeU))),3);
        bufp->chgBit(oldp+240,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1eU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1eU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+241,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+242,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0x10U))));
        bufp->chgBit(oldp+243,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xfU))));
        bufp->chgBit(oldp+244,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xeU))));
        bufp->chgCData(oldp+245,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 0xbU))),3);
        bufp->chgBit(oldp+246,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1eU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1eU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+247,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+248,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xdU))));
        bufp->chgBit(oldp+249,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xcU))));
        bufp->chgBit(oldp+250,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xbU))));
        bufp->chgCData(oldp+251,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 8U))),3);
        bufp->chgBit(oldp+252,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1eU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+253,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+254,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 0xaU))));
        bufp->chgBit(oldp+255,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 9U))));
        bufp->chgBit(oldp+256,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 8U))));
        bufp->chgCData(oldp+257,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 5U))),3);
        bufp->chgBit(oldp+258,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1eU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+259,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+260,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 7U))));
        bufp->chgBit(oldp+261,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 6U))));
        bufp->chgBit(oldp+262,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 5U))));
        bufp->chgCData(oldp+263,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 2U))),3);
        bufp->chgBit(oldp+264,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1eU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1eU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1eU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+265,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+266,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 4U))));
        bufp->chgBit(oldp+267,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 3U))));
        bufp->chgBit(oldp+268,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 2U))));
        bufp->chgCData(oldp+269,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+270,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+271,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+272,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x1eU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+273,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 1U)))));
        bufp->chgBit(oldp+274,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+275,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1eU] >> 1U))));
        bufp->chgCData(oldp+276,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1eU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+277,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1eU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+278,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+279,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x1eU])));
        bufp->chgBit(oldp+280,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+281,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+282,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+283,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+284,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+285,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+286,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+287,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+288,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+289,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+290,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+291,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+292,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+293,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+294,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+295,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+296,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+297,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+298,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+299,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+300,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+301,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+302,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+303,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+304,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+305,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+306,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+307,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+308,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+309,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+310,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+311,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+312,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x1fU]),17);
        bufp->chgSData(oldp+313,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+314,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout));
        bufp->chgBit(oldp+315,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+316,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+317,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+318,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+319,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+320,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+321,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 0xeU))),3);
        bufp->chgBit(oldp+322,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1fU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1fU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+323,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+324,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0x10U))));
        bufp->chgBit(oldp+325,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xfU))));
        bufp->chgBit(oldp+326,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xeU))));
        bufp->chgCData(oldp+327,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 0xbU))),3);
        bufp->chgBit(oldp+328,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1fU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1fU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+329,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+330,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xdU))));
        bufp->chgBit(oldp+331,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xcU))));
        bufp->chgBit(oldp+332,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xbU))));
        bufp->chgCData(oldp+333,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 8U))),3);
        bufp->chgBit(oldp+334,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1fU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+335,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+336,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 0xaU))));
        bufp->chgBit(oldp+337,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 9U))));
        bufp->chgBit(oldp+338,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 8U))));
        bufp->chgCData(oldp+339,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 5U))),3);
        bufp->chgBit(oldp+340,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1fU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+341,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+342,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 7U))));
        bufp->chgBit(oldp+343,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 6U))));
        bufp->chgBit(oldp+344,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 5U))));
        bufp->chgCData(oldp+345,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 2U))),3);
        bufp->chgBit(oldp+346,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1fU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1fU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1fU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+347,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+348,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 4U))));
        bufp->chgBit(oldp+349,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 3U))));
        bufp->chgBit(oldp+350,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 2U))));
        bufp->chgCData(oldp+351,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+352,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+353,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+354,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x1fU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+355,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 1U)))));
        bufp->chgBit(oldp+356,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+357,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x1fU] >> 1U))));
        bufp->chgCData(oldp+358,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1fU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+359,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1fU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+360,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+361,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x1fU])));
        bufp->chgBit(oldp+362,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+363,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+364,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+365,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+366,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+367,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+368,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+369,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+370,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+371,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+372,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+373,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+374,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+375,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+376,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+377,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+378,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+379,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+380,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+381,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+382,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+383,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+384,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+385,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+386,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+387,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+388,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+389,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+390,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+391,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+392,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+393,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+394,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x20U]),17);
        bufp->chgSData(oldp+395,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+396,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout));
        bufp->chgBit(oldp+397,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+398,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+399,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+400,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+401,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+402,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+403,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 0xeU))),3);
        bufp->chgBit(oldp+404,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x20U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x20U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+405,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+406,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0x10U))));
        bufp->chgBit(oldp+407,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xfU))));
        bufp->chgBit(oldp+408,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xeU))));
        bufp->chgCData(oldp+409,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 0xbU))),3);
        bufp->chgBit(oldp+410,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x20U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x20U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+411,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+412,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xdU))));
        bufp->chgBit(oldp+413,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xcU))));
        bufp->chgBit(oldp+414,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xbU))));
        bufp->chgCData(oldp+415,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 8U))),3);
        bufp->chgBit(oldp+416,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x20U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+417,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+418,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 0xaU))));
        bufp->chgBit(oldp+419,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 9U))));
        bufp->chgBit(oldp+420,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 8U))));
        bufp->chgCData(oldp+421,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 5U))),3);
        bufp->chgBit(oldp+422,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x20U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+423,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+424,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 7U))));
        bufp->chgBit(oldp+425,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 6U))));
        bufp->chgBit(oldp+426,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 5U))));
        bufp->chgCData(oldp+427,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 2U))),3);
        bufp->chgBit(oldp+428,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x20U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x20U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x20U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+429,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+430,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 4U))));
        bufp->chgBit(oldp+431,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 3U))));
        bufp->chgBit(oldp+432,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 2U))));
        bufp->chgCData(oldp+433,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+434,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+435,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+436,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x20U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+437,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 1U)))));
        bufp->chgBit(oldp+438,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+439,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x20U] >> 1U))));
        bufp->chgCData(oldp+440,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x20U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+441,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x20U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+442,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+443,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x20U])));
        bufp->chgBit(oldp+444,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+445,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+446,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+447,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+448,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+449,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+450,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+451,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+452,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+453,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+454,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+455,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+456,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+457,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+458,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+459,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+460,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+461,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+462,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+463,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+464,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+465,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+466,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+467,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+468,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+469,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+470,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+471,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+472,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+473,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+474,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+475,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+476,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x21U]),17);
        bufp->chgSData(oldp+477,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+478,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout));
        bufp->chgBit(oldp+479,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+480,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+481,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+482,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+483,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+484,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+485,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 0xeU))),3);
        bufp->chgBit(oldp+486,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x21U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x21U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+487,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+488,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0x10U))));
        bufp->chgBit(oldp+489,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xfU))));
        bufp->chgBit(oldp+490,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xeU))));
        bufp->chgCData(oldp+491,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 0xbU))),3);
        bufp->chgBit(oldp+492,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x21U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x21U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+493,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+494,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xdU))));
        bufp->chgBit(oldp+495,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xcU))));
        bufp->chgBit(oldp+496,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xbU))));
        bufp->chgCData(oldp+497,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 8U))),3);
        bufp->chgBit(oldp+498,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x21U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+499,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+500,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 0xaU))));
        bufp->chgBit(oldp+501,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 9U))));
        bufp->chgBit(oldp+502,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 8U))));
        bufp->chgCData(oldp+503,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 5U))),3);
        bufp->chgBit(oldp+504,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x21U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+505,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+506,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 7U))));
        bufp->chgBit(oldp+507,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 6U))));
        bufp->chgBit(oldp+508,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 5U))));
        bufp->chgCData(oldp+509,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 2U))),3);
        bufp->chgBit(oldp+510,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x21U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x21U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x21U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+511,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+512,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 4U))));
        bufp->chgBit(oldp+513,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 3U))));
        bufp->chgBit(oldp+514,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 2U))));
        bufp->chgCData(oldp+515,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+516,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+517,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+518,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x21U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+519,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 1U)))));
        bufp->chgBit(oldp+520,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+521,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x21U] >> 1U))));
        bufp->chgCData(oldp+522,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x21U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+523,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x21U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+524,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+525,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x21U])));
        bufp->chgBit(oldp+526,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+527,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+528,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+529,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+530,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+531,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+532,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+533,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+534,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+535,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+536,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+537,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+538,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+539,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+540,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+541,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+542,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+543,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+544,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+545,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+546,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+547,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+548,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+549,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+550,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+551,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+552,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+553,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+554,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+555,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+556,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+557,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+558,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x22U]),17);
        bufp->chgSData(oldp+559,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+560,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout));
        bufp->chgBit(oldp+561,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+562,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+563,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+564,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+565,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+566,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+567,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 0xeU))),3);
        bufp->chgBit(oldp+568,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x22U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x22U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+569,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+570,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0x10U))));
        bufp->chgBit(oldp+571,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xfU))));
        bufp->chgBit(oldp+572,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xeU))));
        bufp->chgCData(oldp+573,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 0xbU))),3);
        bufp->chgBit(oldp+574,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x22U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x22U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+575,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+576,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xdU))));
        bufp->chgBit(oldp+577,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xcU))));
        bufp->chgBit(oldp+578,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xbU))));
        bufp->chgCData(oldp+579,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 8U))),3);
        bufp->chgBit(oldp+580,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x22U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+581,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+582,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 0xaU))));
        bufp->chgBit(oldp+583,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 9U))));
        bufp->chgBit(oldp+584,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 8U))));
        bufp->chgCData(oldp+585,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 5U))),3);
        bufp->chgBit(oldp+586,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x22U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+587,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+588,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 7U))));
        bufp->chgBit(oldp+589,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 6U))));
        bufp->chgBit(oldp+590,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 5U))));
        bufp->chgCData(oldp+591,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 2U))),3);
        bufp->chgBit(oldp+592,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x22U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x22U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x22U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+594,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 4U))));
        bufp->chgBit(oldp+595,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 3U))));
        bufp->chgBit(oldp+596,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 2U))));
        bufp->chgCData(oldp+597,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+598,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+599,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+600,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x22U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+601,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 1U)))));
        bufp->chgBit(oldp+602,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+603,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x22U] >> 1U))));
        bufp->chgCData(oldp+604,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x22U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+605,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x22U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+606,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+607,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x22U])));
        bufp->chgBit(oldp+608,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+609,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+610,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+611,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+612,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+613,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+614,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+615,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+616,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+617,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+618,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+619,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+620,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+621,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+622,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+623,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+624,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+625,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+626,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+627,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+628,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+629,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+630,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+631,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+632,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+633,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+634,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+635,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+636,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+637,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+638,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+639,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+640,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x23U]),17);
        bufp->chgSData(oldp+641,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+642,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout));
        bufp->chgBit(oldp+643,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+644,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+645,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+646,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+647,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+648,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+649,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 0xeU))),3);
        bufp->chgBit(oldp+650,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x23U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x23U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+651,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+652,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0x10U))));
        bufp->chgBit(oldp+653,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xfU))));
        bufp->chgBit(oldp+654,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xeU))));
        bufp->chgCData(oldp+655,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 0xbU))),3);
        bufp->chgBit(oldp+656,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x23U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x23U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+657,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+658,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xdU))));
        bufp->chgBit(oldp+659,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xcU))));
        bufp->chgBit(oldp+660,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xbU))));
        bufp->chgCData(oldp+661,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 8U))),3);
        bufp->chgBit(oldp+662,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x23U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+663,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+664,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 0xaU))));
        bufp->chgBit(oldp+665,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 9U))));
        bufp->chgBit(oldp+666,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 8U))));
        bufp->chgCData(oldp+667,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 5U))),3);
        bufp->chgBit(oldp+668,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x23U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+669,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+670,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 7U))));
        bufp->chgBit(oldp+671,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 6U))));
        bufp->chgBit(oldp+672,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 5U))));
        bufp->chgCData(oldp+673,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 2U))),3);
        bufp->chgBit(oldp+674,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x23U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x23U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x23U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+675,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+676,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 4U))));
        bufp->chgBit(oldp+677,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 3U))));
        bufp->chgBit(oldp+678,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 2U))));
        bufp->chgCData(oldp+679,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+680,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+681,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+682,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x23U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+683,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 1U)))));
        bufp->chgBit(oldp+684,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+685,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x23U] >> 1U))));
        bufp->chgCData(oldp+686,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x23U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+687,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x23U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+688,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+689,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x23U])));
        bufp->chgBit(oldp+690,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+691,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+692,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+693,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+694,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+695,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+696,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+697,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+698,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+699,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+700,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+701,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+702,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+703,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+704,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+705,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+706,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+707,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+708,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+709,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+710,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+711,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+712,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+713,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+714,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+715,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+716,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+717,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+718,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+719,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+720,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+721,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+722,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x24U]),17);
        bufp->chgSData(oldp+723,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+724,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout));
        bufp->chgBit(oldp+725,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+726,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+727,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+728,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+729,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+730,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+731,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 0xeU))),3);
        bufp->chgBit(oldp+732,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x24U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x24U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+733,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+734,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0x10U))));
        bufp->chgBit(oldp+735,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xfU))));
        bufp->chgBit(oldp+736,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xeU))));
        bufp->chgCData(oldp+737,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 0xbU))),3);
        bufp->chgBit(oldp+738,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x24U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x24U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+739,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+740,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xdU))));
        bufp->chgBit(oldp+741,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xcU))));
        bufp->chgBit(oldp+742,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xbU))));
        bufp->chgCData(oldp+743,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 8U))),3);
        bufp->chgBit(oldp+744,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x24U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+745,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+746,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 0xaU))));
        bufp->chgBit(oldp+747,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 9U))));
        bufp->chgBit(oldp+748,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 8U))));
        bufp->chgCData(oldp+749,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 5U))),3);
        bufp->chgBit(oldp+750,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x24U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+751,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+752,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 7U))));
        bufp->chgBit(oldp+753,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 6U))));
        bufp->chgBit(oldp+754,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 5U))));
        bufp->chgCData(oldp+755,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 2U))),3);
        bufp->chgBit(oldp+756,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x24U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x24U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x24U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+757,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+758,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 4U))));
        bufp->chgBit(oldp+759,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 3U))));
        bufp->chgBit(oldp+760,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 2U))));
        bufp->chgCData(oldp+761,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+762,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+763,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+764,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x24U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+765,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 1U)))));
        bufp->chgBit(oldp+766,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+767,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x24U] >> 1U))));
        bufp->chgCData(oldp+768,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x24U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+769,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x24U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+770,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+771,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x24U])));
        bufp->chgBit(oldp+772,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+773,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+774,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+775,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+776,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+777,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+778,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+779,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+780,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+781,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+782,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+783,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+784,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+785,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+786,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+787,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+788,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+789,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+790,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+791,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+792,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+793,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+794,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+795,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+796,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+797,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+798,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+799,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+800,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+801,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+802,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+803,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+804,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x25U]),17);
        bufp->chgSData(oldp+805,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+806,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout));
        bufp->chgBit(oldp+807,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+808,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+809,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+810,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+811,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+812,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+813,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 0xeU))),3);
        bufp->chgBit(oldp+814,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x25U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x25U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+815,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+816,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0x10U))));
        bufp->chgBit(oldp+817,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xfU))));
        bufp->chgBit(oldp+818,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xeU))));
        bufp->chgCData(oldp+819,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 0xbU))),3);
        bufp->chgBit(oldp+820,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x25U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x25U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+821,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+822,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xdU))));
        bufp->chgBit(oldp+823,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xcU))));
        bufp->chgBit(oldp+824,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xbU))));
        bufp->chgCData(oldp+825,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 8U))),3);
        bufp->chgBit(oldp+826,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x25U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+827,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+828,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 0xaU))));
        bufp->chgBit(oldp+829,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 9U))));
        bufp->chgBit(oldp+830,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 8U))));
        bufp->chgCData(oldp+831,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 5U))),3);
        bufp->chgBit(oldp+832,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x25U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+833,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+834,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 7U))));
        bufp->chgBit(oldp+835,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 6U))));
        bufp->chgBit(oldp+836,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 5U))));
        bufp->chgCData(oldp+837,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 2U))),3);
        bufp->chgBit(oldp+838,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x25U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x25U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x25U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+839,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+840,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 4U))));
        bufp->chgBit(oldp+841,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 3U))));
        bufp->chgBit(oldp+842,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 2U))));
        bufp->chgCData(oldp+843,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+844,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+845,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+846,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x25U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+847,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 1U)))));
        bufp->chgBit(oldp+848,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+849,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x25U] >> 1U))));
        bufp->chgCData(oldp+850,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x25U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+851,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x25U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+852,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+853,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x25U])));
        bufp->chgBit(oldp+854,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+855,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+856,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+857,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+858,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+859,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+860,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+861,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+862,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+863,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+864,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+865,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+866,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+867,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+868,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+869,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+870,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+871,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+872,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+873,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+874,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+875,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+876,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+877,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+878,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+879,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+880,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+881,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+882,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+883,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+884,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+885,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+886,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x26U]),17);
        bufp->chgSData(oldp+887,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+888,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout));
        bufp->chgBit(oldp+889,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+890,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+891,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+892,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+893,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+894,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+895,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 0xeU))),3);
        bufp->chgBit(oldp+896,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x26U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x26U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+897,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+898,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0x10U))));
        bufp->chgBit(oldp+899,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xfU))));
        bufp->chgBit(oldp+900,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xeU))));
        bufp->chgCData(oldp+901,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 0xbU))),3);
        bufp->chgBit(oldp+902,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x26U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x26U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+903,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+904,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xdU))));
        bufp->chgBit(oldp+905,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xcU))));
        bufp->chgBit(oldp+906,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xbU))));
        bufp->chgCData(oldp+907,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 8U))),3);
        bufp->chgBit(oldp+908,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x26U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+909,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+910,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 0xaU))));
        bufp->chgBit(oldp+911,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 9U))));
        bufp->chgBit(oldp+912,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 8U))));
        bufp->chgCData(oldp+913,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 5U))),3);
        bufp->chgBit(oldp+914,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x26U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+915,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+916,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 7U))));
        bufp->chgBit(oldp+917,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 6U))));
        bufp->chgBit(oldp+918,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 5U))));
        bufp->chgCData(oldp+919,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 2U))),3);
        bufp->chgBit(oldp+920,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x26U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x26U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x26U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+921,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+922,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 4U))));
        bufp->chgBit(oldp+923,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 3U))));
        bufp->chgBit(oldp+924,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 2U))));
        bufp->chgCData(oldp+925,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+926,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+927,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+928,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x26U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+929,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 1U)))));
        bufp->chgBit(oldp+930,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+931,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x26U] >> 1U))));
        bufp->chgCData(oldp+932,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x26U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+933,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x26U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+934,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+935,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x26U])));
        bufp->chgBit(oldp+936,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+937,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+938,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+939,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+940,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+941,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+942,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+943,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+944,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+945,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+946,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+947,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+948,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+949,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+950,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+951,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+952,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+953,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+954,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+955,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+956,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+957,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+958,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+959,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+960,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+961,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+962,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+963,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+964,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+965,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+966,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+967,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+968,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x27U]),17);
        bufp->chgSData(oldp+969,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+970,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout));
        bufp->chgBit(oldp+971,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+972,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+973,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+974,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+975,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+976,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+977,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 0xeU))),3);
        bufp->chgBit(oldp+978,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x27U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+979,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+980,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0x10U))));
        bufp->chgBit(oldp+981,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xfU))));
        bufp->chgBit(oldp+982,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xeU))));
        bufp->chgCData(oldp+983,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 0xbU))),3);
        bufp->chgBit(oldp+984,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x27U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+985,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+986,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xdU))));
        bufp->chgBit(oldp+987,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xcU))));
        bufp->chgBit(oldp+988,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xbU))));
        bufp->chgCData(oldp+989,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 8U))),3);
        bufp->chgBit(oldp+990,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x27U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+991,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+992,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 0xaU))));
        bufp->chgBit(oldp+993,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 9U))));
        bufp->chgBit(oldp+994,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 8U))));
        bufp->chgCData(oldp+995,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 5U))),3);
        bufp->chgBit(oldp+996,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x27U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+997,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+998,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 7U))));
        bufp->chgBit(oldp+999,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x27U] >> 6U))));
        bufp->chgBit(oldp+1000,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x27U] >> 5U))));
        bufp->chgCData(oldp+1001,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U] >> 2U))),3);
        bufp->chgBit(oldp+1002,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x27U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x27U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1003,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1004,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x27U] >> 4U))));
        bufp->chgBit(oldp+1005,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x27U] >> 3U))));
        bufp->chgBit(oldp+1006,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x27U] >> 2U))));
        bufp->chgCData(oldp+1007,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1008,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1009,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1010,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x27U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1011,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x27U] >> 1U)))));
        bufp->chgBit(oldp+1012,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1013,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x27U] >> 1U))));
        bufp->chgCData(oldp+1014,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1015,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x27U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x27U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1016,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1017,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x27U])));
        bufp->chgBit(oldp+1018,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1019,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1020,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1021,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1022,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1023,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1024,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1025,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1026,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1027,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1028,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1029,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1030,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1031,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1032,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1033,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1034,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1035,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1036,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1037,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1038,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1039,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1040,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1041,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1042,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1043,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1044,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1045,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1046,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1047,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1048,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1049,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1050,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x28U]),17);
        bufp->chgSData(oldp+1051,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1052,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1053,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1054,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1055,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1056,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1057,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1058,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1059,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 0xeU))),3);
        bufp->chgBit(oldp+1060,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x28U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x28U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1061,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1062,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 0x10U))));
        bufp->chgBit(oldp+1063,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 0xfU))));
        bufp->chgBit(oldp+1064,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 0xeU))));
        bufp->chgCData(oldp+1065,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 0xbU))),3);
        bufp->chgBit(oldp+1066,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x28U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x28U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1067,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1068,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 0xdU))));
        bufp->chgBit(oldp+1069,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 0xcU))));
        bufp->chgBit(oldp+1070,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 0xbU))));
        bufp->chgCData(oldp+1071,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 8U))),3);
        bufp->chgBit(oldp+1072,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x28U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x28U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1073,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1074,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 0xaU))));
        bufp->chgBit(oldp+1075,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 9U))));
        bufp->chgBit(oldp+1076,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 8U))));
        bufp->chgCData(oldp+1077,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 5U))),3);
        bufp->chgBit(oldp+1078,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x28U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x28U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1079,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1080,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 7U))));
        bufp->chgBit(oldp+1081,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 6U))));
        bufp->chgBit(oldp+1082,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 5U))));
        bufp->chgCData(oldp+1083,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 2U))),3);
        bufp->chgBit(oldp+1084,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x28U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x28U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1085,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1086,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 4U))));
        bufp->chgBit(oldp+1087,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 3U))));
        bufp->chgBit(oldp+1088,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 2U))));
        bufp->chgCData(oldp+1089,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1090,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1091,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1092,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x28U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1093,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 1U)))));
        bufp->chgBit(oldp+1094,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1095,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x28U] >> 1U))));
        bufp->chgCData(oldp+1096,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1097,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x28U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x28U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1098,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1099,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x28U])));
        bufp->chgBit(oldp+1100,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1101,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1102,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1103,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1104,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1105,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1106,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1107,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1108,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1109,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1110,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1111,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1112,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1113,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1114,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1115,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1116,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1117,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1118,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1119,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1120,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1121,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1122,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1123,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1124,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1125,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1126,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1127,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1128,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1129,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1130,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1131,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1132,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x29U]),17);
        bufp->chgSData(oldp+1133,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1134,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1135,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1136,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1137,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1138,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1139,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1140,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1141,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 0xeU))),3);
        bufp->chgBit(oldp+1142,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x29U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x29U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1143,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1144,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 0x10U))));
        bufp->chgBit(oldp+1145,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 0xfU))));
        bufp->chgBit(oldp+1146,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 0xeU))));
        bufp->chgCData(oldp+1147,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 0xbU))),3);
        bufp->chgBit(oldp+1148,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x29U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x29U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1149,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1150,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 0xdU))));
        bufp->chgBit(oldp+1151,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 0xcU))));
        bufp->chgBit(oldp+1152,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 0xbU))));
        bufp->chgCData(oldp+1153,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 8U))),3);
        bufp->chgBit(oldp+1154,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x29U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x29U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1155,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1156,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 0xaU))));
        bufp->chgBit(oldp+1157,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 9U))));
        bufp->chgBit(oldp+1158,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 8U))));
        bufp->chgCData(oldp+1159,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 5U))),3);
        bufp->chgBit(oldp+1160,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x29U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x29U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1161,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1162,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 7U))));
        bufp->chgBit(oldp+1163,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 6U))));
        bufp->chgBit(oldp+1164,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 5U))));
        bufp->chgCData(oldp+1165,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 2U))),3);
        bufp->chgBit(oldp+1166,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x29U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x29U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1167,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1168,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 4U))));
        bufp->chgBit(oldp+1169,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 3U))));
        bufp->chgBit(oldp+1170,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 2U))));
        bufp->chgCData(oldp+1171,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1172,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1173,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1174,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x29U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1175,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 1U)))));
        bufp->chgBit(oldp+1176,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1177,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x29U] >> 1U))));
        bufp->chgCData(oldp+1178,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1179,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x29U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x29U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1180,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1181,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x29U])));
        bufp->chgBit(oldp+1182,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1183,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1184,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1185,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1186,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1187,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1188,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1189,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1190,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1191,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1192,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1193,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1194,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1195,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1196,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1197,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1198,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1199,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1200,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1201,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1202,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1203,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1204,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1205,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1206,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1207,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1208,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1209,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1210,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1211,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1212,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1213,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1214,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x2aU]),17);
        bufp->chgSData(oldp+1215,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1216,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1217,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1218,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1219,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1220,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1221,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1222,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1223,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 0xeU))),3);
        bufp->chgBit(oldp+1224,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2aU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2aU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1225,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1226,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 0x10U))));
        bufp->chgBit(oldp+1227,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 0xfU))));
        bufp->chgBit(oldp+1228,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 0xeU))));
        bufp->chgCData(oldp+1229,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 0xbU))),3);
        bufp->chgBit(oldp+1230,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2aU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2aU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1231,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1232,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 0xdU))));
        bufp->chgBit(oldp+1233,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 0xcU))));
        bufp->chgBit(oldp+1234,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 0xbU))));
        bufp->chgCData(oldp+1235,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 8U))),3);
        bufp->chgBit(oldp+1236,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2aU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2aU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1237,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1238,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 0xaU))));
        bufp->chgBit(oldp+1239,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 9U))));
        bufp->chgBit(oldp+1240,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 8U))));
        bufp->chgCData(oldp+1241,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 5U))),3);
        bufp->chgBit(oldp+1242,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2aU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2aU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1243,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1244,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 7U))));
        bufp->chgBit(oldp+1245,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 6U))));
        bufp->chgBit(oldp+1246,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 5U))));
        bufp->chgCData(oldp+1247,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 2U))),3);
        bufp->chgBit(oldp+1248,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2aU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2aU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1249,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1250,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 4U))));
        bufp->chgBit(oldp+1251,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 3U))));
        bufp->chgBit(oldp+1252,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 2U))));
        bufp->chgCData(oldp+1253,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1254,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1255,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1256,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x2aU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1257,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 1U)))));
        bufp->chgBit(oldp+1258,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1259,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2aU] >> 1U))));
        bufp->chgCData(oldp+1260,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1261,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2aU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2aU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1262,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1263,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x2aU])));
        bufp->chgBit(oldp+1264,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1265,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1266,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1267,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1268,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1269,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1270,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1271,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1272,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1273,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1274,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1275,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1276,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1277,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1278,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1279,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1280,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1281,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1282,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1283,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1284,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1285,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1286,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1287,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1288,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1289,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1290,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1291,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1292,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1293,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1294,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1295,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1296,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x2bU]),17);
        bufp->chgSData(oldp+1297,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1298,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1299,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1300,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1301,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1302,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1303,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1304,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1305,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 0xeU))),3);
        bufp->chgBit(oldp+1306,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2bU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2bU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1307,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1308,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 0x10U))));
        bufp->chgBit(oldp+1309,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 0xfU))));
        bufp->chgBit(oldp+1310,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 0xeU))));
        bufp->chgCData(oldp+1311,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 0xbU))),3);
        bufp->chgBit(oldp+1312,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2bU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2bU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1313,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1314,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 0xdU))));
        bufp->chgBit(oldp+1315,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 0xcU))));
        bufp->chgBit(oldp+1316,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 0xbU))));
        bufp->chgCData(oldp+1317,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 8U))),3);
        bufp->chgBit(oldp+1318,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2bU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2bU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1319,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1320,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 0xaU))));
        bufp->chgBit(oldp+1321,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 9U))));
        bufp->chgBit(oldp+1322,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 8U))));
        bufp->chgCData(oldp+1323,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 5U))),3);
        bufp->chgBit(oldp+1324,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2bU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2bU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1325,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1326,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 7U))));
        bufp->chgBit(oldp+1327,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 6U))));
        bufp->chgBit(oldp+1328,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 5U))));
        bufp->chgCData(oldp+1329,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 2U))),3);
        bufp->chgBit(oldp+1330,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2bU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2bU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1331,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1332,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 4U))));
        bufp->chgBit(oldp+1333,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 3U))));
        bufp->chgBit(oldp+1334,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 2U))));
        bufp->chgCData(oldp+1335,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1336,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1337,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1338,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x2bU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1339,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 1U)))));
        bufp->chgBit(oldp+1340,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1341,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2bU] >> 1U))));
        bufp->chgCData(oldp+1342,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1343,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2bU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2bU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1344,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1345,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x2bU])));
        bufp->chgBit(oldp+1346,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1347,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1348,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1349,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1350,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1351,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1352,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1353,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1354,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1355,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1356,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1357,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1358,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1359,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1360,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1361,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1362,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1363,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1364,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1365,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1366,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1367,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1368,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1369,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1370,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1371,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1372,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1373,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1374,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1375,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1376,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1377,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1378,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x2cU]),17);
        bufp->chgSData(oldp+1379,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1380,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1381,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1382,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1383,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1384,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1385,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1386,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1387,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 0xeU))),3);
        bufp->chgBit(oldp+1388,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2cU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2cU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1389,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1390,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 0x10U))));
        bufp->chgBit(oldp+1391,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 0xfU))));
        bufp->chgBit(oldp+1392,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 0xeU))));
        bufp->chgCData(oldp+1393,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 0xbU))),3);
        bufp->chgBit(oldp+1394,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2cU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2cU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1395,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1396,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 0xdU))));
        bufp->chgBit(oldp+1397,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 0xcU))));
        bufp->chgBit(oldp+1398,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 0xbU))));
        bufp->chgCData(oldp+1399,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 8U))),3);
        bufp->chgBit(oldp+1400,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2cU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2cU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1401,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1402,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 0xaU))));
        bufp->chgBit(oldp+1403,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 9U))));
        bufp->chgBit(oldp+1404,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 8U))));
        bufp->chgCData(oldp+1405,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 5U))),3);
        bufp->chgBit(oldp+1406,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2cU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2cU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1407,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1408,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 7U))));
        bufp->chgBit(oldp+1409,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 6U))));
        bufp->chgBit(oldp+1410,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 5U))));
        bufp->chgCData(oldp+1411,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 2U))),3);
        bufp->chgBit(oldp+1412,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2cU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2cU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1413,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1414,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 4U))));
        bufp->chgBit(oldp+1415,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 3U))));
        bufp->chgBit(oldp+1416,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 2U))));
        bufp->chgCData(oldp+1417,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1418,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1419,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1420,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x2cU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1421,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 1U)))));
        bufp->chgBit(oldp+1422,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1423,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2cU] >> 1U))));
        bufp->chgCData(oldp+1424,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1425,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2cU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2cU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1426,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1427,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x2cU])));
        bufp->chgBit(oldp+1428,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1429,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1430,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1431,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1432,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1433,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1434,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1435,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1436,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1437,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1438,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1439,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1440,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1441,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1442,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1443,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1444,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1445,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1446,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1447,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1448,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1449,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1450,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1451,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1452,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1453,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1454,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1455,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1456,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1457,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1458,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1459,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1460,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x2dU]),17);
        bufp->chgSData(oldp+1461,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1462,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1463,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1464,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1465,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1466,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1467,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1468,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1469,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 0xeU))),3);
        bufp->chgBit(oldp+1470,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2dU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2dU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1471,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1472,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 0x10U))));
        bufp->chgBit(oldp+1473,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 0xfU))));
        bufp->chgBit(oldp+1474,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 0xeU))));
        bufp->chgCData(oldp+1475,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 0xbU))),3);
        bufp->chgBit(oldp+1476,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2dU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2dU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1477,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1478,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 0xdU))));
        bufp->chgBit(oldp+1479,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 0xcU))));
        bufp->chgBit(oldp+1480,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 0xbU))));
        bufp->chgCData(oldp+1481,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 8U))),3);
        bufp->chgBit(oldp+1482,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2dU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2dU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1483,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1484,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 0xaU))));
        bufp->chgBit(oldp+1485,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 9U))));
        bufp->chgBit(oldp+1486,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 8U))));
        bufp->chgCData(oldp+1487,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 5U))),3);
        bufp->chgBit(oldp+1488,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2dU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2dU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1489,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1490,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 7U))));
        bufp->chgBit(oldp+1491,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 6U))));
        bufp->chgBit(oldp+1492,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 5U))));
        bufp->chgCData(oldp+1493,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 2U))),3);
        bufp->chgBit(oldp+1494,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2dU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2dU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1495,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1496,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 4U))));
        bufp->chgBit(oldp+1497,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 3U))));
        bufp->chgBit(oldp+1498,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 2U))));
        bufp->chgCData(oldp+1499,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1500,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1501,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1502,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x2dU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1503,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 1U)))));
        bufp->chgBit(oldp+1504,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1505,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2dU] >> 1U))));
        bufp->chgCData(oldp+1506,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1507,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2dU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2dU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1508,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1509,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x2dU])));
        bufp->chgBit(oldp+1510,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1511,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1512,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1513,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1514,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1515,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1516,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1517,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1518,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1519,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1520,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1521,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1522,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1523,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1524,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1525,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1526,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1527,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1528,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1529,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1530,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1531,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1532,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1533,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1534,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1535,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1536,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1537,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1538,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1539,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1540,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1541,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1542,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x2eU]),17);
        bufp->chgSData(oldp+1543,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1544,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1545,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1546,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1547,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1548,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1549,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1550,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1551,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 0xeU))),3);
        bufp->chgBit(oldp+1552,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2eU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2eU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1553,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1554,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 0x10U))));
        bufp->chgBit(oldp+1555,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 0xfU))));
        bufp->chgBit(oldp+1556,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 0xeU))));
        bufp->chgCData(oldp+1557,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 0xbU))),3);
        bufp->chgBit(oldp+1558,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2eU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2eU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1559,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1560,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 0xdU))));
        bufp->chgBit(oldp+1561,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 0xcU))));
        bufp->chgBit(oldp+1562,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 0xbU))));
        bufp->chgCData(oldp+1563,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 8U))),3);
        bufp->chgBit(oldp+1564,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2eU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2eU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1565,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1566,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 0xaU))));
        bufp->chgBit(oldp+1567,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 9U))));
        bufp->chgBit(oldp+1568,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 8U))));
        bufp->chgCData(oldp+1569,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 5U))),3);
        bufp->chgBit(oldp+1570,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2eU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2eU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1571,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1572,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 7U))));
        bufp->chgBit(oldp+1573,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 6U))));
        bufp->chgBit(oldp+1574,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 5U))));
        bufp->chgCData(oldp+1575,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 2U))),3);
        bufp->chgBit(oldp+1576,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2eU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2eU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1577,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1578,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 4U))));
        bufp->chgBit(oldp+1579,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 3U))));
        bufp->chgBit(oldp+1580,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 2U))));
        bufp->chgCData(oldp+1581,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1582,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1583,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1584,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x2eU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1585,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 1U)))));
        bufp->chgBit(oldp+1586,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1587,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2eU] >> 1U))));
        bufp->chgCData(oldp+1588,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1589,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2eU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2eU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1590,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1591,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x2eU])));
        bufp->chgBit(oldp+1592,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1593,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1594,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1595,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1596,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1597,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1598,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1599,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1600,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1601,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1602,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1603,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1604,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1605,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1606,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1607,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1608,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1609,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1610,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1611,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1612,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1613,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1614,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1615,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1616,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1617,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1618,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1619,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1620,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1621,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1622,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1623,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1624,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x2fU]),17);
        bufp->chgSData(oldp+1625,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1626,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1627,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1628,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1629,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1630,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1631,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1632,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1633,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 0xeU))),3);
        bufp->chgBit(oldp+1634,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2fU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2fU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1635,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1636,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 0x10U))));
        bufp->chgBit(oldp+1637,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 0xfU))));
        bufp->chgBit(oldp+1638,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 0xeU))));
        bufp->chgCData(oldp+1639,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 0xbU))),3);
        bufp->chgBit(oldp+1640,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2fU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2fU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1641,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1642,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 0xdU))));
        bufp->chgBit(oldp+1643,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 0xcU))));
        bufp->chgBit(oldp+1644,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 0xbU))));
        bufp->chgCData(oldp+1645,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 8U))),3);
        bufp->chgBit(oldp+1646,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2fU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2fU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1647,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1648,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 0xaU))));
        bufp->chgBit(oldp+1649,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 9U))));
        bufp->chgBit(oldp+1650,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 8U))));
        bufp->chgCData(oldp+1651,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 5U))),3);
        bufp->chgBit(oldp+1652,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2fU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2fU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1653,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1654,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 7U))));
        bufp->chgBit(oldp+1655,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 6U))));
        bufp->chgBit(oldp+1656,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 5U))));
        bufp->chgCData(oldp+1657,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 2U))),3);
        bufp->chgBit(oldp+1658,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x2fU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x2fU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1659,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1660,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 4U))));
        bufp->chgBit(oldp+1661,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 3U))));
        bufp->chgBit(oldp+1662,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 2U))));
        bufp->chgCData(oldp+1663,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1664,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1665,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1666,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x2fU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1667,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 1U)))));
        bufp->chgBit(oldp+1668,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1669,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x2fU] >> 1U))));
        bufp->chgCData(oldp+1670,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1671,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x2fU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x2fU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1672,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1673,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x2fU])));
        bufp->chgBit(oldp+1674,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1675,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1676,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1677,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1678,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1679,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1680,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1681,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1682,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1683,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1684,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1685,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1686,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1687,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1688,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1689,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1690,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1691,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1692,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1693,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1694,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1695,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1696,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1697,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1698,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1699,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1700,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1701,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1702,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1703,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1704,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1705,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1706,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x30U]),17);
        bufp->chgSData(oldp+1707,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1708,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1709,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1710,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1711,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1712,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1713,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1714,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1715,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 0xeU))),3);
        bufp->chgBit(oldp+1716,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x30U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x30U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1717,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1718,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 0x10U))));
        bufp->chgBit(oldp+1719,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 0xfU))));
        bufp->chgBit(oldp+1720,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 0xeU))));
        bufp->chgCData(oldp+1721,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 0xbU))),3);
        bufp->chgBit(oldp+1722,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x30U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x30U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1723,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1724,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 0xdU))));
        bufp->chgBit(oldp+1725,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 0xcU))));
        bufp->chgBit(oldp+1726,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 0xbU))));
        bufp->chgCData(oldp+1727,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 8U))),3);
        bufp->chgBit(oldp+1728,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x30U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x30U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1729,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1730,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 0xaU))));
        bufp->chgBit(oldp+1731,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 9U))));
        bufp->chgBit(oldp+1732,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 8U))));
        bufp->chgCData(oldp+1733,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 5U))),3);
        bufp->chgBit(oldp+1734,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x30U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x30U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1735,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1736,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 7U))));
        bufp->chgBit(oldp+1737,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 6U))));
        bufp->chgBit(oldp+1738,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 5U))));
        bufp->chgCData(oldp+1739,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 2U))),3);
        bufp->chgBit(oldp+1740,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x30U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x30U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1741,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1742,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 4U))));
        bufp->chgBit(oldp+1743,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 3U))));
        bufp->chgBit(oldp+1744,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 2U))));
        bufp->chgCData(oldp+1745,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1746,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1747,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1748,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x30U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1749,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 1U)))));
        bufp->chgBit(oldp+1750,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1751,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x30U] >> 1U))));
        bufp->chgCData(oldp+1752,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1753,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x30U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x30U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1754,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1755,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x30U])));
        bufp->chgBit(oldp+1756,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1757,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1758,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1759,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1760,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1761,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1762,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1763,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1764,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1765,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1766,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1767,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1768,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1769,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1770,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1771,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1772,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1773,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1774,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1775,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1776,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1777,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1778,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1779,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1780,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1781,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1782,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1783,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1784,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1785,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1786,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1787,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1788,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x31U]),17);
        bufp->chgSData(oldp+1789,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1790,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1791,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1792,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1793,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1794,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1795,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1796,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1797,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 0xeU))),3);
        bufp->chgBit(oldp+1798,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x31U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x31U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1799,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1800,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 0x10U))));
        bufp->chgBit(oldp+1801,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 0xfU))));
        bufp->chgBit(oldp+1802,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 0xeU))));
        bufp->chgCData(oldp+1803,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 0xbU))),3);
        bufp->chgBit(oldp+1804,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x31U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x31U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1805,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1806,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 0xdU))));
        bufp->chgBit(oldp+1807,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 0xcU))));
        bufp->chgBit(oldp+1808,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 0xbU))));
        bufp->chgCData(oldp+1809,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 8U))),3);
        bufp->chgBit(oldp+1810,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x31U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x31U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1811,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1812,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 0xaU))));
        bufp->chgBit(oldp+1813,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 9U))));
        bufp->chgBit(oldp+1814,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 8U))));
        bufp->chgCData(oldp+1815,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 5U))),3);
        bufp->chgBit(oldp+1816,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x31U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x31U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1817,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1818,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 7U))));
        bufp->chgBit(oldp+1819,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 6U))));
        bufp->chgBit(oldp+1820,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 5U))));
        bufp->chgCData(oldp+1821,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 2U))),3);
        bufp->chgBit(oldp+1822,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x31U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x31U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1823,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1824,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 4U))));
        bufp->chgBit(oldp+1825,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 3U))));
        bufp->chgBit(oldp+1826,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 2U))));
        bufp->chgCData(oldp+1827,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1828,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1829,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1830,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x31U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1831,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 1U)))));
        bufp->chgBit(oldp+1832,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1833,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x31U] >> 1U))));
        bufp->chgCData(oldp+1834,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1835,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x31U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x31U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1836,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1837,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x31U])));
        bufp->chgBit(oldp+1838,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1839,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1840,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1841,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1842,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1843,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1844,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1845,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1846,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1847,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1848,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1849,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1850,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1851,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1852,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1853,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1854,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1855,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1856,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1857,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1858,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1859,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1860,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1861,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1862,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1863,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1864,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1865,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1866,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1867,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1868,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1869,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1870,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x32U]),17);
        bufp->chgSData(oldp+1871,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1872,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1873,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1874,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1875,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1876,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1877,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1878,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1879,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 0xeU))),3);
        bufp->chgBit(oldp+1880,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x32U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x32U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1881,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1882,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 0x10U))));
        bufp->chgBit(oldp+1883,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 0xfU))));
        bufp->chgBit(oldp+1884,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 0xeU))));
        bufp->chgCData(oldp+1885,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 0xbU))),3);
        bufp->chgBit(oldp+1886,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x32U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x32U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1887,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1888,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 0xdU))));
        bufp->chgBit(oldp+1889,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 0xcU))));
        bufp->chgBit(oldp+1890,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 0xbU))));
        bufp->chgCData(oldp+1891,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 8U))),3);
        bufp->chgBit(oldp+1892,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x32U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x32U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1893,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1894,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 0xaU))));
        bufp->chgBit(oldp+1895,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 9U))));
        bufp->chgBit(oldp+1896,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 8U))));
        bufp->chgCData(oldp+1897,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 5U))),3);
        bufp->chgBit(oldp+1898,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x32U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x32U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1899,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1900,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 7U))));
        bufp->chgBit(oldp+1901,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 6U))));
        bufp->chgBit(oldp+1902,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 5U))));
        bufp->chgCData(oldp+1903,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 2U))),3);
        bufp->chgBit(oldp+1904,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x32U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x32U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1905,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1906,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 4U))));
        bufp->chgBit(oldp+1907,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 3U))));
        bufp->chgBit(oldp+1908,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 2U))));
        bufp->chgCData(oldp+1909,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1910,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1911,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1912,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x32U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1913,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 1U)))));
        bufp->chgBit(oldp+1914,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1915,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x32U] >> 1U))));
        bufp->chgCData(oldp+1916,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1917,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x32U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x32U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1918,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1919,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x32U])));
        bufp->chgBit(oldp+1920,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1921,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1922,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1923,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1924,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1925,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1926,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1927,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1928,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1929,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1930,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1931,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1932,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1933,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1934,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1935,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1936,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1937,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1938,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1939,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1940,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1941,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1942,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1943,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1944,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1945,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1946,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1947,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1948,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1949,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1950,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1951,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1952,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x33U]),17);
        bufp->chgSData(oldp+1953,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1954,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1955,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1956,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1957,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1958,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1959,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1960,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1961,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 0xeU))),3);
        bufp->chgBit(oldp+1962,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x33U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x33U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1963,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1964,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 0x10U))));
        bufp->chgBit(oldp+1965,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 0xfU))));
        bufp->chgBit(oldp+1966,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 0xeU))));
        bufp->chgCData(oldp+1967,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 0xbU))),3);
        bufp->chgBit(oldp+1968,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x33U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x33U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1969,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1970,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 0xdU))));
        bufp->chgBit(oldp+1971,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 0xcU))));
        bufp->chgBit(oldp+1972,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 0xbU))));
        bufp->chgCData(oldp+1973,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 8U))),3);
        bufp->chgBit(oldp+1974,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x33U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x33U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1975,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1976,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 0xaU))));
        bufp->chgBit(oldp+1977,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 9U))));
        bufp->chgBit(oldp+1978,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 8U))));
        bufp->chgCData(oldp+1979,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 5U))),3);
        bufp->chgBit(oldp+1980,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x33U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x33U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1981,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1982,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 7U))));
        bufp->chgBit(oldp+1983,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 6U))));
        bufp->chgBit(oldp+1984,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 5U))));
        bufp->chgCData(oldp+1985,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 2U))),3);
        bufp->chgBit(oldp+1986,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x33U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x33U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1987,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1988,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 4U))));
        bufp->chgBit(oldp+1989,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 3U))));
        bufp->chgBit(oldp+1990,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 2U))));
        bufp->chgCData(oldp+1991,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1992,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1993,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1994,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x33U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1995,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 1U)))));
        bufp->chgBit(oldp+1996,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1997,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x33U] >> 1U))));
        bufp->chgCData(oldp+1998,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1999,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x33U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x33U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2000,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2001,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x33U])));
        bufp->chgBit(oldp+2002,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2003,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2004,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2005,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2006,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2007,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2008,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2009,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2010,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2011,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2012,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2013,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2014,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2015,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2016,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2017,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2018,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2019,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2020,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2021,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2022,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2023,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2024,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2025,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2026,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2027,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2028,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2029,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2030,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2031,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2032,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2033,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2034,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x34U]),17);
        bufp->chgSData(oldp+2035,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2036,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2037,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2038,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2039,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2040,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2041,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2042,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2043,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 0xeU))),3);
        bufp->chgBit(oldp+2044,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x34U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x34U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2045,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2046,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 0x10U))));
        bufp->chgBit(oldp+2047,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 0xfU))));
        bufp->chgBit(oldp+2048,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 0xeU))));
        bufp->chgCData(oldp+2049,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 0xbU))),3);
        bufp->chgBit(oldp+2050,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x34U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x34U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2051,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2052,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 0xdU))));
        bufp->chgBit(oldp+2053,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 0xcU))));
        bufp->chgBit(oldp+2054,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 0xbU))));
        bufp->chgCData(oldp+2055,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 8U))),3);
        bufp->chgBit(oldp+2056,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x34U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x34U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2057,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2058,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 0xaU))));
        bufp->chgBit(oldp+2059,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 9U))));
        bufp->chgBit(oldp+2060,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 8U))));
        bufp->chgCData(oldp+2061,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 5U))),3);
        bufp->chgBit(oldp+2062,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x34U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x34U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2063,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2064,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 7U))));
        bufp->chgBit(oldp+2065,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 6U))));
        bufp->chgBit(oldp+2066,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 5U))));
        bufp->chgCData(oldp+2067,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 2U))),3);
        bufp->chgBit(oldp+2068,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x34U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x34U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2069,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2070,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 4U))));
        bufp->chgBit(oldp+2071,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 3U))));
        bufp->chgBit(oldp+2072,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 2U))));
        bufp->chgCData(oldp+2073,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2074,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2075,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2076,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x34U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2077,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 1U)))));
        bufp->chgBit(oldp+2078,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2079,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x34U] >> 1U))));
        bufp->chgCData(oldp+2080,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2081,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x34U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x34U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2082,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2083,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x34U])));
        bufp->chgBit(oldp+2084,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2085,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2086,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2087,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2088,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2089,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2090,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2091,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2092,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2093,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2094,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2095,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2096,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2097,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2098,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2099,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2100,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2101,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2102,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2103,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2104,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2105,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2106,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2107,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2108,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2109,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2110,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2111,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2112,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2113,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2114,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2115,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2116,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x35U]),17);
        bufp->chgSData(oldp+2117,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2118,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2119,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2120,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2121,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2122,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2123,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2124,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2125,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 0xeU))),3);
        bufp->chgBit(oldp+2126,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x35U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x35U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2127,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2128,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 0x10U))));
        bufp->chgBit(oldp+2129,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 0xfU))));
        bufp->chgBit(oldp+2130,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 0xeU))));
        bufp->chgCData(oldp+2131,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 0xbU))),3);
        bufp->chgBit(oldp+2132,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x35U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x35U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2133,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2134,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 0xdU))));
        bufp->chgBit(oldp+2135,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 0xcU))));
        bufp->chgBit(oldp+2136,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 0xbU))));
        bufp->chgCData(oldp+2137,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 8U))),3);
        bufp->chgBit(oldp+2138,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x35U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x35U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2139,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2140,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 0xaU))));
        bufp->chgBit(oldp+2141,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 9U))));
        bufp->chgBit(oldp+2142,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 8U))));
        bufp->chgCData(oldp+2143,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 5U))),3);
        bufp->chgBit(oldp+2144,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x35U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x35U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2145,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2146,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 7U))));
        bufp->chgBit(oldp+2147,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 6U))));
        bufp->chgBit(oldp+2148,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 5U))));
        bufp->chgCData(oldp+2149,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 2U))),3);
        bufp->chgBit(oldp+2150,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x35U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x35U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2151,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2152,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 4U))));
        bufp->chgBit(oldp+2153,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 3U))));
        bufp->chgBit(oldp+2154,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 2U))));
        bufp->chgCData(oldp+2155,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2156,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2157,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2158,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x35U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2159,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 1U)))));
        bufp->chgBit(oldp+2160,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2161,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x35U] >> 1U))));
        bufp->chgCData(oldp+2162,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2163,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x35U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x35U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2164,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2165,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x35U])));
        bufp->chgBit(oldp+2166,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2167,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2168,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2169,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2170,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2171,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2172,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2173,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2174,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2175,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2176,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2177,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2178,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2179,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2180,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2181,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2182,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2183,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2184,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2185,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2186,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2187,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2188,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2189,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2190,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2191,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2192,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2193,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2194,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2195,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2196,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2197,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2198,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x36U]),17);
        bufp->chgSData(oldp+2199,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2200,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2201,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2202,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2203,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2204,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2205,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2206,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2207,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 0xeU))),3);
        bufp->chgBit(oldp+2208,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x36U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x36U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2209,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2210,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 0x10U))));
        bufp->chgBit(oldp+2211,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 0xfU))));
        bufp->chgBit(oldp+2212,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 0xeU))));
        bufp->chgCData(oldp+2213,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 0xbU))),3);
        bufp->chgBit(oldp+2214,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x36U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x36U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2215,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2216,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 0xdU))));
        bufp->chgBit(oldp+2217,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 0xcU))));
        bufp->chgBit(oldp+2218,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 0xbU))));
        bufp->chgCData(oldp+2219,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 8U))),3);
        bufp->chgBit(oldp+2220,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x36U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x36U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2221,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2222,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 0xaU))));
        bufp->chgBit(oldp+2223,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 9U))));
        bufp->chgBit(oldp+2224,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 8U))));
        bufp->chgCData(oldp+2225,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 5U))),3);
        bufp->chgBit(oldp+2226,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x36U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x36U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2227,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2228,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 7U))));
        bufp->chgBit(oldp+2229,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 6U))));
        bufp->chgBit(oldp+2230,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 5U))));
        bufp->chgCData(oldp+2231,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 2U))),3);
        bufp->chgBit(oldp+2232,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x36U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x36U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2233,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2234,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 4U))));
        bufp->chgBit(oldp+2235,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 3U))));
        bufp->chgBit(oldp+2236,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 2U))));
        bufp->chgCData(oldp+2237,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2238,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2239,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2240,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x36U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2241,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 1U)))));
        bufp->chgBit(oldp+2242,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2243,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x36U] >> 1U))));
        bufp->chgCData(oldp+2244,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2245,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x36U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x36U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2246,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2247,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x36U])));
        bufp->chgBit(oldp+2248,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2249,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2250,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2251,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2252,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2253,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2254,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2255,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2256,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2257,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2258,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2259,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2260,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2261,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2262,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2263,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2264,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2265,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2266,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2267,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2268,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2269,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2270,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2271,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2272,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2273,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2274,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2275,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2276,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2277,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2278,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2279,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2280,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x37U]),17);
        bufp->chgSData(oldp+2281,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2282,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2283,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2284,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2285,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2286,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2287,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2288,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2289,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 0xeU))),3);
        bufp->chgBit(oldp+2290,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x37U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x37U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2291,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2292,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 0x10U))));
        bufp->chgBit(oldp+2293,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 0xfU))));
        bufp->chgBit(oldp+2294,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 0xeU))));
        bufp->chgCData(oldp+2295,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 0xbU))),3);
        bufp->chgBit(oldp+2296,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x37U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x37U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2297,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2298,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 0xdU))));
        bufp->chgBit(oldp+2299,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 0xcU))));
        bufp->chgBit(oldp+2300,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 0xbU))));
        bufp->chgCData(oldp+2301,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 8U))),3);
        bufp->chgBit(oldp+2302,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x37U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x37U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2303,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2304,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 0xaU))));
        bufp->chgBit(oldp+2305,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 9U))));
        bufp->chgBit(oldp+2306,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x37U] >> 8U))));
        bufp->chgCData(oldp+2307,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 5U))),3);
        bufp->chgBit(oldp+2308,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x37U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x37U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x37U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 5U))))));
    }
}
