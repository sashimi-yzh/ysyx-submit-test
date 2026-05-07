// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TX.h"
#include "VysyxSoCFull__Syms.h"

void VysyxSoCFull_TX___ctor_var_reset(VysyxSoCFull_TX* vlSelf);

VysyxSoCFull_TX::VysyxSoCFull_TX(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull_TX___ctor_var_reset(this);
}

void VysyxSoCFull_TX::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull_TX::~VysyxSoCFull_TX() {
}
