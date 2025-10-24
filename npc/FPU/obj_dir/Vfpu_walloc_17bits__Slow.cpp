// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu.h for the primary calling header

#include "verilated.h"

#include "Vfpu__Syms.h"
#include "Vfpu_walloc_17bits.h"

void Vfpu_walloc_17bits___ctor_var_reset(Vfpu_walloc_17bits* vlSelf);

Vfpu_walloc_17bits::Vfpu_walloc_17bits(Vfpu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfpu_walloc_17bits___ctor_var_reset(this);
}

void Vfpu_walloc_17bits::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfpu_walloc_17bits::~Vfpu_walloc_17bits() {
}
