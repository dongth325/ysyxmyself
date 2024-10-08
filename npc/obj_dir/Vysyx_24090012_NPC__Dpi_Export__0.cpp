// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "Vysyx_24090012_NPC.h"
#include "Vysyx_24090012_NPC__Syms.h"
#include "verilated_dpi.h"


void Vysyx_24090012_NPC::get_rf(svLogicVecVal* regs) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090012_NPC___024root::get_rf\n"); );
    // Init
    VlUnpacked<IData/*31:0*/, 32> regs__Vcvt;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        regs__Vcvt[__Vi0] = 0;
    }
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_rf");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vysyx_24090012_NPC__Vcb_get_rf_t __Vcb = (Vysyx_24090012_NPC__Vcb_get_rf_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vysyx_24090012_NPC__Syms*)(__Vscopep->symsp()), regs__Vcvt);
    for (size_t regs__Vidx = 0; regs__Vidx < 32; ++regs__Vidx) VL_SET_SVLV_I(32, regs + 1 * regs__Vidx, (&regs__Vcvt[0])[regs__Vidx]);
}
