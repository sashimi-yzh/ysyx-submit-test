// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdivider.h"
#include "Vdivider__Syms.h"

//============================================================
// Constructors

Vdivider::Vdivider(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdivider__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , is_signed{vlSymsp->TOP.is_signed}
    , valid{vlSymsp->TOP.valid}
    , dividend{vlSymsp->TOP.dividend}
    , divisor{vlSymsp->TOP.divisor}
    , quotient{vlSymsp->TOP.quotient}
    , remainder{vlSymsp->TOP.remainder}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdivider::Vdivider(const char* _vcname__)
    : Vdivider(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdivider::~Vdivider() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdivider___024root___eval_debug_assertions(Vdivider___024root* vlSelf);
#endif  // VL_DEBUG
void Vdivider___024root___eval_static(Vdivider___024root* vlSelf);
void Vdivider___024root___eval_initial(Vdivider___024root* vlSelf);
void Vdivider___024root___eval_settle(Vdivider___024root* vlSelf);
void Vdivider___024root___eval(Vdivider___024root* vlSelf);

void Vdivider::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdivider::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdivider___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdivider___024root___eval_static(&(vlSymsp->TOP));
        Vdivider___024root___eval_initial(&(vlSymsp->TOP));
        Vdivider___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdivider___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdivider::eventsPending() { return false; }

uint64_t Vdivider::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdivider::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdivider___024root___eval_final(Vdivider___024root* vlSelf);

VL_ATTR_COLD void Vdivider::final() {
    Vdivider___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdivider::hierName() const { return vlSymsp->name(); }
const char* Vdivider::modelName() const { return "Vdivider"; }
unsigned Vdivider::threads() const { return 1; }
