// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VysyxSoCFull.h"
#include "VysyxSoCFull__Syms.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VysyxSoCFull::VysyxSoCFull(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VysyxSoCFull__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , externalPins_gpio_seg_0{vlSymsp->TOP.externalPins_gpio_seg_0}
    , externalPins_gpio_seg_1{vlSymsp->TOP.externalPins_gpio_seg_1}
    , externalPins_gpio_seg_2{vlSymsp->TOP.externalPins_gpio_seg_2}
    , externalPins_gpio_seg_3{vlSymsp->TOP.externalPins_gpio_seg_3}
    , externalPins_gpio_seg_4{vlSymsp->TOP.externalPins_gpio_seg_4}
    , externalPins_gpio_seg_5{vlSymsp->TOP.externalPins_gpio_seg_5}
    , externalPins_gpio_seg_6{vlSymsp->TOP.externalPins_gpio_seg_6}
    , externalPins_gpio_seg_7{vlSymsp->TOP.externalPins_gpio_seg_7}
    , externalPins_ps2_clk{vlSymsp->TOP.externalPins_ps2_clk}
    , externalPins_ps2_data{vlSymsp->TOP.externalPins_ps2_data}
    , externalPins_vga_r{vlSymsp->TOP.externalPins_vga_r}
    , externalPins_vga_g{vlSymsp->TOP.externalPins_vga_g}
    , externalPins_vga_b{vlSymsp->TOP.externalPins_vga_b}
    , externalPins_vga_hsync{vlSymsp->TOP.externalPins_vga_hsync}
    , externalPins_vga_vsync{vlSymsp->TOP.externalPins_vga_vsync}
    , externalPins_vga_valid{vlSymsp->TOP.externalPins_vga_valid}
    , externalPins_uart_rx{vlSymsp->TOP.externalPins_uart_rx}
    , externalPins_uart_tx{vlSymsp->TOP.externalPins_uart_tx}
    , externalPins_gpio_out{vlSymsp->TOP.externalPins_gpio_out}
    , externalPins_gpio_in{vlSymsp->TOP.externalPins_gpio_in}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VysyxSoCFull::VysyxSoCFull(const char* _vcname__)
    : VysyxSoCFull(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VysyxSoCFull::~VysyxSoCFull() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VysyxSoCFull___024root___eval_debug_assertions(VysyxSoCFull___024root* vlSelf);
#endif  // VL_DEBUG
void VysyxSoCFull___024root___eval_static(VysyxSoCFull___024root* vlSelf);
void VysyxSoCFull___024root___eval_initial(VysyxSoCFull___024root* vlSelf);
void VysyxSoCFull___024root___eval_settle(VysyxSoCFull___024root* vlSelf);
void VysyxSoCFull___024root___eval(VysyxSoCFull___024root* vlSelf);

void VysyxSoCFull::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VysyxSoCFull::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VysyxSoCFull___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VysyxSoCFull___024root___eval_static(&(vlSymsp->TOP));
        VysyxSoCFull___024root___eval_initial(&(vlSymsp->TOP));
        VysyxSoCFull___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VysyxSoCFull___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VysyxSoCFull::eventsPending() { return false; }

uint64_t VysyxSoCFull::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VysyxSoCFull::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VysyxSoCFull___024root___eval_final(VysyxSoCFull___024root* vlSelf);

VL_ATTR_COLD void VysyxSoCFull::final() {
    VysyxSoCFull___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VysyxSoCFull::hierName() const { return vlSymsp->name(); }
const char* VysyxSoCFull::modelName() const { return "VysyxSoCFull"; }
unsigned VysyxSoCFull::threads() const { return 1; }
