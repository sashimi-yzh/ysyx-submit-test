// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLFSR.h for the primary calling header

#include "VLFSR__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VLFSR___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VLFSR___024root___eval_triggers__act(VLFSR___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___eval_triggers__act\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VLFSR___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool VLFSR___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void VLFSR___024root___nba_sequent__TOP__0(VLFSR___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___nba_sequent__TOP__0\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.LFSR__DOT__buffer = ((0U == (IData)(vlSelfRef.LFSR__DOT__buffer))
                                    ? (IData)(vlSelfRef.in)
                                    : ((0x00000080U 
                                        & (VL_REDXOR_8(
                                                       (0x1dU 
                                                        & (IData)(vlSelfRef.LFSR__DOT__buffer))) 
                                           << 7U)) 
                                       | (0x0000007fU 
                                          & ((IData)(vlSelfRef.LFSR__DOT__buffer) 
                                             >> 1U))));
    vlSelfRef.out = vlSelfRef.LFSR__DOT__buffer;
}

void VLFSR___024root___eval_nba(VLFSR___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___eval_nba\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VLFSR___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VLFSR___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VLFSR___024root___eval_phase__act(VLFSR___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___eval_phase__act\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VLFSR___024root___eval_triggers__act(vlSelf);
    VLFSR___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VLFSR___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VLFSR___024root___eval_phase__nba(VLFSR___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___eval_phase__nba\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VLFSR___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VLFSR___024root___eval_nba(vlSelf);
        VLFSR___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VLFSR___024root___eval(VLFSR___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___eval\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VLFSR___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/LFSR.v", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VLFSR___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/LFSR.v", 1, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (VLFSR___024root___eval_phase__act(vlSelf));
    } while (VLFSR___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void VLFSR___024root___eval_debug_assertions(VLFSR___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLFSR___024root___eval_debug_assertions\n"); );
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
}
#endif  // VL_DEBUG
