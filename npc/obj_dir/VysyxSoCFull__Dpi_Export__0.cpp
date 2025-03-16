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
