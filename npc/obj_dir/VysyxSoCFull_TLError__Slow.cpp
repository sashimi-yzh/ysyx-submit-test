// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLError.h"
#include "VysyxSoCFull__Syms.h"

void VysyxSoCFull_TLError___ctor_var_reset(VysyxSoCFull_TLError* vlSelf);

VysyxSoCFull_TLError::VysyxSoCFull_TLError(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull_TLError___ctor_var_reset(this);
}

void VysyxSoCFull_TLError::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull_TLError::~VysyxSoCFull_TLError() {
}
