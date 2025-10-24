// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbooth_wallace_multiplier.h"
#include "Vbooth_wallace_multiplier__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vbooth_wallace_multiplier::Vbooth_wallace_multiplier(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbooth_wallace_multiplier__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , is_signed{vlSymsp->TOP.is_signed}
    , valid{vlSymsp->TOP.valid}
    , multiplicand{vlSymsp->TOP.multiplicand}
    , multiplier{vlSymsp->TOP.multiplier}
    , product{vlSymsp->TOP.product}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__0__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__1__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__2__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__3__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__4__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__5__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__6__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__7__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__8__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__9__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__10__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__11__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__12__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__13__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__14__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__15__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__16__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__17__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__18__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__19__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__20__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__21__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__22__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__23__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__24__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__25__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__26__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__27__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__28__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__29__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__30__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__31__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__32__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__33__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__34__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__35__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__36__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__37__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__38__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__39__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__40__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__41__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__42__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__43__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__44__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__45__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__46__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__47__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__48__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__49__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__50__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__51__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__52__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__53__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__54__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__55__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__56__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__57__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__58__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__59__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__60__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__61__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__62__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__63__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__64__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__65__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__66__KET____DOT__uut}
    , __PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut{vlSymsp->TOP.__PVT__booth_wallace_multiplier__DOT__gen_wallace__BRA__67__KET____DOT__uut}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbooth_wallace_multiplier::Vbooth_wallace_multiplier(const char* _vcname__)
    : Vbooth_wallace_multiplier(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbooth_wallace_multiplier::~Vbooth_wallace_multiplier() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbooth_wallace_multiplier___024root___eval_debug_assertions(Vbooth_wallace_multiplier___024root* vlSelf);
#endif  // VL_DEBUG
void Vbooth_wallace_multiplier___024root___eval_static(Vbooth_wallace_multiplier___024root* vlSelf);
void Vbooth_wallace_multiplier___024root___eval_initial(Vbooth_wallace_multiplier___024root* vlSelf);
void Vbooth_wallace_multiplier___024root___eval_settle(Vbooth_wallace_multiplier___024root* vlSelf);
void Vbooth_wallace_multiplier___024root___eval(Vbooth_wallace_multiplier___024root* vlSelf);

void Vbooth_wallace_multiplier::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbooth_wallace_multiplier::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbooth_wallace_multiplier___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbooth_wallace_multiplier___024root___eval_static(&(vlSymsp->TOP));
        Vbooth_wallace_multiplier___024root___eval_initial(&(vlSymsp->TOP));
        Vbooth_wallace_multiplier___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbooth_wallace_multiplier___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbooth_wallace_multiplier::eventsPending() { return false; }

uint64_t Vbooth_wallace_multiplier::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbooth_wallace_multiplier::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbooth_wallace_multiplier___024root___eval_final(Vbooth_wallace_multiplier___024root* vlSelf);

VL_ATTR_COLD void Vbooth_wallace_multiplier::final() {
    Vbooth_wallace_multiplier___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbooth_wallace_multiplier::hierName() const { return vlSymsp->name(); }
const char* Vbooth_wallace_multiplier::modelName() const { return "Vbooth_wallace_multiplier"; }
unsigned Vbooth_wallace_multiplier::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vbooth_wallace_multiplier::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vbooth_wallace_multiplier___024root__trace_init_top(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbooth_wallace_multiplier___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbooth_wallace_multiplier___024root*>(voidSelf);
    Vbooth_wallace_multiplier__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vbooth_wallace_multiplier___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vbooth_wallace_multiplier___024root__trace_register(Vbooth_wallace_multiplier___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbooth_wallace_multiplier::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vbooth_wallace_multiplier::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vbooth_wallace_multiplier___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
