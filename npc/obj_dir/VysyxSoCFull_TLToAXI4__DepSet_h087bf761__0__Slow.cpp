// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLToAXI4.h"
#include "VysyxSoCFull__Syms.h"

VL_ATTR_COLD void VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__0(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__0\n"); );
    // Body
    vlSelf->__PVT__a_first = (0U == (IData)(vlSelf->__PVT__r_counter));
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->__PVT__r_denied = ((IData)(vlSelf->__PVT__r_first)
                                ? (3U == (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rresp))
                                : (IData)(vlSelf->__PVT__r_denied_r));
    vlSelf->__PVT___out_wvalid_T_3 = (1U & ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                            | (IData)(vlSelf->__PVT__doneAW)));
    vlSelf->__PVT__r_wins = (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid) 
                              & (7U != (IData)(vlSelf->__PVT__b_delay))) 
                             | (IData)(vlSelf->__PVT__r_holds_d));
    if (vlSelf->__PVT__r_wins) {
        vlSelf->auto_in_d_bits_corrupt = ((0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rresp)) 
                                          | (IData)(vlSelf->__PVT__r_denied));
        vlSelf->auto_in_d_bits_denied = vlSelf->__PVT__r_denied;
        vlSelf->auto_in_d_valid = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rvalid;
    } else {
        vlSelf->auto_in_d_bits_corrupt = 0U;
        vlSelf->auto_in_d_bits_denied = (0U != (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bresp));
        vlSelf->auto_in_d_valid = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bvalid;
    }
}

extern const VlWide<20>/*639:0*/ VysyxSoCFull__ConstPool__CONST_h72c4c799_0;

