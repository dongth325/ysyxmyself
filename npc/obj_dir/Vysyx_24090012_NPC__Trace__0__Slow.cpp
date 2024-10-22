// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24090012_NPC__Syms.h"


VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_init_sub__TOP__0(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_init_sub__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+39,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+43,0,"ebreak_flag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"exit_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ysyx_24090012_NPC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+39,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+43,0,"ebreak_flag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"exit_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+46,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+2,0,"func3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+3,0,"func7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+4,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+48,0,"rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+6,0,"wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("exu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+42,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+50,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"next_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("idu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+41,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+2,0,"func3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+3,0,"func7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+46,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("ifu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+39,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("regfile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+52,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+39,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+46,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+50,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+6,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+7+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_init_top(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_init_top\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vysyx_24090012_NPC___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24090012_NPC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24090012_NPC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_register(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_register\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vysyx_24090012_NPC___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vysyx_24090012_NPC___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vysyx_24090012_NPC___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vysyx_24090012_NPC___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_const_0_sub_0(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_const_0\n"); );
    // Init
    Vysyx_24090012_NPC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24090012_NPC___024root*>(voidSelf);
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_24090012_NPC___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_const_0_sub_0(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_const_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+52,(5U),32);
    bufp->fullIData(oldp+53,(0x20U),32);
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_full_0_sub_0(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_full_0\n"); );
    // Init
    Vysyx_24090012_NPC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24090012_NPC___024root*>(voidSelf);
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_24090012_NPC___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_24090012_NPC___024root__trace_full_0_sub_0(Vysyx_24090012_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vysyx_24090012_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root__trace_full_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelfRef.ysyx_24090012_NPC__DOT__opcode),7);
    bufp->fullCData(oldp+2,(vlSelfRef.ysyx_24090012_NPC__DOT__func3),3);
    bufp->fullCData(oldp+3,(vlSelfRef.ysyx_24090012_NPC__DOT__func7),7);
    bufp->fullIData(oldp+4,(vlSelfRef.ysyx_24090012_NPC__DOT__imm),32);
    bufp->fullCData(oldp+5,(vlSelfRef.ysyx_24090012_NPC__DOT__alu_op),4);
    bufp->fullBit(oldp+6,(((0x13U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                           | ((0x37U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                              | ((0x17U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                 | ((0x6fU == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                    | ((0x67U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                       | ((0x33U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode)) 
                                          | (3U == (IData)(vlSelfRef.ysyx_24090012_NPC__DOT__opcode))))))))));
    bufp->fullIData(oldp+7,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.ysyx_24090012_NPC__DOT__regfile__DOT__rf[31]),32);
    bufp->fullBit(oldp+39,(vlSelfRef.clk));
    bufp->fullBit(oldp+40,(vlSelfRef.rst));
    bufp->fullIData(oldp+41,(vlSelfRef.mem_data),32);
    bufp->fullIData(oldp+42,(vlSelfRef.pc),32);
    bufp->fullBit(oldp+43,(vlSelfRef.ebreak_flag));
    bufp->fullIData(oldp+44,(vlSelfRef.exit_code),32);
    bufp->fullCData(oldp+45,((0x1fU & (vlSelfRef.mem_data 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+46,((0x1fU & (vlSelfRef.mem_data 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+47,((0x1fU & (vlSelfRef.mem_data 
                                       >> 7U))),5);
    bufp->fullIData(oldp+48,(vlSelfRef.ysyx_24090012_NPC__DOT__rs1_data),32);
    bufp->fullIData(oldp+49,(vlSelfRef.ysyx_24090012_NPC__DOT__rs2_data),32);
    bufp->fullIData(oldp+50,(vlSelfRef.ysyx_24090012_NPC__DOT__result),32);
    bufp->fullIData(oldp+51,(vlSelfRef.ysyx_24090012_NPC__DOT__next_pc),32);
}
