// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpu.h for the primary calling header

#include "verilated.h"

#include "Vfpu__Syms.h"
#include "Vfpu___024root.h"

void Vfpu___024root___ctor_var_reset(Vfpu___024root* vlSelf);

Vfpu___024root::Vfpu___024root(Vfpu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfpu___024root___ctor_var_reset(this);
}

void Vfpu___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfpu___024root::~Vfpu___024root() {
}
