// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "VysyxSoCFull.h"
#include "VysyxSoCFull__Syms.h"
#include "verilated_dpi.h"


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
