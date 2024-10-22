// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24090012_NPC.h for the primary calling header

#ifndef VERILATED_VYSYX_24090012_NPC_YSYX_24090012_NPC_H_
#define VERILATED_VYSYX_24090012_NPC_YSYX_24090012_NPC_H_  // guard

#include "verilated.h"
class Vysyx_24090012_NPC_ysyx_24090012_RegisterFile;


class Vysyx_24090012_NPC__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vysyx_24090012_NPC_ysyx_24090012_NPC final : public VerilatedModule {
  public:
    // CELLS
    Vysyx_24090012_NPC_ysyx_24090012_RegisterFile* regfile;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(ebreak_flag,0,0);
    CData/*4:0*/ rs1;
    CData/*4:0*/ rs2;
    CData/*4:0*/ rd;
    CData/*6:0*/ opcode;
    CData/*2:0*/ func3;
    CData/*6:0*/ func7;
    CData/*3:0*/ alu_op;
    CData/*0:0*/ wen;
    CData/*0:0*/ ifu__DOT__clk;
    CData/*0:0*/ ifu__DOT__rst;
    CData/*4:0*/ idu__DOT__rs1;
    CData/*4:0*/ idu__DOT__rs2;
    CData/*4:0*/ idu__DOT__rd;
    CData/*6:0*/ idu__DOT__opcode;
    CData/*2:0*/ idu__DOT__func3;
    CData/*6:0*/ idu__DOT__func7;
    CData/*3:0*/ idu__DOT__alu_op;
    CData/*3:0*/ exu__DOT__alu_op;
    VL_OUT(pc,31,0);
    VL_IN(mem_data,31,0);
    VL_OUT(exit_code,31,0);
    IData/*31:0*/ imm;
    IData/*31:0*/ rs1_data;
    IData/*31:0*/ rs2_data;
    IData/*31:0*/ result;
    IData/*31:0*/ next_pc;
    IData/*31:0*/ inst;
    IData/*31:0*/ ifu__DOT__pc;
    IData/*31:0*/ ifu__DOT__inst;
    IData/*31:0*/ ifu__DOT__mem_data;
    IData/*31:0*/ idu__DOT__inst;
    IData/*31:0*/ idu__DOT__imm;
    IData/*31:0*/ exu__DOT__pc;
    IData/*31:0*/ exu__DOT__rs1_data;
    IData/*31:0*/ exu__DOT__rs2_data;
    IData/*31:0*/ exu__DOT__imm;
    IData/*31:0*/ exu__DOT__result;
    IData/*31:0*/ exu__DOT__next_pc;

    // INTERNAL VARIABLES
    Vysyx_24090012_NPC__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24090012_NPC_ysyx_24090012_NPC(Vysyx_24090012_NPC__Syms* symsp, const char* v__name);
    ~Vysyx_24090012_NPC_ysyx_24090012_NPC();
    VL_UNCOPYABLE(Vysyx_24090012_NPC_ysyx_24090012_NPC);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
