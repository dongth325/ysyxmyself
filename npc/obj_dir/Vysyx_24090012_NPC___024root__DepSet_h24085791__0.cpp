// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC__Syms.h"
#include "Vysyx_24090012_NPC___024root.h"

extern "C" void ebreak(int exit_code);

VL_INLINE_OPT void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ebreak_TOP(IData/*31:0*/ exit_code) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ebreak_TOP\n"); );
    // Body
    int exit_code__Vcvt;
    for (size_t exit_code__Vidx = 0; exit_code__Vidx < 1; ++exit_code__Vidx) exit_code__Vcvt = exit_code;
    ebreak(exit_code__Vcvt);
}

extern "C" int pmem_read(int raddr);

VL_INLINE_OPT void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, int wmask);

VL_INLINE_OPT void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, IData/*31:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    int wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

void Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__regfile__DOT__get_reg_value_TOP(Vysyx_24090012_NPC__Syms* __restrict vlSymsp, IData/*31:0*/ reg_index, IData/*31:0*/ &get_reg_value__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__regfile__DOT__get_reg_value_TOP\n"); );
    // Init
    // Body
    get_reg_value__Vfuncrtn = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [(0x1fU & reg_index)];
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_write_TOP(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ mask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_write_TOP\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int data__Vcvt;
    for (size_t data__Vidx = 0; data__Vidx < 1; ++data__Vidx) data__Vcvt = data;
    int mask__Vcvt;
    for (size_t mask__Vidx = 0; mask__Vidx < 1; ++mask__Vidx) mask__Vcvt = mask;
    pmem_write(addr__Vcvt, data__Vcvt, mask__Vcvt);
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read_TOP\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(addr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

void Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__csr__DOT__get_csr_reg_value_TOP(Vysyx_24090012_NPC__Syms* __restrict vlSymsp, IData/*31:0*/ csr_reg_index, IData/*31:0*/ &get_csr_reg_value__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__csr__DOT__get_csr_reg_value_TOP\n"); );
    // Init
    // Body
    if ((1U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyx_24090012_NPC__DOT__mcause;
    } else if ((2U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyx_24090012_NPC__DOT__mtvec;
    } else if ((3U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyx_24090012_NPC__DOT__mepc;
    } else if ((4U == csr_reg_index)) {
        get_csr_reg_value__Vfuncrtn = vlSymsp->TOP.ysyx_24090012_NPC__DOT__mstatus;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__ico(Vysyx_24090012_NPC___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24090012_NPC___024root___eval_triggers__ico(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24090012_NPC___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__act(Vysyx_24090012_NPC___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24090012_NPC___024root___eval_triggers__act(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, (((IData)(vlSelfRef.clk) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))) 
                                       | ((IData)(vlSelfRef.rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24090012_NPC___024root___dump_triggers__act(vlSelf);
    }
#endif
}
