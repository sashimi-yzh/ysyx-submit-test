// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_GPR___ctor_var_reset(Vtop_GPR* vlSelf);

Vtop_GPR::Vtop_GPR(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_GPR___ctor_var_reset(this);
}

void Vtop_GPR::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_GPR::~Vtop_GPR() {
}
