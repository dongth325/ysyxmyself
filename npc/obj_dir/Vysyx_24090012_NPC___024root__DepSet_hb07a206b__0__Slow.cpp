// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC___024root.h"

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_static(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_initial__TOP(Vysyx_24090012_NPC___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_initial(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vysyx_24090012_NPC___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_initial__TOP(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr = 0U;
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_final(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__stl(Vysyx_24090012_NPC___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vysyx_24090012_NPC___024root___eval_phase__stl(Vysyx_24090012_NPC___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_settle(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vysyx_24090012_NPC___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/NPC.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vysyx_24090012_NPC___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__stl(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___stl_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_stl(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___stl_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        vlSelfRef.__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___stl_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ysyx_24090012_NPC__DOT__sram_ready = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__opcode = (0x7fU 
                                                & vlSelfRef.ysyx_24090012_NPC__DOT__inst);
    vlSelfRef.ysyx_24090012_NPC__DOT__func3 = (7U & 
                                               (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                >> 0xcU));
    vlSelfRef.ysyx_24090012_NPC__DOT__func7 = (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                               >> 0x19U);
    vlSelfRef.ysyx_24090012_NPC__DOT__rs1 = (0x1fU 
                                             & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                >> 0xfU));
    vlSelfRef.ysyx_24090012_NPC__DOT__rs2 = (0x1fU 
                                             & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                >> 0x14U));
    vlSelfRef.ysyx_24090012_NPC__DOT__is_ecall = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__is_mret = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 0U;
    if ((0x40U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
        if ((0x20U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__is_ecall = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__is_mret = 0U;
                        if ((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))) {
                            if ((1U == (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                        >> 0x14U))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xbU;
                            } else if ((0U == (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                               >> 0x14U))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0x32U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__is_ecall = 1U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__rs1 = 0x11U;
                            } else if ((0x302U == (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                   >> 0x14U))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0x33U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__is_mret = 1U;
                            }
                        } else if ((1U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0x30U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr 
                                = (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                   >> 0x14U);
                            vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 1U;
                        } else if ((2U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0x31U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr 
                                = (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                   >> 0x14U);
                            vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 1U;
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                }
            } else if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__imm 
                                = (((- (IData)((vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                >> 0x1fU))) 
                                    << 0x14U) | ((0xff000U 
                                                  & vlSelfRef.ysyx_24090012_NPC__DOT__inst) 
                                                 | ((0x800U 
                                                     & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                          >> 0x14U)))));
                            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 3U;
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                }
            } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__imm 
                            = (((- (IData)((vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                            >> 0x14U));
                        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 4U;
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                }
            } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm 
                        = (((- (IData)((vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                        >> 0x1fU))) 
                            << 0xdU) | ((0x1000U & 
                                         (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                          >> 0x13U)) 
                                        | ((0x800U 
                                            & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                               << 4U)) 
                                           | ((0x7e0U 
                                               & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                    >> 7U))))));
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op 
                        = ((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                            ? 6U : ((1U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                     ? 7U : ((5U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                              ? 0x15U
                                              : ((7U 
                                                  == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                                  ? 0x1aU
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                                   ? 0x1bU
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                                    ? 0x1eU
                                                    : 0xfU))))));
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                }
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
            }
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        }
    } else if ((0x20U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
        if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
            } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__imm 
                            = (0xfffff000U & vlSelfRef.ysyx_24090012_NPC__DOT__inst);
                        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 1U;
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                }
            } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op 
                        = (((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                            & (0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                            ? 5U : (((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                     & (0x20U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                     ? 0xcU : (((1U 
                                                 == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                & (0U 
                                                   == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                ? 0xdU
                                                : (
                                                   ((7U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                    & (0U 
                                                       == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                    ? 0x10U
                                                    : 
                                                   (((3U 
                                                      == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                     & (0U 
                                                        == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rs2))
                                                      ? 0x12U
                                                      : 0x1cU)
                                                     : 
                                                    (((6U 
                                                       == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                      & (0U 
                                                         == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                      ? 0x14U
                                                      : 
                                                     (((4U 
                                                        == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                       & (0U 
                                                          == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                       ? 0x17U
                                                       : 
                                                      (((2U 
                                                         == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                        & (0U 
                                                           == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                        ? 0x1dU
                                                        : 
                                                       (((5U 
                                                          == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                         & (0x20U 
                                                            == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                         ? 0x21U
                                                         : 
                                                        (((5U 
                                                           == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                          & (0U 
                                                             == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                          ? 0x22U
                                                          : 0xfU))))))))));
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                }
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
            }
        } else if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm 
                    = (((- (IData)((vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                      >> 7U))));
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op 
                    = ((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                        ? 0x23U : ((1U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                    ? 0x34U : ((2U 
                                                == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                                ? 9U
                                                : 0xfU)));
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
            }
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        }
    } else if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
        if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm 
                        = (0xfffff000U & vlSelfRef.ysyx_24090012_NPC__DOT__inst);
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 2U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
                }
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
            }
        } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm 
                    = (((- (IData)((vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                          >> 0x14U));
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op 
                    = ((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                        ? 0U : ((6U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                 ? 0x25U : ((2U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                             ? 0x26U
                                             : ((3U 
                                                 == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                                 ? 0xaU
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                                  ? 0xeU
                                                  : 
                                                 (((7U 
                                                    == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                   & (0xffU 
                                                      == 
                                                      (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                                                       >> 0x14U)))
                                                   ? 0xfU
                                                   : 
                                                  (((5U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                    & (0x20U 
                                                       == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                    ? 0x11U
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                                     ? 0x13U
                                                     : 
                                                    (((5U 
                                                       == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                      & (0U 
                                                         == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                      ? 0x16U
                                                      : 
                                                     (((1U 
                                                        == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3)) 
                                                       & (0U 
                                                          == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func7)))
                                                       ? 0x19U
                                                       : 0xfU))))))))));
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
            }
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        }
    } else if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
    } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
    } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 
                (((- (IData)((vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                              >> 0x1fU))) << 0xcU) 
                 | (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                    >> 0x14U));
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op 
                = ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                    ? ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                        ? 0xfU : ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                   ? 0x20U : 0x18U))
                    : ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                        ? ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                            ? 0xfU : 8U) : ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                             ? 0x1fU
                                             : 0x24U)));
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen2 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen1 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen3 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2 = 0U;
    if (vlSelfRef.ysyx_24090012_NPC__DOT__is_ecall) {
        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen2 = 1U;
        vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2 = 0x341U;
        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen1 = 1U;
        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1 = 0x11U;
        vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1 = 0x342U;
        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2 
            = vlSelfRef.pc;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new = vlSelfRef.ysyx_24090012_NPC__DOT__mstatus;
    if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__is_ecall)))) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__is_mret) {
            vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen3 = 1U;
            vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3 = 0x300U;
            vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new 
                = ((0U != (0x80U & vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new))
                    ? (8U | vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new)
                    : (0xfffffff7U & vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new));
            vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new 
                = (0x80U | vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new);
            vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new 
                = (0xffffe7ffU & vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new);
            vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3 
                = vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new;
        }
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data = ((0U 
                                                   == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rs1))
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                  [vlSelfRef.ysyx_24090012_NPC__DOT__rs1]);
    vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data = ((0U 
                                                   == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rs2))
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                  [vlSelfRef.ysyx_24090012_NPC__DOT__rs2]);
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata = (
                                                   (0x300U 
                                                    == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))
                                                    ? vlSelfRef.ysyx_24090012_NPC__DOT__mstatus
                                                    : 
                                                   ((0x305U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))
                                                     ? vlSelfRef.ysyx_24090012_NPC__DOT__mtvec
                                                     : 
                                                    ((0x341U 
                                                      == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))
                                                      ? vlSelfRef.ysyx_24090012_NPC__DOT__mepc
                                                      : 
                                                     ((0x342U 
                                                       == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))
                                                       ? vlSelfRef.ysyx_24090012_NPC__DOT__mcause
                                                       : 0U))));
    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state 
        = vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__state;
    vlSelfRef.ysyx_24090012_NPC__DOT__idu_ready = (1U 
                                                   & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__state)));
    vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wdata = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__result = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc = vlSelfRef.pc;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 0U;
    if (vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state) {
            vlSelfRef.ysyx_24090012_NPC__DOT__sram_ready = 1U;
        }
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__state) {
            if (vlSelfRef.ysyx_24090012_NPC__DOT__sram_ready) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready = 1U;
            }
        }
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__state) {
            if ((0x20U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if (VL_UNLIKELY((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                        VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                    } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        if (VL_UNLIKELY((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                            VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        } else if (VL_UNLIKELY((1U 
                                                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                            VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                            if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                                    = ((IData)(4U) 
                                       + vlSelfRef.pc);
                                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                                if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    }
                } else if (VL_UNLIKELY((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                    VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        if (VL_UNLIKELY((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                            VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                                 & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                            }
                        }
                    } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                        if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                                = (((- (IData)((1U 
                                                & (vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata 
                                                   >> 7U)))) 
                                    << 8U) | (0xffU 
                                              & vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata));
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                                = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                                = ((IData)(4U) + vlSelfRef.pc);
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                                 & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if (VL_LIKELY((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                        if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                                = ((IData)(4U) + vlSelfRef.pc);
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            }
                        }
                    } else {
                        VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                    }
                } else if (VL_UNLIKELY((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                    VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                    if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = (0xffffU & vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                            if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                                if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                                        = (((- (IData)(
                                                       (1U 
                                                        & (vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata 
                                                           >> 0xfU)))) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata));
                                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                                        = ((IData)(4U) 
                                           + vlSelfRef.pc);
                                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                                    if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                                         & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                    }
                                }
                            } else {
                                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                                if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                                }
                            }
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                                 & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                            }
                        }
                    } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                        if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                                = (0xffU & vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata);
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                                = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                                = ((IData)(4U) + vlSelfRef.pc);
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                                 & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    }
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                         & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                    }
                }
            } else if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        if (VL_UNLIKELY((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                            VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                                 & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                            }
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                        }
                    }
                } else if (VL_UNLIKELY((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                    VL_WRITEF_NX("222default:didnt match any inst from (exu.v)\n",0);
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                    if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        }
                    }
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                    if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    if (vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                    }
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                         & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                    }
                }
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                     & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                }
            }
        }
    } else if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_ready))) {
        if ((0x20U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if (VL_UNLIKELY((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                    VL_WRITEF_NX("111default:didnt match any inst from (exu.v)\n",0);
                } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if (VL_UNLIKELY((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                        VL_WRITEF_NX("111default:didnt match any inst from (exu.v)\n",0);
                    } else if (VL_UNLIKELY((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                        VL_WRITEF_NX("111default:didnt match any inst from (exu.v)\n",0);
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                            = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                               + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_wdata 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data;
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 2U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    }
                } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))
                            ? vlSelfRef.ysyx_24090012_NPC__DOT__mepc
                            : vlSelfRef.ysyx_24090012_NPC__DOT__mtvec);
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata 
                           | vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data);
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if (VL_UNLIKELY((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                VL_WRITEF_NX("111default:didnt match any inst from (exu.v)\n",0);
            } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if (VL_UNLIKELY((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                        VL_WRITEF_NX("111default:didnt match any inst from (exu.v)\n",0);
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = (VL_LTS_III(32, vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data, vlSelfRef.ysyx_24090012_NPC__DOT__imm)
                                ? 1U : 0U);
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    }
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           | vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wdata 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data;
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           >> (0x1fU & vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data));
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data, 
                                     (0x1fU & vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data));
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = ((IData)(4U) + vlSelfRef.pc);
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                    = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                       + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            }
        } else if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                                = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                   + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                            vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                                = (VL_LTS_III(32, vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data, vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                                    ? (vlSelfRef.pc 
                                       + vlSelfRef.ysyx_24090012_NPC__DOT__imm)
                                    : ((IData)(4U) 
                                       + vlSelfRef.pc));
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = (VL_LTS_III(32, vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data, vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                                ? 1U : 0U);
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                < vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                                ? 1U : 0U);
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    }
                } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                < vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                                ? (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm)
                                : ((IData)(4U) + vlSelfRef.pc));
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                >= vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                                ? (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm)
                                : ((IData)(4U) + vlSelfRef.pc));
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    }
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           << (0x1fU & vlSelfRef.ysyx_24090012_NPC__DOT__imm));
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                               ^ vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                               >> (0x1fU & vlSelfRef.ysyx_24090012_NPC__DOT__imm));
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    }
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = (VL_GTES_III(32, vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data, vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                            ? (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm)
                            : ((IData)(4U) + vlSelfRef.pc));
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           | vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           & vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = ((0U != vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                            ? 1U : 0U);
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data, 
                                     (0x1fU & vlSelfRef.ysyx_24090012_NPC__DOT__imm));
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = ((IData)(4U) + vlSelfRef.pc);
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                       & vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = ((IData)(4U) + vlSelfRef.pc);
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            }
        } else if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = (0xffU & vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data);
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__result 
                            = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                               ^ vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = ((IData)(4U) + vlSelfRef.pc);
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    }
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           << (0x1fU & vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data));
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           - vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = ((0U == vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data)
                            ? 1U : 0U);
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                    = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                       + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_wdata 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data;
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 4U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr 
                    = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                       + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            }
        } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                            != vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                            ? (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm)
                            : ((IData)(4U) + vlSelfRef.pc));
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result = 0U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                            == vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)
                            ? (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm)
                            : ((IData)(4U) + vlSelfRef.pc));
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                       + vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = ((IData)(4U) + vlSelfRef.pc);
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = ((IData)(4U) + vlSelfRef.pc);
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = (0xfffffffeU & (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                      + vlSelfRef.ysyx_24090012_NPC__DOT__imm));
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = ((IData)(4U) + vlSelfRef.pc);
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            } else {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = ((IData)(4U) + vlSelfRef.pc);
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = vlSelfRef.ysyx_24090012_NPC__DOT__imm;
            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                = ((IData)(4U) + vlSelfRef.pc);
            vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                = vlSelfRef.ysyx_24090012_NPC__DOT__result;
            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                   + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                = ((IData)(4U) + vlSelfRef.pc);
            vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                = vlSelfRef.ysyx_24090012_NPC__DOT__result;
            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
        }
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__state) {
        vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__next_state = 1U;
        vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid = 0U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__state) {
            vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid = 1U;
            if (vlSelfRef.ysyx_24090012_NPC__DOT__sram_ready) {
                vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__next_state = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid = 0U;
            }
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__next_state = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid = 0U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_valid) {
            vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__next_state = 1U;
            vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid = 1U;
        }
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state) {
        vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__next_state = 1U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state) {
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid)))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__next_state = 0U;
            }
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__next_state = 0U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid) {
            vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__next_state = 1U;
        }
    }
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___eval_triggers__stl(Vysyx_24090012_NPC___024root* vlSelf);

