// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbooth_wallace_multiplier.h for the primary calling header

#ifndef VERILATED_VBOOTH_WALLACE_MULTIPLIER_WALLOC_17BITS_H_
#define VERILATED_VBOOTH_WALLACE_MULTIPLIER_WALLOC_17BITS_H_  // guard

#include "verilated.h"

class Vbooth_wallace_multiplier__Syms;

class Vbooth_wallace_multiplier_walloc_17bits final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(cout,0,0);
    VL_OUT8(s,0,0);
    CData/*0:0*/ __Vcellout__csa0__s;
    CData/*0:0*/ __Vcellout__csa1__s;
    CData/*0:0*/ __Vcellout__csa2__s;
    CData/*0:0*/ __Vcellout__csa3__s;
    CData/*0:0*/ __Vcellout__csa4__s;
    CData/*0:0*/ __Vcellout__csa5__s;
    CData/*0:0*/ __Vcellout__csa6__s;
    CData/*0:0*/ __Vcellout__csa7__s;
    CData/*0:0*/ __Vcellout__csa8__s;
    CData/*0:0*/ __Vcellout__csa9__s;
    CData/*0:0*/ __Vcellout__csaA__s;
    CData/*0:0*/ __Vcellout__csaB__s;
    CData/*0:0*/ __Vcellout__csaC__s;
    CData/*0:0*/ __PVT__fifth_s;
    VL_IN16(cin,13,0);
    VL_OUT16(cout_group,13,0);
    VL_IN(src_in,16,0);

    // INTERNAL VARIABLES
    Vbooth_wallace_multiplier__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbooth_wallace_multiplier_walloc_17bits(Vbooth_wallace_multiplier__Syms* symsp, const char* v__name);
    ~Vbooth_wallace_multiplier_walloc_17bits();
    VL_UNCOPYABLE(Vbooth_wallace_multiplier_walloc_17bits);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
