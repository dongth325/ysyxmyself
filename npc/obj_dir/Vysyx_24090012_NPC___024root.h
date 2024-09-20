// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24090012_NPC.h for the primary calling header

#ifndef VERILATED_VYSYX_24090012_NPC___024ROOT_H_
#define VERILATED_VYSYX_24090012_NPC___024ROOT_H_  // guard

#include "verilated.h"


class Vysyx_24090012_NPC__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vysyx_24090012_NPC___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(ebreak_flag,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc,31,0);
    VL_IN(mem_data,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_24090012_NPC__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24090012_NPC___024root(Vysyx_24090012_NPC__Syms* symsp, const char* v__name);
    ~Vysyx_24090012_NPC___024root();
    VL_UNCOPYABLE(Vysyx_24090012_NPC___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
