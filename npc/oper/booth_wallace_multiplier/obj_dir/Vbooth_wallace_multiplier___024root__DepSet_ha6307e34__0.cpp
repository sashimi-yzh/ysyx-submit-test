// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbooth_wallace_multiplier.h for the primary calling header

#include "verilated.h"

#include "Vbooth_wallace_multiplier___024root.h"

VL_INLINE_OPT void Vbooth_wallace_multiplier___024root___ico_sequent__TOP__0(Vbooth_wallace_multiplier___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbooth_wallace_multiplier___024root___ico_sequent__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h7a44ad7e__0;
    VlWide<3>/*95:0*/ __Vtemp_h7a44ad7e__1;
    VlWide<3>/*95:0*/ __Vtemp_h51bbd105__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8806feb__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807036__0;
    VlWide<3>/*95:0*/ __Vtemp_haddb19dc__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807036__1;
    VlWide<3>/*95:0*/ __Vtemp_h3b9ddfff__0;
    VlWide<3>/*95:0*/ __Vtemp_he995d310__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807036__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8807075__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88070b7__0;
    VlWide<3>/*95:0*/ __Vtemp_hf94bcafb__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88070b7__1;
    VlWide<3>/*95:0*/ __Vtemp_h5e811324__0;
    VlWide<3>/*95:0*/ __Vtemp_h7e597138__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88070b7__2;
    VlWide<3>/*95:0*/ __Vtemp_ha88070f8__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807131__0;
    VlWide<3>/*95:0*/ __Vtemp_he39f2004__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807131__1;
    VlWide<3>/*95:0*/ __Vtemp_hc87906f1__0;
    VlWide<3>/*95:0*/ __Vtemp_h8065c8cb__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8807131__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8807172__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804db2__0;
    VlWide<3>/*95:0*/ __Vtemp_h8eb596a7__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804db2__1;
    VlWide<3>/*95:0*/ __Vtemp_h5e262006__0;
    VlWide<3>/*95:0*/ __Vtemp_ha0c8a20e__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804db2__2;
    VlWide<3>/*95:0*/ __Vtemp_ha88049f1__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804a38__0;
    VlWide<3>/*95:0*/ __Vtemp_h93cf2a80__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804a38__1;
    VlWide<3>/*95:0*/ __Vtemp_ha1bdd602__0;
    VlWide<3>/*95:0*/ __Vtemp_ha719e24e__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804a38__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8804a77__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804ab5__0;
    VlWide<3>/*95:0*/ __Vtemp_h9b9bd666__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804ab5__1;
    VlWide<3>/*95:0*/ __Vtemp_hd346354b__0;
    VlWide<3>/*95:0*/ __Vtemp_h8a79af15__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804ab5__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8804af6__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804b2b__0;
    VlWide<3>/*95:0*/ __Vtemp_h1a878347__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804b2b__1;
    VlWide<3>/*95:0*/ __Vtemp_hbf3a9ce4__0;
    VlWide<3>/*95:0*/ __Vtemp_h1f95bf8b__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8804b2b__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8804b6c__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801740__0;
    VlWide<3>/*95:0*/ __Vtemp_h8359add7__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801740__1;
    VlWide<3>/*95:0*/ __Vtemp_h74f979a8__0;
    VlWide<3>/*95:0*/ __Vtemp_h61471400__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801740__2;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffbff__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffbba__0;
    VlWide<3>/*95:0*/ __Vtemp_hfd54cb3a__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffbba__1;
    VlWide<3>/*95:0*/ __Vtemp_h1331fac1__0;
    VlWide<3>/*95:0*/ __Vtemp_h9b314717__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffbba__2;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffc79__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffc53__0;
    VlWide<3>/*95:0*/ __Vtemp_h262d7eec__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffc53__1;
    VlWide<3>/*95:0*/ __Vtemp_hc1a7b4a4__0;
    VlWide<3>/*95:0*/ __Vtemp_he3a0354b__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffc53__2;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffd14__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffcbd__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8dd53d7__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffcbd__1;
    VlWide<3>/*95:0*/ __Vtemp_h8f1a8c71__0;
    VlWide<3>/*95:0*/ __Vtemp_h783c2462__0;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffcbd__2;
    VlWide<3>/*95:0*/ __Vtemp_ha87ffd7e__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801956__0;
    VlWide<3>/*95:0*/ __Vtemp_h35532d5c__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801956__1;
    VlWide<3>/*95:0*/ __Vtemp_h0587ec26__0;
    VlWide<3>/*95:0*/ __Vtemp_hdbbda542__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801956__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8801615__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88015cc__0;
    VlWide<3>/*95:0*/ __Vtemp_h191ec45f__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88015cc__1;
    VlWide<3>/*95:0*/ __Vtemp_hf0d44295__0;
    VlWide<3>/*95:0*/ __Vtemp_h38f5c37f__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88015cc__2;
    VlWide<3>/*95:0*/ __Vtemp_ha880168b__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801651__0;
    VlWide<3>/*95:0*/ __Vtemp_h6db4c5ac__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801651__1;
    VlWide<3>/*95:0*/ __Vtemp_h54463abc__0;
    VlWide<3>/*95:0*/ __Vtemp_h39efbe44__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8801651__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8801712__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88016d7__0;
    VlWide<3>/*95:0*/ __Vtemp_hc88418eb__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88016d7__1;
    VlWide<3>/*95:0*/ __Vtemp_h3884aed8__0;
    VlWide<3>/*95:0*/ __Vtemp_hf5073a35__0;
    VlWide<3>/*95:0*/ __Vtemp_ha88016d7__2;
    VlWide<3>/*95:0*/ __Vtemp_ha8806768__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8806394__0;
    VlWide<3>/*95:0*/ __Vtemp_h293e3e30__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8806394__1;
    VlWide<3>/*95:0*/ __Vtemp_h9f1bad5b__0;
    VlWide<3>/*95:0*/ __Vtemp_hae88bb2e__0;
    VlWide<3>/*95:0*/ __Vtemp_ha8806394__2;
    VlWide<3>/*95:0*/ __Vtemp_ha88067d3__0;
    // Body
    vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[0U] 
        = vlSelf->multiplicand;
    if (vlSelf->is_signed) {
        vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[1U] 
            = (IData)((0xfffffffffULL & (- (QData)((IData)(
                                                           (vlSelf->multiplicand 
                                                            >> 0x1fU))))));
        vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[2U] 
            = (IData)(((0xfffffffffULL & (- (QData)((IData)(
                                                            (vlSelf->multiplicand 
                                                             >> 0x1fU))))) 
                       >> 0x20U));
        vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
            = (((QData)((IData)((3U & (- (IData)((vlSelf->multiplier 
                                                  >> 0x1fU)))))) 
                << 0x21U) | ((QData)((IData)(vlSelf->multiplier)) 
                             << 1U));
    } else {
        vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[2U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
            = ((QData)((IData)(vlSelf->multiplier)) 
               << 1U);
    }
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hed3c5934__0 
        = (1U & ((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                          >> 1U)) ^ (IData)(vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc3505cf3__0 
        = (1U & VL_REDXOR_4((0xcULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hf9f0876d__0 
        = (1U & VL_REDXOR_8((0x30ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hfe0a41fe__0 
        = (1U & VL_REDXOR_8((0xc0ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc5e42a69__0 
        = (1U & VL_REDXOR_16((0x300ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hbaa102cc__0 
        = (1U & VL_REDXOR_16((0xc00ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb4e6b126__0 
        = (1U & VL_REDXOR_16((0x3000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_haed8dbe3__0 
        = (1U & VL_REDXOR_16((0xc000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb84f77ab__0 
        = (1U & VL_REDXOR_32((0x30000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h937272c0__0 
        = (1U & VL_REDXOR_32((0xc0000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8cb8ba8a__0 
        = (1U & VL_REDXOR_32((0x300000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc18fac15__0 
        = (1U & VL_REDXOR_32((0xc00000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc411b621__0 
        = (1U & VL_REDXOR_32((0x3000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hcef34518__0 
        = (1U & VL_REDXOR_32((0xc000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h91e9dc0e__0 
        = (1U & VL_REDXOR_32((0x30000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8fc047d7__0 
        = (1U & VL_REDXOR_32((0xc0000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h9b1da5a9__0 
        = (1U & VL_REDXOR_64((0x300000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)));
    VL_NEGATE_W(3, __Vtemp_h7a44ad7e__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext);
    VL_NEGATE_W(3, __Vtemp_h7a44ad7e__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h51bbd105__0, __Vtemp_h7a44ad7e__1, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8806feb__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 1U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 2U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hed3c5934__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][0U] 
            = __Vtemp_h7a44ad7e__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][1U] 
            = __Vtemp_h7a44ad7e__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][2U] 
            = (0xfU & __Vtemp_h7a44ad7e__0[2U]);
    } else if ((1U & ((~ ((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                   >> 1U)) | (IData)(vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 2U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][0U] 
            = __Vtemp_h51bbd105__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][1U] 
            = __Vtemp_h51bbd105__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][2U] 
            = (0xfU & __Vtemp_h51bbd105__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 2U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hed3c5934__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][0U] 
            = vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][1U] 
            = vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][2U] 
            = (0xfU & vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext[2U]);
    } else if ((3ULL == (7ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][0U] 
            = __Vtemp_ha8806feb__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][1U] 
            = __Vtemp_ha8806feb__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][2U] 
            = (0xfU & __Vtemp_ha8806feb__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807036__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 2U);
    VL_NEGATE_W(3, __Vtemp_haddb19dc__0, __Vtemp_ha8807036__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807036__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 2U);
    VL_NEGATE_W(3, __Vtemp_h3b9ddfff__0, __Vtemp_ha8807036__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_he995d310__0, __Vtemp_h3b9ddfff__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807036__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 2U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807075__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 3U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 4U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc3505cf3__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][0U] 
            = __Vtemp_haddb19dc__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][1U] 
            = __Vtemp_haddb19dc__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][2U] 
            = (0xfU & __Vtemp_haddb19dc__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xcULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 4U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][0U] 
            = __Vtemp_he995d310__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][1U] 
            = __Vtemp_he995d310__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][2U] 
            = (0xfU & __Vtemp_he995d310__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 4U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc3505cf3__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][0U] 
            = __Vtemp_ha8807036__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][1U] 
            = __Vtemp_ha8807036__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][2U] 
            = (0xfU & __Vtemp_ha8807036__2[2U]);
    } else if ((0xcULL == (0x1cULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][0U] 
            = __Vtemp_ha8807075__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][1U] 
            = __Vtemp_ha8807075__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][2U] 
            = (0xfU & __Vtemp_ha8807075__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[1U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88070b7__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 4U);
    VL_NEGATE_W(3, __Vtemp_hf94bcafb__0, __Vtemp_ha88070b7__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88070b7__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 4U);
    VL_NEGATE_W(3, __Vtemp_h5e811324__0, __Vtemp_ha88070b7__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h7e597138__0, __Vtemp_h5e811324__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88070b7__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 4U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88070f8__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 5U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 6U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hf9f0876d__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][0U] 
            = __Vtemp_hf94bcafb__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][1U] 
            = __Vtemp_hf94bcafb__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][2U] 
            = (0xfU & __Vtemp_hf94bcafb__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x30ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 6U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][0U] 
            = __Vtemp_h7e597138__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][1U] 
            = __Vtemp_h7e597138__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][2U] 
            = (0xfU & __Vtemp_h7e597138__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 6U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hf9f0876d__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][0U] 
            = __Vtemp_ha88070b7__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][1U] 
            = __Vtemp_ha88070b7__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][2U] 
            = (0xfU & __Vtemp_ha88070b7__2[2U]);
    } else if ((0x30ULL == (0x70ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][0U] 
            = __Vtemp_ha88070f8__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][1U] 
            = __Vtemp_ha88070f8__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][2U] 
            = (0xfU & __Vtemp_ha88070f8__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[2U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807131__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 6U);
    VL_NEGATE_W(3, __Vtemp_he39f2004__0, __Vtemp_ha8807131__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807131__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 6U);
    VL_NEGATE_W(3, __Vtemp_hc87906f1__0, __Vtemp_ha8807131__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h8065c8cb__0, __Vtemp_hc87906f1__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807131__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 6U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8807172__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 7U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 8U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hfe0a41fe__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][0U] 
            = __Vtemp_he39f2004__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][1U] 
            = __Vtemp_he39f2004__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][2U] 
            = (0xfU & __Vtemp_he39f2004__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xc0ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 8U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][0U] 
            = __Vtemp_h8065c8cb__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][1U] 
            = __Vtemp_h8065c8cb__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][2U] 
            = (0xfU & __Vtemp_h8065c8cb__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 8U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hfe0a41fe__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][0U] 
            = __Vtemp_ha8807131__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][1U] 
            = __Vtemp_ha8807131__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][2U] 
            = (0xfU & __Vtemp_ha8807131__2[2U]);
    } else if ((0xc0ULL == (0x1c0ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][0U] 
            = __Vtemp_ha8807172__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][1U] 
            = __Vtemp_ha8807172__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][2U] 
            = (0xfU & __Vtemp_ha8807172__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[3U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804db2__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 8U);
    VL_NEGATE_W(3, __Vtemp_h8eb596a7__0, __Vtemp_ha8804db2__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804db2__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 8U);
    VL_NEGATE_W(3, __Vtemp_h5e262006__0, __Vtemp_ha8804db2__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha0c8a20e__0, __Vtemp_h5e262006__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804db2__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 8U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88049f1__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 9U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0xaU)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc5e42a69__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][0U] 
            = __Vtemp_h8eb596a7__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][1U] 
            = __Vtemp_h8eb596a7__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][2U] 
            = (0xfU & __Vtemp_h8eb596a7__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x300ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0xaU))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][0U] 
            = __Vtemp_ha0c8a20e__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][1U] 
            = __Vtemp_ha0c8a20e__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][2U] 
            = (0xfU & __Vtemp_ha0c8a20e__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0xaU))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc5e42a69__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][0U] 
            = __Vtemp_ha8804db2__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][1U] 
            = __Vtemp_ha8804db2__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][2U] 
            = (0xfU & __Vtemp_ha8804db2__2[2U]);
    } else if ((0x300ULL == (0x700ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][0U] 
            = __Vtemp_ha88049f1__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][1U] 
            = __Vtemp_ha88049f1__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][2U] 
            = (0xfU & __Vtemp_ha88049f1__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[4U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804a38__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xaU);
    VL_NEGATE_W(3, __Vtemp_h93cf2a80__0, __Vtemp_ha8804a38__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804a38__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xaU);
    VL_NEGATE_W(3, __Vtemp_ha1bdd602__0, __Vtemp_ha8804a38__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha719e24e__0, __Vtemp_ha1bdd602__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804a38__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xaU);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804a77__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xbU);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0xcU)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hbaa102cc__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][0U] 
            = __Vtemp_h93cf2a80__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][1U] 
            = __Vtemp_h93cf2a80__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][2U] 
            = (0xfU & __Vtemp_h93cf2a80__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xc00ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0xcU))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][0U] 
            = __Vtemp_ha719e24e__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][1U] 
            = __Vtemp_ha719e24e__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][2U] 
            = (0xfU & __Vtemp_ha719e24e__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0xcU))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hbaa102cc__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][0U] 
            = __Vtemp_ha8804a38__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][1U] 
            = __Vtemp_ha8804a38__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][2U] 
            = (0xfU & __Vtemp_ha8804a38__2[2U]);
    } else if ((0xc00ULL == (0x1c00ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][0U] 
            = __Vtemp_ha8804a77__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][1U] 
            = __Vtemp_ha8804a77__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][2U] 
            = (0xfU & __Vtemp_ha8804a77__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[5U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804ab5__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xcU);
    VL_NEGATE_W(3, __Vtemp_h9b9bd666__0, __Vtemp_ha8804ab5__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804ab5__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xcU);
    VL_NEGATE_W(3, __Vtemp_hd346354b__0, __Vtemp_ha8804ab5__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h8a79af15__0, __Vtemp_hd346354b__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804ab5__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xcU);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804af6__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xdU);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0xeU)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb4e6b126__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][0U] 
            = __Vtemp_h9b9bd666__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][1U] 
            = __Vtemp_h9b9bd666__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][2U] 
            = (0xfU & __Vtemp_h9b9bd666__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x3000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0xeU))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][0U] 
            = __Vtemp_h8a79af15__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][1U] 
            = __Vtemp_h8a79af15__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][2U] 
            = (0xfU & __Vtemp_h8a79af15__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0xeU))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb4e6b126__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][0U] 
            = __Vtemp_ha8804ab5__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][1U] 
            = __Vtemp_ha8804ab5__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][2U] 
            = (0xfU & __Vtemp_ha8804ab5__2[2U]);
    } else if ((0x3000ULL == (0x7000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][0U] 
            = __Vtemp_ha8804af6__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][1U] 
            = __Vtemp_ha8804af6__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][2U] 
            = (0xfU & __Vtemp_ha8804af6__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[6U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804b2b__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xeU);
    VL_NEGATE_W(3, __Vtemp_h1a878347__0, __Vtemp_ha8804b2b__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804b2b__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xeU);
    VL_NEGATE_W(3, __Vtemp_hbf3a9ce4__0, __Vtemp_ha8804b2b__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h1f95bf8b__0, __Vtemp_hbf3a9ce4__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804b2b__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xeU);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8804b6c__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0xfU);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x10U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_haed8dbe3__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][0U] 
            = __Vtemp_h1a878347__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][1U] 
            = __Vtemp_h1a878347__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][2U] 
            = (0xfU & __Vtemp_h1a878347__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xc000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x10U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][0U] 
            = __Vtemp_h1f95bf8b__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][1U] 
            = __Vtemp_h1f95bf8b__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][2U] 
            = (0xfU & __Vtemp_h1f95bf8b__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x10U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_haed8dbe3__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][0U] 
            = __Vtemp_ha8804b2b__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][1U] 
            = __Vtemp_ha8804b2b__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][2U] 
            = (0xfU & __Vtemp_ha8804b2b__2[2U]);
    } else if ((0xc000ULL == (0x1c000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][0U] 
            = __Vtemp_ha8804b6c__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][1U] 
            = __Vtemp_ha8804b6c__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][2U] 
            = (0xfU & __Vtemp_ha8804b6c__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[7U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801740__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x10U);
    VL_NEGATE_W(3, __Vtemp_h8359add7__0, __Vtemp_ha8801740__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801740__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x10U);
    VL_NEGATE_W(3, __Vtemp_h74f979a8__0, __Vtemp_ha8801740__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h61471400__0, __Vtemp_h74f979a8__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801740__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x10U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffbff__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x11U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x12U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb84f77ab__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][0U] 
            = __Vtemp_h8359add7__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][1U] 
            = __Vtemp_h8359add7__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][2U] 
            = (0xfU & __Vtemp_h8359add7__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x30000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x12U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][0U] 
            = __Vtemp_h61471400__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][1U] 
            = __Vtemp_h61471400__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][2U] 
            = (0xfU & __Vtemp_h61471400__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x12U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hb84f77ab__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][0U] 
            = __Vtemp_ha8801740__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][1U] 
            = __Vtemp_ha8801740__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][2U] 
            = (0xfU & __Vtemp_ha8801740__2[2U]);
    } else if ((0x30000ULL == (0x70000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][0U] 
            = __Vtemp_ha87ffbff__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][1U] 
            = __Vtemp_ha87ffbff__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][2U] 
            = (0xfU & __Vtemp_ha87ffbff__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[8U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffbba__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x12U);
    VL_NEGATE_W(3, __Vtemp_hfd54cb3a__0, __Vtemp_ha87ffbba__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffbba__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x12U);
    VL_NEGATE_W(3, __Vtemp_h1331fac1__0, __Vtemp_ha87ffbba__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h9b314717__0, __Vtemp_h1331fac1__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffbba__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x12U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffc79__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x13U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x14U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h937272c0__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][0U] 
            = __Vtemp_hfd54cb3a__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][1U] 
            = __Vtemp_hfd54cb3a__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][2U] 
            = (0xfU & __Vtemp_hfd54cb3a__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xc0000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x14U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][0U] 
            = __Vtemp_h9b314717__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][1U] 
            = __Vtemp_h9b314717__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][2U] 
            = (0xfU & __Vtemp_h9b314717__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x14U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h937272c0__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][0U] 
            = __Vtemp_ha87ffbba__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][1U] 
            = __Vtemp_ha87ffbba__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][2U] 
            = (0xfU & __Vtemp_ha87ffbba__2[2U]);
    } else if ((0xc0000ULL == (0x1c0000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][0U] 
            = __Vtemp_ha87ffc79__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][1U] 
            = __Vtemp_ha87ffc79__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][2U] 
            = (0xfU & __Vtemp_ha87ffc79__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[9U][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffc53__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x14U);
    VL_NEGATE_W(3, __Vtemp_h262d7eec__0, __Vtemp_ha87ffc53__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffc53__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x14U);
    VL_NEGATE_W(3, __Vtemp_hc1a7b4a4__0, __Vtemp_ha87ffc53__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_he3a0354b__0, __Vtemp_hc1a7b4a4__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffc53__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x14U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffd14__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x15U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x16U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8cb8ba8a__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][0U] 
            = __Vtemp_h262d7eec__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][1U] 
            = __Vtemp_h262d7eec__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][2U] 
            = (0xfU & __Vtemp_h262d7eec__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x300000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x16U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][0U] 
            = __Vtemp_he3a0354b__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][1U] 
            = __Vtemp_he3a0354b__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][2U] 
            = (0xfU & __Vtemp_he3a0354b__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x16U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8cb8ba8a__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][0U] 
            = __Vtemp_ha87ffc53__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][1U] 
            = __Vtemp_ha87ffc53__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][2U] 
            = (0xfU & __Vtemp_ha87ffc53__2[2U]);
    } else if ((0x300000ULL == (0x700000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][0U] 
            = __Vtemp_ha87ffd14__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][1U] 
            = __Vtemp_ha87ffd14__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][2U] 
            = (0xfU & __Vtemp_ha87ffd14__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xaU][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffcbd__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x16U);
    VL_NEGATE_W(3, __Vtemp_ha8dd53d7__0, __Vtemp_ha87ffcbd__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffcbd__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x16U);
    VL_NEGATE_W(3, __Vtemp_h8f1a8c71__0, __Vtemp_ha87ffcbd__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h783c2462__0, __Vtemp_h8f1a8c71__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffcbd__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x16U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha87ffd7e__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x17U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x18U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc18fac15__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][0U] 
            = __Vtemp_ha8dd53d7__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][1U] 
            = __Vtemp_ha8dd53d7__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][2U] 
            = (0xfU & __Vtemp_ha8dd53d7__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xc00000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x18U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][0U] 
            = __Vtemp_h783c2462__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][1U] 
            = __Vtemp_h783c2462__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][2U] 
            = (0xfU & __Vtemp_h783c2462__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x18U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc18fac15__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][0U] 
            = __Vtemp_ha87ffcbd__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][1U] 
            = __Vtemp_ha87ffcbd__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][2U] 
            = (0xfU & __Vtemp_ha87ffcbd__2[2U]);
    } else if ((0xc00000ULL == (0x1c00000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][0U] 
            = __Vtemp_ha87ffd7e__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][1U] 
            = __Vtemp_ha87ffd7e__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][2U] 
            = (0xfU & __Vtemp_ha87ffd7e__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xbU][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801956__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x18U);
    VL_NEGATE_W(3, __Vtemp_h35532d5c__0, __Vtemp_ha8801956__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801956__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x18U);
    VL_NEGATE_W(3, __Vtemp_h0587ec26__0, __Vtemp_ha8801956__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_hdbbda542__0, __Vtemp_h0587ec26__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801956__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x18U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801615__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x19U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x1aU)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc411b621__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][0U] 
            = __Vtemp_h35532d5c__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][1U] 
            = __Vtemp_h35532d5c__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][2U] 
            = (0xfU & __Vtemp_h35532d5c__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x3000000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x1aU))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][0U] 
            = __Vtemp_hdbbda542__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][1U] 
            = __Vtemp_hdbbda542__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][2U] 
            = (0xfU & __Vtemp_hdbbda542__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x1aU))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hc411b621__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][0U] 
            = __Vtemp_ha8801956__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][1U] 
            = __Vtemp_ha8801956__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][2U] 
            = (0xfU & __Vtemp_ha8801956__2[2U]);
    } else if ((0x3000000ULL == (0x7000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][0U] 
            = __Vtemp_ha8801615__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][1U] 
            = __Vtemp_ha8801615__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][2U] 
            = (0xfU & __Vtemp_ha8801615__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xcU][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88015cc__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1aU);
    VL_NEGATE_W(3, __Vtemp_h191ec45f__0, __Vtemp_ha88015cc__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88015cc__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1aU);
    VL_NEGATE_W(3, __Vtemp_hf0d44295__0, __Vtemp_ha88015cc__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h38f5c37f__0, __Vtemp_hf0d44295__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88015cc__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1aU);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha880168b__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1bU);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x1cU)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hcef34518__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][0U] 
            = __Vtemp_h191ec45f__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][1U] 
            = __Vtemp_h191ec45f__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][2U] 
            = (0xfU & __Vtemp_h191ec45f__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xc000000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x1cU))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][0U] 
            = __Vtemp_h38f5c37f__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][1U] 
            = __Vtemp_h38f5c37f__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][2U] 
            = (0xfU & __Vtemp_h38f5c37f__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x1cU))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_hcef34518__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][0U] 
            = __Vtemp_ha88015cc__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][1U] 
            = __Vtemp_ha88015cc__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][2U] 
            = (0xfU & __Vtemp_ha88015cc__2[2U]);
    } else if ((0xc000000ULL == (0x1c000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][0U] 
            = __Vtemp_ha880168b__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][1U] 
            = __Vtemp_ha880168b__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][2U] 
            = (0xfU & __Vtemp_ha880168b__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xdU][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801651__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1cU);
    VL_NEGATE_W(3, __Vtemp_h6db4c5ac__0, __Vtemp_ha8801651__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801651__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1cU);
    VL_NEGATE_W(3, __Vtemp_h54463abc__0, __Vtemp_ha8801651__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_h39efbe44__0, __Vtemp_h54463abc__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801651__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1cU);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8801712__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1dU);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x1eU)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h91e9dc0e__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][0U] 
            = __Vtemp_h6db4c5ac__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][1U] 
            = __Vtemp_h6db4c5ac__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][2U] 
            = (0xfU & __Vtemp_h6db4c5ac__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x30000000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x1eU))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][0U] 
            = __Vtemp_h39efbe44__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][1U] 
            = __Vtemp_h39efbe44__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][2U] 
            = (0xfU & __Vtemp_h39efbe44__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x1eU))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h91e9dc0e__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][0U] 
            = __Vtemp_ha8801651__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][1U] 
            = __Vtemp_ha8801651__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][2U] 
            = (0xfU & __Vtemp_ha8801651__2[2U]);
    } else if ((0x30000000ULL == (0x70000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][0U] 
            = __Vtemp_ha8801712__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][1U] 
            = __Vtemp_ha8801712__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][2U] 
            = (0xfU & __Vtemp_ha8801712__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xeU][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88016d7__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1eU);
    VL_NEGATE_W(3, __Vtemp_hc88418eb__0, __Vtemp_ha88016d7__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88016d7__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1eU);
    VL_NEGATE_W(3, __Vtemp_h3884aed8__0, __Vtemp_ha88016d7__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_hf5073a35__0, __Vtemp_h3884aed8__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88016d7__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1eU);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8806768__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x1fU);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x20U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8fc047d7__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][0U] 
            = __Vtemp_hc88418eb__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][1U] 
            = __Vtemp_hc88418eb__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][2U] 
            = (0xfU & __Vtemp_hc88418eb__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0xc0000000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x20U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][0U] 
            = __Vtemp_hf5073a35__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][1U] 
            = __Vtemp_hf5073a35__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][2U] 
            = (0xfU & __Vtemp_hf5073a35__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x20U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h8fc047d7__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][0U] 
            = __Vtemp_ha88016d7__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][1U] 
            = __Vtemp_ha88016d7__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][2U] 
            = (0xfU & __Vtemp_ha88016d7__2[2U]);
    } else if ((0xc0000000ULL == (0x1c0000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][0U] 
            = __Vtemp_ha8806768__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][1U] 
            = __Vtemp_ha8806768__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][2U] 
            = (0xfU & __Vtemp_ha8806768__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0xfU][2U] 
            = (0xfU & 0U);
    }
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8806394__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x20U);
    VL_NEGATE_W(3, __Vtemp_h293e3e30__0, __Vtemp_ha8806394__0);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8806394__1, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x20U);
    VL_NEGATE_W(3, __Vtemp_h9f1bad5b__0, __Vtemp_ha8806394__1);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_hae88bb2e__0, __Vtemp_h9f1bad5b__0, 1U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha8806394__2, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x20U);
    VL_SHIFTL_WWI(68,68,32, __Vtemp_ha88067d3__0, vlSelf->booth_wallace_multiplier__DOT__multiplicand_ext, 0x21U);
    if (((IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                  >> 0x22U)) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h9b1da5a9__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][0U] 
            = __Vtemp_h293e3e30__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][1U] 
            = __Vtemp_h293e3e30__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][2U] 
            = (0xfU & __Vtemp_h293e3e30__0[2U]);
    } else if ((1U & ((~ (IData)((0ULL != (0x300000000ULL 
                                           & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext)))) 
                      & (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                                 >> 0x22U))))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][0U] 
            = __Vtemp_hae88bb2e__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][1U] 
            = __Vtemp_hae88bb2e__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][2U] 
            = (0xfU & __Vtemp_hae88bb2e__0[2U]);
    } else if (((~ (IData)((vlSelf->booth_wallace_multiplier__DOT__multiplier_ext 
                            >> 0x22U))) & (IData)(vlSelf->booth_wallace_multiplier__DOT____VdfgTmp_h9b1da5a9__0))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][0U] 
            = __Vtemp_ha8806394__2[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][1U] 
            = __Vtemp_ha8806394__2[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][2U] 
            = (0xfU & __Vtemp_ha8806394__2[2U]);
    } else if ((0x300000000ULL == (0x700000000ULL & vlSelf->booth_wallace_multiplier__DOT__multiplier_ext))) {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][0U] 
            = __Vtemp_ha88067d3__0[0U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][1U] 
            = __Vtemp_ha88067d3__0[1U];
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][2U] 
            = (0xfU & __Vtemp_ha88067d3__0[2U]);
    } else {
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][0U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][1U] = 0U;
        vlSelf->booth_wallace_multiplier__DOT__partial_products[0x10U][2U] 
            = (0xfU & 0U);
    }
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (1U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [0U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (2U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [1U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[1U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [1U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (4U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [2U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[2U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [2U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (8U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [3U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[3U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [3U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x10U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [4U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[4U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [4U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x20U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [5U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[5U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [5U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x40U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [6U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[6U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [6U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x80U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [7U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[7U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [7U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x100U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [8U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [9U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[8U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [8U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [0U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [1U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [2U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                           [3U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [4U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [5U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [6U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [7U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [8U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x200U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                     [9U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xaU][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                               [0xbU][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xcU][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xdU][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xeU][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [0xfU][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[9U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [9U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0x10U][0U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [0U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [1U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [2U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [3U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [4U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [5U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [6U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [7U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [8U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [9U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x400U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                       [0xaU][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xbU][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xcU][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xdU][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xeU][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xfU][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xaU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xaU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0x10U][0U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [0U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [1U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [2U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [3U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [4U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [5U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [6U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [7U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [8U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [9U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xaU][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x800U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                       [0xbU][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xcU][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xdU][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xeU][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xfU][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xbU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xbU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0x10U][0U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [0U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [1U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [2U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [3U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [4U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [5U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [6U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [7U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [8U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [9U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xaU][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xbU][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x1000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                       [0xcU][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xdU][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xeU][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xfU][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xcU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xcU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0x10U][0U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [0U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [1U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [2U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [3U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [4U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [5U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [6U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [7U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [8U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [9U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xaU][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xbU][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xcU][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x2000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                       [0xdU][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xeU][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xfU][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xdU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xdU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0x10U][0U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [0U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [1U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [2U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [3U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [4U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [5U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [6U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [7U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [8U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [9U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xaU][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xbU][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xcU][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xdU][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x4000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                       [0xeU][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xfU][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xeU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xeU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0x10U][0U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [0U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [1U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [2U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                             [3U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [4U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [5U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [6U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                [7U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [8U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [9U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xaU][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [0xbU][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xcU][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xdU][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xeU][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x8000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                       [0xfU][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0xfU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0xfU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0x10U][0U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x10U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x10U]) | (0x10000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0x10U][0U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x11U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x11U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x12U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x12U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x13U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x13U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x14U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x14U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x15U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x15U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x16U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x16U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x17U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x17U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x18U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x18U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x19U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x19U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1aU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1aU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1bU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1bU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1cU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1cU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x1dU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1dU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1dU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][0U] >> 0x1eU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x1dU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1eU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1eU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0U][0U] >> 0x1fU));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][0U] >> 0x1eU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][0U] >> 0x1dU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][0U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][0U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][0U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][0U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][0U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][0U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][0U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][0U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][0U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][0U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][0U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][0U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][0U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x1fU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x1fU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][0U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (1U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x20U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x20U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (2U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [1U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x21U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x21U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (4U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [2U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x22U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x22U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (8U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [3U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x23U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x23U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x10U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [4U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x24U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x24U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x20U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [5U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x25U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x25U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x40U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [6U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x26U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x26U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x80U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [7U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x27U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x27U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x100U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [8U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x28U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x28U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x200U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [9U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x29U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x29U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x400U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0xaU][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2aU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2aU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x800U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0xbU][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2bU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2bU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x1000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0xcU][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2cU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2cU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x2000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0xdU][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2dU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2dU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x4000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0xeU][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2eU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2eU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x8000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0xfU][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x2fU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x2fU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x30U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x30U]) | (0x10000U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0x10U][1U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x31U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x31U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x32U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x32U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x33U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x33U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x34U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x34U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x35U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x35U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x36U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x36U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x37U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x37U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x38U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x38U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x39U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x39U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3aU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3aU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3bU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3bU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3cU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3cU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x1dU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3dU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3dU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][1U] >> 0x1eU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x1dU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3eU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3eU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0U][1U] >> 0x1fU));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][1U] >> 0x1eU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][1U] >> 0x1dU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][1U] >> 0x1cU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][1U] >> 0x1bU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][1U] >> 0x1aU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][1U] >> 0x19U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][1U] >> 0x18U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][1U] >> 0x17U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][1U] >> 0x16U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][1U] >> 0x15U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][1U] >> 0x14U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][1U] >> 0x13U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][1U] >> 0x12U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][1U] >> 0x11U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][1U] >> 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x3fU] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x3fU]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][1U] >> 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (1U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [0U][2U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][2U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][2U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][2U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][2U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][2U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][2U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][2U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][2U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][2U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][2U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][2U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][2U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][2U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][2U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][2U] << 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x40U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x40U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][2U] << 0x10U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][2U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (2U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [1U][2U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][2U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][2U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][2U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][2U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][2U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][2U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][2U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][2U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][2U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][2U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][2U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][2U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][2U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][2U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x41U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x41U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][2U] << 0xfU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][2U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][2U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (4U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [2U][2U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (8U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [3U][2U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][2U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][2U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][2U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][2U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][2U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][2U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][2U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][2U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][2U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][2U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][2U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][2U] << 0xdU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x42U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x42U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][2U] << 0xeU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1fffeU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (1U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [0U][2U] >> 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1fffdU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (2U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [1U][2U] >> 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1fffbU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (4U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                              [2U][2U] >> 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1fff7U & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (8U & vlSelf->booth_wallace_multiplier__DOT__partial_products
                        [3U][2U]));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1ffefU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x10U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [4U][2U] << 1U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1ffdfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x20U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [5U][2U] << 2U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1ffbfU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x40U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [6U][2U] << 3U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1ff7fU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x80U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                 [7U][2U] << 4U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1feffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x100U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [8U][2U] << 5U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1fdffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x200U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [9U][2U] << 6U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1fbffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x400U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xaU][2U] << 7U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1f7ffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x800U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                  [0xbU][2U] << 8U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1efffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x1000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xcU][2U] << 9U)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1dfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x2000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xdU][2U] << 0xaU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x1bfffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x4000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xeU][2U] << 0xbU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0x17fffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x8000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                   [0xfU][2U] << 0xcU)));
    vlSelf->booth_wallace_multiplier__DOT__switch_outputs[0x43U] 
        = ((0xffffU & vlSelf->booth_wallace_multiplier__DOT__switch_outputs
            [0x43U]) | (0x10000U & (vlSelf->booth_wallace_multiplier__DOT__partial_products
                                    [0x10U][2U] << 0xdU)));
}
