// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VNPC.h for the primary calling header

#ifndef VERILATED_VNPC___024ROOT_H_
#define VERILATED_VNPC___024ROOT_H_  // guard

#include "verilated.h"


class VNPC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VNPC___024root final : public VerilatedModule {
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
    VNPC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VNPC___024root(VNPC__Syms* symsp, const char* v__name);
    ~VNPC___024root();
    VL_UNCOPYABLE(VNPC___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
