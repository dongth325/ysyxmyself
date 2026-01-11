// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VYSYXSOCFULL_H_
#define VERILATED_VYSYXSOCFULL_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class VysyxSoCFull__Syms;
class VysyxSoCFull___024root;
class VerilatedVcdC;
class VysyxSoCFull___024unit;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VysyxSoCFull VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VysyxSoCFull__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clock,0,0);
    VL_IN8(&reset,0,0);
    VL_OUT8(&externalPins_gpio_seg_0,7,0);
    VL_OUT8(&externalPins_gpio_seg_1,7,0);
    VL_OUT8(&externalPins_gpio_seg_2,7,0);
    VL_OUT8(&externalPins_gpio_seg_3,7,0);
    VL_OUT8(&externalPins_gpio_seg_4,7,0);
    VL_OUT8(&externalPins_gpio_seg_5,7,0);
    VL_OUT8(&externalPins_gpio_seg_6,7,0);
    VL_OUT8(&externalPins_gpio_seg_7,7,0);
    VL_IN8(&externalPins_ps2_clk,0,0);
    VL_IN8(&externalPins_ps2_data,0,0);
    VL_OUT8(&externalPins_vga_r,7,0);
    VL_OUT8(&externalPins_vga_g,7,0);
    VL_OUT8(&externalPins_vga_b,7,0);
    VL_OUT8(&externalPins_vga_hsync,0,0);
    VL_OUT8(&externalPins_vga_vsync,0,0);
    VL_OUT8(&externalPins_vga_valid,0,0);
    VL_IN8(&externalPins_uart_rx,0,0);
    VL_OUT8(&externalPins_uart_tx,0,0);
    VL_OUT16(&externalPins_gpio_out,15,0);
    VL_IN16(&externalPins_gpio_in,15,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    VysyxSoCFull___024unit* const __PVT____024unit;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VysyxSoCFull___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VysyxSoCFull(VerilatedContext* contextp, const char* name = "TOP");
    explicit VysyxSoCFull(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VysyxSoCFull();
  private:
    VL_UNCOPYABLE(VysyxSoCFull);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    /// DPI Export functions
    static int get_branch_inst_count();
    static int get_compute_inst_count();
    static int get_csr_inst_count();
    static int get_csr_reg_value(int csr_reg_index);
    static int get_exu_count();
    static int get_hit_count();
    static int get_idu_count();
    static int get_if_allow_in();
    static int get_ifu_count();
    static int get_inst_r();
    static int get_instr_completed();
    static int get_jump_inst_count();
    static int get_load_inst_count();
    static int get_lsu_count();
    static int get_miss_count();
    static int get_other_inst_count();
    static int get_pc_value();
    static int get_read_count();
    static int get_reg_value(int reg_index);
    static int get_saved_addr();
    static int get_saved_sim_lsu_addr();
    static int get_store_inst_count();
    static int get_switch_value();
    static int get_write_count();

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
};

#endif  // guard
