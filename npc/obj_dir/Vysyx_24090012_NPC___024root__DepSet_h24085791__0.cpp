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

void Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__regfile__DOT__get_rf_TOP(Vysyx_24090012_NPC__Syms* __restrict vlSymsp, VlUnpacked<IData/*31:0*/, 32> &regs) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root____Vdpiexp_ysyx_24090012_NPC__DOT__regfile__DOT__get_rf_TOP\n"); );
    // Init
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    regs[0U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0U];
    regs[1U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [1U];
    regs[2U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [2U];
    regs[3U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [3U];
    regs[4U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [4U];
    regs[5U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [5U];
    regs[6U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [6U];
    regs[7U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [7U];
    regs[8U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [8U];
    regs[9U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [9U];
    regs[0xaU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0xaU];
    regs[0xbU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0xbU];
    regs[0xcU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0xcU];
    regs[0xdU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0xdU];
    regs[0xeU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0xeU];
    regs[0xfU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0xfU];
    regs[0x10U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x10U];
    regs[0x11U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x11U];
    regs[0x12U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x12U];
    regs[0x13U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x13U];
    regs[0x14U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x14U];
    regs[0x15U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x15U];
    regs[0x16U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x16U];
    regs[0x17U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x17U];
    regs[0x18U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x18U];
    regs[0x19U] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x19U];
    regs[0x1aU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x1aU];
    regs[0x1bU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x1bU];
    regs[0x1cU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x1cU];
    regs[0x1dU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x1dU];
    regs[0x1eU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x1eU];
    regs[0x1fU] = vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__rf
        [0x1fU];
    vlSymsp->TOP.ysyx_24090012_NPC__DOT__regfile__DOT__get_rf__Vstatic__i = 0x20U;
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
    vlSelfRef.__VicoTriggered.set(1U, (IData)(vlSelfRef.__Vdpi_export_trigger));
    vlSelfRef.__Vdpi_export_trigger = 0U;
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
    vlSelfRef.__VactTriggered.set(0U, (IData)(vlSelfRef.__Vdpi_export_trigger));
    vlSelfRef.__Vdpi_export_trigger = 0U;
    vlSelfRef.__VactTriggered.set(1U, (((IData)(vlSelfRef.clk) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))) 
                                       | ((IData)(vlSelfRef.rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0)))));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24090012_NPC___024root___dump_triggers__act(vlSelf);
    }
#endif
}
