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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(input_valid,0,0);
        VL_OUT8(ebreak_flag,0,0);
        CData/*4:0*/ ysyx_24090012_NPC__DOT__rs1;
        CData/*4:0*/ ysyx_24090012_NPC__DOT__rs2;
        CData/*6:0*/ ysyx_24090012_NPC__DOT__opcode;
        CData/*2:0*/ ysyx_24090012_NPC__DOT__func3;
        CData/*6:0*/ ysyx_24090012_NPC__DOT__func7;
        CData/*5:0*/ ysyx_24090012_NPC__DOT__alu_op;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__sram_valid;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__sram_ready;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__idu_valid;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__idu_ready;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__csr_rd_valid;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__csr_rd_ready;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__pc_valid;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__pc_ready;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__mem_valid;
        CData/*3:0*/ ysyx_24090012_NPC__DOT__mem_wmask;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__mem_wen;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__mem_ready;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__rd_valid;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__rd_ready;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__csr_wen3;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__csr_wen1;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__csr_wen2;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__csr_wen;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__is_ecall;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__is_mret;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_ready;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__next_state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__test;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__exu__DOT__state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__exu__DOT__next_state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__lsu__DOT__state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__lsu__DOT__next_state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__sram__DOT__state;
        CData/*0:0*/ ysyx_24090012_NPC__DOT__sram__DOT__next_state;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ ysyx_24090012_NPC__DOT__csr_addr3;
        SData/*11:0*/ ysyx_24090012_NPC__DOT__csr_addr1;
        SData/*11:0*/ ysyx_24090012_NPC__DOT__csr_addr2;
        SData/*11:0*/ ysyx_24090012_NPC__DOT__csr_addr;
        VL_IN(mem_data,31,0);
        VL_IN(input_pc,31,0);
        VL_OUT(pc,31,0);
        VL_OUT(exit_code,31,0);
        IData/*31:0*/ ysyx_24090012_NPC__DOT__imm;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__rs1_data;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__rs2_data;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__result;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__next_pc;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__inst;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__sram_rdata;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__mem_addr;
    };
    struct {
        IData/*31:0*/ ysyx_24090012_NPC__DOT__mem_wdata;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__rd_data;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__csr_wdata3;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__csr_wdata1;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__csr_wdata2;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__csr_wdata;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__mstatus_new;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__csr_rdata;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__mstatus;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__mtvec;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__mepc;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__mcause;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_rdata;
        IData/*31:0*/ ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> ysyx_24090012_NPC__DOT__regfile__DOT__rf;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

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