VL_ATTR_COLD void VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__1(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__tl2axi4__1\n"); );
    // Init
    VlWide<4>/*127:0*/ __PVT___GEN_0;
    VL_ZERO_W(128, __PVT___GEN_0);
    CData/*0:0*/ __VdfgTmp_hbcc272f1__0;
    __VdfgTmp_hbcc272f1__0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_hee9d390a__0;
    VlWide<4>/*127:0*/ __Vtemp_hcb07eeed__0;
    VlWide<3>/*95:0*/ __Vtemp_hc6a9858f__0;
    VlWide<4>/*127:0*/ __Vtemp_hab792b22__0;
    VlWide<3>/*95:0*/ __Vtemp_hba612b4e__0;
    VlWide<3>/*95:0*/ __Vtemp_h15f08d96__0;
    // Body
    __Vtemp_hee9d390a__0[0U] = (IData)((((QData)((IData)(
                                                         (0x7fU 
                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                             >> 1U)))) 
                                         << 0x38U) 
                                        | (((QData)((IData)(
                                                            (0x7fU 
                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                >> 1U)))) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               (0x7fU 
                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                   >> 1U)))) 
                                               << 0x2aU) 
                                              | (((QData)((IData)(
                                                                  (0x7fU 
                                                                   & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                      >> 1U)))) 
                                                  << 0x23U) 
                                                 | (((QData)((IData)(
                                                                     (0x7fU 
                                                                      & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                         >> 1U)))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      ((0xfe00000U 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                           << 0x14U)) 
                                                                       | ((0x1fc000U 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                              << 0xdU)) 
                                                                          | ((0x3f80U 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                             | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))));
    __Vtemp_hee9d390a__0[1U] = ((0x80000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                << 0x1eU)) 
                                | (IData)(((((QData)((IData)(
                                                             (0x7fU 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                 >> 1U)))) 
                                             << 0x38U) 
                                            | (((QData)((IData)(
                                                                (0x7fU 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                    >> 1U)))) 
                                                << 0x31U) 
                                               | (((QData)((IData)(
                                                                   (0x7fU 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                       >> 1U)))) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      (0x7fU 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                          >> 1U)))) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         (0x7fU 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                             >> 1U)))) 
                                                         << 0x1cU) 
                                                        | (QData)((IData)(
                                                                          ((0xfe00000U 
                                                                            & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                               << 0x14U)) 
                                                                           | ((0x1fc000U 
                                                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                                << 0xdU)) 
                                                                              | ((0x3f80U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                                | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))) 
                                           >> 0x20U)));
    __Vtemp_hcb07eeed__0[0U] = __Vtemp_hee9d390a__0[0U];
    __Vtemp_hcb07eeed__0[1U] = __Vtemp_hee9d390a__0[1U];
    __Vtemp_hcb07eeed__0[2U] = ((0xf8000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                << 0x1aU)) 
                                | ((0x7f00000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                  << 0x13U)) 
                                   | ((0xfe000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                   << 0xcU)) 
                                      | ((0x1fc0U & 
                                          ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                           << 5U)) 
                                         | (0x3fU & 
                                            ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                             >> 2U))))));
    __Vtemp_hcb07eeed__0[3U] = ((0xfe00U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                            << 8U)) 
                                | ((0x1fcU & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                              << 1U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                            >> 6U))));
    __Vtemp_hc6a9858f__0[0U] = (IData)((((QData)((IData)(
                                                         (0x7fU 
                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                             >> 1U)))) 
                                         << 0x38U) 
                                        | (((QData)((IData)(
                                                            (0x7fU 
                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                >> 1U)))) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               (0x7fU 
                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                   >> 1U)))) 
                                               << 0x2aU) 
                                              | (((QData)((IData)(
                                                                  (0x7fU 
                                                                   & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                      >> 1U)))) 
                                                  << 0x23U) 
                                                 | (((QData)((IData)(
                                                                     (0x7fU 
                                                                      & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                         >> 1U)))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      ((0xfe00000U 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                           << 0x14U)) 
                                                                       | ((0x1fc000U 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                              << 0xdU)) 
                                                                          | ((0x3f80U 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                             | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))));
    __Vtemp_hc6a9858f__0[1U] = ((0x80000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                << 0x1eU)) 
                                | (IData)(((((QData)((IData)(
                                                             (0x7fU 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                 >> 1U)))) 
                                             << 0x38U) 
                                            | (((QData)((IData)(
                                                                (0x7fU 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                    >> 1U)))) 
                                                << 0x31U) 
                                               | (((QData)((IData)(
                                                                   (0x7fU 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                       >> 1U)))) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      (0x7fU 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                          >> 1U)))) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         (0x7fU 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                             >> 1U)))) 
                                                         << 0x1cU) 
                                                        | (QData)((IData)(
                                                                          ((0xfe00000U 
                                                                            & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                               << 0x14U)) 
                                                                           | ((0x1fc000U 
                                                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                                << 0xdU)) 
                                                                              | ((0x3f80U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                                | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))) 
                                           >> 0x20U)));
    __Vtemp_hab792b22__0[0U] = __Vtemp_hc6a9858f__0[0U];
    __Vtemp_hab792b22__0[1U] = __Vtemp_hc6a9858f__0[1U];
    __Vtemp_hab792b22__0[2U] = ((0xf8000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                << 0x1aU)) 
                                | ((0x7f00000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                  << 0x13U)) 
                                   | ((0xfe000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                   << 0xcU)) 
                                      | ((0x1fc0U & 
                                          ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                           << 5U)) 
                                         | (0x3fU & 
                                            ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                             >> 2U))))));
    __Vtemp_hab792b22__0[3U] = ((0xfe00U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                            << 8U)) 
                                | ((0x1fcU & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                              << 1U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                            >> 6U))));
    if (vlSelf->__PVT__r_wins) {
        vlSelf->__VdfgTmp_h3c545424__0 = ((0x10U & 
                                           ((((0x8000U 
                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                                  << 0xfU)) 
                                              | ((0x4000U 
                                                  & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                                     << 0xeU)) 
                                                 | ((0x2000U 
                                                     & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                           << 0xcU)) 
                                                       | ((0x800U 
                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                              << 0xbU)) 
                                                          | ((0x400U 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                                                 << 0xaU)) 
                                                             | ((0x200U 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                                    << 9U)) 
                                                                | ((0x100U 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                       << 8U)) 
                                                                   | ((0x80U 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                          << 7U)) 
                                                                      | ((0x40U 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                             << 6U)) 
                                                                         | ((0x20U 
                                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                                << 5U)) 
                                                                            | ((0x10U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                               | ((8U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data))))))))))))))))) 
                                             >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                                            << 4U)) 
                                          | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid));
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    ((((QData)((IData)(
                                                                       (0xfU 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                                                           >> 8U)))) 
                                                       << 0x3cU) 
                                                      | (((QData)((IData)(
                                                                          (0xfU 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                                                              >> 8U)))) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             (0xfU 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                                                >> 8U)))) 
                                                             << 0x34U) 
                                                            | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                                                >> 8U)))) 
                                                                << 0x30U) 
                                                               | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                                                >> 8U)))) 
                                                                   << 0x2cU) 
                                                                  | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                                                                >> 8U)))) 
                                                                      << 0x28U) 
                                                                     | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                                                >> 8U)))) 
                                                                         << 0x24U) 
                                                                        | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                                >> 8U)))) 
                                                                            << 0x20U) 
                                                                           | (QData)((IData)(
                                                                                ((0xf0000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                                << 0x14U)) 
                                                                                | ((0xf000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                                << 0x10U)) 
                                                                                | ((0xf00000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                                << 0xcU)) 
                                                                                | ((0xf0000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                                << 8U)) 
                                                                                | ((0xf000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                                | ((0xf00U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data)) 
                                                                                | ((0xf0U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                >> 4U)) 
                                                                                | (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 8U))))))))))))))))))) 
                                                     >> 
                                                     (0x3fU 
                                                      & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid) 
                                                         << 2U)))));
        vlSelf->auto_in_d_bits_source = (0x7fU & ((0x6fU 
                                                   >= 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid))))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hcb07eeed__0[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)))))) 
                                                   | (__Vtemp_hcb07eeed__0[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_rid)))))
                                                   : 0U));
    } else {
        vlSelf->__VdfgTmp_h3c545424__0 = ((0x10U & 
                                           ((((0x8000U 
                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                                  << 0xfU)) 
                                              | ((0x4000U 
                                                  & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                                     << 0xeU)) 
                                                 | ((0x2000U 
                                                     & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                           << 0xcU)) 
                                                       | ((0x800U 
                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                              << 0xbU)) 
                                                          | ((0x400U 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                                                 << 0xaU)) 
                                                             | ((0x200U 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                                    << 9U)) 
                                                                | ((0x100U 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                       << 8U)) 
                                                                   | ((0x80U 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                          << 7U)) 
                                                                      | ((0x40U 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                             << 6U)) 
                                                                         | ((0x20U 
                                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                                << 5U)) 
                                                                            | ((0x10U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                               | ((8U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data))))))))))))))))) 
                                             >> (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                                            << 4U)) 
                                          | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid));
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    ((((QData)((IData)(
                                                                       (0xfU 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                                                           >> 8U)))) 
                                                       << 0x3cU) 
                                                      | (((QData)((IData)(
                                                                          (0xfU 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                                                              >> 8U)))) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             (0xfU 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                                                >> 8U)))) 
                                                             << 0x34U) 
                                                            | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                                                >> 8U)))) 
                                                                << 0x30U) 
                                                               | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                                                >> 8U)))) 
                                                                   << 0x2cU) 
                                                                  | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                                                                >> 8U)))) 
                                                                      << 0x28U) 
                                                                     | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                                                >> 8U)))) 
                                                                         << 0x24U) 
                                                                        | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                                >> 8U)))) 
                                                                            << 0x20U) 
                                                                           | (QData)((IData)(
                                                                                ((0xf0000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                                << 0x14U)) 
                                                                                | ((0xf000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                                << 0x10U)) 
                                                                                | ((0xf00000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                                << 0xcU)) 
                                                                                | ((0xf0000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                                << 8U)) 
                                                                                | ((0xf000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                                | ((0xf00U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data)) 
                                                                                | ((0xf0U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                >> 4U)) 
                                                                                | (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 8U))))))))))))))))))) 
                                                     >> 
                                                     (0x3fU 
                                                      & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid) 
                                                         << 2U)))));
        vlSelf->auto_in_d_bits_source = (0x7fU & ((0x6fU 
                                                   >= 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid))))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hab792b22__0[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)))))) 
                                                   | (__Vtemp_hab792b22__0[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_bid)))))
                                                   : 0U));
    }
    vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id 
        = ((0x27fU >= (0x3ffU & ((IData)(5U) * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))))
            ? (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))))
                          ? 0U : (VysyxSoCFull__ConstPool__CONST_h72c4c799_0[
                                  (((IData)(4U) + (0x3ffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source)))))) 
                        | (VysyxSoCFull__ConstPool__CONST_h72c4c799_0[
                           (0x1fU & (((IData)(5U) * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source)) 
                                     >> 5U))] >> (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))))))
            : 0U);
    if (vlSelf->__PVT__queue_arw_deq_q__DOT__full) {
        vlSelf->auto_out_awecho_tl_state_size = (0xfU 
                                                 & (IData)(
                                                           (vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                            >> 8U)));
        vlSelf->auto_out_awecho_tl_state_source = (0x7fU 
                                                   & (IData)(
                                                             (vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                              >> 1U)));
        vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen 
            = (1U & (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__ram));
        vlSelf->auto_out_awid = (0x1fU & (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                  >> 0x39U)));
    } else {
        vlSelf->auto_out_awecho_tl_state_size = (0xfU 
                                                 & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size));
        vlSelf->auto_out_awecho_tl_state_source = (0x7fU 
                                                   & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source));
        vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen 
            = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                        >> 2U)));
        vlSelf->auto_out_awid = (0x1fU & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id));
    }
    vlSelf->__PVT__r_beats1 = ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))
                                ? 0U : (7U & (~ (0x3ffU 
                                                 & (((IData)(0x1fU) 
                                                     << (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_size)) 
                                                    >> 2U)))));
    vlSelf->__PVT__idStall_4 = (((0U != (IData)(vlSelf->__PVT__count_4)) 
                                 & ((IData)(vlSelf->__PVT__write_4) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count_4)));
    vlSelf->__PVT__idStall_2 = (((0U != (IData)(vlSelf->__PVT__count_2)) 
                                 & ((IData)(vlSelf->__PVT__write_2) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count_2)));
    vlSelf->__PVT__idStall_0 = (((0U != (IData)(vlSelf->__PVT__count)) 
                                 & ((IData)(vlSelf->__PVT__write) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count)));
    vlSelf->__PVT__a_last = ((1U == (IData)(vlSelf->__PVT__r_counter)) 
                             | (0U == (IData)(vlSelf->__PVT__r_beats1)));
    __Vtemp_hba612b4e__0[0U] = (IData)((((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                            << 0x3eU) 
                                           | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                     << 0x3bU) 
                                                    | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                        << 0x3aU) 
                                                       | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                              << 0x38U) 
                                                             | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                 << 0x37U) 
                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                    << 0x36U) 
                                                                   | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                       << 0x35U) 
                                                                      | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                          << 0x34U) 
                                                                         | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                             << 0x33U) 
                                                                            | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x32U) 
                                                                               | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_1)) 
                                                                                & ((IData)(vlSelf->__PVT__write_1) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_1)))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->__PVT__count_22) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->__PVT__count_21) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->__PVT__count_20) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__count_19) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__count_18) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->__PVT__count_17) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->__PVT__count_16) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->__PVT__count_15) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->__PVT__count_14) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->__PVT__count_13) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->__PVT__count_12) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->__PVT__count_11) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->__PVT__count_10) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->__PVT__count_9) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->__PVT__count_8) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->__PVT__count_7))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vtemp_hba612b4e__0[1U] = (IData)(((((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                          << 0x3fU) 
                                         | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                             << 0x3eU) 
                                            | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                << 0x3dU) 
                                               | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                   << 0x3cU) 
                                                  | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                      << 0x3bU) 
                                                     | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                         << 0x3aU) 
                                                        | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                            << 0x39U) 
                                                           | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                               << 0x38U) 
                                                              | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                  << 0x37U) 
                                                                 | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                     << 0x36U) 
                                                                    | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                        << 0x35U) 
                                                                       | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                           << 0x34U) 
                                                                          | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                              << 0x33U) 
                                                                             | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x32U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_1)) 
                                                                                & ((IData)(vlSelf->__PVT__write_1) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_1)))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->__PVT__count_22) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->__PVT__count_21) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->__PVT__count_20) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__count_19) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__count_18) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->__PVT__count_17) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->__PVT__count_16) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->__PVT__count_15) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->__PVT__count_14) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->__PVT__count_13) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->__PVT__count_12) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->__PVT__count_11) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->__PVT__count_10) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->__PVT__count_9) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->__PVT__count_8) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->__PVT__count_7))))))))))))))))))))))))))))))))))))))))))))))))))) 
                                        >> 0x20U));
    __Vtemp_h15f08d96__0[2U] = (((IData)(vlSelf->__PVT__idStall_4) 
                                 << 0x1aU) | (((IData)(vlSelf->__PVT__idStall_4) 
                                               << 0x19U) 
                                              | (((IData)(vlSelf->__PVT__idStall_4) 
                                                  << 0x18U) 
                                                 | (((IData)(vlSelf->__PVT__idStall_4) 
                                                     << 0x17U) 
                                                    | (((IData)(vlSelf->__PVT__idStall_4) 
                                                        << 0x16U) 
                                                       | (((IData)(vlSelf->__PVT__idStall_4) 
                                                           << 0x15U) 
                                                          | (((IData)(vlSelf->__PVT__idStall_4) 
                                                              << 0x14U) 
                                                             | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                 << 0x13U) 
                                                                | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                    << 0x12U) 
                                                                   | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                       << 0x11U) 
                                                                      | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                          << 0x10U) 
                                                                         | (0xffffU 
                                                                            & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_3)) 
                                                                                & ((IData)(vlSelf->__PVT__write_3) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_3)))))))))))))))));
    __PVT___GEN_0[0U] = __Vtemp_hba612b4e__0[0U];
    __PVT___GEN_0[1U] = __Vtemp_hba612b4e__0[1U];
    __PVT___GEN_0[2U] = (((IData)(vlSelf->__PVT__idStall_4) 
                          << 0x1fU) | (((IData)(vlSelf->__PVT__idStall_4) 
                                        << 0x1eU) | 
                                       (((IData)(vlSelf->__PVT__idStall_4) 
                                         << 0x1dU) 
                                        | (((IData)(vlSelf->__PVT__idStall_4) 
                                            << 0x1cU) 
                                           | (((IData)(vlSelf->__PVT__idStall_4) 
                                               << 0x1bU) 
                                              | __Vtemp_h15f08d96__0[2U])))));
    __PVT___GEN_0[3U] = (((- (IData)((((0U != (IData)(vlSelf->__PVT__count_6)) 
                                       & ((IData)(vlSelf->__PVT__write_6) 
                                          != (1U & 
                                              (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                  >> 2U))))) 
                                      | (0x10U == (IData)(vlSelf->__PVT__count_6))))) 
                          << 0x10U) | (0xffffU & (- (IData)(
                                                            (((0U 
                                                               != (IData)(vlSelf->__PVT__count_5)) 
                                                              & ((IData)(vlSelf->__PVT__write_5) 
                                                                 != 
                                                                 (1U 
                                                                  & (~ 
                                                                     ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                                      >> 2U))))) 
                                                             | (0x10U 
                                                                == (IData)(vlSelf->__PVT__count_5)))))));
    vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready 
        = ((IData)(vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen)
            ? ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_awready) 
               & (((0x8000U & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_17__DOT__full)) 
                               << 0xfU)) | ((0x4000U 
                                             & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_16__DOT__full)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_15__DOT__full)) 
                                                   << 0xdU)) 
                                               | ((0x1000U 
                                                   & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_14__DOT__full)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_13__DOT__full)) 
                                                         << 0xbU)) 
                                                     | ((0x400U 
                                                         & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_12__DOT__full)) 
                                                            << 0xaU)) 
                                                        | ((0x200U 
                                                            & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_11__DOT__full)) 
                                                               << 9U)) 
                                                           | ((0x100U 
                                                               & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_10__DOT__full)) 
                                                                  << 8U)) 
                                                              | ((0x80U 
                                                                  & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_9__DOT__full)) 
                                                                     << 7U)) 
                                                                 | ((0x40U 
                                                                     & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_13__DOT__full)) 
                                                                        << 6U)) 
                                                                    | ((0x20U 
                                                                        & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_12__DOT__full)) 
                                                                           << 5U)) 
                                                                       | ((0x10U 
                                                                           & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_11__DOT__full)) 
                                                                              << 4U)) 
                                                                          | ((8U 
                                                                              & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_10__DOT__full)) 
                                                                                << 3U)) 
                                                                             | ((4U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_9__DOT__full)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_8__DOT__full)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_7__DOT__full)))))))))))))))))) 
                  >> (0xfU & (IData)(vlSelf->auto_out_awid))))
            : ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_arready) 
               & (((0x8000U & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_8__DOT__full)) 
                               << 0xfU)) | ((0x4000U 
                                             & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_7__DOT__full)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_6__DOT__full)) 
                                                   << 0xdU)) 
                                               | ((0x1000U 
                                                   & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_5__DOT__full)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_4__DOT__full)) 
                                                         << 0xbU)) 
                                                     | ((0x400U 
                                                         & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_3__DOT__full)) 
                                                            << 0xaU)) 
                                                        | ((0x200U 
                                                            & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_2__DOT__full)) 
                                                               << 9U)) 
                                                           | ((0x100U 
                                                               & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap_1__DOT__full)) 
                                                                  << 8U)) 
                                                              | ((0x80U 
                                                                  & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue1_BundleMap__DOT__full)) 
                                                                     << 7U)) 
                                                                 | ((0x40U 
                                                                     & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_6__DOT__full)) 
                                                                        << 6U)) 
                                                                    | ((0x20U 
                                                                        & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_5__DOT__full)) 
                                                                           << 5U)) 
                                                                       | ((0x10U 
                                                                           & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_4__DOT__full)) 
                                                                              << 4U)) 
                                                                          | ((8U 
                                                                              & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_3__DOT__full)) 
                                                                                << 3U)) 
                                                                             | ((4U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_2__DOT__full)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap_1__DOT__full)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT__axi4yank_1.__PVT__Queue17_BundleMap__DOT__full)))))))))))))))))) 
                  >> (0xfU & (IData)(vlSelf->auto_out_awid)))));
    vlSelf->__PVT__stall = ((__PVT___GEN_0[((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source) 
                                            >> 5U)] 
                             >> (0x1fU & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_source))) 
                            & (0U == (IData)(vlSelf->__PVT__r_counter)));
    __VdfgTmp_hbcc272f1__0 = ((~ (IData)(vlSelf->__PVT__stall)) 
                              & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid));
    vlSelf->auto_in_a_ready = (1U & ((~ (IData)(vlSelf->__PVT__stall)) 
                                     & ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode))
                                         ? (~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full))
                                         : ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                            & (IData)(vlSelf->__PVT___out_wvalid_T_3)))));
    vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid 
        = ((IData)(__VdfgTmp_hbcc272f1__0) & ((~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                                  >> 2U)) 
                                              & (IData)(vlSelf->__PVT___out_wvalid_T_3)));
    vlSelf->__PVT__out_arw_valid = ((IData)(__VdfgTmp_hbcc272f1__0) 
                                    & (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___atomics_auto_out_a_bits_opcode) 
                                        >> 2U) | ((~ (IData)(vlSelf->__PVT__doneAW)) 
                                                  & (~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)))));
    vlSelf->__PVT__monitor__DOT___a_first_T_1 = ((IData)(vlSelf->auto_in_a_ready) 
                                                 & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__chipMaster__DOT___xbar_auto_anon_out_0_a_valid));
    vlSelf->auto_out_wvalid = ((IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full) 
                               | (IData)(vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid));
    vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq = ((~ 
                                                   ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT___cpu_slave_wready))) 
                                                  & ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                                     & (IData)(vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid)));
    vlSelf->__PVT___inc_T_22 = ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                & (IData)(vlSelf->__PVT__out_arw_valid));
    vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full) 
           | (IData)(vlSelf->__PVT__out_arw_valid));
    vlSelf->__PVT__monitor__DOT___GEN_1 = ((IData)(vlSelf->__PVT__monitor__DOT___a_first_T_1) 
                                           & (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1)));
    vlSelf->__PVT__inc = (((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                          & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_1 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 1U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_2 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 2U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_3 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 3U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_4 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 4U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_5 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 5U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_6 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 6U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq = (
                                                   (~ 
                                                    ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                                     & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready))) 
                                                   & (IData)(vlSelf->__PVT___inc_T_22));
}

