// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VYSYX_24090012_NPC__SYMS_H_
#define VERILATED_VYSYX_24090012_NPC__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vysyx_24090012_NPC.h"

// INCLUDE MODULE CLASSES
#include "Vysyx_24090012_NPC___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using Vysyx_24090012_NPC__Vcb_get_reg_value_t = void (*) (Vysyx_24090012_NPC__Syms* __restrict vlSymsp, IData/*31:0*/ reg_index, IData/*31:0*/ &get_reg_value__Vfuncrtn);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vysyx_24090012_NPC__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vysyx_24090012_NPC* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vysyx_24090012_NPC___024root   TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_ysyx_24090012_NPC__regfile;

    // CONSTRUCTORS
    Vysyx_24090012_NPC__Syms(VerilatedContext* contextp, const char* namep, Vysyx_24090012_NPC* modelp);
    ~Vysyx_24090012_NPC__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
