// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "VysyxSoCFull__pch.h"
#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull___024root.h"

extern "C" void ebreak(int exit_code);

VL_INLINE_OPT void VysyxSoCFull___024root____Vdpiimwrap_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ebreak_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ exit_code) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiimwrap_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ebreak_TOP\n"); );
    // Body
    int exit_code__Vcvt;
    for (size_t exit_code__Vidx = 0; exit_code__Vidx < 1; ++exit_code__Vidx) exit_code__Vcvt = exit_code;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    ebreak(exit_code__Vcvt);
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_pc_value_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_pc_value__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_pc_value_TOP\n"); );
    // Init
    // Body
    get_pc_value__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_if_allow_in_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_if_allow_in__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__get_if_allow_in_TOP\n"); );
    // Init
    // Body
    get_if_allow_in__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__if_allow_in;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__get_ifu_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_ifu_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__get_ifu_count_TOP\n"); );
    // Init
    // Body
    get_ifu_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__get_hit_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_hit_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__get_hit_count_TOP\n"); );
    // Init
    // Body
    get_hit_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__get_miss_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_miss_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__get_miss_count_TOP\n"); );
    // Init
    // Body
    get_miss_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_inst_r_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_inst_r__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_inst_r_TOP\n"); );
    // Init
    // Body
    get_inst_r__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__inst_r;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_idu_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_idu_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_idu_count_TOP\n"); );
    // Init
    // Body
    get_idu_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_compute_inst_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_compute_inst_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_compute_inst_count_TOP\n"); );
    // Init
    // Body
    get_compute_inst_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_load_inst_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_load_inst_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_load_inst_count_TOP\n"); );
    // Init
    // Body
    get_load_inst_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_store_inst_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_store_inst_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_store_inst_count_TOP\n"); );
    // Init
    // Body
    get_store_inst_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_branch_inst_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_branch_inst_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_branch_inst_count_TOP\n"); );
    // Init
    // Body
    get_branch_inst_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_jump_inst_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_jump_inst_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_jump_inst_count_TOP\n"); );
    // Init
    // Body
    get_jump_inst_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_csr_inst_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_csr_inst_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_csr_inst_count_TOP\n"); );
    // Init
    // Body
    get_csr_inst_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_other_inst_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_other_inst_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__get_other_inst_count_TOP\n"); );
    // Init
    // Body
    get_other_inst_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__get_reg_value_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ reg_index, IData/*31:0*/ &get_reg_value__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__get_reg_value_TOP\n"); );
    // Init
    // Body
    get_reg_value__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf
        [(0x1fU & reg_index)];
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__get_exu_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_exu_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__get_exu_count_TOP\n"); );
    // Init
    // Body
    get_exu_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr__DOT__get_csr_reg_value_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ csr_reg_index, IData/*31:0*/ &get_csr_reg_value__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr__DOT__get_csr_reg_value_TOP\n"); );
    // Init
    // Body
    if ((1U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mcause;
    } else if ((2U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mtvec;
    } else if ((3U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mepc;
    } else if ((4U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mstatus;
    }
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_saved_addr_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_saved_addr__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_saved_addr_TOP\n"); );
    // Init
    // Body
    get_saved_addr__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__saved_addr;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_lsu_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_lsu_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_lsu_count_TOP\n"); );
    // Init
    // Body
    get_lsu_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__lsu_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_read_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_read_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_read_count_TOP\n"); );
    // Init
    // Body
    get_read_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__read_count;
}

void VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_write_count_TOP(VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_write_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiexp_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__get_write_count_TOP\n"); );
    // Init
    // Body
    get_write_count__Vfuncrtn = vlSymsp->TOP.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__write_count;
}

extern "C" void mrom_read(int raddr, int* rdata);

VL_INLINE_OPT void VysyxSoCFull___024root____Vdpiimwrap_ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__mrom__DOT__mrom_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &rdata) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root____Vdpiimwrap_ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__mrom__DOT__mrom_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int rdata__Vcvt;
    mrom_read(raddr__Vcvt, &rdata__Vcvt);
    rdata = rdata__Vcvt;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VysyxSoCFull___024root___dump_triggers__ico(VysyxSoCFull___024root* vlSelf);
#endif  // VL_DEBUG

void VysyxSoCFull___024root___eval_triggers__ico(VysyxSoCFull___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root___eval_triggers__ico\n"); );
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VysyxSoCFull___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VysyxSoCFull___024root___dump_triggers__act(VysyxSoCFull___024root* vlSelf);
#endif  // VL_DEBUG

void VysyxSoCFull___024root___eval_triggers__act(VysyxSoCFull___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root___eval_triggers__act\n"); );
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset__0))));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSelfRef.reset) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0))));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(vlSelfRef.ysyxSoCFull__DOT___asic_spi_sck) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT___asic_spi_sck__0))));
    vlSelfRef.__VactTriggered.setBit(5U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__reset) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__flash__DOT__reset__0))));
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSelfRef.ysyxSoCFull__DOT____Vcellinp__bitrev__ss) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT____Vcellinp__bitrev__ss__0))));
    vlSelfRef.__VactTriggered.setBit(7U, ((IData)(vlSelfRef.ysyxSoCFull__DOT___asic_psram_ce_n) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT___asic_psram_ce_n__0))));
    vlSelfRef.__VactTriggered.setBit(8U, ((IData)(vlSelfRef.ysyxSoCFull__DOT___asic_psram_sck) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT___asic_psram_sck__0))));
    vlSelfRef.__VactTriggered.setBit(9U, ((~ (IData)(vlSelfRef.clock)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT___asic_spi_sck__0 
        = vlSelfRef.ysyxSoCFull__DOT___asic_spi_sck;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__flash__DOT__reset__0 
        = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT____Vcellinp__bitrev__ss__0 
        = vlSelfRef.ysyxSoCFull__DOT____Vcellinp__bitrev__ss;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT___asic_psram_ce_n__0 
        = vlSelfRef.ysyxSoCFull__DOT___asic_psram_ce_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT___asic_psram_sck__0 
        = vlSelfRef.ysyxSoCFull__DOT___asic_psram_sck;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VysyxSoCFull___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void VysyxSoCFull___024root___nba_sequent__TOP__0(VysyxSoCFull___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root___nba_sequent__TOP__0\n"); );
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__counter 
        = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__cmd 
        = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__cmd;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__state 
        = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__data 
        = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__data;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__addr 
        = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__addr;
    if (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__reset) {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__counter = 0U;
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__cmd = 0U;
    } else if ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state))) {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__counter 
            = (0xffU & ((7U > (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))
                         ? ((IData)(1U) + (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))
                         : 0U));
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__cmd 
            = ((0xfeU & ((IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__cmd) 
                         << 1U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT___asic_spi_mosi));
    } else {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__counter 
            = (0xffU & ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state))
                         ? ((0x17U > (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))
                             ? ((IData)(1U) + (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))
                             : 0U) : ((IData)(1U) + (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))));
    }
    if (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__reset) {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__state = 0U;
    } else if ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state))) {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__state 
            = ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))
                ? 1U : (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state));
    } else if ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state))) {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__state 
            = ((3U != (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__cmd))
                ? 3U : ((0x17U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))
                         ? 2U : (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state)));
    } else if (VL_LIKELY(((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state))))) {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__state 
            = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state;
    } else {
        VL_FWRITEF_NX(0x80000002U,"Assertion failed: Unsupported command `%xh`, only support `03h` read command\n",0,
                      8,vlSelfRef.ysyxSoCFull__DOT__flash__DOT__cmd);
        if (0x80000002U) { VL_FFLUSH_I(0x80000002U); }
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__state 
            = vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state;
        VL_WRITEF_NX("[%0t] %%Fatal: flash.v:44: Assertion failed in %NysyxSoCFull.flash\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/perip/flash/flash.v", 44, "", false);
    }
    if (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__reset) {
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__data = 0U;
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__addr = 0U;
    } else {
        if ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state))) {
            vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__data 
                = (((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter))
                     ? vlSelfRef.ysyxSoCFull__DOT__flash__DOT__data_bswap
                     : vlSelfRef.ysyxSoCFull__DOT__flash__DOT__data) 
                   << 1U);
        }
        if (((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state)) 
             & (0x17U > (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter)))) {
            vlSelfRef.__Vdly__ysyxSoCFull__DOT__flash__DOT__addr 
                = ((0xfffffeU & (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__addr 
                                 << 1U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT___asic_spi_mosi));
        }
    }
}

