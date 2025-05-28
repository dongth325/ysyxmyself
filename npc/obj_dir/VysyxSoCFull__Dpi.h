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
    // DPI export at vsrc/idu.v:523:14
    extern int get_branch_inst_count();
    // DPI export at vsrc/idu.v:511:14
    extern int get_compute_inst_count();
    // DPI export at vsrc/idu.v:531:14
    extern int get_csr_inst_count();
    // DPI export at vsrc/csr.v:167:14
    extern int get_csr_reg_value(int csr_reg_index);
    // DPI export at vsrc/exu.v:1003:14
    extern int get_exu_count();
    // DPI export at vsrc/ifu.v:307:18
    extern int get_hit_count();
    // DPI export at vsrc/idu.v:507:14
    extern int get_idu_count();
    // DPI export at vsrc/NPC.v:731:14
    extern int get_if_allow_in();
    // DPI export at vsrc/ifu.v:303:18
    extern int get_ifu_count();
    // DPI export at vsrc/idu.v:488:14
    extern int get_inst_r();
    // DPI export at vsrc/registerfile.v:144:16
    extern int get_instr_completed();
    // DPI export at vsrc/idu.v:527:14
    extern int get_jump_inst_count();
    // DPI export at vsrc/idu.v:515:14
    extern int get_load_inst_count();
    // DPI export at vsrc/lsu.v:671:14
    extern int get_lsu_count();
    // DPI export at vsrc/ifu.v:311:18
    extern int get_miss_count();
    // DPI export at vsrc/idu.v:535:14
    extern int get_other_inst_count();
    // DPI export at vsrc/NPC.v:726:14
    extern int get_pc_value();
    // DPI export at vsrc/lsu.v:675:14
    extern int get_read_count();
    // DPI export at vsrc/registerfile.v:139:16
    extern int get_reg_value(int reg_index);
    // DPI export at vsrc/lsu.v:658:14
    extern int get_saved_addr();
    // DPI export at vsrc/idu.v:519:14
    extern int get_store_inst_count();
    // DPI export at vsrc/lsu.v:679:14
    extern int get_write_count();

    // DPI IMPORTS
    // DPI import at vsrc/NPC.v:70:40
    extern void ebreak(int exit_code);
    // DPI import at ../ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at ../ysyxSoC/build/ysyxSoCFull.v:5993:30
    extern void mrom_read(int raddr, int* rdata);

#ifdef __cplusplus
}
#endif

#endif  // guard
