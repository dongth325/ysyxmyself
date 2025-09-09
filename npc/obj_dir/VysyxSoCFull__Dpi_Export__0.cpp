// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "VysyxSoCFull.h"
#include "VysyxSoCFull__Syms.h"
#include "verilated_dpi.h"


int VysyxSoCFull::get_pc_value() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_pc_value\n"); );
    // Init
    IData/*31:0*/ get_pc_value__Vfuncrtn__Vcvt;
    get_pc_value__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_pc_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_pc_value_t __Vcb = (VysyxSoCFull__Vcb_get_pc_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_pc_value__Vfuncrtn__Vcvt);
    int get_pc_value__Vfuncrtn;
    for (size_t get_pc_value__Vfuncrtn__Vidx = 0; get_pc_value__Vfuncrtn__Vidx < 1; ++get_pc_value__Vfuncrtn__Vidx) get_pc_value__Vfuncrtn = get_pc_value__Vfuncrtn__Vcvt;
    return get_pc_value__Vfuncrtn;
}

int VysyxSoCFull::get_if_allow_in() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_if_allow_in\n"); );
    // Init
    IData/*31:0*/ get_if_allow_in__Vfuncrtn__Vcvt;
    get_if_allow_in__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_if_allow_in");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_if_allow_in_t __Vcb = (VysyxSoCFull__Vcb_get_if_allow_in_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_if_allow_in__Vfuncrtn__Vcvt);
    int get_if_allow_in__Vfuncrtn;
    for (size_t get_if_allow_in__Vfuncrtn__Vidx = 0; get_if_allow_in__Vfuncrtn__Vidx < 1; ++get_if_allow_in__Vfuncrtn__Vidx) get_if_allow_in__Vfuncrtn = get_if_allow_in__Vfuncrtn__Vcvt;
    return get_if_allow_in__Vfuncrtn;
}

int VysyxSoCFull::get_ifu_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_ifu_count\n"); );
    // Init
    IData/*31:0*/ get_ifu_count__Vfuncrtn__Vcvt;
    get_ifu_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_ifu_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_ifu_count_t __Vcb = (VysyxSoCFull__Vcb_get_ifu_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_ifu_count__Vfuncrtn__Vcvt);
    int get_ifu_count__Vfuncrtn;
    for (size_t get_ifu_count__Vfuncrtn__Vidx = 0; get_ifu_count__Vfuncrtn__Vidx < 1; ++get_ifu_count__Vfuncrtn__Vidx) get_ifu_count__Vfuncrtn = get_ifu_count__Vfuncrtn__Vcvt;
    return get_ifu_count__Vfuncrtn;
}

int VysyxSoCFull::get_hit_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_hit_count\n"); );
    // Init
    IData/*31:0*/ get_hit_count__Vfuncrtn__Vcvt;
    get_hit_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_hit_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_hit_count_t __Vcb = (VysyxSoCFull__Vcb_get_hit_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_hit_count__Vfuncrtn__Vcvt);
    int get_hit_count__Vfuncrtn;
    for (size_t get_hit_count__Vfuncrtn__Vidx = 0; get_hit_count__Vfuncrtn__Vidx < 1; ++get_hit_count__Vfuncrtn__Vidx) get_hit_count__Vfuncrtn = get_hit_count__Vfuncrtn__Vcvt;
    return get_hit_count__Vfuncrtn;
}

int VysyxSoCFull::get_miss_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_miss_count\n"); );
    // Init
    IData/*31:0*/ get_miss_count__Vfuncrtn__Vcvt;
    get_miss_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_miss_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_miss_count_t __Vcb = (VysyxSoCFull__Vcb_get_miss_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_miss_count__Vfuncrtn__Vcvt);
    int get_miss_count__Vfuncrtn;
    for (size_t get_miss_count__Vfuncrtn__Vidx = 0; get_miss_count__Vfuncrtn__Vidx < 1; ++get_miss_count__Vfuncrtn__Vidx) get_miss_count__Vfuncrtn = get_miss_count__Vfuncrtn__Vcvt;
    return get_miss_count__Vfuncrtn;
}

int VysyxSoCFull::get_inst_r() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_inst_r\n"); );
    // Init
    IData/*31:0*/ get_inst_r__Vfuncrtn__Vcvt;
    get_inst_r__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_inst_r");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_inst_r_t __Vcb = (VysyxSoCFull__Vcb_get_inst_r_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_inst_r__Vfuncrtn__Vcvt);
    int get_inst_r__Vfuncrtn;
    for (size_t get_inst_r__Vfuncrtn__Vidx = 0; get_inst_r__Vfuncrtn__Vidx < 1; ++get_inst_r__Vfuncrtn__Vidx) get_inst_r__Vfuncrtn = get_inst_r__Vfuncrtn__Vcvt;
    return get_inst_r__Vfuncrtn;
}

