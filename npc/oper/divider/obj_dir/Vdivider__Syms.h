// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDIVIDER__SYMS_H_
#define VERILATED_VDIVIDER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdivider.h"

// INCLUDE MODULE CLASSES
#include "Vdivider___024root.h"

// SYMS CLASS (contains all model state)
class Vdivider__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdivider* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdivider___024root             TOP;

    // CONSTRUCTORS
    Vdivider__Syms(VerilatedContext* contextp, const char* namep, Vdivider* modelp);
    ~Vdivider__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
