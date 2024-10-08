// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC_ysyx_24090012_RegisterFile.h"

VL_ATTR_COLD void Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___ctor_var_reset(Vysyx_24090012_NPC_ysyx_24090012_RegisterFile* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->raddr1 = VL_RAND_RESET_I(5);
    vlSelf->raddr2 = VL_RAND_RESET_I(5);
    vlSelf->waddr = VL_RAND_RESET_I(5);
    vlSelf->wdata = VL_RAND_RESET_I(32);
    vlSelf->wen = VL_RAND_RESET_I(1);
    vlSelf->rdata1 = VL_RAND_RESET_I(32);
    vlSelf->rdata2 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__VdlyVal__rf__v0 = VL_RAND_RESET_I(32);
    vlSelf->__VdlyDim0__rf__v0 = VL_RAND_RESET_I(5);
    vlSelf->__VdlySet__rf__v0 = 0;
}