int VysyxSoCFull::get_idu_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_idu_count\n"); );
    // Init
    IData/*31:0*/ get_idu_count__Vfuncrtn__Vcvt;
    get_idu_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_idu_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_idu_count_t __Vcb = (VysyxSoCFull__Vcb_get_idu_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_idu_count__Vfuncrtn__Vcvt);
    int get_idu_count__Vfuncrtn;
    for (size_t get_idu_count__Vfuncrtn__Vidx = 0; get_idu_count__Vfuncrtn__Vidx < 1; ++get_idu_count__Vfuncrtn__Vidx) get_idu_count__Vfuncrtn = get_idu_count__Vfuncrtn__Vcvt;
    return get_idu_count__Vfuncrtn;
}

int VysyxSoCFull::get_compute_inst_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_compute_inst_count\n"); );
    // Init
    IData/*31:0*/ get_compute_inst_count__Vfuncrtn__Vcvt;
    get_compute_inst_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_compute_inst_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_compute_inst_count_t __Vcb = (VysyxSoCFull__Vcb_get_compute_inst_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_compute_inst_count__Vfuncrtn__Vcvt);
    int get_compute_inst_count__Vfuncrtn;
    for (size_t get_compute_inst_count__Vfuncrtn__Vidx = 0; get_compute_inst_count__Vfuncrtn__Vidx < 1; ++get_compute_inst_count__Vfuncrtn__Vidx) get_compute_inst_count__Vfuncrtn = get_compute_inst_count__Vfuncrtn__Vcvt;
    return get_compute_inst_count__Vfuncrtn;
}

int VysyxSoCFull::get_load_inst_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_load_inst_count\n"); );
    // Init
    IData/*31:0*/ get_load_inst_count__Vfuncrtn__Vcvt;
    get_load_inst_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_load_inst_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_load_inst_count_t __Vcb = (VysyxSoCFull__Vcb_get_load_inst_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_load_inst_count__Vfuncrtn__Vcvt);
    int get_load_inst_count__Vfuncrtn;
    for (size_t get_load_inst_count__Vfuncrtn__Vidx = 0; get_load_inst_count__Vfuncrtn__Vidx < 1; ++get_load_inst_count__Vfuncrtn__Vidx) get_load_inst_count__Vfuncrtn = get_load_inst_count__Vfuncrtn__Vcvt;
    return get_load_inst_count__Vfuncrtn;
}

int VysyxSoCFull::get_store_inst_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_store_inst_count\n"); );
    // Init
    IData/*31:0*/ get_store_inst_count__Vfuncrtn__Vcvt;
    get_store_inst_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_store_inst_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_store_inst_count_t __Vcb = (VysyxSoCFull__Vcb_get_store_inst_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_store_inst_count__Vfuncrtn__Vcvt);
    int get_store_inst_count__Vfuncrtn;
    for (size_t get_store_inst_count__Vfuncrtn__Vidx = 0; get_store_inst_count__Vfuncrtn__Vidx < 1; ++get_store_inst_count__Vfuncrtn__Vidx) get_store_inst_count__Vfuncrtn = get_store_inst_count__Vfuncrtn__Vcvt;
    return get_store_inst_count__Vfuncrtn;
}

int VysyxSoCFull::get_branch_inst_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_branch_inst_count\n"); );
    // Init
    IData/*31:0*/ get_branch_inst_count__Vfuncrtn__Vcvt;
    get_branch_inst_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_branch_inst_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_branch_inst_count_t __Vcb = (VysyxSoCFull__Vcb_get_branch_inst_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_branch_inst_count__Vfuncrtn__Vcvt);
    int get_branch_inst_count__Vfuncrtn;
    for (size_t get_branch_inst_count__Vfuncrtn__Vidx = 0; get_branch_inst_count__Vfuncrtn__Vidx < 1; ++get_branch_inst_count__Vfuncrtn__Vidx) get_branch_inst_count__Vfuncrtn = get_branch_inst_count__Vfuncrtn__Vcvt;
    return get_branch_inst_count__Vfuncrtn;
}

