// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga.h for the primary calling header

#include "Vvga__pch.h"

VL_ATTR_COLD void Vvga___024root___eval_static(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_static\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void Vvga___024root___eval_initial__TOP(Vvga___024root* vlSelf);

VL_ATTR_COLD void Vvga___024root___eval_initial(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_initial\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vvga___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vvga___024root___eval_initial__TOP(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_initial__TOP\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 24, 307200, 0, "image_data.mif"s
                 ,  &(vlSelfRef.vga__DOT__u_rom__DOT__rom)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vvga___024root___eval_final(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_final\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vvga___024root___eval_phase__stl(Vvga___024root* vlSelf);

VL_ATTR_COLD void Vvga___024root___eval_settle(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_settle\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vvga___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("vsrc/vga.v", 1, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vvga___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vvga___024root___eval_triggers__stl(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_triggers__stl\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vvga___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vvga___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vvga___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vvga___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vvga___024root___stl_sequent__TOP__0(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___stl_sequent__TOP__0\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.vsync = (2U < (IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__y_cnt));
    vlSelfRef.hsync = (0x0060U < (IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__x_cnt));
    vlSelfRef.vga_r = (0x000000ffU & (vlSelfRef.vga__DOT__vga_data 
                                      >> 0x00000010U));
    vlSelfRef.vga_g = (0x000000ffU & (vlSelfRef.vga__DOT__vga_data 
                                      >> 8U));
    vlSelfRef.vga_b = (0x000000ffU & vlSelfRef.vga__DOT__vga_data);
    vlSelfRef.vga__DOT__u_vga_ctrl__DOT__v_valid = 
        ((0x0023U < (IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__y_cnt)) 
         & (0x0203U >= (IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__y_cnt)));
    vlSelfRef.vga__DOT__u_vga_ctrl__DOT__h_valid = 
        ((0x0090U < (IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__x_cnt)) 
         & (0x0310U >= (IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__x_cnt)));
    if (vlSelfRef.vga__DOT__u_vga_ctrl__DOT__v_valid) {
        vlSelfRef.vga__DOT__u_rom__DOT__v_addr = (0x000003ffU 
                                                  & ((IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__y_cnt) 
                                                     - (IData)(0x0024U)));
        vlSelfRef.valid = vlSelfRef.vga__DOT__u_vga_ctrl__DOT__h_valid;
    } else {
        vlSelfRef.vga__DOT__u_rom__DOT__v_addr = 0U;
        vlSelfRef.valid = 0U;
    }
    vlSelfRef.vga__DOT__u_rom__DOT__h_addr = ((IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__h_valid)
                                               ? (0x000003ffU 
                                                  & ((IData)(vlSelfRef.vga__DOT__u_vga_ctrl__DOT__x_cnt) 
                                                     - (IData)(0x0091U)))
                                               : 0U);
}

VL_ATTR_COLD void Vvga___024root____Vm_traceActivitySetAll(Vvga___024root* vlSelf);

VL_ATTR_COLD void Vvga___024root___eval_stl(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_stl\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vvga___024root___stl_sequent__TOP__0(vlSelf);
        Vvga___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vvga___024root___eval_phase__stl(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___eval_phase__stl\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vvga___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vvga___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vvga___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vvga___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vvga___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vvga___024root____Vm_traceActivitySetAll(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root____Vm_traceActivitySetAll\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vvga___024root___ctor_var_reset(Vvga___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga___024root___ctor_var_reset\n"); );
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->vsync = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18337175696363507471ull);
    vlSelf->hsync = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2999247747110030874ull);
    vlSelf->valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4944192500720994163ull);
    vlSelf->vga_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2055607138462276192ull);
    vlSelf->vga_g = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5773750216550251743ull);
    vlSelf->vga_b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17771436561197612375ull);
    vlSelf->vga__DOT__vga_data = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18024704970730073684ull);
    vlSelf->vga__DOT__u_rom__DOT__v_addr = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 13118048935629117416ull);
    vlSelf->vga__DOT__u_rom__DOT__h_addr = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 846058289357962931ull);
    for (int __Vi0 = 0; __Vi0 < 307200; ++__Vi0) {
        vlSelf->vga__DOT__u_rom__DOT__rom[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13161800137001564796ull);
    }
    vlSelf->vga__DOT__u_rom__DOT__addr_reg = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 4753636336874347453ull);
    vlSelf->vga__DOT__u_vga_ctrl__DOT__x_cnt = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 17377035439822976665ull);
    vlSelf->vga__DOT__u_vga_ctrl__DOT__y_cnt = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 15644639189649670144ull);
    vlSelf->vga__DOT__u_vga_ctrl__DOT__h_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9788500083632136934ull);
    vlSelf->vga__DOT__u_vga_ctrl__DOT__v_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8648674073635812563ull);
    vlSelf->__Vdly__vga__DOT__u_vga_ctrl__DOT__x_cnt = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 12120660746279052463ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1487628987237401141ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
