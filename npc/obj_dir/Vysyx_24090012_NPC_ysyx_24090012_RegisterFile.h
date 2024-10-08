// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24090012_NPC.h for the primary calling header

#ifndef VERILATED_VYSYX_24090012_NPC_YSYX_24090012_REGISTERFILE_H_
#define VERILATED_VYSYX_24090012_NPC_YSYX_24090012_REGISTERFILE_H_  // guard

#include "verilated.h"


class Vysyx_24090012_NPC__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vysyx_24090012_NPC_ysyx_24090012_RegisterFile final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(raddr1,4,0);
    VL_IN8(raddr2,4,0);
    VL_IN8(waddr,4,0);
    VL_IN8(wen,0,0);
    CData/*4:0*/ __VdlyDim0__rf__v0;
    CData/*0:0*/ __VdlySet__rf__v0;
    VL_IN(wdata,31,0);
    VL_OUT(rdata1,31,0);
    VL_OUT(rdata2,31,0);
    IData/*31:0*/ __VdlyVal__rf__v0;
    VlUnpacked<IData/*31:0*/, 32> rf;

    // INTERNAL VARIABLES
    Vysyx_24090012_NPC__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ ADDR_WIDTH = 5U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;

    // CONSTRUCTORS
    Vysyx_24090012_NPC_ysyx_24090012_RegisterFile(Vysyx_24090012_NPC__Syms* symsp, const char* v__name);
    ~Vysyx_24090012_NPC_ysyx_24090012_RegisterFile();
    VL_UNCOPYABLE(Vysyx_24090012_NPC_ysyx_24090012_RegisterFile);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
