// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VBOOTH_WALLACE_MULTIPLIER_H_
#define VERILATED_VBOOTH_WALLACE_MULTIPLIER_H_  // guard

#include "verilated.h"

class Vbooth_wallace_multiplier__Syms;
class Vbooth_wallace_multiplier___024root;
class VerilatedVcdC;
class Vbooth_wallace_multiplier_walloc_17bits;


// This class is the main interface to the Verilated model
class Vbooth_wallace_multiplier VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vbooth_wallace_multiplier__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst_n,0,0);
    VL_IN8(&is_signed,0,0);
    VL_OUT8(&valid,0,0);
    VL_IN(&multiplicand,31,0);
    VL_IN(&multiplier,31,0);
    VL_OUT64(&product,63,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut;
    Vbooth_wallace_multiplier_walloc_17bits* const __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vbooth_wallace_multiplier___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vbooth_wallace_multiplier(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vbooth_wallace_multiplier(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vbooth_wallace_multiplier();
  private:
    VL_UNCOPYABLE(Vbooth_wallace_multiplier);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