VL_ATTR_COLD void VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__0(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__0\n"); );
    // Body
    vlSelf->__PVT__a_first = (0U == (IData)(vlSelf->__PVT__r_counter));
    vlSelf->__PVT__monitor__DOT__a_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_1 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_1));
    vlSelf->__PVT__monitor__DOT__d_first_2 = (0U == (IData)(vlSelf->__PVT__monitor__DOT__d_first_counter_2));
    vlSelf->auto_out_awburst = ((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)
                                 ? (3U & (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                  >> 0xcU)))
                                 : 1U);
    vlSelf->__PVT___out_wvalid_T_3 = (1U & ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                            | (IData)(vlSelf->__PVT__doneAW)));
    vlSelf->__PVT__r_denied = ((IData)(vlSelf->__PVT__r_first)
                                ? (3U == (3U & (IData)(
                                                       (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                        >> 2U))))
                                : (IData)(vlSelf->__PVT__r_denied_r));
    vlSelf->__PVT__r_wins = (((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__empty)) 
                              & (7U != (IData)(vlSelf->__PVT__b_delay))) 
                             | (IData)(vlSelf->__PVT__r_holds_d));
    if (vlSelf->__PVT__r_wins) {
        vlSelf->auto_in_d_bits_corrupt = (IData)(((0ULL 
                                                   != 
                                                   (0xcULL 
                                                    & vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data)) 
                                                  | (IData)(vlSelf->__PVT__r_denied)));
        vlSelf->auto_in_d_bits_denied = vlSelf->__PVT__r_denied;
        vlSelf->auto_in_d_valid = (1U & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__empty)));
    } else {
        vlSelf->auto_in_d_bits_corrupt = 0U;
        vlSelf->auto_in_d_bits_denied = (0U != (3U 
                                                & (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                    >> 1U) 
                                                   | ((((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_15) 
                                                        << 0x1eU) 
                                                       | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_14) 
                                                           << 0x1cU) 
                                                          | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_13) 
                                                              << 0x1aU) 
                                                             | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_12) 
                                                                 << 0x18U) 
                                                                | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_11) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_10) 
                                                                       << 0x14U) 
                                                                      | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_9) 
                                                                          << 0x12U) 
                                                                         | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_8) 
                                                                             << 0x10U) 
                                                                            | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_7) 
                                                                                << 0xeU) 
                                                                               | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_6) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_5) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_4) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_3) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_2) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_1) 
                                                                                << 2U) 
                                                                                | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__error_0)))))))))))))))) 
                                                      >> 
                                                      (0x1eU 
                                                       & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                          >> 2U))))));
        vlSelf->auto_in_d_valid = (1U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_bvalid));
    }
}

