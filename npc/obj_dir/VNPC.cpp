// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VNPC__pch.h"

//============================================================
// Constructors

VNPC::VNPC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VNPC__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , ebreak_flag{vlSymsp->TOP.ebreak_flag}
    , pc{vlSymsp->TOP.pc}
    , mem_data{vlSymsp->TOP.mem_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VNPC::VNPC(const char* _vcname__)
    : VNPC(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VNPC::~VNPC() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VNPC___024root___eval_debug_assertions(VNPC___024root* vlSelf);
#endif  // VL_DEBUG
void VNPC___024root___eval_static(VNPC___024root* vlSelf);
void VNPC___024root___eval_initial(VNPC___024root* vlSelf);
void VNPC___024root___eval_settle(VNPC___024root* vlSelf);
void VNPC___024root___eval(VNPC___024root* vlSelf);

void VNPC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VNPC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VNPC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VNPC___024root___eval_static(&(vlSymsp->TOP));
        VNPC___024root___eval_initial(&(vlSymsp->TOP));
        VNPC___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VNPC___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VNPC::eventsPending() { return false; }

uint64_t VNPC::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VNPC::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VNPC___024root___eval_final(VNPC___024root* vlSelf);

VL_ATTR_COLD void VNPC::final() {
    VNPC___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VNPC::hierName() const { return vlSymsp->name(); }
const char* VNPC::modelName() const { return "VNPC"; }
unsigned VNPC::threads() const { return 1; }
void VNPC::prepareClone() const { contextp()->prepareClone(); }
void VNPC::atClone() const {
    contextp()->threadPoolpOnClone();
}
