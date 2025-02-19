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
    // DPI export at vsrc/csr.v:136:14
    extern int get_csr_reg_value(int csr_reg_index);
    // DPI export at vsrc/registerfile.v:61:14
    extern int get_reg_value(int reg_index);

    // DPI IMPORTS
    // DPI import at vsrc/NPC.v:11:32
    extern void ebreak(int exit_code);
    // DPI import at vsrc/sram.v:14:33
    extern int pmem_read(int raddr);
    // DPI import at vsrc/sram.v:15:34
    extern void pmem_write(int waddr, int wdata, int wmask);

#ifdef __cplusplus
}
#endif

#endif  // guard
