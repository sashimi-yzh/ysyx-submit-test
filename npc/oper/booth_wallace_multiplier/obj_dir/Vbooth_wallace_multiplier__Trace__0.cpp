// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbooth_wallace_multiplier__Syms.h"


void Vbooth_wallace_multiplier___024root__trace_chg_sub_0(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp);
void Vbooth_wallace_multiplier___024root__trace_chg_sub_1(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp);
void Vbooth_wallace_multiplier___024root__trace_chg_sub_2(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vbooth_wallace_multiplier___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root__trace_chg_top_0\n"); );
    // Init
    Vbooth_wallace_multiplier___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbooth_wallace_multiplier___024root*>(voidSelf);
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vbooth_wallace_multiplier___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
    Vbooth_wallace_multiplier___024root__trace_chg_sub_1((&vlSymsp->TOP), bufp);
    Vbooth_wallace_multiplier___024root__trace_chg_sub_2((&vlSymsp->TOP), bufp);
}

void Vbooth_wallace_multiplier___024root__trace_chg_sub_0(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_ha87ffc53__0;
    VlWide<3>/*95:0*/ __Vtemp_h967afc56__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffcbd__0;
    VlWide<3>/*95:0*/ __Vtemp_h8bc35bff__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801956__0;
    VlWide<3>/*95:0*/ __Vtemp_h62ba4d10__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88015cc__0;
    VlWide<3>/*95:0*/ __Vtemp_he90806d9__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801651__0;
    VlWide<3>/*95:0*/ __Vtemp_h13c1414b__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88016d7__0;
    VlWide<3>/*95:0*/ __Vtemp_h6b93f5cc__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8806394__0;
    VlWide<3>/*95:0*/ __Vtemp_h7d4c5750__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807036__0;
    VlWide<3>/*95:0*/ __Vtemp_h6a340998__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88070b7__0;
    VlWide<3>/*95:0*/ __Vtemp_hcadd6371__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807131__0;
    VlWide<3>/*95:0*/ __Vtemp_h1c54c8f3__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804db2__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87baff2__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804a38__0;
    VlWide<3>/*95:0*/ __Vtemp_hafa259bf__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804ab5__0;
    VlWide<3>/*95:0*/ __Vtemp_h904468fe__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804b2b__0;
    VlWide<3>/*95:0*/ __Vtemp_h7aeed49f__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801740__0;
    VlWide<3>/*95:0*/ __Vtemp_ha29b949d__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffbba__0;
    VlWide<3>/*95:0*/ __Vtemp_h378e06f7__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgWData(oldp+0,(vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext),68);
        bufp->chgQData(oldp+3,(vlSelf->booth_wallace_multiplier__DOT__multiplier_ext),35);
        bufp->chgWData(oldp+5,(vlSelf->booth_wallace_multiplier__DOT__partial_products[0]),68);
        bufp->chgWData(oldp+8,(vlSelf->booth_wallace_multiplier__DOT__partial_products[1]),68);
        bufp->chgWData(oldp+11,(vlSelf->booth_wallace_multiplier__DOT__partial_products[2]),68);
        bufp->chgWData(oldp+14,(vlSelf->booth_wallace_multiplier__DOT__partial_products[3]),68);
        bufp->chgWData(oldp+17,(vlSelf->booth_wallace_multiplier__DOT__partial_products[4]),68);
        bufp->chgWData(oldp+20,(vlSelf->booth_wallace_multiplier__DOT__partial_products[5]),68);
        bufp->chgWData(oldp+23,(vlSelf->booth_wallace_multiplier__DOT__partial_products[6]),68);
        bufp->chgWData(oldp+26,(vlSelf->booth_wallace_multiplier__DOT__partial_products[7]),68);
        bufp->chgWData(oldp+29,(vlSelf->booth_wallace_multiplier__DOT__partial_products[8]),68);
        bufp->chgWData(oldp+32,(vlSelf->booth_wallace_multiplier__DOT__partial_products[9]),68);
        bufp->chgWData(oldp+35,(vlSelf->booth_wallace_multiplier__DOT__partial_products[10]),68);
        bufp->chgWData(oldp+38,(vlSelf->booth_wallace_multiplier__DOT__partial_products[11]),68);
        bufp->chgWData(oldp+41,(vlSelf->booth_wallace_multiplier__DOT__partial_products[12]),68);
        bufp->chgWData(oldp+44,(vlSelf->booth_wallace_multiplier__DOT__partial_products[13]),68);
        bufp->chgWData(oldp+47,(vlSelf->booth_wallace_multiplier__DOT__partial_products[14]),68);
        bufp->chgWData(oldp+50,(vlSelf->booth_wallace_multiplier__DOT__partial_products[15]),68);
        bufp->chgWData(oldp+53,(vlSelf->booth_wallace_multiplier__DOT__partial_products[16]),68);
        bufp->chgWData(oldp+56,(vlSelf->booth_wallace_multiplier__DOT__cout2),68);
        bufp->chgWData(oldp+59,(vlSelf->booth_wallace_multiplier__DOT__s),68);
        bufp->chgCData(oldp+62,((7U & (IData)(vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))),3);
        bufp->chgBit(oldp+63,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                        >> 2U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hed3c5934__0))));
        bufp->chgBit(oldp+64,((1U & ((~ ((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                  >> 1U)) 
                                         | (IData)(vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) 
                                     & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 2U))))));
        bufp->chgBit(oldp+65,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                           >> 2U))) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hed3c5934__0))));
        bufp->chgBit(oldp+66,((IData)((3ULL == (7ULL 
                                                & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+67,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                               >> 0x14U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffc53__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x14U);
        __Vtemp_h967afc56__0[0U] = __Vtemp_ha87ffc53__0[0U];
        __Vtemp_h967afc56__0[1U] = __Vtemp_ha87ffc53__0[1U];
        __Vtemp_h967afc56__0[2U] = (0xfU & __Vtemp_ha87ffc53__0[2U]);
        bufp->chgWData(oldp+68,(__Vtemp_h967afc56__0),68);
        bufp->chgBit(oldp+71,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                        >> 0x16U)) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8cb8ba8a__0))));
        bufp->chgBit(oldp+72,((1U & ((~ (IData)((0ULL 
                                                 != 
                                                 (0x300000ULL 
                                                  & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                     & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x16U))))));
        bufp->chgBit(oldp+73,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                           >> 0x16U))) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8cb8ba8a__0))));
        bufp->chgBit(oldp+74,((IData)((0x300000ULL 
                                       == (0x700000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+75,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                               >> 0x16U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffcbd__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x16U);
        __Vtemp_h8bc35bff__0[0U] = __Vtemp_ha87ffcbd__0[0U];
        __Vtemp_h8bc35bff__0[1U] = __Vtemp_ha87ffcbd__0[1U];
        __Vtemp_h8bc35bff__0[2U] = (0xfU & __Vtemp_ha87ffcbd__0[2U]);
        bufp->chgWData(oldp+76,(__Vtemp_h8bc35bff__0),68);
        bufp->chgBit(oldp+79,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                        >> 0x18U)) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc18fac15__0))));
        bufp->chgBit(oldp+80,((1U & ((~ (IData)((0ULL 
                                                 != 
                                                 (0xc00000ULL 
                                                  & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                     & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x18U))))));
        bufp->chgBit(oldp+81,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                           >> 0x18U))) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc18fac15__0))));
        bufp->chgBit(oldp+82,((IData)((0xc00000ULL 
                                       == (0x1c00000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+83,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                               >> 0x18U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801956__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x18U);
        __Vtemp_h62ba4d10__0[0U] = __Vtemp_ha8801956__0[0U];
        __Vtemp_h62ba4d10__0[1U] = __Vtemp_ha8801956__0[1U];
        __Vtemp_h62ba4d10__0[2U] = (0xfU & __Vtemp_ha8801956__0[2U]);
        bufp->chgWData(oldp+84,(__Vtemp_h62ba4d10__0),68);
        bufp->chgBit(oldp+87,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                        >> 0x1aU)) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc411b621__0))));
        bufp->chgBit(oldp+88,((1U & ((~ (IData)((0ULL 
                                                 != 
                                                 (0x3000000ULL 
                                                  & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                     & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x1aU))))));
        bufp->chgBit(oldp+89,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                           >> 0x1aU))) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc411b621__0))));
        bufp->chgBit(oldp+90,((IData)((0x3000000ULL 
                                       == (0x7000000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+91,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                               >> 0x1aU)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88015cc__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1aU);
        __Vtemp_he90806d9__0[0U] = __Vtemp_ha88015cc__0[0U];
        __Vtemp_he90806d9__0[1U] = __Vtemp_ha88015cc__0[1U];
        __Vtemp_he90806d9__0[2U] = (0xfU & __Vtemp_ha88015cc__0[2U]);
        bufp->chgWData(oldp+92,(__Vtemp_he90806d9__0),68);
        bufp->chgBit(oldp+95,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                        >> 0x1cU)) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hcef34518__0))));
        bufp->chgBit(oldp+96,((1U & ((~ (IData)((0ULL 
                                                 != 
                                                 (0xc000000ULL 
                                                  & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                     & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x1cU))))));
        bufp->chgBit(oldp+97,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                           >> 0x1cU))) 
                               & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hcef34518__0))));
        bufp->chgBit(oldp+98,((IData)((0xc000000ULL 
                                       == (0x1c000000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+99,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                               >> 0x1cU)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801651__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1cU);
        __Vtemp_h13c1414b__0[0U] = __Vtemp_ha8801651__0[0U];
        __Vtemp_h13c1414b__0[1U] = __Vtemp_ha8801651__0[1U];
        __Vtemp_h13c1414b__0[2U] = (0xfU & __Vtemp_ha8801651__0[2U]);
        bufp->chgWData(oldp+100,(__Vtemp_h13c1414b__0),68);
        bufp->chgBit(oldp+103,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0x1eU)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h91e9dc0e__0))));
        bufp->chgBit(oldp+104,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0x30000000ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0x1eU))))));
        bufp->chgBit(oldp+105,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0x1eU))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h91e9dc0e__0))));
        bufp->chgBit(oldp+106,((IData)((0x30000000ULL 
                                        == (0x70000000ULL 
                                            & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+107,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x1eU)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88016d7__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1eU);
        __Vtemp_h6b93f5cc__0[0U] = __Vtemp_ha88016d7__0[0U];
        __Vtemp_h6b93f5cc__0[1U] = __Vtemp_ha88016d7__0[1U];
        __Vtemp_h6b93f5cc__0[2U] = (0xfU & __Vtemp_ha88016d7__0[2U]);
        bufp->chgWData(oldp+108,(__Vtemp_h6b93f5cc__0),68);
        bufp->chgBit(oldp+111,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0x20U)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8fc047d7__0))));
        bufp->chgBit(oldp+112,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0xc0000000ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0x20U))))));
        bufp->chgBit(oldp+113,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0x20U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8fc047d7__0))));
        bufp->chgBit(oldp+114,((IData)((0xc0000000ULL 
                                        == (0x1c0000000ULL 
                                            & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+115,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x20U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8806394__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x20U);
        __Vtemp_h7d4c5750__0[0U] = __Vtemp_ha8806394__0[0U];
        __Vtemp_h7d4c5750__0[1U] = __Vtemp_ha8806394__0[1U];
        __Vtemp_h7d4c5750__0[2U] = (0xfU & __Vtemp_ha8806394__0[2U]);
        bufp->chgWData(oldp+116,(__Vtemp_h7d4c5750__0),68);
        bufp->chgBit(oldp+119,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0x22U)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h9b1da5a9__0))));
        bufp->chgBit(oldp+120,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0x300000000ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0x22U))))));
        bufp->chgBit(oldp+121,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0x22U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h9b1da5a9__0))));
        bufp->chgBit(oldp+122,((IData)((0x300000000ULL 
                                        == (0x700000000ULL 
                                            & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+123,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 2U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807036__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 2U);
        __Vtemp_h6a340998__0[0U] = __Vtemp_ha8807036__0[0U];
        __Vtemp_h6a340998__0[1U] = __Vtemp_ha8807036__0[1U];
        __Vtemp_h6a340998__0[2U] = (0xfU & __Vtemp_ha8807036__0[2U]);
        bufp->chgWData(oldp+124,(__Vtemp_h6a340998__0),68);
        bufp->chgBit(oldp+127,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 4U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc3505cf3__0))));
        bufp->chgBit(oldp+128,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0xcULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 4U))))));
        bufp->chgBit(oldp+129,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 4U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc3505cf3__0))));
        bufp->chgBit(oldp+130,((IData)((0xcULL == (0x1cULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+131,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 4U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88070b7__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 4U);
        __Vtemp_hcadd6371__0[0U] = __Vtemp_ha88070b7__0[0U];
        __Vtemp_hcadd6371__0[1U] = __Vtemp_ha88070b7__0[1U];
        __Vtemp_hcadd6371__0[2U] = (0xfU & __Vtemp_ha88070b7__0[2U]);
        bufp->chgWData(oldp+132,(__Vtemp_hcadd6371__0),68);
        bufp->chgBit(oldp+135,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 6U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hf9f0876d__0))));
        bufp->chgBit(oldp+136,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0x30ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 6U))))));
        bufp->chgBit(oldp+137,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 6U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hf9f0876d__0))));
        bufp->chgBit(oldp+138,((IData)((0x30ULL == 
                                        (0x70ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+139,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 6U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807131__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 6U);
        __Vtemp_h1c54c8f3__0[0U] = __Vtemp_ha8807131__0[0U];
        __Vtemp_h1c54c8f3__0[1U] = __Vtemp_ha8807131__0[1U];
        __Vtemp_h1c54c8f3__0[2U] = (0xfU & __Vtemp_ha8807131__0[2U]);
        bufp->chgWData(oldp+140,(__Vtemp_h1c54c8f3__0),68);
        bufp->chgBit(oldp+143,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 8U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hfe0a41fe__0))));
        bufp->chgBit(oldp+144,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0xc0ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 8U))))));
        bufp->chgBit(oldp+145,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 8U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hfe0a41fe__0))));
        bufp->chgBit(oldp+146,((IData)((0xc0ULL == 
                                        (0x1c0ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+147,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 8U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804db2__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 8U);
        __Vtemp_ha87baff2__0[0U] = __Vtemp_ha8804db2__0[0U];
        __Vtemp_ha87baff2__0[1U] = __Vtemp_ha8804db2__0[1U];
        __Vtemp_ha87baff2__0[2U] = (0xfU & __Vtemp_ha8804db2__0[2U]);
        bufp->chgWData(oldp+148,(__Vtemp_ha87baff2__0),68);
        bufp->chgBit(oldp+151,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0xaU)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc5e42a69__0))));
        bufp->chgBit(oldp+152,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0x300ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0xaU))))));
        bufp->chgBit(oldp+153,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0xaU))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc5e42a69__0))));
        bufp->chgBit(oldp+154,((IData)((0x300ULL == 
                                        (0x700ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+155,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0xaU)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804a38__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xaU);
        __Vtemp_hafa259bf__0[0U] = __Vtemp_ha8804a38__0[0U];
        __Vtemp_hafa259bf__0[1U] = __Vtemp_ha8804a38__0[1U];
        __Vtemp_hafa259bf__0[2U] = (0xfU & __Vtemp_ha8804a38__0[2U]);
        bufp->chgWData(oldp+156,(__Vtemp_hafa259bf__0),68);
        bufp->chgBit(oldp+159,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0xcU)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hbaa102cc__0))));
        bufp->chgBit(oldp+160,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0xc00ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0xcU))))));
        bufp->chgBit(oldp+161,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0xcU))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hbaa102cc__0))));
        bufp->chgBit(oldp+162,((IData)((0xc00ULL == 
                                        (0x1c00ULL 
                                         & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+163,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0xcU)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804ab5__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xcU);
        __Vtemp_h904468fe__0[0U] = __Vtemp_ha8804ab5__0[0U];
        __Vtemp_h904468fe__0[1U] = __Vtemp_ha8804ab5__0[1U];
        __Vtemp_h904468fe__0[2U] = (0xfU & __Vtemp_ha8804ab5__0[2U]);
        bufp->chgWData(oldp+164,(__Vtemp_h904468fe__0),68);
        bufp->chgBit(oldp+167,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0xeU)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb4e6b126__0))));
        bufp->chgBit(oldp+168,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0x3000ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0xeU))))));
        bufp->chgBit(oldp+169,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0xeU))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb4e6b126__0))));
        bufp->chgBit(oldp+170,((IData)((0x3000ULL == 
                                        (0x7000ULL 
                                         & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+171,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0xeU)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804b2b__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xeU);
        __Vtemp_h7aeed49f__0[0U] = __Vtemp_ha8804b2b__0[0U];
        __Vtemp_h7aeed49f__0[1U] = __Vtemp_ha8804b2b__0[1U];
        __Vtemp_h7aeed49f__0[2U] = (0xfU & __Vtemp_ha8804b2b__0[2U]);
        bufp->chgWData(oldp+172,(__Vtemp_h7aeed49f__0),68);
        bufp->chgBit(oldp+175,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0x10U)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_haed8dbe3__0))));
        bufp->chgBit(oldp+176,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0xc000ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0x10U))))));
        bufp->chgBit(oldp+177,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0x10U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_haed8dbe3__0))));
        bufp->chgBit(oldp+178,((IData)((0xc000ULL == 
                                        (0x1c000ULL 
                                         & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+179,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x10U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801740__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x10U);
        __Vtemp_ha29b949d__0[0U] = __Vtemp_ha8801740__0[0U];
        __Vtemp_ha29b949d__0[1U] = __Vtemp_ha8801740__0[1U];
        __Vtemp_ha29b949d__0[2U] = (0xfU & __Vtemp_ha8801740__0[2U]);
        bufp->chgWData(oldp+180,(__Vtemp_ha29b949d__0),68);
        bufp->chgBit(oldp+183,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0x12U)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb84f77ab__0))));
        bufp->chgBit(oldp+184,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0x30000ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0x12U))))));
        bufp->chgBit(oldp+185,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0x12U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb84f77ab__0))));
        bufp->chgBit(oldp+186,((IData)((0x30000ULL 
                                        == (0x70000ULL 
                                            & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgCData(oldp+187,((7U & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                >> 0x12U)))),3);
        VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffbba__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x12U);
        __Vtemp_h378e06f7__0[0U] = __Vtemp_ha87ffbba__0[0U];
        __Vtemp_h378e06f7__0[1U] = __Vtemp_ha87ffbba__0[1U];
        __Vtemp_h378e06f7__0[2U] = (0xfU & __Vtemp_ha87ffbba__0[2U]);
        bufp->chgWData(oldp+188,(__Vtemp_h378e06f7__0),68);
        bufp->chgBit(oldp+191,(((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                         >> 0x14U)) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h937272c0__0))));
        bufp->chgBit(oldp+192,((1U & ((~ (IData)((0ULL 
                                                  != 
                                                  (0xc0000ULL 
                                                   & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                                 >> 0x14U))))));
        bufp->chgBit(oldp+193,(((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                            >> 0x14U))) 
                                & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h937272c0__0))));
        bufp->chgBit(oldp+194,((IData)((0xc0000ULL 
                                        == (0x1c0000ULL 
                                            & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))));
        bufp->chgIData(oldp+195,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0U]),17);
        bufp->chgSData(oldp+196,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+197,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                      ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                         ^ vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0U])))));
        bufp->chgCData(oldp+198,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+199,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (2U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0U] 
                                                   << 1U))))),4);
        bufp->chgCData(oldp+200,((2U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                         ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                            ^ vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0U])) 
                                        << 1U))),2);
        bufp->chgCData(oldp+201,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 0xeU))),3);
        bufp->chgBit(oldp+202,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0U] >> 0xeU))))));
        bufp->chgBit(oldp+203,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+204,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 0x10U))));
        bufp->chgBit(oldp+205,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 0xfU))));
        bufp->chgBit(oldp+206,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 0xeU))));
        bufp->chgCData(oldp+207,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 0xbU))),3);
        bufp->chgBit(oldp+208,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0U] >> 0xbU))))));
        bufp->chgBit(oldp+209,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+210,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 0xdU))));
        bufp->chgBit(oldp+211,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 0xcU))));
        bufp->chgBit(oldp+212,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 0xbU))));
        bufp->chgCData(oldp+213,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 8U))),3);
        bufp->chgBit(oldp+214,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0U] >> 8U))))));
        bufp->chgBit(oldp+215,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+216,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 0xaU))));
        bufp->chgBit(oldp+217,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 9U))));
        bufp->chgBit(oldp+218,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 8U))));
        bufp->chgCData(oldp+219,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 5U))),3);
        bufp->chgBit(oldp+220,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0U] >> 5U))))));
        bufp->chgBit(oldp+221,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+222,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 7U))));
        bufp->chgBit(oldp+223,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 6U))));
        bufp->chgBit(oldp+224,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 5U))));
        bufp->chgCData(oldp+225,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 2U))),3);
        bufp->chgBit(oldp+226,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0U] >> 2U))))));
        bufp->chgBit(oldp+227,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+228,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 4U))));
        bufp->chgBit(oldp+229,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 3U))));
        bufp->chgBit(oldp+230,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 2U))));
        bufp->chgCData(oldp+231,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+232,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+233,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+234,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [0U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+235,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 1U)))));
        bufp->chgBit(oldp+236,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+237,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0U] >> 1U))));
        bufp->chgCData(oldp+238,((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0U] << 2U))),3);
        bufp->chgBit(oldp+239,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [0U])));
        bufp->chgCData(oldp+240,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (1U 
                                                & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                [0U])))),3);
        bufp->chgBit(oldp+241,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                   [0U]))));
        bufp->chgCData(oldp+242,((4U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa5__s) 
                                         ^ ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.__Vcellout__csa6__s) 
                                            ^ vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0U])) 
                                        << 2U))),3);
        bufp->chgIData(oldp+243,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [1U]),17);
        bufp->chgSData(oldp+244,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+245,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout));
        bufp->chgBit(oldp+246,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+247,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+248,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+249,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+250,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+251,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+252,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 0xeU))),3);
        bufp->chgBit(oldp+253,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [1U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [1U] >> 0xeU))))));
        bufp->chgBit(oldp+254,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+255,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 0x10U))));
        bufp->chgBit(oldp+256,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 0xfU))));
        bufp->chgBit(oldp+257,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 0xeU))));
        bufp->chgCData(oldp+258,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 0xbU))),3);
        bufp->chgBit(oldp+259,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [1U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [1U] >> 0xbU))))));
        bufp->chgBit(oldp+260,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+261,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 0xdU))));
        bufp->chgBit(oldp+262,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 0xcU))));
        bufp->chgBit(oldp+263,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 0xbU))));
        bufp->chgCData(oldp+264,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 8U))),3);
        bufp->chgBit(oldp+265,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [1U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [1U] >> 8U))))));
        bufp->chgBit(oldp+266,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+267,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 0xaU))));
        bufp->chgBit(oldp+268,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 9U))));
        bufp->chgBit(oldp+269,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 8U))));
        bufp->chgCData(oldp+270,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 5U))),3);
        bufp->chgBit(oldp+271,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [1U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [1U] >> 5U))))));
        bufp->chgBit(oldp+272,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+273,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 7U))));
        bufp->chgBit(oldp+274,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 6U))));
        bufp->chgBit(oldp+275,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 5U))));
        bufp->chgCData(oldp+276,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 2U))),3);
        bufp->chgBit(oldp+277,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [1U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [1U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [1U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [1U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [1U] >> 2U))))));
        bufp->chgBit(oldp+278,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+279,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 4U))));
        bufp->chgBit(oldp+280,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 3U))));
        bufp->chgBit(oldp+281,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 2U))));
        bufp->chgCData(oldp+282,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+283,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+284,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+285,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [1U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+286,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 1U)))));
        bufp->chgBit(oldp+287,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+288,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [1U] >> 1U))));
        bufp->chgCData(oldp+289,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [1U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+290,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [1U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [1U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+291,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+292,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [1U])));
        bufp->chgBit(oldp+293,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+294,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+295,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+296,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+297,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+298,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+299,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+300,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+301,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+302,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+303,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+304,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+305,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+306,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+307,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+308,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+309,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+310,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+311,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+312,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+313,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+314,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+315,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+316,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+317,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+318,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+319,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+320,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+321,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+322,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+323,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+324,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+325,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [2U]),17);
        bufp->chgSData(oldp+326,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+327,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout));
        bufp->chgBit(oldp+328,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+329,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+330,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+331,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+332,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+333,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+334,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 0xeU))),3);
        bufp->chgBit(oldp+335,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [2U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [2U] >> 0xeU))))));
        bufp->chgBit(oldp+336,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+337,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 0x10U))));
        bufp->chgBit(oldp+338,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 0xfU))));
        bufp->chgBit(oldp+339,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 0xeU))));
        bufp->chgCData(oldp+340,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 0xbU))),3);
        bufp->chgBit(oldp+341,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [2U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [2U] >> 0xbU))))));
        bufp->chgBit(oldp+342,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+343,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 0xdU))));
        bufp->chgBit(oldp+344,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 0xcU))));
        bufp->chgBit(oldp+345,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 0xbU))));
        bufp->chgCData(oldp+346,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 8U))),3);
        bufp->chgBit(oldp+347,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [2U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [2U] >> 8U))))));
        bufp->chgBit(oldp+348,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+349,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 0xaU))));
        bufp->chgBit(oldp+350,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 9U))));
        bufp->chgBit(oldp+351,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 8U))));
        bufp->chgCData(oldp+352,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 5U))),3);
        bufp->chgBit(oldp+353,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [2U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [2U] >> 5U))))));
        bufp->chgBit(oldp+354,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+355,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 7U))));
        bufp->chgBit(oldp+356,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 6U))));
        bufp->chgBit(oldp+357,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 5U))));
        bufp->chgCData(oldp+358,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 2U))),3);
        bufp->chgBit(oldp+359,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [2U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [2U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [2U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [2U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [2U] >> 2U))))));
        bufp->chgBit(oldp+360,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+361,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 4U))));
        bufp->chgBit(oldp+362,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 3U))));
        bufp->chgBit(oldp+363,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 2U))));
        bufp->chgCData(oldp+364,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+365,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+366,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+367,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [2U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+368,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 1U)))));
        bufp->chgBit(oldp+369,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+370,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [2U] >> 1U))));
        bufp->chgCData(oldp+371,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [2U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+372,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [2U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [2U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+373,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+374,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [2U])));
        bufp->chgBit(oldp+375,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+376,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+377,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+378,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+379,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+380,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+381,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+382,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+383,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+384,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+385,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+386,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+387,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+388,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+389,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+390,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+391,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+392,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+393,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+394,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+395,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+396,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+397,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+398,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+399,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+400,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+401,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+402,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+403,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+404,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+405,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+406,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+407,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [3U]),17);
        bufp->chgSData(oldp+408,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+409,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout));
        bufp->chgBit(oldp+410,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+411,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+412,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+413,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+414,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+415,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+416,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 0xeU))),3);
        bufp->chgBit(oldp+417,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [3U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [3U] >> 0xeU))))));
        bufp->chgBit(oldp+418,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+419,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 0x10U))));
        bufp->chgBit(oldp+420,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 0xfU))));
        bufp->chgBit(oldp+421,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 0xeU))));
        bufp->chgCData(oldp+422,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 0xbU))),3);
        bufp->chgBit(oldp+423,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [3U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [3U] >> 0xbU))))));
        bufp->chgBit(oldp+424,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+425,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 0xdU))));
        bufp->chgBit(oldp+426,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 0xcU))));
        bufp->chgBit(oldp+427,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 0xbU))));
        bufp->chgCData(oldp+428,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 8U))),3);
        bufp->chgBit(oldp+429,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [3U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [3U] >> 8U))))));
        bufp->chgBit(oldp+430,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+431,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 0xaU))));
        bufp->chgBit(oldp+432,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 9U))));
        bufp->chgBit(oldp+433,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 8U))));
        bufp->chgCData(oldp+434,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 5U))),3);
        bufp->chgBit(oldp+435,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [3U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [3U] >> 5U))))));
        bufp->chgBit(oldp+436,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+437,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 7U))));
        bufp->chgBit(oldp+438,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 6U))));
        bufp->chgBit(oldp+439,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 5U))));
        bufp->chgCData(oldp+440,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 2U))),3);
        bufp->chgBit(oldp+441,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [3U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [3U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [3U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [3U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [3U] >> 2U))))));
        bufp->chgBit(oldp+442,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+443,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 4U))));
        bufp->chgBit(oldp+444,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 3U))));
        bufp->chgBit(oldp+445,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 2U))));
        bufp->chgCData(oldp+446,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+447,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+448,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+449,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [3U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+450,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 1U)))));
        bufp->chgBit(oldp+451,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+452,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [3U] >> 1U))));
        bufp->chgCData(oldp+453,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [3U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+454,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [3U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [3U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+455,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+456,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [3U])));
        bufp->chgBit(oldp+457,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+458,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+459,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+460,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+461,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+462,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+463,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+464,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+465,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+466,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+467,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+468,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+469,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+470,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+471,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+472,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+473,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+474,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+475,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+476,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+477,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+478,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+479,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+480,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+481,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+482,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+483,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+484,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+485,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+486,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+487,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+488,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+489,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [4U]),17);
        bufp->chgSData(oldp+490,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+491,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout));
        bufp->chgBit(oldp+492,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+493,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+494,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+495,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+496,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+497,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+498,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 0xeU))),3);
        bufp->chgBit(oldp+499,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [4U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [4U] >> 0xeU))))));
        bufp->chgBit(oldp+500,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+501,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 0x10U))));
        bufp->chgBit(oldp+502,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 0xfU))));
        bufp->chgBit(oldp+503,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 0xeU))));
        bufp->chgCData(oldp+504,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 0xbU))),3);
        bufp->chgBit(oldp+505,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [4U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [4U] >> 0xbU))))));
        bufp->chgBit(oldp+506,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+507,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 0xdU))));
        bufp->chgBit(oldp+508,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 0xcU))));
        bufp->chgBit(oldp+509,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 0xbU))));
        bufp->chgCData(oldp+510,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 8U))),3);
        bufp->chgBit(oldp+511,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [4U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [4U] >> 8U))))));
        bufp->chgBit(oldp+512,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+513,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 0xaU))));
        bufp->chgBit(oldp+514,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 9U))));
        bufp->chgBit(oldp+515,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 8U))));
        bufp->chgCData(oldp+516,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 5U))),3);
        bufp->chgBit(oldp+517,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [4U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [4U] >> 5U))))));
        bufp->chgBit(oldp+518,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+519,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 7U))));
        bufp->chgBit(oldp+520,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 6U))));
        bufp->chgBit(oldp+521,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 5U))));
        bufp->chgCData(oldp+522,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 2U))),3);
        bufp->chgBit(oldp+523,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [4U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [4U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [4U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [4U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [4U] >> 2U))))));
        bufp->chgBit(oldp+524,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+525,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 4U))));
        bufp->chgBit(oldp+526,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 3U))));
        bufp->chgBit(oldp+527,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 2U))));
        bufp->chgCData(oldp+528,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+529,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+530,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+531,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [4U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+532,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 1U)))));
        bufp->chgBit(oldp+533,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+534,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [4U] >> 1U))));
        bufp->chgCData(oldp+535,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [4U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+536,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [4U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [4U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+537,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+538,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [4U])));
        bufp->chgBit(oldp+539,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+540,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+541,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+542,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+543,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+544,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+545,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+546,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+547,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+548,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+549,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+550,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+551,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+552,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+553,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+554,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+555,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+556,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+557,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+558,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+559,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+560,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+561,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+562,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+563,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+564,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+565,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+566,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+567,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+568,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+569,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+570,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+571,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [5U]),17);
        bufp->chgSData(oldp+572,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+573,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout));
        bufp->chgBit(oldp+574,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+575,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+576,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+577,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+578,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+579,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+580,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 0xeU))),3);
        bufp->chgBit(oldp+581,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [5U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [5U] >> 0xeU))))));
        bufp->chgBit(oldp+582,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+583,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 0x10U))));
        bufp->chgBit(oldp+584,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 0xfU))));
        bufp->chgBit(oldp+585,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 0xeU))));
        bufp->chgCData(oldp+586,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 0xbU))),3);
        bufp->chgBit(oldp+587,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [5U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [5U] >> 0xbU))))));
        bufp->chgBit(oldp+588,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+589,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 0xdU))));
        bufp->chgBit(oldp+590,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 0xcU))));
        bufp->chgBit(oldp+591,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 0xbU))));
        bufp->chgCData(oldp+592,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 8U))),3);
        bufp->chgBit(oldp+593,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [5U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [5U] >> 8U))))));
        bufp->chgBit(oldp+594,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+595,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 0xaU))));
        bufp->chgBit(oldp+596,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 9U))));
        bufp->chgBit(oldp+597,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 8U))));
        bufp->chgCData(oldp+598,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 5U))),3);
        bufp->chgBit(oldp+599,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [5U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [5U] >> 5U))))));
        bufp->chgBit(oldp+600,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+601,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 7U))));
        bufp->chgBit(oldp+602,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 6U))));
        bufp->chgBit(oldp+603,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 5U))));
        bufp->chgCData(oldp+604,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 2U))),3);
        bufp->chgBit(oldp+605,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [5U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [5U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [5U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [5U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [5U] >> 2U))))));
        bufp->chgBit(oldp+606,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+607,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 4U))));
        bufp->chgBit(oldp+608,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 3U))));
        bufp->chgBit(oldp+609,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 2U))));
        bufp->chgCData(oldp+610,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+611,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+612,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+613,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [5U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+614,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 1U)))));
        bufp->chgBit(oldp+615,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+616,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [5U] >> 1U))));
        bufp->chgCData(oldp+617,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [5U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+618,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [5U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [5U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+619,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+620,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [5U])));
        bufp->chgBit(oldp+621,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+622,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+623,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+624,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+625,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+626,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+627,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+628,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+629,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+630,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+631,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+632,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+633,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+634,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+635,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+636,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+637,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+638,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+639,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+640,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+641,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+642,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+643,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+644,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+645,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+646,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+647,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+648,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+649,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+650,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+651,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+652,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+653,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [6U]),17);
        bufp->chgSData(oldp+654,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+655,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout));
        bufp->chgBit(oldp+656,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+657,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+658,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+659,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+660,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+661,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+662,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 0xeU))),3);
        bufp->chgBit(oldp+663,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [6U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [6U] >> 0xeU))))));
        bufp->chgBit(oldp+664,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+665,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 0x10U))));
        bufp->chgBit(oldp+666,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 0xfU))));
        bufp->chgBit(oldp+667,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 0xeU))));
        bufp->chgCData(oldp+668,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 0xbU))),3);
        bufp->chgBit(oldp+669,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [6U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [6U] >> 0xbU))))));
        bufp->chgBit(oldp+670,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+671,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 0xdU))));
        bufp->chgBit(oldp+672,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 0xcU))));
        bufp->chgBit(oldp+673,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 0xbU))));
        bufp->chgCData(oldp+674,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 8U))),3);
        bufp->chgBit(oldp+675,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [6U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [6U] >> 8U))))));
        bufp->chgBit(oldp+676,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+677,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 0xaU))));
        bufp->chgBit(oldp+678,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 9U))));
        bufp->chgBit(oldp+679,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 8U))));
        bufp->chgCData(oldp+680,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 5U))),3);
        bufp->chgBit(oldp+681,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [6U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [6U] >> 5U))))));
        bufp->chgBit(oldp+682,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+683,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 7U))));
        bufp->chgBit(oldp+684,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 6U))));
        bufp->chgBit(oldp+685,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 5U))));
        bufp->chgCData(oldp+686,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 2U))),3);
        bufp->chgBit(oldp+687,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [6U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [6U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [6U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [6U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [6U] >> 2U))))));
        bufp->chgBit(oldp+688,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+689,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 4U))));
        bufp->chgBit(oldp+690,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 3U))));
        bufp->chgBit(oldp+691,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 2U))));
        bufp->chgCData(oldp+692,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+693,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+694,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+695,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [6U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+696,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 1U)))));
        bufp->chgBit(oldp+697,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+698,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [6U] >> 1U))));
        bufp->chgCData(oldp+699,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [6U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+700,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [6U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [6U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+701,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+702,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [6U])));
        bufp->chgBit(oldp+703,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+704,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+705,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+706,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+707,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+708,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+709,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+710,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+711,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+712,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+713,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+714,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+715,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+716,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+717,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+718,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+719,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+720,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+721,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+722,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+723,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+724,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+725,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+726,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+727,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+728,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+729,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+730,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+731,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+732,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+733,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+734,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+735,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [7U]),17);
        bufp->chgSData(oldp+736,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+737,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout));
        bufp->chgBit(oldp+738,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+739,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+740,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+741,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+742,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+743,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+744,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 0xeU))),3);
        bufp->chgBit(oldp+745,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [7U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [7U] >> 0xeU))))));
        bufp->chgBit(oldp+746,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+747,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 0x10U))));
        bufp->chgBit(oldp+748,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 0xfU))));
        bufp->chgBit(oldp+749,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 0xeU))));
        bufp->chgCData(oldp+750,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 0xbU))),3);
        bufp->chgBit(oldp+751,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [7U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [7U] >> 0xbU))))));
        bufp->chgBit(oldp+752,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+753,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 0xdU))));
        bufp->chgBit(oldp+754,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 0xcU))));
        bufp->chgBit(oldp+755,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 0xbU))));
        bufp->chgCData(oldp+756,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 8U))),3);
        bufp->chgBit(oldp+757,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [7U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [7U] >> 8U))))));
        bufp->chgBit(oldp+758,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+759,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 0xaU))));
        bufp->chgBit(oldp+760,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 9U))));
        bufp->chgBit(oldp+761,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 8U))));
        bufp->chgCData(oldp+762,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 5U))),3);
        bufp->chgBit(oldp+763,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [7U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [7U] >> 5U))))));
        bufp->chgBit(oldp+764,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+765,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 7U))));
        bufp->chgBit(oldp+766,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 6U))));
        bufp->chgBit(oldp+767,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 5U))));
        bufp->chgCData(oldp+768,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 2U))),3);
        bufp->chgBit(oldp+769,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [7U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [7U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [7U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [7U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [7U] >> 2U))))));
        bufp->chgBit(oldp+770,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+771,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 4U))));
        bufp->chgBit(oldp+772,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 3U))));
        bufp->chgBit(oldp+773,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 2U))));
        bufp->chgCData(oldp+774,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+775,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+776,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+777,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [7U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+778,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 1U)))));
        bufp->chgBit(oldp+779,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+780,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [7U] >> 1U))));
        bufp->chgCData(oldp+781,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [7U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+782,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [7U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [7U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+783,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+784,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [7U])));
        bufp->chgBit(oldp+785,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+786,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+787,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+788,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+789,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+790,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+791,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+792,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+793,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+794,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+795,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+796,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+797,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+798,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+799,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+800,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+801,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+802,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+803,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+804,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+805,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+806,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+807,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+808,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+809,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+810,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+811,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+812,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+813,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+814,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+815,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+816,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+817,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [8U]),17);
        bufp->chgSData(oldp+818,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+819,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout));
        bufp->chgBit(oldp+820,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+821,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+822,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+823,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+824,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+825,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+826,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 0xeU))),3);
        bufp->chgBit(oldp+827,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [8U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [8U] >> 0xeU))))));
        bufp->chgBit(oldp+828,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+829,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 0x10U))));
        bufp->chgBit(oldp+830,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 0xfU))));
        bufp->chgBit(oldp+831,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 0xeU))));
        bufp->chgCData(oldp+832,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 0xbU))),3);
        bufp->chgBit(oldp+833,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [8U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [8U] >> 0xbU))))));
        bufp->chgBit(oldp+834,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+835,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 0xdU))));
        bufp->chgBit(oldp+836,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 0xcU))));
        bufp->chgBit(oldp+837,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 0xbU))));
        bufp->chgCData(oldp+838,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 8U))),3);
        bufp->chgBit(oldp+839,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [8U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [8U] >> 8U))))));
        bufp->chgBit(oldp+840,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+841,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 0xaU))));
        bufp->chgBit(oldp+842,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 9U))));
        bufp->chgBit(oldp+843,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 8U))));
        bufp->chgCData(oldp+844,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 5U))),3);
        bufp->chgBit(oldp+845,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [8U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [8U] >> 5U))))));
        bufp->chgBit(oldp+846,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+847,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 7U))));
        bufp->chgBit(oldp+848,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 6U))));
        bufp->chgBit(oldp+849,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 5U))));
        bufp->chgCData(oldp+850,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 2U))),3);
        bufp->chgBit(oldp+851,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [8U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [8U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [8U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [8U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [8U] >> 2U))))));
        bufp->chgBit(oldp+852,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+853,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 4U))));
        bufp->chgBit(oldp+854,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 3U))));
        bufp->chgBit(oldp+855,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 2U))));
        bufp->chgCData(oldp+856,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+857,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+858,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+859,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [8U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+860,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 1U)))));
        bufp->chgBit(oldp+861,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+862,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [8U] >> 1U))));
        bufp->chgCData(oldp+863,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [8U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+864,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [8U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [8U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+865,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+866,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [8U])));
        bufp->chgBit(oldp+867,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+868,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+869,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+870,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+871,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+872,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+873,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+874,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+875,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+876,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+877,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+878,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+879,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+880,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+881,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+882,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+883,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+884,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+885,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+886,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+887,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+888,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+889,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+890,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+891,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+892,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+893,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+894,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+895,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+896,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+897,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+898,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+899,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [9U]),17);
        bufp->chgSData(oldp+900,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+901,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout));
        bufp->chgBit(oldp+902,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+903,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+904,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+905,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+906,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+907,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+908,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 0xeU))),3);
        bufp->chgBit(oldp+909,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [9U] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [9U] >> 0xeU))))));
        bufp->chgBit(oldp+910,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+911,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 0x10U))));
        bufp->chgBit(oldp+912,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 0xfU))));
        bufp->chgBit(oldp+913,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 0xeU))));
        bufp->chgCData(oldp+914,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 0xbU))),3);
        bufp->chgBit(oldp+915,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [9U] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [9U] >> 0xbU))))));
        bufp->chgBit(oldp+916,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+917,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 0xdU))));
        bufp->chgBit(oldp+918,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 0xcU))));
        bufp->chgBit(oldp+919,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 0xbU))));
        bufp->chgCData(oldp+920,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 8U))),3);
        bufp->chgBit(oldp+921,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 0xaU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 9U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [9U] >> 9U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 0xaU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [9U] >> 8U))))));
        bufp->chgBit(oldp+922,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+923,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 0xaU))));
        bufp->chgBit(oldp+924,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 9U))));
        bufp->chgBit(oldp+925,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 8U))));
        bufp->chgCData(oldp+926,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 5U))),3);
        bufp->chgBit(oldp+927,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 7U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 6U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [9U] >> 6U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 7U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [9U] >> 5U))))));
        bufp->chgBit(oldp+928,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+929,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 7U))));
        bufp->chgBit(oldp+930,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 6U))));
        bufp->chgBit(oldp+931,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 5U))));
        bufp->chgCData(oldp+932,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 2U))),3);
        bufp->chgBit(oldp+933,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [9U] >> 4U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [9U] >> 3U)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [9U] >> 3U) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [9U] >> 4U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [9U] >> 2U))))));
        bufp->chgBit(oldp+934,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+935,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 4U))));
        bufp->chgBit(oldp+936,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 3U))));
        bufp->chgBit(oldp+937,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 2U))));
        bufp->chgCData(oldp+938,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+939,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa1__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa0__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+940,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+941,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s) 
                                              << 1U) 
                                             | (1U 
                                                & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                   [9U] 
                                                   >> 1U))))),3);
        bufp->chgBit(oldp+942,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa4__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa3__s)) 
                                   & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 1U)))));
        bufp->chgBit(oldp+943,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+944,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [9U] >> 1U))));
        bufp->chgCData(oldp+945,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [9U] << 2U)) 
                                  | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                           >> 3U)))),3);
        bufp->chgBit(oldp+946,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [9U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                               >> 4U)) 
                                      | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                           >> 4U) | 
                                          vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [9U]) & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                   >> 3U))))));
        bufp->chgBit(oldp+947,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+948,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                [9U])));
        bufp->chgBit(oldp+949,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 4U))));
        bufp->chgBit(oldp+950,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 3U))));
        bufp->chgCData(oldp+951,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+952,((1U & ((IData)((6U == 
                                               (6U 
                                                & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (6U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                         & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+953,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+954,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 2U))));
        bufp->chgBit(oldp+955,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 1U))));
        bufp->chgBit(oldp+956,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+957,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+958,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa6__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa5__s)) 
                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+959,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+960,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                   >> 5U)))),3);
        bufp->chgBit(oldp+961,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                          >> 6U)) | 
                                      ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                         >> 6U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa8__s)) 
                                       & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                          >> 5U))))));
        bufp->chgBit(oldp+962,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+963,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 6U))));
        bufp->chgBit(oldp+964,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 5U))));
        bufp->chgCData(oldp+965,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                   >> 0xaU))))),3);
        bufp->chgBit(oldp+966,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaA__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csa9__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 0xaU)))));
        bufp->chgBit(oldp+967,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+968,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 0xaU))));
        bufp->chgCData(oldp+969,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+970,((1U & ((IData)((0x300U 
                                               == (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                      | ((IData)((0U 
                                                  != 
                                                  (0x300U 
                                                   & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group)))) 
                                         & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                            >> 7U))))));
        bufp->chgBit(oldp+971,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+972,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 9U))));
        bufp->chgBit(oldp+973,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 8U))));
        bufp->chgBit(oldp+974,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 7U))));
        bufp->chgCData(oldp+975,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s) 
                                              << 1U) 
                                             | (1U 
                                                & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                   >> 0xbU))))),3);
        bufp->chgBit(oldp+976,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s) 
                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s)) 
                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaC__s) 
                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__Vcellout__csaB__s)) 
                                   & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 0xbU)))));
        bufp->chgBit(oldp+977,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 0xbU))));
        bufp->chgCData(oldp+978,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.__PVT__fifth_s) 
                                   << 2U) | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                                   >> 0xcU)))),3);
        bufp->chgBit(oldp+979,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+980,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut.cout_group) 
                                      >> 0xcU))));
        bufp->chgIData(oldp+981,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0xaU]),17);
        bufp->chgSData(oldp+982,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+983,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout));
        bufp->chgBit(oldp+984,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s) 
                                      ^ VL_REDXOR_16(
                                                     (0x3000U 
                                                      & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+985,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s) 
                                   << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s) 
                                              << 3U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s) 
                                                 << 2U) 
                                                | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+986,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s) 
                                   << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s) 
                                              << 2U) 
                                             | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s) 
                                                 << 1U) 
                                                | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+987,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+988,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s) 
                                   << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+989,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+990,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xaU] >> 0xeU))),3);
        bufp->chgBit(oldp+991,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xaU] >> 0x10U) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] >> 0xfU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xaU] >> 0xfU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 0x10U)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xaU] 
                                            >> 0xeU))))));
        bufp->chgBit(oldp+992,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+993,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0xaU] >> 0x10U))));
        bufp->chgBit(oldp+994,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0xaU] >> 0xfU))));
        bufp->chgBit(oldp+995,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0xaU] >> 0xeU))));
        bufp->chgCData(oldp+996,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xaU] >> 0xbU))),3);
        bufp->chgBit(oldp+997,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xaU] >> 0xdU) 
                                       & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] >> 0xcU)) 
                                      | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xaU] >> 0xcU) 
                                          | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 0xdU)) 
                                         & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xaU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+998,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+999,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                      [0xaU] >> 0xdU))));
        bufp->chgBit(oldp+1000,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 0xcU))));
        bufp->chgBit(oldp+1001,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 0xbU))));
        bufp->chgCData(oldp+1002,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xaU] >> 8U))),3);
        bufp->chgBit(oldp+1003,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xaU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xaU] >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xaU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xaU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1004,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1005,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 0xaU))));
        bufp->chgBit(oldp+1006,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 9U))));
        bufp->chgBit(oldp+1007,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 8U))));
        bufp->chgCData(oldp+1008,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xaU] >> 5U))),3);
        bufp->chgBit(oldp+1009,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xaU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xaU] >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xaU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xaU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1010,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1011,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 7U))));
        bufp->chgBit(oldp+1012,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 6U))));
        bufp->chgBit(oldp+1013,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 5U))));
        bufp->chgCData(oldp+1014,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xaU] >> 2U))),3);
        bufp->chgBit(oldp+1015,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xaU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xaU] >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xaU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xaU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xaU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1016,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1017,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 4U))));
        bufp->chgBit(oldp+1018,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 3U))));
        bufp->chgBit(oldp+1019,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 2U))));
        bufp->chgCData(oldp+1020,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1021,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1022,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1023,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0xaU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1024,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 1U)))));
        bufp->chgBit(oldp+1025,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1026,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xaU] >> 1U))));
        bufp->chgCData(oldp+1027,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xaU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1028,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xaU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xaU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1029,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1030,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0xaU])));
        bufp->chgBit(oldp+1031,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1032,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1033,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1034,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1035,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1036,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1037,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1038,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1039,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1040,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1041,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1042,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1043,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1044,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1045,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1046,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1047,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1048,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1049,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1050,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1051,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1052,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1053,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1054,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1055,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1056,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1057,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1058,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1059,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1060,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1061,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1062,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1063,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0xbU]),17);
        bufp->chgSData(oldp+1064,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1065,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1066,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1067,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1068,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1069,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1070,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1071,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1072,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 0xeU))),3);
        bufp->chgBit(oldp+1073,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xbU] >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xbU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xbU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1074,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1075,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 0x10U))));
        bufp->chgBit(oldp+1076,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 0xfU))));
        bufp->chgBit(oldp+1077,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 0xeU))));
        bufp->chgCData(oldp+1078,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 0xbU))),3);
        bufp->chgBit(oldp+1079,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xbU] >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xbU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xbU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1080,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1081,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 0xdU))));
        bufp->chgBit(oldp+1082,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 0xcU))));
        bufp->chgBit(oldp+1083,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 0xbU))));
        bufp->chgCData(oldp+1084,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 8U))),3);
        bufp->chgBit(oldp+1085,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xbU] >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xbU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xbU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1086,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1087,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 0xaU))));
        bufp->chgBit(oldp+1088,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 9U))));
        bufp->chgBit(oldp+1089,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 8U))));
        bufp->chgCData(oldp+1090,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 5U))),3);
        bufp->chgBit(oldp+1091,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xbU] >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xbU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xbU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1092,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1093,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 7U))));
        bufp->chgBit(oldp+1094,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 6U))));
        bufp->chgBit(oldp+1095,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 5U))));
        bufp->chgCData(oldp+1096,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 2U))),3);
        bufp->chgBit(oldp+1097,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xbU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xbU] >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xbU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xbU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xbU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1098,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1099,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 4U))));
        bufp->chgBit(oldp+1100,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 3U))));
        bufp->chgBit(oldp+1101,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 2U))));
        bufp->chgCData(oldp+1102,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1103,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1104,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1105,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0xbU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1106,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 1U)))));
        bufp->chgBit(oldp+1107,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1108,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xbU] >> 1U))));
        bufp->chgCData(oldp+1109,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xbU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1110,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xbU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xbU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1111,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1112,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0xbU])));
        bufp->chgBit(oldp+1113,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1114,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1115,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1116,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1117,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1118,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1119,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1120,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1121,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1122,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1123,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1124,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1125,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1126,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1127,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1128,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1129,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1130,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1131,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1132,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1133,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1134,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1135,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1136,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1137,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1138,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1139,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1140,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1141,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1142,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1143,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1144,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1145,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0xcU]),17);
        bufp->chgSData(oldp+1146,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1147,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1148,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1149,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1150,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1151,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1152,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1153,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1154,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 0xeU))),3);
        bufp->chgBit(oldp+1155,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xcU] >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xcU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xcU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1156,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1157,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 0x10U))));
        bufp->chgBit(oldp+1158,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 0xfU))));
        bufp->chgBit(oldp+1159,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 0xeU))));
        bufp->chgCData(oldp+1160,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 0xbU))),3);
        bufp->chgBit(oldp+1161,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xcU] >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xcU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xcU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1162,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1163,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 0xdU))));
        bufp->chgBit(oldp+1164,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 0xcU))));
        bufp->chgBit(oldp+1165,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 0xbU))));
        bufp->chgCData(oldp+1166,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 8U))),3);
        bufp->chgBit(oldp+1167,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xcU] >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xcU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xcU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1168,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1169,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 0xaU))));
        bufp->chgBit(oldp+1170,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 9U))));
        bufp->chgBit(oldp+1171,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 8U))));
        bufp->chgCData(oldp+1172,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 5U))),3);
        bufp->chgBit(oldp+1173,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xcU] >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xcU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xcU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1174,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1175,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 7U))));
        bufp->chgBit(oldp+1176,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 6U))));
        bufp->chgBit(oldp+1177,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 5U))));
        bufp->chgCData(oldp+1178,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 2U))),3);
        bufp->chgBit(oldp+1179,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xcU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xcU] >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xcU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xcU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xcU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1180,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1181,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 4U))));
        bufp->chgBit(oldp+1182,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 3U))));
        bufp->chgBit(oldp+1183,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 2U))));
        bufp->chgCData(oldp+1184,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1185,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1186,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1187,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0xcU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1188,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 1U)))));
        bufp->chgBit(oldp+1189,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1190,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xcU] >> 1U))));
        bufp->chgCData(oldp+1191,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xcU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1192,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xcU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xcU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1193,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1194,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0xcU])));
        bufp->chgBit(oldp+1195,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1196,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1197,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1198,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1199,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1200,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1201,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1202,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1203,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1204,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1205,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1206,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1207,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1208,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1209,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1210,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1211,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1212,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1213,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1214,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1215,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1216,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1217,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1218,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1219,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1220,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1221,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1222,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1223,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1224,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1225,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1226,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1227,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0xdU]),17);
        bufp->chgSData(oldp+1228,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1229,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1230,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1231,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1232,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1233,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1234,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1235,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1236,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 0xeU))),3);
        bufp->chgBit(oldp+1237,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xdU] >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xdU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xdU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1238,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1239,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 0x10U))));
        bufp->chgBit(oldp+1240,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 0xfU))));
        bufp->chgBit(oldp+1241,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 0xeU))));
        bufp->chgCData(oldp+1242,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 0xbU))),3);
        bufp->chgBit(oldp+1243,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xdU] >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xdU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xdU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1244,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1245,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 0xdU))));
        bufp->chgBit(oldp+1246,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 0xcU))));
        bufp->chgBit(oldp+1247,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 0xbU))));
        bufp->chgCData(oldp+1248,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 8U))),3);
        bufp->chgBit(oldp+1249,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xdU] >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xdU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xdU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1250,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1251,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 0xaU))));
        bufp->chgBit(oldp+1252,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 9U))));
        bufp->chgBit(oldp+1253,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 8U))));
        bufp->chgCData(oldp+1254,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 5U))),3);
        bufp->chgBit(oldp+1255,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xdU] >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xdU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xdU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1256,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1257,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 7U))));
        bufp->chgBit(oldp+1258,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 6U))));
        bufp->chgBit(oldp+1259,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 5U))));
        bufp->chgCData(oldp+1260,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 2U))),3);
        bufp->chgBit(oldp+1261,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xdU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xdU] >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xdU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xdU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xdU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1262,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1263,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 4U))));
        bufp->chgBit(oldp+1264,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 3U))));
        bufp->chgBit(oldp+1265,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 2U))));
        bufp->chgCData(oldp+1266,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1267,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1268,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1269,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0xdU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1270,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 1U)))));
        bufp->chgBit(oldp+1271,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1272,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xdU] >> 1U))));
        bufp->chgCData(oldp+1273,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xdU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1274,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xdU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xdU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1275,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1276,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0xdU])));
        bufp->chgBit(oldp+1277,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1278,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1279,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1280,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1281,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1282,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1283,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1284,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1285,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1286,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1287,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1288,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1289,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1290,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1291,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1292,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1293,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1294,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1295,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1296,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1297,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1298,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1299,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1300,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1301,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1302,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1303,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1304,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1305,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1306,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1307,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1308,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1309,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0xeU]),17);
        bufp->chgSData(oldp+1310,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1311,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1312,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1313,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1314,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1315,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1316,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1317,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1318,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 0xeU))),3);
        bufp->chgBit(oldp+1319,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xeU] >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xeU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xeU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1320,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1321,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 0x10U))));
        bufp->chgBit(oldp+1322,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 0xfU))));
        bufp->chgBit(oldp+1323,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 0xeU))));
        bufp->chgCData(oldp+1324,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 0xbU))),3);
        bufp->chgBit(oldp+1325,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xeU] >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xeU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xeU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1326,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1327,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 0xdU))));
        bufp->chgBit(oldp+1328,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 0xcU))));
        bufp->chgBit(oldp+1329,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 0xbU))));
        bufp->chgCData(oldp+1330,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 8U))),3);
        bufp->chgBit(oldp+1331,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xeU] >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xeU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xeU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1332,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1333,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 0xaU))));
        bufp->chgBit(oldp+1334,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 9U))));
        bufp->chgBit(oldp+1335,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 8U))));
        bufp->chgCData(oldp+1336,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 5U))),3);
        bufp->chgBit(oldp+1337,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xeU] >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xeU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xeU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1338,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1339,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 7U))));
        bufp->chgBit(oldp+1340,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 6U))));
        bufp->chgBit(oldp+1341,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 5U))));
        bufp->chgCData(oldp+1342,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 2U))),3);
        bufp->chgBit(oldp+1343,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xeU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xeU] >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xeU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xeU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xeU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1344,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1345,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 4U))));
        bufp->chgBit(oldp+1346,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 3U))));
        bufp->chgBit(oldp+1347,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 2U))));
        bufp->chgCData(oldp+1348,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1349,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1350,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1351,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0xeU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1352,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 1U)))));
        bufp->chgBit(oldp+1353,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1354,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xeU] >> 1U))));
        bufp->chgCData(oldp+1355,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xeU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1356,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xeU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xeU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1357,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1358,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0xeU])));
        bufp->chgBit(oldp+1359,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1360,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1361,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1362,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1363,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1364,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1365,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1366,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1367,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1368,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1369,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1370,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1371,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1372,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1373,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1374,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1375,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1376,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1377,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1378,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1379,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1380,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1381,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1382,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1383,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1384,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1385,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1386,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1387,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1388,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1389,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1390,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1391,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0xfU]),17);
        bufp->chgSData(oldp+1392,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1393,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1394,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1395,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1396,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1397,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1398,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1399,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1400,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 0xeU))),3);
        bufp->chgBit(oldp+1401,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xfU] >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xfU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xfU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1402,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1403,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 0x10U))));
        bufp->chgBit(oldp+1404,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 0xfU))));
        bufp->chgBit(oldp+1405,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 0xeU))));
        bufp->chgCData(oldp+1406,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 0xbU))),3);
        bufp->chgBit(oldp+1407,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xfU] >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xfU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xfU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1408,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1409,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 0xdU))));
        bufp->chgBit(oldp+1410,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 0xcU))));
        bufp->chgBit(oldp+1411,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 0xbU))));
        bufp->chgCData(oldp+1412,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 8U))),3);
        bufp->chgBit(oldp+1413,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xfU] >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xfU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xfU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1414,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1415,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 0xaU))));
        bufp->chgBit(oldp+1416,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 9U))));
        bufp->chgBit(oldp+1417,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 8U))));
        bufp->chgCData(oldp+1418,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 5U))),3);
        bufp->chgBit(oldp+1419,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xfU] >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xfU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xfU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1420,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1421,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 7U))));
        bufp->chgBit(oldp+1422,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 6U))));
        bufp->chgBit(oldp+1423,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 5U))));
        bufp->chgCData(oldp+1424,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 2U))),3);
        bufp->chgBit(oldp+1425,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0xfU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xfU] >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0xfU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0xfU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0xfU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1426,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1427,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 4U))));
        bufp->chgBit(oldp+1428,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 3U))));
        bufp->chgBit(oldp+1429,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 2U))));
        bufp->chgCData(oldp+1430,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1431,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1432,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1433,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0xfU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1434,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 1U)))));
        bufp->chgBit(oldp+1435,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1436,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0xfU] >> 1U))));
        bufp->chgCData(oldp+1437,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0xfU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1438,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0xfU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                  >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0xfU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1439,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1440,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0xfU])));
        bufp->chgBit(oldp+1441,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1442,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1443,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1444,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1445,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1446,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1447,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1448,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1449,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1450,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1451,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1452,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1453,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1454,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1455,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1456,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1457,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1458,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1459,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1460,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1461,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1462,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1463,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1464,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1465,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1466,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1467,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1468,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1469,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1470,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1471,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1472,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1473,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x10U]),17);
        bufp->chgSData(oldp+1474,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1475,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1476,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1477,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1478,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1479,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1480,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1481,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1482,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 0xeU))),3);
        bufp->chgBit(oldp+1483,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x10U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x10U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x10U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1484,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1485,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 0x10U))));
        bufp->chgBit(oldp+1486,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 0xfU))));
        bufp->chgBit(oldp+1487,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 0xeU))));
        bufp->chgCData(oldp+1488,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 0xbU))),3);
        bufp->chgBit(oldp+1489,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x10U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x10U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x10U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1490,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1491,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 0xdU))));
        bufp->chgBit(oldp+1492,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 0xcU))));
        bufp->chgBit(oldp+1493,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 0xbU))));
        bufp->chgCData(oldp+1494,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 8U))),3);
        bufp->chgBit(oldp+1495,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x10U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x10U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x10U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1496,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1497,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 0xaU))));
        bufp->chgBit(oldp+1498,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 9U))));
        bufp->chgBit(oldp+1499,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 8U))));
        bufp->chgCData(oldp+1500,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 5U))),3);
        bufp->chgBit(oldp+1501,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x10U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x10U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x10U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1502,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1503,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 7U))));
        bufp->chgBit(oldp+1504,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 6U))));
        bufp->chgBit(oldp+1505,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 5U))));
        bufp->chgCData(oldp+1506,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 2U))),3);
        bufp->chgBit(oldp+1507,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x10U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x10U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x10U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x10U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x10U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1508,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1509,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 4U))));
        bufp->chgBit(oldp+1510,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 3U))));
        bufp->chgBit(oldp+1511,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 2U))));
        bufp->chgCData(oldp+1512,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1513,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1514,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1515,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x10U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1516,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 1U)))));
        bufp->chgBit(oldp+1517,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1518,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x10U] >> 1U))));
        bufp->chgCData(oldp+1519,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x10U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1520,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x10U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x10U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1521,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1522,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x10U])));
        bufp->chgBit(oldp+1523,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1524,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1525,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1526,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1527,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1528,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1529,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1530,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1531,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1532,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1533,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1534,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1535,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1536,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1537,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1538,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1539,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1540,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1541,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1542,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1543,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1544,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1545,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1546,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1547,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1548,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1549,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1550,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1551,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1552,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1553,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1554,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1555,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x11U]),17);
        bufp->chgSData(oldp+1556,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1557,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1558,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1559,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1560,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1561,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1562,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1563,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1564,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 0xeU))),3);
        bufp->chgBit(oldp+1565,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x11U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x11U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x11U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1566,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1567,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 0x10U))));
        bufp->chgBit(oldp+1568,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 0xfU))));
        bufp->chgBit(oldp+1569,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 0xeU))));
        bufp->chgCData(oldp+1570,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 0xbU))),3);
        bufp->chgBit(oldp+1571,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x11U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x11U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x11U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1572,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1573,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 0xdU))));
        bufp->chgBit(oldp+1574,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 0xcU))));
        bufp->chgBit(oldp+1575,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 0xbU))));
        bufp->chgCData(oldp+1576,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 8U))),3);
        bufp->chgBit(oldp+1577,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x11U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x11U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x11U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1578,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1579,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 0xaU))));
        bufp->chgBit(oldp+1580,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 9U))));
        bufp->chgBit(oldp+1581,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 8U))));
        bufp->chgCData(oldp+1582,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 5U))),3);
        bufp->chgBit(oldp+1583,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x11U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x11U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x11U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1584,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1585,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 7U))));
        bufp->chgBit(oldp+1586,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 6U))));
        bufp->chgBit(oldp+1587,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 5U))));
        bufp->chgCData(oldp+1588,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 2U))),3);
        bufp->chgBit(oldp+1589,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x11U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x11U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x11U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x11U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x11U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1590,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1591,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 4U))));
        bufp->chgBit(oldp+1592,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 3U))));
        bufp->chgBit(oldp+1593,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 2U))));
        bufp->chgCData(oldp+1594,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1595,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1596,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1597,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x11U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1598,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 1U)))));
        bufp->chgBit(oldp+1599,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1600,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x11U] >> 1U))));
        bufp->chgCData(oldp+1601,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x11U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1602,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x11U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x11U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1603,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1604,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x11U])));
        bufp->chgBit(oldp+1605,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1606,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1607,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1608,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1609,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1610,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1611,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1612,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1613,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1614,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1615,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1616,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1617,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1618,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1619,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1620,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1621,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1622,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1623,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1624,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1625,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1626,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1627,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1628,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1629,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1630,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1631,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1632,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1633,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1634,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1635,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1636,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1637,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x12U]),17);
        bufp->chgSData(oldp+1638,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1639,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1640,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1641,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1642,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1643,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1644,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1645,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1646,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 0xeU))),3);
        bufp->chgBit(oldp+1647,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x12U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x12U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x12U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1648,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1649,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 0x10U))));
        bufp->chgBit(oldp+1650,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 0xfU))));
        bufp->chgBit(oldp+1651,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 0xeU))));
        bufp->chgCData(oldp+1652,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 0xbU))),3);
        bufp->chgBit(oldp+1653,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x12U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x12U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x12U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1654,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1655,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 0xdU))));
        bufp->chgBit(oldp+1656,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 0xcU))));
        bufp->chgBit(oldp+1657,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 0xbU))));
        bufp->chgCData(oldp+1658,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 8U))),3);
        bufp->chgBit(oldp+1659,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x12U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x12U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x12U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1660,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1661,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 0xaU))));
        bufp->chgBit(oldp+1662,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 9U))));
        bufp->chgBit(oldp+1663,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 8U))));
        bufp->chgCData(oldp+1664,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 5U))),3);
        bufp->chgBit(oldp+1665,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x12U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x12U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x12U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1666,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1667,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 7U))));
        bufp->chgBit(oldp+1668,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 6U))));
        bufp->chgBit(oldp+1669,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 5U))));
        bufp->chgCData(oldp+1670,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 2U))),3);
        bufp->chgBit(oldp+1671,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x12U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x12U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x12U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x12U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x12U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1672,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1673,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 4U))));
        bufp->chgBit(oldp+1674,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 3U))));
        bufp->chgBit(oldp+1675,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 2U))));
        bufp->chgCData(oldp+1676,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1677,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1678,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1679,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x12U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1680,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 1U)))));
        bufp->chgBit(oldp+1681,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1682,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x12U] >> 1U))));
        bufp->chgCData(oldp+1683,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x12U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1684,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x12U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x12U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1685,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1686,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x12U])));
        bufp->chgBit(oldp+1687,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1688,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1689,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1690,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1691,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1692,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1693,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1694,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1695,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1696,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1697,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1698,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1699,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1700,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1701,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1702,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1703,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1704,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1705,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1706,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1707,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1708,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1709,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1710,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1711,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1712,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1713,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1714,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1715,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1716,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1717,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1718,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1719,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x13U]),17);
        bufp->chgSData(oldp+1720,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1721,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1722,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1723,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1724,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1725,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1726,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1727,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1728,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 0xeU))),3);
        bufp->chgBit(oldp+1729,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x13U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x13U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x13U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1730,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1731,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 0x10U))));
        bufp->chgBit(oldp+1732,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 0xfU))));
        bufp->chgBit(oldp+1733,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 0xeU))));
        bufp->chgCData(oldp+1734,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 0xbU))),3);
        bufp->chgBit(oldp+1735,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x13U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x13U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x13U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1736,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1737,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 0xdU))));
        bufp->chgBit(oldp+1738,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 0xcU))));
        bufp->chgBit(oldp+1739,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 0xbU))));
        bufp->chgCData(oldp+1740,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 8U))),3);
        bufp->chgBit(oldp+1741,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x13U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x13U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x13U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1742,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1743,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 0xaU))));
        bufp->chgBit(oldp+1744,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 9U))));
        bufp->chgBit(oldp+1745,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 8U))));
        bufp->chgCData(oldp+1746,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 5U))),3);
        bufp->chgBit(oldp+1747,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x13U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x13U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x13U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1748,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1749,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 7U))));
        bufp->chgBit(oldp+1750,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 6U))));
        bufp->chgBit(oldp+1751,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 5U))));
        bufp->chgCData(oldp+1752,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 2U))),3);
        bufp->chgBit(oldp+1753,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x13U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x13U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x13U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x13U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x13U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1754,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1755,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 4U))));
        bufp->chgBit(oldp+1756,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 3U))));
        bufp->chgBit(oldp+1757,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 2U))));
        bufp->chgCData(oldp+1758,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1759,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1760,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1761,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x13U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1762,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 1U)))));
        bufp->chgBit(oldp+1763,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1764,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x13U] >> 1U))));
        bufp->chgCData(oldp+1765,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x13U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1766,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x13U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x13U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1767,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1768,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x13U])));
        bufp->chgBit(oldp+1769,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1770,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1771,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1772,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1773,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1774,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1775,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1776,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1777,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1778,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1779,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1780,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1781,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1782,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1783,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1784,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1785,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1786,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1787,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1788,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1789,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1790,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1791,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1792,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1793,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1794,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1795,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1796,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1797,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1798,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1799,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1800,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1801,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x14U]),17);
        bufp->chgSData(oldp+1802,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1803,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1804,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1805,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1806,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1807,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1808,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1809,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1810,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 0xeU))),3);
        bufp->chgBit(oldp+1811,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x14U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x14U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x14U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1812,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1813,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 0x10U))));
        bufp->chgBit(oldp+1814,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 0xfU))));
        bufp->chgBit(oldp+1815,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 0xeU))));
        bufp->chgCData(oldp+1816,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 0xbU))),3);
        bufp->chgBit(oldp+1817,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x14U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x14U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x14U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1818,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1819,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 0xdU))));
        bufp->chgBit(oldp+1820,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 0xcU))));
        bufp->chgBit(oldp+1821,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 0xbU))));
        bufp->chgCData(oldp+1822,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 8U))),3);
        bufp->chgBit(oldp+1823,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x14U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x14U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x14U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1824,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1825,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 0xaU))));
        bufp->chgBit(oldp+1826,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 9U))));
        bufp->chgBit(oldp+1827,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 8U))));
        bufp->chgCData(oldp+1828,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 5U))),3);
        bufp->chgBit(oldp+1829,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x14U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x14U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x14U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1830,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1831,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 7U))));
        bufp->chgBit(oldp+1832,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 6U))));
        bufp->chgBit(oldp+1833,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 5U))));
        bufp->chgCData(oldp+1834,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 2U))),3);
        bufp->chgBit(oldp+1835,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x14U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x14U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x14U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x14U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x14U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1836,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1837,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 4U))));
        bufp->chgBit(oldp+1838,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 3U))));
        bufp->chgBit(oldp+1839,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 2U))));
        bufp->chgCData(oldp+1840,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1841,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1842,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1843,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x14U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1844,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 1U)))));
        bufp->chgBit(oldp+1845,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1846,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x14U] >> 1U))));
        bufp->chgCData(oldp+1847,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x14U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1848,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x14U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x14U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1849,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1850,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x14U])));
        bufp->chgBit(oldp+1851,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1852,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1853,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1854,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1855,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1856,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1857,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1858,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1859,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1860,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1861,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1862,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1863,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1864,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1865,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1866,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1867,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1868,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1869,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1870,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1871,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1872,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1873,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1874,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1875,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1876,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1877,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1878,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1879,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1880,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1881,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1882,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1883,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x15U]),17);
        bufp->chgSData(oldp+1884,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1885,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1886,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1887,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1888,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1889,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1890,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1891,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1892,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 0xeU))),3);
        bufp->chgBit(oldp+1893,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x15U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x15U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x15U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1894,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1895,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 0x10U))));
        bufp->chgBit(oldp+1896,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 0xfU))));
        bufp->chgBit(oldp+1897,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 0xeU))));
        bufp->chgCData(oldp+1898,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 0xbU))),3);
        bufp->chgBit(oldp+1899,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x15U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x15U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x15U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1900,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1901,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 0xdU))));
        bufp->chgBit(oldp+1902,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 0xcU))));
        bufp->chgBit(oldp+1903,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 0xbU))));
        bufp->chgCData(oldp+1904,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 8U))),3);
        bufp->chgBit(oldp+1905,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x15U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x15U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x15U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1906,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1907,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 0xaU))));
        bufp->chgBit(oldp+1908,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 9U))));
        bufp->chgBit(oldp+1909,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 8U))));
        bufp->chgCData(oldp+1910,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 5U))),3);
        bufp->chgBit(oldp+1911,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x15U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x15U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x15U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1912,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1913,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 7U))));
        bufp->chgBit(oldp+1914,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 6U))));
        bufp->chgBit(oldp+1915,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 5U))));
        bufp->chgCData(oldp+1916,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 2U))),3);
        bufp->chgBit(oldp+1917,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x15U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x15U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x15U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x15U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x15U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+1918,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+1919,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 4U))));
        bufp->chgBit(oldp+1920,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 3U))));
        bufp->chgBit(oldp+1921,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 2U))));
        bufp->chgCData(oldp+1922,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+1923,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+1924,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+1925,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x15U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+1926,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 1U)))));
        bufp->chgBit(oldp+1927,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+1928,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x15U] >> 1U))));
        bufp->chgCData(oldp+1929,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x15U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+1930,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x15U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x15U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+1931,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+1932,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x15U])));
        bufp->chgBit(oldp+1933,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+1934,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+1935,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+1936,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+1937,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+1938,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+1939,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+1940,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+1941,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+1942,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+1943,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+1944,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+1945,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+1946,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+1947,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+1948,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+1949,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+1950,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+1951,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+1952,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+1953,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1954,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+1955,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+1956,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+1957,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+1958,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+1959,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+1960,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+1961,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+1962,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+1963,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+1964,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+1965,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x16U]),17);
        bufp->chgSData(oldp+1966,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+1967,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout));
        bufp->chgBit(oldp+1968,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+1969,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+1970,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+1971,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+1972,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+1973,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+1974,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 0xeU))),3);
        bufp->chgBit(oldp+1975,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x16U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x16U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x16U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+1976,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+1977,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 0x10U))));
        bufp->chgBit(oldp+1978,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 0xfU))));
        bufp->chgBit(oldp+1979,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 0xeU))));
        bufp->chgCData(oldp+1980,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 0xbU))),3);
        bufp->chgBit(oldp+1981,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x16U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x16U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x16U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+1982,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+1983,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 0xdU))));
        bufp->chgBit(oldp+1984,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 0xcU))));
        bufp->chgBit(oldp+1985,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 0xbU))));
        bufp->chgCData(oldp+1986,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 8U))),3);
        bufp->chgBit(oldp+1987,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x16U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x16U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x16U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+1988,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+1989,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 0xaU))));
        bufp->chgBit(oldp+1990,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 9U))));
        bufp->chgBit(oldp+1991,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 8U))));
        bufp->chgCData(oldp+1992,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 5U))),3);
        bufp->chgBit(oldp+1993,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x16U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x16U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x16U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+1994,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+1995,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 7U))));
        bufp->chgBit(oldp+1996,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 6U))));
        bufp->chgBit(oldp+1997,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 5U))));
        bufp->chgCData(oldp+1998,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 2U))),3);
        bufp->chgBit(oldp+1999,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x16U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x16U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x16U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x16U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x16U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2000,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2001,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 4U))));
        bufp->chgBit(oldp+2002,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 3U))));
        bufp->chgBit(oldp+2003,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 2U))));
        bufp->chgCData(oldp+2004,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2005,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2006,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2007,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x16U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2008,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 1U)))));
        bufp->chgBit(oldp+2009,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2010,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x16U] >> 1U))));
        bufp->chgCData(oldp+2011,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x16U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2012,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x16U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x16U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2013,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2014,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x16U])));
        bufp->chgBit(oldp+2015,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2016,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2017,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2018,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2019,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2020,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2021,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2022,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2023,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2024,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2025,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2026,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2027,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2028,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2029,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2030,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2031,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2032,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2033,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2034,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2035,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2036,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2037,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2038,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2039,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2040,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2041,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2042,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2043,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2044,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2045,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2046,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2047,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x17U]),17);
        bufp->chgSData(oldp+2048,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2049,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2050,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2051,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2052,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2053,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2054,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2055,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2056,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 0xeU))),3);
        bufp->chgBit(oldp+2057,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x17U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x17U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x17U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2058,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2059,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 0x10U))));
        bufp->chgBit(oldp+2060,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 0xfU))));
        bufp->chgBit(oldp+2061,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 0xeU))));
        bufp->chgCData(oldp+2062,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 0xbU))),3);
        bufp->chgBit(oldp+2063,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x17U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x17U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x17U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2064,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2065,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 0xdU))));
        bufp->chgBit(oldp+2066,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 0xcU))));
        bufp->chgBit(oldp+2067,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 0xbU))));
        bufp->chgCData(oldp+2068,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 8U))),3);
        bufp->chgBit(oldp+2069,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x17U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x17U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x17U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2070,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2071,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 0xaU))));
        bufp->chgBit(oldp+2072,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 9U))));
        bufp->chgBit(oldp+2073,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 8U))));
        bufp->chgCData(oldp+2074,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 5U))),3);
        bufp->chgBit(oldp+2075,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x17U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x17U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x17U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2076,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2077,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 7U))));
        bufp->chgBit(oldp+2078,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 6U))));
        bufp->chgBit(oldp+2079,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 5U))));
        bufp->chgCData(oldp+2080,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 2U))),3);
        bufp->chgBit(oldp+2081,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x17U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x17U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x17U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x17U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x17U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2082,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2083,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 4U))));
        bufp->chgBit(oldp+2084,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 3U))));
        bufp->chgBit(oldp+2085,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 2U))));
        bufp->chgCData(oldp+2086,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2087,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2088,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2089,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x17U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2090,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 1U)))));
        bufp->chgBit(oldp+2091,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2092,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x17U] >> 1U))));
        bufp->chgCData(oldp+2093,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x17U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2094,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x17U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x17U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2095,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2096,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x17U])));
        bufp->chgBit(oldp+2097,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2098,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2099,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2100,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2101,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2102,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2103,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2104,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2105,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2106,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2107,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2108,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2109,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2110,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2111,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2112,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2113,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2114,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2115,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2116,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2117,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2118,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2119,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2120,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2121,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2122,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2123,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2124,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2125,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2126,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2127,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2128,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2129,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x18U]),17);
        bufp->chgSData(oldp+2130,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2131,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2132,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2133,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2134,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2135,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2136,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2137,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2138,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 0xeU))),3);
        bufp->chgBit(oldp+2139,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x18U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x18U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x18U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2140,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2141,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 0x10U))));
        bufp->chgBit(oldp+2142,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 0xfU))));
        bufp->chgBit(oldp+2143,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 0xeU))));
        bufp->chgCData(oldp+2144,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 0xbU))),3);
        bufp->chgBit(oldp+2145,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x18U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x18U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x18U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2146,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2147,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 0xdU))));
        bufp->chgBit(oldp+2148,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 0xcU))));
        bufp->chgBit(oldp+2149,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 0xbU))));
        bufp->chgCData(oldp+2150,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 8U))),3);
        bufp->chgBit(oldp+2151,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x18U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x18U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x18U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2152,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2153,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 0xaU))));
        bufp->chgBit(oldp+2154,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 9U))));
        bufp->chgBit(oldp+2155,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 8U))));
        bufp->chgCData(oldp+2156,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 5U))),3);
        bufp->chgBit(oldp+2157,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x18U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x18U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x18U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2158,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2159,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 7U))));
        bufp->chgBit(oldp+2160,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 6U))));
        bufp->chgBit(oldp+2161,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 5U))));
        bufp->chgCData(oldp+2162,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 2U))),3);
        bufp->chgBit(oldp+2163,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x18U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x18U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x18U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x18U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x18U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2164,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2165,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 4U))));
        bufp->chgBit(oldp+2166,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 3U))));
        bufp->chgBit(oldp+2167,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 2U))));
        bufp->chgCData(oldp+2168,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2169,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2170,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2171,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x18U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2172,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 1U)))));
        bufp->chgBit(oldp+2173,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2174,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x18U] >> 1U))));
        bufp->chgCData(oldp+2175,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x18U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2176,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x18U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x18U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2177,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2178,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x18U])));
        bufp->chgBit(oldp+2179,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2180,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2181,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2182,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2183,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2184,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2185,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2186,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2187,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2188,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2189,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2190,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2191,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2192,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2193,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2194,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2195,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2196,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2197,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2198,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2199,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2200,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2201,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2202,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2203,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2204,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2205,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2206,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2207,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2208,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2209,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2210,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2211,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x19U]),17);
        bufp->chgSData(oldp+2212,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2213,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2214,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2215,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2216,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2217,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2218,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2219,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2220,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 0xeU))),3);
        bufp->chgBit(oldp+2221,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x19U] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x19U] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x19U] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2222,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2223,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 0x10U))));
        bufp->chgBit(oldp+2224,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 0xfU))));
        bufp->chgBit(oldp+2225,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 0xeU))));
        bufp->chgCData(oldp+2226,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 0xbU))),3);
        bufp->chgBit(oldp+2227,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x19U] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x19U] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x19U] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2228,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2229,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 0xdU))));
        bufp->chgBit(oldp+2230,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 0xcU))));
        bufp->chgBit(oldp+2231,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 0xbU))));
        bufp->chgCData(oldp+2232,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 8U))),3);
        bufp->chgBit(oldp+2233,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x19U] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x19U] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x19U] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2234,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2235,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 0xaU))));
        bufp->chgBit(oldp+2236,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 9U))));
        bufp->chgBit(oldp+2237,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 8U))));
        bufp->chgCData(oldp+2238,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 5U))),3);
        bufp->chgBit(oldp+2239,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x19U] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x19U] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x19U] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2240,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2241,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 7U))));
        bufp->chgBit(oldp+2242,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 6U))));
        bufp->chgBit(oldp+2243,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 5U))));
        bufp->chgCData(oldp+2244,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 2U))),3);
        bufp->chgBit(oldp+2245,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x19U] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x19U] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x19U] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x19U] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x19U] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2246,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2247,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 4U))));
        bufp->chgBit(oldp+2248,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 3U))));
        bufp->chgBit(oldp+2249,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 2U))));
        bufp->chgCData(oldp+2250,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2251,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2252,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2253,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x19U] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2254,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 1U)))));
        bufp->chgBit(oldp+2255,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2256,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x19U] >> 1U))));
        bufp->chgCData(oldp+2257,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x19U] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2258,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x19U] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x19U]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2259,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2260,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x19U])));
        bufp->chgBit(oldp+2261,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2262,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2263,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2264,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2265,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2266,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2267,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2268,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2269,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2270,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2271,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2272,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2273,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2274,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2275,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2276,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2277,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2278,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2279,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2280,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2281,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2282,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2283,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2284,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2285,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2286,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2287,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2288,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2289,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2290,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2291,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2292,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2293,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x1aU]),17);
        bufp->chgSData(oldp+2294,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2295,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2296,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2297,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2298,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2299,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2300,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2301,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2302,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 0xeU))),3);
        bufp->chgBit(oldp+2303,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2304,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2305,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 0x10U))));
        bufp->chgBit(oldp+2306,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 0xfU))));
        bufp->chgBit(oldp+2307,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 0xeU))));
        bufp->chgCData(oldp+2308,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 0xbU))),3);
        bufp->chgBit(oldp+2309,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 0xdU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 0xcU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 0xcU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 0xdU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 0xbU))))));
        bufp->chgBit(oldp+2310,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s));
        bufp->chgBit(oldp+2311,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 0xdU))));
        bufp->chgBit(oldp+2312,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 0xcU))));
        bufp->chgBit(oldp+2313,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 0xbU))));
        bufp->chgCData(oldp+2314,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 8U))),3);
        bufp->chgBit(oldp+2315,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 0xaU) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 9U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 9U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 0xaU)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 8U))))));
        bufp->chgBit(oldp+2316,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s));
        bufp->chgBit(oldp+2317,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 0xaU))));
        bufp->chgBit(oldp+2318,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 9U))));
        bufp->chgBit(oldp+2319,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 8U))));
        bufp->chgCData(oldp+2320,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 5U))),3);
        bufp->chgBit(oldp+2321,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 7U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 6U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 6U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 7U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 5U))))));
        bufp->chgBit(oldp+2322,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s));
        bufp->chgBit(oldp+2323,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 7U))));
        bufp->chgBit(oldp+2324,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 6U))));
        bufp->chgBit(oldp+2325,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 5U))));
        bufp->chgCData(oldp+2326,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 2U))),3);
        bufp->chgBit(oldp+2327,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1aU] >> 4U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1aU] 
                                           >> 3U)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1aU] 
                                            >> 3U) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x1aU] 
                                              >> 4U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1aU] 
                                             >> 2U))))));
        bufp->chgBit(oldp+2328,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s));
        bufp->chgBit(oldp+2329,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 4U))));
        bufp->chgBit(oldp+2330,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 3U))));
        bufp->chgBit(oldp+2331,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 2U))));
        bufp->chgCData(oldp+2332,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s)))),3);
        bufp->chgBit(oldp+2333,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa1__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa0__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa2__s)))));
        bufp->chgBit(oldp+2334,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s));
        bufp->chgCData(oldp+2335,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s) 
                                               << 1U) 
                                              | (1U 
                                                 & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                                    [0x1aU] 
                                                    >> 1U))))),3);
        bufp->chgBit(oldp+2336,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa4__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa3__s)) 
                                    & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 1U)))));
        bufp->chgBit(oldp+2337,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s));
        bufp->chgBit(oldp+2338,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1aU] >> 1U))));
        bufp->chgCData(oldp+2339,(((4U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                          [0x1aU] << 2U)) 
                                   | (3U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                            >> 3U)))),3);
        bufp->chgBit(oldp+2340,((1U & ((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                        [0x1aU] & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                   >> 4U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                            >> 4U) 
                                           | vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1aU]) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                             >> 3U))))));
        bufp->chgBit(oldp+2341,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s));
        bufp->chgBit(oldp+2342,((1U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                 [0x1aU])));
        bufp->chgBit(oldp+2343,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 4U))));
        bufp->chgBit(oldp+2344,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 3U))));
        bufp->chgCData(oldp+2345,((7U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))),3);
        bufp->chgBit(oldp+2346,((1U & ((IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (6U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                          & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))))));
        bufp->chgBit(oldp+2347,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s));
        bufp->chgBit(oldp+2348,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 2U))));
        bufp->chgBit(oldp+2349,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 1U))));
        bufp->chgBit(oldp+2350,((1U & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group))));
        bufp->chgCData(oldp+2351,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s)))),3);
        bufp->chgBit(oldp+2352,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa6__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa5__s)) 
                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa7__s)))));
        bufp->chgBit(oldp+2353,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s));
        bufp->chgCData(oldp+2354,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                               >> 5U)))),3);
        bufp->chgBit(oldp+2355,((1U & (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s) 
                                        & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                           >> 6U)) 
                                       | ((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                            >> 6U) 
                                           | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa8__s)) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                             >> 5U))))));
        bufp->chgBit(oldp+2356,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s));
        bufp->chgBit(oldp+2357,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 6U))));
        bufp->chgBit(oldp+2358,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 5U))));
        bufp->chgCData(oldp+2359,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                    >> 0xaU))))),3);
        bufp->chgBit(oldp+2360,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaA__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csa9__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xaU)))));
        bufp->chgBit(oldp+2361,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s));
        bufp->chgBit(oldp+2362,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xaU))));
        bufp->chgCData(oldp+2363,((7U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+2364,((1U & ((IData)((0x300U 
                                                == 
                                                (0x300U 
                                                 & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                       | ((IData)((0U 
                                                   != 
                                                   (0x300U 
                                                    & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group)))) 
                                          & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                             >> 7U))))));
        bufp->chgBit(oldp+2365,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s));
        bufp->chgBit(oldp+2366,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 9U))));
        bufp->chgBit(oldp+2367,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 8U))));
        bufp->chgBit(oldp+2368,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 7U))));
        bufp->chgCData(oldp+2369,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 2U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s) 
                                               << 1U) 
                                              | (1U 
                                                 & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                                    >> 0xbU))))),3);
        bufp->chgBit(oldp+2370,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s) 
                                  & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s)) 
                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaC__s) 
                                     | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__Vcellout__csaB__s)) 
                                    & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xbU)))));
        bufp->chgBit(oldp+2371,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xbU))));
        bufp->chgCData(oldp+2372,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.__PVT__fifth_s) 
                                    << 2U) | (3U & 
                                              ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                               >> 0xcU)))),3);
        bufp->chgBit(oldp+2373,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xdU))));
        bufp->chgBit(oldp+2374,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut.cout_group) 
                                       >> 0xcU))));
        bufp->chgIData(oldp+2375,(vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                  [0x1bU]),17);
        bufp->chgSData(oldp+2376,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout_group),14);
        bufp->chgBit(oldp+2377,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.cout));
        bufp->chgBit(oldp+2378,((1U & ((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s) 
                                       ^ VL_REDXOR_16(
                                                      (0x3000U 
                                                       & (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut.cout_group)))))));
        bufp->chgCData(oldp+2379,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s) 
                                    << 4U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa1__s) 
                                               << 3U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa2__s) 
                                                  << 2U) 
                                                 | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa3__s) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa4__s)))))),5);
        bufp->chgCData(oldp+2380,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa5__s) 
                                    << 3U) | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa6__s) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa7__s) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa8__s))))),4);
        bufp->chgCData(oldp+2381,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa9__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaA__s))),2);
        bufp->chgCData(oldp+2382,((((IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaB__s) 
                                    << 1U) | (IData)(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csaC__s))),2);
        bufp->chgBit(oldp+2383,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__PVT__fifth_s));
        bufp->chgCData(oldp+2384,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 0xeU))),3);
        bufp->chgBit(oldp+2385,((1U & (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 0x10U) 
                                        & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                           [0x1bU] 
                                           >> 0xfU)) 
                                       | (((vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                            [0x1bU] 
                                            >> 0xfU) 
                                           | (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                              [0x1bU] 
                                              >> 0x10U)) 
                                          & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                             [0x1bU] 
                                             >> 0xeU))))));
        bufp->chgBit(oldp+2386,(vlSymsp->TOP__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut.__Vcellout__csa0__s));
        bufp->chgBit(oldp+2387,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] >> 0x10U))));
        bufp->chgBit(oldp+2388,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] >> 0xfU))));
        bufp->chgBit(oldp+2389,((1U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                       [0x1bU] >> 0xeU))));
        bufp->chgCData(oldp+2390,((7U & (vlSelf->booth_wallace_multiplier__DOT__switch_outputs
                                         [0x1bU] >> 0xbU))),3);
    }
}
