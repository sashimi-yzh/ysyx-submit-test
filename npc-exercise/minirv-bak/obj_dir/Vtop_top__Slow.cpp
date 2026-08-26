// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_top___ctor_var_reset(Vtop_top* vlSelf);

Vtop_top::Vtop_top(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_top___ctor_var_reset(this);
}

void Vtop_top::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_top::~Vtop_top() {
}
