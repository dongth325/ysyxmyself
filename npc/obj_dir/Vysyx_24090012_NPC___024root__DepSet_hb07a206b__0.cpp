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
    }
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___ico_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state)))) {
        if (((IData)(vlSelfRef.input_valid) & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid)))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__test = 1U;
        }
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state) {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state = 1U;
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 0U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 1U;
            if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_ready) {
                vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 0U;
            }
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 0U;
        if (((IData)(vlSelfRef.input_valid) & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid)))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state = 1U;
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 1U;
        }
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state) {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 1U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state) {
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid)))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 0U;
            }
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 0U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 1U;
        }
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
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_24090012_NPC___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
}

void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, IData/*31:0*/ wmask);
void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ebreak_TOP(IData/*31:0*/ exit_code);

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_sequent__TOP__0(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read__1__Vfuncout;
    __Vfunc_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_24090012_NPC__DOT__sram__DOT__pmem_read__3__Vfuncout;
    __Vfunc_ysyx_24090012_NPC__DOT__sram__DOT__pmem_read__3__Vfuncout = 0;
    CData/*0:0*/ __Vdly__ysyx_24090012_NPC__DOT__pc_ready;
    __Vdly__ysyx_24090012_NPC__DOT__pc_ready = 0;
    CData/*0:0*/ __Vdly__ysyx_24090012_NPC__DOT__idu_valid;
    __Vdly__ysyx_24090012_NPC__DOT__idu_valid = 0;
    CData/*0:0*/ __Vdly__ysyx_24090012_NPC__DOT__rd_ready;
    __Vdly__ysyx_24090012_NPC__DOT__rd_ready = 0;
    IData/*31:0*/ __VdlyVal__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0;
    __VdlyVal__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0;
    __VdlyDim0__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0;
    __VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 = 0;
    // Body
    __Vdly__ysyx_24090012_NPC__DOT__pc_ready = vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready;
    __Vdly__ysyx_24090012_NPC__DOT__idu_valid = vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid;
    __Vdly__ysyx_24090012_NPC__DOT__rd_ready = vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready;
    __VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__state 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__next_state));
    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__state 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state));
    if (vlSelfRef.rst) {
        __Vdly__ysyx_24090012_NPC__DOT__rd_ready = 1U;
    } else if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready))) {
        if ((0U != (0x1fU & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                             >> 7U)))) {
            __VdlyVal__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 
                = vlSelfRef.ysyx_24090012_NPC__DOT__result;
            __VdlyDim0__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 
                = (0x1fU & (vlSelfRef.ysyx_24090012_NPC__DOT__inst 
                            >> 7U));
            __VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0 = 1U;
        }
        __Vdly__ysyx_24090012_NPC__DOT__rd_ready = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready)))) {
        __Vdly__ysyx_24090012_NPC__DOT__rd_ready = 1U;
    }
    if (vlSelfRef.rst) {
        vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata = 0U;
    } else if (((~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state)) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__sram_valid))) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__mem_wen) {
            Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_write_TOP(vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr, vlSelfRef.ysyx_24090012_NPC__DOT__mem_wdata, (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__mem_wmask));
        } else {
            Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read_TOP(vlSelfRef.ysyx_24090012_NPC__DOT__mem_addr, __Vfunc_ysyx_24090012_NPC__DOT__sram__DOT__pmem_read__3__Vfuncout);
            vlSelfRef.ysyx_24090012_NPC__DOT__sram_rdata 
                = __Vfunc_ysyx_24090012_NPC__DOT__sram__DOT__pmem_read__3__Vfuncout;
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.pc = 0x80000000U;
        __Vdly__ysyx_24090012_NPC__DOT__pc_ready = 1U;
    } else if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
        vlSelfRef.pc = vlSelfRef.ysyx_24090012_NPC__DOT__next_pc;
        __Vdly__ysyx_24090012_NPC__DOT__pc_ready = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready)))) {
        __Vdly__ysyx_24090012_NPC__DOT__pc_ready = 1U;
    }
    if (vlSelfRef.rst) {
        vlSelfRef.pc = 0x80000000U;
        vlSelfRef.ebreak_flag = 0U;
    } else if ((0x100073U == vlSelfRef.ysyx_24090012_NPC__DOT__inst)) {
        Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ebreak_TOP(
                                                                                vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
                                                                                [0xaU]);
        vlSelfRef.ebreak_flag = 1U;
        vlSelfRef.exit_code = vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf
            [0xaU];
    } else if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready))) {
        vlSelfRef.pc = vlSelfRef.ysyx_24090012_NPC__DOT__next_pc;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready = __Vdly__ysyx_24090012_NPC__DOT__rd_ready;
    vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready = __Vdly__ysyx_24090012_NPC__DOT__pc_ready;
    if (__VdlySet__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0) {
        vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[__VdlyDim0__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0] 
            = __VdlyVal__ysyx_24090012_NPC__DOT__regfile__DOT__rf__v0;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__next_state));
    if (vlSelfRef.rst) {
        vlSelfRef.ysyx_24090012_NPC__DOT__inst = 0U;
        __Vdly__ysyx_24090012_NPC__DOT__idu_valid = 0U;
    } else if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_ready))) {
        vlSelfRef.ysyx_24090012_NPC__DOT__inst = vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_rdata;
        __Vdly__ysyx_24090012_NPC__DOT__idu_valid = 1U;
    } else if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_ready))) {
        __Vdly__ysyx_24090012_NPC__DOT__idu_valid = 0U;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid = __Vdly__ysyx_24090012_NPC__DOT__idu_valid;
    vlSelfRef.ysyx_24090012_NPC__DOT__sram_ready = 0U;
    if (vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__sram__DOT__state) {
            vlSelfRef.ysyx_24090012_NPC__DOT__sram_ready = 1U;
        }
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state));
    if (vlSelfRef.rst) {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_rdata = 0U;
    } else if (((~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state)) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid))) {
        Vysyx_24090012_NPC___024root____Vdpiimwrap_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read_TOP(vlSelfRef.input_pc, __Vfunc_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read__1__Vfuncout);
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_rdata 
            = __Vfunc_ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__pmem_read__1__Vfuncout;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready = 0U;
    if (vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__lsu__DOT__state) {
            if (vlSelfRef.ysyx_24090012_NPC__DOT__sram_ready) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mem_ready = 1U;
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state)))) {
        if (((IData)(vlSelfRef.input_valid) & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid)))) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__test = 1U;
        }
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state));
    vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_ready = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state 
        = vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state;
    vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 0U;
    if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_ready = 1U;
        }
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__state) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 1U;
            if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_ready) {
                vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state = 0U;
                vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 0U;
            }
        }
    } else if (((IData)(vlSelfRef.input_valid) & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__idu_valid)))) {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__next_state = 1U;
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid = 1U;
    }
    if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state) {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 1U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__state) {
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid)))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 0U;
            }
        }
    } else {
        vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 0U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__ifu_sram_valid) {
            vlSelfRef.ysyx_24090012_NPC__DOT__ifu__DOT__inst_sram__DOT__next_state = 1U;
        }
    }
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_sequent__TOP__1(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__ysyx_24090012_NPC__DOT__csr_rd_ready;
    __Vdly__ysyx_24090012_NPC__DOT__csr_rd_ready = 0;
    // Body
    __Vdly__ysyx_24090012_NPC__DOT__csr_rd_ready = vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_ready;
    if (vlSelfRef.rst) {
        vlSelfRef.ysyx_24090012_NPC__DOT__mstatus = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__mtvec = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__mepc = 0U;
        vlSelfRef.ysyx_24090012_NPC__DOT__mcause = 0U;
        __Vdly__ysyx_24090012_NPC__DOT__csr_rd_ready = 1U;
    } else if (((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid) 
                & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_ready))) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen) {
            if ((0x300U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mstatus 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata;
            } else if ((0x305U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mtvec 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata;
            } else if ((0x341U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mepc 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata;
            } else if ((0x342U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mcause 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata;
            }
        }
        __Vdly__ysyx_24090012_NPC__DOT__csr_rd_ready = 0U;
        if (vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen1) {
            if ((0x300U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mstatus 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1;
            } else if ((0x305U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mtvec 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1;
            } else if ((0x341U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mepc 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1;
            } else if ((0x342U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mcause 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1;
            }
        }
        if (vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen2) {
            if ((0x300U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mstatus 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2;
            } else if ((0x305U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mtvec 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2;
            } else if ((0x341U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mepc 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2;
            } else if ((0x342U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mcause 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2;
            }
        }
        if (vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen3) {
            if ((0x300U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mstatus 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3;
            } else if ((0x305U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mtvec 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3;
            } else if ((0x341U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mepc 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3;
            } else if ((0x342U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3))) {
                vlSelfRef.ysyx_24090012_NPC__DOT__mcause 
                    = vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3;
            }
        }
    } else if ((1U & (~ (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_ready)))) {
        __Vdly__ysyx_24090012_NPC__DOT__csr_rd_ready = 1U;
    }
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_ready 
        = __Vdly__ysyx_24090012_NPC__DOT__csr_rd_ready;
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_sequent__TOP__2(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_INLINE_OPT void Vysyx_24090012_NPC___024root___nba_comb__TOP__0(Vysyx_24090012_NPC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root___nba_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen1 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen2 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen3 = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__result = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc = vlSelfRef.pc;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata = 0U;
    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 0U;
    if (vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__state) {
        if (vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__state) {
            if ((0x20U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                if ((0x10U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                    } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                        } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
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
                        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if ((((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_ready) 
                                  & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready)) 
                                 & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                            }
                        } else {
                            vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 1U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                            if ((((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_ready) 
                                  & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready)) 
                                 & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready))) {
                                vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 0U;
                                vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                            }
                        }
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 1U;
                        if ((((IData)(vlSelfRef.ysyx_24090012_NPC__DOT__rd_ready) 
                              & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__pc_ready)) 
                             & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_ready))) {
                            vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 0U;
                            vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 0U;
                        }
                    }
                } else if ((8U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                } else if ((4U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
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
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
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
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 0U;
                    }
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
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
                        if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
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
                } else if ((2U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
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
                    if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__mstatus;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3 = 0x300U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen3 = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__mepc;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new 
                            = ((0U != (0x80U & vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new))
                                ? (8U | vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new)
                                : (0xfffffff7U & vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new));
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new 
                            = (0x80U | vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new);
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new 
                            = (0xffffe7ffU & vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new);
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__unnamedblk1__DOT__mstatus_new;
                    } else {
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2 = 0x341U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2 
                            = vlSelfRef.pc;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen2 = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1 = 0x342U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1 = 0x11U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen1 = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                            = vlSelfRef.ysyx_24090012_NPC__DOT__mtvec;
                        vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                        vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                    }
                } else if ((1U & (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op))) {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata 
                        = (vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata 
                           | vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data);
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__exu__DOT__next_state = 1U;
                } else {
                    vlSelfRef.ysyx_24090012_NPC__DOT__result 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata;
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_data 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__result;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata 
                        = vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__next_pc 
                        = ((IData)(4U) + vlSelfRef.pc);
                    vlSelfRef.ysyx_24090012_NPC__DOT__rd_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__pc_valid = 1U;
                    vlSelfRef.ysyx_24090012_NPC__DOT__csr_rd_valid = 1U;
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
    if (VL_UNLIKELY((vlSelfRef.input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
