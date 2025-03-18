// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYXSOCFULL__DPI_H_
#define VERILATED_VYSYXSOCFULL__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at vsrc/csr.v:136:14
    extern int get_csr_reg_value(int csr_reg_index);
    // DPI export at vsrc/NPC.v:600:14
    extern int get_if_allow_in();
    // DPI export at vsrc/idu.v:348:14
    extern int get_inst_r();
    // DPI export at vsrc/NPC.v:595:14
    extern int get_pc_value();
    // DPI export at vsrc/registerfile.v:61:14
    extern int get_reg_value(int reg_index);
    // DPI export at vsrc/lsu.v:503:14
    extern int get_saved_addr();

    // DPI IMPORTS
    // DPI import at vsrc/NPC.v:70:40
    extern void ebreak(int exit_code);
    // DPI import at ../ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at ../ysyxSoC/build/ysyxSoCFull.v:4648:30
    extern void mrom_read(int raddr, int* rdata);
    // DPI import at vsrc/exu.v:67:30
    extern int pmem_read(int addr);
    // DPI import at vsrc/exu.v:66:31
    extern void pmem_write(int addr, int data, int mask);

#ifdef __cplusplus
}
#endif

#endif  // guard
