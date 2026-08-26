// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VPS2__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VPS2::VPS2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VPS2__Syms(contextp(), _vcname__, this)}
    , CLK{vlSymsp->TOP.CLK}
    , CLRN{vlSymsp->TOP.CLRN}
    , seg0L{vlSymsp->TOP.seg0L}
    , seg0H{vlSymsp->TOP.seg0H}
    , seg1L{vlSymsp->TOP.seg1L}
    , seg1H{vlSymsp->TOP.seg1H}
    , seg2L{vlSymsp->TOP.seg2L}
    , seg2H{vlSymsp->TOP.seg2H}
    , seg3L{vlSymsp->TOP.seg3L}
    , seg3H{vlSymsp->TOP.seg3H}
    , data{vlSymsp->TOP.data}
    , PS2_CLK{vlSymsp->TOP.PS2_CLK}
    , PS2_DAT{vlSymsp->TOP.PS2_DAT}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VPS2::VPS2(const char* _vcname__)
    : VPS2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VPS2::~VPS2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VPS2___024root___eval_debug_assertions(VPS2___024root* vlSelf);
#endif  // VL_DEBUG
void VPS2___024root___eval_static(VPS2___024root* vlSelf);
void VPS2___024root___eval_initial(VPS2___024root* vlSelf);
void VPS2___024root___eval_settle(VPS2___024root* vlSelf);
void VPS2___024root___eval(VPS2___024root* vlSelf);

void VPS2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPS2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VPS2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VPS2___024root___eval_static(&(vlSymsp->TOP));
        VPS2___024root___eval_initial(&(vlSymsp->TOP));
        VPS2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VPS2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VPS2::eventsPending() { return false; }

uint64_t VPS2::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VPS2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VPS2___024root___eval_final(VPS2___024root* vlSelf);

VL_ATTR_COLD void VPS2::final() {
    VPS2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VPS2::hierName() const { return vlSymsp->name(); }
const char* VPS2::modelName() const { return "VPS2"; }
unsigned VPS2::threads() const { return 1; }
void VPS2::prepareClone() const { contextp()->prepareClone(); }
void VPS2::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VPS2::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VPS2___024root__trace_decl_types(VerilatedVcd* tracep);

void VPS2___024root__trace_init_top(VPS2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VPS2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VPS2___024root*>(voidSelf);
    VPS2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VPS2___024root__trace_decl_types(tracep);
    VPS2___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VPS2___024root__trace_register(VPS2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VPS2::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VPS2::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VPS2___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
