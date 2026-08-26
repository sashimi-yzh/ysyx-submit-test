// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);

void Vtop_top___ico_sequent__TOP__top__0(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ico_sequent__TOP__top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.snpc = ((IData)(4U) + vlSelfRef.PC);
    if (vlSymsp->TOP.rst) {
        vlSelfRef.PC_command = 0U;
    } else {
        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.PC, vlSelfRef.__Vfunc_pmem_read__1__Vfuncout);
        vlSelfRef.PC_command = vlSelfRef.__Vfunc_pmem_read__1__Vfuncout;
    }
    vlSelfRef.__PVT__IDU_0__DOT__isADD = (IData)((0x00000033U 
                                                  == 
                                                  (0xfe00707fU 
                                                   & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__rs1_val = ((0U == (0x0000001fU 
                                        & (vlSelfRef.PC_command 
                                           >> 0x0000000fU)))
                                 ? 0U : vlSymsp->TOP__top__GPR_0.GPR
                                [(0x0000001fU & (vlSelfRef.PC_command 
                                                 >> 0x0000000fU))]);
    vlSelfRef.__PVT__IDU_0__DOT__isSW = (IData)((0x00002023U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isSB = (IData)((0x00000023U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isJALR = (IData)((0x00000067U 
                                                   == 
                                                   (0x0000707fU 
                                                    & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isLW = (IData)((0x00002003U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isLB = (IData)((3U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isLBU = (IData)((0x00004003U 
                                                  == 
                                                  (0x0000707fU 
                                                   & vlSelfRef.PC_command)));
    vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_4 
        = ((IData)((0x00000013U == (0x0000707fU & vlSelfRef.PC_command))) 
           | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isJALR));
    vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_6 
        = ((IData)(vlSelfRef.__PVT__IDU_0__DOT__isLBU) 
           | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isLB));
    vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_5 
        = ((IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_4) 
           | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isADD));
    vlSelfRef.__PVT__IDU_0__DOT__isLOAD = ((IData)(vlSelfRef.__PVT__IDU_0__DOT__isLW) 
                                           | (IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_6));
    vlSelfRef.__PVT__IDU_0__DOT__isWRITE = ((IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_5) 
                                            | (0x37U 
                                               == (0x0000007fU 
                                                   & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isI = ((IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_4) 
                                        | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isLOAD));
}

void Vtop_top___ico_sequent__TOP__top__1(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ico_sequent__TOP__top__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdfgRegularize_he2b63832_0_0 = ((IData)(vlSelfRef.__PVT__IDU_0__DOT__isI) 
                                                | ((0x37U 
                                                    == 
                                                    (0x0000007fU 
                                                     & vlSelfRef.PC_command)) 
                                                   | (IData)(vlSymsp->TOP.LSU_WEN)));
}

void Vtop_top___ico_sequent__TOP__top__2(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ico_sequent__TOP__top__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dnpc = vlSymsp->TOP.LSU_address;
    vlSelfRef.__PVT__LSU_0__DOT__val0 = ((IData)(vlSymsp->TOP.LSU_REN)
                                          ? ([&]() {
                Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSymsp->TOP.LSU_address, vlSelfRef.__Vfunc_pmem_read__2__Vfuncout);
            }(), vlSelfRef.__Vfunc_pmem_read__2__Vfuncout)
                                          : 0U);
    vlSelfRef.__PVT__LSU_0__DOT__val1 = (((- (IData)(
                                                     (vlSelfRef.__PVT__LSU_0__DOT__val0 
                                                      >> 0x0000001fU))) 
                                          << 0x00000018U) 
                                         | (vlSelfRef.__PVT__LSU_0__DOT__val0 
                                            >> 8U));
    vlSelfRef.__PVT__LSU_0__DOT__val2 = (((- (IData)(
                                                     (vlSelfRef.__PVT__LSU_0__DOT__val0 
                                                      >> 0x0000001fU))) 
                                          << 0x00000018U) 
                                         | (vlSelfRef.__PVT__LSU_0__DOT__val1 
                                            >> 8U));
    vlSelfRef.__PVT__LSU_0__DOT__rdata4 = ((2U & vlSymsp->TOP.LSU_address)
                                            ? ((1U 
                                                & vlSymsp->TOP.LSU_address)
                                                ? (
                                                   ((- (IData)(
                                                               (vlSelfRef.__PVT__LSU_0__DOT__val0 
                                                                >> 0x0000001fU))) 
                                                    << 0x00000018U) 
                                                   | (vlSelfRef.__PVT__LSU_0__DOT__val2 
                                                      >> 8U))
                                                : vlSelfRef.__PVT__LSU_0__DOT__val2)
                                            : ((1U 
                                                & vlSymsp->TOP.LSU_address)
                                                ? vlSelfRef.__PVT__LSU_0__DOT__val1
                                                : vlSelfRef.__PVT__LSU_0__DOT__val0));
}

void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.rst) {
        vlSelfRef.__PVT__clkdiv_0__DOT__cnt = 1U;
        vlSelfRef.PC = 0x80000000U;
    } else {
        vlSelfRef.__PVT__clkdiv_0__DOT__cnt = ((6U 
                                                & ((IData)(vlSelfRef.__PVT__clkdiv_0__DOT__cnt) 
                                                   << 1U)) 
                                               | (1U 
                                                  & ((IData)(vlSelfRef.__PVT__clkdiv_0__DOT__cnt) 
                                                     >> 2U)));
        vlSelfRef.PC = ((IData)(vlSelfRef.__PVT__IDU_0__DOT__isJALR)
                         ? vlSelfRef.dnpc : vlSelfRef.snpc);
    }
}

void Vtop_top___nba_sequent__TOP__top__1(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.snpc = ((IData)(4U) + vlSelfRef.PC);
}

void Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vtop___024unit____Vdpiimwrap_ebreak_TOP____024unit();

void Vtop_top___nba_sequent__TOP__top__2(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.LSU_WEN) {
        Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(vlSymsp->TOP.LSU_address, 
                                                               ((2U 
                                                                 & vlSymsp->TOP.LSU_address)
                                                                 ? 
                                                                ((1U 
                                                                  & vlSymsp->TOP.LSU_address)
                                                                  ? 
                                                                 VL_SHIFTL_III(32,32,32, vlSymsp->TOP.LSU_writedata, 0x00000018U)
                                                                  : 
                                                                 VL_SHIFTL_III(32,32,32, vlSymsp->TOP.LSU_writedata, 0x00000010U))
                                                                 : 
                                                                ((1U 
                                                                  & vlSymsp->TOP.LSU_address)
                                                                  ? 
                                                                 VL_SHIFTL_III(32,32,32, vlSymsp->TOP.LSU_writedata, 8U)
                                                                  : vlSymsp->TOP.LSU_writedata)), (IData)(vlSymsp->TOP.LSU_wmask));
    }
    if ((0x00100073U == vlSelfRef.PC_command)) {
        Vtop___024unit____Vdpiimwrap_ebreak_TOP____024unit();
    }
}

void Vtop_top___nba_sequent__TOP__top__3(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.rst) {
        vlSelfRef.PC_command = 0U;
    } else {
        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.PC, vlSelfRef.__Vfunc_pmem_read__1__Vfuncout);
        vlSelfRef.PC_command = vlSelfRef.__Vfunc_pmem_read__1__Vfuncout;
    }
    vlSelfRef.__PVT__IDU_0__DOT__isADD = (IData)((0x00000033U 
                                                  == 
                                                  (0xfe00707fU 
                                                   & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__rs1_val = ((0U == (0x0000001fU 
                                        & (vlSelfRef.PC_command 
                                           >> 0x0000000fU)))
                                 ? 0U : vlSymsp->TOP__top__GPR_0.GPR
                                [(0x0000001fU & (vlSelfRef.PC_command 
                                                 >> 0x0000000fU))]);
    vlSelfRef.__PVT__IDU_0__DOT__isSW = (IData)((0x00002023U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isSB = (IData)((0x00000023U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isJALR = (IData)((0x00000067U 
                                                   == 
                                                   (0x0000707fU 
                                                    & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isLW = (IData)((0x00002003U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isLB = (IData)((3U 
                                                 == 
                                                 (0x0000707fU 
                                                  & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isLBU = (IData)((0x00004003U 
                                                  == 
                                                  (0x0000707fU 
                                                   & vlSelfRef.PC_command)));
    vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_4 
        = ((IData)((0x00000013U == (0x0000707fU & vlSelfRef.PC_command))) 
           | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isJALR));
    vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_6 
        = ((IData)(vlSelfRef.__PVT__IDU_0__DOT__isLBU) 
           | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isLB));
    vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_5 
        = ((IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_4) 
           | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isADD));
    vlSelfRef.__PVT__IDU_0__DOT__isLOAD = ((IData)(vlSelfRef.__PVT__IDU_0__DOT__isLW) 
                                           | (IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_6));
    vlSelfRef.__PVT__IDU_0__DOT__isWRITE = ((IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_5) 
                                            | (0x37U 
                                               == (0x0000007fU 
                                                   & vlSelfRef.PC_command)));
    vlSelfRef.__PVT__IDU_0__DOT__isI = ((IData)(vlSelfRef.IDU_0__DOT____VdfgRegularize_h52656aab_0_4) 
                                        | (IData)(vlSelfRef.__PVT__IDU_0__DOT__isLOAD));
}
