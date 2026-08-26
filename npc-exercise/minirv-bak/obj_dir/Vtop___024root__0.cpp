// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.PC_command = vlSymsp->TOP__top.PC_command;
    vlSelfRef.LSU_writedata = ((0U == (0x0000001fU 
                                       & (vlSymsp->TOP__top.PC_command 
                                          >> 0x00000014U)))
                                ? 0U : vlSymsp->TOP__top__GPR_0.GPR
                               [(0x0000001fU & (vlSymsp->TOP__top.PC_command 
                                                >> 0x00000014U))]);
    vlSelfRef.LSU_wmask = ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isSW)
                            ? 0x0fU : ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isSB)
                                        ? 1U : 0U));
    vlSelfRef.LSU_WEN = ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isSW) 
                         | (IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isSB));
    vlSelfRef.LSU_REN = ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLB) 
                         | ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLBU) 
                            | (IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLW)));
    vlSelfRef.LSU_rmask = ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLW)
                            ? 0x0fU : ((IData)(vlSymsp->TOP__top.IDU_0__DOT____VdfgRegularize_h52656aab_0_6)
                                        ? 1U : 0U));
}

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP__top.__VdfgRegularize_he2b63832_0_0) {
        vlSelfRef.EXU_inB = vlSymsp->TOP__top.__PVT__rs1_val;
        vlSelfRef.EXU_inA = ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isI)
                              ? (((- (IData)((vlSymsp->TOP__top.PC_command 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 (vlSymsp->TOP__top.PC_command 
                                  >> 0x00000014U)) : 
                             ((IData)(vlSelfRef.LSU_WEN)
                               ? (((- (IData)((vlSymsp->TOP__top.PC_command 
                                               >> 0x0000001fU))) 
                                   << 0x0000000cU) 
                                  | ((0x00000fe0U & 
                                      (vlSymsp->TOP__top.PC_command 
                                       >> 0x00000014U)) 
                                     | (0x0000001fU 
                                        & (vlSymsp->TOP__top.PC_command 
                                           >> 7U))))
                               : ((0x37U == (0x0000007fU 
                                             & vlSymsp->TOP__top.PC_command))
                                   ? (0xfffff000U & vlSymsp->TOP__top.PC_command)
                                   : 0U)));
    } else {
        vlSelfRef.EXU_inB = vlSelfRef.LSU_writedata;
        vlSelfRef.EXU_inA = vlSymsp->TOP__top.__PVT__rs1_val;
    }
    vlSelfRef.LSU_address = (((IData)(vlSymsp->TOP__top.IDU_0__DOT____VdfgRegularize_h52656aab_0_5) 
                              | ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLW) 
                                 | ((IData)(vlSymsp->TOP__top.IDU_0__DOT____VdfgRegularize_h52656aab_0_6) 
                                    | (IData)(vlSelfRef.LSU_WEN))))
                              ? (vlSelfRef.EXU_inA 
                                 + vlSelfRef.EXU_inB)
                              : vlSelfRef.EXU_inA);
    vlSelfRef.EXU_data = vlSelfRef.LSU_address;
}

void Vtop___024root___ico_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.LSU_readdata = ((8U & (IData)(vlSelfRef.LSU_rmask))
                               ? ((4U & (IData)(vlSelfRef.LSU_rmask))
                                   ? ((2U & (IData)(vlSelfRef.LSU_rmask))
                                       ? ((1U & (IData)(vlSelfRef.LSU_rmask))
                                           ? vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4
                                           : 0xffffffffU)
                                       : 0xffffffffU)
                                   : 0xffffffffU) : 
                              ((4U & (IData)(vlSelfRef.LSU_rmask))
                                ? 0xffffffffU : ((2U 
                                                  & (IData)(vlSelfRef.LSU_rmask))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.LSU_rmask))
                                                   ? 
                                                  ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLBU)
                                                    ? 
                                                   (0x0000ffffU 
                                                    & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4 
                                                                    >> 0x0000000fU)))) 
                                                     << 0x00000010U) 
                                                    | (0x0000ffffU 
                                                       & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)))
                                                   : 0xffffffffU)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.LSU_rmask))
                                                   ? 
                                                  ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLBU)
                                                    ? 
                                                   (0x000000ffU 
                                                    & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4 
                                                                    >> 7U)))) 
                                                     << 8U) 
                                                    | (0x000000ffU 
                                                       & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)))
                                                   : 0xffffffffU))));
}

void Vtop_top___ico_sequent__TOP__top__0(Vtop_top* vlSelf);
void Vtop_top___ico_sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop_top___ico_sequent__TOP__top__2(Vtop_top* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop_top___ico_sequent__TOP__top__0((&vlSymsp->TOP__top));
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_top___ico_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
        Vtop_top___ico_sequent__TOP__top__2((&vlSymsp->TOP__top));
        Vtop___024root___ico_sequent__TOP__2(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.rst) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf);
void Vtop_GPR___nba_sequent__TOP__top__GPR_0__0(Vtop_GPR* vlSelf);
void Vtop_top___nba_sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop_top___nba_sequent__TOP__top__2(Vtop_top* vlSelf);
void Vtop_top___nba_sequent__TOP__top__3(Vtop_top* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_top___nba_sequent__TOP__top__0((&vlSymsp->TOP__top));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vtop_GPR___nba_sequent__TOP__top__GPR_0__0((&vlSymsp->TOP__top__GPR_0));
        Vtop_top___nba_sequent__TOP__top__1((&vlSymsp->TOP__top));
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_top___nba_sequent__TOP__top__2((&vlSymsp->TOP__top));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_top___nba_sequent__TOP__top__3((&vlSymsp->TOP__top));
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_top___ico_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
        Vtop_top___ico_sequent__TOP__top__2((&vlSymsp->TOP__top));
        Vtop___024root___ico_sequent__TOP__2(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 5, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/top.v", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
