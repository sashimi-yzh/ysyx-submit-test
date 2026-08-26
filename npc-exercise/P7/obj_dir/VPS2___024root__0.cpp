// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPS2.h for the primary calling header

#include "VPS2__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VPS2___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VPS2___024root___eval_triggers__act(VPS2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___eval_triggers__act\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.CLK) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CLK__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__CLK__0 = vlSelfRef.CLK;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VPS2___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool VPS2___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___trigger_anySet__act\n"); );
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

extern const VlUnpacked<CData/*6:0*/, 16> VPS2__ConstPool__TABLE_h0ee5ce4f_0;
extern const VlUnpacked<CData/*6:0*/, 32> VPS2__ConstPool__TABLE_hfa5a6cbf_0;
extern const VlUnpacked<CData/*0:0*/, 256> VPS2__ConstPool__TABLE_hdaf6d84f_0;
extern const VlUnpacked<CData/*7:0*/, 256> VPS2__ConstPool__TABLE_h433c6e94_0;

void VPS2___024root___nba_sequent__TOP__0(VPS2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___nba_sequent__TOP__0\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*3:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*3:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    CData/*0:0*/ __Vdly__PS2__DOT__ifPressed;
    __Vdly__PS2__DOT__ifPressed = 0;
    CData/*2:0*/ __Vdly__PS2__DOT__inst__DOT__ps2_clk_sync;
    __Vdly__PS2__DOT__inst__DOT__ps2_clk_sync = 0;
    CData/*2:0*/ __Vdly__PS2__DOT__inst__DOT__r_ptr;
    __Vdly__PS2__DOT__inst__DOT__r_ptr = 0;
    CData/*0:0*/ __Vdly__PS2__DOT__ready;
    __Vdly__PS2__DOT__ready = 0;
    CData/*2:0*/ __Vdly__PS2__DOT__inst__DOT__w_ptr;
    __Vdly__PS2__DOT__inst__DOT__w_ptr = 0;
    CData/*3:0*/ __Vdly__PS2__DOT__inst__DOT__count;
    __Vdly__PS2__DOT__inst__DOT__count = 0;
    CData/*7:0*/ __VdlyVal__PS2__DOT__inst__DOT__fifo__v0;
    __VdlyVal__PS2__DOT__inst__DOT__fifo__v0 = 0;
    CData/*2:0*/ __VdlyDim0__PS2__DOT__inst__DOT__fifo__v0;
    __VdlyDim0__PS2__DOT__inst__DOT__fifo__v0 = 0;
    CData/*0:0*/ __VdlySet__PS2__DOT__inst__DOT__fifo__v0;
    __VdlySet__PS2__DOT__inst__DOT__fifo__v0 = 0;
    // Body
    __Vdly__PS2__DOT__inst__DOT__ps2_clk_sync = vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync;
    __Vdly__PS2__DOT__ready = vlSelfRef.PS2__DOT__ready;
    __Vdly__PS2__DOT__inst__DOT__w_ptr = vlSelfRef.PS2__DOT__inst__DOT__w_ptr;
    __Vdly__PS2__DOT__inst__DOT__count = vlSelfRef.PS2__DOT__inst__DOT__count;
    __Vdly__PS2__DOT__inst__DOT__r_ptr = vlSelfRef.PS2__DOT__inst__DOT__r_ptr;
    __VdlySet__PS2__DOT__inst__DOT__fifo__v0 = 0U;
    __Vdly__PS2__DOT__ifPressed = vlSelfRef.PS2__DOT__ifPressed;
    __Vdly__PS2__DOT__inst__DOT__ps2_clk_sync = ((6U 
                                                  & ((IData)(vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync) 
                                                     << 1U)) 
                                                 | (IData)(vlSelfRef.PS2_CLK));
    if (vlSelfRef.CLRN) {
        if (vlSelfRef.PS2__DOT__ready) {
            if ((1U & (~ (IData)(vlSelfRef.PS2__DOT__nextdata_n)))) {
                __Vdly__PS2__DOT__inst__DOT__r_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.PS2__DOT__inst__DOT__r_ptr)));
                if (((IData)(vlSelfRef.PS2__DOT__inst__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelfRef.PS2__DOT__inst__DOT__r_ptr))))) {
                    __Vdly__PS2__DOT__ready = 0U;
                }
            }
        }
        if ((IData)((4U == (6U & (IData)(vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync))))) {
            if ((0x0aU == (IData)(vlSelfRef.PS2__DOT__inst__DOT__count))) {
                if ((((~ (IData)(vlSelfRef.PS2__DOT__inst__DOT__buffer)) 
                      & (IData)(vlSelfRef.PS2_DAT)) 
                     & VL_REDXOR_32((0x000001ffU & 
                                     ((IData)(vlSelfRef.PS2__DOT__inst__DOT__buffer) 
                                      >> 1U))))) {
                    __VdlyVal__PS2__DOT__inst__DOT__fifo__v0 
                        = (0x000000ffU & ((IData)(vlSelfRef.PS2__DOT__inst__DOT__buffer) 
                                          >> 1U));
                    __VdlyDim0__PS2__DOT__inst__DOT__fifo__v0 
                        = vlSelfRef.PS2__DOT__inst__DOT__w_ptr;
                    __VdlySet__PS2__DOT__inst__DOT__fifo__v0 = 1U;
                    __Vdly__PS2__DOT__ready = 1U;
                    __Vdly__PS2__DOT__inst__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.PS2__DOT__inst__DOT__w_ptr)));
                    vlSelfRef.PS2__DOT__overflow = 
                        ((IData)(vlSelfRef.PS2__DOT__overflow) 
                         | ((IData)(vlSelfRef.PS2__DOT__inst__DOT__r_ptr) 
                            == (7U & ((IData)(1U) + (IData)(vlSelfRef.PS2__DOT__inst__DOT__w_ptr)))));
                }
                __Vdly__PS2__DOT__inst__DOT__count = 0U;
            } else {
                vlSelfRef.PS2__DOT__inst__DOT____Vlvbound_hf7a7b477__0 
                    = vlSelfRef.PS2_DAT;
                if ((9U >= (IData)(vlSelfRef.PS2__DOT__inst__DOT__count))) {
                    vlSelfRef.PS2__DOT__inst__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelfRef.PS2__DOT__inst__DOT__count))) 
                            & (IData)(vlSelfRef.PS2__DOT__inst__DOT__buffer)) 
                           | (0x03ffU & ((IData)(vlSelfRef.PS2__DOT__inst__DOT____Vlvbound_hf7a7b477__0) 
                                         << (IData)(vlSelfRef.PS2__DOT__inst__DOT__count))));
                }
                __Vdly__PS2__DOT__inst__DOT__count 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.PS2__DOT__inst__DOT__count)));
            }
        }
        if (vlSelfRef.PS2__DOT__status) {
            __Vdly__PS2__DOT__ifPressed = 0U;
        } else if (((((~ (IData)(vlSelfRef.PS2__DOT__status)) 
                      & (IData)(vlSelfRef.PS2__DOT__ready)) 
                     & (~ (IData)(vlSelfRef.PS2__DOT__ifPressed))) 
                    & (~ (IData)(vlSelfRef.PS2__DOT__nextstatus)))) {
            vlSelfRef.PS2__DOT__count = (0x000000ffU 
                                         & ((IData)(1U) 
                                            + (IData)(vlSelfRef.PS2__DOT__count)));
            __Vdly__PS2__DOT__ifPressed = 1U;
        }
        if (vlSelfRef.PS2__DOT__nextdata_n) {
            if (vlSelfRef.PS2__DOT__ready) {
                vlSelfRef.PS2__DOT__receiveData = (
                                                   (0x00ffff00U 
                                                    & vlSelfRef.PS2__DOT__receiveData) 
                                                   | (IData)(vlSelfRef.data));
                vlSelfRef.PS2__DOT__nextdata_n = 0U;
            }
        } else {
            vlSelfRef.PS2__DOT__nextdata_n = 1U;
        }
    } else {
        __Vdly__PS2__DOT__inst__DOT__count = 0U;
        __Vdly__PS2__DOT__inst__DOT__w_ptr = 0U;
        __Vdly__PS2__DOT__inst__DOT__r_ptr = 0U;
        vlSelfRef.PS2__DOT__overflow = 0U;
        __Vdly__PS2__DOT__ready = 0U;
        __Vdly__PS2__DOT__ifPressed = 0U;
        vlSelfRef.PS2__DOT__nextdata_n = 1U;
    }
    vlSelfRef.PS2__DOT__inst__DOT__ps2_clk_sync = __Vdly__PS2__DOT__inst__DOT__ps2_clk_sync;
    vlSelfRef.PS2__DOT__inst__DOT__w_ptr = __Vdly__PS2__DOT__inst__DOT__w_ptr;
    vlSelfRef.PS2__DOT__inst__DOT__count = __Vdly__PS2__DOT__inst__DOT__count;
    vlSelfRef.PS2__DOT__inst__DOT__r_ptr = __Vdly__PS2__DOT__inst__DOT__r_ptr;
    if (__VdlySet__PS2__DOT__inst__DOT__fifo__v0) {
        vlSelfRef.PS2__DOT__inst__DOT__fifo[__VdlyDim0__PS2__DOT__inst__DOT__fifo__v0] 
            = __VdlyVal__PS2__DOT__inst__DOT__fifo__v0;
    }
    vlSelfRef.PS2__DOT__ifPressed = __Vdly__PS2__DOT__ifPressed;
    vlSelfRef.PS2__DOT__ready = __Vdly__PS2__DOT__ready;
    vlSelfRef.data = vlSelfRef.PS2__DOT__inst__DOT__fifo
        [vlSelfRef.PS2__DOT__inst__DOT__r_ptr];
    __Vtableidx6 = (0x0000000fU & (IData)(vlSelfRef.PS2__DOT__count));
    vlSelfRef.PS2__DOT____Vcellout__segdec6____pinNumber2 
        = VPS2__ConstPool__TABLE_h0ee5ce4f_0[__Vtableidx6];
    __Vtableidx7 = (0x0000000fU & ((IData)(vlSelfRef.PS2__DOT__count) 
                                   >> 4U));
    vlSelfRef.PS2__DOT____Vcellout__segdec7____pinNumber2 
        = VPS2__ConstPool__TABLE_h0ee5ce4f_0[__Vtableidx7];
    vlSelfRef.PS2__DOT__status = ((IData)(vlSelfRef.CLRN) 
                                  && (IData)(vlSelfRef.PS2__DOT__nextstatus));
    __Vtableidx2 = ((0x0000001eU & (vlSelfRef.PS2__DOT__receiveData 
                                    << 1U)) | (IData)(vlSelfRef.PS2__DOT__ifPressed));
    vlSelfRef.PS2__DOT____Vcellout__segdec0____pinNumber2 
        = VPS2__ConstPool__TABLE_hfa5a6cbf_0[__Vtableidx2];
    __Vtableidx3 = ((0x0000001eU & (vlSelfRef.PS2__DOT__receiveData 
                                    >> 3U)) | (IData)(vlSelfRef.PS2__DOT__ifPressed));
    vlSelfRef.PS2__DOT____Vcellout__segdec1____pinNumber2 
        = VPS2__ConstPool__TABLE_hfa5a6cbf_0[__Vtableidx3];
    __Vtableidx1 = (0x000000ffU & vlSelfRef.PS2__DOT__receiveData);
    vlSelfRef.PS2__DOT__u_keycode_to_ascii__DOT__valid 
        = VPS2__ConstPool__TABLE_hdaf6d84f_0[__Vtableidx1];
    vlSelfRef.PS2__DOT__ascii_out = VPS2__ConstPool__TABLE_h433c6e94_0
        [__Vtableidx1];
    vlSelfRef.seg3L = (1U | ((IData)(vlSelfRef.PS2__DOT____Vcellout__segdec6____pinNumber2) 
                             << 1U));
    vlSelfRef.seg3H = (1U | ((IData)(vlSelfRef.PS2__DOT____Vcellout__segdec7____pinNumber2) 
                             << 1U));
    vlSelfRef.seg0L = (1U | ((IData)(vlSelfRef.PS2__DOT____Vcellout__segdec0____pinNumber2) 
                             << 1U));
    vlSelfRef.seg0H = (1U | ((IData)(vlSelfRef.PS2__DOT____Vcellout__segdec1____pinNumber2) 
                             << 1U));
    __Vtableidx4 = ((0x0000001eU & ((IData)(vlSelfRef.PS2__DOT__ascii_out) 
                                    << 1U)) | (IData)(vlSelfRef.PS2__DOT__ifPressed));
    vlSelfRef.PS2__DOT____Vcellout__segdec2____pinNumber2 
        = VPS2__ConstPool__TABLE_hfa5a6cbf_0[__Vtableidx4];
    __Vtableidx5 = ((0x0000001eU & ((IData)(vlSelfRef.PS2__DOT__ascii_out) 
                                    >> 3U)) | (IData)(vlSelfRef.PS2__DOT__ifPressed));
    vlSelfRef.PS2__DOT____Vcellout__segdec3____pinNumber2 
        = VPS2__ConstPool__TABLE_hfa5a6cbf_0[__Vtableidx5];
    vlSelfRef.PS2__DOT__nextstatus = ((~ (IData)(vlSelfRef.PS2__DOT__status)) 
                                      & (0xf0U == (0x000000ffU 
                                                   & vlSelfRef.PS2__DOT__receiveData)));
    vlSelfRef.seg1L = (1U | ((IData)(vlSelfRef.PS2__DOT____Vcellout__segdec2____pinNumber2) 
                             << 1U));
    vlSelfRef.seg1H = (1U | ((IData)(vlSelfRef.PS2__DOT____Vcellout__segdec3____pinNumber2) 
                             << 1U));
}

