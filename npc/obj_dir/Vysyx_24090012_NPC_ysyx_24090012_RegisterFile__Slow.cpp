// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090012_NPC.h for the primary calling header

#include "Vysyx_24090012_NPC__pch.h"
#include "Vysyx_24090012_NPC__Syms.h"
#include "Vysyx_24090012_NPC_ysyx_24090012_RegisterFile.h"

// Parameter definitions for Vysyx_24090012_NPC_ysyx_24090012_RegisterFile
constexpr IData/*31:0*/ Vysyx_24090012_NPC_ysyx_24090012_RegisterFile::ADDR_WIDTH;
constexpr IData/*31:0*/ Vysyx_24090012_NPC_ysyx_24090012_RegisterFile::DATA_WIDTH;


void Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___ctor_var_reset(Vysyx_24090012_NPC_ysyx_24090012_RegisterFile* vlSelf);

Vysyx_24090012_NPC_ysyx_24090012_RegisterFile::Vysyx_24090012_NPC_ysyx_24090012_RegisterFile(Vysyx_24090012_NPC__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vysyx_24090012_NPC_ysyx_24090012_RegisterFile___ctor_var_reset(this);
}

void Vysyx_24090012_NPC_ysyx_24090012_RegisterFile::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vysyx_24090012_NPC_ysyx_24090012_RegisterFile::~Vysyx_24090012_NPC_ysyx_24090012_RegisterFile() {
}
