// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop_top.h"
#include "Vtop___024unit.h"
#include "Vtop_GPR.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
    , TOP__top{this, Verilated::catName(namep, "top")}
    , TOP__top__GPR_0{this, Verilated::catName(namep, "top.GPR_0")}
{
    // Check resources
    Verilated::stackCheck(372);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    TOP.top = &TOP__top;
    TOP__top.GPR_0 = &TOP__top__GPR_0;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    TOP__top.__Vconfigure(true);
    TOP__top__GPR_0.__Vconfigure(true);
    // Setup scopes
    __Vscope_top.configure(this, name(), "top", "top", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__GPR_0.configure(this, name(), "top.GPR_0", "GPR_0", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_top.varInsert(__Vfinal,"PC", &(TOP__top.PC), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top.varInsert(__Vfinal,"dnpc", &(TOP__top.dnpc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top.varInsert(__Vfinal,"snpc", &(TOP__top.snpc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_top__GPR_0.varInsert(__Vfinal,"GPR", &(TOP__top__GPR_0.GPR), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,31,0 ,31,0);
    }
}
