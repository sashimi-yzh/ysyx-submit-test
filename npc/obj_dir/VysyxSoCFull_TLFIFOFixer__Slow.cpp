// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VysyxSoCFull_TLFIFOFixer.h"
#include "VysyxSoCFull__Syms.h"

void VysyxSoCFull_TLFIFOFixer___ctor_var_reset(VysyxSoCFull_TLFIFOFixer* vlSelf);

VysyxSoCFull_TLFIFOFixer::VysyxSoCFull_TLFIFOFixer(VysyxSoCFull__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VysyxSoCFull_TLFIFOFixer___ctor_var_reset(this);
}

void VysyxSoCFull_TLFIFOFixer::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VysyxSoCFull_TLFIFOFixer::~VysyxSoCFull_TLFIFOFixer() {
}
