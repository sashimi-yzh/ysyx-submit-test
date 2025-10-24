// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VFPU_H_
#define VERILATED_VFPU_H_  // guard

#include "verilated.h"

class Vfpu__Syms;
class Vfpu___024root;
class VerilatedVcdC;
class Vfpu_walloc_17bits;


// This class is the main interface to the Verilated model
class Vfpu VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vfpu__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&freg_rs1,4,0);
    VL_IN8(&freg_rs2,4,0);
    VL_IN8(&freg_rd,4,0);
    VL_IN8(&freg_write_en,0,0);
    VL_IN8(&fpu_op_valid,0,0);
    VL_IN8(&fpu_op_type,5,0);
    VL_IN8(&fpu_op_round,2,0);
    VL_IN8(&downstream_valid,0,0);
    VL_OUT8(&fpu_ready,0,0);
    VL_OUT8(&exception_flags,4,0);
    VL_OUT8(&fpu_result_valid,0,0);
    VL_IN(&freg_write_data,31,0);
    VL_OUT(&freg_read_data1,31,0);
    VL_OUT(&freg_read_data2,31,0);
    VL_IN(&operand1_fp,31,0);
    VL_IN(&operand2_fp,31,0);
    VL_IN(&operand3_fp,31,0);
    VL_IN(&operand4_int,31,0);
    VL_OUT(&fpu_result,31,0);
    VL_OUT(&int_result,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__0__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__1__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__2__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__3__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__4__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__5__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__6__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__7__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__8__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__9__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__10__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__11__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__12__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__13__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__14__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__15__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__16__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__17__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__18__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__19__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__20__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__21__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__22__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__23__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__24__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__25__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__26__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__27__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__28__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__29__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__30__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__31__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__32__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__33__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__34__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__35__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__36__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__37__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__38__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__39__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__40__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__41__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__42__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__43__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__44__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__45__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__46__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__47__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__48__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__49__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__50__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__51__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__52__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__53__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__54__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__55__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__56__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__57__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__58__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__59__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__60__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__61__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__62__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__63__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__64__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__65__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__66__KET____DOT__uut;
    Vfpu_walloc_17bits* const __PVT__fpu_tb__DOT__fpu_inst__DOT__mul_inst__DOT__gen_wallace__BRA__67__KET____DOT__uut;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vfpu___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vfpu(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vfpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vfpu();
  private:
    VL_UNCOPYABLE(Vfpu);  ///< Copying not allowed

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
