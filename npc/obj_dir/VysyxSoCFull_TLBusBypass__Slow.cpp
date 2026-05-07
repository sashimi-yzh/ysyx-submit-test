// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLBusBypass.h"
#include "VysyxSoCFull__Syms.h"

void VysyxSoCFull_TLBusBypass___ctor_var_reset(VysyxSoCFull_TLBusBypass* vlSelf);

VysyxSoCFull_TLBusBypass::VysyxSoCFull_TLBusBypass(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull_TLBusBypass___ctor_var_reset(this);
}

void VysyxSoCFull_TLBusBypass::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull_TLBusBypass::~VysyxSoCFull_TLBusBypass() {
}
