// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpu__Syms.h"


void Vfpu___024root__trace_chg_sub_0(Vfpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);
void Vfpu___024root__trace_chg_sub_1(Vfpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);
void Vfpu___024root__trace_chg_sub_2(Vfpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root__trace_chg_top_0\n"); );
    // Init
    Vfpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpu___024root*>(voidSelf);
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfpu___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
    Vfpu___024root__trace_chg_sub_1((&vlSymsp->TOP), bufp);
    Vfpu___024root__trace_chg_sub_2((&vlSymsp->TOP), bufp);
}

void Vfpu___024root__trace_chg_sub_0(Vfpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpu___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3a1a__0;
    VlWide<3>/*95:0*/ __Vtemp_h2965bfe5__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3b9c__0;
    VlWide<3>/*95:0*/ __Vtemp_h6fa02d4c__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3723__0;
    VlWide<3>/*95:0*/ __Vtemp_h8c3432ba__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3ca1__0;
    VlWide<3>/*95:0*/ __Vtemp_h58f4b9f5__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3c20__0;
    VlWide<3>/*95:0*/ __Vtemp_hbe8f3385__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3d9e__0;
    VlWide<3>/*95:0*/ __Vtemp_h3d123818__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed6259__0;
    VlWide<3>/*95:0*/ __Vtemp_h99778e24__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed4e03__0;
    VlWide<3>/*95:0*/ __Vtemp_ha2d3c6e0__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed4f7e__0;
    VlWide<3>/*95:0*/ __Vtemp_h7386d19a__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed4f00__0;
    VlWide<3>/*95:0*/ __Vtemp_hc8242373__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed6c7f__0;
    VlWide<3>/*95:0*/ __Vtemp_h20360ba8__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed6ffd__0;
    VlWide<3>/*95:0*/ __Vtemp_hb72b3b5a__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed7184__0;
    VlWide<3>/*95:0*/ __Vtemp_h5d050081__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed7102__0;
    VlWide<3>/*95:0*/ __Vtemp_h146180b1__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3d35__0;
    VlWide<3>/*95:0*/ __Vtemp_h49015499__0;
    VlWide<3>/*95:0*/ __Vtemp_hc0ed3ab7__0;
    VlWide<3>/*95:0*/ __Vtemp_h6964d4eb__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_nan1));
        bufp->chgBit(oldp+1,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_nan2));
        bufp->chgBit(oldp+2,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_snan1));
        bufp->chgBit(oldp+3,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_snan2));
        bufp->chgBit(oldp+4,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_inf1));
        bufp->chgBit(oldp+5,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_inf2));
        bufp->chgBit(oldp+6,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_zero1));
        bufp->chgBit(oldp+7,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_zero2));
        bufp->chgBit(oldp+8,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_denorm1));
        bufp->chgBit(oldp+9,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__is_denorm2));
        bufp->chgIData(oldp+10,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mant1),24);
        bufp->chgIData(oldp+11,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mant2),24);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+12,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__next_state),2);
        bufp->chgBit(oldp+13,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__next_fpu_ready));
        bufp->chgIData(oldp+14,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__comb_result),32);
        bufp->chgIData(oldp+15,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__comb_int_result),32);
        bufp->chgCData(oldp+16,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__comb_exception),5);
        bufp->chgSData(oldp+17,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__shift_amt),9);
        bufp->chgSData(oldp+18,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__lzc),9);
        bufp->chgIData(oldp+19,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mant_for_round),27);
        bufp->chgSData(oldp+20,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__true_exp1),9);
        bufp->chgSData(oldp+21,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__true_exp2),9);
        bufp->chgSData(oldp+22,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__max_exp),9);
        bufp->chgIData(oldp+23,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__norm_mant1),24);
        bufp->chgIData(oldp+24,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__norm_mant2),24);
        bufp->chgSData(oldp+25,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__lead_zeros1),9);
        bufp->chgSData(oldp+26,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__lead_zeros2),9);
        bufp->chgIData(oldp+27,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__shifted_mant1),28);
        bufp->chgIData(oldp+28,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__shifted_mant2),28);
        bufp->chgIData(oldp+29,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__sum_mant),29);
        bufp->chgSData(oldp+30,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__result_exp),9);
        bufp->chgBit(oldp+31,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__result_sign));
        bufp->chgBit(oldp+32,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__guard));
        bufp->chgBit(oldp+33,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__round));
        bufp->chgBit(oldp+34,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__sticky));
        bufp->chgQData(oldp+35,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__prod_mant),48);
        bufp->chgBit(oldp+37,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__sign2_eff));
        bufp->chgIData(oldp+38,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_rounded_mant),27);
        bufp->chgSData(oldp+39,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_rounded_exp),9);
        bufp->chgBit(oldp+40,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_guard));
        bufp->chgBit(oldp+41,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_round));
        bufp->chgBit(oldp+42,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_lsb));
        bufp->chgBit(oldp+43,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_round_up));
        bufp->chgIData(oldp+44,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_denorm_mant),23);
        bufp->chgSData(oldp+45,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__l_shift_amt),9);
        bufp->chgIData(oldp+46,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant1),32);
        bufp->chgIData(oldp+47,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2),32);
        bufp->chgWData(oldp+48,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext),68);
        bufp->chgQData(oldp+51,((((QData)((IData)((3U 
                                                   & (- (IData)(
                                                                (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                                                 >> 0x1fU)))))) 
                                  << 0x21U) | ((QData)((IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)) 
                                               << 1U))),35);
        bufp->chgWData(oldp+53,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[0]),68);
        bufp->chgWData(oldp+56,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[1]),68);
        bufp->chgWData(oldp+59,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[2]),68);
        bufp->chgWData(oldp+62,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[3]),68);
        bufp->chgWData(oldp+65,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[4]),68);
        bufp->chgWData(oldp+68,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[5]),68);
        bufp->chgWData(oldp+71,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[6]),68);
        bufp->chgWData(oldp+74,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[7]),68);
        bufp->chgWData(oldp+77,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[8]),68);
        bufp->chgWData(oldp+80,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[9]),68);
        bufp->chgWData(oldp+83,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[10]),68);
        bufp->chgWData(oldp+86,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[11]),68);
        bufp->chgWData(oldp+89,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[12]),68);
        bufp->chgWData(oldp+92,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[13]),68);
        bufp->chgWData(oldp+95,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[14]),68);
        bufp->chgWData(oldp+98,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[15]),68);
        bufp->chgWData(oldp+101,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__partial_products[16]),68);
        bufp->chgWData(oldp+104,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__cout2),68);
        bufp->chgWData(oldp+107,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__s),68);
        bufp->chgCData(oldp+110,((6U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        << 1U))),3);
        bufp->chgBit(oldp+111,((IData)((3U == (3U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgBit(oldp+112,((IData)((2U == (3U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgBit(oldp+113,((IData)((1U == (3U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+114,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0x13U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3a1a__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x14U);
        __Vtemp_h2965bfe5__0[0U] = __Vtemp_hc0ed3a1a__0[0U];
        __Vtemp_h2965bfe5__0[1U] = __Vtemp_hc0ed3a1a__0[1U];
        __Vtemp_h2965bfe5__0[2U] = (0xfU & __Vtemp_hc0ed3a1a__0[2U]);
        bufp->chgWData(oldp+115,(__Vtemp_h2965bfe5__0),68);
        bufp->chgBit(oldp+118,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x15U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h8cb8ba8a__0))));
        bufp->chgBit(oldp+119,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x180000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0x15U)))));
        bufp->chgBit(oldp+120,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x15U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h8cb8ba8a__0))));
        bufp->chgBit(oldp+121,((IData)((0x180000U == 
                                        (0x380000U 
                                         & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+122,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0x15U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3b9c__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x16U);
        __Vtemp_h6fa02d4c__0[0U] = __Vtemp_hc0ed3b9c__0[0U];
        __Vtemp_h6fa02d4c__0[1U] = __Vtemp_hc0ed3b9c__0[1U];
        __Vtemp_h6fa02d4c__0[2U] = (0xfU & __Vtemp_hc0ed3b9c__0[2U]);
        bufp->chgWData(oldp+123,(__Vtemp_h6fa02d4c__0),68);
        bufp->chgBit(oldp+126,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x17U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc18fac15__0))));
        bufp->chgBit(oldp+127,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x600000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0x17U)))));
        bufp->chgBit(oldp+128,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x17U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc18fac15__0))));
        bufp->chgBit(oldp+129,((IData)((0x600000U == 
                                        (0xe00000U 
                                         & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+130,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0x17U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3723__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x18U);
        __Vtemp_h8c3432ba__0[0U] = __Vtemp_hc0ed3723__0[0U];
        __Vtemp_h8c3432ba__0[1U] = __Vtemp_hc0ed3723__0[1U];
        __Vtemp_h8c3432ba__0[2U] = (0xfU & __Vtemp_hc0ed3723__0[2U]);
        bufp->chgWData(oldp+131,(__Vtemp_h8c3432ba__0),68);
        bufp->chgBit(oldp+134,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x19U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc411b621__0))));
        bufp->chgBit(oldp+135,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x1800000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0x19U)))));
        bufp->chgBit(oldp+136,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x19U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc411b621__0))));
        bufp->chgBit(oldp+137,((IData)((0x1800000U 
                                        == (0x3800000U 
                                            & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+138,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0x19U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3ca1__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x1aU);
        __Vtemp_h58f4b9f5__0[0U] = __Vtemp_hc0ed3ca1__0[0U];
        __Vtemp_h58f4b9f5__0[1U] = __Vtemp_hc0ed3ca1__0[1U];
        __Vtemp_h58f4b9f5__0[2U] = (0xfU & __Vtemp_hc0ed3ca1__0[2U]);
        bufp->chgWData(oldp+139,(__Vtemp_h58f4b9f5__0),68);
        bufp->chgBit(oldp+142,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x1bU) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hcef34518__0))));
        bufp->chgBit(oldp+143,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x6000000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0x1bU)))));
        bufp->chgBit(oldp+144,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x1bU)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hcef34518__0))));
        bufp->chgBit(oldp+145,((IData)((0x6000000U 
                                        == (0xe000000U 
                                            & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+146,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0x1bU))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3c20__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x1cU);
        __Vtemp_hbe8f3385__0[0U] = __Vtemp_hc0ed3c20__0[0U];
        __Vtemp_hbe8f3385__0[1U] = __Vtemp_hc0ed3c20__0[1U];
        __Vtemp_hbe8f3385__0[2U] = (0xfU & __Vtemp_hc0ed3c20__0[2U]);
        bufp->chgWData(oldp+147,(__Vtemp_hbe8f3385__0),68);
        bufp->chgBit(oldp+150,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x1dU) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h91e9dc0e__0))));
        bufp->chgBit(oldp+151,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x18000000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0x1dU)))));
        bufp->chgBit(oldp+152,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x1dU)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h91e9dc0e__0))));
        bufp->chgBit(oldp+153,((IData)((0x18000000U 
                                        == (0x38000000U 
                                            & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+154,((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                  >> 0x1dU)),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3d9e__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x1eU);
        __Vtemp_h3d123818__0[0U] = __Vtemp_hc0ed3d9e__0[0U];
        __Vtemp_h3d123818__0[1U] = __Vtemp_hc0ed3d9e__0[1U];
        __Vtemp_h3d123818__0[2U] = (0xfU & __Vtemp_hc0ed3d9e__0[2U]);
        bufp->chgWData(oldp+155,(__Vtemp_h3d123818__0),68);
        bufp->chgBit(oldp+158,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x1fU) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h8fc047d7__0))));
        bufp->chgBit(oldp+159,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x1fU) & (~ (IData)(
                                                        (0U 
                                                         != 
                                                         (0x60000000U 
                                                          & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))))));
        bufp->chgBit(oldp+160,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x1fU)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h8fc047d7__0))));
        bufp->chgBit(oldp+161,((IData)((0x60000000U 
                                        == (0xe0000000U 
                                            & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+162,(((6U & ((- (IData)(
                                                    (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                                     >> 0x1fU))) 
                                         << 1U)) | 
                                  (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                   >> 0x1fU))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed6259__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x20U);
        __Vtemp_h99778e24__0[0U] = __Vtemp_hc0ed6259__0[0U];
        __Vtemp_h99778e24__0[1U] = __Vtemp_hc0ed6259__0[1U];
        __Vtemp_h99778e24__0[2U] = (0xfU & __Vtemp_hc0ed6259__0[2U]);
        bufp->chgWData(oldp+163,(__Vtemp_h99778e24__0),68);
        bufp->chgBit(oldp+166,(0U));
        bufp->chgCData(oldp+167,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 1U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed4e03__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 2U);
        __Vtemp_ha2d3c6e0__0[0U] = __Vtemp_hc0ed4e03__0[0U];
        __Vtemp_ha2d3c6e0__0[1U] = __Vtemp_hc0ed4e03__0[1U];
        __Vtemp_ha2d3c6e0__0[2U] = (0xfU & __Vtemp_hc0ed4e03__0[2U]);
        bufp->chgWData(oldp+168,(__Vtemp_ha2d3c6e0__0),68);
        bufp->chgBit(oldp+171,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 3U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc3505cf3__0))));
        bufp->chgBit(oldp+172,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (6U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 3U)))));
        bufp->chgBit(oldp+173,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 3U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc3505cf3__0))));
        bufp->chgBit(oldp+174,((IData)((6U == (0xeU 
                                               & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+175,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 3U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed4f7e__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 4U);
        __Vtemp_h7386d19a__0[0U] = __Vtemp_hc0ed4f7e__0[0U];
        __Vtemp_h7386d19a__0[1U] = __Vtemp_hc0ed4f7e__0[1U];
        __Vtemp_h7386d19a__0[2U] = (0xfU & __Vtemp_hc0ed4f7e__0[2U]);
        bufp->chgWData(oldp+176,(__Vtemp_h7386d19a__0),68);
        bufp->chgBit(oldp+179,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 5U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hf9f0876d__0))));
        bufp->chgBit(oldp+180,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x18U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 5U)))));
        bufp->chgBit(oldp+181,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 5U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hf9f0876d__0))));
        bufp->chgBit(oldp+182,((IData)((0x18U == (0x38U 
                                                  & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+183,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 5U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed4f00__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 6U);
        __Vtemp_hc8242373__0[0U] = __Vtemp_hc0ed4f00__0[0U];
        __Vtemp_hc8242373__0[1U] = __Vtemp_hc0ed4f00__0[1U];
        __Vtemp_hc8242373__0[2U] = (0xfU & __Vtemp_hc0ed4f00__0[2U]);
        bufp->chgWData(oldp+184,(__Vtemp_hc8242373__0),68);
        bufp->chgBit(oldp+187,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 7U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hfe0a41fe__0))));
        bufp->chgBit(oldp+188,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x60U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 7U)))));
        bufp->chgBit(oldp+189,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 7U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hfe0a41fe__0))));
        bufp->chgBit(oldp+190,((IData)((0x60U == (0xe0U 
                                                  & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+191,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 7U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed6c7f__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 8U);
        __Vtemp_h20360ba8__0[0U] = __Vtemp_hc0ed6c7f__0[0U];
        __Vtemp_h20360ba8__0[1U] = __Vtemp_hc0ed6c7f__0[1U];
        __Vtemp_h20360ba8__0[2U] = (0xfU & __Vtemp_hc0ed6c7f__0[2U]);
        bufp->chgWData(oldp+192,(__Vtemp_h20360ba8__0),68);
        bufp->chgBit(oldp+195,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 9U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc5e42a69__0))));
        bufp->chgBit(oldp+196,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x180U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 9U)))));
        bufp->chgBit(oldp+197,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 9U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hc5e42a69__0))));
        bufp->chgBit(oldp+198,((IData)((0x180U == (0x380U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+199,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 9U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed6ffd__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0xaU);
        __Vtemp_hb72b3b5a__0[0U] = __Vtemp_hc0ed6ffd__0[0U];
        __Vtemp_hb72b3b5a__0[1U] = __Vtemp_hc0ed6ffd__0[1U];
        __Vtemp_hb72b3b5a__0[2U] = (0xfU & __Vtemp_hc0ed6ffd__0[2U]);
        bufp->chgWData(oldp+200,(__Vtemp_hb72b3b5a__0),68);
        bufp->chgBit(oldp+203,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0xbU) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hbaa102cc__0))));
        bufp->chgBit(oldp+204,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x600U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0xbU)))));
        bufp->chgBit(oldp+205,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0xbU)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hbaa102cc__0))));
        bufp->chgBit(oldp+206,((IData)((0x600U == (0xe00U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+207,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0xbU))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed7184__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0xcU);
        __Vtemp_h5d050081__0[0U] = __Vtemp_hc0ed7184__0[0U];
        __Vtemp_h5d050081__0[1U] = __Vtemp_hc0ed7184__0[1U];
        __Vtemp_h5d050081__0[2U] = (0xfU & __Vtemp_hc0ed7184__0[2U]);
        bufp->chgWData(oldp+208,(__Vtemp_h5d050081__0),68);
        bufp->chgBit(oldp+211,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0xdU) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hb4e6b126__0))));
        bufp->chgBit(oldp+212,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x1800U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0xdU)))));
        bufp->chgBit(oldp+213,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0xdU)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hb4e6b126__0))));
        bufp->chgBit(oldp+214,((IData)((0x1800U == 
                                        (0x3800U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+215,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0xdU))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed7102__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0xeU);
        __Vtemp_h146180b1__0[0U] = __Vtemp_hc0ed7102__0[0U];
        __Vtemp_h146180b1__0[1U] = __Vtemp_hc0ed7102__0[1U];
        __Vtemp_h146180b1__0[2U] = (0xfU & __Vtemp_hc0ed7102__0[2U]);
        bufp->chgWData(oldp+216,(__Vtemp_h146180b1__0),68);
        bufp->chgBit(oldp+219,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0xfU) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_haed8dbe3__0))));
        bufp->chgBit(oldp+220,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x6000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0xfU)))));
        bufp->chgBit(oldp+221,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0xfU)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_haed8dbe3__0))));
        bufp->chgBit(oldp+222,((IData)((0x6000U == 
                                        (0xe000U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+223,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0xfU))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3d35__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x10U);
        __Vtemp_h49015499__0[0U] = __Vtemp_hc0ed3d35__0[0U];
        __Vtemp_h49015499__0[1U] = __Vtemp_hc0ed3d35__0[1U];
        __Vtemp_h49015499__0[2U] = (0xfU & __Vtemp_hc0ed3d35__0[2U]);
        bufp->chgWData(oldp+224,(__Vtemp_h49015499__0),68);
        bufp->chgBit(oldp+227,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x11U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hb84f77ab__0))));
        bufp->chgBit(oldp+228,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x18000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0x11U)))));
        bufp->chgBit(oldp+229,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x11U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_hb84f77ab__0))));
        bufp->chgBit(oldp+230,((IData)((0x18000U == 
                                        (0x38000U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgCData(oldp+231,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                        >> 0x11U))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_hc0ed3ab7__0, vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__multiplicand_ext, 0x12U);
        __Vtemp_h6964d4eb__0[0U] = __Vtemp_hc0ed3ab7__0[0U];
        __Vtemp_h6964d4eb__0[1U] = __Vtemp_hc0ed3ab7__0[1U];
        __Vtemp_h6964d4eb__0[2U] = (0xfU & __Vtemp_hc0ed3ab7__0[2U]);
        bufp->chgWData(oldp+232,(__Vtemp_h6964d4eb__0),68);
        bufp->chgBit(oldp+235,(((vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                 >> 0x13U) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h937272c0__0))));
        bufp->chgBit(oldp+236,((1U & ((~ (IData)((0U 
                                                  != 
                                                  (0x60000U 
                                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))) 
                                      & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                         >> 0x13U)))));
        bufp->chgBit(oldp+237,(((~ (vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2 
                                    >> 0x13U)) & (IData)(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT____VdfgTmp_h937272c0__0))));
        bufp->chgBit(oldp+238,((IData)((0x60000U == 
                                        (0xe0000U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__multiplier_mant2)))));
        bufp->chgIData(oldp+239,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0U]),17);
        bufp->chgSData(oldp+240,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+241,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                      ^ ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                         ^ vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0U])))));
        bufp->chgCData(oldp+242,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+243,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (2U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0U] 
                                                   << 1U))))),4);
        bufp->chgCData(oldp+244,((2U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                         ^ ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                            ^ vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0U])) 
                                        << 1U))),2);
        bufp->chgCData(oldp+245,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 0xeU))),3);
        bufp->chgBit(oldp+246,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0U] >> 0xeU))))));
        bufp->chgBit(oldp+247,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+248,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 0x10U))));
        bufp->chgBit(oldp+249,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 0xfU))));
        bufp->chgBit(oldp+250,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 0xeU))));
        bufp->chgCData(oldp+251,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 0xbU))),3);
        bufp->chgBit(oldp+252,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0U] >> 0xbU))))));
        bufp->chgBit(oldp+253,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+254,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 0xdU))));
        bufp->chgBit(oldp+255,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 0xcU))));
        bufp->chgBit(oldp+256,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 0xbU))));
        bufp->chgCData(oldp+257,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 8U))),3);
        bufp->chgBit(oldp+258,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0U] >> 8U))))));
        bufp->chgBit(oldp+259,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+260,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 0xaU))));
        bufp->chgBit(oldp+261,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 9U))));
        bufp->chgBit(oldp+262,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 8U))));
        bufp->chgCData(oldp+263,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 5U))),3);
        bufp->chgBit(oldp+264,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0U] >> 5U))))));
        bufp->chgBit(oldp+265,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+266,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 7U))));
        bufp->chgBit(oldp+267,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 6U))));
        bufp->chgBit(oldp+268,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 5U))));
        bufp->chgCData(oldp+269,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 2U))),3);
        bufp->chgBit(oldp+270,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0U] >> 2U))))));
        bufp->chgBit(oldp+271,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+272,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 4U))));
        bufp->chgBit(oldp+273,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 3U))));
        bufp->chgBit(oldp+274,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 2U))));
        bufp->chgCData(oldp+275,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+276,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+277,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+278,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [0U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+279,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 1U)))));
        bufp->chgBit(oldp+280,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+281,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [0U] >> 1U))));
        bufp->chgCData(oldp+282,((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0U] << 2U))),3);
        bufp->chgBit(oldp+283,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [0U])));
        bufp->chgCData(oldp+284,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (1U 
                                                & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                [0U])))),3);
        bufp->chgBit(oldp+285,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                   [0U]))));
        bufp->chgCData(oldp+286,((4U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                         ^ ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                            ^ vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0U])) 
                                        << 2U))),3);
        bufp->chgIData(oldp+287,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [1U]),17);
        bufp->chgSData(oldp+288,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+289,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout));
        bufp->chgBit(oldp+290,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+291,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+292,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+293,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+294,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+295,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+296,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 0xeU))),3);
        bufp->chgBit(oldp+297,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [1U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [1U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [1U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [1U] >> 0xeU))))));
        bufp->chgBit(oldp+298,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+299,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 0x10U))));
        bufp->chgBit(oldp+300,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 0xfU))));
        bufp->chgBit(oldp+301,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 0xeU))));
        bufp->chgCData(oldp+302,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 0xbU))),3);
        bufp->chgBit(oldp+303,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [1U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [1U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [1U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [1U] >> 0xbU))))));
        bufp->chgBit(oldp+304,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+305,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 0xdU))));
        bufp->chgBit(oldp+306,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 0xcU))));
        bufp->chgBit(oldp+307,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 0xbU))));
        bufp->chgCData(oldp+308,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 8U))),3);
        bufp->chgBit(oldp+309,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [1U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [1U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [1U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [1U] >> 8U))))));
        bufp->chgBit(oldp+310,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+311,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 0xaU))));
        bufp->chgBit(oldp+312,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 9U))));
        bufp->chgBit(oldp+313,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 8U))));
        bufp->chgCData(oldp+314,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 5U))),3);
        bufp->chgBit(oldp+315,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [1U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [1U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [1U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [1U] >> 5U))))));
        bufp->chgBit(oldp+316,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+317,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 7U))));
        bufp->chgBit(oldp+318,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 6U))));
        bufp->chgBit(oldp+319,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 5U))));
        bufp->chgCData(oldp+320,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 2U))),3);
        bufp->chgBit(oldp+321,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [1U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [1U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [1U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [1U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [1U] >> 2U))))));
        bufp->chgBit(oldp+322,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+323,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 4U))));
        bufp->chgBit(oldp+324,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 3U))));
        bufp->chgBit(oldp+325,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 2U))));
        bufp->chgCData(oldp+326,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+327,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+328,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+329,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [1U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+330,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 1U)))));
        bufp->chgBit(oldp+331,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+332,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [1U] >> 1U))));
        bufp->chgCData(oldp+333,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [1U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+334,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [1U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [1U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+335,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+336,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [1U])));
        bufp->chgBit(oldp+337,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+338,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+339,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+340,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+341,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+342,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+343,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+344,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+345,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+346,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+347,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+348,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+349,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+350,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+351,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+352,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+353,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+354,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+355,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+356,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+357,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+358,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+359,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+360,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+361,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+362,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+363,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+364,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+365,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+366,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+367,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+368,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+369,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [2U]),17);
        bufp->chgSData(oldp+370,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+371,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout));
        bufp->chgBit(oldp+372,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+373,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+374,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+375,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+376,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+377,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+378,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 0xeU))),3);
        bufp->chgBit(oldp+379,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [2U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [2U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [2U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [2U] >> 0xeU))))));
        bufp->chgBit(oldp+380,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+381,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 0x10U))));
        bufp->chgBit(oldp+382,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 0xfU))));
        bufp->chgBit(oldp+383,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 0xeU))));
        bufp->chgCData(oldp+384,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 0xbU))),3);
        bufp->chgBit(oldp+385,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [2U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [2U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [2U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [2U] >> 0xbU))))));
        bufp->chgBit(oldp+386,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+387,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 0xdU))));
        bufp->chgBit(oldp+388,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 0xcU))));
        bufp->chgBit(oldp+389,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 0xbU))));
        bufp->chgCData(oldp+390,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 8U))),3);
        bufp->chgBit(oldp+391,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [2U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [2U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [2U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [2U] >> 8U))))));
        bufp->chgBit(oldp+392,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+393,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 0xaU))));
        bufp->chgBit(oldp+394,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 9U))));
        bufp->chgBit(oldp+395,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 8U))));
        bufp->chgCData(oldp+396,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 5U))),3);
        bufp->chgBit(oldp+397,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [2U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [2U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [2U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [2U] >> 5U))))));
        bufp->chgBit(oldp+398,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+399,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 7U))));
        bufp->chgBit(oldp+400,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 6U))));
        bufp->chgBit(oldp+401,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 5U))));
        bufp->chgCData(oldp+402,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 2U))),3);
        bufp->chgBit(oldp+403,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [2U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [2U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [2U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [2U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [2U] >> 2U))))));
        bufp->chgBit(oldp+404,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+405,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 4U))));
        bufp->chgBit(oldp+406,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 3U))));
        bufp->chgBit(oldp+407,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 2U))));
        bufp->chgCData(oldp+408,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+409,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+410,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+411,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [2U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+412,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 1U)))));
        bufp->chgBit(oldp+413,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+414,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [2U] >> 1U))));
        bufp->chgCData(oldp+415,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [2U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+416,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [2U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [2U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+417,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+418,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [2U])));
        bufp->chgBit(oldp+419,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+420,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+421,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+422,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+423,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+424,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+425,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+426,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+427,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+428,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+429,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+430,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+431,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+432,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+433,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+434,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+435,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+436,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+437,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+438,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+439,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+440,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+441,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+442,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+443,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+444,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+445,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+446,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+447,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+448,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+449,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+450,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+451,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [3U]),17);
        bufp->chgSData(oldp+452,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+453,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout));
        bufp->chgBit(oldp+454,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+455,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+456,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+457,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+458,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+459,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+460,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 0xeU))),3);
        bufp->chgBit(oldp+461,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [3U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [3U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [3U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [3U] >> 0xeU))))));
        bufp->chgBit(oldp+462,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+463,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 0x10U))));
        bufp->chgBit(oldp+464,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 0xfU))));
        bufp->chgBit(oldp+465,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 0xeU))));
        bufp->chgCData(oldp+466,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 0xbU))),3);
        bufp->chgBit(oldp+467,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [3U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [3U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [3U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [3U] >> 0xbU))))));
        bufp->chgBit(oldp+468,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+469,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 0xdU))));
        bufp->chgBit(oldp+470,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 0xcU))));
        bufp->chgBit(oldp+471,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 0xbU))));
        bufp->chgCData(oldp+472,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 8U))),3);
        bufp->chgBit(oldp+473,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [3U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [3U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [3U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [3U] >> 8U))))));
        bufp->chgBit(oldp+474,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+475,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 0xaU))));
        bufp->chgBit(oldp+476,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 9U))));
        bufp->chgBit(oldp+477,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 8U))));
        bufp->chgCData(oldp+478,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 5U))),3);
        bufp->chgBit(oldp+479,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [3U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [3U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [3U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [3U] >> 5U))))));
        bufp->chgBit(oldp+480,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+481,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 7U))));
        bufp->chgBit(oldp+482,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 6U))));
        bufp->chgBit(oldp+483,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 5U))));
        bufp->chgCData(oldp+484,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 2U))),3);
        bufp->chgBit(oldp+485,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [3U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [3U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [3U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [3U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [3U] >> 2U))))));
        bufp->chgBit(oldp+486,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+487,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 4U))));
        bufp->chgBit(oldp+488,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 3U))));
        bufp->chgBit(oldp+489,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 2U))));
        bufp->chgCData(oldp+490,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+491,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+492,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+493,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [3U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+494,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 1U)))));
        bufp->chgBit(oldp+495,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+496,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [3U] >> 1U))));
        bufp->chgCData(oldp+497,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [3U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+498,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [3U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [3U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+499,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+500,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [3U])));
        bufp->chgBit(oldp+501,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+502,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+503,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+504,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+505,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+506,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+507,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+508,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+509,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+510,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+511,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+512,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+513,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+514,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+515,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+516,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+517,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+518,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+519,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+520,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+521,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+522,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+523,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+524,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+525,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+526,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+527,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+528,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+529,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+530,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+531,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+532,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+533,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [4U]),17);
        bufp->chgSData(oldp+534,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+535,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout));
        bufp->chgBit(oldp+536,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+537,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+538,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+539,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+540,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+541,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+542,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 0xeU))),3);
        bufp->chgBit(oldp+543,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [4U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [4U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [4U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [4U] >> 0xeU))))));
        bufp->chgBit(oldp+544,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+545,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 0x10U))));
        bufp->chgBit(oldp+546,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 0xfU))));
        bufp->chgBit(oldp+547,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 0xeU))));
        bufp->chgCData(oldp+548,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 0xbU))),3);
        bufp->chgBit(oldp+549,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [4U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [4U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [4U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [4U] >> 0xbU))))));
        bufp->chgBit(oldp+550,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+551,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 0xdU))));
        bufp->chgBit(oldp+552,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 0xcU))));
        bufp->chgBit(oldp+553,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 0xbU))));
        bufp->chgCData(oldp+554,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 8U))),3);
        bufp->chgBit(oldp+555,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [4U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [4U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [4U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [4U] >> 8U))))));
        bufp->chgBit(oldp+556,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+557,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 0xaU))));
        bufp->chgBit(oldp+558,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 9U))));
        bufp->chgBit(oldp+559,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 8U))));
        bufp->chgCData(oldp+560,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 5U))),3);
        bufp->chgBit(oldp+561,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [4U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [4U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [4U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [4U] >> 5U))))));
        bufp->chgBit(oldp+562,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+563,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 7U))));
        bufp->chgBit(oldp+564,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 6U))));
        bufp->chgBit(oldp+565,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 5U))));
        bufp->chgCData(oldp+566,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 2U))),3);
        bufp->chgBit(oldp+567,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [4U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [4U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [4U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [4U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [4U] >> 2U))))));
        bufp->chgBit(oldp+568,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+569,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 4U))));
        bufp->chgBit(oldp+570,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 3U))));
        bufp->chgBit(oldp+571,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 2U))));
        bufp->chgCData(oldp+572,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+573,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+574,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+575,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [4U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+576,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 1U)))));
        bufp->chgBit(oldp+577,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+578,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [4U] >> 1U))));
        bufp->chgCData(oldp+579,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [4U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+580,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [4U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [4U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+581,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+582,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [4U])));
        bufp->chgBit(oldp+583,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+584,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+585,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+586,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+587,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+588,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+589,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+590,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+591,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+592,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+594,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+595,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+596,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+597,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+598,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+599,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+600,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+601,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+602,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+603,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+604,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+605,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+606,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+607,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+608,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+609,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+610,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+611,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+612,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+613,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+614,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+615,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [5U]),17);
        bufp->chgSData(oldp+616,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+617,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout));
        bufp->chgBit(oldp+618,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+619,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+620,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+621,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+622,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+623,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+624,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 0xeU))),3);
        bufp->chgBit(oldp+625,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [5U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [5U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [5U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [5U] >> 0xeU))))));
        bufp->chgBit(oldp+626,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+627,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 0x10U))));
        bufp->chgBit(oldp+628,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 0xfU))));
        bufp->chgBit(oldp+629,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 0xeU))));
        bufp->chgCData(oldp+630,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 0xbU))),3);
        bufp->chgBit(oldp+631,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [5U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [5U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [5U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [5U] >> 0xbU))))));
        bufp->chgBit(oldp+632,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+633,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 0xdU))));
        bufp->chgBit(oldp+634,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 0xcU))));
        bufp->chgBit(oldp+635,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 0xbU))));
        bufp->chgCData(oldp+636,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 8U))),3);
        bufp->chgBit(oldp+637,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [5U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [5U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [5U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [5U] >> 8U))))));
        bufp->chgBit(oldp+638,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+639,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 0xaU))));
        bufp->chgBit(oldp+640,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 9U))));
        bufp->chgBit(oldp+641,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 8U))));
        bufp->chgCData(oldp+642,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 5U))),3);
        bufp->chgBit(oldp+643,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [5U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [5U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [5U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [5U] >> 5U))))));
        bufp->chgBit(oldp+644,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+645,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 7U))));
        bufp->chgBit(oldp+646,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 6U))));
        bufp->chgBit(oldp+647,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 5U))));
        bufp->chgCData(oldp+648,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 2U))),3);
        bufp->chgBit(oldp+649,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [5U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [5U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [5U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [5U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [5U] >> 2U))))));
        bufp->chgBit(oldp+650,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+651,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 4U))));
        bufp->chgBit(oldp+652,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 3U))));
        bufp->chgBit(oldp+653,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 2U))));
        bufp->chgCData(oldp+654,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+655,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+656,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+657,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [5U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+658,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 1U)))));
        bufp->chgBit(oldp+659,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+660,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [5U] >> 1U))));
        bufp->chgCData(oldp+661,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [5U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+662,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [5U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [5U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+663,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+664,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [5U])));
        bufp->chgBit(oldp+665,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+666,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+667,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+668,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+669,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+670,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+671,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+672,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+673,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+674,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+675,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+676,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+677,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+678,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+679,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+680,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+681,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+682,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+683,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+684,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+685,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+686,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+687,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+688,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+689,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+690,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+691,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+692,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+693,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+694,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+695,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+696,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+697,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [6U]),17);
        bufp->chgSData(oldp+698,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+699,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout));
        bufp->chgBit(oldp+700,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+701,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+702,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+703,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+704,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+705,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+706,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 0xeU))),3);
        bufp->chgBit(oldp+707,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [6U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [6U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [6U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [6U] >> 0xeU))))));
        bufp->chgBit(oldp+708,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+709,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 0x10U))));
        bufp->chgBit(oldp+710,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 0xfU))));
        bufp->chgBit(oldp+711,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 0xeU))));
        bufp->chgCData(oldp+712,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 0xbU))),3);
        bufp->chgBit(oldp+713,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [6U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [6U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [6U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [6U] >> 0xbU))))));
        bufp->chgBit(oldp+714,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+715,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 0xdU))));
        bufp->chgBit(oldp+716,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 0xcU))));
        bufp->chgBit(oldp+717,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 0xbU))));
        bufp->chgCData(oldp+718,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 8U))),3);
        bufp->chgBit(oldp+719,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [6U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [6U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [6U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [6U] >> 8U))))));
        bufp->chgBit(oldp+720,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+721,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 0xaU))));
        bufp->chgBit(oldp+722,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 9U))));
        bufp->chgBit(oldp+723,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 8U))));
        bufp->chgCData(oldp+724,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 5U))),3);
        bufp->chgBit(oldp+725,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [6U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [6U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [6U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [6U] >> 5U))))));
        bufp->chgBit(oldp+726,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+727,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 7U))));
        bufp->chgBit(oldp+728,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 6U))));
        bufp->chgBit(oldp+729,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 5U))));
        bufp->chgCData(oldp+730,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 2U))),3);
        bufp->chgBit(oldp+731,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [6U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [6U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [6U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [6U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [6U] >> 2U))))));
        bufp->chgBit(oldp+732,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+733,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 4U))));
        bufp->chgBit(oldp+734,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 3U))));
        bufp->chgBit(oldp+735,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 2U))));
        bufp->chgCData(oldp+736,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+737,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+738,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+739,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [6U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+740,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 1U)))));
        bufp->chgBit(oldp+741,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+742,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [6U] >> 1U))));
        bufp->chgCData(oldp+743,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [6U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+744,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [6U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [6U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+745,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+746,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [6U])));
        bufp->chgBit(oldp+747,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+748,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+749,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+750,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+751,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+752,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+753,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+754,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+755,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+756,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+757,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+758,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+759,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+760,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+761,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+762,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+763,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+764,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+765,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+766,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+767,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+768,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+769,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+770,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+771,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+772,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+773,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+774,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+775,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+776,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+777,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+778,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+779,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [7U]),17);
        bufp->chgSData(oldp+780,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+781,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout));
        bufp->chgBit(oldp+782,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+783,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+784,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+785,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+786,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+787,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+788,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 0xeU))),3);
        bufp->chgBit(oldp+789,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [7U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [7U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [7U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [7U] >> 0xeU))))));
        bufp->chgBit(oldp+790,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+791,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 0x10U))));
        bufp->chgBit(oldp+792,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 0xfU))));
        bufp->chgBit(oldp+793,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 0xeU))));
        bufp->chgCData(oldp+794,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 0xbU))),3);
        bufp->chgBit(oldp+795,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [7U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [7U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [7U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [7U] >> 0xbU))))));
        bufp->chgBit(oldp+796,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+797,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 0xdU))));
        bufp->chgBit(oldp+798,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 0xcU))));
        bufp->chgBit(oldp+799,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 0xbU))));
        bufp->chgCData(oldp+800,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 8U))),3);
        bufp->chgBit(oldp+801,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [7U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [7U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [7U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [7U] >> 8U))))));
        bufp->chgBit(oldp+802,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+803,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 0xaU))));
        bufp->chgBit(oldp+804,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 9U))));
        bufp->chgBit(oldp+805,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 8U))));
        bufp->chgCData(oldp+806,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 5U))),3);
        bufp->chgBit(oldp+807,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [7U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [7U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [7U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [7U] >> 5U))))));
        bufp->chgBit(oldp+808,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+809,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 7U))));
        bufp->chgBit(oldp+810,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 6U))));
        bufp->chgBit(oldp+811,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 5U))));
        bufp->chgCData(oldp+812,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 2U))),3);
        bufp->chgBit(oldp+813,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [7U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [7U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [7U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [7U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [7U] >> 2U))))));
        bufp->chgBit(oldp+814,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+815,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 4U))));
        bufp->chgBit(oldp+816,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 3U))));
        bufp->chgBit(oldp+817,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 2U))));
        bufp->chgCData(oldp+818,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+819,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+820,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+821,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [7U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+822,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 1U)))));
        bufp->chgBit(oldp+823,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+824,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [7U] >> 1U))));
        bufp->chgCData(oldp+825,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [7U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+826,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [7U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [7U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+827,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+828,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [7U])));
        bufp->chgBit(oldp+829,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+830,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+831,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+832,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+833,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+834,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+835,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+836,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+837,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+838,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+839,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+840,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+841,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+842,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+843,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+844,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+845,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+846,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+847,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+848,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+849,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+850,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+851,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+852,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+853,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+854,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+855,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+856,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+857,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+858,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+859,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+860,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+861,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [8U]),17);
        bufp->chgSData(oldp+862,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+863,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout));
        bufp->chgBit(oldp+864,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+865,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+866,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+867,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+868,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+869,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+870,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 0xeU))),3);
        bufp->chgBit(oldp+871,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [8U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [8U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [8U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [8U] >> 0xeU))))));
        bufp->chgBit(oldp+872,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+873,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 0x10U))));
        bufp->chgBit(oldp+874,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 0xfU))));
        bufp->chgBit(oldp+875,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 0xeU))));
        bufp->chgCData(oldp+876,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 0xbU))),3);
        bufp->chgBit(oldp+877,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [8U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [8U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [8U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [8U] >> 0xbU))))));
        bufp->chgBit(oldp+878,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+879,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 0xdU))));
        bufp->chgBit(oldp+880,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 0xcU))));
        bufp->chgBit(oldp+881,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 0xbU))));
        bufp->chgCData(oldp+882,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 8U))),3);
        bufp->chgBit(oldp+883,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [8U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [8U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [8U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [8U] >> 8U))))));
        bufp->chgBit(oldp+884,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+885,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 0xaU))));
        bufp->chgBit(oldp+886,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 9U))));
        bufp->chgBit(oldp+887,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 8U))));
        bufp->chgCData(oldp+888,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 5U))),3);
        bufp->chgBit(oldp+889,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [8U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [8U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [8U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [8U] >> 5U))))));
        bufp->chgBit(oldp+890,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+891,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 7U))));
        bufp->chgBit(oldp+892,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 6U))));
        bufp->chgBit(oldp+893,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 5U))));
        bufp->chgCData(oldp+894,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 2U))),3);
        bufp->chgBit(oldp+895,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [8U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [8U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [8U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [8U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [8U] >> 2U))))));
        bufp->chgBit(oldp+896,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+897,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 4U))));
        bufp->chgBit(oldp+898,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 3U))));
        bufp->chgBit(oldp+899,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 2U))));
        bufp->chgCData(oldp+900,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+901,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+902,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+903,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [8U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+904,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 1U)))));
        bufp->chgBit(oldp+905,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+906,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [8U] >> 1U))));
        bufp->chgCData(oldp+907,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [8U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+908,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [8U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [8U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+909,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+910,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [8U])));
        bufp->chgBit(oldp+911,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+912,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+913,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+914,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+915,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+916,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+917,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+918,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+919,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+920,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+921,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+922,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+923,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+924,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+925,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+926,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+927,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+928,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+929,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+930,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+931,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+932,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+933,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+934,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+935,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+936,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+937,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+938,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+939,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+940,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+941,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+942,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+943,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [9U]),17);
        bufp->chgSData(oldp+944,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+945,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout));
        bufp->chgBit(oldp+946,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+947,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+948,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+949,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+950,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+951,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+952,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 0xeU))),3);
        bufp->chgBit(oldp+953,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 0x10U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [9U] >> 0xfU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [9U] >> 0xfU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [9U] >> 0x10U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [9U] >> 0xeU))))));
        bufp->chgBit(oldp+954,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+955,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 0x10U))));
        bufp->chgBit(oldp+956,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 0xfU))));
        bufp->chgBit(oldp+957,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 0xeU))));
        bufp->chgCData(oldp+958,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 0xbU))),3);
        bufp->chgBit(oldp+959,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 0xdU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [9U] >> 0xcU)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [9U] >> 0xcU) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [9U] >> 0xdU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [9U] >> 0xbU))))));
        bufp->chgBit(oldp+960,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+961,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 0xdU))));
        bufp->chgBit(oldp+962,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 0xcU))));
        bufp->chgBit(oldp+963,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 0xbU))));
        bufp->chgCData(oldp+964,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 8U))),3);
        bufp->chgBit(oldp+965,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 0xaU) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [9U] >> 9U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [9U] >> 9U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [9U] >> 0xaU)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [9U] >> 8U))))));
        bufp->chgBit(oldp+966,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+967,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 0xaU))));
        bufp->chgBit(oldp+968,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 9U))));
        bufp->chgBit(oldp+969,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 8U))));
        bufp->chgCData(oldp+970,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 5U))),3);
        bufp->chgBit(oldp+971,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 7U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [9U] >> 6U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [9U] >> 6U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [9U] >> 7U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [9U] >> 5U))))));
        bufp->chgBit(oldp+972,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+973,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 7U))));
        bufp->chgBit(oldp+974,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 6U))));
        bufp->chgBit(oldp+975,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 5U))));
        bufp->chgCData(oldp+976,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 2U))),3);
        bufp->chgBit(oldp+977,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [9U] >> 4U) 
                                       & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [9U] >> 3U)) 
                                      | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [9U] >> 3U) 
                                          | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [9U] >> 4U)) 
                                         & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [9U] >> 2U))))));
        bufp->chgBit(oldp+978,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+979,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 4U))));
        bufp->chgBit(oldp+980,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 3U))));
        bufp->chgBit(oldp+981,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 2U))));
        bufp->chgCData(oldp+982,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+983,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+984,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+985,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                   [9U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+986,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 1U)))));
        bufp->chgBit(oldp+987,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+988,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                      [9U] >> 1U))));
        bufp->chgCData(oldp+989,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [9U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+990,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [9U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [9U]) & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+991,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+992,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                [9U])));
        bufp->chgBit(oldp+993,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+994,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+995,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+996,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+997,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+998,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+999,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+1000,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1001,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1002,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1003,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1004,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1005,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1006,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1007,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1008,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1009,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1010,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1011,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1012,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1013,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1014,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1015,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1016,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1017,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1018,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1019,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1020,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1021,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1022,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1023,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1024,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1025,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0xaU]),17);
        bufp->chgSData(oldp+1026,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1027,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1028,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1029,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1030,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1031,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1032,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1033,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1034,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 0xeU))),3);
        bufp->chgBit(oldp+1035,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xaU] >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xaU] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xaU] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xaU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1036,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1037,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 0x10U))));
        bufp->chgBit(oldp+1038,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 0xfU))));
        bufp->chgBit(oldp+1039,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 0xeU))));
        bufp->chgCData(oldp+1040,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 0xbU))),3);
        bufp->chgBit(oldp+1041,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xaU] >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xaU] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xaU] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xaU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1042,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1043,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 0xdU))));
        bufp->chgBit(oldp+1044,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 0xcU))));
        bufp->chgBit(oldp+1045,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 0xbU))));
        bufp->chgCData(oldp+1046,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 8U))),3);
        bufp->chgBit(oldp+1047,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xaU] >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xaU] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xaU] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xaU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1048,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1049,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 0xaU))));
        bufp->chgBit(oldp+1050,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 9U))));
        bufp->chgBit(oldp+1051,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 8U))));
        bufp->chgCData(oldp+1052,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 5U))),3);
        bufp->chgBit(oldp+1053,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xaU] >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xaU] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xaU] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xaU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1054,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1055,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 7U))));
        bufp->chgBit(oldp+1056,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 6U))));
        bufp->chgBit(oldp+1057,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 5U))));
        bufp->chgCData(oldp+1058,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 2U))),3);
        bufp->chgBit(oldp+1059,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xaU] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xaU] >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xaU] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xaU] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xaU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1060,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1061,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 4U))));
        bufp->chgBit(oldp+1062,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 3U))));
        bufp->chgBit(oldp+1063,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 2U))));
        bufp->chgCData(oldp+1064,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1065,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1066,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1067,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0xaU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1068,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 1U)))));
        bufp->chgBit(oldp+1069,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1070,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xaU] >> 1U))));
        bufp->chgCData(oldp+1071,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0xaU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1072,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0xaU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xaU]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1073,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1074,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0xaU])));
        bufp->chgBit(oldp+1075,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1076,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1077,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1078,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1079,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1080,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1081,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1082,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1083,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1084,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1085,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1086,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1087,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1088,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1089,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1090,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1091,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1092,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1093,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1094,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1095,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1096,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1097,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1098,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1099,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1100,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1101,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1102,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1103,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1104,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1105,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1106,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1107,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0xbU]),17);
        bufp->chgSData(oldp+1108,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1109,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1110,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1111,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1112,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1113,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1114,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1115,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1116,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 0xeU))),3);
        bufp->chgBit(oldp+1117,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xbU] >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xbU] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xbU] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xbU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1118,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1119,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 0x10U))));
        bufp->chgBit(oldp+1120,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 0xfU))));
        bufp->chgBit(oldp+1121,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 0xeU))));
        bufp->chgCData(oldp+1122,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 0xbU))),3);
        bufp->chgBit(oldp+1123,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xbU] >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xbU] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xbU] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xbU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1124,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1125,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 0xdU))));
        bufp->chgBit(oldp+1126,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 0xcU))));
        bufp->chgBit(oldp+1127,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 0xbU))));
        bufp->chgCData(oldp+1128,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 8U))),3);
        bufp->chgBit(oldp+1129,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xbU] >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xbU] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xbU] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xbU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1130,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1131,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 0xaU))));
        bufp->chgBit(oldp+1132,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 9U))));
        bufp->chgBit(oldp+1133,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 8U))));
        bufp->chgCData(oldp+1134,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 5U))),3);
        bufp->chgBit(oldp+1135,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xbU] >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xbU] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xbU] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xbU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1136,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1137,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 7U))));
        bufp->chgBit(oldp+1138,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 6U))));
        bufp->chgBit(oldp+1139,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 5U))));
        bufp->chgCData(oldp+1140,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 2U))),3);
        bufp->chgBit(oldp+1141,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xbU] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xbU] >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xbU] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xbU] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xbU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1142,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1143,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 4U))));
        bufp->chgBit(oldp+1144,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 3U))));
        bufp->chgBit(oldp+1145,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 2U))));
        bufp->chgCData(oldp+1146,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1147,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1148,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1149,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0xbU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1150,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 1U)))));
        bufp->chgBit(oldp+1151,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1152,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xbU] >> 1U))));
        bufp->chgCData(oldp+1153,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0xbU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1154,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0xbU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xbU]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1155,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1156,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0xbU])));
        bufp->chgBit(oldp+1157,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1158,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1159,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1160,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1161,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1162,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1163,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1164,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1165,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1166,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1167,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1168,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1169,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1170,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1171,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1172,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1173,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1174,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1175,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1176,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1177,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1178,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1179,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1180,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1181,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1182,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1183,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1184,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1185,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1186,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1187,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1188,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1189,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0xcU]),17);
        bufp->chgSData(oldp+1190,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1191,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1192,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1193,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1194,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1195,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1196,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1197,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1198,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 0xeU))),3);
        bufp->chgBit(oldp+1199,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xcU] >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xcU] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xcU] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xcU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1200,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1201,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 0x10U))));
        bufp->chgBit(oldp+1202,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 0xfU))));
        bufp->chgBit(oldp+1203,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 0xeU))));
        bufp->chgCData(oldp+1204,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 0xbU))),3);
        bufp->chgBit(oldp+1205,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xcU] >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xcU] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xcU] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xcU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1206,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1207,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 0xdU))));
        bufp->chgBit(oldp+1208,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 0xcU))));
        bufp->chgBit(oldp+1209,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 0xbU))));
        bufp->chgCData(oldp+1210,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 8U))),3);
        bufp->chgBit(oldp+1211,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xcU] >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xcU] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xcU] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xcU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1212,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1213,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 0xaU))));
        bufp->chgBit(oldp+1214,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 9U))));
        bufp->chgBit(oldp+1215,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 8U))));
        bufp->chgCData(oldp+1216,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 5U))),3);
        bufp->chgBit(oldp+1217,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xcU] >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xcU] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xcU] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xcU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1218,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1219,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 7U))));
        bufp->chgBit(oldp+1220,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 6U))));
        bufp->chgBit(oldp+1221,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 5U))));
        bufp->chgCData(oldp+1222,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 2U))),3);
        bufp->chgBit(oldp+1223,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xcU] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xcU] >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xcU] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xcU] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xcU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1224,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1225,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 4U))));
        bufp->chgBit(oldp+1226,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 3U))));
        bufp->chgBit(oldp+1227,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 2U))));
        bufp->chgCData(oldp+1228,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1229,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1230,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1231,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0xcU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1232,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 1U)))));
        bufp->chgBit(oldp+1233,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1234,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xcU] >> 1U))));
        bufp->chgCData(oldp+1235,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0xcU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1236,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0xcU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xcU]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1237,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1238,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0xcU])));
        bufp->chgBit(oldp+1239,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1240,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1241,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1242,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1243,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1244,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1245,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1246,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1247,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1248,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1249,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1250,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1251,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1252,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1253,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1254,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1255,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1256,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1257,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1258,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1259,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1260,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1261,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1262,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1263,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1264,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1265,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1266,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1267,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1268,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1269,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1270,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1271,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0xdU]),17);
        bufp->chgSData(oldp+1272,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1273,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1274,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1275,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1276,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1277,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1278,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1279,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1280,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 0xeU))),3);
        bufp->chgBit(oldp+1281,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xdU] >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xdU] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xdU] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xdU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1282,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1283,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 0x10U))));
        bufp->chgBit(oldp+1284,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 0xfU))));
        bufp->chgBit(oldp+1285,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 0xeU))));
        bufp->chgCData(oldp+1286,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 0xbU))),3);
        bufp->chgBit(oldp+1287,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xdU] >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xdU] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xdU] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xdU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1288,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1289,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 0xdU))));
        bufp->chgBit(oldp+1290,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 0xcU))));
        bufp->chgBit(oldp+1291,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 0xbU))));
        bufp->chgCData(oldp+1292,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 8U))),3);
        bufp->chgBit(oldp+1293,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xdU] >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xdU] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xdU] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xdU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1294,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1295,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 0xaU))));
        bufp->chgBit(oldp+1296,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 9U))));
        bufp->chgBit(oldp+1297,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 8U))));
        bufp->chgCData(oldp+1298,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 5U))),3);
        bufp->chgBit(oldp+1299,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xdU] >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xdU] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xdU] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xdU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1300,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1301,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 7U))));
        bufp->chgBit(oldp+1302,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 6U))));
        bufp->chgBit(oldp+1303,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 5U))));
        bufp->chgCData(oldp+1304,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 2U))),3);
        bufp->chgBit(oldp+1305,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xdU] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xdU] >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xdU] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xdU] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xdU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1306,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1307,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 4U))));
        bufp->chgBit(oldp+1308,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 3U))));
        bufp->chgBit(oldp+1309,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 2U))));
        bufp->chgCData(oldp+1310,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1311,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1312,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1313,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0xdU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1314,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 1U)))));
        bufp->chgBit(oldp+1315,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1316,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xdU] >> 1U))));
        bufp->chgCData(oldp+1317,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0xdU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1318,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0xdU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xdU]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1319,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1320,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0xdU])));
        bufp->chgBit(oldp+1321,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1322,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1323,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1324,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1325,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1326,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1327,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1328,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1329,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1330,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1331,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1332,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1333,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1334,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1335,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1336,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1337,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1338,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1339,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1340,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1341,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1342,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1343,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1344,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1345,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1346,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1347,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1348,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1349,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1350,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1351,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1352,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1353,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0xeU]),17);
        bufp->chgSData(oldp+1354,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1355,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1356,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1357,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1358,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1359,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1360,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1361,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1362,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 0xeU))),3);
        bufp->chgBit(oldp+1363,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xeU] >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xeU] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xeU] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xeU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1364,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1365,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 0x10U))));
        bufp->chgBit(oldp+1366,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 0xfU))));
        bufp->chgBit(oldp+1367,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 0xeU))));
        bufp->chgCData(oldp+1368,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 0xbU))),3);
        bufp->chgBit(oldp+1369,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xeU] >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xeU] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xeU] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xeU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1370,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1371,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 0xdU))));
        bufp->chgBit(oldp+1372,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 0xcU))));
        bufp->chgBit(oldp+1373,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 0xbU))));
        bufp->chgCData(oldp+1374,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 8U))),3);
        bufp->chgBit(oldp+1375,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xeU] >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xeU] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xeU] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xeU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1376,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1377,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 0xaU))));
        bufp->chgBit(oldp+1378,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 9U))));
        bufp->chgBit(oldp+1379,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 8U))));
        bufp->chgCData(oldp+1380,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 5U))),3);
        bufp->chgBit(oldp+1381,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xeU] >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xeU] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xeU] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xeU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1382,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1383,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 7U))));
        bufp->chgBit(oldp+1384,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 6U))));
        bufp->chgBit(oldp+1385,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 5U))));
        bufp->chgCData(oldp+1386,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 2U))),3);
        bufp->chgBit(oldp+1387,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xeU] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xeU] >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xeU] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xeU] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xeU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1388,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1389,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 4U))));
        bufp->chgBit(oldp+1390,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 3U))));
        bufp->chgBit(oldp+1391,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 2U))));
        bufp->chgCData(oldp+1392,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1393,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1394,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1395,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0xeU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1396,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 1U)))));
        bufp->chgBit(oldp+1397,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1398,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xeU] >> 1U))));
        bufp->chgCData(oldp+1399,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0xeU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1400,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0xeU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xeU]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1401,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1402,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0xeU])));
        bufp->chgBit(oldp+1403,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1404,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1405,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1406,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1407,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1408,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1409,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1410,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1411,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1412,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1413,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1414,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1415,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1416,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1417,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1418,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1419,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1420,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1421,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1422,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1423,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1424,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1425,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1426,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1427,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1428,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1429,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1430,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1431,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1432,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1433,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1434,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1435,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0xfU]),17);
        bufp->chgSData(oldp+1436,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1437,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1438,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1439,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1440,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1441,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1442,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1443,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1444,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 0xeU))),3);
        bufp->chgBit(oldp+1445,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xfU] >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xfU] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xfU] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xfU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1446,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1447,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 0x10U))));
        bufp->chgBit(oldp+1448,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 0xfU))));
        bufp->chgBit(oldp+1449,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 0xeU))));
        bufp->chgCData(oldp+1450,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 0xbU))),3);
        bufp->chgBit(oldp+1451,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xfU] >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xfU] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xfU] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xfU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1452,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1453,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 0xdU))));
        bufp->chgBit(oldp+1454,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 0xcU))));
        bufp->chgBit(oldp+1455,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 0xbU))));
        bufp->chgCData(oldp+1456,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 8U))),3);
        bufp->chgBit(oldp+1457,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xfU] >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xfU] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xfU] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xfU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1458,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1459,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 0xaU))));
        bufp->chgBit(oldp+1460,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 9U))));
        bufp->chgBit(oldp+1461,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 8U))));
        bufp->chgCData(oldp+1462,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 5U))),3);
        bufp->chgBit(oldp+1463,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xfU] >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xfU] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xfU] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xfU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1464,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1465,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 7U))));
        bufp->chgBit(oldp+1466,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 6U))));
        bufp->chgBit(oldp+1467,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 5U))));
        bufp->chgCData(oldp+1468,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 2U))),3);
        bufp->chgBit(oldp+1469,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0xfU] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xfU] >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0xfU] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0xfU] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0xfU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1470,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1471,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 4U))));
        bufp->chgBit(oldp+1472,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 3U))));
        bufp->chgBit(oldp+1473,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 2U))));
        bufp->chgCData(oldp+1474,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1475,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1476,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1477,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0xfU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1478,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 1U)))));
        bufp->chgBit(oldp+1479,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1480,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0xfU] >> 1U))));
        bufp->chgCData(oldp+1481,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0xfU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1482,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0xfU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0xfU]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1483,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1484,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0xfU])));
        bufp->chgBit(oldp+1485,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1486,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1487,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1488,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1489,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1490,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1491,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1492,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1493,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1494,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1495,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1496,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1497,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1498,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1499,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1500,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1501,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1502,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1503,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1504,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1505,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1506,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1507,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1508,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1509,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1510,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1511,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1512,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1513,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1514,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1515,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1516,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1517,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x10U]),17);
        bufp->chgSData(oldp+1518,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1519,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1520,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1521,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1522,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1523,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1524,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1525,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1526,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 0xeU))),3);
        bufp->chgBit(oldp+1527,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x10U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x10U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x10U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x10U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1528,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1529,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 0x10U))));
        bufp->chgBit(oldp+1530,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 0xfU))));
        bufp->chgBit(oldp+1531,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 0xeU))));
        bufp->chgCData(oldp+1532,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 0xbU))),3);
        bufp->chgBit(oldp+1533,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x10U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x10U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x10U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x10U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1534,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1535,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 0xdU))));
        bufp->chgBit(oldp+1536,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 0xcU))));
        bufp->chgBit(oldp+1537,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 0xbU))));
        bufp->chgCData(oldp+1538,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 8U))),3);
        bufp->chgBit(oldp+1539,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x10U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x10U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x10U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x10U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1540,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1541,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 0xaU))));
        bufp->chgBit(oldp+1542,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 9U))));
        bufp->chgBit(oldp+1543,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 8U))));
        bufp->chgCData(oldp+1544,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 5U))),3);
        bufp->chgBit(oldp+1545,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x10U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x10U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x10U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x10U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1546,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1547,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 7U))));
        bufp->chgBit(oldp+1548,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 6U))));
        bufp->chgBit(oldp+1549,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 5U))));
        bufp->chgCData(oldp+1550,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 2U))),3);
        bufp->chgBit(oldp+1551,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x10U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x10U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x10U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x10U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x10U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1552,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1553,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 4U))));
        bufp->chgBit(oldp+1554,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 3U))));
        bufp->chgBit(oldp+1555,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 2U))));
        bufp->chgCData(oldp+1556,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1557,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1558,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1559,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x10U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1560,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 1U)))));
        bufp->chgBit(oldp+1561,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1562,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x10U] >> 1U))));
        bufp->chgCData(oldp+1563,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x10U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1564,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x10U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x10U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1565,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1566,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x10U])));
        bufp->chgBit(oldp+1567,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1568,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1569,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1570,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1571,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1572,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1573,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1574,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1575,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1576,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1577,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1578,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1579,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1580,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1581,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1582,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1583,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1584,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1585,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1586,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1587,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1588,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1589,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1590,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1591,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1592,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1593,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1594,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1595,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1596,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1597,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1598,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1599,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x11U]),17);
        bufp->chgSData(oldp+1600,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1601,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1602,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1603,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1604,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1605,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1606,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1607,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1608,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 0xeU))),3);
        bufp->chgBit(oldp+1609,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x11U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x11U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x11U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x11U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1610,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1611,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 0x10U))));
        bufp->chgBit(oldp+1612,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 0xfU))));
        bufp->chgBit(oldp+1613,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 0xeU))));
        bufp->chgCData(oldp+1614,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 0xbU))),3);
        bufp->chgBit(oldp+1615,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x11U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x11U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x11U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x11U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1616,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1617,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 0xdU))));
        bufp->chgBit(oldp+1618,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 0xcU))));
        bufp->chgBit(oldp+1619,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 0xbU))));
        bufp->chgCData(oldp+1620,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 8U))),3);
        bufp->chgBit(oldp+1621,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x11U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x11U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x11U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x11U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1622,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1623,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 0xaU))));
        bufp->chgBit(oldp+1624,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 9U))));
        bufp->chgBit(oldp+1625,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 8U))));
        bufp->chgCData(oldp+1626,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 5U))),3);
        bufp->chgBit(oldp+1627,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x11U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x11U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x11U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x11U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1628,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1629,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 7U))));
        bufp->chgBit(oldp+1630,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 6U))));
        bufp->chgBit(oldp+1631,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 5U))));
        bufp->chgCData(oldp+1632,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 2U))),3);
        bufp->chgBit(oldp+1633,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x11U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x11U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x11U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x11U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x11U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1634,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1635,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 4U))));
        bufp->chgBit(oldp+1636,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 3U))));
        bufp->chgBit(oldp+1637,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 2U))));
        bufp->chgCData(oldp+1638,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1639,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1640,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1641,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x11U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1642,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 1U)))));
        bufp->chgBit(oldp+1643,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1644,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x11U] >> 1U))));
        bufp->chgCData(oldp+1645,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x11U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1646,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x11U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x11U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1647,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1648,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x11U])));
        bufp->chgBit(oldp+1649,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1650,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1651,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1652,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1653,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1654,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1655,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1656,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1657,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1658,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1659,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1660,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1661,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1662,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1663,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1664,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1665,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1666,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1667,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1668,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1669,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1670,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1671,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1672,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1673,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1674,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1675,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1676,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1677,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1678,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1679,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1680,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1681,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x12U]),17);
        bufp->chgSData(oldp+1682,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1683,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1684,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1685,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1686,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1687,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1688,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1689,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1690,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 0xeU))),3);
        bufp->chgBit(oldp+1691,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x12U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x12U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x12U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x12U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1692,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1693,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 0x10U))));
        bufp->chgBit(oldp+1694,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 0xfU))));
        bufp->chgBit(oldp+1695,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 0xeU))));
        bufp->chgCData(oldp+1696,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 0xbU))),3);
        bufp->chgBit(oldp+1697,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x12U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x12U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x12U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x12U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1698,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1699,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 0xdU))));
        bufp->chgBit(oldp+1700,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 0xcU))));
        bufp->chgBit(oldp+1701,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 0xbU))));
        bufp->chgCData(oldp+1702,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 8U))),3);
        bufp->chgBit(oldp+1703,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x12U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x12U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x12U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x12U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1704,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1705,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 0xaU))));
        bufp->chgBit(oldp+1706,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 9U))));
        bufp->chgBit(oldp+1707,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 8U))));
        bufp->chgCData(oldp+1708,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 5U))),3);
        bufp->chgBit(oldp+1709,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x12U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x12U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x12U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x12U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1710,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1711,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 7U))));
        bufp->chgBit(oldp+1712,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 6U))));
        bufp->chgBit(oldp+1713,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 5U))));
        bufp->chgCData(oldp+1714,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 2U))),3);
        bufp->chgBit(oldp+1715,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x12U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x12U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x12U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x12U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x12U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1716,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1717,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 4U))));
        bufp->chgBit(oldp+1718,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 3U))));
        bufp->chgBit(oldp+1719,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 2U))));
        bufp->chgCData(oldp+1720,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1721,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1722,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1723,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x12U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1724,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 1U)))));
        bufp->chgBit(oldp+1725,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1726,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x12U] >> 1U))));
        bufp->chgCData(oldp+1727,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x12U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1728,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x12U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x12U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1729,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1730,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x12U])));
        bufp->chgBit(oldp+1731,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1732,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1733,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1734,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1735,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1736,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1737,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1738,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1739,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1740,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1741,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1742,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1743,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1744,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1745,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1746,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1747,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1748,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1749,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1750,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1751,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1752,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1753,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1754,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1755,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1756,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1757,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1758,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1759,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1760,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1761,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1762,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1763,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x13U]),17);
        bufp->chgSData(oldp+1764,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1765,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1766,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1767,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1768,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1769,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1770,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1771,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1772,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 0xeU))),3);
        bufp->chgBit(oldp+1773,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x13U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x13U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x13U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x13U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1774,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1775,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 0x10U))));
        bufp->chgBit(oldp+1776,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 0xfU))));
        bufp->chgBit(oldp+1777,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 0xeU))));
        bufp->chgCData(oldp+1778,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 0xbU))),3);
        bufp->chgBit(oldp+1779,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x13U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x13U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x13U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x13U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1780,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1781,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 0xdU))));
        bufp->chgBit(oldp+1782,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 0xcU))));
        bufp->chgBit(oldp+1783,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 0xbU))));
        bufp->chgCData(oldp+1784,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 8U))),3);
        bufp->chgBit(oldp+1785,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x13U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x13U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x13U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x13U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1786,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1787,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 0xaU))));
        bufp->chgBit(oldp+1788,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 9U))));
        bufp->chgBit(oldp+1789,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 8U))));
        bufp->chgCData(oldp+1790,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 5U))),3);
        bufp->chgBit(oldp+1791,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x13U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x13U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x13U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x13U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1792,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1793,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 7U))));
        bufp->chgBit(oldp+1794,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 6U))));
        bufp->chgBit(oldp+1795,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 5U))));
        bufp->chgCData(oldp+1796,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 2U))),3);
        bufp->chgBit(oldp+1797,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x13U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x13U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x13U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x13U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x13U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1798,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1799,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 4U))));
        bufp->chgBit(oldp+1800,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 3U))));
        bufp->chgBit(oldp+1801,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 2U))));
        bufp->chgCData(oldp+1802,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1803,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1804,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1805,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x13U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1806,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 1U)))));
        bufp->chgBit(oldp+1807,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1808,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x13U] >> 1U))));
        bufp->chgCData(oldp+1809,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x13U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1810,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x13U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x13U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1811,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1812,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x13U])));
        bufp->chgBit(oldp+1813,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1814,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1815,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1816,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1817,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1818,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1819,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1820,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1821,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1822,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1823,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1824,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1825,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1826,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1827,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1828,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1829,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1830,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1831,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1832,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1833,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1834,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1835,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1836,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1837,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1838,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1839,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1840,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1841,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1842,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1843,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1844,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1845,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x14U]),17);
        bufp->chgSData(oldp+1846,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1847,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1848,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1849,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1850,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1851,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1852,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1853,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1854,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 0xeU))),3);
        bufp->chgBit(oldp+1855,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x14U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x14U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x14U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x14U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1856,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1857,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 0x10U))));
        bufp->chgBit(oldp+1858,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 0xfU))));
        bufp->chgBit(oldp+1859,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 0xeU))));
        bufp->chgCData(oldp+1860,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 0xbU))),3);
        bufp->chgBit(oldp+1861,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x14U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x14U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x14U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x14U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1862,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1863,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 0xdU))));
        bufp->chgBit(oldp+1864,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 0xcU))));
        bufp->chgBit(oldp+1865,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 0xbU))));
        bufp->chgCData(oldp+1866,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 8U))),3);
        bufp->chgBit(oldp+1867,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x14U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x14U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x14U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x14U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1868,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1869,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 0xaU))));
        bufp->chgBit(oldp+1870,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 9U))));
        bufp->chgBit(oldp+1871,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 8U))));
        bufp->chgCData(oldp+1872,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 5U))),3);
        bufp->chgBit(oldp+1873,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x14U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x14U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x14U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x14U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1874,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1875,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 7U))));
        bufp->chgBit(oldp+1876,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 6U))));
        bufp->chgBit(oldp+1877,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 5U))));
        bufp->chgCData(oldp+1878,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 2U))),3);
        bufp->chgBit(oldp+1879,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x14U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x14U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x14U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x14U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x14U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1880,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1881,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 4U))));
        bufp->chgBit(oldp+1882,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 3U))));
        bufp->chgBit(oldp+1883,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 2U))));
        bufp->chgCData(oldp+1884,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1885,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1886,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1887,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x14U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1888,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 1U)))));
        bufp->chgBit(oldp+1889,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1890,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x14U] >> 1U))));
        bufp->chgCData(oldp+1891,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x14U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1892,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x14U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x14U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1893,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1894,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x14U])));
        bufp->chgBit(oldp+1895,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1896,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1897,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1898,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1899,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1900,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1901,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1902,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1903,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1904,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1905,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1906,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1907,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1908,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1909,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1910,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1911,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1912,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1913,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1914,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1915,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1916,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1917,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1918,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1919,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1920,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1921,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1922,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1923,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1924,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1925,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1926,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1927,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x15U]),17);
        bufp->chgSData(oldp+1928,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1929,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1930,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1931,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1932,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1933,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1934,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1935,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1936,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 0xeU))),3);
        bufp->chgBit(oldp+1937,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x15U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x15U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x15U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x15U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1938,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1939,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 0x10U))));
        bufp->chgBit(oldp+1940,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 0xfU))));
        bufp->chgBit(oldp+1941,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 0xeU))));
        bufp->chgCData(oldp+1942,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 0xbU))),3);
        bufp->chgBit(oldp+1943,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x15U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x15U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x15U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x15U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1944,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1945,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 0xdU))));
        bufp->chgBit(oldp+1946,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 0xcU))));
        bufp->chgBit(oldp+1947,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 0xbU))));
        bufp->chgCData(oldp+1948,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 8U))),3);
        bufp->chgBit(oldp+1949,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x15U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x15U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x15U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x15U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1950,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1951,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 0xaU))));
        bufp->chgBit(oldp+1952,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 9U))));
        bufp->chgBit(oldp+1953,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 8U))));
        bufp->chgCData(oldp+1954,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 5U))),3);
        bufp->chgBit(oldp+1955,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x15U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x15U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x15U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x15U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1956,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1957,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 7U))));
        bufp->chgBit(oldp+1958,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 6U))));
        bufp->chgBit(oldp+1959,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 5U))));
        bufp->chgCData(oldp+1960,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 2U))),3);
        bufp->chgBit(oldp+1961,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x15U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x15U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x15U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x15U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x15U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1962,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1963,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 4U))));
        bufp->chgBit(oldp+1964,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 3U))));
        bufp->chgBit(oldp+1965,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 2U))));
        bufp->chgCData(oldp+1966,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1967,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1968,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1969,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x15U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1970,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 1U)))));
        bufp->chgBit(oldp+1971,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1972,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x15U] >> 1U))));
        bufp->chgCData(oldp+1973,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x15U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1974,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x15U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x15U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1975,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1976,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x15U])));
        bufp->chgBit(oldp+1977,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1978,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1979,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1980,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1981,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1982,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1983,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1984,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1985,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1986,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1987,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1988,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1989,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1990,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1991,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1992,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1993,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1994,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1995,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1996,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1997,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1998,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1999,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2000,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2001,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2002,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2003,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2004,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2005,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2006,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2007,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2008,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2009,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x16U]),17);
        bufp->chgSData(oldp+2010,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2011,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2012,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2013,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2014,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2015,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2016,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2017,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2018,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 0xeU))),3);
        bufp->chgBit(oldp+2019,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x16U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x16U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x16U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x16U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2020,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2021,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 0x10U))));
        bufp->chgBit(oldp+2022,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 0xfU))));
        bufp->chgBit(oldp+2023,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 0xeU))));
        bufp->chgCData(oldp+2024,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 0xbU))),3);
        bufp->chgBit(oldp+2025,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x16U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x16U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x16U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x16U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2026,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2027,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 0xdU))));
        bufp->chgBit(oldp+2028,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 0xcU))));
        bufp->chgBit(oldp+2029,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 0xbU))));
        bufp->chgCData(oldp+2030,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 8U))),3);
        bufp->chgBit(oldp+2031,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x16U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x16U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x16U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x16U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2032,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2033,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 0xaU))));
        bufp->chgBit(oldp+2034,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 9U))));
        bufp->chgBit(oldp+2035,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 8U))));
        bufp->chgCData(oldp+2036,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 5U))),3);
        bufp->chgBit(oldp+2037,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x16U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x16U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x16U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x16U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2038,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2039,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 7U))));
        bufp->chgBit(oldp+2040,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 6U))));
        bufp->chgBit(oldp+2041,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 5U))));
        bufp->chgCData(oldp+2042,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 2U))),3);
        bufp->chgBit(oldp+2043,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x16U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x16U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x16U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x16U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x16U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2044,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2045,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 4U))));
        bufp->chgBit(oldp+2046,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 3U))));
        bufp->chgBit(oldp+2047,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 2U))));
        bufp->chgCData(oldp+2048,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2049,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2050,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2051,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x16U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2052,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 1U)))));
        bufp->chgBit(oldp+2053,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2054,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x16U] >> 1U))));
        bufp->chgCData(oldp+2055,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x16U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2056,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x16U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x16U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2057,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2058,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x16U])));
        bufp->chgBit(oldp+2059,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2060,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2061,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2062,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2063,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2064,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2065,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2066,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2067,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2068,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2069,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2070,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2071,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2072,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2073,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2074,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2075,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2076,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2077,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2078,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2079,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2080,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2081,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2082,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2083,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2084,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2085,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2086,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2087,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2088,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2089,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2090,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2091,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x17U]),17);
        bufp->chgSData(oldp+2092,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2093,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2094,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2095,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2096,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2097,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2098,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2099,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2100,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 0xeU))),3);
        bufp->chgBit(oldp+2101,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x17U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x17U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x17U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x17U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2102,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2103,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 0x10U))));
        bufp->chgBit(oldp+2104,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 0xfU))));
        bufp->chgBit(oldp+2105,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 0xeU))));
        bufp->chgCData(oldp+2106,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 0xbU))),3);
        bufp->chgBit(oldp+2107,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x17U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x17U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x17U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x17U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2108,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2109,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 0xdU))));
        bufp->chgBit(oldp+2110,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 0xcU))));
        bufp->chgBit(oldp+2111,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 0xbU))));
        bufp->chgCData(oldp+2112,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 8U))),3);
        bufp->chgBit(oldp+2113,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x17U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x17U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x17U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x17U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2114,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2115,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 0xaU))));
        bufp->chgBit(oldp+2116,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 9U))));
        bufp->chgBit(oldp+2117,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 8U))));
        bufp->chgCData(oldp+2118,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 5U))),3);
        bufp->chgBit(oldp+2119,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x17U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x17U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x17U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x17U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2120,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2121,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 7U))));
        bufp->chgBit(oldp+2122,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 6U))));
        bufp->chgBit(oldp+2123,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 5U))));
        bufp->chgCData(oldp+2124,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 2U))),3);
        bufp->chgBit(oldp+2125,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x17U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x17U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x17U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x17U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x17U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2126,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2127,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 4U))));
        bufp->chgBit(oldp+2128,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 3U))));
        bufp->chgBit(oldp+2129,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 2U))));
        bufp->chgCData(oldp+2130,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2131,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2132,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2133,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x17U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2134,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 1U)))));
        bufp->chgBit(oldp+2135,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2136,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x17U] >> 1U))));
        bufp->chgCData(oldp+2137,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x17U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2138,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x17U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x17U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2139,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2140,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x17U])));
        bufp->chgBit(oldp+2141,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2142,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2143,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2144,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2145,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2146,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2147,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2148,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2149,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2150,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2151,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2152,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2153,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2154,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2155,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2156,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2157,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2158,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2159,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2160,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2161,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2162,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2163,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2164,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2165,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2166,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2167,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2168,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2169,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2170,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2171,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2172,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2173,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x18U]),17);
        bufp->chgSData(oldp+2174,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2175,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2176,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2177,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2178,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2179,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2180,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2181,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2182,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 0xeU))),3);
        bufp->chgBit(oldp+2183,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x18U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x18U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x18U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x18U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2184,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2185,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 0x10U))));
        bufp->chgBit(oldp+2186,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 0xfU))));
        bufp->chgBit(oldp+2187,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 0xeU))));
        bufp->chgCData(oldp+2188,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 0xbU))),3);
        bufp->chgBit(oldp+2189,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x18U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x18U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x18U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x18U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2190,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2191,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 0xdU))));
        bufp->chgBit(oldp+2192,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 0xcU))));
        bufp->chgBit(oldp+2193,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 0xbU))));
        bufp->chgCData(oldp+2194,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 8U))),3);
        bufp->chgBit(oldp+2195,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x18U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x18U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x18U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x18U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2196,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2197,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 0xaU))));
        bufp->chgBit(oldp+2198,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 9U))));
        bufp->chgBit(oldp+2199,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 8U))));
        bufp->chgCData(oldp+2200,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 5U))),3);
        bufp->chgBit(oldp+2201,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x18U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x18U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x18U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x18U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2202,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2203,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 7U))));
        bufp->chgBit(oldp+2204,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 6U))));
        bufp->chgBit(oldp+2205,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 5U))));
        bufp->chgCData(oldp+2206,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 2U))),3);
        bufp->chgBit(oldp+2207,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x18U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x18U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x18U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x18U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x18U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2208,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2209,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 4U))));
        bufp->chgBit(oldp+2210,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 3U))));
        bufp->chgBit(oldp+2211,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 2U))));
        bufp->chgCData(oldp+2212,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2213,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2214,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2215,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x18U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2216,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 1U)))));
        bufp->chgBit(oldp+2217,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2218,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x18U] >> 1U))));
        bufp->chgCData(oldp+2219,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x18U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2220,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x18U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x18U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2221,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2222,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x18U])));
        bufp->chgBit(oldp+2223,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2224,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2225,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2226,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2227,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2228,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2229,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2230,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2231,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2232,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2233,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2234,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2235,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2236,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2237,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2238,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2239,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2240,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2241,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2242,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2243,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2244,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2245,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2246,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2247,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2248,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2249,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2250,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2251,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2252,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2253,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2254,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2255,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x19U]),17);
        bufp->chgSData(oldp+2256,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2257,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2258,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2259,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2260,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2261,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2262,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2263,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2264,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 0xeU))),3);
        bufp->chgBit(oldp+2265,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x19U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x19U] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x19U] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x19U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2266,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2267,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 0x10U))));
        bufp->chgBit(oldp+2268,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 0xfU))));
        bufp->chgBit(oldp+2269,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 0xeU))));
        bufp->chgCData(oldp+2270,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 0xbU))),3);
        bufp->chgBit(oldp+2271,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x19U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x19U] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x19U] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x19U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2272,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2273,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 0xdU))));
        bufp->chgBit(oldp+2274,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 0xcU))));
        bufp->chgBit(oldp+2275,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 0xbU))));
        bufp->chgCData(oldp+2276,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 8U))),3);
        bufp->chgBit(oldp+2277,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x19U] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x19U] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x19U] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x19U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2278,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2279,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 0xaU))));
        bufp->chgBit(oldp+2280,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 9U))));
        bufp->chgBit(oldp+2281,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 8U))));
        bufp->chgCData(oldp+2282,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 5U))),3);
        bufp->chgBit(oldp+2283,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x19U] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x19U] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x19U] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x19U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2284,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2285,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 7U))));
        bufp->chgBit(oldp+2286,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 6U))));
        bufp->chgBit(oldp+2287,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 5U))));
        bufp->chgCData(oldp+2288,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 2U))),3);
        bufp->chgBit(oldp+2289,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x19U] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x19U] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x19U] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x19U] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x19U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2290,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2291,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 4U))));
        bufp->chgBit(oldp+2292,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 3U))));
        bufp->chgBit(oldp+2293,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 2U))));
        bufp->chgCData(oldp+2294,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2295,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2296,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2297,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x19U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2298,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 1U)))));
        bufp->chgBit(oldp+2299,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2300,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x19U] >> 1U))));
        bufp->chgCData(oldp+2301,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x19U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2302,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x19U] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x19U]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2303,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2304,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x19U])));
        bufp->chgBit(oldp+2305,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2306,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2307,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2308,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2309,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2310,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2311,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2312,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2313,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2314,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2315,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2316,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2317,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2318,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2319,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2320,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2321,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2322,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2323,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2324,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2325,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2326,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2327,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2328,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2329,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2330,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2331,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2332,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2333,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2334,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2335,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2336,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2337,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x1aU]),17);
        bufp->chgSData(oldp+2338,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2339,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2340,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2341,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2342,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2343,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2344,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2345,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2346,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 0xeU))),3);
        bufp->chgBit(oldp+2347,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 0x10U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 0xfU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 0x10U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2348,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2349,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 0x10U))));
        bufp->chgBit(oldp+2350,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 0xfU))));
        bufp->chgBit(oldp+2351,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 0xeU))));
        bufp->chgCData(oldp+2352,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 0xbU))),3);
        bufp->chgBit(oldp+2353,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 0xdU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 0xcU) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 0xdU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2354,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2355,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 0xdU))));
        bufp->chgBit(oldp+2356,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 0xcU))));
        bufp->chgBit(oldp+2357,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 0xbU))));
        bufp->chgCData(oldp+2358,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 8U))),3);
        bufp->chgBit(oldp+2359,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 0xaU) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 9U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 9U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 0xaU)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2360,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2361,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 0xaU))));
        bufp->chgBit(oldp+2362,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 9U))));
        bufp->chgBit(oldp+2363,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 8U))));
        bufp->chgCData(oldp+2364,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 5U))),3);
        bufp->chgBit(oldp+2365,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 7U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 6U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 6U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 7U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2366,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2367,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 7U))));
        bufp->chgBit(oldp+2368,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 6U))));
        bufp->chgBit(oldp+2369,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 5U))));
        bufp->chgCData(oldp+2370,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 2U))),3);
        bufp->chgBit(oldp+2371,((1U & (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1aU] >> 4U) 
                                        & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 3U)) 
                                       | (((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 3U) 
                                           | (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 4U)) 
                                          & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2372,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2373,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 4U))));
        bufp->chgBit(oldp+2374,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 3U))));
        bufp->chgBit(oldp+2375,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 2U))));
        bufp->chgCData(oldp+2376,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2377,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2378,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2379,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                                    [0x1aU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2380,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 1U)))));
        bufp->chgBit(oldp+2381,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2382,((1U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                       [0x1aU] >> 1U))));
        bufp->chgCData(oldp+2383,(((4U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                          [0x1aU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2384,((1U & ((vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                        [0x1aU] & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                           [0x1aU]) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2385,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2386,((1U & vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                 [0x1aU])));
        bufp->chgBit(oldp+2387,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2388,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2389,((7U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2390,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2391,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2392,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2393,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2394,((1U & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2395,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2396,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2397,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2398,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2399,((1U & (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2400,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2401,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2402,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2403,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2404,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2405,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2406,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2407,((7U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2408,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2409,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2410,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2411,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2412,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2413,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2414,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2415,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2416,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2417,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2418,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2419,(vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                  [0x1bU]),17);
        bufp->chgSData(oldp+2420,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2421,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2422,((1U & ((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2423,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2424,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2425,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2426,((((IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2427,(vlSymsp->TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2428,((7U & (vlSelf->fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__switch_outputs
                                         [0x1bU] >> 0xeU))),3);
    }
}
