// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbooth_wallace_multiplier.h for the primary calling header

#include "verilated.h"

#include "Vbooth_wallace_multiplier__Syms.h"
#include "Vbooth_wallace_multiplier_walloc_17bits.h"

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h4d8d9ad3__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1fU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h4d8d9ad3__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
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
                                                                  [0x1fU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x1fU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x1fU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x1fU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x1fU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x1fU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x1fU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x1fU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x1fU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h4d8d9ad3__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x20U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x20U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x20U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x20U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x20U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x20U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x20U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x20U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x20U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x20U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x20U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x20U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h4e67750f__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x20U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h4e67750f__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
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
                                                                  [0x20U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x20U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x20U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x20U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x20U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x20U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x20U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x20U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x20U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h4e67750f__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x21U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x21U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x21U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x21U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x21U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x21U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x21U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x21U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x21U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x21U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x21U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x21U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h02f783f2__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x21U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h02f783f2__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
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
                                                                  [0x21U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x21U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x21U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x21U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x21U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x21U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x21U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x21U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x21U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h02f783f2__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x22U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x22U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x22U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x22U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x22U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x22U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x22U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x22U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x22U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x22U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x22U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x22U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h3c6b36d4__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x22U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h3c6b36d4__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
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
                                                                  [0x22U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x22U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x22U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x22U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x22U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x22U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x22U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x22U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x22U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h3c6b36d4__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x23U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x23U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x23U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x23U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x23U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x23U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x23U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x23U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x23U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x23U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x23U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x23U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h51b8c8f0__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x23U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h51b8c8f0__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
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
                                                                  [0x23U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x23U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x23U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x23U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x23U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x23U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x23U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x23U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x23U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h51b8c8f0__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x24U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x24U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x24U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x24U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x24U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x24U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x24U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x24U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x24U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x24U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x24U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x24U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hf65cb7f7__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x24U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hf65cb7f7__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
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
                                                                  [0x24U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x24U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x24U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x24U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x24U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x24U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x24U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x24U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x24U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hf65cb7f7__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x25U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x25U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x25U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x25U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x25U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x25U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x25U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x25U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x25U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x25U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x25U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x25U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_ha668bb37__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x25U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_ha668bb37__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
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
                                                                  [0x25U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x25U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x25U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x25U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x25U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x25U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x25U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x25U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x25U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_ha668bb37__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x26U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x26U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x26U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x26U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x26U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x26U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x26U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x26U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x26U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x26U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x26U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x26U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h9d834743__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x26U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h9d834743__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
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
                                                                  [0x26U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x26U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x26U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x26U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x26U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x26U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x26U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x26U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x26U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h9d834743__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x27U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x27U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x27U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x27U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x27U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x27U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x27U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x27U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hf757f66a__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x27U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hf757f66a__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
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
                                                                  [0x27U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x27U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x27U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x27U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x27U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x27U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x27U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x27U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x27U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hf757f66a__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x28U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x28U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x28U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x28U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x28U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x28U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x28U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x28U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h5373cf42__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x28U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h5373cf42__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
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
                                                                  [0x28U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x28U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x28U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x28U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x28U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x28U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x28U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x28U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x28U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h5373cf42__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x29U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x29U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x29U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x29U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x29U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x29U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x29U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x29U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h2487825e__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x29U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h2487825e__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
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
                                                                  [0x29U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x29U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x29U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x29U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x29U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x29U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x29U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x29U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x29U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h2487825e__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2aU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2aU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2aU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h801e2073__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2aU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h801e2073__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
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
                                                                  [0x2aU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x2aU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x2aU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x2aU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x2aU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x2aU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x2aU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x2aU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2aU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h801e2073__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2bU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2bU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2bU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hf3a59d7e__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2bU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hf3a59d7e__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
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
                                                                  [0x2bU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x2bU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x2bU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x2bU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x2bU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x2bU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x2bU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x2bU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2bU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hf3a59d7e__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2cU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2cU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2cU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h31c03ae4__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2cU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h31c03ae4__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
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
                                                                  [0x2cU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x2cU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x2cU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x2cU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x2cU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x2cU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x2cU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x2cU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2cU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h31c03ae4__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2dU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2dU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2dU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h937491a0__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2dU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h937491a0__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
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
                                                                  [0x2dU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x2dU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x2dU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x2dU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x2dU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x2dU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x2dU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x2dU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2dU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h937491a0__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2eU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2eU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2eU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_he9ef5e81__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2eU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_he9ef5e81__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
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
                                                                  [0x2eU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x2eU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x2eU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x2eU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x2eU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x2eU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x2eU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x2eU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2eU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_he9ef5e81__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x2fU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x2fU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x2fU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hf8a09595__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x2fU]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hf8a09595__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
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
                                                                  [0x2fU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x2fU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x2fU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x2fU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x2fU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x2fU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x2fU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x2fU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x2fU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hf8a09595__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x30U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x30U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x30U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x30U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x30U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x30U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x30U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x30U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h23778c3d__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x30U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h23778c3d__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
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
                                                                  [0x30U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x30U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x30U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x30U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x30U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x30U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x30U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x30U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x30U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h23778c3d__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x31U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x31U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x31U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x31U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x31U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x31U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x31U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x31U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hdbcb0f38__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x31U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hdbcb0f38__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
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
                                                                  [0x31U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x31U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x31U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x31U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x31U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x31U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x31U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x31U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x31U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hdbcb0f38__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x32U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x32U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x32U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x32U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x32U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x32U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x32U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x32U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hcbb6e3da__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x32U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hcbb6e3da__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
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
                                                                  [0x32U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x32U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x32U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x32U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x32U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x32U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x32U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x32U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x32U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hcbb6e3da__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x33U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x33U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x33U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x33U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x33U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x33U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x33U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x33U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hc3baa1c0__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x33U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hc3baa1c0__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
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
                                                                  [0x33U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x33U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x33U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x33U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x33U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x33U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x33U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x33U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x33U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hc3baa1c0__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x34U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x34U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x34U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x34U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x34U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x34U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x34U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x34U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h59948f38__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x34U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h59948f38__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
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
                                                                  [0x34U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x34U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x34U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x34U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x34U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x34U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x34U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x34U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x34U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h59948f38__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x35U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x35U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x35U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x35U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x35U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x35U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x35U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x35U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h6ce8b370__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x35U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h6ce8b370__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
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
                                                                  [0x35U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x35U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x35U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x35U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x35U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x35U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x35U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x35U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x35U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h6ce8b370__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x36U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x36U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x36U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x36U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x36U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x36U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x36U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x36U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hfcd5e729__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x36U]));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hfcd5e729__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
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
                                                                  [0x36U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x36U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x36U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x36U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x36U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x36U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x36U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x36U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x36U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hfcd5e729__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x37U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x37U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x37U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x37U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x37U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x37U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x37U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x37U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hd6fcc91b__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x37U]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hd6fcc91b__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
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
                                                                  [0x37U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x37U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x37U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x37U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x37U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x37U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x37U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x37U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x37U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hd6fcc91b__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x38U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x38U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x38U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x38U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x38U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x38U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x38U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x38U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x38U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x38U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x38U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x38U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h1da9501d__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x38U]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h1da9501d__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
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
                                                                  [0x38U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x38U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x38U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x38U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x38U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x38U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x38U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x38U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x38U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h1da9501d__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x39U] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x39U] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x39U] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x39U] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x39U] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x39U] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x39U] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x39U] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x39U] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x39U] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x39U] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x39U] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h9d2aadab__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x39U]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h9d2aadab__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
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
                                                                  [0x39U] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x39U] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x39U] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x39U] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x39U] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x39U] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x39U] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x39U] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x39U] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h9d2aadab__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3aU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3aU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3aU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h892ca7c5__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3aU]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h892ca7c5__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
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
                                                                  [0x3aU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x3aU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x3aU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x3aU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x3aU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x3aU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x3aU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x3aU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3aU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h892ca7c5__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3bU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3bU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3bU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h85ef9300__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3bU]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h85ef9300__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
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
                                                                  [0x3bU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x3bU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x3bU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x3bU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x3bU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x3bU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x3bU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x3bU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3bU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h85ef9300__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3cU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3cU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3cU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h3721f715__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3cU]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_h3721f715__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
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
                                                                  [0x3cU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x3cU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x3cU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x3cU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x3cU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x3cU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x3cU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x3cU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3cU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_h3721f715__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut__0(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut__0\n"); );
    // Body
    vlSelf->__Vcellout__csa0__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 0x10U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 0xfU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 0xeU))));
    vlSelf->__Vcellout__csa1__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 0xdU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 0xcU) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 0xbU))));
    vlSelf->__Vcellout__csa2__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 0xaU) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 9U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 8U))));
    vlSelf->__Vcellout__csa3__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 7U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 6U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 5U))));
    vlSelf->__Vcellout__csa4__s = (1U & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                          [0x3dU] >> 4U) 
                                         ^ ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                             [0x3dU] 
                                             >> 3U) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 2U))));
    vlSelf->__Vcellout__csa5__s = ((IData)(vlSelf->__Vcellout__csa0__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa1__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa2__s)));
    vlSelf->__Vcellout__csa6__s = (1U & ((IData)(vlSelf->__Vcellout__csa3__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csa4__s) 
                                            ^ (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                               [0x3dU] 
                                               >> 1U))));
}

