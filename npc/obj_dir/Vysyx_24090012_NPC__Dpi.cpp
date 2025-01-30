// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call Vysyx_24090012_NPC::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "Vysyx_24090012_NPC__Dpi.h"
#include "Vysyx_24090012_NPC.h"

#ifndef VL_DPIDECL_get_csr_reg_value_
#define VL_DPIDECL_get_csr_reg_value_
int get_csr_reg_value(int csr_reg_index) {
    // DPI export at vsrc/csr.v:136:14
    return Vysyx_24090012_NPC::get_csr_reg_value(csr_reg_index);
}
#endif

#ifndef VL_DPIDECL_get_reg_value_
#define VL_DPIDECL_get_reg_value_
int get_reg_value(int reg_index) {
    // DPI export at vsrc/registerfile.v:61:14
    return Vysyx_24090012_NPC::get_reg_value(reg_index);
}
#endif

