// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu.h for the primary calling header

#include "verilated.h"

#include "Vfpu_walloc_17bits.h"

VL_ATTR_COLD void Vfpu_walloc_17bits___ctor_var_reset(Vfpu_walloc_17bits* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vfpu_walloc_17bits___ctor_var_reset\n"); );
    // Body
    vlSelf->src_in = VL_RAND_RESET_I(17);
    vlSelf->cin = VL_RAND_RESET_I(14);
    vlSelf->cout_group = VL_RAND_RESET_I(14);
    vlSelf->cout = VL_RAND_RESET_I(1);
    vlSelf->s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa0__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa1__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa2__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa3__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa4__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa5__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa6__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa7__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa8__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csa9__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csaA__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csaB__s = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__csaC__s = VL_RAND_RESET_I(1);
    vlSelf->__PVT__fifth_s = VL_RAND_RESET_I(1);
}
