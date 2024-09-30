// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vysyx_24090012_NPC__pch.h"

//============================================================
// Constructors

Vysyx_24090012_NPC::Vysyx_24090012_NPC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vysyx_24090012_NPC__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , ebreak_flag{vlSymsp->TOP.ebreak_flag}
    , pc{vlSymsp->TOP.pc}
    , mem_data{vlSymsp->TOP.mem_data}
    , exit_code{vlSymsp->TOP.exit_code}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vysyx_24090012_NPC::Vysyx_24090012_NPC(const char* _vcname__)
    : Vysyx_24090012_NPC(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vysyx_24090012_NPC::~Vysyx_24090012_NPC() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vysyx_24090012_NPC___024root___eval_debug_assertions(Vysyx_24090012_NPC___024root* vlSelf);
#endif  // VL_DEBUG
void Vysyx_24090012_NPC___024root___eval_static(Vysyx_24090012_NPC___024root* vlSelf);
void Vysyx_24090012_NPC___024root___eval_initial(Vysyx_24090012_NPC___024root* vlSelf);
void Vysyx_24090012_NPC___024root___eval_settle(Vysyx_24090012_NPC___024root* vlSelf);
void Vysyx_24090012_NPC___024root___eval(Vysyx_24090012_NPC___024root* vlSelf);

void Vysyx_24090012_NPC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vysyx_24090012_NPC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vysyx_24090012_NPC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vysyx_24090012_NPC___024root___eval_static(&(vlSymsp->TOP));
        Vysyx_24090012_NPC___024root___eval_initial(&(vlSymsp->TOP));
        Vysyx_24090012_NPC___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vysyx_24090012_NPC___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vysyx_24090012_NPC::eventsPending() { return false; }

uint64_t Vysyx_24090012_NPC::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vysyx_24090012_NPC::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vysyx_24090012_NPC___024root___eval_final(Vysyx_24090012_NPC___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24090012_NPC::final() {
    Vysyx_24090012_NPC___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vysyx_24090012_NPC::hierName() const { return vlSymsp->name(); }
const char* Vysyx_24090012_NPC::modelName() const { return "Vysyx_24090012_NPC"; }
unsigned Vysyx_24090012_NPC::threads() const { return 1; }
void Vysyx_24090012_NPC::prepareClone() const { contextp()->prepareClone(); }
void Vysyx_24090012_NPC::atClone() const {
    contextp()->threadPoolpOnClone();
}
