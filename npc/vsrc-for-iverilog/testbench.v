`timescale 1ns / 1ps

module testbench;
    reg clk = 0;
    reg reset = 1;

    // Define all AXI wires explicitly (to fix port expression error)
    wire npc_awvalid, npc_wvalid, npc_bready, npc_arvalid, npc_rready, npc_wlast;
    wire pmem_awready, pmem_wready, pmem_bvalid, pmem_arready, pmem_rvalid, pmem_rlast;
    wire [1:0] pmem_bresp, pmem_rresp;
    wire [3:0] pmem_bid, pmem_rid;
    wire [31:0] pmem_rdata;
    wire [31:0] npc_awaddr, npc_wdata, npc_araddr;
    wire [3:0] npc_awid, npc_wstrb, npc_arid;
    wire [7:0] npc_awlen, npc_arlen;
    wire [2:0] npc_awsize, npc_arsize;
    wire [1:0] npc_awburst, npc_arburst;

    // u_npc instance with named ports (fix line 21 syntax)
    ysyx_24090012 u_npc (
        .clock(clk),
        .reset(reset),
        .io_interrupt(1'b0),

        .io_master_awready(pmem_awready),
        .io_master_awvalid(npc_awvalid),
        .io_master_awaddr(npc_awaddr),
        .io_master_awid(npc_awid),
        .io_master_awlen(npc_awlen),
        .io_master_awsize(npc_awsize),
        .io_master_awburst(npc_awburst),
        .io_master_wready(pmem_wready),
        .io_master_wvalid(npc_wvalid),
        .io_master_wdata(npc_wdata),
        .io_master_wstrb(npc_wstrb),
        .io_master_wlast(npc_wlast),
        .io_master_bready(npc_bready),
        .io_master_bvalid(pmem_bvalid),
        .io_master_bresp(pmem_bresp),
        .io_master_bid(pmem_bid),
        .io_master_arready(pmem_arready),
        .io_master_arvalid(npc_arvalid),
        .io_master_araddr(npc_araddr),
        .io_master_arid(npc_arid),
        .io_master_arlen(npc_arlen),
        .io_master_arsize(npc_arsize),
        .io_master_arburst(npc_arburst),
        .io_master_rready(npc_rready),
        .io_master_rvalid(pmem_rvalid),
        .io_master_rresp(pmem_rresp),
        .io_master_rdata(pmem_rdata),
        .io_master_rlast(pmem_rlast),
        .io_master_rid(pmem_rid),  // line ~59, named port fix

        // io_slave_* assigned to 0 (named, ignore outputs)
        .io_slave_awready(1'b0),
        .io_slave_awvalid(1'b0),
        .io_slave_awaddr(32'b0),
        .io_slave_awid(4'b0),
        .io_slave_awlen(8'b0),
        .io_slave_awsize(3'b0),
        .io_slave_awburst(2'b0),
        .io_slave_wready(1'b0),
        .io_slave_wvalid(1'b0),
        .io_slave_wdata(32'b0),
        .io_slave_wstrb(4'b0),
        .io_slave_wlast(1'b0),
        .io_slave_bready(1'b0),
        .io_slave_bvalid(/* ignore */),
        .io_slave_bresp(/* ignore */),
        .io_slave_bid(/* ignore */),
        .io_slave_arready(1'b0),
        .io_slave_arvalid(1'b0),
        .io_slave_araddr(32'b0),
        .io_slave_arid(4'b0),
        .io_slave_arlen(8'b0),
        .io_slave_arsize(3'b0),
        .io_slave_arburst(2'b0),
        .io_slave_rready(1'b0),
        .io_slave_rvalid(/* ignore */),
        .io_slave_rresp(/* ignore */),
        .io_slave_rdata(/* ignore */),
        .io_slave_rlast(/* ignore */),
        .io_slave_rid(/* ignore */)
    );

    // u_pmem instance with named ports
    pmem u_pmem (
        .clk(clk),
        .reset(reset),

        .io_master_awready(pmem_awready),
        .io_master_awvalid(npc_awvalid),
        .io_master_awaddr(npc_awaddr),
        .io_master_awid(npc_awid),
        .io_master_awlen(npc_awlen),
        .io_master_awsize(npc_awsize),
        .io_master_awburst(npc_awburst),
        .io_master_wready(pmem_wready),
        .io_master_wvalid(npc_wvalid),
        .io_master_wdata(npc_wdata),
        .io_master_wstrb(npc_wstrb),
        .io_master_wlast(npc_wlast),
        .io_master_bready(npc_bready),
        .io_master_bvalid(pmem_bvalid),
        .io_master_bresp(pmem_bresp),
        .io_master_bid(pmem_bid),
        .io_master_arready(pmem_arready),
        .io_master_arvalid(npc_arvalid),
        .io_master_araddr(npc_araddr),
        .io_master_arid(npc_arid),
        .io_master_arlen(npc_arlen),
        .io_master_arsize(npc_arsize),
        .io_master_arburst(npc_arburst),
        .io_master_rready(npc_rready),
        .io_master_rvalid(pmem_rvalid),
        .io_master_rdata(pmem_rdata),
        .io_master_rresp(pmem_rresp),
        .io_master_rlast(pmem_rlast),
        .io_master_rid(pmem_rid)
    );

    always #5 clk = ~clk;

    initial begin
        #10 reset = 0;
        #100000 $finish;
    end

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, testbench);
    end
endmodule