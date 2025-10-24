// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbooth_wallace_multiplier.h for the primary calling header

#include "verilated.h"

#include "Vbooth_wallace_multiplier__Syms.h"
#include "Vbooth_wallace_multiplier_walloc_17bits.h"

void Vbooth_wallace_multiplier_walloc_17bits___ctor_var_reset(Vbooth_wallace_multiplier_walloc_17bits* vlSelf);

Vbooth_wallace_multiplier_walloc_17bits::Vbooth_wallace_multiplier_walloc_17bits(Vbooth_wallace_multiplier__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vbooth_wallace_multiplier_walloc_17bits___ctor_var_reset(this);
}

void Vbooth_wallace_multiplier_walloc_17bits::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vbooth_wallace_multiplier_walloc_17bits::~Vbooth_wallace_multiplier_walloc_17bits() {
}
