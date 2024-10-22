// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24090012_NPC__Syms.h"


void Vysyx_24090012_NPC___024root__trace_chg_0_sub_0(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_24090012_NPC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_chg_0\n"); );
    // Init
    Vysyx_24090012_NPC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24090012_NPC___024root*>(voidSelf);
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_24090012_NPC___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_24090012_NPC___024root__trace_chg_0_sub_0(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelfRef.ysyx_24090012_NPC__DOT__opcode),7);
        bufp->chgCData(oldp+1,(vlSelfRef.ysyx_24090012_NPC__DOT__func3),3);
        bufp->chgCData(oldp+2,(vlSelfRef.ysyx_24090012_NPC__DOT__func7),7);
        bufp->chgIData(oldp+3,(vlSelfRef.ysyx_24090012_NPC__DOT__imm),32);
        bufp->chgCData(oldp+4,(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op),4);
        bufp->chgBit(oldp+5,(((0x13U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                              | ((0x37U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                 | ((0x17U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                    | ((0x6fU == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                       | ((0x67U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                          | ((0x33U 
                                              == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                             | (3U 
                                                == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))))))))));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+6,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+38,(vlSelfRef.clk));
    bufp->chgBit(oldp+39,(vlSelfRef.rst));
    bufp->chgIData(oldp+40,(vlSelfRef.mem_data),32);
    bufp->chgIData(oldp+41,(vlSelfRef.pc),32);
    bufp->chgBit(oldp+42,(vlSelfRef.ebreak_flag));
    bufp->chgIData(oldp+43,(vlSelfRef.exit_code),32);
    bufp->chgCData(oldp+44,((0x1fU & (vlSelfRef.mem_data 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+45,((0x1fU & (vlSelfRef.mem_data 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+46,((0x1fU & (vlSelfRef.mem_data 
                                      >> 7U))),5);
    bufp->chgIData(oldp+47,(vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data),32);
    bufp->chgIData(oldp+48,(vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data),32);
    bufp->chgIData(oldp+49,(vlSelfRef.ysyx_24090012_NPC__DOT__result),32);
    bufp->chgIData(oldp+50,(vlSelfRef.ysyx_24090012_NPC__DOT__next_pc),32);
}

void Vysyx_24090012_NPC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_cleanup\n"); );
    // Init
    Vysyx_24090012_NPC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24090012_NPC___024root*>(voidSelf);
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
