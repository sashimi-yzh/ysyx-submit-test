// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu.h for the primary calling header

#include "verilated.h"

#include "Vfpu__Syms.h"
#include "Vfpu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__ico(Vfpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpu___024root___eval_triggers__ico(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpu___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vfpu___024root___ico_sequent__TOP__2(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___ico_sequent__TOP__2\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hd252095e__0;
    VlWide<3>/*95:0*/ __Vtemp_h61c4b67e__0;
    // Body
    __Vtemp_hd252095e__0[0U] = (IData)((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                                             ^ 
                                                             VL_REDXOR_16(
                                                                          (0x3000U 
                                                                           & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))))))) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            (1U 
                                                             & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                                                ^ 
                                                                VL_REDXOR_16(
                                                                             (0x3000U 
                                                                              & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))))))) 
                                            << 0x3eU) 
                                           | (((QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                                                   ^ 
                                                                   VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))))))) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                                                      ^ 
                                                                      VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))))))) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                                                         ^ 
                                                                         VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))))))) 
                                                     << 0x3bU) 
                                                    | (((QData)((IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                                                            ^ 
                                                                            VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))))))) 
                                                        << 0x3aU) 
                                                       | (((QData)((IData)(
                                                                           (1U 
                                                                            & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                                                               ^ 
                                                                               VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))))))) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(
                                                                              (1U 
                                                                               & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))))))) 
                                                              << 0x38U) 
                                                             | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))))))) 
                                                                 << 0x37U) 
                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))))))) 
                                                                    << 0x36U) 
                                                                   | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))))))) 
                                                                       << 0x35U) 
                                                                      | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))))))) 
                                                                          << 0x34U) 
                                                                         | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))))))) 
                                                                             << 0x33U) 
                                                                            | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x32U) 
                                                                               | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1fU) 
                                                                                | ((0x40000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1eU)) 
                                                                                | ((0x20000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1dU)) 
                                                                                | ((0x10000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1cU)) 
                                                                                | ((0x8000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1bU)) 
                                                                                | ((0x4000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1aU)) 
                                                                                | ((0x2000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                                                                << 0x19U)) 
                                                                                | ((0x1000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                                                                << 0x18U)) 
                                                                                | ((0x800000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                                                                << 0x17U)) 
                                                                                | ((0x400000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                                                                << 0x16U)) 
                                                                                | ((0x200000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                                                                << 0x15U)) 
                                                                                | ((0x100000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                                                                << 0x14U)) 
                                                                                | ((0x80000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                                                                << 0x13U)) 
                                                                                | ((0x40000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                                                                << 0x12U)) 
                                                                                | ((0x20000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                                                                ^ 
                                                                                ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                                                                ^ 
                                                                                vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0U])))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vtemp_hd252095e__0[1U] = (IData)(((((QData)((IData)(
                                                          (1U 
                                                           & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.__PVT__fifth_s) 
                                                              ^ 
                                                              VL_REDXOR_16(
                                                                           (0x3000U 
                                                                            & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout_group))))))) 
                                          << 0x3fU) 
                                         | (((QData)((IData)(
                                                             (1U 
                                                              & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.__PVT__fifth_s) 
                                                                 ^ 
                                                                 VL_REDXOR_16(
                                                                              (0x3000U 
                                                                               & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout_group))))))) 
                                             << 0x3eU) 
                                            | (((QData)((IData)(
                                                                (1U 
                                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.__PVT__fifth_s) 
                                                                    ^ 
                                                                    VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout_group))))))) 
                                                << 0x3dU) 
                                               | (((QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.__PVT__fifth_s) 
                                                                       ^ 
                                                                       VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout_group))))))) 
                                                   << 0x3cU) 
                                                  | (((QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.__PVT__fifth_s) 
                                                                          ^ 
                                                                          VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout_group))))))) 
                                                      << 0x3bU) 
                                                     | (((QData)((IData)(
                                                                         (1U 
                                                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.__PVT__fifth_s) 
                                                                             ^ 
                                                                             VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout_group))))))) 
                                                         << 0x3aU) 
                                                        | (((QData)((IData)(
                                                                            (1U 
                                                                             & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout_group))))))) 
                                                            << 0x39U) 
                                                           | (((QData)((IData)(
                                                                               (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout_group))))))) 
                                                               << 0x38U) 
                                                              | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout_group))))))) 
                                                                  << 0x37U) 
                                                                 | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout_group))))))) 
                                                                     << 0x36U) 
                                                                    | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout_group))))))) 
                                                                        << 0x35U) 
                                                                       | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout_group))))))) 
                                                                           << 0x34U) 
                                                                          | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout_group))))))) 
                                                                              << 0x33U) 
                                                                             | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x32U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout_group))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1fU) 
                                                                                | ((0x40000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1eU)) 
                                                                                | ((0x20000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1dU)) 
                                                                                | ((0x10000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1cU)) 
                                                                                | ((0x8000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1bU)) 
                                                                                | ((0x4000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                                                                << 0x1aU)) 
                                                                                | ((0x2000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                                                                << 0x19U)) 
                                                                                | ((0x1000000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                                                                << 0x18U)) 
                                                                                | ((0x800000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                                                                << 0x17U)) 
                                                                                | ((0x400000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                                                                << 0x16U)) 
                                                                                | ((0x200000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                                                                << 0x15U)) 
                                                                                | ((0x100000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                                                                << 0x14U)) 
                                                                                | ((0x80000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                                                                << 0x13U)) 
                                                                                | ((0x40000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                                                                << 0x12U)) 
                                                                                | ((0x20000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s) 
                                                                                ^ 
                                                                                VL_REDXOR_16(
                                                                                (0x3000U 
                                                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                                                                ^ 
                                                                                ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                                                                ^ 
                                                                                vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                                                [0U])))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) 
                                        >> 0x20U));
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__s[0U] 
        = __Vtemp_hd252095e__0[0U];
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__s[1U] 
        = __Vtemp_hd252095e__0[1U];
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__s[2U] 
        = ((8U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.__PVT__fifth_s) 
                   ^ VL_REDXOR_16((0x3000U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout_group)))) 
                  << 3U)) | ((4U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.__PVT__fifth_s) 
                                     ^ VL_REDXOR_16(
                                                    (0x3000U 
                                                     & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout_group)))) 
                                    << 2U)) | ((2U 
                                                & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.__PVT__fifth_s) 
                                                    ^ 
                                                    VL_REDXOR_16(
                                                                 (0x3000U 
                                                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout_group)))) 
                                                   << 1U)) 
                                               | (1U 
                                                  & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.__PVT__fifth_s) 
                                                     ^ 
                                                     VL_REDXOR_16(
                                                                  (0x3000U 
                                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout_group))))))));
    __Vtemp_h61c4b67e__0[0U] = (IData)((((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout)) 
                                            << 0x3eU) 
                                           | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout)) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout)) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout)) 
                                                     << 0x3bU) 
                                                    | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout)) 
                                                        << 0x3aU) 
                                                       | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout)) 
                                                              << 0x38U) 
                                                             | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout)) 
                                                                 << 0x37U) 
                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout)) 
                                                                    << 0x36U) 
                                                                   | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout)) 
                                                                       << 0x35U) 
                                                                      | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout)) 
                                                                          << 0x34U) 
                                                                         | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout)) 
                                                                             << 0x33U) 
                                                                            | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout)) 
                                                                                << 0x32U) 
                                                                               | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout)) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout)) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout)) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout)) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout)) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout)) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout)) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout)) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout)) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout)) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout)) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout)) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout)) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout)) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout)) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout) 
                                                                                << 2U) 
                                                                                | ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout) 
                                                                                << 1U))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vtemp_h61c4b67e__0[1U] = (IData)(((((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut.cout)) 
                                          << 0x3fU) 
                                         | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut.cout)) 
                                             << 0x3eU) 
                                            | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut.cout)) 
                                                << 0x3dU) 
                                               | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut.cout)) 
                                                   << 0x3cU) 
                                                  | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut.cout)) 
                                                      << 0x3bU) 
                                                     | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut.cout)) 
                                                         << 0x3aU) 
                                                        | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut.cout)) 
                                                            << 0x39U) 
                                                           | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut.cout)) 
                                                               << 0x38U) 
                                                              | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut.cout)) 
                                                                  << 0x37U) 
                                                                 | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut.cout)) 
                                                                     << 0x36U) 
                                                                    | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut.cout)) 
                                                                        << 0x35U) 
                                                                       | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut.cout)) 
                                                                           << 0x34U) 
                                                                          | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut.cout)) 
                                                                              << 0x33U) 
                                                                             | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut.cout)) 
                                                                                << 0x32U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut.cout)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut.cout)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut.cout)) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut.cout)) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut.cout)) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut.cout)) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut.cout)) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut.cout)) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut.cout)) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut.cout)) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut.cout)) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut.cout)) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut.cout)) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut.cout)) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut.cout)) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut.cout)) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut.cout)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut.cout)) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut.cout) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut.cout) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut.cout) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut.cout) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout) 
                                                                                << 2U) 
                                                                                | ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout) 
                                                                                << 1U))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) 
                                        >> 0x20U));
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__cout2[0U] 
        = __Vtemp_h61c4b67e__0[0U];
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__cout2[1U] 
        = __Vtemp_h61c4b67e__0[1U];
    vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__cout2[2U] 
        = (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut.cout) 
            << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut.cout) 
                       << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut.cout) 
                                  << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut.cout))));
}

void Vfpu___024root___ico_sequent__TOP__0(Vfpu___024root* vlSelf);
void Vfpu___024root___ico_sequent__TOP__1(Vfpu___024root* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut__0(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);
void Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut__1(Vfpu_walloc_17bits* vlSelf);

void Vfpu___024root___eval_ico(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vfpu___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        Vfpu___024root___ico_sequent__TOP__1(vlSelf);
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut));
        Vfpu___024root___ico_sequent__TOP__2(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpu___024root___dump_triggers__act(Vfpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpu___024root___eval_triggers__act(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->reset) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__reset))));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__reset = vlSelf->reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpu___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vfpu___024root___nba_sequent__TOP__0(Vfpu___024root* vlSelf);
void Vfpu___024root___nba_sequent__TOP__1(Vfpu___024root* vlSelf);

void Vfpu___024root___eval_nba(Vfpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vfpu___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vfpu___024root___nba_sequent__TOP__1(vlSelf);
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut__0((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut));
        Vfpu_walloc_17bits___ico_sequent__TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut__1((&vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut));
        Vfpu___024root___ico_sequent__TOP__2(vlSelf);
    }
}
