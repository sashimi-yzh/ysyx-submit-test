// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLMonitor_7.h"
#include "VysyxSoCFull__Syms.h"

void VysyxSoCFull_TLMonitor_7___ctor_var_reset(VysyxSoCFull_TLMonitor_7* vlSelf);

VysyxSoCFull_TLMonitor_7::VysyxSoCFull_TLMonitor_7(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull_TLMonitor_7___ctor_var_reset(this);
}

void VysyxSoCFull_TLMonitor_7::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull_TLMonitor_7::~VysyxSoCFull_TLMonitor_7() {
}
