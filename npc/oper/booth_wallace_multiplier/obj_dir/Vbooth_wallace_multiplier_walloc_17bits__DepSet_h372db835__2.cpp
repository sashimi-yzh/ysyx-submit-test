// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbooth_wallace_multiplier.h for the primary calling header

#include "verilated.h"

#include "Vbooth_wallace_multiplier__Syms.h"
#include "Vbooth_wallace_multiplier_walloc_17bits.h"

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3eU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3eU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3eU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hcc0f3418__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3eU]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hcc0f3418__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                            << 4U)))) 
                                                  | (((((IData)(vlSelf->__Vcellout__csa0__s) 
                                                        & (IData)(vlSelf->__Vcellout__csa1__s)) 
                                                       | (((IData)(vlSelf->__Vcellout__csa1__s) 
                                                           | (IData)(vlSelf->__Vcellout__csa0__s)) 
                                                          & (IData)(vlSelf->__Vcellout__csa2__s))) 
                                                      << 8U) 
                                                     | (((((IData)(vlSelf->__Vcellout__csa3__s) 
                                                           & (IData)(vlSelf->__Vcellout__csa4__s)) 
                                                          << 7U) 
                                                         | (0xffffff80U 
                                                            & ((((IData)(vlSelf->__Vcellout__csa4__s) 
                                                                 | (IData)(vlSelf->__Vcellout__csa3__s)) 
                                                                << 7U) 
                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                  [0x3eU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x3eU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x3eU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x3eU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x3eU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x3eU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x3eU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x3eU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3eU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hcc0f3418__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3fU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3fU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3fU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hd2898f10__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3fU]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hd2898f10__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                            << 4U)))) 
                                                  | (((((IData)(vlSelf->__Vcellout__csa0__s) 
                                                        & (IData)(vlSelf->__Vcellout__csa1__s)) 
                                                       | (((IData)(vlSelf->__Vcellout__csa1__s) 
                                                           | (IData)(vlSelf->__Vcellout__csa0__s)) 
                                                          & (IData)(vlSelf->__Vcellout__csa2__s))) 
                                                      << 8U) 
                                                     | (((((IData)(vlSelf->__Vcellout__csa3__s) 
                                                           & (IData)(vlSelf->__Vcellout__csa4__s)) 
                                                          << 7U) 
                                                         | (0xffffff80U 
                                                            & ((((IData)(vlSelf->__Vcellout__csa4__s) 
                                                                 | (IData)(vlSelf->__Vcellout__csa3__s)) 
                                                                << 7U) 
                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                  [0x3fU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x3fU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x3fU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x3fU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x3fU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x3fU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x3fU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x3fU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3fU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hd2898f10__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x40U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x40U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x40U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x40U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x40U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x40U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x40U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x40U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x40U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x40U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x40U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x40U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h0dcb3d60__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x40U]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h0dcb3d60__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                            << 4U)))) 
                                                  | (((((IData)(vlSelf->__Vcellout__csa0__s) 
                                                        & (IData)(vlSelf->__Vcellout__csa1__s)) 
                                                       | (((IData)(vlSelf->__Vcellout__csa1__s) 
                                                           | (IData)(vlSelf->__Vcellout__csa0__s)) 
                                                          & (IData)(vlSelf->__Vcellout__csa2__s))) 
                                                      << 8U) 
                                                     | (((((IData)(vlSelf->__Vcellout__csa3__s) 
                                                           & (IData)(vlSelf->__Vcellout__csa4__s)) 
                                                          << 7U) 
                                                         | (0xffffff80U 
                                                            & ((((IData)(vlSelf->__Vcellout__csa4__s) 
                                                                 | (IData)(vlSelf->__Vcellout__csa3__s)) 
                                                                << 7U) 
                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                  [0x40U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x40U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x40U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x40U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x40U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x40U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x40U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x40U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x40U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h0dcb3d60__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x41U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x41U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x41U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x41U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x41U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x41U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x41U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x41U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x41U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x41U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x41U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x41U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hc6bb974e__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x41U]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hc6bb974e__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                            << 4U)))) 
                                                  | (((((IData)(vlSelf->__Vcellout__csa0__s) 
                                                        & (IData)(vlSelf->__Vcellout__csa1__s)) 
                                                       | (((IData)(vlSelf->__Vcellout__csa1__s) 
                                                           | (IData)(vlSelf->__Vcellout__csa0__s)) 
                                                          & (IData)(vlSelf->__Vcellout__csa2__s))) 
                                                      << 8U) 
                                                     | (((((IData)(vlSelf->__Vcellout__csa3__s) 
                                                           & (IData)(vlSelf->__Vcellout__csa4__s)) 
                                                          << 7U) 
                                                         | (0xffffff80U 
                                                            & ((((IData)(vlSelf->__Vcellout__csa4__s) 
                                                                 | (IData)(vlSelf->__Vcellout__csa3__s)) 
                                                                << 7U) 
                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                  [0x41U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x41U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x41U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x41U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x41U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x41U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x41U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x41U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x41U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hc6bb974e__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x42U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x42U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x42U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x42U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x42U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x42U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x42U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x42U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x42U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x42U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x42U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x42U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h223f900d__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x42U]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h223f900d__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                            << 4U)))) 
                                                  | (((((IData)(vlSelf->__Vcellout__csa0__s) 
                                                        & (IData)(vlSelf->__Vcellout__csa1__s)) 
                                                       | (((IData)(vlSelf->__Vcellout__csa1__s) 
                                                           | (IData)(vlSelf->__Vcellout__csa0__s)) 
                                                          & (IData)(vlSelf->__Vcellout__csa2__s))) 
                                                      << 8U) 
                                                     | (((((IData)(vlSelf->__Vcellout__csa3__s) 
                                                           & (IData)(vlSelf->__Vcellout__csa4__s)) 
                                                          << 7U) 
                                                         | (0xffffff80U 
                                                            & ((((IData)(vlSelf->__Vcellout__csa4__s) 
                                                                 | (IData)(vlSelf->__Vcellout__csa3__s)) 
                                                                << 7U) 
                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                  [0x42U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x42U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x42U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x42U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x42U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x42U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x42U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x42U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x42U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h223f900d__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x43U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x43U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x43U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x43U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x43U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x43U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x43U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x43U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x43U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x43U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x43U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x43U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut__1\n"); );
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x43U]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}
