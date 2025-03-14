// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VYSYXSOCFULL__SYMS_H_
#define VERILATED_VYSYXSOCFULL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VysyxSoCFull.h"

// INCLUDE MODULE CLASSES
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VysyxSoCFull__Vcb_get_csr_reg_value_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ csr_reg_index, IData/*31:0*/ &get_csr_reg_value__Vfuncrtn);
using VysyxSoCFull__Vcb_get_if_allow_in_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_if_allow_in__Vfuncrtn);
using VysyxSoCFull__Vcb_get_inst_r_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_inst_r__Vfuncrtn);
using VysyxSoCFull__Vcb_get_pc_value_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_pc_value__Vfuncrtn);
using VysyxSoCFull__Vcb_get_reg_value_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ reg_index, IData/*31:0*/ &get_reg_value__Vfuncrtn);
using VysyxSoCFull__Vcb_get_saved_addr_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_saved_addr__Vfuncrtn);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VysyxSoCFull__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VysyxSoCFull* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VysyxSoCFull___024root         TOP;
    VysyxSoCFull___024unit         TOP____024unit;

    // SCOPE NAMES
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi42apb;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__csr;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__idu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__lsu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__regfile;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lmrom;
    VerilatedScope __Vscope_ysyxSoCFull__flash;
    VerilatedScope __Vscope_ysyxSoCFull__flash__flash_cmd_i;

    // CONSTRUCTORS
    VysyxSoCFull__Syms(VerilatedContext* contextp, const char* namep, VysyxSoCFull* modelp);
    ~VysyxSoCFull__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
