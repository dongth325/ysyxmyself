// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC___024root.h"

void Vysyx_24090012_NPC___024root___ico_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf);

void Vysyx_24090012_NPC___024root___eval_ico(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_write_TOP(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ mask);
void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___ico_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data = ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelfRef.mem_data 
                                                       >> 0xfU)))
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                  [
                                                  (0x1fU 
                                                   & (vlSelfRef.mem_data 
                                                      >> 0xfU))]);
    vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data = ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelfRef.mem_data 
                                                       >> 0x14U)))
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                  [
                                                  (0x1fU 
                                                   & (vlSelfRef.mem_data 
                                                      >> 0x14U))]);
    vlSelfRef.ysyx_24090012_NPC__DOT__opcode = (0x7fU 
                                                & vlSelfRef.mem_data);
    vlSelfRef.ysyx_24090012_NPC__DOT__func3 = (7U & 
                                               (vlSelfRef.mem_data 
                                                >> 0xcU));
    vlSelfRef.ysyx_24090012_NPC__DOT__func7 = (vlSelfRef.mem_data 
                                               >> 0x19U);
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
                        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xbU;
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
                                = (((- (IData)((vlSelfRef.mem_data 
                                                >> 0x1fU))) 
                                    << 0x14U) | ((0xff000U 
                                                  & vlSelfRef.mem_data) 
                                                 | ((0x800U 
                                                     & (vlSelfRef.mem_data 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelfRef.mem_data 
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
                            = (((- (IData)((vlSelfRef.mem_data 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.mem_data 
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
                        = (((- (IData)((vlSelfRef.mem_data 
                                        >> 0x1fU))) 
                            << 0xdU) | ((0x1000U & 
                                         (vlSelfRef.mem_data 
                                          >> 0x13U)) 
                                        | ((0x800U 
                                            & (vlSelfRef.mem_data 
                                               << 4U)) 
                                           | ((0x7e0U 
                                               & (vlSelfRef.mem_data 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelfRef.mem_data 
                                                    >> 7U))))));
                    vlSelfRef.ysyx_24090012_NPC__DOT__alu_op 
                        = ((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                            ? 6U : ((1U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                     ? 7U : 0xfU));
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
                            = (0xfffff000U & vlSelfRef.mem_data);
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
                                     ? 0xcU : 0xfU));
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
                    = (((- (IData)((vlSelfRef.mem_data 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelfRef.mem_data 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelfRef.mem_data 
                                                      >> 7U))));
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 9U;
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
                        = (0xfffff000U & vlSelfRef.mem_data);
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
                    = (((- (IData)((vlSelfRef.mem_data 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelfRef.mem_data >> 0x14U));
                vlSelfRef.ysyx_24090012_NPC__DOT__alu_op 
                    = ((0U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                        ? 0U : ((6U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__func3))
                                 ? 0xaU : 0xfU));
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
                (((- (IData)((vlSelfRef.mem_data >> 0x1fU))) 
                  << 0xcU) | (vlSelfRef.mem_data >> 0x14U));
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 8U;
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
            vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__imm = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__alu_op = 0xfU;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__result = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc = (((
                                                   ((3U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)) 
                                                    | (4U 
                                                       == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) 
                                                   | (6U 
                                                      == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) 
                                                  | (7U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))
                                                  ? 0U
                                                  : 
                                                 ((IData)(4U) 
                                                  + vlSelfRef.pc));
    if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
        if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((1U & (~ ((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           - vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
                }
            }
        } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = ((0U == vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data)
                        ? 1U : 0U);
            }
        } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                   + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
            Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_write_TOP(vlSelfRef.ysyx_24090012_NPC__DOT__result, vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data, 4U);
        } else {
            Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read_TOP(
                                                                                (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                                                                + vlSelfRef.ysyx_24090012_NPC__DOT__imm), vlSelfRef.__Vfunc_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read__2__Vfuncout);
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = vlSelfRef.__Vfunc_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read__2__Vfuncout;
        }
    } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
        if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                     != vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                }
            } else if ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                        == vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)) {
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
            }
        } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                   + vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = ((IData)(4U) + vlSelfRef.pc);
            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                = (0xfffffffeU & (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                  + vlSelfRef.ysyx_24090012_NPC__DOT__imm));
        }
    } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = ((IData)(4U) + vlSelfRef.pc);
            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__result = 
            ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))
              ? vlSelfRef.ysyx_24090012_NPC__DOT__imm
              : (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                 + vlSelfRef.ysyx_24090012_NPC__DOT__imm));
    }
}

void Vysyx_24090012_NPC___024root___eval_triggers__ico(Vysyx_24090012_NPC___024root* vlSelf);

bool Vysyx_24090012_NPC___024root___eval_phase__ico(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vysyx_24090012_NPC___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vysyx_24090012_NPC___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vysyx_24090012_NPC___024root___eval_act(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vysyx_24090012_NPC___024root___nba_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf);
void Vysyx_24090012_NPC___024root___nba_sequent__TOP__1(Vysyx_24090012_NPC___024root* vlSelf);
void Vysyx_24090012_NPC___024root___nba_sequent__TOP__2(Vysyx_24090012_NPC___024root* vlSelf);
void Vysyx_24090012_NPC___024root___nba_comb__TOP__0(Vysyx_24090012_NPC___024root* vlSelf);

void Vysyx_24090012_NPC___024root___eval_nba(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 = 0U;
    if (VL_UNLIKELY((((0x13U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                      | ((0x37U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                         | ((0x17U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                            | ((0x6fU == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                               | ((0x67U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                  | ((0x33U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                     | (3U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)))))))) 
                     & (0U != (0x1fU & (vlSelfRef.mem_data 
                                        >> 7U)))))) {
        VL_WRITEF_NX("At time %t: Writing to  (rf[%2#]), new value = %x from (registerfile.v)\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,5,(0x1fU 
                                                   & (vlSelfRef.mem_data 
                                                      >> 7U)),
                     32,vlSelfRef.ysyx_24090012_NPC__DOT__result);
        vlSelfRef.__VdlyVal__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 
            = vlSelfRef.ysyx_24090012_NPC__DOT__result;
        vlSelfRef.__VdlyDim0__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 
            = (0x1fU & (vlSelfRef.mem_data >> 7U));
        vlSelfRef.__VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 = 1U;
    }
}

void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ebreak_TOP(IData/*31:0*/ exit_code);

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_sequent__TOP__1(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst) {
        vlSelfRef.pc = 0x80000000U;
        vlSelfRef.ebreak_flag = 0U;
    } else if ((0x100073U == vlSelfRef.mem_data)) {
        Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ebreak_TOP(
                                                                                vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                                                [0xaU]);
        vlSelfRef.ebreak_flag = 1U;
        vlSelfRef.exit_code = vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
            [0xaU];
    } else {
        vlSelfRef.pc = vlSelfRef.ysyx_24090012_NPC__DOT__next_pc;
    }
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_sequent__TOP__2(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0) {
        vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[vlSelfRef.__VdlyDim0__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0] 
            = vlSelfRef.__VdlyVal__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data = ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelfRef.mem_data 
                                                       >> 0xfU)))
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                  [
                                                  (0x1fU 
                                                   & (vlSelfRef.mem_data 
                                                      >> 0xfU))]);
    vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data = ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelfRef.mem_data 
                                                       >> 0x14U)))
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                  [
                                                  (0x1fU 
                                                   & (vlSelfRef.mem_data 
                                                      >> 0x14U))]);
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_comb__TOP__0(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ysyx_24090012_NPC__DOT__result = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc = (((
                                                   ((3U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)) 
                                                    | (4U 
                                                       == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) 
                                                   | (6U 
                                                      == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) 
                                                  | (7U 
                                                     == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))
                                                  ? 0U
                                                  : 
                                                 ((IData)(4U) 
                                                  + vlSelfRef.pc));
    if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
        if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((1U & (~ ((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                           - vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
                }
            }
        } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op)))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__result 
                    = ((0U == vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data)
                        ? 1U : 0U);
            }
        } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                   + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
            Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_write_TOP(vlSelfRef.ysyx_24090012_NPC__DOT__result, vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data, 4U);
        } else {
            Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read_TOP(
                                                                                (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                                                                + vlSelfRef.ysyx_24090012_NPC__DOT__imm), vlSelfRef.__Vfunc_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read__2__Vfuncout);
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = vlSelfRef.__Vfunc_ysyx_24090012_NPC__DOT__exu__DOT__pmem_read__2__Vfuncout;
        }
    } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
        if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                     != vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
                }
            } else if ((vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                        == vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data)) {
                vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                    = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
            }
        } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                   + vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data);
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = ((IData)(4U) + vlSelfRef.pc);
            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                = (0xfffffffeU & (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                                  + vlSelfRef.ysyx_24090012_NPC__DOT__imm));
        }
    } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = ((IData)(4U) + vlSelfRef.pc);
            vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
        } else {
            vlSelfRef.ysyx_24090012_NPC__DOT__result 
                = (vlSelfRef.pc + vlSelfRef.ysyx_24090012_NPC__DOT__imm);
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__result = 
            ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))
              ? vlSelfRef.ysyx_24090012_NPC__DOT__imm
              : (vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data 
                 + vlSelfRef.ysyx_24090012_NPC__DOT__imm));
    }
}

void Vysyx_24090012_NPC___024root___eval_triggers__act(Vysyx_24090012_NPC___024root* vlSelf);

bool Vysyx_24090012_NPC___024root___eval_phase__act(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vysyx_24090012_NPC___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vysyx_24090012_NPC___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vysyx_24090012_NPC___024root___eval_phase__nba(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vysyx_24090012_NPC___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__ico(Vysyx_24090012_NPC___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__nba(Vysyx_24090012_NPC___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090012_NPC___024root___dump_triggers__act(Vysyx_24090012_NPC___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24090012_NPC___024root___eval(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vysyx_24090012_NPC___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("vsrc/NPC.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vysyx_24090012_NPC___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vysyx_24090012_NPC___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/NPC.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vysyx_24090012_NPC___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/NPC.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vysyx_24090012_NPC___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vysyx_24090012_NPC___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_24090012_NPC___024root___eval_debug_assertions(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
