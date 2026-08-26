// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvga__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vvga::Vvga(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vvga__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , vsync{vlSymsp->TOP.vsync}
    , hsync{vlSymsp->TOP.hsync}
    , valid{vlSymsp->TOP.valid}
    , vga_r{vlSymsp->TOP.vga_r}
    , vga_g{vlSymsp->TOP.vga_g}
    , vga_b{vlSymsp->TOP.vga_b}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vvga::Vvga(const char* _vcname__)
    : Vvga(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vvga::~Vvga() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vvga___024root___eval_debug_assertions(Vvga___024root* vlSelf);
#endif  // VL_DEBUG
void Vvga___024root___eval_static(Vvga___024root* vlSelf);
void Vvga___024root___eval_initial(Vvga___024root* vlSelf);
void Vvga___024root___eval_settle(Vvga___024root* vlSelf);
void Vvga___024root___eval(Vvga___024root* vlSelf);

void Vvga::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvga::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvga___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vvga___024root___eval_static(&(vlSymsp->TOP));
        Vvga___024root___eval_initial(&(vlSymsp->TOP));
        Vvga___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vvga___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vvga::eventsPending() { return false; }

uint64_t Vvga::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vvga::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vvga___024root___eval_final(Vvga___024root* vlSelf);

VL_ATTR_COLD void Vvga::final() {
    Vvga___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vvga::hierName() const { return vlSymsp->name(); }
const char* Vvga::modelName() const { return "Vvga"; }
unsigned Vvga::threads() const { return 1; }
void Vvga::prepareClone() const { contextp()->prepareClone(); }
void Vvga::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vvga::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vvga___024root__trace_decl_types(VerilatedVcd* tracep);

void Vvga___024root__trace_init_top(Vvga___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vvga___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vvga___024root*>(voidSelf);
    Vvga__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vvga___024root__trace_decl_types(tracep);
    Vvga___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vvga___024root__trace_register(Vvga___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vvga::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vvga::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vvga___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
