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
    // DPI export at vsrc/idu.v:471:14
    extern int get_branch_inst_count();
    // DPI export at vsrc/idu.v:459:14
    extern int get_compute_inst_count();
    // DPI export at vsrc/idu.v:479:14
    extern int get_csr_inst_count();
    // DPI export at vsrc/csr.v:195:14
    extern int get_csr_reg_value(int csr_reg_index);
    // DPI export at vsrc/exu.v:335:14
    extern int get_exu_count();
    // DPI export at vsrc/ifu.v:341:18
    extern int get_hit_count();
    // DPI export at vsrc/idu.v:455:14
    extern int get_idu_count();
    // DPI export at vsrc/NPC.v:806:14
    extern int get_if_allow_in();
    // DPI export at vsrc/ifu.v:337:18
    extern int get_ifu_count();
    // DPI export at vsrc/idu.v:436:14
    extern int get_inst_r();
    // DPI export at vsrc/registerfile.v:175:16
    extern int get_instr_completed();
    // DPI export at vsrc/idu.v:475:14
    extern int get_jump_inst_count();
    // DPI export at vsrc/idu.v:463:14
    extern int get_load_inst_count();
    // DPI export at vsrc/lsu.v:708:14
    extern int get_lsu_count();
    // DPI export at vsrc/ifu.v:345:18
    extern int get_miss_count();
    // DPI export at vsrc/idu.v:483:14
    extern int get_other_inst_count();
    // DPI export at vsrc/NPC.v:801:14
    extern int get_pc_value();
    // DPI export at vsrc/lsu.v:712:14
    extern int get_read_count();
    // DPI export at vsrc/registerfile.v:170:16
    extern int get_reg_value(int reg_index);
    // DPI export at vsrc/lsu.v:695:14
    extern int get_saved_addr();
    // DPI export at vsrc/registerfile.v:181:16
    extern int get_saved_sim_lsu_addr();
    // DPI export at vsrc/idu.v:467:14
    extern int get_store_inst_count();
    // DPI export at ../ysyxSoC/perip/gpio/gpio_top_apb.v:114:16
    extern int get_switch_value();
    // DPI export at vsrc/lsu.v:716:14
    extern int get_write_count();

    // DPI IMPORTS
    // DPI import at vsrc/NPC.v:70:40
    extern void ebreak(int exit_code);
    // DPI import at ../ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at ../ysyxSoC/build/ysyxSoCFull.v:5997:30
    extern void mrom_read(int raddr, int* rdata);

#ifdef __cplusplus
}
#endif

#endif  // guard
