// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VysyxSoCFull.h for the primary calling header

#include "VysyxSoCFull__pch.h"
#include "VysyxSoCFull__Syms.h"
#include "VysyxSoCFull___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VysyxSoCFull___024root___dump_triggers__stl(VysyxSoCFull___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VysyxSoCFull___024root___eval_triggers__stl(VysyxSoCFull___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root___eval_triggers__stl\n"); );
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.setBit(1U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_arready) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_arready__0)));
    vlSelfRef.__VstlTriggered.setBit(2U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_valid) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_valid__0)));
    vlSelfRef.__VstlTriggered.setBit(3U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awIn_0_io_deq_valid) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awIn_0_io_deq_valid__0)));
    vlSelfRef.__VstlTriggered.setBit(4U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_exu_valid) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_exu_valid__0)));
    vlSelfRef.__VstlTriggered.setBit(5U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lsdram_axi__DOT__msdram__DOT__u_sdram_axi__DOT__u_axi__DOT__write_active_w) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__lsdram_axi__DOT__msdram__DOT__u_sdram_axi__DOT__u_axi__DOT__write_active_w__0)));
    vlSelfRef.__VstlTriggered.setBit(6U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid__0)));
    vlSelfRef.__VstlTriggered.setBit(7U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write__0)));
    vlSelfRef.__VstlTriggered.setBit(8U, ((IData)(vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT____VdfgRegularize_h456d727f_0_0) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT____VdfgRegularize_h456d727f_0_0__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_arready__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__arbiter_arready;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_valid__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_valid;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awIn_0_io_deq_valid__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi4xbar__DOT___awIn_0_io_deq_valid;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_exu_valid__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__idu_to_exu_valid;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__lsdram_axi__DOT__msdram__DOT__u_sdram_axi__DOT__u_axi__DOT__write_active_w__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__lsdram_axi__DOT__msdram__DOT__u_sdram_axi__DOT__u_axi__DOT__write_active_w;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write;
    vlSelfRef.__Vtrigprevexpr___TOP__ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT____VdfgRegularize_h456d727f_0_0__0 
        = vlSelfRef.ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT____VdfgRegularize_h456d727f_0_0;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
        vlSelfRef.__VstlTriggered.setBit(2U, 1U);
        vlSelfRef.__VstlTriggered.setBit(3U, 1U);
        vlSelfRef.__VstlTriggered.setBit(4U, 1U);
        vlSelfRef.__VstlTriggered.setBit(5U, 1U);
        vlSelfRef.__VstlTriggered.setBit(6U, 1U);
        vlSelfRef.__VstlTriggered.setBit(7U, 1U);
        vlSelfRef.__VstlTriggered.setBit(8U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VysyxSoCFull___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
