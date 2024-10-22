// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC_ysyx_24090012_RegisterFile.h"

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___ico_sequent__TOP__ysyx_24090012_NPC__regfile__0(Vysyx_24090012_NPC_ysyx_24090012_RegisterFile* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___ico_sequent__TOP__ysyx_24090012_NPC__regfile__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata1 = ((0U == (IData)(vlSelfRef.raddr1))
                         ? 0U : vlSelfRef.rf[vlSelfRef.raddr1]);
    vlSelfRef.rdata2 = ((0U == (IData)(vlSelfRef.raddr2))
                         ? 0U : vlSelfRef.rf[vlSelfRef.raddr2]);
}

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___nba_sequent__TOP__ysyx_24090012_NPC__regfile__0(Vysyx_24090012_NPC_ysyx_24090012_RegisterFile* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___nba_sequent__TOP__ysyx_24090012_NPC__regfile__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((0xaU == (IData)(vlSelfRef.raddr1)))) {
        VL_WRITEF_NX("At time %t: Reading from a0 (rf[10]), value = %x\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,32,
                     vlSelfRef.rdata1);
    }
    if (VL_UNLIKELY((0xaU == (IData)(vlSelfRef.raddr2)))) {
        VL_WRITEF_NX("At time %t: Reading from a0 (rf[10]), value = %x\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,32,
                     vlSelfRef.rdata2);
    }
    vlSelfRef.__VdlySet__rf__v0 = 0U;
    if (((IData)(vlSelfRef.wen) & (0U != (IData)(vlSelfRef.waddr)))) {
        if (VL_UNLIKELY((0xaU == (IData)(vlSelfRef.waddr)))) {
            VL_WRITEF_NX("At time %t: Writing to a0 (rf[10]), new value = %x\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         32,vlSelfRef.wdata);
        }
        vlSelfRef.__VdlyVal__rf__v0 = vlSelfRef.wdata;
        vlSelfRef.__VdlyDim0__rf__v0 = vlSelfRef.waddr;
        vlSelfRef.__VdlySet__rf__v0 = 1U;
    }
}

VL_INLINE_OPT void Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___nba_sequent__TOP__ysyx_24090012_NPC__regfile__1(Vysyx_24090012_NPC_ysyx_24090012_RegisterFile* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___nba_sequent__TOP__ysyx_24090012_NPC__regfile__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__rf__v0) {
        vlSelfRef.rf[vlSelfRef.__VdlyDim0__rf__v0] 
            = vlSelfRef.__VdlyVal__rf__v0;
    }
    vlSelfRef.rdata1 = ((0U == (IData)(vlSelfRef.raddr1))
                         ? 0U : vlSelfRef.rf[vlSelfRef.raddr1]);
    vlSelfRef.rdata2 = ((0U == (IData)(vlSelfRef.raddr2))
                         ? 0U : vlSelfRef.rf[vlSelfRef.raddr2]);
}
