// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC__Syms.h"
#include "Vysyx_24090012_NPC_ysyx_24090012_NPC.h"

VL_ATTR_COLD void Vysyx_24090012_NPC_ysyx_24090012_NPC___stl_sequent__TOP__ysyx_24090012_NPC__0(Vysyx_24090012_NPC_ysyx_24090012_NPC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC___stl_sequent__TOP__ysyx_24090012_NPC__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ifu__DOT__pc = vlSelfRef.pc;
    vlSelfRef.exu__DOT__pc = vlSelfRef.pc;
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