VL_ATTR_COLD bool Vysyx_24090012_NPC___024root___eval_phase__stl(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vysyx_24090012_NPC___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vysyx_24090012_NPC___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__act(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__nba(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24090012_NPC___024root___ctor_var_reset(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->mem_data = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->ebreak_flag = VL_RAND_RESET_I(1);
    vlSelf->exit_code = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_24090012_NPC__DOT__rs2 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_24090012_NPC__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->ysyx_24090012_NPC__DOT__func3 = VL_RAND_RESET_I(3);
    vlSelf->ysyx_24090012_NPC__DOT__func7 = VL_RAND_RESET_I(7);
    vlSelf->ysyx_24090012_NPC__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__alu_op = VL_RAND_RESET_I(6);
    vlSelf->ysyx_24090012_NPC__DOT__rs1_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__sram_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__sram_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__sram_rdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__idu_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__idu_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__pc_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__pc_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__mem_addr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__mem_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__mem_wmask = VL_RAND_RESET_I(4);
    vlSelf->ysyx_24090012_NPC__DOT__mem_wen = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__mem_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__rd_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__rd_valid = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__rd_ready = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__csr_addr3 = VL_RAND_RESET_I(12);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wdata3 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wen3 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__csr_addr1 = VL_RAND_RESET_I(12);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wdata1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wen1 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__csr_addr2 = VL_RAND_RESET_I(12);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wdata2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wen2 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__csr_addr = VL_RAND_RESET_I(12);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__csr_wen = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__mstatus_new = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__is_ecall = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__is_mret = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__csr_rdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__mstatus = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__mepc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24090012_NPC__DOT__mcause = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_24090012_NPC__DOT__regfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_24090012_NPC__DOT__exu__DOT__state = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__exu__DOT__next_state = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__lsu__DOT__state = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__lsu__DOT__next_state = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__sram__DOT__state = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24090012_NPC__DOT__sram__DOT__next_state = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