VL_INLINE_OPT void Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut__1(Vbooth_wallace_multiplier_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbooth_wallace_multiplier_walloc_17bits___ico_sequent__TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hcadcf111__0;
    // Body
    vlSelf->__Vcellout__csaC__s = (1U & VL_REDXOR_16(
                                                     (0x380U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa8__s = (1U & VL_REDXOR_4(
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))));
    vlSelf->__Vcellout__csa7__s = (1U & (VL_REDXOR_8(
                                                     (0x18U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))) 
                                         ^ vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                         [0x3dU]));
    vlSelf->__Vcellout__csaA__s = (1U & ((IData)(vlSelf->__Vcellout__csa8__s) 
                                         ^ VL_REDXOR_8(
                                                       (0x60U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))));
    vlSelf->__Vcellout__csa9__s = ((IData)(vlSelf->__Vcellout__csa5__s) 
                                   ^ ((IData)(vlSelf->__Vcellout__csa6__s) 
                                      ^ (IData)(vlSelf->__Vcellout__csa7__s)));
    vlSelf->__Vcellout__csaB__s = (1U & ((IData)(vlSelf->__Vcellout__csa9__s) 
                                         ^ ((IData)(vlSelf->__Vcellout__csaA__s) 
                                            ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                               >> 0xaU))));
    vlSelf->__PVT__fifth_s = (1U & ((IData)(vlSelf->__Vcellout__csaB__s) 
                                    ^ ((IData)(vlSelf->__Vcellout__csaC__s) 
                                       ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                          >> 0xbU))));
    __Vtemp_hcadcf111__0 = (((((IData)(vlSelf->__Vcellout__csaB__s) 
                               & (IData)(vlSelf->__Vcellout__csaC__s)) 
                              << 0xdU) | (0xffffe000U 
                                          & ((((IData)(vlSelf->__Vcellout__csaC__s) 
                                               | (IData)(vlSelf->__Vcellout__csaB__s)) 
                                              << 0xdU) 
                                             & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                << 2U)))) 
                            | (((((IData)(vlSelf->__Vcellout__csa9__s) 
                                  & (IData)(vlSelf->__Vcellout__csaA__s)) 
                                 << 0xcU) | (0xfffff000U 
                                             & ((((IData)(vlSelf->__Vcellout__csaA__s) 
                                                  | (IData)(vlSelf->__Vcellout__csa9__s)) 
                                                 << 0xcU) 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                   << 2U)))) 
                               | ((0x800U & (((IData)(
                                                      (0x300U 
                                                       == 
                                                       (0x300U 
                                                        & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                              << 0xbU) 
                                             | (0xfffff800U 
                                                & (((IData)(
                                                            (0U 
                                                             != 
                                                             (0x300U 
                                                              & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                                    << 0xbU) 
                                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                      << 4U))))) 
                                  | (((((IData)(vlSelf->__Vcellout__csa5__s) 
                                        & (IData)(vlSelf->__Vcellout__csa6__s)) 
                                       | (((IData)(vlSelf->__Vcellout__csa6__s) 
                                           | (IData)(vlSelf->__Vcellout__csa5__s)) 
                                          & (IData)(vlSelf->__Vcellout__csa7__s))) 
                                      << 0xaU) | ((0x200U 
                                                   & ((((IData)(vlSelf->__Vcellout__csa8__s) 
                                                        << 9U) 
                                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                          << 3U)) 
                                                      | (((0xfffffe00U 
                                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                              << 3U)) 
                                                          | ((IData)(vlSelf->__Vcellout__csa8__s) 
                                                             << 9U)) 
                                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
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
                                                                  [0x3dU] 
                                                                  << 6U)))) 
                                                        | ((0x40U 
                                                            & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                 [0x3dU] 
                                                                 << 6U) 
                                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                                   << 2U)) 
                                                               | (((0xffffffc0U 
                                                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                                       << 2U)) 
                                                                   | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                      [0x3dU] 
                                                                      << 6U)) 
                                                                  & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                                                     << 3U)))) 
                                                           | ((0x20U 
                                                               & (((IData)(
                                                                           (6U 
                                                                            == 
                                                                            (6U 
                                                                             & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                                                   | ((IData)(
                                                                              (0U 
                                                                               != 
                                                                               (6U 
                                                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group)))) 
                                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & ((0xffff0U 
                                                                      & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                          [0x3dU] 
                                                                          >> 0xcU) 
                                                                         & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                            [0x3dU] 
                                                                            >> 0xbU))) 
                                                                     | (0x3ffff0U 
                                                                        & (((0x1ffff0U 
                                                                             & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 0xbU)) 
                                                                            | (0xffff0U 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 0xcU))) 
                                                                           & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                              [0x3dU] 
                                                                              >> 0xaU))))) 
                                                                 | ((8U 
                                                                     & ((0x3ffff8U 
                                                                         & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                             [0x3dU] 
                                                                             >> 0xaU) 
                                                                            & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                               [0x3dU] 
                                                                               >> 9U))) 
                                                                        | (0xfffff8U 
                                                                           & (((0x7ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 9U)) 
                                                                               | (0x3ffff8U 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 0xaU))) 
                                                                              & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 8U))))) 
                                                                    | ((4U 
                                                                        & ((0xfffffcU 
                                                                            & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 8U) 
                                                                               & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 7U))) 
                                                                           | (0x3fffffcU 
                                                                              & (((0x1fffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 7U)) 
                                                                                | (0xfffffcU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 8U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 6U))))) 
                                                                       | ((2U 
                                                                           & ((0x3fffffeU 
                                                                               & ((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 6U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 5U))) 
                                                                              | (0xffffffeU 
                                                                                & (((0x7fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 5U)) 
                                                                                | (0x3fffffeU 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 6U))) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 4U))))) 
                                                                          | (1U 
                                                                             & (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 4U) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 3U)) 
                                                                                | (((vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 3U) 
                                                                                | (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 4U)) 
                                                                                & (vlSymsp->TOP.booth_wallace_multiplier__DOT__switch_outputs
                                                                                [0x3dU] 
                                                                                >> 2U)))))))))))))))));
    vlSelf->cout_group = __Vtemp_hcadcf111__0;
    vlSelf->cout = (1U & (((IData)(vlSelf->__PVT__fifth_s) 
                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                              >> 0xdU)) | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                             >> 0xdU) 
                                            | (IData)(vlSelf->__PVT__fifth_s)) 
                                           & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group) 
                                              >> 0xcU))));
}
