// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_24090012_NPC__DPI_H_
#define VERILATED_VYSYX_24090012_NPC__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at vsrc/registerfile.v:58:14
    extern int get_reg_value(int reg_index);

    // DPI IMPORTS
    // DPI import at vsrc/NPC.v:9:32
    extern void ebreak(int exit_code);
    // DPI import at vsrc/exu.v:11:30
    extern int pmem_read(int addr);
    // DPI import at vsrc/exu.v:10:31
    extern void pmem_write(int addr, int data, int mask);

#ifdef __cplusplus
}
#endif

#endif  // guard
