// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_AXI4UserYanker_1.h"
#include "VysyxSoCFull__Syms.h"

void VysyxSoCFull_AXI4UserYanker_1___ctor_var_reset(VysyxSoCFull_AXI4UserYanker_1* vlSelf);

VysyxSoCFull_AXI4UserYanker_1::VysyxSoCFull_AXI4UserYanker_1(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull_AXI4UserYanker_1___ctor_var_reset(this);
}

void VysyxSoCFull_AXI4UserYanker_1::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull_AXI4UserYanker_1::~VysyxSoCFull_AXI4UserYanker_1() {
}
