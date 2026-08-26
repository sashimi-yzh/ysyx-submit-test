// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_GPR___ctor_var_reset(Vtop_GPR* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_GPR___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__PVT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__PVT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->__PVT__addRA = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3742534636164052463ull);
    vlSelf->__PVT__addRB = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15890044701751212234ull);
    vlSelf->__PVT__addW = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3263691094783157846ull);
    vlSelf->__PVT__outA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8920352487145152019ull);
    vlSelf->__PVT__outB = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17388924514444529742ull);
    vlSelf->__PVT__inData = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17521711824098783449ull);
    vlSelf->__PVT__WEN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16162439619744449072ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->GPR[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3611090588693839745ull);
    }
    vlSelf->__PVT__unnamedblk1__DOT__i = 0;
}
