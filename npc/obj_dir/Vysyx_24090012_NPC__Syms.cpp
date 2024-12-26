// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC.h"
#include "Vysyx_24090012_NPC___024root.h"

void Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__csr__DOT__get_csr_reg_value_TOP(Vysyx_24090012_NPC__Syms* __restrict vlSymsp, IData/*31:0*/ csr_reg_index, IData/*31:0*/ &get_csr_reg_value__Vfuncrtn);
void Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__regfile__DOT__get_reg_value_TOP(Vysyx_24090012_NPC__Syms* __restrict vlSymsp, IData/*31:0*/ reg_index, IData/*31:0*/ &get_reg_value__Vfuncrtn);

// FUNCTIONS
Vysyx_24090012_NPC__Syms::~Vysyx_24090012_NPC__Syms()
{
}

Vysyx_24090012_NPC__Syms::Vysyx_24090012_NPC__Syms(VerilatedContext* contextp, const char* namep, Vysyx_24090012_NPC* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(185);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_ysyx_24090012_NPC__csr.configure(this, name(), "ysyx_24090012_NPC.csr", "csr", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyx_24090012_NPC__regfile.configure(this, name(), "ysyx_24090012_NPC.regfile", "regfile", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_ysyx_24090012_NPC__csr.exportInsert(__Vfinal, "get_csr_reg_value", (void*)(&Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__csr__DOT__get_csr_reg_value_TOP));
        __Vscope_ysyx_24090012_NPC__regfile.exportInsert(__Vfinal, "get_reg_value", (void*)(&Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__regfile__DOT__get_reg_value_TOP));
    }
}