VL_ATTR_COLD void VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__1(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__1\n"); );
    // Init
    VlWide<4>/*127:0*/ __PVT___GEN_0;
    VL_ZERO_W(128, __PVT___GEN_0);
    CData/*0:0*/ __VdfgTmp_hbcc272f1__0;
    __VdfgTmp_hbcc272f1__0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_h2961c68b__0;
    VlWide<4>/*127:0*/ __Vtemp_h4286d03b__0;
    VlWide<3>/*95:0*/ __Vtemp_h3bda771c__0;
    VlWide<4>/*127:0*/ __Vtemp_h9c3ed76f__0;
    VlWide<3>/*95:0*/ __Vtemp_h0f66af41__0;
    VlWide<3>/*95:0*/ __Vtemp_h97ba1eef__0;
    // Body
    __Vtemp_h2961c68b__0[0U] = (IData)((((QData)((IData)(
                                                         (0x7fU 
                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                             >> 1U)))) 
                                         << 0x38U) 
                                        | (((QData)((IData)(
                                                            (0x7fU 
                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                >> 1U)))) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               (0x7fU 
                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                   >> 1U)))) 
                                               << 0x2aU) 
                                              | (((QData)((IData)(
                                                                  (0x7fU 
                                                                   & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                      >> 1U)))) 
                                                  << 0x23U) 
                                                 | (((QData)((IData)(
                                                                     (0x7fU 
                                                                      & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                         >> 1U)))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      ((0xfe00000U 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                           << 0x14U)) 
                                                                       | ((0x1fc000U 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                              << 0xdU)) 
                                                                          | ((0x3f80U 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                             | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))));
    __Vtemp_h2961c68b__0[1U] = ((0x80000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                << 0x1eU)) 
                                | (IData)(((((QData)((IData)(
                                                             (0x7fU 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                 >> 1U)))) 
                                             << 0x38U) 
                                            | (((QData)((IData)(
                                                                (0x7fU 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                    >> 1U)))) 
                                                << 0x31U) 
                                               | (((QData)((IData)(
                                                                   (0x7fU 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                       >> 1U)))) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      (0x7fU 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                          >> 1U)))) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         (0x7fU 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                             >> 1U)))) 
                                                         << 0x1cU) 
                                                        | (QData)((IData)(
                                                                          ((0xfe00000U 
                                                                            & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                               << 0x14U)) 
                                                                           | ((0x1fc000U 
                                                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                                << 0xdU)) 
                                                                              | ((0x3f80U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                                | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))) 
                                           >> 0x20U)));
    __Vtemp_h4286d03b__0[0U] = __Vtemp_h2961c68b__0[0U];
    __Vtemp_h4286d03b__0[1U] = __Vtemp_h2961c68b__0[1U];
    __Vtemp_h4286d03b__0[2U] = ((0xf8000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                << 0x1aU)) 
                                | ((0x7f00000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                  << 0x13U)) 
                                   | ((0xfe000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                   << 0xcU)) 
                                      | ((0x1fc0U & 
                                          ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                           << 5U)) 
                                         | (0x3fU & 
                                            ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                             >> 2U))))));
    __Vtemp_h4286d03b__0[3U] = ((0xfe00U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                            << 8U)) 
                                | ((0x1fcU & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                              << 1U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                            >> 6U))));
    __Vtemp_h3bda771c__0[0U] = (IData)((((QData)((IData)(
                                                         (0x7fU 
                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                             >> 1U)))) 
                                         << 0x38U) 
                                        | (((QData)((IData)(
                                                            (0x7fU 
                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                >> 1U)))) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               (0x7fU 
                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                   >> 1U)))) 
                                               << 0x2aU) 
                                              | (((QData)((IData)(
                                                                  (0x7fU 
                                                                   & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                      >> 1U)))) 
                                                  << 0x23U) 
                                                 | (((QData)((IData)(
                                                                     (0x7fU 
                                                                      & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                         >> 1U)))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      ((0xfe00000U 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                           << 0x14U)) 
                                                                       | ((0x1fc000U 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                              << 0xdU)) 
                                                                          | ((0x3f80U 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                             | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))));
    __Vtemp_h3bda771c__0[1U] = ((0x80000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                << 0x1eU)) 
                                | (IData)(((((QData)((IData)(
                                                             (0x7fU 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                 >> 1U)))) 
                                             << 0x38U) 
                                            | (((QData)((IData)(
                                                                (0x7fU 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                    >> 1U)))) 
                                                << 0x31U) 
                                               | (((QData)((IData)(
                                                                   (0x7fU 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                       >> 1U)))) 
                                                   << 0x2aU) 
                                                  | (((QData)((IData)(
                                                                      (0x7fU 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                          >> 1U)))) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         (0x7fU 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                             >> 1U)))) 
                                                         << 0x1cU) 
                                                        | (QData)((IData)(
                                                                          ((0xfe00000U 
                                                                            & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                               << 0x14U)) 
                                                                           | ((0x1fc000U 
                                                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                                << 0xdU)) 
                                                                              | ((0x3f80U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 6U)) 
                                                                                | (0x7fU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 1U)))))))))))) 
                                           >> 0x20U)));
    __Vtemp_h9c3ed76f__0[0U] = __Vtemp_h3bda771c__0[0U];
    __Vtemp_h9c3ed76f__0[1U] = __Vtemp_h3bda771c__0[1U];
    __Vtemp_h9c3ed76f__0[2U] = ((0xf8000000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                << 0x1aU)) 
                                | ((0x7f00000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                  << 0x13U)) 
                                   | ((0xfe000U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                   << 0xcU)) 
                                      | ((0x1fc0U & 
                                          ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                           << 5U)) 
                                         | (0x3fU & 
                                            ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                             >> 2U))))));
    __Vtemp_h9c3ed76f__0[3U] = ((0xfe00U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                            << 8U)) 
                                | ((0x1fcU & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                              << 1U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                            >> 6U))));
    if (vlSelf->__PVT__r_wins) {
        vlSelf->__VdfgTmp_h3c545424__0 = ((0x10U & 
                                           ((((0x8000U 
                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                                  << 0xfU)) 
                                              | ((0x4000U 
                                                  & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                                     << 0xeU)) 
                                                 | ((0x2000U 
                                                     & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                           << 0xcU)) 
                                                       | ((0x800U 
                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                              << 0xbU)) 
                                                          | ((0x400U 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                                                 << 0xaU)) 
                                                             | ((0x200U 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                                    << 9U)) 
                                                                | ((0x100U 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                       << 8U)) 
                                                                   | ((0x80U 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                          << 7U)) 
                                                                      | ((0x40U 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                             << 6U)) 
                                                                         | ((0x20U 
                                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                                << 5U)) 
                                                                            | ((0x10U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                               | ((8U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data))))))))))))))))) 
                                             >> (0xfU 
                                                 & (IData)(
                                                           (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                            >> 0x24U)))) 
                                            << 4U)) 
                                          | (0xfU & (IData)(
                                                            (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                             >> 0x24U))));
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    ((((QData)((IData)(
                                                                       (0xfU 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_8__DOT__ram) 
                                                                           >> 8U)))) 
                                                       << 0x3cU) 
                                                      | (((QData)((IData)(
                                                                          (0xfU 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_7__DOT__ram) 
                                                                              >> 8U)))) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             (0xfU 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_6__DOT__ram) 
                                                                                >> 8U)))) 
                                                             << 0x34U) 
                                                            | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_5__DOT__ram) 
                                                                                >> 8U)))) 
                                                                << 0x30U) 
                                                               | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_4__DOT__ram) 
                                                                                >> 8U)))) 
                                                                   << 0x2cU) 
                                                                  | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_3__DOT__ram) 
                                                                                >> 8U)))) 
                                                                      << 0x28U) 
                                                                     | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_2__DOT__ram) 
                                                                                >> 8U)))) 
                                                                         << 0x24U) 
                                                                        | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_1__DOT__ram) 
                                                                                >> 8U)))) 
                                                                            << 0x20U) 
                                                                           | (QData)((IData)(
                                                                                ((0xf0000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap__DOT__ram) 
                                                                                << 0x14U)) 
                                                                                | ((0xf000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_6__DOT___ram_ext_R0_data) 
                                                                                << 0x10U)) 
                                                                                | ((0xf00000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_5__DOT___ram_ext_R0_data) 
                                                                                << 0xcU)) 
                                                                                | ((0xf0000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_4__DOT___ram_ext_R0_data) 
                                                                                << 8U)) 
                                                                                | ((0xf000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_3__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                                | ((0xf00U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_2__DOT___ram_ext_R0_data)) 
                                                                                | ((0xf0U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_1__DOT___ram_ext_R0_data) 
                                                                                >> 4U)) 
                                                                                | (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap__DOT___ram_ext_R0_data) 
                                                                                >> 8U))))))))))))))))))) 
                                                     >> 
                                                     (0x3cU 
                                                      & ((IData)(
                                                                 (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                                  >> 0x24U)) 
                                                         << 2U)))));
        vlSelf->auto_in_d_bits_source = (0x7fU & ((0x6fU 
                                                   >= 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & (IData)(
                                                                  (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                                   >> 0x24U))))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0xfU 
                                                          & (IData)(
                                                                    (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                                     >> 0x24U))))))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_h4286d03b__0[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * 
                                                           (0xfU 
                                                            & (IData)(
                                                                      (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                                       >> 0x24U)))))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0xfU 
                                                           & (IData)(
                                                                     (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                                      >> 0x24U)))))))) 
                                                   | (__Vtemp_h4286d03b__0[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * 
                                                           (0xfU 
                                                            & (IData)(
                                                                      (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                                       >> 0x24U)))) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0xfU 
                                                           & (IData)(
                                                                     (vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                                      >> 0x24U)))))))
                                                   : 0U));
    } else {
        vlSelf->__VdfgTmp_h3c545424__0 = ((0x10U & 
                                           ((((0x8000U 
                                               & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                                  << 0xfU)) 
                                              | ((0x4000U 
                                                  & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                                     << 0xeU)) 
                                                 | ((0x2000U 
                                                     & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                           << 0xcU)) 
                                                       | ((0x800U 
                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                              << 0xbU)) 
                                                          | ((0x400U 
                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                                                 << 0xaU)) 
                                                             | ((0x200U 
                                                                 & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                                    << 9U)) 
                                                                | ((0x100U 
                                                                    & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                       << 8U)) 
                                                                   | ((0x80U 
                                                                       & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                          << 7U)) 
                                                                      | ((0x40U 
                                                                          & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                             << 6U)) 
                                                                         | ((0x20U 
                                                                             & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                                << 5U)) 
                                                                            | ((0x10U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                               | ((8U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data))))))))))))))))) 
                                             >> (0xfU 
                                                 & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                    >> 3U))) 
                                            << 4U)) 
                                          | (0xfU & 
                                             ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                              >> 3U)));
        vlSelf->auto_in_d_bits_size = (7U & (IData)(
                                                    ((((QData)((IData)(
                                                                       (0xfU 
                                                                        & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_17__DOT__ram) 
                                                                           >> 8U)))) 
                                                       << 0x3cU) 
                                                      | (((QData)((IData)(
                                                                          (0xfU 
                                                                           & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_16__DOT__ram) 
                                                                              >> 8U)))) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             (0xfU 
                                                                              & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_15__DOT__ram) 
                                                                                >> 8U)))) 
                                                             << 0x34U) 
                                                            | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_14__DOT__ram) 
                                                                                >> 8U)))) 
                                                                << 0x30U) 
                                                               | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_13__DOT__ram) 
                                                                                >> 8U)))) 
                                                                   << 0x2cU) 
                                                                  | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_12__DOT__ram) 
                                                                                >> 8U)))) 
                                                                      << 0x28U) 
                                                                     | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_11__DOT__ram) 
                                                                                >> 8U)))) 
                                                                         << 0x24U) 
                                                                        | (((QData)((IData)(
                                                                                (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_10__DOT__ram) 
                                                                                >> 8U)))) 
                                                                            << 0x20U) 
                                                                           | (QData)((IData)(
                                                                                ((0xf0000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue1_BundleMap_9__DOT__ram) 
                                                                                << 0x14U)) 
                                                                                | ((0xf000000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_13__DOT___ram_ext_R0_data) 
                                                                                << 0x10U)) 
                                                                                | ((0xf00000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_12__DOT___ram_ext_R0_data) 
                                                                                << 0xcU)) 
                                                                                | ((0xf0000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_11__DOT___ram_ext_R0_data) 
                                                                                << 8U)) 
                                                                                | ((0xf000U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_10__DOT___ram_ext_R0_data) 
                                                                                << 4U)) 
                                                                                | ((0xf00U 
                                                                                & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_9__DOT___ram_ext_R0_data)) 
                                                                                | ((0xf0U 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_8__DOT___ram_ext_R0_data) 
                                                                                >> 4U)) 
                                                                                | (0xfU 
                                                                                & ((IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__PVT__Queue17_BundleMap_7__DOT___ram_ext_R0_data) 
                                                                                >> 8U))))))))))))))))))) 
                                                     >> 
                                                     (0x3cU 
                                                      & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                         >> 1U)))));
        vlSelf->auto_in_d_bits_source = (0x7fU & ((0x6fU 
                                                   >= 
                                                   (0x7fU 
                                                    & ((IData)(7U) 
                                                       * 
                                                       (0xfU 
                                                        & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                           >> 3U)))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * 
                                                         (0xfU 
                                                          & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                             >> 3U)))))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_h9c3ed76f__0[
                                                     (((IData)(6U) 
                                                       + 
                                                       (0x7fU 
                                                        & ((IData)(7U) 
                                                           * 
                                                           (0xfU 
                                                            & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                               >> 3U))))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0xfU 
                                                           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                              >> 3U))))))) 
                                                   | (__Vtemp_h9c3ed76f__0[
                                                      (3U 
                                                       & (((IData)(7U) 
                                                           * 
                                                           (0xfU 
                                                            & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                               >> 3U))) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          * 
                                                          (0xfU 
                                                           & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT___ram_ext_R0_data) 
                                                              >> 3U))))))
                                                   : 0U));
    }
    vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_size 
        = ((0U != (3U & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size) 
                         >> 1U))) ? 2U : (7U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size)));
    vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id 
        = ((0x27fU >= (0x3ffU & ((IData)(5U) * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source))))
            ? (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source))))
                          ? 0U : (VysyxSoCFull__ConstPool__CONST_h72c4c799_0[
                                  (((IData)(4U) + (0x3ffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source)))))) 
                        | (VysyxSoCFull__ConstPool__CONST_h72c4c799_0[
                           (0x1fU & (((IData)(5U) * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source)) 
                                     >> 5U))] >> (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source))))))
            : 0U);
    if (vlSelf->__PVT__queue_arw_deq_q__DOT__full) {
        vlSelf->auto_out_awecho_tl_state_size = (0xfU 
                                                 & (IData)(
                                                           (vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                            >> 8U)));
        vlSelf->auto_out_awlen = (0xffU & (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                   >> 0x11U)));
        vlSelf->auto_out_awaddr = (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                           >> 0x19U));
        vlSelf->auto_out_awecho_tl_state_source = (0x7fU 
                                                   & (IData)(
                                                             (vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                              >> 1U)));
        vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen 
            = (1U & (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__ram));
        vlSelf->auto_out_awsize = (7U & (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                 >> 0xeU)));
        vlSelf->auto_out_awid = (0x1fU & (IData)((vlSelf->__PVT__queue_arw_deq_q__DOT__ram 
                                                  >> 0x39U)));
    } else {
        vlSelf->auto_out_awecho_tl_state_size = (0xfU 
                                                 & (7U 
                                                    & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size)));
        vlSelf->auto_out_awlen = (0xffU & (~ (0x7fffU 
                                              & (((IData)(0x3ffU) 
                                                  << 
                                                  (7U 
                                                   & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size))) 
                                                 >> 2U))));
        vlSelf->auto_out_awaddr = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_address;
        vlSelf->auto_out_awecho_tl_state_source = (0x7fU 
                                                   & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source));
        vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen 
            = (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                        >> 2U)));
        vlSelf->auto_out_awsize = (7U & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_size));
        vlSelf->auto_out_awid = (0x1fU & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id));
    }
    vlSelf->__PVT__r_beats1 = ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))
                                ? 0U : (7U & (~ (0x3ffU 
                                                 & (((IData)(0x1fU) 
                                                     << 
                                                     (7U 
                                                      & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_size))) 
                                                    >> 2U)))));
    vlSelf->__PVT__idStall_4 = (((0U != (IData)(vlSelf->__PVT__count_4)) 
                                 & ((IData)(vlSelf->__PVT__write_4) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count_4)));
    vlSelf->__PVT__idStall_2 = (((0U != (IData)(vlSelf->__PVT__count_2)) 
                                 & ((IData)(vlSelf->__PVT__write_2) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count_2)));
    vlSelf->__PVT__idStall_0 = (((0U != (IData)(vlSelf->__PVT__count)) 
                                 & ((IData)(vlSelf->__PVT__write) 
                                    != (1U & (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                 >> 2U))))) 
                                | (0x10U == (IData)(vlSelf->__PVT__count)));
    vlSelf->__PVT__a_last = ((1U == (IData)(vlSelf->__PVT__r_counter)) 
                             | (0U == (IData)(vlSelf->__PVT__r_beats1)));
    if (vlSelf->__PVT__nodeOut_wdeq_q__DOT__full) {
        vlSelf->auto_out_wstrb = (0xfU & (IData)((vlSelf->__PVT__nodeOut_wdeq_q__DOT__ram 
                                                  >> 1U)));
        vlSelf->auto_out_wdata = (IData)((vlSelf->__PVT__nodeOut_wdeq_q__DOT__ram 
                                          >> 5U));
        vlSelf->auto_out_wlast = (1U & (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__ram));
    } else {
        vlSelf->auto_out_wstrb = (0xfU & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_mask));
        vlSelf->auto_out_wdata = vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_data;
        vlSelf->auto_out_wlast = (1U & (IData)(vlSelf->__PVT__a_last));
    }
    __Vtemp_h0f66af41__0[0U] = (IData)((((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                            << 0x3eU) 
                                           | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                     << 0x3bU) 
                                                    | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                        << 0x3aU) 
                                                       | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                              << 0x38U) 
                                                             | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                 << 0x37U) 
                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                    << 0x36U) 
                                                                   | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                       << 0x35U) 
                                                                      | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                          << 0x34U) 
                                                                         | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                             << 0x33U) 
                                                                            | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x32U) 
                                                                               | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_1)) 
                                                                                & ((IData)(vlSelf->__PVT__write_1) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_1)))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->__PVT__count_22) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->__PVT__count_21) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->__PVT__count_20) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__count_19) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__count_18) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->__PVT__count_17) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->__PVT__count_16) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->__PVT__count_15) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->__PVT__count_14) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->__PVT__count_13) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->__PVT__count_12) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->__PVT__count_11) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->__PVT__count_10) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->__PVT__count_9) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->__PVT__count_8) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->__PVT__count_7))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vtemp_h0f66af41__0[1U] = (IData)(((((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                          << 0x3fU) 
                                         | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                             << 0x3eU) 
                                            | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                << 0x3dU) 
                                               | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                   << 0x3cU) 
                                                  | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                      << 0x3bU) 
                                                     | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                         << 0x3aU) 
                                                        | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                            << 0x39U) 
                                                           | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                               << 0x38U) 
                                                              | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                  << 0x37U) 
                                                                 | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                     << 0x36U) 
                                                                    | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                        << 0x35U) 
                                                                       | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                           << 0x34U) 
                                                                          | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                              << 0x33U) 
                                                                             | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x32U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(vlSelf->__PVT__idStall_2)) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_1)) 
                                                                                & ((IData)(vlSelf->__PVT__write_1) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_1)))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1fU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1eU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1dU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1cU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x1aU) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->__PVT__idStall_0) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->__PVT__count_22) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->__PVT__count_21) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->__PVT__count_20) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__count_19) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__count_18) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->__PVT__count_17) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->__PVT__count_16) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->__PVT__count_15) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->__PVT__count_14) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->__PVT__count_13) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->__PVT__count_12) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->__PVT__count_11) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->__PVT__count_10) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->__PVT__count_9) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->__PVT__count_8) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->__PVT__count_7))))))))))))))))))))))))))))))))))))))))))))))))))) 
                                        >> 0x20U));
    __Vtemp_h97ba1eef__0[2U] = (((IData)(vlSelf->__PVT__idStall_4) 
                                 << 0x1aU) | (((IData)(vlSelf->__PVT__idStall_4) 
                                               << 0x19U) 
                                              | (((IData)(vlSelf->__PVT__idStall_4) 
                                                  << 0x18U) 
                                                 | (((IData)(vlSelf->__PVT__idStall_4) 
                                                     << 0x17U) 
                                                    | (((IData)(vlSelf->__PVT__idStall_4) 
                                                        << 0x16U) 
                                                       | (((IData)(vlSelf->__PVT__idStall_4) 
                                                           << 0x15U) 
                                                          | (((IData)(vlSelf->__PVT__idStall_4) 
                                                              << 0x14U) 
                                                             | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                 << 0x13U) 
                                                                | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                    << 0x12U) 
                                                                   | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                       << 0x11U) 
                                                                      | (((IData)(vlSelf->__PVT__idStall_4) 
                                                                          << 0x10U) 
                                                                         | (0xffffU 
                                                                            & (- (IData)(
                                                                                (((0U 
                                                                                != (IData)(vlSelf->__PVT__count_3)) 
                                                                                & ((IData)(vlSelf->__PVT__write_3) 
                                                                                != 
                                                                                (1U 
                                                                                & (~ 
                                                                                ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                                                >> 2U))))) 
                                                                                | (0x10U 
                                                                                == (IData)(vlSelf->__PVT__count_3)))))))))))))))));
    __PVT___GEN_0[0U] = __Vtemp_h0f66af41__0[0U];
    __PVT___GEN_0[1U] = __Vtemp_h0f66af41__0[1U];
    __PVT___GEN_0[2U] = (((IData)(vlSelf->__PVT__idStall_4) 
                          << 0x1fU) | (((IData)(vlSelf->__PVT__idStall_4) 
                                        << 0x1eU) | 
                                       (((IData)(vlSelf->__PVT__idStall_4) 
                                         << 0x1dU) 
                                        | (((IData)(vlSelf->__PVT__idStall_4) 
                                            << 0x1cU) 
                                           | (((IData)(vlSelf->__PVT__idStall_4) 
                                               << 0x1bU) 
                                              | __Vtemp_h97ba1eef__0[2U])))));
    __PVT___GEN_0[3U] = (((- (IData)((((0U != (IData)(vlSelf->__PVT__count_6)) 
                                       & ((IData)(vlSelf->__PVT__write_6) 
                                          != (1U & 
                                              (~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                  >> 2U))))) 
                                      | (0x10U == (IData)(vlSelf->__PVT__count_6))))) 
                          << 0x10U) | (0xffffU & (- (IData)(
                                                            (((0U 
                                                               != (IData)(vlSelf->__PVT__count_5)) 
                                                              & ((IData)(vlSelf->__PVT__write_5) 
                                                                 != 
                                                                 (1U 
                                                                  & (~ 
                                                                     ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                                      >> 2U))))) 
                                                             | (0x10U 
                                                                == (IData)(vlSelf->__PVT__count_5)))))));
    vlSelf->__PVT__stall = ((__PVT___GEN_0[((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source) 
                                            >> 5U)] 
                             >> (0x1fU & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_source))) 
                            & (0U == (IData)(vlSelf->__PVT__r_counter)));
    __VdfgTmp_hbcc272f1__0 = ((~ (IData)(vlSelf->__PVT__stall)) 
                              & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid));
    vlSelf->auto_in_a_ready = (1U & ((~ (IData)(vlSelf->__PVT__stall)) 
                                     & ((4U & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode))
                                         ? (~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full))
                                         : ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                            & (IData)(vlSelf->__PVT___out_wvalid_T_3)))));
    vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid 
        = ((IData)(__VdfgTmp_hbcc272f1__0) & ((~ ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                                  >> 2U)) 
                                              & (IData)(vlSelf->__PVT___out_wvalid_T_3)));
    vlSelf->__PVT__out_arw_valid = ((IData)(__VdfgTmp_hbcc272f1__0) 
                                    & (((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___atomics_auto_out_a_bits_opcode) 
                                        >> 2U) | ((~ (IData)(vlSelf->__PVT__doneAW)) 
                                                  & (~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)))));
    vlSelf->__PVT__monitor__DOT___a_first_T_1 = ((IData)(vlSelf->auto_in_a_ready) 
                                                 & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_a_valid));
    vlSelf->__PVT__nodeOut_wdeq_q__DOT__do_enq = ((~ 
                                                   ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                                    & (~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__in_wdeq_q__DOT__full)))) 
                                                  & ((~ (IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full)) 
                                                     & (IData)(vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid)));
    vlSelf->auto_out_wvalid = ((IData)(vlSelf->__PVT__nodeOut_wdeq_q__DOT__full) 
                               | (IData)(vlSelf->__Vcellinp__nodeOut_wdeq_q__io_enq_valid));
    vlSelf->__PVT___inc_T_22 = ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                & (IData)(vlSelf->__PVT__out_arw_valid));
    vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0 
        = ((IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full) 
           | (IData)(vlSelf->__PVT__out_arw_valid));
    vlSelf->__PVT__monitor__DOT___GEN_1 = ((IData)(vlSelf->__PVT__monitor__DOT___a_first_T_1) 
                                           & (0U == (IData)(vlSelf->__PVT__monitor__DOT__a_first_counter_1)));
    vlSelf->__PVT__inc = (((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                          & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_1 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 1U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_2 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 2U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_3 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 3U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_4 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 4U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_5 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 5U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->__PVT__inc_6 = ((((IData)(1U) << (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_enq_bits_id)) 
                             >> 6U) & (IData)(vlSelf->__PVT___inc_T_22));
    vlSelf->auto_out_arvalid = ((~ (IData)(vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen)) 
                                & (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0));
    vlSelf->auto_out_awvalid = ((IData)(vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen) 
                                & (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__io_deq_valid_0));
}

VL_ATTR_COLD void VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__2(VysyxSoCFull_TLToAXI4* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VysyxSoCFull_TLToAXI4___stl_sequent__TOP__ysyxSoCFull__DOT__fpga__DOT__tl2axi4__2\n"); );
    // Body
    vlSelf->__VdfgTmp_hc0989b25__0 = (((~ (IData)(vlSelf->__PVT__r_wins)) 
                                       | (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT___axi4frag_auto_in_rlast)) 
                                      & ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_d_ready) 
                                         & (IData)(vlSelf->auto_in_d_valid)));
    vlSelf->auto_out_rready = ((IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_d_ready) 
                               & (IData)(vlSelf->__PVT__r_wins));
    vlSelf->auto_out_bready = ((~ (IData)(vlSelf->__PVT__r_wins)) 
                               & (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__fpga__DOT___xbar_auto_anon_out_0_d_ready));
    vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready 
        = ((IData)(vlSelf->__PVT___queue_arw_deq_q_io_deq_bits_wen)
            ? ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__deq_q_1__DOT__full)) 
               & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__VdfgTmp_h3deb4dd1__0))
            : ((~ (IData)(vlSymsp->TOP.ysyxSoCFull__DOT__mem__DOT__axi4frag__DOT__deq_q__DOT__full)) 
               & (IData)(vlSymsp->TOP__ysyxSoCFull__DOT__fpga__DOT__axi4yank.__VdfgTmp_h6bd82316__0)));
    vlSelf->__PVT__queue_arw_deq_q__DOT__do_enq = (
                                                   (~ 
                                                    ((~ (IData)(vlSelf->__PVT__queue_arw_deq_q__DOT__full)) 
                                                     & (IData)(vlSelf->__Vcellinp__queue_arw_deq_q__io_deq_ready))) 
                                                   & (IData)(vlSelf->__PVT___inc_T_22));
}
