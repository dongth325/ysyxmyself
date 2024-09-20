// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNPC.h for the primary calling header

#include "VNPC__pch.h"
#include "VNPC__Syms.h"
#include "VNPC___024root.h"

extern "C" void ebreak();

VL_INLINE_OPT void VNPC___024root____Vdpiimwrap_NPC__DOT__ebreak_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNPC___024root____Vdpiimwrap_NPC__DOT__ebreak_TOP\n"); );
    // Body
    ebreak();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VNPC___024root___dump_triggers__act(VNPC___024root* vlSelf);
#endif  // VL_DEBUG

void VNPC___024root___eval_triggers__act(VNPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VNPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNPC___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, (((IData)(vlSelfRef.clk) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))) 
                                       | ((IData)(vlSelfRef.rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VNPC___024root___dump_triggers__act(vlSelf);
    }
#endif
}