void VPS2___024root___eval_nba(VPS2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___eval_nba\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VPS2___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void VPS2___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VPS2___024root___eval_phase__act(VPS2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___eval_phase__act\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VPS2___024root___eval_triggers__act(vlSelf);
    VPS2___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VPS2___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VPS2___024root___eval_phase__nba(VPS2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___eval_phase__nba\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VPS2___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VPS2___024root___eval_nba(vlSelf);
        VPS2___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VPS2___024root___eval(VPS2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___eval\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VPS2___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/PS2.v", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VPS2___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/PS2.v", 1, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (VPS2___024root___eval_phase__act(vlSelf));
    } while (VPS2___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void VPS2___024root___eval_debug_assertions(VPS2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPS2___024root___eval_debug_assertions\n"); );
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.CLK & 0xfeU)))) {
        Verilated::overWidthError("CLK");
    }
    if (VL_UNLIKELY(((vlSelfRef.CLRN & 0xfeU)))) {
        Verilated::overWidthError("CLRN");
    }
    if (VL_UNLIKELY(((vlSelfRef.PS2_CLK & 0xfeU)))) {
        Verilated::overWidthError("PS2_CLK");
    }
    if (VL_UNLIKELY(((vlSelfRef.PS2_DAT & 0xfeU)))) {
        Verilated::overWidthError("PS2_DAT");
    }
}
#endif  // VL_DEBUG
