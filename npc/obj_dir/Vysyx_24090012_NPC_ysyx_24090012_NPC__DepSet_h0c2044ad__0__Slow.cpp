// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC_ysyx_24090012_NPC.h"

VL_ATTR_COLD void Vysyx_24090012_NPC_ysyx_24090012_NPC___ctor_var_reset(Vysyx_24090012_NPC_ysyx_24090012_NPC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vysyx_24090012_NPC_ysyx_24090012_NPC___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->mem_data = VL_RAND_RESET_I(32);
    vlSelf->ebreak_flag = VL_RAND_RESET_I(1);
    vlSelf->exit_code = VL_RAND_RESET_I(32);
    vlSelf->rs1 = VL_RAND_RESET_I(5);
    vlSelf->rs2 = VL_RAND_RESET_I(5);
    vlSelf->rd = VL_RAND_RESET_I(5);
    vlSelf->opcode = VL_RAND_RESET_I(7);
    vlSelf->func3 = VL_RAND_RESET_I(3);
    vlSelf->func7 = VL_RAND_RESET_I(7);
    vlSelf->imm = VL_RAND_RESET_I(32);
    vlSelf->alu_op = VL_RAND_RESET_I(4);
    vlSelf->rs1_data = VL_RAND_RESET_I(32);
    vlSelf->rs2_data = VL_RAND_RESET_I(32);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->next_pc = VL_RAND_RESET_I(32);
    vlSelf->wen = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->ifu__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->ifu__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->ifu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->ifu__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->ifu__DOT__mem_data = VL_RAND_RESET_I(32);
    vlSelf->idu__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->idu__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->idu__DOT__rs2 = VL_RAND_RESET_I(5);
    vlSelf->idu__DOT__rd = VL_RAND_RESET_I(5);
    vlSelf->idu__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->idu__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->idu__DOT__func3 = VL_RAND_RESET_I(3);
    vlSelf->idu__DOT__func7 = VL_RAND_RESET_I(7);
    vlSelf->idu__DOT__alu_op = VL_RAND_RESET_I(4);
    vlSelf->exu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->exu__DOT__rs1_data = VL_RAND_RESET_I(32);
    vlSelf->exu__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->exu__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->exu__DOT__alu_op = VL_RAND_RESET_I(4);
    vlSelf->exu__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->exu__DOT__next_pc = VL_RAND_RESET_I(32);
}
