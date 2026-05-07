// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLToAXI4.h"
#include "VysyxSoCFull__Syms.h"

void VysyxSoCFull_TLToAXI4___ctor_var_reset(VysyxSoCFull_TLToAXI4* vlSelf);

VysyxSoCFull_TLToAXI4::VysyxSoCFull_TLToAXI4(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull_TLToAXI4___ctor_var_reset(this);
}

void VysyxSoCFull_TLToAXI4::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull_TLToAXI4::~VysyxSoCFull_TLToAXI4() {
}
