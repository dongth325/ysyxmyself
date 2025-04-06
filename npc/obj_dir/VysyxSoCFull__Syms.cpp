// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VysyxSoCFull__pch.h"
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull___024unit.h"

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_if_allow_in_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_if_allow_in__Vfuncrtn);
void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_pc_value_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_pc_value__Vfuncrtn);
void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr__DOT__get_csr_reg_value_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ csr_reg_index, IData/*31:0*/ &get_csr_reg_value__Vfuncrtn);
void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_inst_r_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_inst_r__Vfuncrtn);
void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_saved_addr_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_saved_addr__Vfuncrtn);
void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__get_reg_value_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ reg_index, IData/*31:0*/ &get_reg_value__Vfuncrtn);

// FUNCTIONS
VysyxSoCFull__Syms::~VysyxSoCFull__Syms()
{
}

VysyxSoCFull__Syms::VysyxSoCFull__Syms(VerilatedContext* contextp, const char* namep, VysyxSoCFull* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
{
        // Check resources
        Verilated::stackCheck(599);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    // Setup scopes
    __Vscope_ysyxSoCFull__asic__axi42apb.configure(this, name(), "ysyxSoCFull.asic.axi42apb", "axi42apb", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__axi4frag.configure(this, name(), "ysyxSoCFull.asic.axi4frag", "axi4frag", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__axi4xbar_1.configure(this, name(), "ysyxSoCFull.asic.axi4xbar_1", "axi4xbar_1", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__axi4yank.configure(this, name(), "ysyxSoCFull.asic.axi4yank", "axi4yank", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__axi4yank__unnamedblk1.configure(this, name(), "ysyxSoCFull.asic.axi4yank.unnamedblk1", "unnamedblk1", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__cpu__cpu.configure(this, name(), "ysyxSoCFull.asic.cpu.cpu", "cpu", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__cpu__cpu__csr.configure(this, name(), "ysyxSoCFull.asic.cpu.cpu.csr", "csr", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__cpu__cpu__idu.configure(this, name(), "ysyxSoCFull.asic.cpu.cpu.idu", "idu", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__cpu__cpu__lsu.configure(this, name(), "ysyxSoCFull.asic.cpu.cpu.lsu", "lsu", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__cpu__cpu__regfile.configure(this, name(), "ysyxSoCFull.asic.cpu.cpu.regfile", "regfile", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__asic__lmrom.configure(this, name(), "ysyxSoCFull.asic.lmrom", "lmrom", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__flash.configure(this, name(), "ysyxSoCFull.flash", "flash", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyxSoCFull__flash__flash_cmd_i.configure(this, name(), "ysyxSoCFull.flash.flash_cmd_i", "flash_cmd_i", -9, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_ysyxSoCFull__asic__cpu__cpu.exportInsert(__Vfinal, "get_if_allow_in", (void*)(&VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_if_allow_in_TOP));
        __Vscope_ysyxSoCFull__asic__cpu__cpu.exportInsert(__Vfinal, "get_pc_value", (void*)(&VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_pc_value_TOP));
        __Vscope_ysyxSoCFull__asic__cpu__cpu__csr.exportInsert(__Vfinal, "get_csr_reg_value", (void*)(&VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr__DOT__get_csr_reg_value_TOP));
        __Vscope_ysyxSoCFull__asic__cpu__cpu__idu.exportInsert(__Vfinal, "get_inst_r", (void*)(&VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_inst_r_TOP));
        __Vscope_ysyxSoCFull__asic__cpu__cpu__lsu.exportInsert(__Vfinal, "get_saved_addr", (void*)(&VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_saved_addr_TOP));
        __Vscope_ysyxSoCFull__asic__cpu__cpu__regfile.exportInsert(__Vfinal, "get_reg_value", (void*)(&VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__get_reg_value_TOP));
    }
}
