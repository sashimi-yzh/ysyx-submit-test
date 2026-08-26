// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_GPR___nba_sequent__TOP__top__GPR_0__0(Vtop_GPR* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_GPR___nba_sequent__TOP__top__GPR_0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdlySet__GPR__v0;
    __VdlySet__GPR__v0 = 0;
    IData/*31:0*/ __VdlyVal__GPR__v32;
    __VdlyVal__GPR__v32 = 0;
    CData/*4:0*/ __VdlyDim0__GPR__v32;
    __VdlyDim0__GPR__v32 = 0;
    CData/*0:0*/ __VdlySet__GPR__v32;
    __VdlySet__GPR__v32 = 0;
    // Body
    __VdlySet__GPR__v0 = 0U;
    __VdlySet__GPR__v32 = 0U;
    if (vlSymsp->TOP.rst) {
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0x00000020U;
        __VdlySet__GPR__v0 = 1U;
    } else {
        __VdlyVal__GPR__v32 = (((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLOAD) 
                                | (IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isWRITE))
                                ? ((0U == (0x0000001fU 
                                           & (vlSymsp->TOP__top.PC_command 
                                              >> 7U)))
                                    ? 0U : ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLOAD)
                                             ? vlSymsp->TOP.LSU_readdata
                                             : ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isJALR)
                                                 ? vlSymsp->TOP__top.snpc
                                                 : 
                                                ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isWRITE)
                                                  ? vlSymsp->TOP.LSU_address
                                                  : 0xf0f0f0f0U))))
                                : vlSelfRef.GPR[(0x0000001fU 
                                                 & (vlSymsp->TOP__top.PC_command 
                                                    >> 7U))]);
        __VdlyDim0__GPR__v32 = (0x0000001fU & (vlSymsp->TOP__top.PC_command 
                                               >> 7U));
        __VdlySet__GPR__v32 = 1U;
    }
    if (__VdlySet__GPR__v0) {
        vlSelfRef.GPR[0U] = 0U;
        vlSelfRef.GPR[1U] = 0U;
        vlSelfRef.GPR[2U] = 0U;
        vlSelfRef.GPR[3U] = 0U;
        vlSelfRef.GPR[4U] = 0U;
        vlSelfRef.GPR[5U] = 0U;
        vlSelfRef.GPR[6U] = 0U;
        vlSelfRef.GPR[7U] = 0U;
        vlSelfRef.GPR[8U] = 0U;
        vlSelfRef.GPR[9U] = 0U;
        vlSelfRef.GPR[0x0aU] = 0U;
        vlSelfRef.GPR[0x0bU] = 0U;
        vlSelfRef.GPR[0x0cU] = 0U;
        vlSelfRef.GPR[0x0dU] = 0U;
        vlSelfRef.GPR[0x0eU] = 0U;
        vlSelfRef.GPR[0x0fU] = 0U;
        vlSelfRef.GPR[0x10U] = 0U;
        vlSelfRef.GPR[0x11U] = 0U;
        vlSelfRef.GPR[0x12U] = 0U;
        vlSelfRef.GPR[0x13U] = 0U;
        vlSelfRef.GPR[0x14U] = 0U;
        vlSelfRef.GPR[0x15U] = 0U;
        vlSelfRef.GPR[0x16U] = 0U;
        vlSelfRef.GPR[0x17U] = 0U;
        vlSelfRef.GPR[0x18U] = 0U;
        vlSelfRef.GPR[0x19U] = 0U;
        vlSelfRef.GPR[0x1aU] = 0U;
        vlSelfRef.GPR[0x1bU] = 0U;
        vlSelfRef.GPR[0x1cU] = 0U;
        vlSelfRef.GPR[0x1dU] = 0U;
        vlSelfRef.GPR[0x1eU] = 0U;
        vlSelfRef.GPR[0x1fU] = 0U;
    }
    if (__VdlySet__GPR__v32) {
        vlSelfRef.GPR[__VdlyDim0__GPR__v32] = __VdlyVal__GPR__v32;
    }
}
