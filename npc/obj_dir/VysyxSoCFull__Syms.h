// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VYSYXSOCFULL__SYMS_H_
#define VERILATED_VYSYXSOCFULL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VysyxSoCFull.h"

// INCLUDE MODULE CLASSES
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VysyxSoCFull__Vcb_get_csr_reg_value_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ csr_reg_index, IData/*31:0*/ &get_csr_reg_value__Vfuncrtn);
using VysyxSoCFull__Vcb_get_if_allow_in_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_if_allow_in__Vfuncrtn);
using VysyxSoCFull__Vcb_get_inst_r_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_inst_r__Vfuncrtn);
using VysyxSoCFull__Vcb_get_pc_value_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_pc_value__Vfuncrtn);
using VysyxSoCFull__Vcb_get_reg_value_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ reg_index, IData/*31:0*/ &get_reg_value__Vfuncrtn);
using VysyxSoCFull__Vcb_get_saved_addr_t = void (*) (VysyxSoCFull__Syms* __restrict vlSymsp, IData/*31:0*/ &get_saved_addr__Vfuncrtn);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VysyxSoCFull__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VysyxSoCFull* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VysyxSoCFull___024root         TOP;
    VysyxSoCFull___024unit         TOP____024unit;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_ysyxSoCFull;
    VerilatedScope __Vscope_ysyxSoCFull__asic;
    VerilatedScope __Vscope_ysyxSoCFull__asic__apbdelay_delayer;
    VerilatedScope __Vscope_ysyxSoCFull__asic__apbxbar;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi42apb;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi42apb__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi42apb__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__deq_q;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__deq_q_1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__deq_q_1__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__deq_q__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__in_wdeq_q;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__in_wdeq_q__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__unnamedblk1__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__unnamedblk1__unnamedblk3;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__unnamedblk1__unnamedblk4;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4frag__unnamedblk5;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4ram;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4ram__mem_ext;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4ram__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1__awIn_0;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1__awIn_0__ram_ext;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1__awIn_0__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4xbar_1__unnamedblk3;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_10;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_10__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_10__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_11;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_11__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_11__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_12;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_12__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_12__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_13;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_13__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_13__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_14;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_14__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_14__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_15;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_15__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_15__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_16;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_16__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_16__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_17;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_17__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_17__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_18;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_18__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_18__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_19;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_19__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_19__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_1__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_1__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_20;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_20__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_20__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_21;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_21__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_21__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_22;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_22__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_22__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_23;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_23__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_23__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_24;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_24__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_24__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_25;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_25__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_25__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_26;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_26__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_26__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_27;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_27__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_27__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_28;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_28__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_28__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_29;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_29__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_29__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_2__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_2__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_3;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_30;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_30__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_30__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_31;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_31__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_31__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_3__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_3__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_4;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_4__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_4__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_5;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_5__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_5__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_6;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_6__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_6__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_7;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_7__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_7__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_8;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_8__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_8__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_9;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_9__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap_9__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__Queue1_BundleMap__unnamedblk2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__axi4yank__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__arbiter;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__csr;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__exu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__idu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__ifu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__lsu;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu__cpu__regfile;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu_reset_chain;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu_reset_chain__output_chain;
    VerilatedScope __Vscope_ysyxSoCFull__asic__cpu_reset_chain__output_chain__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lgpio;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lgpio__mgpio;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lkeyboard;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lkeyboard__mps2;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lmrom;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lmrom__mrom;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lmrom__unnamedblk1;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lpsram;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lpsram__mpsram;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lpsram__mpsram__u0;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lpsram__mpsram__u0__MR;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lpsram__mpsram__u0__MW;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lsdram_apb;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lsdram_apb__msdram;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lsdram_apb__msdram__u_sdram_ctrl;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lspi;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lspi__mspi;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lspi__mspi__u0_spi_top;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lspi__mspi__u0_spi_top__clgen;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lspi__mspi__u0_spi_top__shift;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs__i_uart_sync_flops;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs__receiver;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs__receiver__fifo_rx;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs__receiver__fifo_rx__rfifo;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs__transmitter;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs__transmitter__fifo_tx;
    VerilatedScope __Vscope_ysyxSoCFull__asic__luart__muart__Uregs__transmitter__fifo_tx__tfifo;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lvga;
    VerilatedScope __Vscope_ysyxSoCFull__asic__lvga__mvga;
    VerilatedScope __Vscope_ysyxSoCFull__bitrev;
    VerilatedScope __Vscope_ysyxSoCFull__flash;
    VerilatedScope __Vscope_ysyxSoCFull__flash__flash_cmd_i;
    VerilatedScope __Vscope_ysyxSoCFull__psram;
    VerilatedScope __Vscope_ysyxSoCFull__sdram;

    // CONSTRUCTORS
    VysyxSoCFull__Syms(VerilatedContext* contextp, const char* namep, VysyxSoCFull* modelp);
    ~VysyxSoCFull__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
