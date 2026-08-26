// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_top___ctor_var_reset(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->LSU_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3446524407634464399ull);
    vlSelf->LSU_rmask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15114391294081831391ull);
    vlSelf->LSU_wmask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 66315869969167284ull);
    vlSelf->LSU_writedata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8621591918967330140ull);
    vlSelf->LSU_WEN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4139174640315457831ull);
    vlSelf->LSU_REN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2923086650083657279ull);
    vlSelf->LSU_readdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5454595947310901637ull);
    vlSelf->PC_command = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1288837359877173570ull);
    vlSelf->EXU_inA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9531828074647327223ull);
    vlSelf->EXU_inB = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9377487099893787553ull);
    vlSelf->EXU_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11529933568103740182ull);
    vlSelf->PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12700755172620096637ull);
    vlSelf->dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9558418065809668140ull);
    vlSelf->snpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17955041938888895009ull);
    vlSelf->__PVT__command = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13453452394900071627ull);
    vlSelf->__PVT__rs1_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 544071659820774754ull);
    vlSelf->__VdfgRegularize_he2b63832_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15367874221688210060ull);
    vlSelf->__PVT__clkdiv_0__DOT__cnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14236119770383845724ull);
    vlSelf->__PVT__IDU_0__DOT__isJALR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5246149202446548276ull);
    vlSelf->__PVT__IDU_0__DOT__isADD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8334213873409465367ull);
    vlSelf->__PVT__IDU_0__DOT__isLW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6035066000229272285ull);
    vlSelf->__PVT__IDU_0__DOT__isLBU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3618939125699111747ull);
    vlSelf->__PVT__IDU_0__DOT__isLB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14686421087291650575ull);
    vlSelf->__PVT__IDU_0__DOT__isSW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8548530652802062501ull);
    vlSelf->__PVT__IDU_0__DOT__isSB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10047481134680103685ull);
    vlSelf->__PVT__IDU_0__DOT__isLOAD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11233470253092472184ull);
    vlSelf->__PVT__IDU_0__DOT__isWRITE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3095463806045344290ull);
    vlSelf->__PVT__IDU_0__DOT__isI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17630841040017951095ull);
    vlSelf->IDU_0__DOT____VdfgRegularize_h52656aab_0_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2515204577952603912ull);
    vlSelf->IDU_0__DOT____VdfgRegularize_h52656aab_0_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4930961895721110611ull);
    vlSelf->IDU_0__DOT____VdfgRegularize_h52656aab_0_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16225603173642167387ull);
    vlSelf->__PVT__LSU_0__DOT__val0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12890089465768826232ull);
    vlSelf->__PVT__LSU_0__DOT__val1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4109603144407191250ull);
    vlSelf->__PVT__LSU_0__DOT__val2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17821248515118016228ull);
    vlSelf->__PVT__LSU_0__DOT__rdata4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8987603242583941298ull);
    vlSelf->__Vfunc_pmem_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_pmem_read__2__Vfuncout = 0;
}