VL_INLINE_OPT void VysyxSoCFull___024root___nba_sequent__TOP__3(VysyxSoCFull___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root___nba_sequent__TOP__3\n"); );
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_4;
    ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_4 = 0;
    SData/*15:0*/ ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_5;
    ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_5 = 0;
    CData/*0:0*/ ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_0;
    ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_0 = 0;
    CData/*0:0*/ ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_1;
    ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_1 = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3 = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2 = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1 = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3 = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4 = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1 = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready = 0;
    QData/*63:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count = 0;
    CData/*3:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count = 0;
    VlWide<4>/*127:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data;
    VL_ZERO_W(128, __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data);
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready = 0;
    IData/*31:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14 = 0;
    CData/*1:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15 = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full = 0;
    CData/*0:0*/ __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full = 0;
    CData/*1:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*2:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v0;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v0 = 0;
    IData/*23:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16 = 0;
    CData/*3:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16 = 0;
    CData/*3:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v16;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v16 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16;
    VL_ZERO_W(128, __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16);
    CData/*3:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16 = 0;
    IData/*31:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0;
    CData/*7:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0 = 0;
    CData/*7:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0 = 0;
    CData/*7:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0 = 0;
    SData/*10:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0 = 0;
    CData/*7:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1 = 0;
    SData/*10:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1 = 0;
    CData/*7:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2 = 0;
    SData/*10:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2 = 0;
    CData/*7:0*/ __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3;
    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3 = 0;
    SData/*10:0*/ __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3;
    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3 = 0;
    CData/*0:0*/ __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3 = 0;
    // Body
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0 = 0U;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready;
    vlSelfRef.__VdlySet__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v0 = 0U;
    vlSelfRef.__VdlySet__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v1 = 0U;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0 = 0U;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0 = 0U;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4;
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((0x200U & ((~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready) 
                                               & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid))) 
                                           << 9U)) 
                                | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:4408: Assertion failed in %NysyxSoCFull.asic.axi4frag: Assertion failed at Fragmenter.scala:181\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 4408, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:4410: Assertion failed in %NysyxSoCFull.asic.axi4frag\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 4410, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid)) 
                                   | (~ ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full))) 
                                         || (1U & (IData)(
                                                          (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
                                                           >> 0x24U)))))) 
                                  | (1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:4414: Assertion failed in %NysyxSoCFull.asic.axi4frag: Assertion failed at Fragmenter.scala:190\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 4414, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:4416: Assertion failed in %NysyxSoCFull.asic.axi4frag\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 4416, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1771: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1771, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1773: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1773, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1777: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1777, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1779: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1779, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1783: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1783, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1785: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1785, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1789: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1789, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1791: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1791, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1795: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1795, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1797: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1797, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1801: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1801, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1803: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1803, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1807: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1807, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1809: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1809, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1813: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1813, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1815: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1815, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1819: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1819, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1821: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1821, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1825: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1825, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1827: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1827, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1831: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1831, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1833: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1833, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1837: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1837, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1839: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1839, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1843: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1843, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1845: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1845, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1849: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1849, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1851: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1851, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1855: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1855, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1857: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1857, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1861: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1861, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1863: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1863, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1867: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1867, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1869: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1869, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1873: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1873, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1875: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1875, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1879: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1879, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1881: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1881, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1885: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1885, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1887: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1887, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1891: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1891, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1893: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1893, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1897: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1897, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1899: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1899, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1903: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1903, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1905: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1905, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1909: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1909, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1911: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1911, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1915: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1915, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1917: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1917, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1921: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1921, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1923: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1923, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1927: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1927, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1929: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1929, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1933: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1933, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1935: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1935, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1939: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1939, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1941: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1941, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1945: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1945, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1947: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1947, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1951: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1951, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1953: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1953, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1957: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1957, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1959: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1959, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1963: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1963, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1965: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1965, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1969: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1969, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1971: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1971, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1975: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1975, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1977: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1977, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1981: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1981, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1983: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1983, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1987: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1987, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1989: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1989, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1993: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1993, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1995: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1995, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1999: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1999, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2001: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2001, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2005: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2005, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2007: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2007, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2011: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2011, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2013: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2013, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2017: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2017, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2019: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2019, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2023: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2023, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2025: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2025, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2029: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2029, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2031: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2031, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2035: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2035, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2037: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2037, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2041: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2041, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2043: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2043, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2047: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2047, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2049: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2049, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2053: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2053, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2055: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2055, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2059: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2059, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2061: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2061, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2065: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2065, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2067: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2067, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2071: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2071, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2073: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2073, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2077: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2077, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2079: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2079, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2083: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2083, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2085: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2085, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2089: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2089, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2091: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2091, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2095: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2095, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2097: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2097, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2101: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2101, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2103: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2103, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2107: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2107, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2109: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2109, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2113: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2113, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2115: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2115, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2119: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2119, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2121: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2121, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2125: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2125, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2127: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2127, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2131: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2131, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2133: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2133, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2137: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2137, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2139: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2139, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4))) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2143: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2143, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2145: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2145, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2149: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2149, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2151: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2151, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1)) 
                                   | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1))) 
                                  & ((~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1) 
                                         | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1))) 
                                     | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2)))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2157: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:286\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2157, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2159: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2159, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid)) 
                                    | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1)) 
                                   | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1)) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2163: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:288\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2163, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2165: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2165, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0)) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2169: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:286\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2169, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2171: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2171, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1)) 
                                   | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0)) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2175: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1: Assertion failed at Xbar.scala:288\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2175, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2177: Assertion failed in %NysyxSoCFull.asic.axi4xbar_1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2177, "", false);
    }
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0 = 0U;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1 = 0U;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2 = 0U;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3 = 0U;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full;
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid) 
                         & (0U == ((6U & (4U ^ (0x1eU 
                                                & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                                   >> 0x1bU)))) 
                                   | (1U & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                            >> 0x18U))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2950: Assertion failed in %NysyxSoCFull.asic.lmrom: Assertion failed: do not support write operations\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2950, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2952: Assertion failed in %NysyxSoCFull.asic.lmrom\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2952, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_wvalid) 
                         & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awIn_0_io_deq_bits) 
                            >> 1U)))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:2956: Assertion failed in %NysyxSoCFull.asic.lmrom: Assertion failed: do not support write operations\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2956, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:2958: Assertion failed in %NysyxSoCFull.asic.lmrom\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 2958, "", false);
    }
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0U;
    if (VL_UNLIKELY(((((~ (IData)(vlSelfRef.reset)) 
                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid)) 
                      & (2U < (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size)))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:3330: Assertion failed in %NysyxSoCFull.asic.axi42apb: Assertion failed at AXI4ToAPB.scala:64\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3330, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:3332: Assertion failed in %NysyxSoCFull.asic.axi42apb\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3332, "", false);
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelfRef.reset)) 
                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid)) 
                      & (2U < (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size)))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:3336: Assertion failed in %NysyxSoCFull.asic.axi42apb: Assertion failed at AXI4ToAPB.scala:65\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3336, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:3338: Assertion failed in %NysyxSoCFull.asic.axi42apb\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3338, "", false);
    }
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full;
    if (VL_UNLIKELY(((0U != ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__muxState_3_0)
                              ? (3U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp) 
                                       | (((((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15) 
                                               << 0x1eU) 
                                              | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14) 
                                                 << 0x1cU)) 
                                             | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13) 
                                                 << 0x1aU) 
                                                | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12) 
                                                   << 0x18U))) 
                                            | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11) 
                                                 << 0x16U) 
                                                | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10) 
                                                   << 0x14U)) 
                                               | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9) 
                                                   << 0x12U) 
                                                  | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8) 
                                                     << 0x10U)))) 
                                           | (((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7) 
                                                 << 0xeU) 
                                                | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6) 
                                                   << 0xcU)) 
                                               | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5) 
                                                   << 0xaU) 
                                                  | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4) 
                                                     << 8U))) 
                                              | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3) 
                                                   << 6U) 
                                                  | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2) 
                                                     << 4U)) 
                                                 | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1) 
                                                     << 2U) 
                                                    | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0))))) 
                                          >> (0x1fU 
                                              & VL_SHIFTL_III(5,5,32, (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid), 1U)))))
                              : 0U))))) {
        VL_WRITEF_NX("LSU error! bid expected: %x, received: %x, bresp: %b\n",0,
                     4,vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__curr_id,
                     4,(IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid),
                     2,((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__muxState_3_0)
                         ? (3U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp) 
                                  | (((((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15) 
                                          << 0x1eU) 
                                         | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14) 
                                            << 0x1cU)) 
                                        | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13) 
                                            << 0x1aU) 
                                           | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12) 
                                              << 0x18U))) 
                                       | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11) 
                                            << 0x16U) 
                                           | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10) 
                                              << 0x14U)) 
                                          | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9) 
                                              << 0x12U) 
                                             | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8) 
                                                << 0x10U)))) 
                                      | (((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7) 
                                            << 0xeU) 
                                           | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6) 
                                              << 0xcU)) 
                                          | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5) 
                                              << 0xaU) 
                                             | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4) 
                                                << 8U))) 
                                         | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3) 
                                              << 6U) 
                                             | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2) 
                                                << 4U)) 
                                            | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0))))) 
                                     >> (0x1fU & VL_SHIFTL_III(5,5,32, (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid), 1U)))))
                         : 0U));
        Verilated::runFlushCallbacks();
    }
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_rresp))))) {
        VL_WRITEF_NX("LSU read ID wrong! curr_id: %x, rid: %x, rresp: %b\n",0,
                     4,vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__curr_id,
                     4,(IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_rid),
                     2,vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_rresp);
        Verilated::runFlushCallbacks();
    }
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 0U;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[0U] 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[0U];
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[1U] 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[1U];
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[2U] 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[2U];
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[3U] 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[3U];
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v0 = 0U;
    __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16 = 0U;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id;
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full;
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_0_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:598: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 598, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:600: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 600, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_0_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_0_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:604: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 604, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:606: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 606, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_0_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:610: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 610, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:612: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 612, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_0_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_0_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:616: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 616, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:618: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 618, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_1_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:622: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 622, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:624: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 624, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_1_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_1_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:628: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 628, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:630: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 630, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_1_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:634: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 634, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:636: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 636, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_1_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_1_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:640: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 640, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:642: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 642, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_2_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:646: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 646, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:648: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 648, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_2_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_2_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:652: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 652, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:654: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 654, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_2_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:658: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 658, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:660: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 660, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_2_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_2_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:664: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 664, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:666: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 666, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_3_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:670: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 670, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:672: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 672, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_3_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_3_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:676: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 676, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:678: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 678, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_3_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:682: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 682, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:684: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 684, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_3_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_3_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:688: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 688, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:690: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 690, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_4_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:694: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 694, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:696: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 696, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_4_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_4_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:700: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 700, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:702: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 702, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_4_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:706: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 706, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:708: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 708, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_4_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_4_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:712: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 712, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:714: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 714, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_5_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:718: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 718, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:720: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 720, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_5_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_5_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:724: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 724, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:726: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 726, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_5_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:730: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 730, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:732: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 732, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_5_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_5_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:736: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 736, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:738: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 738, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_6_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:742: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 742, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:744: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 744, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_6_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_6_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:748: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 748, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:750: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 750, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_6_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:754: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 754, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:756: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 756, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_6_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_6_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:760: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 760, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:762: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 762, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_7_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:766: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 766, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:768: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 768, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_7_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_7_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:772: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 772, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:774: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 774, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_7_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:778: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 778, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:780: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 780, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_7_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_7_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:784: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 784, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:786: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 786, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_8_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:790: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 790, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:792: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 792, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_8_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_8_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:796: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 796, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:798: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 798, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_8_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:802: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 802, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:804: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 804, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_8_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_8_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:808: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 808, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:810: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 810, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_9_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:814: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 814, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:816: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 816, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_9_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_9_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:820: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 820, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:822: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 822, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_9_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:826: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 826, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:828: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 828, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_9_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_9_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:832: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 832, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:834: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 834, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_10_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:838: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 838, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:840: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 840, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_10_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_10_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:844: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 844, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:846: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 846, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_10_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:850: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 850, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:852: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 852, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_10_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_10_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:856: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 856, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:858: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 858, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_11_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:862: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 862, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:864: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 864, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_11_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_11_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:868: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 868, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:870: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 870, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_11_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:874: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 874, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:876: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 876, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_11_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_11_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:880: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 880, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:882: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 882, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_12_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:886: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 886, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:888: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 888, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_12_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_12_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:892: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 892, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:894: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 894, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_12_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:898: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 898, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:900: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 900, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_12_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_12_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:904: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 904, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:906: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 906, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_13_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:910: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 910, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:912: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 912, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_13_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_13_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:916: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 916, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:918: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 918, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_13_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:922: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 922, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:924: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 924, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_13_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_13_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:928: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 928, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:930: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 930, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_14_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:934: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 934, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:936: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 936, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_14_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_14_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:940: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 940, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:942: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 942, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_14_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:946: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 946, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:948: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 948, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_14_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_14_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:952: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 952, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:954: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 954, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_15_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:958: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 958, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:960: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 960, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_15_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_15_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:964: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 964, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:966: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 966, "", false);
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.reset)) 
                      & (0U == ((8U & ((~ ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))) 
                                       << 3U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_15_count))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:970: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:131\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 970, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:972: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 972, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_2)) 
                                  | (7U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_15_count))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:976: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:132\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 976, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:978: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 978, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__prefixOR_1)) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_2_1))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:982: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:286\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 982, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:984: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 984, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__anyValid)) 
                                   | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__prefixOR_1)) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_2_1)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:988: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:288\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 988, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:990: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 990, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_3_0)) 
                                  | (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_3_1))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:994: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:286\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 994, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:996: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 996, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__anyValid_1)) 
                                   | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_3_0)) 
                                  | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_3_1)))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:1000: Assertion failed in %NysyxSoCFull.asic.axi4xbar: Assertion failed at Xbar.scala:288\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1000, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:1002: Assertion failed in %NysyxSoCFull.asic.axi4xbar\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 1002, "", false);
    }
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__lsu_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__lsu_count;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__read_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__read_count;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__write_count 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__write_count;
    vlSelfRef.__Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__curr_id 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__curr_id;
    ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_4 
        = ((((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full) 
               << 0xfU) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full) 
                           << 0xeU)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full) 
                                         << 0xdU) | 
                                        ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full) 
                                         << 0xcU))) 
            | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full) 
                 << 0xbU) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full) 
                             << 0xaU)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full) 
                                           << 9U) | 
                                          ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full) 
                                           << 8U)))) 
           | (((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full) 
                 << 7U) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full) 
                           << 6U)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full) 
                                       << 5U) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full) 
                                                 << 4U))) 
              | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full) 
                   << 3U) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full) 
                             << 2U)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full) 
                                         << 1U) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))));
    ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_5 
        = ((((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full) 
               << 0xfU) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full) 
                           << 0xeU)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full) 
                                         << 0xdU) | 
                                        ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full) 
                                         << 0xcU))) 
            | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full) 
                 << 0xbU) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full) 
                             << 0xaU)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full) 
                                           << 9U) | 
                                          ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full) 
                                           << 8U)))) 
           | (((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full) 
                 << 7U) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full) 
                           << 6U)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full) 
                                       << 5U) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full) 
                                                 << 4U))) 
              | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full) 
                   << 3U) | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full) 
                             << 2U)) | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full) 
                                         << 1U) | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__unnamedblk1__DOT__i = 0x10U;
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid)) 
                                  | ((IData)(ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_4) 
                                     >> (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:3734: Assertion failed in %NysyxSoCFull.asic.axi4yank.unnamedblk1: Assertion failed at UserYanker.scala:69\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3734, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:3736: Assertion failed in %NysyxSoCFull.asic.axi4yank.unnamedblk1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3736, "", false);
    }
    if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.reset)) 
                            & (~ ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid)) 
                                  | ((IData)(ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__unnamedblk1__DOT___GEN_5) 
                                     >> (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ysyxSoCFull.v:3740: Assertion failed in %NysyxSoCFull.asic.axi4yank.unnamedblk1: Assertion failed at UserYanker.scala:98\n\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3740, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ysyxSoCFull.v:3742: Assertion failed in %NysyxSoCFull.asic.axi4yank.unnamedblk1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("../ysyxSoC/build/ysyxSoCFull.v", 3742, "", false);
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime = 0ULL;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count = 0U;
    } else {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime 
            = (1ULL + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime);
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_to_idu_valid) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_ifu_ready))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count 
                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count);
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc = 0x30000000U;
    } else if (VL_UNLIKELY(((0x100073U == vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst)))) {
        VL_WRITEF_NX("pc = 0x%08x from NPC\ninst = 0x%08x from NPC\n",0,
                     32,vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc,
                     32,vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst);
        Verilated::runFlushCallbacks();
        VysyxSoCFull___024root____Vdpiimwrap_ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ebreak_TOP(
                                                                                (&(vlSymsp->__Vscope_ysyxSoCFull__asic__cpu__cpu)), 
                                                                                "vsrc/NPC.v", 0x275U, 
                                                                                vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf
                                                                                [0xaU]);
    }
    if (VL_UNLIKELY((vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset))) {
        VL_WRITEF_NX("reset = %1# \n",0,1,vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset);
        Verilated::runFlushCallbacks();
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc = 0x30000000U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready = 1U;
    } else if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_valid) 
                & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready))) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__next_pc;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready)))) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready = 1U;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count = 0U;
    }
    if (((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__state)) 
         & (0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__next_state)))) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count 
            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count);
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count = 0U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) 
         & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state)))) {
        if ((0x40U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            if ((0x20U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count 
                                        = ((IData)(1U) 
                                           + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count = 0U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) 
         & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state)))) {
        if ((0x40U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            if ((0x20U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        if ((4U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                            if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count 
                                        = ((IData)(1U) 
                                           + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count);
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count 
                                    = ((IData)(1U) 
                                       + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count);
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count = 0U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) 
         & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state)))) {
        if ((0x40U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            if ((0x20U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((0x10U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    if ((8U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                    } else if ((4U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                    } else if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                        }
                    } else {
                        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                    }
                } else if ((8U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                            if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                                    = ((IData)(1U) 
                                       + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                            }
                        } else {
                            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                        }
                    } else {
                        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                    }
                } else if ((4U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                        }
                    } else {
                        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                    }
                } else if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                    }
                } else {
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                        = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                }
            } else {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
            }
        } else if ((0x20U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            if ((0x10U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((8U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                        = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                } else if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                    }
                } else {
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                        = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                }
            } else if ((8U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
            } else if ((4U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
            } else if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                        = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                }
            } else {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
            }
        } else if ((0x10U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            if ((8U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
            } else if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                        = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
                }
            } else {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
            }
        } else if ((8U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
        } else if ((4U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
        } else if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode)))) {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
            }
        } else {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count);
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count = 0U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) 
         & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state)))) {
        if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((0x10U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                  >> 3U)))) {
                        if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count 
                                    = ((IData)(1U) 
                                       + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count);
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                              >> 3U)))) {
                    if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count 
                                = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count);
                        }
                    }
                }
            }
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count = 0U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) 
         & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state)))) {
        if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count 
                                        = ((IData)(1U) 
                                           + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count = 0U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) 
         & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state)))) {
        if ((0x40U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
            if ((0x20U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((0x10U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                    if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count 
                                        = ((IData)(1U) 
                                           + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count = 0U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) 
         & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state)))) {
        if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__opcode))) {
                                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count 
                                        = ((IData)(1U) 
                                           + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__qpi_enabled) {
        if (((0xeU <= (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)) 
             & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                <= ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__qpi_enabled)
                     ? 0x15U : 0x1bU)))) {
            if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck) {
                vlSelfRef.__VdlyVal__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v0 
                    = ((0xf0U & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                                 [vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__byte_index] 
                                 << 4U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__psram__DOT__din));
                vlSelfRef.__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v0 
                    = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__byte_index;
                vlSelfRef.__VdlySet__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v0 = 1U;
            }
        }
    } else if (((0x14U <= (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter)) 
                & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__counter) 
                   <= ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__qpi_enabled)
                        ? 0x15U : 0x1bU)))) {
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__mr_sck) {
            vlSelfRef.__VdlyVal__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v1 
                = ((0xf0U & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data
                             [vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__byte_index] 
                             << 4U)) | (IData)(vlSelfRef.ysyxSoCFull__DOT__psram__DOT__din));
            vlSelfRef.__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v1 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__byte_index;
            vlSelfRef.__VdlySet__ysyxSoCFull__DOT__asic__DOT__lpsram__DOT__mpsram__DOT__u0__DOT__MR__DOT__data__v1 = 1U;
        }
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0 
            = (0xffU & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                        >> 3U));
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top;
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0 = 1U;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_in;
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top;
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0 = 1U;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren) 
                                                   | ((~ 
                                                       ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_rready) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full))) 
                                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_full))));
    __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___GEN) 
                                                   | ((~ 
                                                       ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_2_bready) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full))) 
                                                      & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_13_count) 
                                                       + 
                                                       ((0xdU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xdU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_12_count) 
                                                       + 
                                                       ((0xcU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xcU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_11_count) 
                                                       + 
                                                       ((0xbU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xbU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_10_count) 
                                                       + 
                                                       ((0xaU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xaU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_9_count) 
                                                       + 
                                                       ((9U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((9U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_8_count) 
                                                       + 
                                                       ((8U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((8U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_7_count) 
                                                       + 
                                                       ((7U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((7U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_6_count) 
                                                       + 
                                                       ((6U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((6U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_4_count) 
                                                       + 
                                                       ((4U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((4U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_0_count) 
                                                       + 
                                                       ((0U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_1_count) 
                                                       + 
                                                       ((1U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((1U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_2_count) 
                                                       + 
                                                       ((2U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((2U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_3_count) 
                                                       + 
                                                       ((3U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((3U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_5_count) 
                                                       + 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((5U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_14_count) 
                                                       + 
                                                       ((0xeU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xeU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__arFIFOMap_15_count) 
                                                       + 
                                                       ((0xfU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xfU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____VdfgRegularize_hb7083124_6_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)
                                                  ? 
                                                 (~ 
                                                  (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                                                    & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)
                                                        ? 
                                                       ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                                                        >> 1U)
                                                        : (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1))) 
                                                   & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__state)))
                                                  : (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_13_count) 
                                                       + 
                                                       ((0xdU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xdU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_12_count) 
                                                       + 
                                                       ((0xcU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xcU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_11_count) 
                                                       + 
                                                       ((0xbU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xbU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_10_count) 
                                                       + 
                                                       ((0xaU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xaU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_9_count) 
                                                       + 
                                                       ((9U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((9U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_8_count) 
                                                       + 
                                                       ((8U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((8U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_7_count) 
                                                       + 
                                                       ((7U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((7U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_6_count) 
                                                       + 
                                                       ((6U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((6U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_0_count) 
                                                       + 
                                                       ((0U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_1_count) 
                                                       + 
                                                       ((1U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((1U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_2_count) 
                                                       + 
                                                       ((2U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((2U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_3_count) 
                                                       + 
                                                       ((3U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((3U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_4_count) 
                                                       + 
                                                       ((4U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((4U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_5_count) 
                                                       + 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((5U 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_14_count) 
                                                       + 
                                                       ((0xeU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xeU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awFIFOMap_15_count) 
                                                       + 
                                                       ((0xfU 
                                                         == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid)) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_1))) 
                                                      - 
                                                      ((0xfU 
                                                        == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4)))));
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en) 
         & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb))) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0 
            = (0xffU & vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata);
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0 
            = (0x7ffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                         >> 2U));
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0 = 1U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en) 
         & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb) 
            >> 1U))) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1 
            = (0xffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata 
                        >> 8U));
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1 
            = (0x7ffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                         >> 2U));
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1 = 1U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en) 
         & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb) 
            >> 2U))) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2 
            = (0xffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata 
                        >> 0x10U));
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2 
            = (0x7ffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                         >> 2U));
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2 = 1U;
    }
    if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT____Vcellinp__mem_ext__W0_en) 
         & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb) 
            >> 3U))) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3 
            = (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata 
               >> 0x18U);
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3 
            = (0x7ffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                         >> 2U));
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3 = 1U;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT____Vcellinp__awIn_0__io_enq_bits;
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap;
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 1U;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ 
                                                    ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awready) 
                                                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_awvalid))) 
                                                   & (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0_io_enq_valid)) 
                                                      | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__do_enq) {
        __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____Vcellinp__awIn_0__io_enq_bits;
        __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap;
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0 = 1U;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__latched 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ 
                                                    ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__in_0_awready) 
                                                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__in_0_awvalid))) 
                                                   & (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__full)) 
                                                       & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0_io_enq_valid)) 
                                                      | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__latched))));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ 
                                                    ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_awready) 
                                                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_awvalid))) 
                                                   & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_valid) 
                                                       & (0U 
                                                          == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter))) 
                                                      | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready = 1U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count = 0U;
    } else if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_valid) 
                & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready))) {
        if ((0U != (0x1fU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__inst_r 
                             >> 7U)))) {
            __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__result;
            __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0 
                = (0x1fU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__inst_r 
                            >> 7U));
            __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0 = 1U;
        }
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready)))) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready = 1U;
    }
    if (((((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state)) 
           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_hit)) 
          & (0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__next_state))) 
         | ((((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state)) 
              & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_rvalid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_rready)) 
            & (0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__next_state))))) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count 
            = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count);
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_arready = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_rvalid = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__imm_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__alu_op_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__rs1_data_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__rs2_data_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mcause_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mstatus_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mtvec_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mepc_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__csr_rdata_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_rdata = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__current_state = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__pc_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__pc_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__inst_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__addr_r = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__state = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[0U] = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[1U] = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[2U] = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[3U] = 0U;
        __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v0 = 1U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state = 0U;
    } else {
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__state) {
            if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__state) {
                vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_arready = 0U;
                vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_rvalid = 1U;
                vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__divided_time 
                    = VL_DIV_QQQ(64, vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime, 0x3e8ULL);
                if ((8U == (0xfU & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__addr_r))) {
                    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__hw_time 
                        = (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__divided_time);
                    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_rdata 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__hw_time;
                } else if ((0xcU == (0xfU & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__addr_r))) {
                    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__hw_time 
                        = (IData)((vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__divided_time 
                                   >> 0x20U));
                    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_rdata 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__hw_time;
                } else {
                    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_rdata = 0U;
                }
            }
        } else {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_arready = 1U;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_rvalid = 0U;
        }
        if (((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__state)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_exu_valid))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__imm_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__alu_op_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__alu_op;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__rs1_data_r 
                = ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rs1))
                    ? 0U : vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf
                   [vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rs1]);
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__rs2_data_r 
                = ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rs2))
                    ? 0U : vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf
                   [vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rs2]);
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mcause_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mcause;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mstatus_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mstatus;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mtvec_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mtvec;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__mepc_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mepc;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__csr_rdata_r 
                = ((0x300U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_addr))
                    ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mstatus
                    : ((0x305U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_addr))
                        ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mtvec
                        : ((0x341U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_addr))
                            ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mepc
                            : ((0x342U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_addr))
                                ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mcause
                                : ((0xf11U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_addr))
                                    ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mvendorid
                                    : ((0xf12U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr_addr))
                                        ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__marchid
                                        : 0U))))));
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__pc_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc;
        }
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__current_state 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__next_state;
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_to_idu_valid) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_ifu_ready))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__pc_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__inst_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst;
        }
        if (((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__state)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_arvalid))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__addr_r 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_araddr;
        }
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__state 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__next_state;
        if (((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state)) 
             & (2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__next_state)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id)));
        }
        if ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state))) {
            if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_hit) {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count);
            } else {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count 
                    = ((IData)(1U) + vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count);
            }
        }
        if (((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state)) 
             & (1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__next_state)))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
        }
        if ((((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state)) 
              & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_rvalid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_rready))) {
            if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count))) {
                if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count))) {
                    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__req_tag;
                    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__req_index;
                    __VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16 = 1U;
                    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v16 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__req_index;
                    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[0U] 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[0U];
                    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[1U] 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[1U];
                    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[2U] 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[2U];
                    __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[3U] 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_rdata;
                    __VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__req_index;
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count = 0U;
                } else {
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count)));
                    __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[2U] 
                        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_rdata;
                }
            } else if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count))) {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count)));
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[1U] 
                    = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_rdata;
            } else {
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count)));
                __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[0U] 
                    = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_rdata;
            }
        }
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__next_state;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w;
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___nodeIn_rid_T) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rdata_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT___mrom_rdata;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lmrom__DOT__nodeIn_rid_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1;
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wdata;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_wstrb;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_id 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__r_sel1 
        = (0x7800U == (0x7fffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                                  >> 0xdU)));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT___R0_addr_d0 
        = (0x7ffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr 
                     >> 2U));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___GEN) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_id 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_araddr;
    }
    if ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r 
            = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pslverr) 
               << 1U);
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_sel1 
        = (0x7800U == (0x7fffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awaddr 
                                  >> 0xdU)));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_2) 
              & (0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_arid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len)))));
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_5_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_5_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_4_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_4_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_1_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_1_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_12_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_12_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_2_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_2_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_3_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_3_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_6_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_6_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_9_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_9_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_0_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_0_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_7_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_7_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_8_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_8_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_10_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_10_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_11_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_11_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_13_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_13_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_14_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_14_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_15_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_15_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestARIO_0_1;
    }
    if ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)) 
           & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT___GEN_8) 
              & (0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_awid))));
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__ram_real_last 
            = (1U & (~ (IData)((0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1)))));
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_3_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_3_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_2_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_2_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_13_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_13_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_10_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_10_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_1_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_1_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_15_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_0_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_0_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_4_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_4_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_7_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_7_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_5_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_5_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_6_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_6_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_8_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_8_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_9_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_9_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_11_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_11_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_12_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_12_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_14_T_2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_14_last 
            = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__requestAWIO_0_1;
    }
    ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_0 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_arready) 
           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0));
    if (ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___inc_addr_T_1 
            = (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr 
               + (0xffffU & ((IData)(1U) << (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___wrapMask_T_1 
            = (0x7fffffU & ((0xffU | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_len) 
                                      << 8U)) << (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_size)));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___mux_addr_T_1 
            = (~ vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr);
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len 
            = (0xffU & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len) 
                        - (IData)(1U)));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr 
            = ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst))
                ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_addr
                : ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst))
                    ? ((0x7fffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___inc_addr_T_1 
                                   & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___wrapMask_T_1 
                                      >> 8U))) | (~ 
                                                  ((0xffff8000U 
                                                    & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___mux_addr_T_1) 
                                                   | (0x7fffU 
                                                      & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___mux_addr_T_1 
                                                         | (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___wrapMask_T_1 
                                                            >> 8U))))))
                    : vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk3__DOT___inc_addr_T_1));
    }
    ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_1 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_awready) 
           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0));
    if (vlSelfRef.reset) {
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_15_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_14_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_5_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_0_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_3_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_2_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_1_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_4_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_6_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_7_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_8_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_9_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_10_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_11_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_12_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_13_count = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_15_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_14_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_2_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_5_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_4_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_3_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_1_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_0_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_6_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_7_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_8_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_9_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_10_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_11_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_12_count = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_13_count = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap = 0U;
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3 = 1U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_mask_1 = 3U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_3_0 = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_3_1 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2 = 1U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_mask = 3U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_2_0 = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_2_1 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4 = 1U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1 = 7U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0 = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__maybe_full = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1 = 0U;
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3 = 1U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask = 7U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0 = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1 = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2 = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter = 0U;
    } else {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2 
            = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready) 
               & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid));
        if (((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid)) 
             & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk2__DOT___GEN_2))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_becho_real_last)
                    ? 0U : ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15) 
                            | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_bresp)));
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full) 
                  & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__in_wdeq_q__io_deq_ready)) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__io_deq_valid_0)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq;
        }
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_15_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_15_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_15_T_2)) 
                     - ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_14_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_14_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_14_T_2)) 
                     - ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_5_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_5_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_5_T_2)) 
                     - ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_0_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_0_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_0_T_2)) 
                     - ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_3_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_3_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_3_T_2)) 
                     - ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_2_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_2_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_2_T_2)) 
                     - ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_1_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_1_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_1_T_2)) 
                     - ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_4_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_4_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_4_T_2)) 
                     - ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_6_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_6_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_6_T_2)) 
                     - ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_7_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_7_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_7_T_2)) 
                     - ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_8_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_8_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_8_T_2)) 
                     - ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_9_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_9_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_9_T_2)) 
                     - ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_10_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_10_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_10_T_2)) 
                     - ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_11_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_11_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_11_T_2)) 
                     - ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_12_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_12_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_12_T_2)) 
                     - ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_13_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__arFIFOMap_13_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___arFIFOMap_13_T_2)) 
                     - ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_auto_anon_in_rid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT____VdfgRegularize_h3f4aebb8_12_2))));
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap 
                = (1U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap) 
                         - (IData)(1U)));
        }
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_15_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_15_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_2)) 
                     - ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_14_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_14_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_14_T_2)) 
                     - ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_2_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_2_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_2_T_2)) 
                     - ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_5_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_5_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_5_T_2)) 
                     - ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_4_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_4_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_4_T_2)) 
                     - ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_3_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_3_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_3_T_2)) 
                     - ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_1_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_1_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_1_T_2)) 
                     - ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_0_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_0_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_0_T_2)) 
                     - ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_6_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_6_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_6_T_2)) 
                     - ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_7_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_7_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_7_T_2)) 
                     - ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_8_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_8_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_8_T_2)) 
                     - ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_9_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_9_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_9_T_2)) 
                     - ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_10_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_10_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_10_T_2)) 
                     - ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_11_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_11_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_11_T_2)) 
                     - ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_12_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_12_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_12_T_2)) 
                     - ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_13_count 
            = (7U & (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awFIFOMap_13_count) 
                      + (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_13_T_2)) 
                     - ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bid)) 
                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awFIFOMap_15_T_4))));
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1 
                = (1U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1) 
                         - (IData)(1U)));
        }
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__do_enq) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap 
                = (1U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap) 
                         - (IData)(1U)));
        }
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__unnamedblk1__DOT___GEN 
            = (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state) 
                << 6U) | ((0x20U & ((~ (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready) 
                                         & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid)) 
                                        | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready) 
                                           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid)))) 
                                    << 5U)) | ((((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready)
                                                  ? 
                                                 (2U 
                                                  & ((~ 
                                                      (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_rready) 
                                                        & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid)) 
                                                       | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_bready) 
                                                          & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid)))) 
                                                     << 1U))
                                                  : 1U) 
                                                << 2U) 
                                               | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_arvalid) 
                                                  | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_awvalid) 
                                                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4xbar_1_auto_anon_out_0_wvalid))))));
        vlSelfRef.__Vdly__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state 
            = (3U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__unnamedblk1__DOT___GEN) 
                     >> (7U & VL_SHIFTL_III(3,32,32, (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state), 1U))));
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__do_deq) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1 
                = (1U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1) 
                         - (IData)(1U)));
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full) 
                  & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q__io_deq_ready)) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__io_deq_valid_0)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full) 
                  & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT____Vcellinp__deq_q_1__io_deq_ready)) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__io_deq_valid_0)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq;
        }
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3 
            = (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bready) 
                & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_bvalid)) 
               | ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__anyValid_1)) 
                  & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3)));
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3) 
             & (0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_valid_1)))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__unnamedblk2__DOT___readys_mask_T_5 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_readys_1) 
                   & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_valid_1));
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_mask_1 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__unnamedblk2__DOT___readys_mask_T_5) 
                   | (2U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__unnamedblk2__DOT___readys_mask_T_5) 
                            << 1U)));
        }
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_3_0 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_3_0;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_3_1 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_3_1;
        }
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2 
            = (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_rready) 
                & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__in_0_rvalid)) 
               | ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__anyValid)) 
                  & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2)));
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2) 
             & (0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_valid)))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__unnamedblk1__DOT___readys_mask_T 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_readys) 
                   & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_valid));
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__readys_mask 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__unnamedblk1__DOT___readys_mask_T) 
                   | (2U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__unnamedblk1__DOT___readys_mask_T) 
                            << 1U)));
        }
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_2_0 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__prefixOR_1;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__state_2_1 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__winner_2_1;
        }
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4 
            = (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_bready) 
                & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_bvalid)) 
               | ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid_1)) 
                  & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4)));
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4) 
             & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full) 
                | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid)))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk2__DOT___readys_mask_T_8 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys_1) 
                   & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid_1));
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk2__DOT___readys_mask_T_11 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk2__DOT___readys_mask_T_8) 
                   | (6U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk2__DOT___readys_mask_T_8) 
                            << 1U)));
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask_1 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk2__DOT___readys_mask_T_11) 
                   | (4U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk2__DOT___readys_mask_T_11) 
                            << 2U)));
        }
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_0 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_0;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_4_2 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_4_2;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___arFIFOMap_15_T_4) 
                  & ((0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_rid)) 
                     & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_rlast))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq) 
             != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_deq))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (4U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (5U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (6U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (7U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (8U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (9U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (0xaU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (0xbU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (0xcU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (0xdU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (0xeU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq) 
             != (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___awFIFOMap_15_T_4) 
                  & (0xfU == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_in_bid))) 
                 & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full)))) {
            __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__unnamedblk1__DOT__do_enq;
        }
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__do_enq) 
             != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__do_deq))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__maybe_full 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__do_enq;
        }
        if (ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_0) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy 
                = (0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len));
        }
        if (ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_1) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1 
                = (0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1));
        }
        __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3 
            = (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4frag_auto_out_rready) 
                & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__in_0_rvalid)) 
               | ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__anyValid)) 
                  & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3)));
        if (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3) 
             & (0U != (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid)))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk1__DOT___readys_mask_T 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_readys) 
                   & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_valid));
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk1__DOT___readys_mask_T_3 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk1__DOT___readys_mask_T) 
                   | (6U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk1__DOT___readys_mask_T) 
                            << 1U)));
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__readys_mask 
                = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk1__DOT___readys_mask_T_3) 
                   | (4U & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__unnamedblk1__DOT___readys_mask_T_3) 
                            << 2U)));
        }
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_0 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__prefixOR_1;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_1 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_1;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__state_3_2 
                = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__winner_3_2;
        }
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter 
            = (0x1ffU & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_todo) 
                         - ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT___axi4yank_auto_in_wready) 
                            & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__nodeOut_wvalid))));
    }
    if (ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT___GEN_1) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___inc_addr_T_3 
            = (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__addr_1 
               + (0xffffU & ((IData)(1U) << (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size))));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___wrapMask_T_3 
            = (0x7fffffU & ((0xffU | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len) 
                                      << 8U)) << (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_size)));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___mux_addr_T_6 
            = (~ vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr);
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1 
            = (0xffU & ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1) 
                        - (IData)(1U)));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_addr_1 
            = ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst))
                ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_addr
                : ((2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst))
                    ? ((0x7fffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___inc_addr_T_3 
                                   & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___wrapMask_T_3 
                                      >> 8U))) | (~ 
                                                  ((0xffff8000U 
                                                    & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___mux_addr_T_6) 
                                                   | (0x7fffU 
                                                      & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___mux_addr_T_6 
                                                         | (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___wrapMask_T_3 
                                                            >> 8U))))))
                    : vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__unnamedblk1__DOT__unnamedblk4__DOT___inc_addr_T_3));
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram 
            = (((QData)((IData)((0x800U | (((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_arsize) 
                                            << 8U) 
                                           | ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__use_lsu_addr)
                                               ? 0U
                                               : 3U))))) 
                << 0x24U) | (((QData)((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_araddr)) 
                              << 4U) | (QData)((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_arid))));
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram 
            = (0x800000000000ULL | (((QData)((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__saved_awsize)) 
                                     << 0x2cU) | (((QData)((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__saved_addr)) 
                                                   << 4U) 
                                                  | (QData)((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__curr_id)))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__idu_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_ready;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu__DOT__exu_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__branch_inst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__jump_inst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__other_inst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__compute_inst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__load_inst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__csr_inst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__store_inst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rd_ready;
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram__v0;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_0;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_1;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_2;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_3;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_4;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_5;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_6;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_7;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_8;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_9;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_10;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_11;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_12;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_13;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_14;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__error_15;
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram__v0;
    }
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__do_enq) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__ram 
            = (0x1000000000ULL | (((QData)((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_wstrb)) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_wdata))));
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__in_wdeq_q__DOT__full;
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0] 
            = ((0xffffff00U & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory
                [__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0]) 
               | (IData)(__VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v0));
    }
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1] 
            = ((0xffff00ffU & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory
                [__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1]) 
               | ((IData)(__VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v1) 
                  << 8U));
    }
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2] 
            = ((0xff00ffffU & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory
                [__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2]) 
               | ((IData)(__VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v2) 
                  << 0x10U));
    }
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3] 
            = ((0xffffffU & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory
                [__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3]) 
               | ((IData)(__VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory__v3) 
                  << 0x18U));
    }
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap;
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__ifu_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full;
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__regfile__DOT__rf__v0;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_3;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__idle_2;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_4;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__w_full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_1__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_2__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_3__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_4__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_5__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_6__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_7__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_8__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_9__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_10__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_11__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_12__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_13__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_14__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_15__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__mtime;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_16__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_17__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_18__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_19__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_20__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_21__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_22__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_23__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_24__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_25__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_26__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_27__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_28__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_29__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_30__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4yank__DOT__Queue1_BundleMap_31__DOT__full;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state 
        = ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset))) 
           && (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__next_state));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap) 
           == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__wrap_1));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ptr_match 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap) 
           == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__wrap_1));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2;
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r0 
            = (0xffU & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data);
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r1 
            = (0xffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data 
                        >> 8U));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r2 
            = (0xffU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data 
                        >> 0x10U));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_r3 
            = (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data 
               >> 0x18U);
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__ren;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT___mem_ext_R0_data 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__rdata_REG)
            ? vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory
           [vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT___R0_addr_d0]
            : 0U);
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT____VdfgRegularize_hc31b045e_0_1 
        = ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__current_state)) 
           | (1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__current_state)));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT____VdfgRegularize_hc31b045e_0_2 
        = ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__current_state)) 
           | (2U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter__DOT__current_state)));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_io_deq_bits_burst 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__full)
            ? (3U & (IData)((vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q__DOT__ram 
                             >> 0x2fU))) : 1U);
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__full) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst 
            = (3U & (IData)((vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram 
                             >> 0x2fU)));
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len 
            = (0xffU & (IData)((vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__deq_q_1__DOT__ram 
                                >> 0x24U)));
    } else {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_burst = 1U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len = 0U;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__idle_3;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match) 
           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__empty 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__maybe_full)) 
           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__ptr_match));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__empty 
        = ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__maybe_full)) 
           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ptr_match));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__full 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__ptr_match) 
           & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT__awIn_0__DOT__maybe_full));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__hit_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__miss_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__burst_count;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[0U] 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[0U];
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[1U] 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[1U];
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[2U] 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[2U];
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[3U] 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__temp_cache_data[3U];
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v0) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[1U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[1U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[1U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[1U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[2U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[2U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[2U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[2U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[3U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[3U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[3U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[3U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[4U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[4U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[4U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[4U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[5U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[5U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[5U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[5U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[6U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[6U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[6U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[6U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[7U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[7U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[7U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[7U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[8U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[8U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[8U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[8U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[9U][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[9U][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[9U][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[9U][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xaU][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xaU][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xaU][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xaU][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xbU][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xbU][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xbU][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xbU][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xcU][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xcU][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xcU][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xcU][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xdU][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xdU][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xdU][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xdU][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xeU][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xeU][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xeU][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xeU][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xfU][0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xfU][1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xfU][2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[0xfU][3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[4U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[5U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[6U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[7U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[8U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[9U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[0xaU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[0xbU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[0xcU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[0xdU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[0xeU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[0xfU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[0U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[1U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[2U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[3U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[4U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[5U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[6U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[7U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[8U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[9U] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[0xaU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[0xbU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[0xcU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[0xdU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[0xeU] = 0U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[0xfU] = 0U;
    }
    if (__VdlySet__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16][0U] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[0U];
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16][1U] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[1U];
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16][2U] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[2U];
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16][3U] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_data__v16[3U];
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid__v16] = 1U;
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags[__VdlyDim0__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16] 
            = __VdlyVal__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags__v16;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id 
        = __Vdly__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__curr_id;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__len_1 
        = ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__busy_1)
            ? (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__r_len_1)
            : (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___deq_q_1_io_deq_bits_len));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_ifu_ready = 0U;
    if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state)))) {
        vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_ifu_ready = 1U;
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_exu_valid = 0U;
    if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) {
        if (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu__DOT__state) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_exu_valid = 1U;
        }
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT___anonIn_awready_T 
        = (1U & ((~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__awIn_0__DOT__full)) 
                 | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar_1__DOT__latched)));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT___in_awready_T 
        = ((0U == (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__w_counter)) 
           | (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4frag__DOT__wbeats_latched));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__state 
        = ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset))) 
           && (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__clint_inst__DOT__next_state));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__req_tag 
        = (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc 
           >> 8U);
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__req_index 
        = (0xfU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc 
                   >> 4U));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_hit 
        = (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_valid
           [(0xfU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc 
                     >> 4U))] & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__cache_tags
                                 [(0xfU & (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc 
                                           >> 4U))] 
                                 == (vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc 
                                     >> 8U)));
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_rready = 0U;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_arvalid = 0U;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_araddr 
        = (0xfffffff0U & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc);
    if ((2U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_rready = 1U;
        }
        if ((1U & (~ (IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__state)))) {
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_arvalid = 1U;
            vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_araddr 
                = (0xfffffff0U & vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu__DOT__saved_pc);
        }
    }
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9;
    vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9 
        = vlSelfRef.reset;
}

void VysyxSoCFull___024unit____Vdpiimwrap_flash_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &data);

VL_INLINE_OPT void VysyxSoCFull___024root___nba_sequent__TOP__7(VysyxSoCFull___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root___nba_sequent__TOP__7\n"); );
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vtask_flash_read__5__data;
    __Vtask_flash_read__5__data = 0;
    // Body
    if (((1U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__state)) 
         & (0x17U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__counter)))) {
        if (VL_LIKELY(((3U == (IData)(vlSelfRef.ysyxSoCFull__DOT__flash__DOT__cmd))))) {
            VysyxSoCFull___024unit____Vdpiimwrap_flash_read_TOP____024unit(
                                                                           ((0xfffffeU 
                                                                             & (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__addr 
                                                                                << 1U)) 
                                                                            | (IData)(vlSelfRef.ysyxSoCFull__DOT___asic_spi_mosi)), __Vtask_flash_read__5__data);
            vlSelfRef.ysyxSoCFull__DOT__flash__DOT__rdata 
                = __Vtask_flash_read__5__data;
        } else {
            VL_FWRITEF_NX(0x80000002U,"Assertion failed: Unsupport command `%xh`, only support `03h` read command\n",0,
                          8,vlSelfRef.ysyxSoCFull__DOT__flash__DOT__cmd);
            if (0x80000002U) { VL_FFLUSH_I(0x80000002U); }
            VL_WRITEF_NX("[%0t] %%Fatal: flash.v:98: Assertion failed in %NysyxSoCFull.flash.flash_cmd_i\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            Verilated::runFlushCallbacks();
            VL_STOP_MT("../ysyxSoC/perip/flash/flash.v", 98, "", false);
        }
    }
    vlSelfRef.ysyxSoCFull__DOT__flash__DOT__data_bswap 
        = (((vlSelfRef.ysyxSoCFull__DOT__flash__DOT__rdata 
             << 0x18U) | (0xff0000U & (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__rdata 
                                       << 8U))) | (
                                                   (0xff00U 
                                                    & (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__rdata 
                                                       >> 8U)) 
                                                   | (vlSelfRef.ysyxSoCFull__DOT__flash__DOT__rdata 
                                                      >> 0x18U)));
}
