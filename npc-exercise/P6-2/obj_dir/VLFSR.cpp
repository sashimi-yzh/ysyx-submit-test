// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VLFSR__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VLFSR::VLFSR(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VLFSR__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , in{vlSymsp->TOP.in}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VLFSR::VLFSR(const char* _vcname__)
    : VLFSR(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VLFSR::~VLFSR() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VLFSR___024root___eval_debug_assertions(VLFSR___024root* vlSelf);
#endif  // VL_DEBUG
void VLFSR___024root___eval_static(VLFSR___024root* vlSelf);
void VLFSR___024root___eval_initial(VLFSR___024root* vlSelf);
void VLFSR___024root___eval_settle(VLFSR___024root* vlSelf);
void VLFSR___024root___eval(VLFSR___024root* vlSelf);

void VLFSR::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VLFSR::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VLFSR___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VLFSR___024root___eval_static(&(vlSymsp->TOP));
        VLFSR___024root___eval_initial(&(vlSymsp->TOP));
        VLFSR___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VLFSR___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VLFSR::eventsPending() { return false; }

uint64_t VLFSR::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VLFSR::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VLFSR___024root___eval_final(VLFSR___024root* vlSelf);

VL_ATTR_COLD void VLFSR::final() {
    VLFSR___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VLFSR::hierName() const { return vlSymsp->name(); }
const char* VLFSR::modelName() const { return "VLFSR"; }
unsigned VLFSR::threads() const { return 1; }
void VLFSR::prepareClone() const { contextp()->prepareClone(); }
void VLFSR::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VLFSR::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VLFSR___024root__trace_decl_types(VerilatedVcd* tracep);

void VLFSR___024root__trace_init_top(VLFSR___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VLFSR___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VLFSR___024root*>(voidSelf);
    VLFSR__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VLFSR___024root__trace_decl_types(tracep);
    VLFSR___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VLFSR___024root__trace_register(VLFSR___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VLFSR::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VLFSR::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VLFSR___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
