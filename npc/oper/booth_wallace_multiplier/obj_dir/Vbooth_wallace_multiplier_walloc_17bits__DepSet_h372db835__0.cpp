// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbooth_wallace_multiplier.h for the primary calling header

#include "verilated.h"

#include "Vbooth_wallace_multiplier__Syms.h"
#include "Vbooth_wallace_multiplier_walloc_17bits.h"

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0U] 
                                               >> 1U))));
    vlSelf->cout_group = (((((IData)(vlSelf->__Vcellout__csa5__s) 
                             & (IData)(vlSelf->__Vcellout__csa6__s)) 
                            | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                | (IData)(vlSelf->__Vcellout__csa5__s)) 
                               & vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                               [0U])) << 0xaU) | ((
                                                   (((IData)(vlSelf->__Vcellout__csa0__s) 
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
                                                               [0U] 
                                                               << 6U)))) 
                                                     | ((0x10U 
                                                         & ((0xffff0U 
                                                             & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0U] 
                                                                 >> 0xcU) 
                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                   [0U] 
                                                                   >> 0xbU))) 
                                                            | (0x3ffff0U 
                                                               & (((0x1ffff0U 
                                                                    & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                       [0U] 
                                                                       >> 0xbU)) 
                                                                   | (0xffff0U 
                                                                      & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                         [0U] 
                                                                         >> 0xcU))) 
                                                                  & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                     [0U] 
                                                                     >> 0xaU))))) 
                                                        | ((8U 
                                                            & ((0x3ffff8U 
                                                                & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                    [0U] 
                                                                    >> 0xaU) 
                                                                   & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0U] 
                                                                      >> 9U))) 
                                                               | (0xfffff8U 
                                                                  & (((0x7ffff8U 
                                                                       & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0U] 
                                                                          >> 9U)) 
                                                                      | (0x3ffff8U 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0U] 
                                                                            >> 0xaU))) 
                                                                     & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                        [0U] 
                                                                        >> 8U))))) 
                                                           | ((4U 
                                                               & ((0xfffffcU 
                                                                   & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                       [0U] 
                                                                       >> 8U) 
                                                                      & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                         [0U] 
                                                                         >> 7U))) 
                                                                  | (0x3fffffcU 
                                                                     & (((0x1fffffcU 
                                                                          & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0U] 
                                                                             >> 7U)) 
                                                                         | (0xfffffcU 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0U] 
                                                                               >> 8U))) 
                                                                        & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                           [0U] 
                                                                           >> 6U))))) 
                                                              | ((2U 
                                                                  & ((0x3fffffeU 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0U] 
                                                                          >> 6U) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0U] 
                                                                            >> 5U))) 
                                                                     | (0xffffffeU 
                                                                        & (((0x7fffffeU 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0U] 
                                                                                >> 5U)) 
                                                                            | (0x3fffffeU 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0U] 
                                                                                >> 6U))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0U] 
                                                                              >> 4U))))) 
                                                                 | (1U 
                                                                    & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                         [0U] 
                                                                         >> 4U) 
                                                                        & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                           [0U] 
                                                                           >> 3U)) 
                                                                       | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0U] 
                                                                            >> 3U) 
                                                                           | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0U] 
                                                                              >> 4U)) 
                                                                          & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0U] 
                                                                             >> 2U)))))))))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [1U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [1U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [1U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [1U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [1U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [1U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h736403f1__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [1U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h736403f1__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
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
                                                                  [1U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [1U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [1U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [1U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [1U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [1U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [1U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [1U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [1U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h736403f1__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [2U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [2U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [2U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [2U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [2U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [2U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hd3835c50__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [2U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hd3835c50__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
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
                                                                  [2U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [2U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [2U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [2U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [2U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [2U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [2U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [2U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [2U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hd3835c50__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [3U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [3U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [3U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [3U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [3U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [3U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_ha9227b0e__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [3U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_ha9227b0e__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
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
                                                                  [3U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [3U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [3U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [3U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [3U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [3U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [3U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [3U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [3U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_ha9227b0e__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [4U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [4U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [4U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [4U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [4U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [4U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h19bf0394__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [4U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h19bf0394__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
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
                                                                  [4U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [4U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [4U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [4U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [4U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [4U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [4U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [4U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [4U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h19bf0394__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [5U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [5U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [5U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [5U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [5U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [5U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h8c958328__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [5U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h8c958328__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
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
                                                                  [5U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [5U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [5U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [5U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [5U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [5U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [5U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [5U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [5U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h8c958328__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [6U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [6U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [6U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [6U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [6U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [6U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hd5f39236__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [6U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hd5f39236__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
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
                                                                  [6U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [6U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [6U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [6U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [6U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [6U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [6U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [6U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [6U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hd5f39236__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [7U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [7U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [7U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [7U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [7U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [7U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h99c1753c__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [7U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h99c1753c__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
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
                                                                  [7U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [7U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [7U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [7U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [7U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [7U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [7U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [7U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [7U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h99c1753c__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [8U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [8U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [8U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [8U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [8U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [8U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hb7fc6cf2__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [8U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hb7fc6cf2__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
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
                                                                  [8U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [8U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [8U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [8U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [8U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [8U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [8U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [8U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [8U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hb7fc6cf2__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [9U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [9U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [9U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [9U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [9U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [9U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h997ed9cb__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [9U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h997ed9cb__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
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
                                                                  [9U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [9U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [9U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [9U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [9U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [9U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [9U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [9U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [9U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h997ed9cb__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xaU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xaU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xaU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xaU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xaU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xaU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hb3e303d6__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0xaU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hb3e303d6__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
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
                                                                  [0xaU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0xaU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0xaU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0xaU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0xaU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0xaU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0xaU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0xaU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xaU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hb3e303d6__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xbU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xbU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xbU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xbU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xbU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xbU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xbU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xbU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xbU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xbU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xbU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h6d9ff044__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h6d9ff044__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
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
                                                                  [0xbU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0xbU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0xbU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0xbU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0xbU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0xbU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0xbU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0xbU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xbU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h6d9ff044__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xcU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xcU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xcU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xcU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xcU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xcU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xcU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xcU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xcU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xcU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xcU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h81227b2e__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h81227b2e__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
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
                                                                  [0xcU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0xcU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0xcU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0xcU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0xcU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0xcU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0xcU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0xcU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xcU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h81227b2e__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xdU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xdU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xdU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xdU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xdU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xdU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xdU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xdU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xdU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xdU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xdU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_he07922df__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_he07922df__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
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
                                                                  [0xdU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0xdU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0xdU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0xdU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0xdU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0xdU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0xdU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0xdU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xdU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_he07922df__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xeU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xeU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xeU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xeU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xeU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xeU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xeU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xeU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xeU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xeU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xeU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h6c68b7a8__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h6c68b7a8__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
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
                                                                  [0xeU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0xeU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0xeU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0xeU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0xeU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0xeU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0xeU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0xeU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xeU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h6c68b7a8__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xfU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xfU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xfU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xfU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xfU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xfU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xfU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xfU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0xfU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xfU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0xfU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h25de3927__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h25de3927__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
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
                                                                  [0xfU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0xfU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0xfU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0xfU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0xfU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0xfU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0xfU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0xfU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0xfU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h25de3927__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x10U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x10U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x10U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x10U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x10U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x10U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x10U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x10U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x10U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x10U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x10U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h69a2fb0c__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h69a2fb0c__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
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
                                                                  [0x10U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x10U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x10U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x10U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x10U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x10U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x10U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x10U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x10U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h69a2fb0c__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x11U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x11U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x11U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x11U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x11U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x11U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x11U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x11U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x11U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x11U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x11U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h7c75278c__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h7c75278c__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
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
                                                                  [0x11U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x11U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x11U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x11U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x11U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x11U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x11U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x11U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x11U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h7c75278c__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x12U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x12U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x12U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x12U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x12U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x12U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x12U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x12U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x12U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x12U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x12U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h2b320164__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h2b320164__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
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
                                                                  [0x12U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x12U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x12U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x12U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x12U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x12U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x12U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x12U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x12U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h2b320164__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x13U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x13U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x13U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x13U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x13U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x13U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x13U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x13U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x13U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x13U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x13U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h2a1c091b__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h2a1c091b__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
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
                                                                  [0x13U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x13U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x13U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x13U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x13U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x13U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x13U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x13U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x13U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h2a1c091b__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x14U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x14U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x14U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x14U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x14U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x14U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x14U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x14U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x14U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x14U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x14U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hb6c22883__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hb6c22883__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
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
                                                                  [0x14U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x14U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x14U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x14U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x14U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x14U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x14U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x14U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x14U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hb6c22883__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x15U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x15U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x15U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x15U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x15U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x15U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x15U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x15U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x15U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x15U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x15U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hea9ee118__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hea9ee118__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
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
                                                                  [0x15U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x15U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x15U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x15U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x15U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x15U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x15U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x15U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x15U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hea9ee118__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x16U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x16U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x16U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x16U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x16U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x16U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x16U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x16U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x16U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x16U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x16U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hfd479f81__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hfd479f81__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
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
                                                                  [0x16U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x16U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x16U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x16U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x16U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x16U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x16U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x16U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x16U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hfd479f81__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x17U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x17U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x17U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x17U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x17U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x17U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x17U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x17U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x17U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x17U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x17U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h9aa4601f__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h9aa4601f__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
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
                                                                  [0x17U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x17U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x17U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x17U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x17U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x17U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x17U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x17U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x17U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h9aa4601f__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x18U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x18U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x18U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x18U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x18U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x18U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x18U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x18U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x18U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x18U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x18U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h89092ca0__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h89092ca0__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
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
                                                                  [0x18U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x18U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x18U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x18U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x18U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x18U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x18U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x18U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x18U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h89092ca0__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x19U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x19U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x19U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x19U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x19U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x19U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x19U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x19U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x19U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x19U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x19U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_ha4aa4f0a__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_ha4aa4f0a__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
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
                                                                  [0x19U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x19U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x19U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x19U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x19U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x19U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x19U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x19U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x19U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_ha4aa4f0a__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1aU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1aU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1aU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1aU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1aU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1aU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1aU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1aU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1aU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1aU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1aU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h6bfd9551__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h6bfd9551__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
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
                                                                  [0x1aU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x1aU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x1aU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x1aU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x1aU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x1aU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x1aU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x1aU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1aU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h6bfd9551__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1bU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1bU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1bU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1bU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1bU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1bU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1bU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hada16a26__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hada16a26__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
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
                                                                  [0x1bU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x1bU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x1bU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x1bU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x1bU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x1bU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x1bU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x1bU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1bU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hada16a26__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1cU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1cU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1cU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1cU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1cU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1cU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1cU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hf8af5b23__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1cU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hf8af5b23__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
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
                                                                  [0x1cU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x1cU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x1cU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x1cU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x1cU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x1cU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x1cU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x1cU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1cU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hf8af5b23__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1dU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1dU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1dU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1dU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1dU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1dU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1dU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_he96a22e7__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1dU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_he96a22e7__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
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
                                                                  [0x1dU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x1dU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x1dU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x1dU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x1dU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x1dU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x1dU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x1dU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1dU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_he96a22e7__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1eU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1eU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1eU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1eU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1eU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1eU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1eU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hf4568511__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1eU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hf4568511__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
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
                                                                  [0x1eU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x1eU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x1eU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x1eU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x1eU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x1eU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x1eU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x1eU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1eU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hf4568511__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1fU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1fU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1fU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1fU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1fU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1fU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x1fU] 
                                               >> 1U))));
}