int VysyxSoCFull::get_jump_inst_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_jump_inst_count\n"); );
    // Init
    IData/*31:0*/ get_jump_inst_count__Vfuncrtn__Vcvt;
    get_jump_inst_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_jump_inst_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_jump_inst_count_t __Vcb = (VysyxSoCFull__Vcb_get_jump_inst_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_jump_inst_count__Vfuncrtn__Vcvt);
    int get_jump_inst_count__Vfuncrtn;
    for (size_t get_jump_inst_count__Vfuncrtn__Vidx = 0; get_jump_inst_count__Vfuncrtn__Vidx < 1; ++get_jump_inst_count__Vfuncrtn__Vidx) get_jump_inst_count__Vfuncrtn = get_jump_inst_count__Vfuncrtn__Vcvt;
    return get_jump_inst_count__Vfuncrtn;
}

int VysyxSoCFull::get_csr_inst_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_csr_inst_count\n"); );
    // Init
    IData/*31:0*/ get_csr_inst_count__Vfuncrtn__Vcvt;
    get_csr_inst_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_csr_inst_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_csr_inst_count_t __Vcb = (VysyxSoCFull__Vcb_get_csr_inst_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_csr_inst_count__Vfuncrtn__Vcvt);
    int get_csr_inst_count__Vfuncrtn;
    for (size_t get_csr_inst_count__Vfuncrtn__Vidx = 0; get_csr_inst_count__Vfuncrtn__Vidx < 1; ++get_csr_inst_count__Vfuncrtn__Vidx) get_csr_inst_count__Vfuncrtn = get_csr_inst_count__Vfuncrtn__Vcvt;
    return get_csr_inst_count__Vfuncrtn;
}

int VysyxSoCFull::get_other_inst_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_other_inst_count\n"); );
    // Init
    IData/*31:0*/ get_other_inst_count__Vfuncrtn__Vcvt;
    get_other_inst_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_other_inst_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_other_inst_count_t __Vcb = (VysyxSoCFull__Vcb_get_other_inst_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_other_inst_count__Vfuncrtn__Vcvt);
    int get_other_inst_count__Vfuncrtn;
    for (size_t get_other_inst_count__Vfuncrtn__Vidx = 0; get_other_inst_count__Vfuncrtn__Vidx < 1; ++get_other_inst_count__Vfuncrtn__Vidx) get_other_inst_count__Vfuncrtn = get_other_inst_count__Vfuncrtn__Vcvt;
    return get_other_inst_count__Vfuncrtn;
}

int VysyxSoCFull::get_reg_value(int reg_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_reg_value\n"); );
    // Init
    IData/*31:0*/ reg_index__Vcvt;
    reg_index__Vcvt = 0;
    IData/*31:0*/ get_reg_value__Vfuncrtn__Vcvt;
    get_reg_value__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_reg_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_reg_value_t __Vcb = (VysyxSoCFull__Vcb_get_reg_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    reg_index__Vcvt = reg_index;
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), reg_index__Vcvt, get_reg_value__Vfuncrtn__Vcvt);
    int get_reg_value__Vfuncrtn;
    for (size_t get_reg_value__Vfuncrtn__Vidx = 0; get_reg_value__Vfuncrtn__Vidx < 1; ++get_reg_value__Vfuncrtn__Vidx) get_reg_value__Vfuncrtn = get_reg_value__Vfuncrtn__Vcvt;
    return get_reg_value__Vfuncrtn;
}

int VysyxSoCFull::get_exu_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_exu_count\n"); );
    // Init
    IData/*31:0*/ get_exu_count__Vfuncrtn__Vcvt;
    get_exu_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_exu_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_exu_count_t __Vcb = (VysyxSoCFull__Vcb_get_exu_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_exu_count__Vfuncrtn__Vcvt);
    int get_exu_count__Vfuncrtn;
    for (size_t get_exu_count__Vfuncrtn__Vidx = 0; get_exu_count__Vfuncrtn__Vidx < 1; ++get_exu_count__Vfuncrtn__Vidx) get_exu_count__Vfuncrtn = get_exu_count__Vfuncrtn__Vcvt;
    return get_exu_count__Vfuncrtn;
}

