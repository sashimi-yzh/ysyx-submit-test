// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbooth_wallace_multiplier__Syms.h"


void Vbooth_wallace_multiplier___024root__trace_chg_sub_2(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root__trace_chg_sub_2\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 4701);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 7U))));
        bufp->chgBit(oldp+2,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 6U))));
        bufp->chgBit(oldp+3,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 5U))));
        bufp->chgCData(oldp+4,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] >> 2U))),3);
        bufp->chgBit(oldp+5,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
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
        bufp->chgBit(oldp+6,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+7,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 4U))));
        bufp->chgBit(oldp+8,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 3U))));
        bufp->chgBit(oldp+9,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                    [0x37U] >> 2U))));
        bufp->chgCData(oldp+10,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+11,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s)) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+13,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                             << 1U) 
                                            | (1U & 
                                               (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                [0x37U] 
                                                >> 1U))))),3);
        bufp->chgBit(oldp+14,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s)) 
                                  & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x37U] >> 1U)))));
        bufp->chgBit(oldp+15,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+16,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x37U] >> 1U))));
        bufp->chgCData(oldp+17,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x37U] << 2U)) 
                                 | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                          >> 3U)))),3);
        bufp->chgBit(oldp+18,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x37U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                 >> 4U)) 
                                     | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                          >> 4U) | 
                                         vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U]) & 
                                        ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 3U))))));
        bufp->chgBit(oldp+19,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+20,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                               [0x37U])));
        bufp->chgBit(oldp+21,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 4U))));
        bufp->chgBit(oldp+22,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 3U))));
        bufp->chgCData(oldp+23,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+24,((1U & ((IData)((6U == 
                                              (6U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                     | ((IData)((0U 
                                                 != 
                                                 (6U 
                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+26,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 2U))));
        bufp->chgBit(oldp+27,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 1U))));
        bufp->chgBit(oldp+28,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+29,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+30,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s)) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+31,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+32,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                  << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                  >> 5U)))),3);
        bufp->chgBit(oldp+33,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                      & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 6U)) | 
                                     ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                        >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s)) 
                                      & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 5U))))));
        bufp->chgBit(oldp+34,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+35,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 6U))));
        bufp->chgBit(oldp+36,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 5U))));
        bufp->chgCData(oldp+37,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                             << 1U) 
                                            | (1U & 
                                               ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                >> 0xaU))))),3);
        bufp->chgBit(oldp+38,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s)) 
                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xaU)))));
        bufp->chgBit(oldp+39,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+40,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xaU))));
        bufp->chgCData(oldp+41,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                       >> 7U))),3);
        bufp->chgBit(oldp+42,((1U & ((IData)((0x300U 
                                              == (0x300U 
                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                     | ((IData)((0U 
                                                 != 
                                                 (0x300U 
                                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                           >> 7U))))));
        bufp->chgBit(oldp+43,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+44,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 9U))));
        bufp->chgBit(oldp+45,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 8U))));
        bufp->chgBit(oldp+46,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 7U))));
        bufp->chgCData(oldp+47,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                             << 1U) 
                                            | (1U & 
                                               ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                >> 0xbU))))),3);
        bufp->chgBit(oldp+48,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s)) 
                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xbU)))));
        bufp->chgBit(oldp+49,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xbU))));
        bufp->chgCData(oldp+50,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                  << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                  >> 0xcU)))),3);
        bufp->chgBit(oldp+51,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xdU))));
        bufp->chgBit(oldp+52,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xcU))));
        bufp->chgIData(oldp+53,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x38U]),17);
        bufp->chgSData(oldp+54,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+55,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout));
        bufp->chgBit(oldp+56,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                     ^ VL_REDXOR_16(
                                                    (0x3000U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+57,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 3U) 
                                            | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s) 
                                                << 2U) 
                                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+58,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                  << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                             << 2U) 
                                            | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s) 
                                                << 1U) 
                                               | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+59,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                  << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+60,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                  << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+61,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+62,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 0xeU))),3);
        bufp->chgBit(oldp+63,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 0x10U) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 0xfU)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 0xfU) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x38U] 
                                            >> 0x10U)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xeU))))));
        bufp->chgBit(oldp+64,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+65,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 0x10U))));
        bufp->chgBit(oldp+66,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 0xfU))));
        bufp->chgBit(oldp+67,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 0xeU))));
        bufp->chgCData(oldp+68,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 0xbU))),3);
        bufp->chgBit(oldp+69,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 0xdU) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 0xcU)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 0xcU) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x38U] 
                                            >> 0xdU)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xbU))))));
        bufp->chgBit(oldp+70,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+71,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 0xdU))));
        bufp->chgBit(oldp+72,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 0xcU))));
        bufp->chgBit(oldp+73,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 0xbU))));
        bufp->chgCData(oldp+74,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 8U))),3);
        bufp->chgBit(oldp+75,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 0xaU) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 9U)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 9U) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x38U] 
                                            >> 0xaU)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 8U))))));
        bufp->chgBit(oldp+76,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+77,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 0xaU))));
        bufp->chgBit(oldp+78,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 9U))));
        bufp->chgBit(oldp+79,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 8U))));
        bufp->chgCData(oldp+80,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 5U))),3);
        bufp->chgBit(oldp+81,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 7U) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 6U)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 6U) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x38U] 
                                            >> 7U)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 5U))))));
        bufp->chgBit(oldp+82,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+83,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 7U))));
        bufp->chgBit(oldp+84,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 6U))));
        bufp->chgBit(oldp+85,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 5U))));
        bufp->chgCData(oldp+86,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 2U))),3);
        bufp->chgBit(oldp+87,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] >> 4U) 
                                      & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U] >> 3U)) 
                                     | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 3U) 
                                         | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x38U] 
                                            >> 4U)) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x38U] 
                                           >> 2U))))));
        bufp->chgBit(oldp+88,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+89,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 4U))));
        bufp->chgBit(oldp+90,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 3U))));
        bufp->chgBit(oldp+91,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 2U))));
        bufp->chgCData(oldp+92,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+93,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s)) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+94,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+95,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                             << 1U) 
                                            | (1U & 
                                               (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                [0x38U] 
                                                >> 1U))))),3);
        bufp->chgBit(oldp+96,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)) 
                               | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s)) 
                                  & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 1U)))));
        bufp->chgBit(oldp+97,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+98,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                     [0x38U] >> 1U))));
        bufp->chgCData(oldp+99,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x38U] << 2U)) 
                                 | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 3U)))),3);
        bufp->chgBit(oldp+100,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x38U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+101,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+102,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x38U])));
        bufp->chgBit(oldp+103,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+104,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+105,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+106,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+107,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+108,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+109,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+110,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+111,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+112,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+113,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+114,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+115,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+116,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+117,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+118,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+119,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+120,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+121,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+122,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+123,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+124,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+125,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+126,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+127,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+128,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+129,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+130,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+131,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+132,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+133,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+134,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+135,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x39U]),17);
        bufp->chgSData(oldp+136,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+137,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout));
        bufp->chgBit(oldp+138,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+139,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+140,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+141,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+142,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+143,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+144,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 0xeU))),3);
        bufp->chgBit(oldp+145,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x39U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x39U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+146,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+147,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0x10U))));
        bufp->chgBit(oldp+148,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xfU))));
        bufp->chgBit(oldp+149,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xeU))));
        bufp->chgCData(oldp+150,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 0xbU))),3);
        bufp->chgBit(oldp+151,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x39U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x39U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+152,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+153,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xdU))));
        bufp->chgBit(oldp+154,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xcU))));
        bufp->chgBit(oldp+155,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xbU))));
        bufp->chgCData(oldp+156,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 8U))),3);
        bufp->chgBit(oldp+157,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x39U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+158,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+159,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 0xaU))));
        bufp->chgBit(oldp+160,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 9U))));
        bufp->chgBit(oldp+161,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 8U))));
        bufp->chgCData(oldp+162,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 5U))),3);
        bufp->chgBit(oldp+163,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x39U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+164,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+165,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 7U))));
        bufp->chgBit(oldp+166,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 6U))));
        bufp->chgBit(oldp+167,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 5U))));
        bufp->chgCData(oldp+168,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 2U))),3);
        bufp->chgBit(oldp+169,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x39U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x39U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x39U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+170,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+171,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 4U))));
        bufp->chgBit(oldp+172,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 3U))));
        bufp->chgBit(oldp+173,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 2U))));
        bufp->chgCData(oldp+174,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+175,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+176,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+177,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x39U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+178,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 1U)))));
        bufp->chgBit(oldp+179,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+180,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x39U] >> 1U))));
        bufp->chgCData(oldp+181,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x39U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+182,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x39U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+183,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+184,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x39U])));
        bufp->chgBit(oldp+185,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+186,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+187,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+188,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+189,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+190,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+191,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+192,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+193,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+194,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+195,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+196,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+197,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+198,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+199,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+200,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+201,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+202,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+203,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+204,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+205,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+206,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+207,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+208,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+209,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+210,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+211,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+212,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+213,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+214,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+215,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+216,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+217,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x3aU]),17);
        bufp->chgSData(oldp+218,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+219,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout));
        bufp->chgBit(oldp+220,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+221,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+222,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+223,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+224,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+225,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+226,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 0xeU))),3);
        bufp->chgBit(oldp+227,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+228,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+229,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0x10U))));
        bufp->chgBit(oldp+230,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xfU))));
        bufp->chgBit(oldp+231,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xeU))));
        bufp->chgCData(oldp+232,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 0xbU))),3);
        bufp->chgBit(oldp+233,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+234,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+235,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xdU))));
        bufp->chgBit(oldp+236,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xcU))));
        bufp->chgBit(oldp+237,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xbU))));
        bufp->chgCData(oldp+238,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 8U))),3);
        bufp->chgBit(oldp+239,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+240,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+241,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 0xaU))));
        bufp->chgBit(oldp+242,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 9U))));
        bufp->chgBit(oldp+243,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 8U))));
        bufp->chgCData(oldp+244,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 5U))),3);
        bufp->chgBit(oldp+245,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+246,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+247,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 7U))));
        bufp->chgBit(oldp+248,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 6U))));
        bufp->chgBit(oldp+249,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 5U))));
        bufp->chgCData(oldp+250,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 2U))),3);
        bufp->chgBit(oldp+251,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3aU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+252,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+253,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 4U))));
        bufp->chgBit(oldp+254,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 3U))));
        bufp->chgBit(oldp+255,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 2U))));
        bufp->chgCData(oldp+256,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+257,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+258,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+259,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x3aU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+260,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 1U)))));
        bufp->chgBit(oldp+261,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+262,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3aU] >> 1U))));
        bufp->chgCData(oldp+263,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3aU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+264,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3aU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+265,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+266,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x3aU])));
        bufp->chgBit(oldp+267,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+268,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+269,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+270,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+271,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+272,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+273,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+274,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+275,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+276,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+277,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+278,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+279,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+280,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+281,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+282,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+283,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+284,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+285,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+286,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+287,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+288,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+289,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+290,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+291,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+292,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+293,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+294,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+295,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+296,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+297,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+298,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+299,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x3bU]),17);
        bufp->chgSData(oldp+300,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+301,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout));
        bufp->chgBit(oldp+302,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+303,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+304,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+305,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+306,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+307,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+308,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 0xeU))),3);
        bufp->chgBit(oldp+309,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+310,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+311,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0x10U))));
        bufp->chgBit(oldp+312,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xfU))));
        bufp->chgBit(oldp+313,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xeU))));
        bufp->chgCData(oldp+314,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 0xbU))),3);
        bufp->chgBit(oldp+315,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+316,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+317,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xdU))));
        bufp->chgBit(oldp+318,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xcU))));
        bufp->chgBit(oldp+319,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xbU))));
        bufp->chgCData(oldp+320,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 8U))),3);
        bufp->chgBit(oldp+321,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+322,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+323,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 0xaU))));
        bufp->chgBit(oldp+324,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 9U))));
        bufp->chgBit(oldp+325,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 8U))));
        bufp->chgCData(oldp+326,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 5U))),3);
        bufp->chgBit(oldp+327,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+328,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+329,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 7U))));
        bufp->chgBit(oldp+330,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 6U))));
        bufp->chgBit(oldp+331,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 5U))));
        bufp->chgCData(oldp+332,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 2U))),3);
        bufp->chgBit(oldp+333,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3bU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+334,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+335,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 4U))));
        bufp->chgBit(oldp+336,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 3U))));
        bufp->chgBit(oldp+337,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 2U))));
        bufp->chgCData(oldp+338,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+339,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+340,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+341,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x3bU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+342,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 1U)))));
        bufp->chgBit(oldp+343,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+344,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3bU] >> 1U))));
        bufp->chgCData(oldp+345,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3bU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+346,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3bU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+347,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+348,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x3bU])));
        bufp->chgBit(oldp+349,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+350,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+351,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+352,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+353,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+354,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+355,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+356,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+357,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+358,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+359,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+360,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+361,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+362,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+363,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+364,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+365,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+366,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+367,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+368,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+369,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+370,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+371,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+372,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+373,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+374,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+375,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+376,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+377,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+378,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+379,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+380,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+381,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x3cU]),17);
        bufp->chgSData(oldp+382,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+383,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout));
        bufp->chgBit(oldp+384,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+385,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+386,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+387,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+388,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+389,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+390,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 0xeU))),3);
        bufp->chgBit(oldp+391,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+392,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+393,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0x10U))));
        bufp->chgBit(oldp+394,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xfU))));
        bufp->chgBit(oldp+395,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xeU))));
        bufp->chgCData(oldp+396,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 0xbU))),3);
        bufp->chgBit(oldp+397,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+398,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+399,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xdU))));
        bufp->chgBit(oldp+400,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xcU))));
        bufp->chgBit(oldp+401,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xbU))));
        bufp->chgCData(oldp+402,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 8U))),3);
        bufp->chgBit(oldp+403,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+404,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+405,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 0xaU))));
        bufp->chgBit(oldp+406,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 9U))));
        bufp->chgBit(oldp+407,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 8U))));
        bufp->chgCData(oldp+408,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 5U))),3);
        bufp->chgBit(oldp+409,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+410,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+411,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 7U))));
        bufp->chgBit(oldp+412,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 6U))));
        bufp->chgBit(oldp+413,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 5U))));
        bufp->chgCData(oldp+414,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 2U))),3);
        bufp->chgBit(oldp+415,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3cU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+416,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+417,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 4U))));
        bufp->chgBit(oldp+418,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 3U))));
        bufp->chgBit(oldp+419,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 2U))));
        bufp->chgCData(oldp+420,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+421,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+422,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+423,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x3cU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+424,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 1U)))));
        bufp->chgBit(oldp+425,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+426,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3cU] >> 1U))));
        bufp->chgCData(oldp+427,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3cU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+428,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3cU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+429,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+430,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x3cU])));
        bufp->chgBit(oldp+431,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+432,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+433,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+434,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+435,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+436,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+437,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+438,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+439,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+440,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+441,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+442,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+443,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+444,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+445,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+446,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+447,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+448,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+449,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+450,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+451,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+452,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+453,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+454,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+455,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+456,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+457,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+458,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+459,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+460,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+461,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+462,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+463,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x3dU]),17);
        bufp->chgSData(oldp+464,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+465,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout));
        bufp->chgBit(oldp+466,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+467,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+468,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+469,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+470,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+471,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+472,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 0xeU))),3);
        bufp->chgBit(oldp+473,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+474,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+475,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0x10U))));
        bufp->chgBit(oldp+476,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xfU))));
        bufp->chgBit(oldp+477,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xeU))));
        bufp->chgCData(oldp+478,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 0xbU))),3);
        bufp->chgBit(oldp+479,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+480,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+481,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xdU))));
        bufp->chgBit(oldp+482,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xcU))));
        bufp->chgBit(oldp+483,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xbU))));
        bufp->chgCData(oldp+484,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 8U))),3);
        bufp->chgBit(oldp+485,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+486,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+487,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 0xaU))));
        bufp->chgBit(oldp+488,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 9U))));
        bufp->chgBit(oldp+489,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 8U))));
        bufp->chgCData(oldp+490,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 5U))),3);
        bufp->chgBit(oldp+491,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+492,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+493,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 7U))));
        bufp->chgBit(oldp+494,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 6U))));
        bufp->chgBit(oldp+495,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 5U))));
        bufp->chgCData(oldp+496,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 2U))),3);
        bufp->chgBit(oldp+497,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3dU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+498,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+499,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 4U))));
        bufp->chgBit(oldp+500,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 3U))));
        bufp->chgBit(oldp+501,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 2U))));
        bufp->chgCData(oldp+502,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+503,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+504,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+505,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x3dU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+506,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 1U)))));
        bufp->chgBit(oldp+507,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+508,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3dU] >> 1U))));
        bufp->chgCData(oldp+509,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3dU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+510,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3dU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+511,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+512,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x3dU])));
        bufp->chgBit(oldp+513,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+514,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+515,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+516,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+517,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+518,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+519,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+520,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+521,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+522,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+523,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+524,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+525,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+526,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+527,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+528,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+529,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+530,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+531,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+532,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+533,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+534,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+535,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+536,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+537,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+538,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+539,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+540,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+541,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+542,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+543,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+544,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+545,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x3eU]),17);
        bufp->chgSData(oldp+546,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+547,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout));
        bufp->chgBit(oldp+548,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+549,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+550,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+551,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+552,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+553,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+554,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 0xeU))),3);
        bufp->chgBit(oldp+555,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+556,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+557,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0x10U))));
        bufp->chgBit(oldp+558,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xfU))));
        bufp->chgBit(oldp+559,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xeU))));
        bufp->chgCData(oldp+560,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 0xbU))),3);
        bufp->chgBit(oldp+561,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+562,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+563,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xdU))));
        bufp->chgBit(oldp+564,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xcU))));
        bufp->chgBit(oldp+565,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xbU))));
        bufp->chgCData(oldp+566,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 8U))),3);
        bufp->chgBit(oldp+567,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+568,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+569,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 0xaU))));
        bufp->chgBit(oldp+570,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 9U))));
        bufp->chgBit(oldp+571,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 8U))));
        bufp->chgCData(oldp+572,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 5U))),3);
        bufp->chgBit(oldp+573,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+574,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+575,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 7U))));
        bufp->chgBit(oldp+576,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 6U))));
        bufp->chgBit(oldp+577,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 5U))));
        bufp->chgCData(oldp+578,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 2U))),3);
        bufp->chgBit(oldp+579,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3eU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+580,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+581,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 4U))));
        bufp->chgBit(oldp+582,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 3U))));
        bufp->chgBit(oldp+583,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 2U))));
        bufp->chgCData(oldp+584,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+585,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+586,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+587,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x3eU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+588,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 1U)))));
        bufp->chgBit(oldp+589,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+590,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3eU] >> 1U))));
        bufp->chgCData(oldp+591,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3eU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+592,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3eU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+594,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x3eU])));
        bufp->chgBit(oldp+595,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+596,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+597,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+598,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+599,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+600,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+601,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+602,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+603,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+604,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+605,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+606,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+607,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+608,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+609,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+610,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+611,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+612,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+613,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+614,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+615,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+616,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+617,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+618,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+619,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+620,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+621,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+622,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+623,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+624,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+625,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+626,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+627,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x3fU]),17);
        bufp->chgSData(oldp+628,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+629,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout));
        bufp->chgBit(oldp+630,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+631,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+632,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+633,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+634,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+635,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+636,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 0xeU))),3);
        bufp->chgBit(oldp+637,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+638,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+639,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0x10U))));
        bufp->chgBit(oldp+640,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xfU))));
        bufp->chgBit(oldp+641,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xeU))));
        bufp->chgCData(oldp+642,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 0xbU))),3);
        bufp->chgBit(oldp+643,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+644,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+645,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xdU))));
        bufp->chgBit(oldp+646,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xcU))));
        bufp->chgBit(oldp+647,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xbU))));
        bufp->chgCData(oldp+648,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 8U))),3);
        bufp->chgBit(oldp+649,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+650,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+651,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 0xaU))));
        bufp->chgBit(oldp+652,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 9U))));
        bufp->chgBit(oldp+653,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 8U))));
        bufp->chgCData(oldp+654,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 5U))),3);
        bufp->chgBit(oldp+655,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+656,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+657,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 7U))));
        bufp->chgBit(oldp+658,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 6U))));
        bufp->chgBit(oldp+659,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 5U))));
        bufp->chgCData(oldp+660,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 2U))),3);
        bufp->chgBit(oldp+661,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x3fU] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+662,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+663,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 4U))));
        bufp->chgBit(oldp+664,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 3U))));
        bufp->chgBit(oldp+665,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 2U))));
        bufp->chgCData(oldp+666,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+667,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+668,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+669,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x3fU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+670,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 1U)))));
        bufp->chgBit(oldp+671,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+672,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x3fU] >> 1U))));
        bufp->chgCData(oldp+673,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3fU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+674,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x3fU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+675,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+676,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x3fU])));
        bufp->chgBit(oldp+677,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+678,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+679,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+680,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+681,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+682,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+683,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+684,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+685,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+686,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+687,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+688,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+689,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+690,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+691,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+692,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+693,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+694,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+695,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+696,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+697,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+698,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+699,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+700,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+701,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+702,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+703,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+704,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+705,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+706,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+707,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+708,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+709,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x40U]),17);
        bufp->chgSData(oldp+710,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+711,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout));
        bufp->chgBit(oldp+712,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+713,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+714,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+715,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+716,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+717,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+718,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 0xeU))),3);
        bufp->chgBit(oldp+719,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x40U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x40U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+720,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+721,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0x10U))));
        bufp->chgBit(oldp+722,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xfU))));
        bufp->chgBit(oldp+723,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xeU))));
        bufp->chgCData(oldp+724,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 0xbU))),3);
        bufp->chgBit(oldp+725,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x40U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x40U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+726,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+727,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xdU))));
        bufp->chgBit(oldp+728,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xcU))));
        bufp->chgBit(oldp+729,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xbU))));
        bufp->chgCData(oldp+730,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 8U))),3);
        bufp->chgBit(oldp+731,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x40U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+732,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+733,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 0xaU))));
        bufp->chgBit(oldp+734,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 9U))));
        bufp->chgBit(oldp+735,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 8U))));
        bufp->chgCData(oldp+736,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 5U))),3);
        bufp->chgBit(oldp+737,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x40U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+738,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+739,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 7U))));
        bufp->chgBit(oldp+740,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 6U))));
        bufp->chgBit(oldp+741,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 5U))));
        bufp->chgCData(oldp+742,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 2U))),3);
        bufp->chgBit(oldp+743,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x40U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x40U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x40U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+744,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+745,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 4U))));
        bufp->chgBit(oldp+746,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 3U))));
        bufp->chgBit(oldp+747,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 2U))));
        bufp->chgCData(oldp+748,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+749,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+750,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+751,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x40U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+752,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 1U)))));
        bufp->chgBit(oldp+753,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+754,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x40U] >> 1U))));
        bufp->chgCData(oldp+755,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x40U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+756,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x40U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+757,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+758,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x40U])));
        bufp->chgBit(oldp+759,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+760,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+761,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+762,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+763,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+764,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+765,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+766,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+767,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+768,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+769,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+770,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+771,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+772,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+773,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+774,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+775,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+776,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+777,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+778,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+779,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+780,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+781,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+782,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+783,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+784,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+785,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+786,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+787,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+788,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+789,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+790,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+791,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x41U]),17);
        bufp->chgSData(oldp+792,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+793,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout));
        bufp->chgBit(oldp+794,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+795,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+796,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+797,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+798,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+799,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+800,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 0xeU))),3);
        bufp->chgBit(oldp+801,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x41U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x41U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+802,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+803,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0x10U))));
        bufp->chgBit(oldp+804,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xfU))));
        bufp->chgBit(oldp+805,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xeU))));
        bufp->chgCData(oldp+806,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 0xbU))),3);
        bufp->chgBit(oldp+807,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x41U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x41U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+808,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+809,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xdU))));
        bufp->chgBit(oldp+810,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xcU))));
        bufp->chgBit(oldp+811,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xbU))));
        bufp->chgCData(oldp+812,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 8U))),3);
        bufp->chgBit(oldp+813,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x41U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+814,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+815,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 0xaU))));
        bufp->chgBit(oldp+816,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 9U))));
        bufp->chgBit(oldp+817,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 8U))));
        bufp->chgCData(oldp+818,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 5U))),3);
        bufp->chgBit(oldp+819,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x41U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+820,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+821,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 7U))));
        bufp->chgBit(oldp+822,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 6U))));
        bufp->chgBit(oldp+823,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 5U))));
        bufp->chgCData(oldp+824,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 2U))),3);
        bufp->chgBit(oldp+825,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x41U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x41U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x41U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+826,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+827,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 4U))));
        bufp->chgBit(oldp+828,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 3U))));
        bufp->chgBit(oldp+829,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 2U))));
        bufp->chgCData(oldp+830,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+831,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+832,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+833,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x41U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+834,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 1U)))));
        bufp->chgBit(oldp+835,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+836,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x41U] >> 1U))));
        bufp->chgCData(oldp+837,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x41U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+838,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x41U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+839,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+840,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x41U])));
        bufp->chgBit(oldp+841,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+842,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+843,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+844,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+845,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+846,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+847,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+848,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+849,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+850,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+851,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+852,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+853,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+854,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+855,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+856,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+857,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+858,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+859,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+860,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+861,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+862,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+863,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+864,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+865,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+866,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+867,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+868,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+869,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+870,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+871,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+872,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+873,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x42U]),17);
        bufp->chgSData(oldp+874,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+875,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout));
        bufp->chgBit(oldp+876,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+877,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+878,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+879,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+880,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+881,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+882,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 0xeU))),3);
        bufp->chgBit(oldp+883,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x42U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x42U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+884,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+885,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0x10U))));
        bufp->chgBit(oldp+886,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xfU))));
        bufp->chgBit(oldp+887,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xeU))));
        bufp->chgCData(oldp+888,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 0xbU))),3);
        bufp->chgBit(oldp+889,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x42U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x42U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+890,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+891,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xdU))));
        bufp->chgBit(oldp+892,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xcU))));
        bufp->chgBit(oldp+893,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xbU))));
        bufp->chgCData(oldp+894,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 8U))),3);
        bufp->chgBit(oldp+895,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x42U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+896,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+897,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 0xaU))));
        bufp->chgBit(oldp+898,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 9U))));
        bufp->chgBit(oldp+899,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 8U))));
        bufp->chgCData(oldp+900,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 5U))),3);
        bufp->chgBit(oldp+901,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x42U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+902,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+903,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 7U))));
        bufp->chgBit(oldp+904,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 6U))));
        bufp->chgBit(oldp+905,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 5U))));
        bufp->chgCData(oldp+906,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 2U))),3);
        bufp->chgBit(oldp+907,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x42U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x42U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x42U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+908,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+909,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 4U))));
        bufp->chgBit(oldp+910,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 3U))));
        bufp->chgBit(oldp+911,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 2U))));
        bufp->chgCData(oldp+912,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+913,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+914,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+915,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x42U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+916,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 1U)))));
        bufp->chgBit(oldp+917,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+918,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x42U] >> 1U))));
        bufp->chgCData(oldp+919,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x42U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+920,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x42U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U]) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+921,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+922,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0x42U])));
        bufp->chgBit(oldp+923,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+924,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+925,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+926,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+927,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+928,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+929,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+930,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+931,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+932,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+933,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+934,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+935,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+936,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+937,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+938,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+939,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+940,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+941,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+942,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+943,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+944,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+945,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+946,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+947,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+948,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+949,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+950,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+951,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+952,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+953,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+954,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+955,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x43U]),17);
        bufp->chgSData(oldp+956,((((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
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
                                     | ((0x800U & (
                                                   ((IData)(
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
        bufp->chgBit(oldp+957,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.cout));
        bufp->chgBit(oldp+958,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+959,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+960,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+961,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+962,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+963,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+964,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 0xeU))),3);
        bufp->chgBit(oldp+965,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x43U] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x43U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+966,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+967,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0x10U))));
        bufp->chgBit(oldp+968,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xfU))));
        bufp->chgBit(oldp+969,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xeU))));
        bufp->chgCData(oldp+970,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 0xbU))),3);
        bufp->chgBit(oldp+971,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x43U] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x43U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+972,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+973,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xdU))));
        bufp->chgBit(oldp+974,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xcU))));
        bufp->chgBit(oldp+975,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xbU))));
        bufp->chgCData(oldp+976,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 8U))),3);
        bufp->chgBit(oldp+977,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 9U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x43U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+978,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+979,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 0xaU))));
        bufp->chgBit(oldp+980,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 9U))));
        bufp->chgBit(oldp+981,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 8U))));
        bufp->chgCData(oldp+982,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 5U))),3);
        bufp->chgBit(oldp+983,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 6U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x43U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+984,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+985,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 7U))));
        bufp->chgBit(oldp+986,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 6U))));
        bufp->chgBit(oldp+987,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 5U))));
        bufp->chgCData(oldp+988,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 2U))),3);
        bufp->chgBit(oldp+989,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 3U) | 
                                          (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U] 
                                           >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x43U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+990,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+991,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 4U))));
        bufp->chgBit(oldp+992,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 3U))));
        bufp->chgBit(oldp+993,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 2U))));
        bufp->chgCData(oldp+994,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+995,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+996,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+997,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0x43U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+998,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0x43U] >> 1U)))));
        bufp->chgBit(oldp+999,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1000,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x43U] >> 1U))));
        bufp->chgCData(oldp+1001,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1002,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x43U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x43U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1003,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1004,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x43U])));
        bufp->chgBit(oldp+1005,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1006,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1007,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1008,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1009,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1010,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1011,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1012,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1013,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1014,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1015,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1016,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1017,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1018,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1019,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1020,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1021,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1022,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1023,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1024,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1025,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1026,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1027,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1028,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1029,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1030,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1031,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1032,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1033,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1034,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1035,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1036,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
    }
    bufp->chgBit(oldp+1037,(vlSelf->clk));
    bufp->chgBit(oldp+1038,(vlSelf->rst_n));
    bufp->chgIData(oldp+1039,(vlSelf->multiplicand),32);
    bufp->chgIData(oldp+1040,(vlSelf->multiplier),32);
    bufp->chgBit(oldp+1041,(vlSelf->is_signed));
    bufp->chgQData(oldp+1042,(vlSelf->product),64);
    bufp->chgBit(oldp+1044,(vlSelf->valid));
}

void Vbooth_wallace_multiplier___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root__trace_cleanup\n"); );
    // Init
    Vbooth_wallace_multiplier___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbooth_wallace_multiplier___024root*>(voidSelf);
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
