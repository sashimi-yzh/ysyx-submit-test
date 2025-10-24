// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFPU__SYMS_H_
#define VERILATED_VFPU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfpu.h"

// INCLUDE MODULE CLASSES
#include "Vfpu___024root.h"
#include "Vfpu_walloc_17bits.h"

// SYMS CLASS (contains all model state)
class Vfpu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfpu* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfpu___024root                 TOP;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut;
    Vfpu_walloc_17bits             TOP__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut;

    // CONSTRUCTORS
    Vfpu__Syms(VerilatedContext* contextp, const char* namep, Vfpu* modelp);
    ~Vfpu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
