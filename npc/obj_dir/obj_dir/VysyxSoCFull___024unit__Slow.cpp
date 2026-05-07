// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull___024unit.h"

void VysyxSoCFull___024unit___ctor_var_reset(VysyxSoCFull___024unit* vlSelf);

VysyxSoCFull___024unit::VysyxSoCFull___024unit(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull___024unit___ctor_var_reset(this);
}

void VysyxSoCFull___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull___024unit::~VysyxSoCFull___024unit() {
}
