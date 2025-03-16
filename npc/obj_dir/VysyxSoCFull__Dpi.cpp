// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call VysyxSoCFull::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull.h"

#ifndef VL_DPIDECL_get_csr_reg_value_
#define VL_DPIDECL_get_csr_reg_value_
int get_csr_reg_value(int csr_reg_index) {
    // DPI export at vsrc/csr.v:136:14
    return VysyxSoCFull::get_csr_reg_value(csr_reg_index);
}
#endif

#ifndef VL_DPIDECL_get_if_allow_in_
#define VL_DPIDECL_get_if_allow_in_
int get_if_allow_in() {
    // DPI export at vsrc/NPC.v:600:14
    return VysyxSoCFull::get_if_allow_in();
}
#endif

#ifndef VL_DPIDECL_get_inst_r_
#define VL_DPIDECL_get_inst_r_
int get_inst_r() {
    // DPI export at vsrc/idu.v:348:14
    return VysyxSoCFull::get_inst_r();
}
#endif

#ifndef VL_DPIDECL_get_pc_value_
#define VL_DPIDECL_get_pc_value_
int get_pc_value() {
    // DPI export at vsrc/NPC.v:595:14
    return VysyxSoCFull::get_pc_value();
}
#endif

#ifndef VL_DPIDECL_get_reg_value_
#define VL_DPIDECL_get_reg_value_
int get_reg_value(int reg_index) {
    // DPI export at vsrc/registerfile.v:61:14
    return VysyxSoCFull::get_reg_value(reg_index);
}
#endif

#ifndef VL_DPIDECL_get_saved_addr_
#define VL_DPIDECL_get_saved_addr_
int get_saved_addr() {
    // DPI export at vsrc/lsu.v:422:14
    return VysyxSoCFull::get_saved_addr();
}
#endif

