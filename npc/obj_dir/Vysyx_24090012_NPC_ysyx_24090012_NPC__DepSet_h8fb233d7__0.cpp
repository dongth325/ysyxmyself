// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC__Syms.h"
#include "Vysyx_24090012_NPC_ysyx_24090012_NPC.h"

extern "C" void ebreak(int exit_code);

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_NPC____Vdpiimwrap_ebreak_TOP__ysyx_24090012_NPC(IData/*31:0*/ exit_code) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC____Vdpiimwrap_ebreak_TOP__ysyx_24090012_NPC\n"); );
    // Body
    int exit_code__Vcvt;
    for (size_t exit_code__Vidx = 0; exit_code__Vidx < 1; ++exit_code__Vidx) exit_code__Vcvt = exit_code;
    ebreak(exit_code__Vcvt);
}

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_NPC___ico_sequent__TOP__ysyx_24090012_NPC__0(Vysyx_24090012_NPC_ysyx_24090012_NPC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC___ico_sequent__TOP__ysyx_24090012_NPC__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.rst = vlSelfRef.rst;
    vlSelfRef.ifu__DOT__rst = vlSelfRef.rst;
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.clk = vlSelfRef.clk;
    vlSelfRef.ifu__DOT__clk = vlSelfRef.clk;
    vlSelfRef.ifu__DOT__mem_data = vlSelfRef.mem_data;
    vlSelfRef.inst = vlSelfRef.mem_data;
    vlSelfRef.ifu__DOT__inst = vlSelfRef.inst;
    vlSelfRef.idu__DOT__inst = vlSelfRef.inst;
    vlSelfRef.rd = (0x1fU & (vlSelfRef.inst >> 7U));
    vlSelfRef.rs1 = (0x1fU & (vlSelfRef.inst >> 0xfU));
    vlSelfRef.rs2 = (0x1fU & (vlSelfRef.inst >> 0x14U));
    vlSelfRef.opcode = (0x7fU & vlSelfRef.inst);
    vlSelfRef.func3 = (7U & (vlSelfRef.inst >> 0xcU));
    vlSelfRef.func7 = (vlSelfRef.inst >> 0x19U);
    if ((0x40U & (IData)(vlSelfRef.opcode))) {
        if ((0x20U & (IData)(vlSelfRef.opcode))) {
            if ((0x10U & (IData)(vlSelfRef.opcode))) {
                if ((8U & (IData)(vlSelfRef.opcode))) {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                } else if ((4U & (IData)(vlSelfRef.opcode))) {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                } else if ((2U & (IData)(vlSelfRef.opcode))) {
                    if ((1U & (IData)(vlSelfRef.opcode))) {
                        vlSelfRef.imm = 0U;
                        vlSelfRef.alu_op = 0xbU;
                    } else {
                        vlSelfRef.imm = 0U;
                        vlSelfRef.alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                }
            } else if ((8U & (IData)(vlSelfRef.opcode))) {
                if ((4U & (IData)(vlSelfRef.opcode))) {
                    if ((2U & (IData)(vlSelfRef.opcode))) {
                        if ((1U & (IData)(vlSelfRef.opcode))) {
                            vlSelfRef.imm = (((- (IData)(
                                                         (vlSelfRef.inst 
                                                          >> 0x1fU))) 
                                              << 0x14U) 
                                             | ((0xff000U 
                                                 & vlSelfRef.inst) 
                                                | ((0x800U 
                                                    & (vlSelfRef.inst 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSelfRef.inst 
                                                         >> 0x14U)))));
                            vlSelfRef.alu_op = 3U;
                        } else {
                            vlSelfRef.imm = 0U;
                            vlSelfRef.alu_op = 0xfU;
                        }
                    } else {
                        vlSelfRef.imm = 0U;
                        vlSelfRef.alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                }
            } else if ((4U & (IData)(vlSelfRef.opcode))) {
                if ((2U & (IData)(vlSelfRef.opcode))) {
                    if ((1U & (IData)(vlSelfRef.opcode))) {
                        vlSelfRef.imm = (((- (IData)(
                                                     (vlSelfRef.inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelfRef.inst 
                                            >> 0x14U));
                        vlSelfRef.alu_op = 4U;
                    } else {
                        vlSelfRef.imm = 0U;
                        vlSelfRef.alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                }
            } else if ((2U & (IData)(vlSelfRef.opcode))) {
                if ((1U & (IData)(vlSelfRef.opcode))) {
                    vlSelfRef.imm = (((- (IData)((vlSelfRef.inst 
                                                  >> 0x1fU))) 
                                      << 0xdU) | ((0x1000U 
                                                   & (vlSelfRef.inst 
                                                      >> 0x13U)) 
                                                  | ((0x800U 
                                                      & (vlSelfRef.inst 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlSelfRef.inst 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlSelfRef.inst 
                                                              >> 7U))))));
                    vlSelfRef.alu_op = ((0U == (IData)(vlSelfRef.func3))
                                         ? 6U : ((1U 
                                                  == (IData)(vlSelfRef.func3))
                                                  ? 7U
                                                  : 0xfU));
                } else {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                }
            } else {
                vlSelfRef.imm = 0U;
                vlSelfRef.alu_op = 0xfU;
            }
        } else {
            vlSelfRef.imm = 0U;
            vlSelfRef.alu_op = 0xfU;
        }
    } else if ((0x20U & (IData)(vlSelfRef.opcode))) {
        if ((0x10U & (IData)(vlSelfRef.opcode))) {
            if ((8U & (IData)(vlSelfRef.opcode))) {
                vlSelfRef.imm = 0U;
                vlSelfRef.alu_op = 0xfU;
            } else if ((4U & (IData)(vlSelfRef.opcode))) {
                if ((2U & (IData)(vlSelfRef.opcode))) {
                    if ((1U & (IData)(vlSelfRef.opcode))) {
                        vlSelfRef.imm = (0xfffff000U 
                                         & vlSelfRef.inst);
                        vlSelfRef.alu_op = 1U;
                    } else {
                        vlSelfRef.imm = 0U;
                        vlSelfRef.alu_op = 0xfU;
                    }
                } else {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                }
            } else if ((2U & (IData)(vlSelfRef.opcode))) {
                if ((1U & (IData)(vlSelfRef.opcode))) {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = (((0U == (IData)(vlSelfRef.func3)) 
                                         & (0U == (IData)(vlSelfRef.func7)))
                                         ? 5U : (((0U 
                                                   == (IData)(vlSelfRef.func3)) 
                                                  & (0x20U 
                                                     == (IData)(vlSelfRef.func7)))
                                                  ? 0xcU
                                                  : 0xfU));
                } else {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                }
            } else {
                vlSelfRef.imm = 0U;
                vlSelfRef.alu_op = 0xfU;
            }
        } else if ((8U & (IData)(vlSelfRef.opcode))) {
            vlSelfRef.imm = 0U;
            vlSelfRef.alu_op = 0xfU;
        } else if ((4U & (IData)(vlSelfRef.opcode))) {
            vlSelfRef.imm = 0U;
            vlSelfRef.alu_op = 0xfU;
        } else if ((2U & (IData)(vlSelfRef.opcode))) {
            if ((1U & (IData)(vlSelfRef.opcode))) {
                vlSelfRef.imm = (((- (IData)((vlSelfRef.inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelfRef.inst 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.inst 
                                                    >> 7U))));
                vlSelfRef.alu_op = 9U;
            } else {
                vlSelfRef.imm = 0U;
                vlSelfRef.alu_op = 0xfU;
            }
        } else {
            vlSelfRef.imm = 0U;
            vlSelfRef.alu_op = 0xfU;
        }
    } else if ((0x10U & (IData)(vlSelfRef.opcode))) {
        if ((8U & (IData)(vlSelfRef.opcode))) {
            vlSelfRef.imm = 0U;
            vlSelfRef.alu_op = 0xfU;
        } else if ((4U & (IData)(vlSelfRef.opcode))) {
            if ((2U & (IData)(vlSelfRef.opcode))) {
                if ((1U & (IData)(vlSelfRef.opcode))) {
                    vlSelfRef.imm = (0xfffff000U & vlSelfRef.inst);
                    vlSelfRef.alu_op = 2U;
                } else {
                    vlSelfRef.imm = 0U;
                    vlSelfRef.alu_op = 0xfU;
                }
            } else {
                vlSelfRef.imm = 0U;
                vlSelfRef.alu_op = 0xfU;
            }
        } else if ((2U & (IData)(vlSelfRef.opcode))) {
            if ((1U & (IData)(vlSelfRef.opcode))) {
                vlSelfRef.imm = (((- (IData)((vlSelfRef.inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelfRef.inst 
                                              >> 0x14U));
                vlSelfRef.alu_op = ((0U == (IData)(vlSelfRef.func3))
                                     ? 0U : ((6U == (IData)(vlSelfRef.func3))
                                              ? 0xaU
                                              : 0xfU));
            } else {
                vlSelfRef.imm = 0U;
                vlSelfRef.alu_op = 0xfU;
            }
        } else {
            vlSelfRef.imm = 0U;
            vlSelfRef.alu_op = 0xfU;
        }
    } else if ((8U & (IData)(vlSelfRef.opcode))) {
        vlSelfRef.imm = 0U;
        vlSelfRef.alu_op = 0xfU;
    } else if ((4U & (IData)(vlSelfRef.opcode))) {
        vlSelfRef.imm = 0U;
        vlSelfRef.alu_op = 0xfU;
    } else if ((2U & (IData)(vlSelfRef.opcode))) {
        if ((1U & (IData)(vlSelfRef.opcode))) {
            vlSelfRef.imm = (((- (IData)((vlSelfRef.inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelfRef.inst 
                                          >> 0x14U));
            vlSelfRef.alu_op = 8U;
        } else {
            vlSelfRef.imm = 0U;
            vlSelfRef.alu_op = 0xfU;
        }
    } else {
        vlSelfRef.imm = 0U;
        vlSelfRef.alu_op = 0xfU;
    }
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.waddr 
        = vlSelfRef.rd;
    vlSelfRef.idu__DOT__rd = vlSelfRef.rd;
    vlSelfRef.idu__DOT__rs1 = vlSelfRef.rs1;
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.raddr1 
        = vlSelfRef.rs1;
    vlSelfRef.idu__DOT__rs2 = vlSelfRef.rs2;
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.raddr2 
        = vlSelfRef.rs2;
    vlSelfRef.idu__DOT__func3 = vlSelfRef.func3;
    vlSelfRef.idu__DOT__func7 = vlSelfRef.func7;
    vlSelfRef.idu__DOT__opcode = vlSelfRef.opcode;
    vlSelfRef.wen = ((0x13U == (IData)(vlSelfRef.opcode)) 
                     | ((0x37U == (IData)(vlSelfRef.opcode)) 
                        | ((0x17U == (IData)(vlSelfRef.opcode)) 
                           | ((0x6fU == (IData)(vlSelfRef.opcode)) 
                              | ((0x67U == (IData)(vlSelfRef.opcode)) 
                                 | ((0x33U == (IData)(vlSelfRef.opcode)) 
                                    | ((0x23U == (IData)(vlSelfRef.opcode)) 
                                       | (3U == (IData)(vlSelfRef.opcode)))))))));
    vlSelfRef.idu__DOT__imm = vlSelfRef.imm;
    vlSelfRef.exu__DOT__imm = vlSelfRef.imm;
    vlSelfRef.idu__DOT__alu_op = vlSelfRef.alu_op;
    vlSelfRef.exu__DOT__alu_op = vlSelfRef.alu_op;
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.wen = vlSelfRef.wen;
}

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_NPC___ico_sequent__TOP__ysyx_24090012_NPC__1(Vysyx_24090012_NPC_ysyx_24090012_NPC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC___ico_sequent__TOP__ysyx_24090012_NPC__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rs1_data = vlSymsp->TOP__ysyx_24090012_NPC__regfile.rdata1;
    vlSelfRef.rs2_data = vlSymsp->TOP__ysyx_24090012_NPC__regfile.rdata2;
    vlSelfRef.exu__DOT__rs1_data = vlSelfRef.rs1_data;
    vlSelfRef.exu__DOT__rs2_data = vlSelfRef.rs2_data;
    vlSelfRef.next_pc = ((IData)(4U) + vlSelfRef.pc);
    if ((1U & (~ ((IData)(vlSelfRef.alu_op) >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.alu_op))) {
            if ((2U & (IData)(vlSelfRef.alu_op))) {
                if ((1U & (IData)(vlSelfRef.alu_op))) {
                    if ((vlSelfRef.rs1_data != vlSelfRef.rs2_data)) {
                        vlSelfRef.next_pc = (vlSelfRef.pc 
                                             + vlSelfRef.imm);
                    }
                } else if ((vlSelfRef.rs1_data == vlSelfRef.rs2_data)) {
                    vlSelfRef.next_pc = (vlSelfRef.pc 
                                         + vlSelfRef.imm);
                }
            } else if ((1U & (~ (IData)(vlSelfRef.alu_op)))) {
                vlSelfRef.next_pc = (0xfffffffeU & 
                                     (vlSelfRef.rs1_data 
                                      + vlSelfRef.imm));
            }
        } else if ((2U & (IData)(vlSelfRef.alu_op))) {
            if ((1U & (IData)(vlSelfRef.alu_op))) {
                vlSelfRef.next_pc = (vlSelfRef.pc + vlSelfRef.imm);
            }
        }
    }
    vlSelfRef.result = 0U;
    if ((8U & (IData)(vlSelfRef.alu_op))) {
        if ((4U & (IData)(vlSelfRef.alu_op))) {
            if ((1U & (~ ((IData)(vlSelfRef.alu_op) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.alu_op)))) {
                    vlSelfRef.result = (vlSelfRef.rs1_data 
                                        - vlSelfRef.rs2_data);
                }
            }
        } else if ((2U & (IData)(vlSelfRef.alu_op))) {
            if ((1U & (~ (IData)(vlSelfRef.alu_op)))) {
                vlSelfRef.result = ((0U == vlSelfRef.rs1_data)
                                     ? 1U : 0U);
            }
        } else {
            vlSelfRef.result = ((1U & (IData)(vlSelfRef.alu_op))
                                 ? (vlSelfRef.rs1_data 
                                    + vlSelfRef.imm)
                                 : (vlSelfRef.rs1_data 
                                    + vlSelfRef.imm));
        }
    } else if ((4U & (IData)(vlSelfRef.alu_op))) {
        if ((1U & (~ ((IData)(vlSelfRef.alu_op) >> 1U)))) {
            vlSelfRef.result = ((1U & (IData)(vlSelfRef.alu_op))
                                 ? (vlSelfRef.rs1_data 
                                    + vlSelfRef.rs2_data)
                                 : ((IData)(4U) + vlSelfRef.pc));
        }
    } else {
        vlSelfRef.result = ((2U & (IData)(vlSelfRef.alu_op))
                             ? ((1U & (IData)(vlSelfRef.alu_op))
                                 ? ((IData)(4U) + vlSelfRef.pc)
                                 : (vlSelfRef.pc + vlSelfRef.imm))
                             : ((1U & (IData)(vlSelfRef.alu_op))
                                 ? vlSelfRef.imm : 
                                (vlSelfRef.rs1_data 
                                 + vlSelfRef.imm)));
    }
    vlSelfRef.exu__DOT__next_pc = vlSelfRef.next_pc;
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.wdata 
        = vlSelfRef.result;
    vlSelfRef.exu__DOT__result = vlSelfRef.result;
}

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_NPC___nba_sequent__TOP__ysyx_24090012_NPC__0(Vysyx_24090012_NPC_ysyx_24090012_NPC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC___nba_sequent__TOP__ysyx_24090012_NPC__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst) {
        vlSelfRef.pc = 0x80000000U;
        vlSelfRef.ebreak_flag = 0U;
    } else if ((0x100073U == vlSelfRef.inst)) {
        Vysyx_24090012_NPC_ysyx_24090012_NPC____Vdpiimwrap_ebreak_TOP__ysyx_24090012_NPC(
                                                                                vlSymsp->TOP__ysyx_24090012_NPC__regfile.rf
                                                                                [0xaU]);
        vlSelfRef.ebreak_flag = 1U;
        vlSelfRef.exit_code = vlSymsp->TOP__ysyx_24090012_NPC__regfile.rf
            [0xaU];
    } else {
        vlSelfRef.pc = vlSelfRef.next_pc;
    }
    vlSelfRef.ifu__DOT__pc = vlSelfRef.pc;
    vlSelfRef.exu__DOT__pc = vlSelfRef.pc;
}

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_NPC___nba_sequent__TOP__ysyx_24090012_NPC__1(Vysyx_24090012_NPC_ysyx_24090012_NPC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC___nba_sequent__TOP__ysyx_24090012_NPC__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rs1_data = vlSymsp->TOP__ysyx_24090012_NPC__regfile.rdata1;
    vlSelfRef.rs2_data = vlSymsp->TOP__ysyx_24090012_NPC__regfile.rdata2;
    vlSelfRef.exu__DOT__rs1_data = vlSelfRef.rs1_data;
    vlSelfRef.exu__DOT__rs2_data = vlSelfRef.rs2_data;
}

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_NPC___nba_comb__TOP__ysyx_24090012_NPC__0(Vysyx_24090012_NPC_ysyx_24090012_NPC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC___nba_comb__TOP__ysyx_24090012_NPC__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.next_pc = ((IData)(4U) + vlSelfRef.pc);
    if ((1U & (~ ((IData)(vlSelfRef.alu_op) >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.alu_op))) {
            if ((2U & (IData)(vlSelfRef.alu_op))) {
                if ((1U & (IData)(vlSelfRef.alu_op))) {
                    if ((vlSelfRef.rs1_data != vlSelfRef.rs2_data)) {
                        vlSelfRef.next_pc = (vlSelfRef.pc 
                                             + vlSelfRef.imm);
                    }
                } else if ((vlSelfRef.rs1_data == vlSelfRef.rs2_data)) {
                    vlSelfRef.next_pc = (vlSelfRef.pc 
                                         + vlSelfRef.imm);
                }
            } else if ((1U & (~ (IData)(vlSelfRef.alu_op)))) {
                vlSelfRef.next_pc = (0xfffffffeU & 
                                     (vlSelfRef.rs1_data 
                                      + vlSelfRef.imm));
            }
        } else if ((2U & (IData)(vlSelfRef.alu_op))) {
            if ((1U & (IData)(vlSelfRef.alu_op))) {
                vlSelfRef.next_pc = (vlSelfRef.pc + vlSelfRef.imm);
            }
        }
    }
    vlSelfRef.result = 0U;
    if ((8U & (IData)(vlSelfRef.alu_op))) {
        if ((4U & (IData)(vlSelfRef.alu_op))) {
            if ((1U & (~ ((IData)(vlSelfRef.alu_op) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.alu_op)))) {
                    vlSelfRef.result = (vlSelfRef.rs1_data 
                                        - vlSelfRef.rs2_data);
                }
            }
        } else if ((2U & (IData)(vlSelfRef.alu_op))) {
            if ((1U & (~ (IData)(vlSelfRef.alu_op)))) {
                vlSelfRef.result = ((0U == vlSelfRef.rs1_data)
                                     ? 1U : 0U);
            }
        } else {
            vlSelfRef.result = ((1U & (IData)(vlSelfRef.alu_op))
                                 ? (vlSelfRef.rs1_data 
                                    + vlSelfRef.imm)
                                 : (vlSelfRef.rs1_data 
                                    + vlSelfRef.imm));
        }
    } else if ((4U & (IData)(vlSelfRef.alu_op))) {
        if ((1U & (~ ((IData)(vlSelfRef.alu_op) >> 1U)))) {
            vlSelfRef.result = ((1U & (IData)(vlSelfRef.alu_op))
                                 ? (vlSelfRef.rs1_data 
                                    + vlSelfRef.rs2_data)
                                 : ((IData)(4U) + vlSelfRef.pc));
        }
    } else {
        vlSelfRef.result = ((2U & (IData)(vlSelfRef.alu_op))
                             ? ((1U & (IData)(vlSelfRef.alu_op))
                                 ? ((IData)(4U) + vlSelfRef.pc)
                                 : (vlSelfRef.pc + vlSelfRef.imm))
                             : ((1U & (IData)(vlSelfRef.alu_op))
                                 ? vlSelfRef.imm : 
                                (vlSelfRef.rs1_data 
                                 + vlSelfRef.imm)));
    }
    vlSelfRef.exu__DOT__next_pc = vlSelfRef.next_pc;
    vlSymsp->TOP__ysyx_24090012_NPC__regfile.wdata 
        = vlSelfRef.result;
    vlSelfRef.exu__DOT__result = vlSelfRef.result;
}