int VysyxSoCFull::get_csr_reg_value(int csr_reg_index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_csr_reg_value\n"); );
    // Init
    IData/*31:0*/ csr_reg_index__Vcvt;
    csr_reg_index__Vcvt = 0;
    IData/*31:0*/ get_csr_reg_value__Vfuncrtn__Vcvt;
    get_csr_reg_value__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_csr_reg_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_csr_reg_value_t __Vcb = (VysyxSoCFull__Vcb_get_csr_reg_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    csr_reg_index__Vcvt = csr_reg_index;
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), csr_reg_index__Vcvt, get_csr_reg_value__Vfuncrtn__Vcvt);
    int get_csr_reg_value__Vfuncrtn;
    for (size_t get_csr_reg_value__Vfuncrtn__Vidx = 0; get_csr_reg_value__Vfuncrtn__Vidx < 1; ++get_csr_reg_value__Vfuncrtn__Vidx) get_csr_reg_value__Vfuncrtn = get_csr_reg_value__Vfuncrtn__Vcvt;
    return get_csr_reg_value__Vfuncrtn;
}

int VysyxSoCFull::get_saved_addr() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_saved_addr\n"); );
    // Init
    IData/*31:0*/ get_saved_addr__Vfuncrtn__Vcvt;
    get_saved_addr__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_saved_addr");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_saved_addr_t __Vcb = (VysyxSoCFull__Vcb_get_saved_addr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_saved_addr__Vfuncrtn__Vcvt);
    int get_saved_addr__Vfuncrtn;
    for (size_t get_saved_addr__Vfuncrtn__Vidx = 0; get_saved_addr__Vfuncrtn__Vidx < 1; ++get_saved_addr__Vfuncrtn__Vidx) get_saved_addr__Vfuncrtn = get_saved_addr__Vfuncrtn__Vcvt;
    return get_saved_addr__Vfuncrtn;
}

int VysyxSoCFull::get_lsu_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_lsu_count\n"); );
    // Init
    IData/*31:0*/ get_lsu_count__Vfuncrtn__Vcvt;
    get_lsu_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_lsu_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_lsu_count_t __Vcb = (VysyxSoCFull__Vcb_get_lsu_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_lsu_count__Vfuncrtn__Vcvt);
    int get_lsu_count__Vfuncrtn;
    for (size_t get_lsu_count__Vfuncrtn__Vidx = 0; get_lsu_count__Vfuncrtn__Vidx < 1; ++get_lsu_count__Vfuncrtn__Vidx) get_lsu_count__Vfuncrtn = get_lsu_count__Vfuncrtn__Vcvt;
    return get_lsu_count__Vfuncrtn;
}

int VysyxSoCFull::get_read_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_read_count\n"); );
    // Init
    IData/*31:0*/ get_read_count__Vfuncrtn__Vcvt;
    get_read_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_read_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_read_count_t __Vcb = (VysyxSoCFull__Vcb_get_read_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_read_count__Vfuncrtn__Vcvt);
    int get_read_count__Vfuncrtn;
    for (size_t get_read_count__Vfuncrtn__Vidx = 0; get_read_count__Vfuncrtn__Vidx < 1; ++get_read_count__Vfuncrtn__Vidx) get_read_count__Vfuncrtn = get_read_count__Vfuncrtn__Vcvt;
    return get_read_count__Vfuncrtn;
}

int VysyxSoCFull::get_write_count() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_write_count\n"); );
    // Init
    IData/*31:0*/ get_write_count__Vfuncrtn__Vcvt;
    get_write_count__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_write_count");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_write_count_t __Vcb = (VysyxSoCFull__Vcb_get_write_count_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_write_count__Vfuncrtn__Vcvt);
    int get_write_count__Vfuncrtn;
    for (size_t get_write_count__Vfuncrtn__Vidx = 0; get_write_count__Vfuncrtn__Vidx < 1; ++get_write_count__Vfuncrtn__Vidx) get_write_count__Vfuncrtn = get_write_count__Vfuncrtn__Vcvt;
    return get_write_count__Vfuncrtn;
}

int VysyxSoCFull::get_switch_value() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root::get_switch_value\n"); );
    // Init
    IData/*31:0*/ get_switch_value__Vfuncrtn__Vcvt;
    get_switch_value__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_switch_value");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VysyxSoCFull__Vcb_get_switch_value_t __Vcb = (VysyxSoCFull__Vcb_get_switch_value_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VysyxSoCFull__Syms*)(__Vscopep->symsp()), get_switch_value__Vfuncrtn__Vcvt);
    int get_switch_value__Vfuncrtn;
    for (size_t get_switch_value__Vfuncrtn__Vidx = 0; get_switch_value__Vfuncrtn__Vidx < 1; ++get_switch_value__Vfuncrtn__Vidx) get_switch_value__Vfuncrtn = get_switch_value__Vfuncrtn__Vcvt;
    return get_switch_value__Vfuncrtn;
}
