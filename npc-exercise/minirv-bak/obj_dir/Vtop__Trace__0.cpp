// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [3U])))) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__top.PC_command),32);
        bufp->chgBit(oldp+1,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isADD));
        bufp->chgBit(oldp+2,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isI));
        bufp->chgBit(oldp+3,((0x37U == (0x0000007fU 
                                        & vlSymsp->TOP__top.PC_command))));
        bufp->chgCData(oldp+4,((0x0000001fU & (vlSymsp->TOP__top.PC_command 
                                               >> 7U))),5);
        bufp->chgCData(oldp+5,((0x0000001fU & (vlSymsp->TOP__top.PC_command 
                                               >> 0x0000000fU))),5);
        bufp->chgCData(oldp+6,((0x0000001fU & (vlSymsp->TOP__top.PC_command 
                                               >> 0x00000014U))),5);
        bufp->chgIData(oldp+7,(vlSymsp->TOP__top.__PVT__rs1_val),32);
        bufp->chgBit(oldp+8,(((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLOAD) 
                              | (IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isWRITE))));
        bufp->chgBit(oldp+9,((0x00100073U == vlSymsp->TOP__top.PC_command)));
        bufp->chgBit(oldp+10,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLOAD));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isWRITE));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isJALR));
        bufp->chgBit(oldp+13,((1U & (~ (IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLBU)))));
        bufp->chgCData(oldp+14,((0x0000007fU & vlSymsp->TOP__top.PC_command)),7);
        bufp->chgCData(oldp+15,((7U & (vlSymsp->TOP__top.PC_command 
                                       >> 0x0000000cU))),3);
        bufp->chgCData(oldp+16,((vlSymsp->TOP__top.PC_command 
                                 >> 0x00000019U)),7);
        bufp->chgSData(oldp+17,((vlSymsp->TOP__top.PC_command 
                                 >> 0x00000014U)),12);
        bufp->chgSData(oldp+18,(((0x00000fe0U & (vlSymsp->TOP__top.PC_command 
                                                 >> 0x00000014U)) 
                                 | (0x0000001fU & (vlSymsp->TOP__top.PC_command 
                                                   >> 7U)))),12);
        bufp->chgSData(oldp+19,(((((2U & (vlSymsp->TOP__top.PC_command 
                                          >> 0x0000001eU)) 
                                   | (1U & (vlSymsp->TOP__top.PC_command 
                                            >> 7U))) 
                                  << 0x0000000aU) | 
                                 ((0x000003f0U & (vlSymsp->TOP__top.PC_command 
                                                  >> 0x00000015U)) 
                                  | (0x0000000fU & 
                                     (vlSymsp->TOP__top.PC_command 
                                      >> 8U))))),12);
        bufp->chgIData(oldp+20,((vlSymsp->TOP__top.PC_command 
                                 >> 0x0000000cU)),20);
        bufp->chgIData(oldp+21,(((0x00080000U & (vlSymsp->TOP__top.PC_command 
                                                 >> 0x0000000cU)) 
                                 | ((0x0007f800U & 
                                     (vlSymsp->TOP__top.PC_command 
                                      >> 1U)) | ((0x00000400U 
                                                  & (vlSymsp->TOP__top.PC_command 
                                                     >> 0x0000000aU)) 
                                                 | (0x000003ffU 
                                                    & (vlSymsp->TOP__top.PC_command 
                                                       >> 0x00000015U)))))),20);
        bufp->chgBit(oldp+22,((IData)((0x00000013U 
                                       == (0x0000707fU 
                                           & vlSymsp->TOP__top.PC_command)))));
        bufp->chgBit(oldp+23,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLW));
        bufp->chgBit(oldp+24,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLBU));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLB));
        bufp->chgBit(oldp+26,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isSW));
        bufp->chgBit(oldp+27,(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isSB));
        bufp->chgIData(oldp+28,(vlSymsp->TOP__top.__PVT__LSU_0__DOT__val0),32);
        bufp->chgIData(oldp+29,(vlSymsp->TOP__top.__PVT__LSU_0__DOT__val1),32);
        bufp->chgIData(oldp+30,(vlSymsp->TOP__top.__PVT__LSU_0__DOT__val2),32);
        bufp->chgIData(oldp+31,((((- (IData)((vlSymsp->TOP__top.__PVT__LSU_0__DOT__val0 
                                              >> 0x0000001fU))) 
                                  << 0x00000018U) | 
                                 (vlSymsp->TOP__top.__PVT__LSU_0__DOT__val2 
                                  >> 8U))),32);
        bufp->chgIData(oldp+32,(((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLBU)
                                  ? (0x000000ffU & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)
                                  : (((- (IData)((1U 
                                                  & (vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4 
                                                     >> 7U)))) 
                                      << 8U) | (0x000000ffU 
                                                & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)))),32);
        bufp->chgIData(oldp+33,(((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLBU)
                                  ? (0x0000ffffU & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)
                                  : (((- (IData)((1U 
                                                  & (vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4 
                                                     >> 0x0000000fU)))) 
                                      << 0x00000010U) 
                                     | (0x0000ffffU 
                                        & vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4)))),32);
        bufp->chgIData(oldp+34,(vlSymsp->TOP__top.__PVT__LSU_0__DOT__rdata4),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+35,((1U & (IData)(vlSymsp->TOP__top.__PVT__clkdiv_0__DOT__cnt))));
        bufp->chgBit(oldp+36,((1U & ((IData)(vlSymsp->TOP__top.__PVT__clkdiv_0__DOT__cnt) 
                                     >> 1U))));
        bufp->chgBit(oldp+37,((1U & ((IData)(vlSymsp->TOP__top.__PVT__clkdiv_0__DOT__cnt) 
                                     >> 2U))));
        bufp->chgCData(oldp+38,(vlSymsp->TOP__top.__PVT__clkdiv_0__DOT__cnt),3);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__top__GPR_0.__PVT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+40,(vlSelfRef.clk));
    bufp->chgBit(oldp+41,(vlSelfRef.rst));
    bufp->chgIData(oldp+42,(vlSelfRef.LSU_address),32);
    bufp->chgCData(oldp+43,(vlSelfRef.LSU_rmask),4);
    bufp->chgCData(oldp+44,(vlSelfRef.LSU_wmask),4);
    bufp->chgIData(oldp+45,(vlSelfRef.LSU_writedata),32);
    bufp->chgBit(oldp+46,(vlSelfRef.LSU_WEN));
    bufp->chgBit(oldp+47,(vlSelfRef.LSU_REN));
    bufp->chgIData(oldp+48,(vlSelfRef.LSU_readdata),32);
    bufp->chgIData(oldp+49,(vlSelfRef.PC_command),32);
    bufp->chgIData(oldp+50,(vlSelfRef.EXU_inA),32);
    bufp->chgIData(oldp+51,(vlSelfRef.EXU_inB),32);
    bufp->chgIData(oldp+52,(vlSelfRef.EXU_data),32);
    bufp->chgIData(oldp+53,(vlSymsp->TOP__top.PC),32);
    bufp->chgIData(oldp+54,(vlSymsp->TOP__top.dnpc),32);
    bufp->chgIData(oldp+55,(vlSymsp->TOP__top.snpc),32);
    bufp->chgIData(oldp+56,(((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isI)
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
                                   : 0U)))),32);
    bufp->chgIData(oldp+57,(((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLOAD)
                              ? vlSelfRef.LSU_readdata
                              : ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isJALR)
                                  ? vlSymsp->TOP__top.snpc
                                  : ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isWRITE)
                                      ? vlSelfRef.LSU_address
                                      : 0xf0f0f0f0U)))),32);
    bufp->chgSData(oldp+58,((((IData)(vlSymsp->TOP__top.IDU_0__DOT____VdfgRegularize_h52656aab_0_5) 
                              | ((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isLW) 
                                 | ((IData)(vlSymsp->TOP__top.IDU_0__DOT____VdfgRegularize_h52656aab_0_6) 
                                    | (IData)(vlSelfRef.LSU_WEN)))) 
                             << 9U)),10);
    bufp->chgIData(oldp+59,((vlSelfRef.EXU_inA + vlSelfRef.EXU_inB)),32);
    bufp->chgCData(oldp+60,((((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isADD) 
                              << 5U) | (((IData)(vlSymsp->TOP__top.__PVT__IDU_0__DOT__isI) 
                                         << 4U) | (
                                                   ((IData)(vlSelfRef.LSU_WEN) 
                                                    << 3U) 
                                                   | ((0x37U 
                                                       == 
                                                       (0x0000007fU 
                                                        & vlSymsp->TOP__top.PC_command)) 
                                                      << 1U))))),6);
    bufp->chgIData(oldp+61,(VL_SHIFTL_III(32,32,32, vlSelfRef.LSU_writedata, 8U)),32);
    bufp->chgIData(oldp+62,(VL_SHIFTL_III(32,32,32, vlSelfRef.LSU_writedata, 0x00000010U)),32);
    bufp->chgIData(oldp+63,(VL_SHIFTL_III(32,32,32, vlSelfRef.LSU_writedata, 0x00000018U)),32);
    bufp->chgIData(oldp+64,(((2U & vlSelfRef.LSU_address)
                              ? ((1U & vlSelfRef.LSU_address)
                                  ? VL_SHIFTL_III(32,32,32, vlSelfRef.LSU_writedata, 0x00000018U)
                                  : VL_SHIFTL_III(32,32,32, vlSelfRef.LSU_writedata, 0x00000010U))
                              : ((1U & vlSelfRef.LSU_address)
                                  ? VL_SHIFTL_III(32,32,32, vlSelfRef.LSU_writedata, 8U)
                                  : vlSelfRef.LSU_writedata))),32);
    bufp->chgIData(oldp+65,(vlSymsp->TOP__top__GPR_0.GPR[0]),32);
    bufp->chgIData(oldp+66,(vlSymsp->TOP__top__GPR_0.GPR[1]),32);
    bufp->chgIData(oldp+67,(vlSymsp->TOP__top__GPR_0.GPR[2]),32);
    bufp->chgIData(oldp+68,(vlSymsp->TOP__top__GPR_0.GPR[3]),32);
    bufp->chgIData(oldp+69,(vlSymsp->TOP__top__GPR_0.GPR[4]),32);
    bufp->chgIData(oldp+70,(vlSymsp->TOP__top__GPR_0.GPR[5]),32);
    bufp->chgIData(oldp+71,(vlSymsp->TOP__top__GPR_0.GPR[6]),32);
    bufp->chgIData(oldp+72,(vlSymsp->TOP__top__GPR_0.GPR[7]),32);
    bufp->chgIData(oldp+73,(vlSymsp->TOP__top__GPR_0.GPR[8]),32);
    bufp->chgIData(oldp+74,(vlSymsp->TOP__top__GPR_0.GPR[9]),32);
    bufp->chgIData(oldp+75,(vlSymsp->TOP__top__GPR_0.GPR[10]),32);
    bufp->chgIData(oldp+76,(vlSymsp->TOP__top__GPR_0.GPR[11]),32);
    bufp->chgIData(oldp+77,(vlSymsp->TOP__top__GPR_0.GPR[12]),32);
    bufp->chgIData(oldp+78,(vlSymsp->TOP__top__GPR_0.GPR[13]),32);
    bufp->chgIData(oldp+79,(vlSymsp->TOP__top__GPR_0.GPR[14]),32);
    bufp->chgIData(oldp+80,(vlSymsp->TOP__top__GPR_0.GPR[15]),32);
    bufp->chgIData(oldp+81,(vlSymsp->TOP__top__GPR_0.GPR[16]),32);
    bufp->chgIData(oldp+82,(vlSymsp->TOP__top__GPR_0.GPR[17]),32);
    bufp->chgIData(oldp+83,(vlSymsp->TOP__top__GPR_0.GPR[18]),32);
    bufp->chgIData(oldp+84,(vlSymsp->TOP__top__GPR_0.GPR[19]),32);
    bufp->chgIData(oldp+85,(vlSymsp->TOP__top__GPR_0.GPR[20]),32);
    bufp->chgIData(oldp+86,(vlSymsp->TOP__top__GPR_0.GPR[21]),32);
    bufp->chgIData(oldp+87,(vlSymsp->TOP__top__GPR_0.GPR[22]),32);
    bufp->chgIData(oldp+88,(vlSymsp->TOP__top__GPR_0.GPR[23]),32);
    bufp->chgIData(oldp+89,(vlSymsp->TOP__top__GPR_0.GPR[24]),32);
    bufp->chgIData(oldp+90,(vlSymsp->TOP__top__GPR_0.GPR[25]),32);
    bufp->chgIData(oldp+91,(vlSymsp->TOP__top__GPR_0.GPR[26]),32);
    bufp->chgIData(oldp+92,(vlSymsp->TOP__top__GPR_0.GPR[27]),32);
    bufp->chgIData(oldp+93,(vlSymsp->TOP__top__GPR_0.GPR[28]),32);
    bufp->chgIData(oldp+94,(vlSymsp->TOP__top__GPR_0.GPR[29]),32);
    bufp->chgIData(oldp+95,(vlSymsp->TOP__top__GPR_0.GPR[30]),32);
    bufp->chgIData(oldp+96,(vlSymsp->TOP__top__GPR_0.GPR[31]),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
