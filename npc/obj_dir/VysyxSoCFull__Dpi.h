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
    // DPI export at vsrc/idu.v:537:14
    extern int get_branch_inst_count();
    // DPI export at vsrc/idu.v:525:14
    extern int get_compute_inst_count();
    // DPI export at vsrc/idu.v:545:14
    extern int get_csr_inst_count();
    // DPI export at vsrc/csr.v:167:14
    extern int get_csr_reg_value(int csr_reg_index);
    // DPI export at vsrc/exu.v:1003:14
    extern int get_exu_count();
    // DPI export at vsrc/ifu.v:323:18
    extern int get_hit_count();
    // DPI export at vsrc/idu.v:521:14
    extern int get_idu_count();
    // DPI export at vsrc/NPC.v:737:14
    extern int get_if_allow_in();
    // DPI export at vsrc/ifu.v:319:18
    extern int get_ifu_count();
    // DPI export at vsrc/idu.v:502:14
    extern int get_inst_r();
    // DPI export at vsrc/registerfile.v:150:16
    extern int get_instr_completed();
    // DPI export at vsrc/idu.v:541:14
    extern int get_jump_inst_count();
    // DPI export at vsrc/idu.v:529:14
    extern int get_load_inst_count();
    // DPI export at vsrc/lsu.v:676:14
    extern int get_lsu_count();
    // DPI export at vsrc/ifu.v:327:18
    extern int get_miss_count();
    // DPI export at vsrc/idu.v:549:14
    extern int get_other_inst_count();
    // DPI export at vsrc/NPC.v:732:14
    extern int get_pc_value();
    // DPI export at vsrc/lsu.v:680:14
    extern int get_read_count();
    // DPI export at vsrc/registerfile.v:145:16
    extern int get_reg_value(int reg_index);
    // DPI export at vsrc/lsu.v:663:14
    extern int get_saved_addr();
    // DPI export at vsrc/registerfile.v:156:16
    extern int get_saved_sim_lsu_addr();
    // DPI export at vsrc/idu.v:533:14
    extern int get_store_inst_count();
    // DPI export at vsrc/lsu.v:684:14
    extern int get_write_count();

    // DPI IMPORTS
    // DPI import at vsrc/NPC.v:70:40
    extern void ebreak(int exit_code);
    // DPI import at ../ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at ../ysyxSoC/build/ysyxSoCFull.v:5995:30
    extern void mrom_read(int raddr, int* rdata);

#ifdef __cplusplus
}
#endif

#endif  // guard
