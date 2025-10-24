// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpu__Syms.h"


void Vfpu___024root__trace_chg_sub_2(Vfpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root__trace_chg_sub_2\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 4739);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 0xaU))));
        bufp->chgBit(oldp+2,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 9U))));
        bufp->chgBit(oldp+3,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 8U))));
        bufp->chgCData(oldp+4,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] >> 5U))),3);
        bufp->chgBit(oldp+5,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
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
        bufp->chgBit(oldp+6,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+7,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 7U))));
        bufp->chgBit(oldp+8,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 6U))));
        bufp->chgBit(oldp+9,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                    [0x37U] >> 5U))));
        bufp->chgCData(oldp+10,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x37U] >> 2U))),3);
        bufp->chgBit(oldp+11,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x37U] >> 4U) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x37U] >> 3U)) 
                                     | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x37U] >> 3U) 
                                         | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x37U] 
                                            >> 4U)) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x37U] 
                                           >> 2U))))));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+13,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x37U] >> 4U))));
        bufp->chgBit(oldp+14,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x37U] >> 3U))));
        bufp->chgBit(oldp+15,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x37U] >> 2U))));
        bufp->chgCData(oldp+16,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+17,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s) 
                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s)) 
                               | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa1__s) 
                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa0__s)) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+18,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+19,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                             << 1U) 
                                            | (1U & 
                                               (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                [0x37U] 
                                                >> 1U))))),3);
        bufp->chgBit(oldp+20,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s) 
                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s)) 
                               | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa4__s) 
                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa3__s)) 
                                  & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x37U] >> 1U)))));
        bufp->chgBit(oldp+21,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+22,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x37U] >> 1U))));
        bufp->chgCData(oldp+23,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x37U] << 2U)) 
                                 | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                          >> 3U)))),3);
        bufp->chgBit(oldp+24,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x37U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                 >> 4U)) 
                                     | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                          >> 4U) | 
                                         vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x37U]) & 
                                        ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 3U))))));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+26,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                               [0x37U])));
        bufp->chgBit(oldp+27,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 4U))));
        bufp->chgBit(oldp+28,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 3U))));
        bufp->chgCData(oldp+29,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+30,((1U & ((IData)((6U == 
                                              (6U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                     | ((IData)((0U 
                                                 != 
                                                 (6U 
                                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                        & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+31,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+32,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 2U))));
        bufp->chgBit(oldp+33,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 1U))));
        bufp->chgBit(oldp+34,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+35,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+36,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s) 
                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s)) 
                               | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa6__s) 
                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa5__s)) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+37,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+38,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                  << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                  >> 5U)))),3);
        bufp->chgBit(oldp+39,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s) 
                                      & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 6U)) | 
                                     ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                        >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa8__s)) 
                                      & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                         >> 5U))))));
        bufp->chgBit(oldp+40,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+41,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 6U))));
        bufp->chgBit(oldp+42,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 5U))));
        bufp->chgCData(oldp+43,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                             << 1U) 
                                            | (1U & 
                                               ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                >> 0xaU))))),3);
        bufp->chgBit(oldp+44,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s) 
                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s)) 
                               | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaA__s) 
                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csa9__s)) 
                                  & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xaU)))));
        bufp->chgBit(oldp+45,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+46,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xaU))));
        bufp->chgCData(oldp+47,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                       >> 7U))),3);
        bufp->chgBit(oldp+48,((1U & ((IData)((0x300U 
                                              == (0x300U 
                                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                     | ((IData)((0U 
                                                 != 
                                                 (0x300U 
                                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                           >> 7U))))));
        bufp->chgBit(oldp+49,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+50,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 9U))));
        bufp->chgBit(oldp+51,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 8U))));
        bufp->chgBit(oldp+52,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 7U))));
        bufp->chgCData(oldp+53,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                             << 1U) 
                                            | (1U & 
                                               ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                >> 0xbU))))),3);
        bufp->chgBit(oldp+54,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s) 
                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s)) 
                               | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaC__s) 
                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__Vcellout__csaB__s)) 
                                  & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xbU)))));
        bufp->chgBit(oldp+55,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xbU))));
        bufp->chgCData(oldp+56,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                  << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                  >> 0xcU)))),3);
        bufp->chgBit(oldp+57,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xdU))));
        bufp->chgBit(oldp+58,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                     >> 0xcU))));
        bufp->chgIData(oldp+59,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x38U]),17);
        bufp->chgSData(oldp+60,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+61,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout));
        bufp->chgBit(oldp+62,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                     ^ VL_REDXOR_16(
                                                    (0x3000U 
                                                     & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+63,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 3U) 
                                            | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s) 
                                                << 2U) 
                                               | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+64,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                  << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                             << 2U) 
                                            | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s) 
                                                << 1U) 
                                               | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+65,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                  << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+66,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                  << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+67,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+68,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 0xeU))),3);
        bufp->chgBit(oldp+69,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 0x10U) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 0xfU)) 
                                     | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 0xfU) 
                                         | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x38U] 
                                            >> 0x10U)) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xeU))))));
        bufp->chgBit(oldp+70,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+71,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 0x10U))));
        bufp->chgBit(oldp+72,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 0xfU))));
        bufp->chgBit(oldp+73,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 0xeU))));
        bufp->chgCData(oldp+74,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 0xbU))),3);
        bufp->chgBit(oldp+75,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 0xdU) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 0xcU)) 
                                     | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 0xcU) 
                                         | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x38U] 
                                            >> 0xdU)) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 0xbU))))));
        bufp->chgBit(oldp+76,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+77,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 0xdU))));
        bufp->chgBit(oldp+78,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 0xcU))));
        bufp->chgBit(oldp+79,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 0xbU))));
        bufp->chgCData(oldp+80,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 8U))),3);
        bufp->chgBit(oldp+81,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 0xaU) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 9U)) 
                                     | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 9U) 
                                         | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x38U] 
                                            >> 0xaU)) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 8U))))));
        bufp->chgBit(oldp+82,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+83,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 0xaU))));
        bufp->chgBit(oldp+84,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 9U))));
        bufp->chgBit(oldp+85,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 8U))));
        bufp->chgCData(oldp+86,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 5U))),3);
        bufp->chgBit(oldp+87,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 7U) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 6U)) 
                                     | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 6U) 
                                         | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x38U] 
                                            >> 7U)) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 5U))))));
        bufp->chgBit(oldp+88,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+89,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 7U))));
        bufp->chgBit(oldp+90,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 6U))));
        bufp->chgBit(oldp+91,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 5U))));
        bufp->chgCData(oldp+92,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 2U))),3);
        bufp->chgBit(oldp+93,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] >> 4U) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] >> 3U)) 
                                     | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U] >> 3U) 
                                         | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x38U] 
                                            >> 4U)) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x38U] 
                                           >> 2U))))));
        bufp->chgBit(oldp+94,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+95,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 4U))));
        bufp->chgBit(oldp+96,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 3U))));
        bufp->chgBit(oldp+97,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                     [0x38U] >> 2U))));
        bufp->chgCData(oldp+98,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                  << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                             << 1U) 
                                            | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+99,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s) 
                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s)) 
                               | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa1__s) 
                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa0__s)) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+100,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+101,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x38U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+102,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 1U)))));
        bufp->chgBit(oldp+103,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+104,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x38U] >> 1U))));
        bufp->chgCData(oldp+105,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x38U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+106,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x38U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x38U]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+107,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+108,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x38U])));
        bufp->chgBit(oldp+109,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+110,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+111,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+112,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+113,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+114,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+115,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+116,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+117,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+118,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+119,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+120,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+121,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+122,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+123,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+124,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+125,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+126,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+127,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+128,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+129,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+130,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+131,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+132,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+133,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+134,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+135,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+136,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+137,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+138,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+139,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+140,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+141,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x39U]),17);
        bufp->chgSData(oldp+142,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+143,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout));
        bufp->chgBit(oldp+144,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+145,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+146,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+147,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+148,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+149,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+150,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 0xeU))),3);
        bufp->chgBit(oldp+151,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x39U] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x39U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+152,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+153,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0x10U))));
        bufp->chgBit(oldp+154,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xfU))));
        bufp->chgBit(oldp+155,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xeU))));
        bufp->chgCData(oldp+156,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 0xbU))),3);
        bufp->chgBit(oldp+157,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x39U] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x39U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+158,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+159,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xdU))));
        bufp->chgBit(oldp+160,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xcU))));
        bufp->chgBit(oldp+161,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xbU))));
        bufp->chgCData(oldp+162,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 8U))),3);
        bufp->chgBit(oldp+163,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x39U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+164,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+165,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 0xaU))));
        bufp->chgBit(oldp+166,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 9U))));
        bufp->chgBit(oldp+167,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 8U))));
        bufp->chgCData(oldp+168,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 5U))),3);
        bufp->chgBit(oldp+169,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x39U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+170,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+171,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 7U))));
        bufp->chgBit(oldp+172,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 6U))));
        bufp->chgBit(oldp+173,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 5U))));
        bufp->chgCData(oldp+174,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 2U))),3);
        bufp->chgBit(oldp+175,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x39U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x39U] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x39U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+176,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+177,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 4U))));
        bufp->chgBit(oldp+178,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 3U))));
        bufp->chgBit(oldp+179,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 2U))));
        bufp->chgCData(oldp+180,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+181,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+182,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+183,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x39U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+184,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 1U)))));
        bufp->chgBit(oldp+185,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+186,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x39U] >> 1U))));
        bufp->chgCData(oldp+187,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x39U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+188,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x39U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x39U]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+189,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+190,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x39U])));
        bufp->chgBit(oldp+191,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+192,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+193,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+194,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+195,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+196,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+197,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+198,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+199,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+200,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+201,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+202,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+203,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+204,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+205,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+206,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+207,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+208,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+209,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+210,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+211,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+212,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+213,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+214,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+215,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+216,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+217,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+218,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+219,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+220,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+221,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+222,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+223,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x3aU]),17);
        bufp->chgSData(oldp+224,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+225,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout));
        bufp->chgBit(oldp+226,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+227,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+228,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+229,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+230,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+231,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+232,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 0xeU))),3);
        bufp->chgBit(oldp+233,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+234,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+235,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0x10U))));
        bufp->chgBit(oldp+236,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xfU))));
        bufp->chgBit(oldp+237,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xeU))));
        bufp->chgCData(oldp+238,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 0xbU))),3);
        bufp->chgBit(oldp+239,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+240,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+241,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xdU))));
        bufp->chgBit(oldp+242,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xcU))));
        bufp->chgBit(oldp+243,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xbU))));
        bufp->chgCData(oldp+244,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 8U))),3);
        bufp->chgBit(oldp+245,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+246,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+247,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 0xaU))));
        bufp->chgBit(oldp+248,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 9U))));
        bufp->chgBit(oldp+249,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 8U))));
        bufp->chgCData(oldp+250,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 5U))),3);
        bufp->chgBit(oldp+251,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+252,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+253,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 7U))));
        bufp->chgBit(oldp+254,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 6U))));
        bufp->chgBit(oldp+255,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 5U))));
        bufp->chgCData(oldp+256,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 2U))),3);
        bufp->chgBit(oldp+257,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3aU] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3aU] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3aU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+258,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+259,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 4U))));
        bufp->chgBit(oldp+260,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 3U))));
        bufp->chgBit(oldp+261,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 2U))));
        bufp->chgCData(oldp+262,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+263,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+264,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+265,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x3aU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+266,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 1U)))));
        bufp->chgBit(oldp+267,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+268,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3aU] >> 1U))));
        bufp->chgCData(oldp+269,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3aU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+270,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3aU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3aU]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+271,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+272,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x3aU])));
        bufp->chgBit(oldp+273,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+274,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+275,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+276,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+277,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+278,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+279,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+280,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+281,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+282,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+283,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+284,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+285,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+286,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+287,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+288,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+289,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+290,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+291,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+292,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+293,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+294,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+295,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+296,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+297,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+298,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+299,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+300,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+301,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+302,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+303,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+304,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+305,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x3bU]),17);
        bufp->chgSData(oldp+306,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+307,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout));
        bufp->chgBit(oldp+308,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+309,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+310,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+311,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+312,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+313,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+314,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 0xeU))),3);
        bufp->chgBit(oldp+315,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+316,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+317,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0x10U))));
        bufp->chgBit(oldp+318,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xfU))));
        bufp->chgBit(oldp+319,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xeU))));
        bufp->chgCData(oldp+320,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 0xbU))),3);
        bufp->chgBit(oldp+321,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+322,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+323,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xdU))));
        bufp->chgBit(oldp+324,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xcU))));
        bufp->chgBit(oldp+325,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xbU))));
        bufp->chgCData(oldp+326,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 8U))),3);
        bufp->chgBit(oldp+327,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+328,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+329,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 0xaU))));
        bufp->chgBit(oldp+330,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 9U))));
        bufp->chgBit(oldp+331,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 8U))));
        bufp->chgCData(oldp+332,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 5U))),3);
        bufp->chgBit(oldp+333,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+334,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+335,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 7U))));
        bufp->chgBit(oldp+336,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 6U))));
        bufp->chgBit(oldp+337,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 5U))));
        bufp->chgCData(oldp+338,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 2U))),3);
        bufp->chgBit(oldp+339,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3bU] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3bU] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3bU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+340,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+341,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 4U))));
        bufp->chgBit(oldp+342,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 3U))));
        bufp->chgBit(oldp+343,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 2U))));
        bufp->chgCData(oldp+344,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+345,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+346,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+347,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x3bU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+348,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 1U)))));
        bufp->chgBit(oldp+349,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+350,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3bU] >> 1U))));
        bufp->chgCData(oldp+351,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3bU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+352,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3bU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3bU]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+353,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+354,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x3bU])));
        bufp->chgBit(oldp+355,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+356,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+357,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+358,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+359,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+360,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+361,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+362,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+363,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+364,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+365,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+366,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+367,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+368,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+369,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+370,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+371,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+372,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+373,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+374,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+375,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+376,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+377,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+378,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+379,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+380,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+381,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+382,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+383,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+384,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+385,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+386,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+387,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x3cU]),17);
        bufp->chgSData(oldp+388,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+389,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout));
        bufp->chgBit(oldp+390,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+391,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+392,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+393,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+394,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+395,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+396,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 0xeU))),3);
        bufp->chgBit(oldp+397,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+398,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+399,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0x10U))));
        bufp->chgBit(oldp+400,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xfU))));
        bufp->chgBit(oldp+401,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xeU))));
        bufp->chgCData(oldp+402,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 0xbU))),3);
        bufp->chgBit(oldp+403,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+404,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+405,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xdU))));
        bufp->chgBit(oldp+406,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xcU))));
        bufp->chgBit(oldp+407,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xbU))));
        bufp->chgCData(oldp+408,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 8U))),3);
        bufp->chgBit(oldp+409,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+410,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+411,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 0xaU))));
        bufp->chgBit(oldp+412,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 9U))));
        bufp->chgBit(oldp+413,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 8U))));
        bufp->chgCData(oldp+414,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 5U))),3);
        bufp->chgBit(oldp+415,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+416,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+417,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 7U))));
        bufp->chgBit(oldp+418,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 6U))));
        bufp->chgBit(oldp+419,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 5U))));
        bufp->chgCData(oldp+420,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 2U))),3);
        bufp->chgBit(oldp+421,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3cU] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3cU] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3cU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+422,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+423,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 4U))));
        bufp->chgBit(oldp+424,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 3U))));
        bufp->chgBit(oldp+425,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 2U))));
        bufp->chgCData(oldp+426,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+427,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+428,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+429,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x3cU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+430,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 1U)))));
        bufp->chgBit(oldp+431,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+432,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3cU] >> 1U))));
        bufp->chgCData(oldp+433,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3cU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+434,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3cU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3cU]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+435,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+436,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x3cU])));
        bufp->chgBit(oldp+437,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+438,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+439,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+440,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+441,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+442,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+443,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+444,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+445,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+446,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+447,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+448,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+449,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+450,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+451,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+452,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+453,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+454,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+455,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+456,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+457,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+458,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+459,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+460,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+461,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+462,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+463,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+464,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+465,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+466,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+467,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+468,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+469,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x3dU]),17);
        bufp->chgSData(oldp+470,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+471,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout));
        bufp->chgBit(oldp+472,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+473,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+474,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+475,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+476,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+477,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+478,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 0xeU))),3);
        bufp->chgBit(oldp+479,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+480,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+481,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0x10U))));
        bufp->chgBit(oldp+482,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xfU))));
        bufp->chgBit(oldp+483,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xeU))));
        bufp->chgCData(oldp+484,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 0xbU))),3);
        bufp->chgBit(oldp+485,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+486,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+487,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xdU))));
        bufp->chgBit(oldp+488,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xcU))));
        bufp->chgBit(oldp+489,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xbU))));
        bufp->chgCData(oldp+490,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 8U))),3);
        bufp->chgBit(oldp+491,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+492,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+493,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 0xaU))));
        bufp->chgBit(oldp+494,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 9U))));
        bufp->chgBit(oldp+495,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 8U))));
        bufp->chgCData(oldp+496,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 5U))),3);
        bufp->chgBit(oldp+497,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+498,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+499,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 7U))));
        bufp->chgBit(oldp+500,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 6U))));
        bufp->chgBit(oldp+501,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 5U))));
        bufp->chgCData(oldp+502,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 2U))),3);
        bufp->chgBit(oldp+503,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3dU] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3dU] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3dU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+504,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+505,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 4U))));
        bufp->chgBit(oldp+506,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 3U))));
        bufp->chgBit(oldp+507,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 2U))));
        bufp->chgCData(oldp+508,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+509,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+510,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+511,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x3dU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+512,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 1U)))));
        bufp->chgBit(oldp+513,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+514,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3dU] >> 1U))));
        bufp->chgCData(oldp+515,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3dU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+516,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3dU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3dU]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+517,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+518,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x3dU])));
        bufp->chgBit(oldp+519,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+520,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+521,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+522,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+523,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+524,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+525,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+526,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+527,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+528,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+529,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+530,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+531,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+532,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+533,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+534,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+535,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+536,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+537,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+538,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+539,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+540,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+541,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+542,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+543,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+544,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+545,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+546,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+547,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+548,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+549,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+550,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+551,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x3eU]),17);
        bufp->chgSData(oldp+552,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+553,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout));
        bufp->chgBit(oldp+554,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+555,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+556,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+557,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+558,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+559,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+560,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 0xeU))),3);
        bufp->chgBit(oldp+561,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+562,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+563,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0x10U))));
        bufp->chgBit(oldp+564,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xfU))));
        bufp->chgBit(oldp+565,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xeU))));
        bufp->chgCData(oldp+566,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 0xbU))),3);
        bufp->chgBit(oldp+567,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+568,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+569,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xdU))));
        bufp->chgBit(oldp+570,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xcU))));
        bufp->chgBit(oldp+571,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xbU))));
        bufp->chgCData(oldp+572,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 8U))),3);
        bufp->chgBit(oldp+573,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+574,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+575,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 0xaU))));
        bufp->chgBit(oldp+576,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 9U))));
        bufp->chgBit(oldp+577,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 8U))));
        bufp->chgCData(oldp+578,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 5U))),3);
        bufp->chgBit(oldp+579,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+580,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+581,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 7U))));
        bufp->chgBit(oldp+582,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 6U))));
        bufp->chgBit(oldp+583,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 5U))));
        bufp->chgCData(oldp+584,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 2U))),3);
        bufp->chgBit(oldp+585,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3eU] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3eU] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3eU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+586,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+587,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 4U))));
        bufp->chgBit(oldp+588,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 3U))));
        bufp->chgBit(oldp+589,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 2U))));
        bufp->chgCData(oldp+590,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+591,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+592,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+593,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x3eU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+594,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 1U)))));
        bufp->chgBit(oldp+595,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+596,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3eU] >> 1U))));
        bufp->chgCData(oldp+597,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3eU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+598,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3eU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3eU]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+599,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+600,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x3eU])));
        bufp->chgBit(oldp+601,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+602,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+603,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+604,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+605,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+606,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+607,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+608,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+609,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+610,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+611,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+612,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+613,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+614,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+615,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+616,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+617,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+618,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+619,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+620,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+621,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+622,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+623,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+624,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+625,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+626,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+627,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+628,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+629,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+630,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+631,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+632,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+633,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x3fU]),17);
        bufp->chgSData(oldp+634,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+635,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout));
        bufp->chgBit(oldp+636,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+637,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+638,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+639,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+640,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+641,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+642,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 0xeU))),3);
        bufp->chgBit(oldp+643,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+644,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+645,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0x10U))));
        bufp->chgBit(oldp+646,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xfU))));
        bufp->chgBit(oldp+647,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xeU))));
        bufp->chgCData(oldp+648,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 0xbU))),3);
        bufp->chgBit(oldp+649,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+650,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+651,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xdU))));
        bufp->chgBit(oldp+652,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xcU))));
        bufp->chgBit(oldp+653,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xbU))));
        bufp->chgCData(oldp+654,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 8U))),3);
        bufp->chgBit(oldp+655,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 8U))))));
        bufp->chgBit(oldp+656,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+657,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 0xaU))));
        bufp->chgBit(oldp+658,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 9U))));
        bufp->chgBit(oldp+659,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 8U))));
        bufp->chgCData(oldp+660,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 5U))),3);
        bufp->chgBit(oldp+661,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+662,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+663,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 7U))));
        bufp->chgBit(oldp+664,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 6U))));
        bufp->chgBit(oldp+665,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 5U))));
        bufp->chgCData(oldp+666,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 2U))),3);
        bufp->chgBit(oldp+667,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x3fU] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x3fU] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x3fU] 
                                            >> 2U))))));
        bufp->chgBit(oldp+668,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+669,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 4U))));
        bufp->chgBit(oldp+670,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 3U))));
        bufp->chgBit(oldp+671,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 2U))));
        bufp->chgCData(oldp+672,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+673,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+674,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+675,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x3fU] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+676,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 1U)))));
        bufp->chgBit(oldp+677,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+678,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x3fU] >> 1U))));
        bufp->chgCData(oldp+679,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x3fU] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+680,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x3fU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x3fU]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+681,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+682,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x3fU])));
        bufp->chgBit(oldp+683,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+684,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+685,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+686,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+687,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+688,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+689,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+690,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+691,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+692,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+693,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+694,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+695,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+696,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+697,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+698,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+699,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+700,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+701,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+702,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+703,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+704,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+705,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+706,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+707,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+708,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+709,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+710,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+711,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+712,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+713,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+714,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+715,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x40U]),17);
        bufp->chgSData(oldp+716,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+717,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout));
        bufp->chgBit(oldp+718,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+719,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+720,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+721,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+722,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+723,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+724,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 0xeU))),3);
        bufp->chgBit(oldp+725,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x40U] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x40U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+726,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+727,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0x10U))));
        bufp->chgBit(oldp+728,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xfU))));
        bufp->chgBit(oldp+729,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xeU))));
        bufp->chgCData(oldp+730,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 0xbU))),3);
        bufp->chgBit(oldp+731,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x40U] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x40U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+732,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+733,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xdU))));
        bufp->chgBit(oldp+734,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xcU))));
        bufp->chgBit(oldp+735,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xbU))));
        bufp->chgCData(oldp+736,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 8U))),3);
        bufp->chgBit(oldp+737,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x40U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+738,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+739,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 0xaU))));
        bufp->chgBit(oldp+740,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 9U))));
        bufp->chgBit(oldp+741,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 8U))));
        bufp->chgCData(oldp+742,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 5U))),3);
        bufp->chgBit(oldp+743,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x40U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+744,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+745,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 7U))));
        bufp->chgBit(oldp+746,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 6U))));
        bufp->chgBit(oldp+747,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 5U))));
        bufp->chgCData(oldp+748,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 2U))),3);
        bufp->chgBit(oldp+749,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x40U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x40U] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x40U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+750,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+751,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 4U))));
        bufp->chgBit(oldp+752,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 3U))));
        bufp->chgBit(oldp+753,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 2U))));
        bufp->chgCData(oldp+754,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+755,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+756,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+757,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x40U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+758,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 1U)))));
        bufp->chgBit(oldp+759,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+760,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x40U] >> 1U))));
        bufp->chgCData(oldp+761,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x40U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+762,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x40U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x40U]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+763,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+764,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x40U])));
        bufp->chgBit(oldp+765,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+766,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+767,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+768,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+769,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+770,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+771,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+772,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+773,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+774,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+775,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+776,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+777,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+778,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+779,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+780,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+781,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+782,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+783,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+784,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+785,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+786,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+787,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+788,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+789,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+790,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+791,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+792,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+793,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+794,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+795,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+796,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+797,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x41U]),17);
        bufp->chgSData(oldp+798,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+799,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout));
        bufp->chgBit(oldp+800,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+801,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+802,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+803,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+804,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+805,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+806,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 0xeU))),3);
        bufp->chgBit(oldp+807,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x41U] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x41U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+808,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+809,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0x10U))));
        bufp->chgBit(oldp+810,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xfU))));
        bufp->chgBit(oldp+811,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xeU))));
        bufp->chgCData(oldp+812,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 0xbU))),3);
        bufp->chgBit(oldp+813,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x41U] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x41U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+814,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+815,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xdU))));
        bufp->chgBit(oldp+816,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xcU))));
        bufp->chgBit(oldp+817,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xbU))));
        bufp->chgCData(oldp+818,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 8U))),3);
        bufp->chgBit(oldp+819,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x41U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+820,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+821,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 0xaU))));
        bufp->chgBit(oldp+822,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 9U))));
        bufp->chgBit(oldp+823,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 8U))));
        bufp->chgCData(oldp+824,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 5U))),3);
        bufp->chgBit(oldp+825,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x41U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+826,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+827,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 7U))));
        bufp->chgBit(oldp+828,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 6U))));
        bufp->chgBit(oldp+829,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 5U))));
        bufp->chgCData(oldp+830,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 2U))),3);
        bufp->chgBit(oldp+831,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x41U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x41U] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x41U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+832,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+833,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 4U))));
        bufp->chgBit(oldp+834,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 3U))));
        bufp->chgBit(oldp+835,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 2U))));
        bufp->chgCData(oldp+836,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+837,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+838,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+839,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x41U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+840,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 1U)))));
        bufp->chgBit(oldp+841,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+842,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x41U] >> 1U))));
        bufp->chgCData(oldp+843,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x41U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+844,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x41U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x41U]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+845,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+846,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x41U])));
        bufp->chgBit(oldp+847,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+848,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+849,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+850,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+851,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+852,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+853,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+854,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+855,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+856,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+857,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+858,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+859,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+860,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+861,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+862,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+863,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+864,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+865,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+866,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+867,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+868,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+869,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+870,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+871,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+872,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+873,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+874,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+875,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+876,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+877,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+878,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+879,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x42U]),17);
        bufp->chgSData(oldp+880,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+881,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout));
        bufp->chgBit(oldp+882,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+883,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+884,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+885,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+886,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+887,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+888,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 0xeU))),3);
        bufp->chgBit(oldp+889,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x42U] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x42U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+890,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+891,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0x10U))));
        bufp->chgBit(oldp+892,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xfU))));
        bufp->chgBit(oldp+893,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xeU))));
        bufp->chgCData(oldp+894,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 0xbU))),3);
        bufp->chgBit(oldp+895,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x42U] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x42U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+896,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+897,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xdU))));
        bufp->chgBit(oldp+898,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xcU))));
        bufp->chgBit(oldp+899,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xbU))));
        bufp->chgCData(oldp+900,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 8U))),3);
        bufp->chgBit(oldp+901,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x42U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+902,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+903,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 0xaU))));
        bufp->chgBit(oldp+904,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 9U))));
        bufp->chgBit(oldp+905,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 8U))));
        bufp->chgCData(oldp+906,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 5U))),3);
        bufp->chgBit(oldp+907,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x42U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+908,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+909,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 7U))));
        bufp->chgBit(oldp+910,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 6U))));
        bufp->chgBit(oldp+911,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 5U))));
        bufp->chgCData(oldp+912,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 2U))),3);
        bufp->chgBit(oldp+913,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x42U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x42U] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x42U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+914,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+915,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 4U))));
        bufp->chgBit(oldp+916,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 3U))));
        bufp->chgBit(oldp+917,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 2U))));
        bufp->chgCData(oldp+918,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+919,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+920,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+921,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0x42U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+922,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 1U)))));
        bufp->chgBit(oldp+923,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+924,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x42U] >> 1U))));
        bufp->chgCData(oldp+925,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x42U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+926,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x42U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x42U]) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                            >> 3U))))));
        bufp->chgBit(oldp+927,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+928,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0x42U])));
        bufp->chgBit(oldp+929,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+930,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+931,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+932,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+933,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+934,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+935,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+936,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+937,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+938,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+939,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+940,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+941,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+942,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+943,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+944,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+945,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+946,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+947,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+948,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+949,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+950,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+951,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+952,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+953,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+954,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+955,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+956,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+957,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+958,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+959,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+960,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+961,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x43U]),17);
        bufp->chgSData(oldp+962,((((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
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
                                     | ((0x800U & (
                                                   ((IData)(
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
        bufp->chgBit(oldp+963,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.cout));
        bufp->chgBit(oldp+964,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+965,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+966,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+967,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+968,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+969,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+970,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 0xeU))),3);
        bufp->chgBit(oldp+971,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x43U] 
                                             >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x43U] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+972,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+973,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0x10U))));
        bufp->chgBit(oldp+974,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xfU))));
        bufp->chgBit(oldp+975,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xeU))));
        bufp->chgCData(oldp+976,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 0xbU))),3);
        bufp->chgBit(oldp+977,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x43U] 
                                             >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x43U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+978,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+979,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xdU))));
        bufp->chgBit(oldp+980,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xcU))));
        bufp->chgBit(oldp+981,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xbU))));
        bufp->chgCData(oldp+982,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 8U))),3);
        bufp->chgBit(oldp+983,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 9U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x43U] 
                                            >> 8U))))));
        bufp->chgBit(oldp+984,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+985,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 0xaU))));
        bufp->chgBit(oldp+986,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 9U))));
        bufp->chgBit(oldp+987,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 8U))));
        bufp->chgCData(oldp+988,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 5U))),3);
        bufp->chgBit(oldp+989,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 6U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x43U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+990,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+991,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 7U))));
        bufp->chgBit(oldp+992,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 6U))));
        bufp->chgBit(oldp+993,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 5U))));
        bufp->chgCData(oldp+994,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 2U))),3);
        bufp->chgBit(oldp+995,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 3U) | 
                                          (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U] 
                                           >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x43U] 
                                            >> 2U))))));
        bufp->chgBit(oldp+996,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+997,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 4U))));
        bufp->chgBit(oldp+998,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 3U))));
        bufp->chgBit(oldp+999,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0x43U] >> 2U))));
        bufp->chgCData(oldp+1000,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1001,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1002,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1003,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x43U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1004,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x43U] >> 1U)))));
        bufp->chgBit(oldp+1005,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1006,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x43U] >> 1U))));
        bufp->chgCData(oldp+1007,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x43U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1008,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x43U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x43U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1009,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1010,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x43U])));
        bufp->chgBit(oldp+1011,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1012,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1013,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1014,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1015,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1016,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1017,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1018,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1019,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1020,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1021,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1022,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1023,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1024,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1025,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1026,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1027,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1028,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1029,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1030,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1031,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1032,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1033,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1034,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1035,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1036,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1037,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1038,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1039,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1040,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1041,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1042,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+1043,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__state),2);
        bufp->chgIData(oldp+1044,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_result),32);
        bufp->chgIData(oldp+1045,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_int_result),32);
        bufp->chgCData(oldp+1046,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__temp_exception),5);
        bufp->chgSData(oldp+1047,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__stored_true_exp1),9);
        bufp->chgSData(oldp+1048,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__stored_true_exp2),9);
        bufp->chgQData(oldp+1049,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_product),64);
        bufp->chgBit(oldp+1051,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_valid));
        bufp->chgIData(oldp+1052,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[0]),32);
        bufp->chgIData(oldp+1053,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[1]),32);
        bufp->chgIData(oldp+1054,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[2]),32);
        bufp->chgIData(oldp+1055,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[3]),32);
        bufp->chgIData(oldp+1056,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[4]),32);
        bufp->chgIData(oldp+1057,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[5]),32);
        bufp->chgIData(oldp+1058,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[6]),32);
        bufp->chgIData(oldp+1059,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[7]),32);
        bufp->chgIData(oldp+1060,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[8]),32);
        bufp->chgIData(oldp+1061,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[9]),32);
        bufp->chgIData(oldp+1062,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[10]),32);
        bufp->chgIData(oldp+1063,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[11]),32);
        bufp->chgIData(oldp+1064,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[12]),32);
        bufp->chgIData(oldp+1065,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[13]),32);
        bufp->chgIData(oldp+1066,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[14]),32);
        bufp->chgIData(oldp+1067,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[15]),32);
        bufp->chgIData(oldp+1068,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[16]),32);
        bufp->chgIData(oldp+1069,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[17]),32);
        bufp->chgIData(oldp+1070,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[18]),32);
        bufp->chgIData(oldp+1071,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[19]),32);
        bufp->chgIData(oldp+1072,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[20]),32);
        bufp->chgIData(oldp+1073,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[21]),32);
        bufp->chgIData(oldp+1074,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[22]),32);
        bufp->chgIData(oldp+1075,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[23]),32);
        bufp->chgIData(oldp+1076,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[24]),32);
        bufp->chgIData(oldp+1077,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[25]),32);
        bufp->chgIData(oldp+1078,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[26]),32);
        bufp->chgIData(oldp+1079,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[27]),32);
        bufp->chgIData(oldp+1080,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[28]),32);
        bufp->chgIData(oldp+1081,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[29]),32);
        bufp->chgIData(oldp+1082,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[30]),32);
        bufp->chgIData(oldp+1083,(vlSelf->fpu_tb__DOT__freg_inst__DOT__fregs[31]),32);
        bufp->chgIData(oldp+1084,(vlSelf->fpu_tb__DOT__freg_inst__DOT__i),32);
    }
    bufp->chgBit(oldp+1085,(vlSelf->clk));
    bufp->chgBit(oldp+1086,(vlSelf->reset));
    bufp->chgCData(oldp+1087,(vlSelf->freg_rs1),5);
    bufp->chgCData(oldp+1088,(vlSelf->freg_rs2),5);
    bufp->chgCData(oldp+1089,(vlSelf->freg_rd),5);
    bufp->chgIData(oldp+1090,(vlSelf->freg_write_data),32);
    bufp->chgBit(oldp+1091,(vlSelf->freg_write_en));
    bufp->chgIData(oldp+1092,(vlSelf->freg_read_data1),32);
    bufp->chgIData(oldp+1093,(vlSelf->freg_read_data2),32);
    bufp->chgBit(oldp+1094,(vlSelf->fpu_op_valid));
    bufp->chgCData(oldp+1095,(vlSelf->fpu_op_type),6);
    bufp->chgCData(oldp+1096,(vlSelf->fpu_op_round),3);
    bufp->chgIData(oldp+1097,(vlSelf->operand1_fp),32);
    bufp->chgIData(oldp+1098,(vlSelf->operand2_fp),32);
    bufp->chgIData(oldp+1099,(vlSelf->operand3_fp),32);
    bufp->chgIData(oldp+1100,(vlSelf->operand4_int),32);
    bufp->chgBit(oldp+1101,(vlSelf->downstream_valid));
    bufp->chgBit(oldp+1102,(vlSelf->fpu_ready));
    bufp->chgIData(oldp+1103,(vlSelf->fpu_result),32);
    bufp->chgIData(oldp+1104,(vlSelf->int_result),32);
    bufp->chgCData(oldp+1105,(vlSelf->exception_flags),5);
    bufp->chgBit(oldp+1106,(vlSelf->fpu_result_valid));
    bufp->chgBit(oldp+1107,((vlSelf->operand1_fp >> 0x1fU)));
    bufp->chgCData(oldp+1108,((0xffU & (vlSelf->operand1_fp 
                                        >> 0x17U))),8);
    bufp->chgIData(oldp+1109,((0x7fffffU & vlSelf->operand1_fp)),23);
    bufp->chgBit(oldp+1110,((vlSelf->operand2_fp >> 0x1fU)));
    bufp->chgCData(oldp+1111,((0xffU & (vlSelf->operand2_fp 
                                        >> 0x17U))),8);
    bufp->chgIData(oldp+1112,((0x7fffffU & vlSelf->operand2_fp)),23);
    bufp->chgBit(oldp+1113,((1U & (~ (IData)(vlSelf->reset)))));
}

void Vfpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root__trace_cleanup\n"); );
    // Init
    Vfpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpu___024root*>(voidSelf);
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
