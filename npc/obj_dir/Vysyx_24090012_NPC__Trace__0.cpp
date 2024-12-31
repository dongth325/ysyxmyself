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
        bufp->chgCData(oldp+0,(vlSelfRef.ysyx_24090012_NPC__DOT__rs1),5);
        bufp->chgCData(oldp+1,(vlSelfRef.ysyx_24090012_NPC__DOT__rs2),5);
        bufp->chgCData(oldp+2,(vlSelfRef.ysyx_24090012_NPC__DOT__opcode),7);
        bufp->chgCData(oldp+3,(vlSelfRef.ysyx_24090012_NPC__DOT__func3),3);
        bufp->chgCData(oldp+4,(vlSelfRef.ysyx_24090012_NPC__DOT__func7),7);
        bufp->chgIData(oldp+5,(vlSelfRef.ysyx_24090012_NPC__DOT__imm),32);
        bufp->chgCData(oldp+6,(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op),6);
        bufp->chgBit(oldp+7,(((0x13U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                              | ((0x37U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                 | ((0x17U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                    | ((0x73U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                       | ((0x6fU == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                          | ((0x67U 
                                              == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                             | ((0x33U 
                                                 == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                                | (3U 
                                                   == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)))))))))));
        bufp->chgSData(oldp+8,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr3),12);
        bufp->chgBit(oldp+9,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen3));
        bufp->chgSData(oldp+10,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr1),12);
        bufp->chgIData(oldp+11,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata1),32);
        bufp->chgBit(oldp+12,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen1));
        bufp->chgSData(oldp+13,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr2),12);
        bufp->chgBit(oldp+14,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen2));
        bufp->chgSData(oldp+15,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_addr),12);
        bufp->chgBit(oldp+16,(vlSelfRef.ysyx_24090012_NPC__DOT__is_ecall));
        bufp->chgBit(oldp+17,(vlSelfRef.ysyx_24090012_NPC__DOT__is_mret));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+18,(vlSelfRef.ysyx_24090012_NPC__DOT__result),32);
        bufp->chgIData(oldp+19,(vlSelfRef.ysyx_24090012_NPC__DOT__next_pc),32);
        bufp->chgIData(oldp+20,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+21,(vlSelfRef.ysyx_24090012_NPC__DOT__mstatus),32);
        bufp->chgIData(oldp+22,(vlSelfRef.ysyx_24090012_NPC__DOT__mtvec),32);
        bufp->chgIData(oldp+23,(vlSelfRef.ysyx_24090012_NPC__DOT__mepc),32);
        bufp->chgIData(oldp+24,(vlSelfRef.ysyx_24090012_NPC__DOT__mcause),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+25,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+57,(vlSelfRef.clk));
    bufp->chgBit(oldp+58,(vlSelfRef.rst));
    bufp->chgIData(oldp+59,(vlSelfRef.mem_data),32);
    bufp->chgIData(oldp+60,(vlSelfRef.pc),32);
    bufp->chgBit(oldp+61,(vlSelfRef.ebreak_flag));
    bufp->chgIData(oldp+62,(vlSelfRef.exit_code),32);
    bufp->chgCData(oldp+63,((0x1fU & (vlSelfRef.mem_data 
                                      >> 7U))),5);
    bufp->chgIData(oldp+64,(vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data),32);
    bufp->chgIData(oldp+65,(vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data),32);
    bufp->chgIData(oldp+66,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata3),32);
    bufp->chgIData(oldp+67,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wdata2),32);
    bufp->chgBit(oldp+68,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_wen));
    bufp->chgIData(oldp+69,(vlSelfRef.ysyx_24090012_NPC__DOT__mstatus_new),32);
    bufp->chgIData(oldp+70,(vlSelfRef.ysyx_24090012_NPC__DOT__csr_rdata),32);
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
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
