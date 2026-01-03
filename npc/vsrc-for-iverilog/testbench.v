`timescale 1ns / 1ps

module testbench;
    reg clk = 0;
    reg reset = 1;
    reg io_interrupt = 1'b0; // 声明为 reg 并在 initial 块中保持 0 更好

    // --- AXI Master/Slave Interface Wires ---

    // AXI Master (NPC -> PMEM) Wires
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

    // AXI Slave (NPC作为从机) **OUTPUT** 端口的忽略线
    // 这些 wire 必须存在，以接收 DUT (ysyx_24090012) 的输出值
    wire io_slave_awready_ignore;
    wire io_slave_wready_ignore;
    wire io_slave_bvalid_ignore;
    wire [1:0] io_slave_bresp_ignore;
    wire [3:0] io_slave_bid_ignore;
    wire io_slave_arready_ignore;
    wire io_slave_rvalid_ignore;
    wire [1:0] io_slave_rresp_ignore;
    wire [31:0] io_slave_rdata_ignore;
    wire io_slave_rlast_ignore;
    wire [3:0] io_slave_rid_ignore;



    ysyx_24090012 u_npc (
        .clk(clk),
        .reset(reset),
        .io_interrupt(io_interrupt),
      
        // Master scalar
        .io_master_awready(pmem_awready),
        .io_master_awvalid(npc_awvalid),
        .io_master_wready(pmem_wready),
        .io_master_wvalid(npc_wvalid),
        .io_master_wlast(npc_wlast),
        .io_master_bready(npc_bready),
        .io_master_bvalid(pmem_bvalid),
        .io_master_arready(pmem_arready),
        .io_master_arvalid(npc_arvalid),
        .io_master_rready(npc_rready),
        .io_master_rvalid(pmem_rvalid),
        .io_master_rlast(pmem_rlast),
      
        // Master AWADDR[31:0]
        .\io_master_awaddr[0] (npc_awaddr[0]), .\io_master_awaddr[1] (npc_awaddr[1]), .\io_master_awaddr[2] (npc_awaddr[2]), .\io_master_awaddr[3] (npc_awaddr[3]),
        .\io_master_awaddr[4] (npc_awaddr[4]), .\io_master_awaddr[5] (npc_awaddr[5]), .\io_master_awaddr[6] (npc_awaddr[6]), .\io_master_awaddr[7] (npc_awaddr[7]),
        .\io_master_awaddr[8] (npc_awaddr[8]), .\io_master_awaddr[9] (npc_awaddr[9]), .\io_master_awaddr[10] (npc_awaddr[10]), .\io_master_awaddr[11] (npc_awaddr[11]),
        .\io_master_awaddr[12] (npc_awaddr[12]), .\io_master_awaddr[13] (npc_awaddr[13]), .\io_master_awaddr[14] (npc_awaddr[14]), .\io_master_awaddr[15] (npc_awaddr[15]),
        .\io_master_awaddr[16] (npc_awaddr[16]), .\io_master_awaddr[17] (npc_awaddr[17]), .\io_master_awaddr[18] (npc_awaddr[18]), .\io_master_awaddr[19] (npc_awaddr[19]),
        .\io_master_awaddr[20] (npc_awaddr[20]), .\io_master_awaddr[21] (npc_awaddr[21]), .\io_master_awaddr[22] (npc_awaddr[22]), .\io_master_awaddr[23] (npc_awaddr[23]),
        .\io_master_awaddr[24] (npc_awaddr[24]), .\io_master_awaddr[25] (npc_awaddr[25]), .\io_master_awaddr[26] (npc_awaddr[26]), .\io_master_awaddr[27] (npc_awaddr[27]),
        .\io_master_awaddr[28] (npc_awaddr[28]), .\io_master_awaddr[29] (npc_awaddr[29]), .\io_master_awaddr[30] (npc_awaddr[30]), .\io_master_awaddr[31] (npc_awaddr[31]),
      
        // Master AWID[3:0]
        .\io_master_awid[0] (npc_awid[0]), .\io_master_awid[1] (npc_awid[1]), .\io_master_awid[2] (npc_awid[2]), .\io_master_awid[3] (npc_awid[3]),
      
        // Master AWLEN[7:0]
        .\io_master_awlen[0] (npc_awlen[0]), .\io_master_awlen[1] (npc_awlen[1]), .\io_master_awlen[2] (npc_awlen[2]), .\io_master_awlen[3] (npc_awlen[3]),
        .\io_master_awlen[4] (npc_awlen[4]), .\io_master_awlen[5] (npc_awlen[5]), .\io_master_awlen[6] (npc_awlen[6]), .\io_master_awlen[7] (npc_awlen[7]),
      
        // Master AWSIZE[2:0]
        .\io_master_awsize[0] (npc_awsize[0]), .\io_master_awsize[1] (npc_awsize[1]), .\io_master_awsize[2] (npc_awsize[2]),
      
        // Master AWBURST[1:0]
        .\io_master_awburst[0] (npc_awburst[0]), .\io_master_awburst[1] (npc_awburst[1]),
      
        // Master WDATA[31:0]
        .\io_master_wdata[0] (npc_wdata[0]), .\io_master_wdata[1] (npc_wdata[1]), .\io_master_wdata[2] (npc_wdata[2]), .\io_master_wdata[3] (npc_wdata[3]),
        .\io_master_wdata[4] (npc_wdata[4]), .\io_master_wdata[5] (npc_wdata[5]), .\io_master_wdata[6] (npc_wdata[6]), .\io_master_wdata[7] (npc_wdata[7]),
        .\io_master_wdata[8] (npc_wdata[8]), .\io_master_wdata[9] (npc_wdata[9]), .\io_master_wdata[10] (npc_wdata[10]), .\io_master_wdata[11] (npc_wdata[11]),
        .\io_master_wdata[12] (npc_wdata[12]), .\io_master_wdata[13] (npc_wdata[13]), .\io_master_wdata[14] (npc_wdata[14]), .\io_master_wdata[15] (npc_wdata[15]),
        .\io_master_wdata[16] (npc_wdata[16]), .\io_master_wdata[17] (npc_wdata[17]), .\io_master_wdata[18] (npc_wdata[18]), .\io_master_wdata[19] (npc_wdata[19]),
        .\io_master_wdata[20] (npc_wdata[20]), .\io_master_wdata[21] (npc_wdata[21]), .\io_master_wdata[22] (npc_wdata[22]), .\io_master_wdata[23] (npc_wdata[23]),
        .\io_master_wdata[24] (npc_wdata[24]), .\io_master_wdata[25] (npc_wdata[25]), .\io_master_wdata[26] (npc_wdata[26]), .\io_master_wdata[27] (npc_wdata[27]),
        .\io_master_wdata[28] (npc_wdata[28]), .\io_master_wdata[29] (npc_wdata[29]), .\io_master_wdata[30] (npc_wdata[30]), .\io_master_wdata[31] (npc_wdata[31]),
      
        // Master WSTRB[3:0]
        .\io_master_wstrb[0] (npc_wstrb[0]), .\io_master_wstrb[1] (npc_wstrb[1]), .\io_master_wstrb[2] (npc_wstrb[2]), .\io_master_wstrb[3] (npc_wstrb[3]),
      
        // Master BRESP[1:0]
        .\io_master_bresp[0] (pmem_bresp[0]), .\io_master_bresp[1] (pmem_bresp[1]),
      
        // Master BID[3:0]
        .\io_master_bid[0] (pmem_bid[0]), .\io_master_bid[1] (pmem_bid[1]), .\io_master_bid[2] (pmem_bid[2]), .\io_master_bid[3] (pmem_bid[3]),
      
        // Master ARADDR[31:0]
        .\io_master_araddr[0] (npc_araddr[0]), .\io_master_araddr[1] (npc_araddr[1]), .\io_master_araddr[2] (npc_araddr[2]), .\io_master_araddr[3] (npc_araddr[3]),
        .\io_master_araddr[4] (npc_araddr[4]), .\io_master_araddr[5] (npc_araddr[5]), .\io_master_araddr[6] (npc_araddr[6]), .\io_master_araddr[7] (npc_araddr[7]),
        .\io_master_araddr[8] (npc_araddr[8]), .\io_master_araddr[9] (npc_araddr[9]), .\io_master_araddr[10] (npc_araddr[10]), .\io_master_araddr[11] (npc_araddr[11]),
        .\io_master_araddr[12] (npc_araddr[12]), .\io_master_araddr[13] (npc_araddr[13]), .\io_master_araddr[14] (npc_araddr[14]), .\io_master_araddr[15] (npc_araddr[15]),
        .\io_master_araddr[16] (npc_araddr[16]), .\io_master_araddr[17] (npc_araddr[17]), .\io_master_araddr[18] (npc_araddr[18]), .\io_master_araddr[19] (npc_araddr[19]),
        .\io_master_araddr[20] (npc_araddr[20]), .\io_master_araddr[21] (npc_araddr[21]), .\io_master_araddr[22] (npc_araddr[22]), .\io_master_araddr[23] (npc_araddr[23]),
        .\io_master_araddr[24] (npc_araddr[24]), .\io_master_araddr[25] (npc_araddr[25]), .\io_master_araddr[26] (npc_araddr[26]), .\io_master_araddr[27] (npc_araddr[27]),
        .\io_master_araddr[28] (npc_araddr[28]), .\io_master_araddr[29] (npc_araddr[29]), .\io_master_araddr[30] (npc_araddr[30]), .\io_master_araddr[31] (npc_araddr[31]),
      
        // Master ARID[3:0]
        .\io_master_arid[0] (npc_arid[0]), .\io_master_arid[1] (npc_arid[1]), .\io_master_arid[2] (npc_arid[2]), .\io_master_arid[3] (npc_arid[3]),
      
        // Master ARLEN[7:0]
        .\io_master_arlen[0] (npc_arlen[0]), .\io_master_arlen[1] (npc_arlen[1]), .\io_master_arlen[2] (npc_arlen[2]), .\io_master_arlen[3] (npc_arlen[3]),
        .\io_master_arlen[4] (npc_arlen[4]), .\io_master_arlen[5] (npc_arlen[5]), .\io_master_arlen[6] (npc_arlen[6]), .\io_master_arlen[7] (npc_arlen[7]),
      
        // Master ARSIZE[2:0]
        .\io_master_arsize[0] (npc_arsize[0]), .\io_master_arsize[1] (npc_arsize[1]), .\io_master_arsize[2] (npc_arsize[2]),
      
        // Master ARBURST[1:0]
        .\io_master_arburst[0] (npc_arburst[0]), .\io_master_arburst[1] (npc_arburst[1]),
      
        // Master RRESP[1:0]
        .\io_master_rresp[0] (pmem_rresp[0]), .\io_master_rresp[1] (pmem_rresp[1]),
      
        // Master RDATA[31:0]
        .\io_master_rdata[0] (pmem_rdata[0]), .\io_master_rdata[1] (pmem_rdata[1]), .\io_master_rdata[2] (pmem_rdata[2]), .\io_master_rdata[3] (pmem_rdata[3]),
        .\io_master_rdata[4] (pmem_rdata[4]), .\io_master_rdata[5] (pmem_rdata[5]), .\io_master_rdata[6] (pmem_rdata[6]), .\io_master_rdata[7] (pmem_rdata[7]),
        .\io_master_rdata[8] (pmem_rdata[8]), .\io_master_rdata[9] (pmem_rdata[9]), .\io_master_rdata[10] (pmem_rdata[10]), .\io_master_rdata[11] (pmem_rdata[11]),
        .\io_master_rdata[12] (pmem_rdata[12]), .\io_master_rdata[13] (pmem_rdata[13]), .\io_master_rdata[14] (pmem_rdata[14]), .\io_master_rdata[15] (pmem_rdata[15]),
        .\io_master_rdata[16] (pmem_rdata[16]), .\io_master_rdata[17] (pmem_rdata[17]), .\io_master_rdata[18] (pmem_rdata[18]), .\io_master_rdata[19] (pmem_rdata[19]),
        .\io_master_rdata[20] (pmem_rdata[20]), .\io_master_rdata[21] (pmem_rdata[21]), .\io_master_rdata[22] (pmem_rdata[22]), .\io_master_rdata[23] (pmem_rdata[23]),
        .\io_master_rdata[24] (pmem_rdata[24]), .\io_master_rdata[25] (pmem_rdata[25]), .\io_master_rdata[26] (pmem_rdata[26]), .\io_master_rdata[27] (pmem_rdata[27]),
        .\io_master_rdata[28] (pmem_rdata[28]), .\io_master_rdata[29] (pmem_rdata[29]), .\io_master_rdata[30] (pmem_rdata[30]), .\io_master_rdata[31] (pmem_rdata[31]),
      
        // Master RID[3:0]
        .\io_master_rid[0] (pmem_rid[0]), .\io_master_rid[1] (pmem_rid[1]), .\io_master_rid[2] (pmem_rid[2]), .\io_master_rid[3] (pmem_rid[3]),
      
        // Slave scalar
        .io_slave_awready(io_slave_awready_ignore),
        .io_slave_awvalid(1'b0),
        .io_slave_wready(io_slave_wready_ignore),
        .io_slave_wvalid(1'b0),
        .io_slave_wlast(1'b0),
        .io_slave_bready(1'b0),
        .io_slave_bvalid(io_slave_bvalid_ignore),
        .io_slave_arready(io_slave_arready_ignore),
        .io_slave_arvalid(1'b0),
        .io_slave_rready(1'b0),
        .io_slave_rvalid(io_slave_rvalid_ignore),
        .io_slave_rlast(io_slave_rlast_ignore),
      
        // Slave AWADDR[31:0] -> 0
        .\io_slave_awaddr[0] (1'b0), .\io_slave_awaddr[1] (1'b0), .\io_slave_awaddr[2] (1'b0), .\io_slave_awaddr[3] (1'b0),
        .\io_slave_awaddr[4] (1'b0), .\io_slave_awaddr[5] (1'b0), .\io_slave_awaddr[6] (1'b0), .\io_slave_awaddr[7] (1'b0),
        .\io_slave_awaddr[8] (1'b0), .\io_slave_awaddr[9] (1'b0), .\io_slave_awaddr[10] (1'b0), .\io_slave_awaddr[11] (1'b0),
        .\io_slave_awaddr[12] (1'b0), .\io_slave_awaddr[13] (1'b0), .\io_slave_awaddr[14] (1'b0), .\io_slave_awaddr[15] (1'b0),
        .\io_slave_awaddr[16] (1'b0), .\io_slave_awaddr[17] (1'b0), .\io_slave_awaddr[18] (1'b0), .\io_slave_awaddr[19] (1'b0),
        .\io_slave_awaddr[20] (1'b0), .\io_slave_awaddr[21] (1'b0), .\io_slave_awaddr[22] (1'b0), .\io_slave_awaddr[23] (1'b0),
        .\io_slave_awaddr[24] (1'b0), .\io_slave_awaddr[25] (1'b0), .\io_slave_awaddr[26] (1'b0), .\io_slave_awaddr[27] (1'b0),
        .\io_slave_awaddr[28] (1'b0), .\io_slave_awaddr[29] (1'b0), .\io_slave_awaddr[30] (1'b0), .\io_slave_awaddr[31] (1'b0),
      
        // Slave AWID[3:0] -> 0
        .\io_slave_awid[0] (1'b0), .\io_slave_awid[1] (1'b0), .\io_slave_awid[2] (1'b0), .\io_slave_awid[3] (1'b0),
      
        // Slave AWLEN[7:0] -> 0
        .\io_slave_awlen[0] (1'b0), .\io_slave_awlen[1] (1'b0), .\io_slave_awlen[2] (1'b0), .\io_slave_awlen[3] (1'b0),
        .\io_slave_awlen[4] (1'b0), .\io_slave_awlen[5] (1'b0), .\io_slave_awlen[6] (1'b0), .\io_slave_awlen[7] (1'b0),
      
        // Slave AWSIZE[2:0] -> 0
        .\io_slave_awsize[0] (1'b0), .\io_slave_awsize[1] (1'b0), .\io_slave_awsize[2] (1'b0),
      
        // Slave AWBURST[1:0] -> 0
        .\io_slave_awburst[0] (1'b0), .\io_slave_awburst[1] (1'b0),
      
        // Slave WDATA[31:0] -> 0
        .\io_slave_wdata[0] (1'b0), .\io_slave_wdata[1] (1'b0), .\io_slave_wdata[2] (1'b0), .\io_slave_wdata[3] (1'b0),
        .\io_slave_wdata[4] (1'b0), .\io_slave_wdata[5] (1'b0), .\io_slave_wdata[6] (1'b0), .\io_slave_wdata[7] (1'b0),
        .\io_slave_wdata[8] (1'b0), .\io_slave_wdata[9] (1'b0), .\io_slave_wdata[10] (1'b0), .\io_slave_wdata[11] (1'b0),
        .\io_slave_wdata[12] (1'b0), .\io_slave_wdata[13] (1'b0), .\io_slave_wdata[14] (1'b0), .\io_slave_wdata[15] (1'b0),
        .\io_slave_wdata[16] (1'b0), .\io_slave_wdata[17] (1'b0), .\io_slave_wdata[18] (1'b0), .\io_slave_wdata[19] (1'b0),
        .\io_slave_wdata[20] (1'b0), .\io_slave_wdata[21] (1'b0), .\io_slave_wdata[22] (1'b0), .\io_slave_wdata[23] (1'b0),
        .\io_slave_wdata[24] (1'b0), .\io_slave_wdata[25] (1'b0), .\io_slave_wdata[26] (1'b0), .\io_slave_wdata[27] (1'b0),
        .\io_slave_wdata[28] (1'b0), .\io_slave_wdata[29] (1'b0), .\io_slave_wdata[30] (1'b0), .\io_slave_wdata[31] (1'b0),
      
        // Slave WSTRB[3:0] -> 0
        .\io_slave_wstrb[0] (1'b0), .\io_slave_wstrb[1] (1'b0), .\io_slave_wstrb[2] (1'b0), .\io_slave_wstrb[3] (1'b0),
      
        // Slave BRESP[1:0] -> to ignore wires
        .\io_slave_bresp[0] (io_slave_bresp_ignore[0]), .\io_slave_bresp[1] (io_slave_bresp_ignore[1]),
      
        // Slave BID[3:0] -> to ignore wires
        .\io_slave_bid[0] (io_slave_bid_ignore[0]), .\io_slave_bid[1] (io_slave_bid_ignore[1]),
        .\io_slave_bid[2] (io_slave_bid_ignore[2]), .\io_slave_bid[3] (io_slave_bid_ignore[3]),
      
        // Slave ARADDR[31:0] -> 0
        .\io_slave_araddr[0] (1'b0), .\io_slave_araddr[1] (1'b0), .\io_slave_araddr[2] (1'b0), .\io_slave_araddr[3] (1'b0),
        .\io_slave_araddr[4] (1'b0), .\io_slave_araddr[5] (1'b0), .\io_slave_araddr[6] (1'b0), .\io_slave_araddr[7] (1'b0),
        .\io_slave_araddr[8] (1'b0), .\io_slave_araddr[9] (1'b0), .\io_slave_araddr[10] (1'b0), .\io_slave_araddr[11] (1'b0),
        .\io_slave_araddr[12] (1'b0), .\io_slave_araddr[13] (1'b0), .\io_slave_araddr[14] (1'b0), .\io_slave_araddr[15] (1'b0),
        .\io_slave_araddr[16] (1'b0), .\io_slave_araddr[17] (1'b0), .\io_slave_araddr[18] (1'b0), .\io_slave_araddr[19] (1'b0),
        .\io_slave_araddr[20] (1'b0), .\io_slave_araddr[21] (1'b0), .\io_slave_araddr[22] (1'b0), .\io_slave_araddr[23] (1'b0),
        .\io_slave_araddr[24] (1'b0), .\io_slave_araddr[25] (1'b0), .\io_slave_araddr[26] (1'b0), .\io_slave_araddr[27] (1'b0),
        .\io_slave_araddr[28] (1'b0), .\io_slave_araddr[29] (1'b0), .\io_slave_araddr[30] (1'b0), .\io_slave_araddr[31] (1'b0),
      
        // Slave ARID[3:0] -> 0
        .\io_slave_arid[0] (1'b0), .\io_slave_arid[1] (1'b0), .\io_slave_arid[2] (1'b0), .\io_slave_arid[3] (1'b0),
      
        // Slave ARLEN[7:0] -> 0
        .\io_slave_arlen[0] (1'b0), .\io_slave_arlen[1] (1'b0), .\io_slave_arlen[2] (1'b0), .\io_slave_arlen[3] (1'b0),
        .\io_slave_arlen[4] (1'b0), .\io_slave_arlen[5] (1'b0), .\io_slave_arlen[6] (1'b0), .\io_slave_arlen[7] (1'b0),
      
        // Slave ARSIZE[2:0] -> 0
        .\io_slave_arsize[0] (1'b0), .\io_slave_arsize[1] (1'b0), .\io_slave_arsize[2] (1'b0),
      
        // Slave ARBURST[1:0] -> 0
        .\io_slave_arburst[0] (1'b0), .\io_slave_arburst[1] (1'b0),
      
        // Slave RRESP[1:0] -> to ignore wires
        .\io_slave_rresp[0] (io_slave_rresp_ignore[0]), .\io_slave_rresp[1] (io_slave_rresp_ignore[1]),
      
        // Slave RDATA[31:0] -> to ignore wires
        .\io_slave_rdata[0] (io_slave_rdata_ignore[0]), .\io_slave_rdata[1] (io_slave_rdata_ignore[1]), .\io_slave_rdata[2] (io_slave_rdata_ignore[2]), .\io_slave_rdata[3] (io_slave_rdata_ignore[3]),
        .\io_slave_rdata[4] (io_slave_rdata_ignore[4]), .\io_slave_rdata[5] (io_slave_rdata_ignore[5]), .\io_slave_rdata[6] (io_slave_rdata_ignore[6]), .\io_slave_rdata[7] (io_slave_rdata_ignore[7]),
        .\io_slave_rdata[8] (io_slave_rdata_ignore[8]), .\io_slave_rdata[9] (io_slave_rdata_ignore[9]), .\io_slave_rdata[10] (io_slave_rdata_ignore[10]), .\io_slave_rdata[11] (io_slave_rdata_ignore[11]),
        .\io_slave_rdata[12] (io_slave_rdata_ignore[12]), .\io_slave_rdata[13] (io_slave_rdata_ignore[13]), .\io_slave_rdata[14] (io_slave_rdata_ignore[14]), .\io_slave_rdata[15] (io_slave_rdata_ignore[15]),
        .\io_slave_rdata[16] (io_slave_rdata_ignore[16]), .\io_slave_rdata[17] (io_slave_rdata_ignore[17]), .\io_slave_rdata[18] (io_slave_rdata_ignore[18]), .\io_slave_rdata[19] (io_slave_rdata_ignore[19]),
        .\io_slave_rdata[20] (io_slave_rdata_ignore[20]), .\io_slave_rdata[21] (io_slave_rdata_ignore[21]), .\io_slave_rdata[22] (io_slave_rdata_ignore[22]), .\io_slave_rdata[23] (io_slave_rdata_ignore[23]),
        .\io_slave_rdata[24] (io_slave_rdata_ignore[24]), .\io_slave_rdata[25] (io_slave_rdata_ignore[25]), .\io_slave_rdata[26] (io_slave_rdata_ignore[26]), .\io_slave_rdata[27] (io_slave_rdata_ignore[27]),
        .\io_slave_rdata[28] (io_slave_rdata_ignore[28]), .\io_slave_rdata[29] (io_slave_rdata_ignore[29]), .\io_slave_rdata[30] (io_slave_rdata_ignore[30]), .\io_slave_rdata[31] (io_slave_rdata_ignore[31]),
      
        // Slave RID[3:0] -> to ignore wires
        .\io_slave_rid[0] (io_slave_rid_ignore[0]), .\io_slave_rid[1] (io_slave_rid_ignore[1]),
        .\io_slave_rid[2] (io_slave_rid_ignore[2]), .\io_slave_rid[3] (io_slave_rid_ignore[3])
      );



      // ebreak 检测逻辑
always @(posedge clk) begin
    if (!reset) begin
        // 检测 ebreak 指令 (0x00100073)

       // $display("Final instruction: 0x%08h", pmem_rdata);
     if (pmem_rdata == 32'h00100073) begin
            $display("==========================================");
            $display("EBREAK detected! Program execution completed.");
            $display("Time: %t", $time);
            $display("Final instruction: 0x%08h", pmem_rdata);
            $display("=======================================6666===");
            #100; // 等待几个时钟周期
            $finish;
        end
        /*if (pmem_rdata == 32'h00100073) begin
            $display("==========================================");
            $display("EBREAK detected! Program execution completed.");
            $display("Time: %t", $time);
            $display("Final instruction: 0x%08h", pmem_rdata);
            $display("==========================================");
            #100; // 等待几个时钟周期
            $finish;
        end*/
    end
end


/*
    // u_npc 实例化
ysyx_24090012 u_npc (
        .clk(clk),
        .reset(reset),
        .io_interrupt(io_interrupt),

        // AXI4 Master Interface (NPC -> PMEM)
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
        .io_master_rid(pmem_rid),

        // AXI4 Slave Interface (忽略连接，连接常量或忽略线)

        // **输出端口** 必须连接到 wire
        .io_slave_awready(io_slave_awready_ignore), // 修正 Line 56
        // **输入端口** 可直接连常量
        .io_slave_awvalid(1'b0),
        .io_slave_awaddr(32'b0),
        .io_slave_awid(4'b0),
        .io_slave_awlen(8'b0),
        .io_slave_awsize(3'b0),
        .io_slave_awburst(2'b0),

        // **输出端口** 必须连接到 wire
        .io_slave_wready(io_slave_wready_ignore), // 修正 Line 63
        // **输入端口** 可直接连常量
        .io_slave_wvalid(1'b0),
        .io_slave_wdata(32'b0),
        .io_slave_wstrb(4'b0),
        .io_slave_wlast(1'b0),
        .io_slave_bready(1'b0),

        // **输出端口** 必须连接到 wire
        .io_slave_bvalid(io_slave_bvalid_ignore),
        .io_slave_bresp(io_slave_bresp_ignore),
        .io_slave_bid(io_slave_bid_ignore),

        // **输出端口** 必须连接到 wire
        .io_slave_arready(io_slave_arready_ignore), // 修正 Line 72
        // **输入端口** 可直接连常量
        .io_slave_arvalid(1'b0),
        .io_slave_araddr(32'b0),
        .io_slave_arid(4'b0),
        .io_slave_arlen(8'b0),
        .io_slave_arsize(3'b0),
        .io_slave_arburst(2'b0),

        // **输入端口** 可直接连常量
        .io_slave_rready(1'b0),
        // **输出端口** 必须连接到 wire
        .io_slave_rvalid(io_slave_rvalid_ignore),
        .io_slave_rresp(io_slave_rresp_ignore),
        .io_slave_rdata(io_slave_rdata_ignore),
        .io_slave_rlast(io_slave_rlast_ignore),
        .io_slave_rid(io_slave_rid_ignore)
    );
*/
    // u_pmem instance with named ports
    pmem u_pmem (
        .clk(clk),
        .reset(reset),

        // 连接 AXI Master 信号
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
    #100000000 $finish;
    end

    initial begin
       // $dumpfile("wave.vcd");
      //  $dumpvars(0, testbench);
    end
endmodule