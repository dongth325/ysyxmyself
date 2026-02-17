`timescale 1ns / 1ps

module ysyx_24090014;
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

module ysyx_24090012_RegisterFile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
  input clock,
  input reset,
  input [31:0] next_pc,
  output reg [31:0] pc,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
 // input [ADDR_WIDTH-1:0] waddr,
  input [DATA_WIDTH-1:0] wdata,

  output wire [31:0] wbu_hazard_result,
  //input wen,
  input [31:0] lsu_to_wbu_inst,
  output wire [31:0] data_hazard_wbu_inst,
  input  rd_valid, // 来自EXU的写请求
  output   rd_ready,  // 写就绪信号 
  output [DATA_WIDTH-1:0] rdata1,
  output [DATA_WIDTH-1:0] rdata2,
  input [63:0] num,
  input [31:0] sim_lsu_addr,//lsu传来用于仿真环境判断读写访问地址是否跳过difftest
  output reg instr_completed,  // 新增：指令完成标志
  output reg [63:0] wbu_back_to_idu_num,
  output wire [63:0] wbu_reg_num  
);
 

  reg [DATA_WIDTH-1:0] rf [15:0];
  
  // 状态定义
  localparam IDLE = 1'b0;    // 空闲状态，等待写请求
  localparam WRITE = 1'b1;   // 写入状态，执行寄存器写入
  
  // 状态寄存器
  reg state, next_state;
  reg [31:0] saved_pc;
  // 保存写请求的寄存器
 // reg [ADDR_WIDTH-1:0] saved_waddr;
 
 // reg saved_wen;
  reg [63:0] num_r;
  reg [DATA_WIDTH-1:0] saved_wdata;
  reg [31:0] saved_sim_lsu_addr;
  reg [31:0] saved_lsu_to_wbu_inst;
  // 读出数据
  assign rdata1 = (raddr1[3:0] == 4'b0) ? 32'b0 : rf[raddr1[3:0]];
  assign rdata2 = (raddr2[3:0] == 4'b0) ? 32'b0 : rf[raddr2[3:0]];


  assign data_hazard_wbu_inst = saved_lsu_to_wbu_inst;

  assign wbu_reg_num = num_r;

  assign wbu_hazard_result = saved_wdata;




  wire [4:0] saved_waddr = saved_lsu_to_wbu_inst[11:7];
  wire [6:0] opcode = saved_lsu_to_wbu_inst[6:0];


  wire saved_wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1110011||
  opcode == 7'b1101111 || opcode == 7'b1100111 || opcode == 7'b0110011 || 
   opcode == 7'b0000011);//流水线流水线流水线
  
  always @(posedge clock or posedge reset) begin
    if (reset) begin
      state <= IDLE;
     
      saved_wdata <= 0;
     
      pc <= 32'h7FFFFFFC;
      num_r <= 64'h0;
      instr_completed <= 1'b0;  
      saved_sim_lsu_addr <= 32'h0;
      saved_lsu_to_wbu_inst <= 32'h0;
    end else begin
      // 状态更新
      state <= next_state;
      
   

      // 数据处理
      if (state == IDLE) begin
        if (rd_valid && rd_ready) begin
          // 保存写请求数据
       
          saved_wdata <= wdata;
        
          saved_pc <= next_pc;
          num_r <= num;
          saved_sim_lsu_addr <= sim_lsu_addr;
          saved_lsu_to_wbu_inst <= lsu_to_wbu_inst;
        end
        instr_completed <= 1'b0;
      end else if (state == WRITE) begin

        pc <= saved_pc;
        // 执行写入操作
        if (saved_wen && saved_waddr[3:0] != 0) begin
          rf[saved_waddr[3:0]] <= saved_wdata;
          if (saved_waddr[3:0] == 4'd2) begin
           // $display(">> WBU: Writing SP (x2) <<");
         // $display(" | PC: %h | INST: %h | WDATA: %h | NUM: %d", saved_pc, saved_lsu_to_wbu_inst, saved_wdata, num_r);
            end
        end


        wbu_back_to_idu_num <= num_r;

            // 在WRITE状态完成时设置指令完成标志
        instr_completed <= 1'b1;
       
      end
    end
  end




  
















assign rd_ready = (state == IDLE);

  
  // 状态机逻辑和数据保存
  always @(*) begin
    // 默认值
    next_state = state;
   
    
    case (state)
      IDLE: begin
       
        // 在IDLE状态，如果有有效的写请求，保存数据并转到WRITE状态
        if (rd_valid && rd_ready) begin
          next_state = WRITE;
        end
      end
      
      WRITE: begin
        // 在WRITE状态，完成写入后返回IDLE状态
        next_state = IDLE;
      end
    endcase
  end
  




endmodule

module pmem (
    input  clk,
    input  reset,

    // AXI Slave (to NPC Master)
    // Write Address
    output reg        io_master_awready,
    input             io_master_awvalid,
    input  [31:0]     io_master_awaddr,
    input  [3:0]      io_master_awid,
    input  [7:0]      io_master_awlen,
    input  [2:0]      io_master_awsize,
    input  [1:0]      io_master_awburst,
    // Write Data
    output reg        io_master_wready,
    input             io_master_wvalid,
    input  [31:0]     io_master_wdata,
    input  [3:0]      io_master_wstrb,
    input             io_master_wlast,
    // Write Resp
    input             io_master_bready,
    output reg        io_master_bvalid,
    output reg [1:0]  io_master_bresp,
    output reg [3:0]  io_master_bid,

    // Read Address
    output reg        io_master_arready,
    input             io_master_arvalid,
    input  [31:0]     io_master_araddr,
    input  [3:0]      io_master_arid,
    input  [7:0]      io_master_arlen,
    input  [2:0]      io_master_arsize,
    input  [1:0]      io_master_arburst,
    // Read Data
    input             io_master_rready,
    output reg        io_master_rvalid,
    output reg [31:0] io_master_rdata, // Master最终拿到的数据 (大端序)
    output reg [1:0]  io_master_rresp,
    output reg        io_master_rlast,
    output reg [3:0]  io_master_rid
);

    // 参数与内存
    parameter MEM_BASE = 32'h80000000;
    parameter MEM_SIZE = 128 * 1024 * 1024 / 4;  // 128MB -> words
    
    reg [31:0] mem [0:MEM_SIZE-1]; // 内存以小端序格式存储数据

    // 写通道状态
    reg [1:0]  w_state;
    reg [31:0] w_addr;
    reg [3:0]  w_id;
    reg [31:0] w_idx;

    // 读通道状态
    reg [1:0]  r_state;
    reg [31:0] r_base_addr;
    reg [3:0]  r_id;
    reg [7:0]  r_len;     // << 新增：用于保存 ARLEN (8位)
    reg [1:0]  r_burst;   // << 新增：用于保存 ARBURST (2位)
    reg [7:0]  r_cnt;     // 使用 8 位计数器，可支持 AXI 标准的最大突发长度 (r_len最大255)
    reg [31:0] r_idx; 
    
    // 用于字节序转换的寄存器
    reg [31:0] r_data_le; // 从mem中取出的原始小端序数据
    reg [31:0] r_data_be; // 转换后的大端序数据

    integer i;

    // 初始化避免X传播
    initial begin
        for (i = 0; i < MEM_SIZE; i = i + 1) mem[i] = 32'h0;
        
       // $display("INFO: Attempting to load program.hex...");
        $readmemh("build/program.hex", mem);
        $display("INFO: Program load complete.");
        $display("DEBUG: First Instruction (mem[0]) should be: %h", mem[0]); 

        w_state = 0; w_addr = 0; w_id = 0; w_idx = 0;
        r_state = 0; r_base_addr = 0; r_id = 0; r_cnt = 0; r_idx = 0;
        r_len = 8'h0; r_burst = 2'b00; // 初始化新增的寄存器
        
        r_data_le = 32'h0; 
        r_data_be = 32'h0; 

        io_master_awready = 1'b1;
        io_master_wready  = 1'b1;
        io_master_bvalid  = 1'b0;
        io_master_bresp   = 2'b00;
        io_master_bid     = 4'b0;

        io_master_arready = 1'b1;
        io_master_rvalid  = 1'b0;
        io_master_rdata   = 32'h0;
        io_master_rresp   = 2'b00;
        io_master_rlast   = 1'b0;
        io_master_rid     = 4'b0;
    end

    // 写通道：单拍写即可 (保持不变)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            w_state <= 0;
            io_master_awready <= 1'b1;
            io_master_wready  <= 1'b1;
            io_master_bvalid  <= 1'b0;
            io_master_bresp   <= 2'b00;
        end else begin
            case (w_state)
                0: begin
                    if (io_master_awvalid && io_master_awready) begin
                        w_addr          <= io_master_awaddr;
                        w_id            <= io_master_awid;
                        io_master_awready <= 1'b0;
                        w_state         <= 1;
                    end
                end
                1: begin
                    if (io_master_wvalid && io_master_wready) begin
                        if (w_addr >= MEM_BASE && w_addr < MEM_BASE + (MEM_SIZE<<2)) begin
                            w_idx = (w_addr - MEM_BASE) >> 2;
                            
                            if (io_master_wstrb[0]) mem[w_idx][7:0]   <= io_master_wdata[31:24];
                            if (io_master_wstrb[1]) mem[w_idx][15:8]  <= io_master_wdata[23:16];
                            if (io_master_wstrb[2]) mem[w_idx][23:16] <= io_master_wdata[15:8];
                            if (io_master_wstrb[3]) mem[w_idx][31:24] <= io_master_wdata[7:0];
                        end

                         
                       
                        io_master_wready <= 1'b0;
                        io_master_bvalid <= 1'b1;
                        io_master_bresp  <= 2'b00;
                        io_master_bid    <= w_id;
                        w_state          <= 2;
                    end
                   
                end
                2: begin
                    if (io_master_bready) begin
                        io_master_bvalid  <= 1'b0;
                        io_master_awready <= 1'b1;
                        io_master_wready  <= 1'b1;
                        w_state           <= 0;
                    end
                end
                default: w_state <= 0;
            endcase
        end
    end


    // 读通道：动态长度 Burst (RLAST 和 字节序转换)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            // 重置所有寄存器和输出信号
            r_state           <= 0;
            io_master_arready <= 1'b1;  // 默认准备好接收 AR 请求
            io_master_rvalid  <= 1'b0;
            io_master_rlast   <= 1'b0;
            r_cnt             <= 0;
            
            // 新增的 AXI 信号捕获寄存器
            r_len             <= 8'h0;
            r_burst           <= 2'b00; 
            
            // 其它寄存器
            r_data_le         <= 32'h0;
            r_data_be         <= 32'h0;
        end else begin
            // rvalid 信号在状态 1 (数据传输) 期间拉高
            io_master_rvalid <= (r_state == 1); 
            
            case (r_state)
                // 状态 0: 等待 Read 地址请求 (AR)
                0: begin
                    io_master_rlast    <= 1'b0;
                    
                    if (io_master_arvalid && io_master_arready) begin
                        // 1. 捕获地址、ID、突发长度和类型
                        //r_base_addr        <= {io_master_araddr[31:4], 4'b0000}; // 对齐到 16 字节边界
                        r_base_addr        <= io_master_araddr;
                        r_id               <= io_master_arid;
                        r_len              <= io_master_arlen;    // << 捕获突发长度 ARLEN
                        r_burst            <= io_master_arburst;  // << 捕获突发类型 ARBURST
                        r_cnt              <= 0;
                        
                        // 2. 拉低 arready 并进入数据传输状态
                        io_master_arready  <= 1'b0;
                        r_state            <= 1; 
                    end else begin
                        io_master_arready  <= 1'b1; // 保持准备好接收
                    end
                end
                
                // 状态 1: 数据传输 (R)
                1: begin
                    // A. 地址计算：基于 r_base_addr 和 r_cnt
                    // 注意：这里只实现了 INCR 突发逻辑。FIXED 或 WRAP 需要更复杂的逻辑。
                    if (r_burst == 2'b01) begin // INCR 突发类型
                        // r_cnt 代表已经传输了多少拍，r_base_addr 是起始地址
                        r_idx = ((r_base_addr - MEM_BASE) >> 2) + r_cnt;
                    end else begin 
                        // 简单处理：对于非 INCR 类型，地址不递增，只取首地址数据
                        r_idx = (r_base_addr - MEM_BASE) >> 2; 
                    end

                    // B. 数据获取 (小端序)
                    if (r_base_addr >= MEM_BASE && r_base_addr < MEM_BASE + (MEM_SIZE<<2)) begin
                        r_data_le <= mem[r_idx];
                    end else begin
                        r_data_le <= 32'h0; // 地址越界返回 0
                    end
                    
                    // C. 大小端转换并输出 (从机通常输出大端序数据)
                    // 注意：这里直接使用了 mem[r_idx] 的组合逻辑输出，但 r_data_le 和 r_data_be 
                    // 寄存器通常用于流水线操作。为简化和避免可能的时序问题，**直接使用 mem[r_idx]**
                    // 进行组合逻辑输出，但这里我们沿用你的寄存器方式，需要在下一拍生效。
                    io_master_rdata  <= {
                        mem[r_idx][7:0],    // 原始 Byte 0 (最低地址) 变为最高位
                        mem[r_idx][15:8],   // 原始 Byte 1 
                        mem[r_idx][23:16],  // 原始 Byte 2
                        mem[r_idx][31:24]   // 原始 Byte 3 (最高地址) 变为最低位
                    };
                    
                    // D. 状态输出
                    io_master_rresp <= 2'b00; // OKAYAY 响应
                    io_master_rid   <= r_id;
                    
                    // E. 动态判断 RLAST：当传输计数 r_cnt 等于 ARLEN 寄存器 r_len 时，置位 RLAST
                    io_master_rlast <= (r_cnt == r_len); 

                    // F. 状态和计数器更新 (在 rready 握手成功后更新)
                    if (io_master_rready) begin
                        if (r_cnt == r_len) begin // 本次是最后一次传输
                            r_state           <= 0;
                            io_master_arready <= 1'b1; // 重新准备接收新的 AR 请求
                        end else begin
                            r_cnt <= r_cnt + 1; // 递增计数器
                            r_state <= 1;       // 保持在数据传输状态
                        end
                    end 
                end
                
                // 状态 default: 错误恢复
                default: begin
                    r_state           <= 0;
                    io_master_arready <= 1'b1;
                    io_master_rvalid  <= 1'b0;
                    io_master_rlast   <= 1'b0;
                end
            endcase
        end
    end

endmodule


module ysyx_24090012(
    input         clk,          // 综合需要改成clk
    input         reset,          // 改名：rst -> reset
    input         io_interrupt,   // 外部中断信号，永0

    // AXI4 Master Interface
    input         io_master_awready,
    output        io_master_awvalid,
    output [31:0] io_master_awaddr,
    output [3:0]  io_master_awid,
    output [7:0]  io_master_awlen,
    output [2:0]  io_master_awsize,
    output [1:0]  io_master_awburst,
    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [3:0]  io_master_wstrb,
    output        io_master_wlast,
    output        io_master_bready,
    input         io_master_bvalid,
    input  [1:0]  io_master_bresp,
    input  [3:0]  io_master_bid,
    input         io_master_arready,
    output        io_master_arvalid,
    output [31:0] io_master_araddr,
    output [3:0]  io_master_arid,
    output [7:0]  io_master_arlen,
    output [2:0]  io_master_arsize,
    output [1:0]  io_master_arburst,
    output        io_master_rready,
    input         io_master_rvalid,
    input  [1:0]  io_master_rresp,
    input  [31:0] io_master_rdata,
    input         io_master_rlast,
    input  [3:0]  io_master_rid,

    // AXI4 Slave Interface
    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [31:0] io_slave_awaddr,
    input  [3:0]  io_slave_awid,
    input  [7:0]  io_slave_awlen,
    input  [2:0]  io_slave_awsize,
    input  [1:0]  io_slave_awburst,
    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [3:0]  io_slave_wstrb,
    input         io_slave_wlast,
    input         io_slave_bready,
    output        io_slave_bvalid,
    output [1:0]  io_slave_bresp,
    output [3:0]  io_slave_bid,
    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [31:0] io_slave_araddr,
    input  [3:0]  io_slave_arid,
    input  [7:0]  io_slave_arlen,
    input  [2:0]  io_slave_arsize,
    input  [1:0]  io_slave_arburst,
    input         io_slave_rready,
    output        io_slave_rvalid,
    output [1:0]  io_slave_rresp,
    output [31:0] io_slave_rdata,
    output        io_slave_rlast,
    output [3:0]  io_slave_rid
);



  assign io_slave_awready = 1'b0;
  assign io_slave_wready = 1'b0;
  assign io_slave_bvalid = 1'b0;
  assign io_slave_bresp = 2'b00;
  assign io_slave_bid = 4'b0;
  assign io_slave_arready = 1'b0;
  assign io_slave_rvalid = 1'b0;
  assign io_slave_rresp = 2'b00;
  assign io_slave_rdata = 32'b0;
  assign io_slave_rlast = 1'b0;
  assign io_slave_rid = 4'b0;



  wire [4:0] rs1, rs2, rd;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [6:0] func7;
  wire [31:0] imm;
  wire [5:0] alu_op;

  wire [31:0] rs1_data, rs2_data, result, next_pc;
  wire wen;
  wire [31:0] inst;

  wire [31:0] pc;

  wire [4:0] wbu_rd;
  wire wbu_rd_wen;
  wire [31:0] wbu_data;
  wire wbu_valid;
  wire wbu_ready;
  wire [31:0] wbu_next_pc;

  wire [11:0] wbu_csr_addr;
  wire [31:0] wbu_csr_wdata;
  wire wbu_csr_wen;

  wire wbu_csr_valid;
  wire wbu_csr_ready;

 wire control_hazard;
 wire [31:0] branch_target_pc;

  wire out_is_ecall;
  wire out_is_mret;


  wire [31:0] rs1_data_out;
  wire [31:0] rs2_data_out;


wire instr_completed;

  wire [31:0] exu_out_pc;
  wire [31:0] lsu_out_pc;

  wire [31:0] idu_to_exu_inst;
  wire [31:0] exu_to_lsu_inst;
  wire [31:0] lsu_to_wbu_inst;
   wire ifu_to_idu_valid;   // IFU向IDU发出的有效信号
   wire idu_to_ifu_ready;
/* verilator lint_off UNOPTFLAT */
   wire idu_to_exu_valid;  // IDU向EXU发出的有效信号
/* verilator lint_on UNOPTFLAT */
   wire exu_to_idu_ready;  // EXU向IDU发出的就绪信号

   wire is_use_lsu;
   wire [4:0] rd_addr_out;
   wire rd_wen_out;

    wire idu_state;  // IDU状态信号
    wire [1:0] exu_state;  // EXU状态信号
    wire [2:0] ifu_state;  // IFU状态信号
    wire [2:0] lsu_state;

    wire [31:0] sim_lsu_addr;



    wire [31:0] data_hazard_exu_inst;
    wire [31:0] data_hazard_lsu_inst;
    wire [31:0] data_hazard_wbu_inst;
   

    // PC更新接口
  // wire if_allow_in = !reset && wbu_ready && idu_state == 1'b0 && exu_state == 2'b00 && ifu_state == 2'b00  && lsu_state == 3'b00;
    wire if_allow_in = 1;  //流水线可以一直取指令

// 使用组合逻辑(wire)实现mem_unsigned
wire mem_unsigned;//将idu解码信息进行判断，传给lsu用于无符号读取指令的逻辑处理




   



    wire [31:0] ifu_to_idu_pc;    // IFU传给IDU的PC
    wire [31:0] idu_to_exu_pc;    // IDU传给EXU的PC
 



        // LSU接口
    wire [31:0] mem_addr;
     // verilator lint_off UNOPTFLAT
    wire        mem_valid;
    // verilator lint_on UNOPTFLAT
    wire [31:0] mem_wdata;
    wire [3:0]  mem_wmask;
    wire        mem_wen;
    // verilator lint_off UNOPTFLAT
    wire        mem_ready;
    // verilator lint_on UNOPTFLAT

    wire [2:0]  mem_arsize;
    wire [2:0]  mem_awsize;


 

wire [63:0] ifu_to_idu_num;//流水线下传
wire [63:0] idu_to_exu_num;
wire [63:0] exu_to_lsu_num;
wire [63:0] lsu_to_wbu_num;
wire [63:0] wbu_back_to_idu_num;


wire [63:0] wbu_reg_num;//冒险上传
wire [63:0] exu_reg_num;
wire [63:0] lsu_reg_num;

wire [31:0] wbu_hazard_result;//冒险上传
wire [31:0] exu_hazard_result;
wire [31:0] lsu_hazard_result;

 
    wire [31:0] rd_data;

    wire        rd_wen;



wire [11:0] out_csr_addr;
wire out_csr_wen;

wire [11:0] csr_addr;
wire [31:0] csr_wdata;

wire csr_wen;



wire is_ecall;
wire is_mret;
wire [31:0] csr_rdata;
wire [31:0] mstatus;
wire [31:0] mtvec;
wire [31:0] mepc;
wire [31:0] mcause;
wire [31:0] mvendorid;
wire [31:0] marchid;
// LSU到arbiter的接口线
wire        lsu_awvalid;
wire        lsu_awready;
wire [31:0] lsu_awaddr;
wire [3:0]  lsu_awid;
wire [7:0]  lsu_awlen;
wire [2:0]  lsu_awsize;
wire [1:0]  lsu_awburst;
wire        lsu_wvalid;
wire        lsu_wready;
wire [31:0] lsu_wdata;
wire [3:0]  lsu_wstrb;
wire        lsu_wlast;
wire        lsu_bready;
wire        lsu_bvalid;
wire [1:0]  lsu_bresp;
wire [3:0]  lsu_bid;
wire        lsu_arvalid;
wire        lsu_arready;
wire [31:0] lsu_araddr;
wire [3:0]  lsu_arid;
wire [7:0]  lsu_arlen;
wire [2:0]  lsu_arsize;
wire [1:0]  lsu_arburst;
wire        lsu_rready;
// verilator lint_off UNOPTFLAT
wire        lsu_rvalid;
// verilator lint_on UNOPTFLAT

// verilator lint_off UNOPTFLAT
wire [1:0]  lsu_rresp;
// verilator lint_on UNOPTFLAT
wire [31:0] lsu_rdata;
wire        lsu_rlast;
wire [3:0]  lsu_rid;



// IFU到arbiter的接口线
wire        ifu_arvalid;
wire        ifu_arready;
wire [31:0] ifu_araddr;
wire [3:0]  ifu_arid;
wire [7:0]  ifu_arlen;
wire [2:0]  ifu_arsize;
wire [1:0]  ifu_arburst;
wire        ifu_rready;
wire        ifu_rvalid;
wire [1:0]  ifu_rresp;
wire [31:0] ifu_rdata;
wire        ifu_rlast;
wire [3:0]  ifu_rid;










// CLINT地址范围定义
localparam CLINT_BASE = 32'ha000_0000;
localparam CLINT_SIZE = 32'h0001_0000;  // 64KB空间

// 从arbiter获取的原始arvalid信号
wire        arbiter_arvalid;
wire [31:0] arbiter_araddr;
wire [3:0]  arbiter_arid;
wire [7:0]  arbiter_arlen;
wire [2:0]  arbiter_arsize;
wire [1:0]  arbiter_arburst;
wire        arbiter_rready;

// 判断地址是否在CLINT范围内
wire is_clint_addr = (io_master_araddr >= CLINT_BASE) && (io_master_araddr < CLINT_BASE + CLINT_SIZE);

// 判断是否访问CLINT - 只处理读请求
wire is_clint_read = arbiter_arvalid && is_clint_addr;

// CLINT AXI4-Lite接口信号
wire        clint_arvalid;
wire        clint_arready;
wire [31:0] clint_araddr;
wire        clint_rvalid;
wire        clint_rready;
wire [31:0] clint_rdata;
wire [1:0]  clint_rresp;

// 连接CLINT接口
assign clint_arvalid = arbiter_arvalid && is_clint_addr;
assign clint_araddr = io_master_araddr;
assign clint_rready = io_master_rready;

// 连接到外部设备的信号
assign io_master_arvalid = arbiter_arvalid && !is_clint_addr;//如果不是clint地址，就不发送到外部，不确定这一个信号能否全部阻塞
assign io_master_araddr = arbiter_araddr;
assign io_master_arid = arbiter_arid;
assign io_master_arlen = arbiter_arlen;
assign io_master_arsize = arbiter_arsize;
assign io_master_arburst = arbiter_arburst;
assign io_master_rready = arbiter_rready;

// 返回给arbiter的信号
// verilator lint_off UNOPTFLAT
wire        arbiter_arready = is_clint_addr ? clint_arready : io_master_arready;
// verilator lint_on UNOPTFLAT
wire        arbiter_rvalid = is_clint_addr ? clint_rvalid : io_master_rvalid;
wire [1:0]  arbiter_rresp = is_clint_addr ? clint_rresp : io_master_rresp;
wire [31:0] arbiter_rdata = is_clint_addr ? clint_rdata : io_master_rdata;
wire        arbiter_rlast = is_clint_addr ? 1'b1 : io_master_rlast;  //对于clint直接返回1
wire [3:0]  arbiter_rid = is_clint_addr ? arbiter_arid : io_master_rid;  // 对于CLINT，使用请求ID作为响应ID
//id原路返回，不确定实现流水线后是否正确

ysyx_24090012_CLINT clint_inst (
    .clk           (clk),
    .rst           (reset),
    .s_axi_arvalid (clint_arvalid),
    .s_axi_arready (clint_arready),
    .s_axi_araddr  (clint_araddr),
    .s_axi_rvalid  (clint_rvalid),
    .s_axi_rready  (clint_rready),
    .s_axi_rdata   (clint_rdata),
    .s_axi_rresp   (clint_rresp)
);


// 实例化arbiter
ysyx_24090012_arbiter arbiter(
    .clk(clk),
    .rst(reset),

    // LSU Master Interface
    .lsu_awvalid(lsu_awvalid),
    .lsu_awready(lsu_awready),
    .lsu_awaddr(lsu_awaddr),
    .lsu_awid(lsu_awid),
    .lsu_awlen(lsu_awlen),
    .lsu_awsize(lsu_awsize),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid),
    .lsu_wready(lsu_wready),
    .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb),
    .lsu_wlast(lsu_wlast),
    .lsu_bready(lsu_bready),
    .lsu_bvalid(lsu_bvalid),
    .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid),
    .lsu_arvalid(lsu_arvalid),
    .lsu_arready(lsu_arready),
    .lsu_araddr(lsu_araddr),
    .lsu_arid(lsu_arid),
    .lsu_arlen(lsu_arlen),
    .lsu_arsize(lsu_arsize),
    .lsu_arburst(lsu_arburst),
    .lsu_rready(lsu_rready),
    .lsu_rvalid(lsu_rvalid),
    .lsu_rresp(lsu_rresp),
    .lsu_rdata(lsu_rdata),
    .lsu_rlast(lsu_rlast),
    .lsu_rid(lsu_rid),

        // IFU Master Interface
    .ifu_arvalid(ifu_arvalid),
    .ifu_arready(ifu_arready),
    .ifu_araddr(ifu_araddr),
    .ifu_arid(ifu_arid),
    .ifu_arlen(ifu_arlen),
    .ifu_arsize(ifu_arsize),
    .ifu_arburst(ifu_arburst),
    .ifu_rready(ifu_rready),
    .ifu_rvalid(ifu_rvalid),
    .ifu_rresp(ifu_rresp),
    .ifu_rdata(ifu_rdata),
    .ifu_rlast(ifu_rlast),
    .ifu_rid(ifu_rid),

    // AXI4 Slave Interface (to memory)
    .io_master_awvalid(io_master_awvalid),
    .io_master_awready(io_master_awready),
    .io_master_awaddr(io_master_awaddr),
    .io_master_awid(io_master_awid),
    .io_master_awlen(io_master_awlen),
    .io_master_awsize(io_master_awsize),
    .io_master_awburst(io_master_awburst),
    .io_master_wvalid(io_master_wvalid),
    .io_master_wready(io_master_wready),
    .io_master_wdata(io_master_wdata),
    .io_master_wstrb(io_master_wstrb),
    .io_master_wlast(io_master_wlast),
    .io_master_bready(io_master_bready),
    .io_master_bvalid(io_master_bvalid),
    .io_master_bresp(io_master_bresp),
    .io_master_bid(io_master_bid),
   // .io_master_arvalid(io_master_arvalid),
   // .io_master_arready(io_master_arready),
  //  .io_master_araddr(io_master_araddr),
 //  .io_master_arid(io_master_arid),
   // .io_master_arlen(io_master_arlen),
   // .io_master_arsize(io_master_arsize),
   // .io_master_arburst(io_master_arburst),
  //  .io_master_rready(io_master_rready),
   // .io_master_rvalid(io_master_rvalid),
   // .io_master_rresp(io_master_rresp),
   // .io_master_rdata(io_master_rdata),
    //.io_master_rlast(io_master_rlast),
    //.io_master_rid(io_master_rid)
    .io_master_arvalid(arbiter_arvalid),
    .io_master_arready(arbiter_arready),
    .io_master_araddr(arbiter_araddr),
    .io_master_arid(arbiter_arid),
    .io_master_arlen(arbiter_arlen),
    .io_master_arsize(arbiter_arsize),
    .io_master_arburst(arbiter_arburst),
    .io_master_rready(arbiter_rready),
    .io_master_rvalid(arbiter_rvalid),
    .io_master_rresp(arbiter_rresp),
    .io_master_rdata(arbiter_rdata),
    .io_master_rlast(arbiter_rlast),
    .io_master_rid(arbiter_rid)
);




  // 实例化各个模块
  ysyx_24090012_IFU ifu(
    .clock(clk),
    .reset(reset),
    .state_out(ifu_state),
        // Control Interface
    .if_allow_in(if_allow_in),    // 暂时设为常开
    .if_next_pc(pc),
    
    // IDU Interface
    .idu_ready(idu_to_ifu_ready),//与idu握手信号和信息传输
    .idu_valid(ifu_to_idu_valid),
    .idu_pc(ifu_to_idu_pc),
    .idu_inst(inst),

    .control_hazard(control_hazard),
    .branch_target_pc(branch_target_pc),

    // AXI4 Interface
    .io_master_arready(ifu_arready),
    .io_master_arvalid(ifu_arvalid),
    .io_master_araddr(ifu_araddr),
    .io_master_arid(ifu_arid),
    .io_master_arlen(ifu_arlen),
    .io_master_arsize(ifu_arsize),
    .io_master_arburst(ifu_arburst),
    .io_master_rvalid(ifu_rvalid),
    .io_master_rdata(ifu_rdata),
    .io_master_rid(ifu_rid),
    .io_master_rlast(ifu_rlast),
    .io_master_rresp(ifu_rresp),
    .io_master_rready(ifu_rready),
    .num(ifu_to_idu_num)
);
 // 修改IDU实例化
ysyx_24090012_IDU idu(
    .clock(clk),
    .reset(reset),
      .ifu_to_idu_pc(ifu_to_idu_pc),  // 从IFU来的PC
      .idu_to_exu_pc(idu_to_exu_pc),  // 输出到EXU的PC
    // IFU Interface
    .ifu_ready(idu_to_ifu_ready),    // output: 告诉IFU是否准备好接收新指令
    .ifu_valid(ifu_to_idu_valid),    // input: IFU提供的指令是否有效
    .rs1_data(rs1_data),
    .rs2_data(rs2_data),


    .data_hazard_exu_inst(data_hazard_exu_inst),
    .data_hazard_lsu_inst(data_hazard_lsu_inst),
    .data_hazard_wbu_inst(data_hazard_wbu_inst),


    .exu_hazard_result(exu_hazard_result),
    .lsu_hazard_result(lsu_hazard_result),
    .wbu_hazard_result(wbu_hazard_result),
    // EXU Interface
    .exu_ready(exu_to_idu_ready),    // input: EXU是否准备好接收新指令
    .exu_valid(idu_to_exu_valid),    // output: 向EXU提供的指令是否有效
    
    .csr_addr(csr_addr),
   
    .rs1_data_out(rs1_data_out),
    .rs2_data_out(rs2_data_out),
    .wbu_reg_num(wbu_reg_num),
    .lsu_reg_num(lsu_reg_num),
    .exu_reg_num(exu_reg_num),

    .exu_next_pc(next_pc),
    .control_hazard(control_hazard),
    .branch_target_pc(branch_target_pc),
    // Instruction Information
    .inst(inst),              // input: 指令

    .idu_to_exu_inst(idu_to_exu_inst),
    
    .state_out(idu_state),  // 连接状态输出
    // Decoded Information
    .rs1(rs1),               // output
    .rs2(rs2),               // output
    .rd(rd),                 // output
    .imm(imm),               // output
    .opcode(opcode),         // output
    .func3(func3),           // output
    .func7(func7),           // output
    .alu_op(alu_op),         // output
    .rd_wen(rd_wen),      // output
    .num(ifu_to_idu_num),
    .num_r(idu_to_exu_num),
    .wbu_num(wbu_back_to_idu_num)
  
);
  ysyx_24090012_RegisterFile regfile(

    .lsu_to_wbu_inst(lsu_to_wbu_inst),
    .next_pc(wbu_next_pc),
    .clock(clk),
    .pc(pc),
    .reset(reset),
    .raddr1(rs1),
    .raddr2(rs2),
    //.waddr(wbu_rd),
    .wdata(wbu_data),
   // .wen(wbu_rd_wen),
          .rd_valid(wbu_valid),
        .rd_ready(wbu_ready),


        .wbu_hazard_result(wbu_hazard_result),

        .data_hazard_wbu_inst(data_hazard_wbu_inst),

        .wbu_reg_num(wbu_reg_num),
   
    .sim_lsu_addr(sim_lsu_addr),
   

    .rdata1(rs1_data),
    .rdata2(rs2_data),
    .num(lsu_to_wbu_num),
    .wbu_back_to_idu_num(wbu_back_to_idu_num),
    .instr_completed(instr_completed)
    
    );





  
  ysyx_24090012_EXU exu(
    .rst(reset),
    .clk(clk),

  .pc(idu_to_exu_pc),
  .rs1_data(rs1_data_out),
  .rs2_data(rs2_data_out),  // 添加 rs2_data 连接
  .imm(imm),

  .out_pc(exu_out_pc),
  .alu_op(alu_op),
   .state_out(exu_state),

   .exu_reg_num(exu_reg_num),

   .exu_hazard_result(exu_hazard_result),

   .data_hazard_exu_inst(data_hazard_exu_inst),

 //  .is_use_lsu(is_use_lsu),

  .idu_valid(idu_to_exu_valid),
  .idu_ready(exu_to_idu_ready),

  .idu_to_exu_inst(idu_to_exu_inst),
  .exu_to_lsu_inst(exu_to_lsu_inst),
          // LSU接口
        .mem_addr(mem_addr),
        .mem_valid(mem_valid),
        .mem_wdata(mem_wdata),
      
       
        .mem_ready(mem_ready),
      
   
                // RegisterFile写回接口
       
        .rd_data(rd_data),

       

 
        // PC更新接口
       

  
    .mtvec(mtvec),
   
    .mepc(mepc),

   

  
  .next_pc(next_pc),
   .csr_rdata(csr_rdata),

   .csr_addr(csr_addr),
   .csr_wen(csr_wen),

    .csr_wdata(csr_wdata),
   
    .out_csr_addr(out_csr_addr),
    .out_csr_wen(out_csr_wen),
     
   

      .num(idu_to_exu_num),
      .num_r(exu_to_lsu_num)
       
);




   ysyx_24090012_CSR csr(
  
  .wbu_csr_valid(wbu_csr_valid),
  .wbu_csr_ready(wbu_csr_ready),
  .pc(lsu_out_pc),
  .clk(clk),
  .rst(reset),
  .csr_addr(csr_addr),

  .csr_wdata(wbu_csr_wdata),
 
  .lsu_to_wbu_inst(lsu_to_wbu_inst),
  .csr_rdata(csr_rdata),
  .mstatus(mstatus),
  .mtvec(mtvec),
  .mepc(mepc),
  .mcause(mcause),
  .mvendorid(mvendorid),
  .marchid(marchid)
);

    // 实例化LSU
    ysyx_24090012_LSU lsu(
    .clock(clk),
    .reset(reset),
     .next_pc(next_pc),
   // .mem_unsigned(mem_unsigned),  // 无符号处理flag 
    .state_out(lsu_state),
    // EXU Interface
    .mem_addr(mem_addr),
    .mem_valid(mem_valid),
    .mem_wdata(mem_wdata),

    .lsu_hazard_result(lsu_hazard_result),



    .lsu_reg_num(lsu_reg_num),
  


    .data_hazard_lsu_inst(data_hazard_lsu_inst),
  //  .mem_wen(mem_wen),
    .mem_ready(mem_ready),

    .lsu_in_pc(exu_out_pc),
    .lsu_out_pc(lsu_out_pc),

   // .mem_arsize(mem_arsize),
   // .mem_awsize(mem_awsize),

    //.is_ecall(is_ecall),
   // .is_mret(is_mret),
   // .out_is_ecall(out_is_ecall),
   // .out_is_mret(out_is_mret),
   
   // .mem_rd(rd_addr_out),
   // .mem_rd_wen(rd_wen_out),
    .mem_result(rd_data),
   // .is_use_lsu(is_use_lsu),

    //.wbu_rd(wbu_rd),
    //.wbu_rd_wen(wbu_rd_wen),
    .wbu_data(wbu_data),

    .wbu_valid(wbu_valid),
    .wbu_ready(wbu_ready),
    .wbu_next_pc(wbu_next_pc),

    .num(exu_to_lsu_num),
    .num_r(lsu_to_wbu_num),

    //.csr_addr(out_csr_addr),
    .csr_wdata(csr_wdata),
   // .csr_wen(out_csr_wen),

    .exu_to_lsu_inst(exu_to_lsu_inst),
    .lsu_to_wbu_inst(lsu_to_wbu_inst),

   // .wbu_csr_addr(wbu_csr_addr),
    .wbu_csr_wdata(wbu_csr_wdata),
   // .wbu_csr_wen(wbu_csr_wen),

    .wbu_csr_valid(wbu_csr_valid),
    .wbu_csr_ready(wbu_csr_ready),

    .sim_lsu_addr(sim_lsu_addr),

    // AXI4 Interface
    .io_master_awready(lsu_awready),
    .io_master_awvalid(lsu_awvalid),
    .io_master_awaddr(lsu_awaddr),
    .io_master_awid(lsu_awid),
    .io_master_awlen(lsu_awlen),
    .io_master_awsize(lsu_awsize),
    .io_master_awburst(lsu_awburst),
    .io_master_wready(lsu_wready),
    .io_master_wvalid(lsu_wvalid),
    .io_master_wdata(lsu_wdata),
    .io_master_wstrb(lsu_wstrb),
    .io_master_wlast(lsu_wlast),
    .io_master_bready(lsu_bready),
    .io_master_bvalid(lsu_bvalid),
    .io_master_bresp(lsu_bresp),
    .io_master_bid(lsu_bid),
    .io_master_arready(lsu_arready),
    .io_master_arvalid(lsu_arvalid),
    .io_master_araddr(lsu_araddr),
    .io_master_arid(lsu_arid),
    .io_master_arlen(lsu_arlen),
    .io_master_arsize(lsu_arsize),
    .io_master_arburst(lsu_arburst),
    .io_master_rready(lsu_rready),
    .io_master_rvalid(lsu_rvalid),
    .io_master_rdata(lsu_rdata),
    .io_master_rresp(lsu_rresp),
    .io_master_rid(lsu_rid)
    );


    always @(posedge clk) begin// 更新 PC
      if (inst == 32'h00100073 && ifu_to_idu_valid == 1) begin  // ebreak 指令  用于没有cache的ifu，如果不加这个判断会在bootloader取到ebreak就会停止仿真
           // $display("pc = 0x%08x from NPC", pc);
           // $display("inst = 0x%08x from NPC",inst);
           // $display("HIT GOOD TRAP");
         // ebreak(regfile.rf[10]);       // 调用 DPI-C 函数     综合需要注释
        end 
      end





endmodule



module ysyx_24090012_LSU (
    input wire         clock,
    input wire         reset,
    output reg [2:0] state_out,   //换成wire
  
   // input   mem_unsigned,

    input [31:0] lsu_in_pc,
    output  [31:0] lsu_out_pc,   //不清楚是否需要，或许可以去掉

    // EXU Interface (slave)
    input  wire [31:0] mem_addr,
    input  wire        mem_valid,
    input  wire [31:0] mem_wdata,

    output          mem_ready,

    output wire [31:0] data_hazard_lsu_inst,
    output wire [31:0]  lsu_hazard_result,

    input [31:0] mem_result,    // 流水线流水线流水线
    input wire [31:0] next_pc,

    output [31:0] wbu_data,    // 流水线流水线流水线

    input [31:0] csr_wdata,
 
    output [31:0] wbu_csr_wdata,
    input [31:0] exu_to_lsu_inst,
    output [31:0] lsu_to_wbu_inst,
 
    output     wbu_csr_valid,
    input        wbu_csr_ready,

    output     wbu_valid,   // 流水线流水线流水线
    input         wbu_ready,   // 流水线流水线流水线
    output [31:0] wbu_next_pc, // 流水线流水线流水线

    output wire [63:0] lsu_reg_num,


    input [63:0] num,
    output reg [63:0] num_r,

    output reg [31:0] sim_lsu_addr,//用于流水线仿真环境取出写入地址判断是否跳过difftest


    // AXI4 Master Interface
    // Write Address Channel
    input  wire        io_master_awready,
    output          io_master_awvalid,
    output   [31:0] io_master_awaddr,
    output   [3:0]  io_master_awid,     // 传递事务ID
    output   [7:0]  io_master_awlen,
    output   [2:0]  io_master_awsize,
    output   [1:0]  io_master_awburst,

    // Write Data Channel
    input  wire        io_master_wready,
    output          io_master_wvalid,
    output reg  [31:0] io_master_wdata,
    output reg  [3:0]  io_master_wstrb,
    output          io_master_wlast,     // 单次传输永远为1

    // Write Response Channel
    output          io_master_bready,
    input  wire        io_master_bvalid,
    input  wire [1:0]  io_master_bresp,    // 写响应状态
    input  wire [3:0]  io_master_bid,      // 写响应ID

    // Read Address Channel
    input  wire        io_master_arready,
    output          io_master_arvalid,
    output   [31:0] io_master_araddr,
    output   [3:0]  io_master_arid,     // 传递事务ID
    output   [7:0]  io_master_arlen,
    output   [2:0]  io_master_arsize,
    output   [1:0]  io_master_arburst,

    // Read Data Channel
    output          io_master_rready,
    input  wire        io_master_rvalid,
    input  wire [31:0] io_master_rdata,
    input  wire [1:0]  io_master_rresp,    // 读响应状态
    input  wire [3:0]  io_master_rid       // 读响应ID
);

    // 状态定义
    localparam IDLE        = 3'd0;
    localparam WRITE_ADDR  = 3'd1;
    localparam WRITE_DATA  = 3'd2;
    localparam WRITE_RESP  = 3'd3;
    localparam READ_ADDR   = 3'd4;
    localparam READ_DATA   = 3'd5;
    localparam WBU_WAIT    = 3'd6;
    localparam SAVE_STATE  = 3'd7; 


    //reg [31:0] exu_to_lsu_inst_r;
    reg [31:0] exu_to_lsu_inst_r = 32'h00000000;

    // 寄存器定义
    //reg [2:0] state;
    reg [2:0] state = IDLE;
   // reg [31:0] saved_addr;//读写地址
    reg [31:0] saved_addr = 32'h00000000;
    //reg [31:0] saved_wdata;
    reg [31:0] saved_wdata = 32'h00000000;
    
     // 组合逻辑：状态转换和控制信号生成
    reg [2:0] next_state;
    reg [31:0] processed_rdata;//用于对读出数据进行寄存，最后赋值给mem rdata

  //  reg [3:0]  curr_id;    // 当前事务ID
    reg [3:0]  curr_id = 4'h0;
  
   // reg [4:0]  saved_rd;//流水线流水线流水线
   // reg        saved_rd_wen;//流水线流水线流水线
    reg [31:0] saved_result;//流水线流水线流水线    
 
    reg [31:0] saved_next_pc;
   

   //reg  [31:0] saved_pc;
    reg [31:0] saved_pc = 32'h00000000; // 初始PC值 是30000000 - 4.为了下面默认saved pc = saved pc +4初始值

  
 
    //reg [11:0] saved_csr_addr;
    reg [31:0] saved_csr_wdata;
    //reg saved_csr_wen;

    reg [31:0] lsu_count;          // LSU总操作计数器
    reg [31:0] read_count;         // 读操作计数器
    reg [31:0] write_count;        // 写操作计数器


assign lsu_to_wbu_inst = exu_to_lsu_inst_r;
assign data_hazard_lsu_inst = exu_to_lsu_inst_r;

assign lsu_hazard_result = saved_result;

assign lsu_reg_num = num_r;

wire [6:0] opcode = exu_to_lsu_inst_r[6:0];
wire [2:0] func3 = exu_to_lsu_inst_r[14:12];


wire saved_mem_unsigned = 
    (opcode == 7'b0000011 && func3 == 3'b100) || // LBU
    (opcode == 7'b0000011 && func3 == 3'b101);   // LHU

wire saved_is_use_lsu = (opcode == 7'b0000011) || (opcode == 7'b0100011);  
wire saved_wen = (opcode == 7'b0100011);


   wire [2:0] saved_arsize = 
    (opcode == 7'b0000011 && (func3 == 3'b000 || func3 == 3'b100)) ? 3'b000 :  // LB/LBU
    (opcode == 7'b0000011 && (func3 == 3'b001 || func3 == 3'b101)) ? 3'b001 :  // LH/LHU
    (opcode == 7'b0000011 && func3 == 3'b010) ? 3'b010 :                       // LW
    3'b000;      

    wire [2:0] saved_awsize = 
    (opcode == 7'b0100011 && func3 == 3'b000) ? 3'b000 :  // SB
    (opcode == 7'b0100011 && func3 == 3'b001) ? 3'b001 :  // SH
    (opcode == 7'b0100011 && func3 == 3'b010) ? 3'b010 :  // SW
    3'b000;     




always @(posedge clock) begin
    // 写响应检测
    if (io_master_bresp != 2'b00) begin
      /*  $display("LSU error! bid expected: %h, received: %h, bresp: %b inst = %h from lsu.v line:169 num = %h", 
                curr_id, 
                io_master_bid, 
                io_master_bresp,
                exu_to_lsu_inst_r,
                num_r);  */   //综合需要注释
    end
    
    // 读响应检测
    if (io_master_rresp != 2'b00) begin
      /*  $display("LSU read ID wrong! curr_id: %h, rid: %h, rresp: %b inst = %h from lsu.v line:179 num = %h",
                curr_id,
                io_master_rid,
                io_master_rresp,
                exu_to_lsu_inst_r,
                num_r);   *///综合需要注释
    end
end


    // 时序逻辑：状态更新和数据保存
    always @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;

            lsu_count <= 32'h0;
            read_count <= 32'h0;
            write_count <= 32'h0;
            num_r <= 64'h0;

        end else begin
            // 在IDLE状态且有新请求时保存数据
            if (state == IDLE && mem_valid) begin
                saved_addr <= mem_addr;//读写地址
                saved_wdata <= mem_wdata;//写数据
             
              
              
                curr_id <= curr_id + 4'h1;  // 递增事务ID
             
                saved_result <= mem_result;   
             
                saved_next_pc <= next_pc;
               
                saved_csr_wdata <= csr_wdata;
                saved_pc <= lsu_in_pc;//                           不确定是否需要
            
                num_r <= num;
                exu_to_lsu_inst_r <= exu_to_lsu_inst;
            end

   // 更新计数器 - 当读操作完成时
            if (state == READ_DATA && next_state == IDLE) begin
                read_count <= read_count + 1;
                lsu_count <= lsu_count + 1;
            end
            
            // 更新计数器 - 当写操作完成时
            if (state == WRITE_RESP && next_state == IDLE) begin
                write_count <= write_count + 1;
                lsu_count <= lsu_count + 1;
            end

            if (state == READ_DATA && io_master_rvalid && io_master_rresp == 2'b00) begin
                saved_result <= processed_rdata;
            end

            state <= next_state;
        end
    end

   assign mem_ready = (state == IDLE);
   assign wbu_valid = (state == WBU_WAIT);
   assign wbu_csr_valid = (state == WBU_WAIT);
   assign  lsu_out_pc = saved_pc;

   assign io_master_awvalid = (state == WRITE_ADDR);
   assign io_master_awaddr = saved_addr;
   assign io_master_araddr = saved_addr;
   assign io_master_awsize = saved_awsize;
   assign io_master_arsize = saved_arsize;
   assign io_master_awlen = 8'b0;
   assign io_master_arlen = 8'b0;
   assign io_master_awid = curr_id;
   assign io_master_arid = curr_id;
   assign io_master_awburst = 2'b01;
   assign io_master_arburst = 2'b01;
   assign io_master_wvalid = (state == WRITE_DATA);
   assign io_master_wlast = 1'b1;//单次传输为1
   assign io_master_bready = (state == WRITE_RESP);
   assign io_master_rready = (state == READ_DATA);
   assign io_master_arvalid = (state == READ_ADDR);

   assign wbu_data = saved_result;//流水线流水线流水线
   assign wbu_next_pc = saved_next_pc;

   assign wbu_csr_wdata = saved_csr_wdata;
  

    always @(*) begin

      state_out = state;

        // 默认值
        next_state = state;




   

       sim_lsu_addr = saved_addr;
      
        
        // 状态转换和控制信号生成
        case (state)
            IDLE: begin
              //  mem_ready = 1'b1;//改为wire assign
                if (mem_valid) begin//流水线流水线流水线
                    // 有新请求，进入保存状态
                   
                    next_state = SAVE_STATE;
                end
            end

            SAVE_STATE: begin
                // 在这个状态下，saved_is_use_lsu已经被更新
                if (!saved_is_use_lsu) begin    //如果不使用lsu直接到wbu wait状态和wbu握手
                    // 非内存操作，直接传递给WBU
                    next_state = WBU_WAIT;
                end else begin                   //如果使用lsu就正常执行
                    // 内存操作，进入相应状态
                    next_state = saved_wen ? WRITE_ADDR : READ_ADDR;
                end
            end

            WBU_WAIT: begin //流水线流水线流水线    
               // wbu_valid = 1'b1; 
              //  wbu_csr_valid = 1'b1;
                if (wbu_ready  && wbu_csr_ready) begin
                    // WBU已就绪，完成操作
                    next_state = IDLE;
                end else begin
                    // WBU未就绪，等待
                    next_state = WBU_WAIT;
                end
            end
            
            WRITE_ADDR: begin
               // io_master_awvalid = 1'b1;
                if (io_master_awready) begin
                    next_state = WRITE_DATA;
                end
            end
            
            WRITE_DATA: begin
               // io_master_wvalid = 1'b1;
                if (io_master_wready) begin
                    next_state = WRITE_RESP;
                end
            end
            

            




                 WRITE_RESP: begin
              //  io_master_bready = 1'b1;
                if (io_master_bvalid) begin
                    // 检查响应和ID
                    if (io_master_bid == curr_id && io_master_bresp == 2'b00) begin
                    
                        
                        //mem_ready = 1'b1;流水线流水线流水线
                        next_state = WBU_WAIT;//流水线流水线流水线
                        //流水线流水线流水线

                    end

                   else begin
            // 写操作失败，记录错误
         /*   $display("LSU write error! bid expected: %h, received: %h, bresp: %b inst = %h from lsu.v line:183 num = %h", 
                    curr_id, 
                    io_master_bid, 
                    io_master_bresp,
                    exu_to_lsu_inst_r,
                    num_r); */    //综合需要注释
            
            // 返回IDLE状态
                   next_state = IDLE;
                        end
                end
            end
            
            READ_ADDR: begin
               // io_master_arvalid = 1'b1;
                if (io_master_arready) begin
                    next_state = READ_DATA;
                end
            end
            
            READ_DATA: begin
              //  io_master_rready = 1'b1;
                if (io_master_rvalid) begin
                    // 检查响应和ID
                    //if (io_master_rid == curr_id && io_master_rresp == 2'b00) begin
                     if (io_master_rresp == 2'b00) begin//在初始化串口发现id不匹配先不对比id
                        //mem_ready = 1'b1;流水线流水线流水线
                      
                      //  mem_rdata = processed_rdata; 流水线流水线流水线
                       //$display("mem_rdata is %h from lsu.v line:197", mem_rdata);
                      
                          // 读操作成功完成，更新计数器
                        next_state = WBU_WAIT;//流水线流水线流水线
           
                    end
                    else begin
                        // 写操作失败，记录错误
                     /*   $display("LSU write error! bid expected: %h, received: %h, bresp: %b inst = %h from lsu.v line:187 num = %h", 
                                curr_id, 
                                io_master_bid, 
                                io_master_bresp,
                                exu_to_lsu_inst_r,
                                num_r);    */ //综合需要注释
                        
                        // 返回IDLE状态
                        next_state = IDLE;
                    end
                end
                
            end
            
            default: next_state = IDLE;
        endcase
    end






   wire is_mrom_region = (saved_addr[31:24] == 8'h20);
   wire is_uart_region = (saved_addr[31:24] == 8'h10);

//这里processed data和 下面的io master信号也能换成wire

always @(*) begin
    // 默认值
    processed_rdata = 32'b0;
        // 判断地址区间 - MROM区域通常在0x2000_0000开始
   



    // 根据读操作类型处理数据
    case (saved_arsize)
        3'b000: begin // 字节访问 lb lbu
        if(is_mrom_region) begin


        processed_rdata = {{24{io_master_rdata[7]}}, io_master_rdata[7:0]};
        //$display("processed_rdata is %h from lsu.v line:236", processed_rdata);

        end
        else  if (!saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{24{io_master_rdata[7]}}, io_master_rdata[7:0]};
                2'b01: processed_rdata = {{24{io_master_rdata[15]}}, io_master_rdata[15:8]};
                2'b10: processed_rdata = {{24{io_master_rdata[23]}}, io_master_rdata[23:16]};
                2'b11: processed_rdata = {{24{io_master_rdata[31]}}, io_master_rdata[31:24]};
            endcase
          
        end

        else if (saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{24{1'b0}}, io_master_rdata[7:0]};
                2'b01: processed_rdata = {{24{1'b0}}, io_master_rdata[15:8]};
                2'b10: processed_rdata = {{24{1'b0}}, io_master_rdata[23:16]};
                2'b11: processed_rdata = {{24{1'b0}}, io_master_rdata[31:24]};
            endcase
        end

        end
        3'b001: begin // 半字访问 lh lhu
        if(is_mrom_region) begin



        processed_rdata = {{16{io_master_rdata[15]}}, io_master_rdata[15:0]};


        end

        else  if (!saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{16{io_master_rdata[15]}}, io_master_rdata[15:0]};
                2'b10: processed_rdata = {{16{io_master_rdata[31]}}, io_master_rdata[31:16]};
                default: begin
                    processed_rdata = 32'b0;
                   // $display("error!!!!! half word read is not aligned inst = %h from lsu.v line:201 num = %h", exu_to_lsu_inst_r, num_r);        //综合需要注释
                end
            endcase
        end

        else if (saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{16{1'b0}}, io_master_rdata[15:0]};
                2'b10: processed_rdata = {{16{1'b0}}, io_master_rdata[31:16]};
                default: begin
                    processed_rdata = 32'b0;
                   // $display("error!!!!! half word read is not aligned inst = %h from lsu.v line:205 num = %h", exu_to_lsu_inst_r, num_r);        //综合需要注释
                end
            endcase
        end

        end
        3'b010: begin // 字访问 lw
        if(is_mrom_region) begin



        processed_rdata = io_master_rdata;

        end
        else begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = io_master_rdata;
                default: begin
                    processed_rdata = 32'b0;
                   // $display("error!!!!! word read is not aligned inst = %h from lsu.v line:209 num = %h", exu_to_lsu_inst_r, num_r);
                   // $display("saved_addr is %h  inst = %h from lsu.v line:210 num = %h", saved_addr, exu_to_lsu_inst_r, num_r);    //综合需要注释
                end
            endcase
        end
        end
        default: begin
            processed_rdata = 32'b0;
           // $display("wrong!!!!! unknown read size inst = %h from lsu.v line:303 num = %h", exu_to_lsu_inst_r, num_r);    //综合需要注释
        end
    endcase
end












//

always @(*) begin
    // 默认值
    io_master_wdata  = saved_wdata;//综合锁存器需要 yosys
  //is_uart_region = (saved_addr[31:24] == 8'h10);
    io_master_wstrb = 4'b0000;
 //io_master_wstrb = 1;

    // 根据写操作的大小和地址计算 wstrb
    case (saved_awsize)
    3'b000: begin // 1 字节 sb
        if(is_uart_region) begin
           case (saved_addr[1:0])//sram write
            2'b00: begin
                io_master_wstrb = 4'b0001;
                io_master_wdata = {24'b0, saved_wdata[7:0]}; // 数据在低8位
            end
            2'b01: begin
                io_master_wstrb = 4'b0010;
                io_master_wdata = {16'b0, saved_wdata[7:0], 8'b0}; // 数据在8-15位
            end
            2'b10: begin
                io_master_wstrb = 4'b0100;
                io_master_wdata = {8'b0, saved_wdata[7:0], 16'b0}; // 数据在16-23位
            end
            2'b11: begin
                io_master_wstrb = 4'b1000;
                io_master_wdata = {saved_wdata[7:0], 24'b0}; // 数据在高8位
            end
        endcase
        end
        else begin
        case (saved_addr[1:0])//sram write
            2'b00: begin
                io_master_wstrb = 4'b0001;
                io_master_wdata = {24'b0, saved_wdata[7:0]}; // 数据在低8位
            end
            2'b01: begin
                io_master_wstrb = 4'b0010;
                io_master_wdata = {16'b0, saved_wdata[7:0], 8'b0}; // 数据在8-15位
            end
            2'b10: begin
                io_master_wstrb = 4'b0100;
                io_master_wdata = {8'b0, saved_wdata[7:0], 16'b0}; // 数据在16-23位
            end
            2'b11: begin
                io_master_wstrb = 4'b1000;
                io_master_wdata = {saved_wdata[7:0], 24'b0}; // 数据在高8位
            end
        endcase
    end
    end
3'b001: begin // 半字访问  sh
    if(is_uart_region) begin
       case (saved_addr[1:0])
        2'b00: begin

            io_master_wstrb = 4'b0011;  // 写入低两字节
            io_master_wdata = {16'b0, saved_wdata[15:0]}; // 数据保持低位
        end
        2'b10: begin
            io_master_wstrb = 4'b1100;  // 写入高两字节
            io_master_wdata = {saved_wdata[15:0], 16'b0}; // 数据左移16位
        end
        default: begin 
            io_master_wstrb = 4'b0000;
           // $display("error!!!!! half word access is not aligned inst = %h from lsu.v line:213 num = %h", exu_to_lsu_inst_r, num_r);   //综合需要注释
        end
    endcase
    end
    else begin
    case (saved_addr[1:0])
        2'b00: begin

            io_master_wstrb = 4'b0011;  // 写入低两字节
            io_master_wdata = {16'b0, saved_wdata[15:0]}; // 数据保持低位
        end
        2'b10: begin
            io_master_wstrb = 4'b1100;  // 写入高两字节
            io_master_wdata = {saved_wdata[15:0], 16'b0}; // 数据左移16位
        end
        default: begin 
            io_master_wstrb = 4'b0000;
          //  $display("error!!!!! half word access is not aligned inst = %h from lsu.v line:217 num = %h", exu_to_lsu_inst_r, num_r);   //综合需要注释
        end
    endcase
    end
end
    3'b010: begin // 字访问  sw
    if(is_uart_region) begin
       case (saved_addr[1:0])
            2'b00: io_master_wstrb = 4'b1111;
            default: begin
                io_master_wstrb = 4'b0000;
              //  $display("error!!!!! word access is not aligned inst = %h from lsu.v line:236 num = %h", exu_to_lsu_inst_r, num_r);
              //  $display("saved_addr is %h from lsu.v line:237 num = %h inst = %h", saved_addr, num_r, exu_to_lsu_inst_r);    //综合需要注释
                // 应该触发非对齐
            end
        endcase
    end
    else begin
        case (saved_addr[1:0])
            2'b00: io_master_wstrb = 4'b1111;
            default: begin
                io_master_wstrb = 4'b0000;
               // $display("error!!!!! word access is not aligned inst = %h from lsu.v line:236 num = %h", exu_to_lsu_inst_r, num_r);
               // $display("saved_addr is %h from lsu.v line:237 num = %h inst = %h", saved_addr, num_r, exu_to_lsu_inst_r);     //综合需要注释
                // 应该触发非对齐
            end
        endcase
    end
    end
        default: begin
            io_master_wstrb = 4'b0000;
          // $display("wrong!!!!!!!saved awsizes is unknown number inst = %h from lsu.v line:230 num = %h", exu_to_lsu_inst_r, num_r);
          //  $display("saved_awsize is %h from lsu.v line:231 num = %h inst = %h", saved_awsize, num_r, exu_to_lsu_inst_r);   //综合需要注释
        end
    endcase
end   








endmodule

module ysyx_24090012_IFU (
    input  wire         clock,
    input  wire         reset,
    
    // Control Interface
    input  wire         if_allow_in,    // 允许取指信号
    input  wire [31:0]  if_next_pc,     // 外部传入的下一条指令地址  //if next pc(真实pc用不到了)

    input control_hazard,
    input [31:0] branch_target_pc,
    
    // IDU Interface
    input  wire         idu_ready,      // IDU准备好接收新指令
    output reg         idu_valid,      // 指令有效信号
    output reg [31:0]  idu_pc,         // 当前指令PC
    output reg [31:0]  idu_inst,       // 当前指令

    // AXI4 Interface for MROM
    input  wire         io_master_arready,
    output  wire        io_master_arvalid,
    output wire [31:0]  io_master_araddr,
    output wire [3:0]   io_master_arid,
    output wire [7:0]   io_master_arlen,
    output wire [2:0]   io_master_arsize,
    output wire [1:0]   io_master_arburst,
    
    output reg [2:0] state_out,

    input  wire         io_master_rvalid,
    input  wire [31:0]  io_master_rdata,
    input  wire [3:0]   io_master_rid,
    input  wire         io_master_rlast,//暂时不用
    input  wire [1:0]   io_master_rresp,//暂时不用
    output          io_master_rready,
    output reg  [63:0]  num
);

localparam FENCE_I_INST = 32'h0000100F;  // fence.i 指令编码

    // icache配置参数

//原来的23100面积
localparam CACHE_LINES = 2;                // 缓存块数量
localparam INDEX_BITS = 1;                  // 索引位数 (2^4 = 16)


//localparam CACHE_LINES = 1048576;                // 缓存块数量
//localparam INDEX_BITS = 20;                  // 索引位数 (2^20 = 1048576)  这里是将icache扩大到可以可以容纳dummy所有指令触发缓存一致性问题

//localparam OFFSET_BITS = 2;                 // 偏移位数 (4B块大小)
localparam OFFSET_BITS = 4;                 // 突发传输icache
localparam TAG_BITS = 32 - INDEX_BITS - OFFSET_BITS; // 标签位数

// 状态定义 - 简化的三状态机
localparam IDLE        = 3'b000;  // 空闲状态
localparam CHECK_CACHE = 3'b001;  // 第1步：检查缓存是否命中
localparam FETCH_ADDR  = 3'b010;  // 第2-3步：发起总线请求取数据
localparam FETCH_DATA  = 3'b011;  // 第4-5步：接收数据并响应
localparam WAIT_IDU    = 3'b100;






    // 寄存器定义
    reg [2:0] state;
   // reg [2:0] state = IDLE;
    //reg [2:0] next_state;
    reg [2:0] next_state = IDLE;
  //  reg [31:0] saved_pc;    // 锁存的PC
    reg [31:0] saved_pc = 32'h7FFFFFFC; // 初始PC值 是30000000 - 4.为了下面默认saved pc = saved pc +4初始值
  //  reg [3:0]  curr_id;     // 当前事务ID
    reg [3:0]  curr_id = 4'h0;

    reg [31:0] ifu_count;  // IFU取指计数器
    reg [31:0] hit_count;   // 缓存命中计数
    reg [31:0] miss_count;  // 缓存未命中计数


   // reg [1:0] burst_count;  // 突发传输计数器  突发传输icache
    reg [1:0] burst_count = 2'b00;  // 初始化burst计数器   突发传输icache
    reg [TAG_BITS-1:0] cache_tags [0:CACHE_LINES-1];  // 标签数组
    reg cache_valid [0:CACHE_LINES-1];                // 有效位数组
    //reg [31:0] cache_data [0:CACHE_LINES-1];          // 数据数组
    reg [127:0] cache_data [0:CACHE_LINES-1];   //突发传输icache
    // 添加临时缓存数据
reg [127:0] temp_cache_data;  // 临时数据寄存器用于累积突发传输数据   突发传输icache
wire [1:0] word_offset = saved_pc[3:2];  // 添加: 块内字偏移，用于选择正确的32位指令  突发传输icache

      // 地址解析
    wire [TAG_BITS-1:0] req_tag = saved_pc[31:INDEX_BITS+OFFSET_BITS];
    wire [INDEX_BITS-1:0] req_index = saved_pc[INDEX_BITS+OFFSET_BITS-1:OFFSET_BITS];
    wire [OFFSET_BITS-1:0] req_offset = saved_pc[OFFSET_BITS-1:0]; // 对于指令总是为0
    
    // 缓存命中判断
    wire cache_hit = cache_valid[req_index] && (cache_tags[req_index] == req_tag);


   


    always @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;
            saved_pc <= 32'h7FFFFFFC; // 初始PC值 是30000000 - 4.为了下面默认saved pc = saved pc +4初始值
            ifu_count <= 32'h0;
            hit_count <= 32'h0;
            miss_count <= 32'h0;
            num <= 64'h1;//必须为1,要不然前两条指令发生数据冒险的时候，idu中的num rr会和wbu num的默认值0相同，巧合的破解了数据冒险

            burst_count <= 2'b00;  // 初始化burst计数器   突发传输icache
            temp_cache_data <= 128'h0;  // 初始化临时数  突发传输icache

            for (integer i = 0; i < CACHE_LINES; i = i + 1) begin
                cache_valid[i] <= 1'b0;
                cache_tags[i] <= {TAG_BITS{1'b0}};
                cache_data[i] <= 128'h0;
            end
        end
        
        else begin

            if ((state == CHECK_CACHE && cache_hit && next_state == IDLE) || 
            (state == FETCH_DATA && io_master_rvalid && io_master_rready && next_state == IDLE)) begin
            ifu_count <= ifu_count + 32'h1;
            end


            state <= next_state;
            
                       // 当进入CHECK_CACHE状态时，锁存PC
            if (state == IDLE && next_state == CHECK_CACHE) begin

                if (control_hazard) begin  //控制冒险判断
                    saved_pc <= branch_target_pc;
                end
              else begin 
                // saved_pc <= if_next_pc; //if next pc(真实pc用不到了)

                saved_pc <= saved_pc + 4;

              end
            end
            
            // 当请求发送时更新事务ID
            if (state == CHECK_CACHE && next_state == FETCH_ADDR) begin
                curr_id <= curr_id + 4'h1;
            end

            // 计数器更新
            if (state == CHECK_CACHE) begin    //计数器在实现控制冒险之后会统计错误，因为取出错误的指令冲刷流水线后count记数不会减去
                if (cache_hit) begin
                    hit_count <= hit_count + 32'h1;
                   // $display("hit_count: %d", hit_count);
                end else begin
                    miss_count <= miss_count + 32'h1;
                   // $display("miss_count: %d", miss_count);
                end
            end
            
     // 在IDU握手成功时增加指令序列号
            if (idu_valid && idu_ready) begin
                num <= num + 64'h1;
            end

              // 在FETCH_DATA状态更新缓存
          /*  if (state == FETCH_DATA && io_master_rvalid && io_master_rready) begin
                cache_tags[req_index] <= req_tag;
                cache_valid[req_index] <= 1'b1;
                cache_data[req_index] <= io_master_rdata;
            end*/


            if (state == FETCH_DATA && io_master_rvalid && io_master_rready) begin
                case (burst_count)
                    2'b00: begin
                        temp_cache_data[31:0] <= io_master_rdata;
                        burst_count <= burst_count + 1;
                    end
                    2'b01: begin
                        temp_cache_data[63:32] <= io_master_rdata;
                        burst_count <= burst_count + 1;
                    end
                    2'b10: begin
                        temp_cache_data[95:64] <= io_master_rdata;
                        burst_count <= burst_count + 1;
                    end
                    2'b11: begin
                        // 最后一个传输，完成缓存更新
                        cache_tags[req_index] <= req_tag;
                        cache_valid[req_index] <= 1'b1;
                        cache_data[req_index] <= {io_master_rdata, temp_cache_data[95:0]};
                        burst_count <= 2'b00;  // 重置计数器
                    end
                endcase
            end

            if (state == CHECK_CACHE && cache_hit && idu_inst == FENCE_I_INST) begin
                for (integer i = 0; i < CACHE_LINES; i = i + 1) begin
                    cache_valid[i] <= 1'b0;  // 无效化所有缓存行
                end
            end else if (state == FETCH_DATA && io_master_rvalid && io_master_rready && io_master_rlast && idu_inst == FENCE_I_INST) begin
                for (integer i = 0; i < CACHE_LINES; i = i + 1) begin
                    cache_valid[i] <= 1'b0;  // 无效化所有缓存行
                end
            end

        end

        
        
    end


    assign io_master_arvalid = (state == FETCH_ADDR);
    assign io_master_rready = (state == FETCH_DATA);

    assign io_master_araddr =   {saved_pc[31:4], 4'b0000};
    

    // 组合逻辑：状态转换和所有输出信号生成
    always @(*) begin
        // 默认值
        next_state = state;
        
      //  io_master_arvalid = 1'b0;
       // io_master_rready = 1'b0;
        idu_valid = 1'b0;
        idu_pc = saved_pc;//当前pc
        idu_inst = 32'h0;//在后面赋值
        state_out = state;

        if (control_hazard) begin
            next_state = IDLE;
        end

        case (state)
            IDLE: begin
                if (if_allow_in) begin
                    next_state = CHECK_CACHE;
                end
            end
            
            CHECK_CACHE: begin
                if (cache_hit) begin
                    // 缓存命中，直接响应
                    idu_valid = 1'b1;
                  //  idu_inst = cache_data[req_index];
                    case (word_offset)    //突发传输icache
                    2'b00: idu_inst = cache_data[req_index][31:0];
                    2'b01: idu_inst = cache_data[req_index][63:32];
                    2'b10: idu_inst = cache_data[req_index][95:64];
                    2'b11: idu_inst = cache_data[req_index][127:96];
                endcase   
                    
                    if (idu_ready) begin
                        next_state = IDLE;
                      //  $display("ifu_inst = 0x%08x", idu_inst);
                    end  else begin//add
                        next_state = CHECK_CACHE; // IDU not ready, 保持在当前状态等待 add
                    end //add
                end else begin
                    // 缓存未命中，发起内存访问
                    next_state = FETCH_ADDR;
                end
            end


            FETCH_ADDR: begin
              //  io_master_arvalid = 1'b1;
              //  io_master_araddr =   {saved_pc[31:4], 4'b0000};
                if (io_master_arready) begin
                    next_state = FETCH_DATA;
                end
            end
            
            FETCH_DATA: begin
              //  io_master_rready = 1'b1;
                if (io_master_rvalid && (io_master_rid == curr_id)) begin

                    if (io_master_rlast) begin
                        // 根据word_offset选择正确的指令
                        case (word_offset)
                            2'b00: idu_inst = temp_cache_data[31:0];
                            2'b01: idu_inst = temp_cache_data[63:32];
                            2'b10: idu_inst = temp_cache_data[95:64];
                            2'b11: idu_inst = io_master_rdata; // 最后一个word
                        endcase
                      
                        idu_valid = 1'b1;
                        if (idu_ready) begin
                            next_state = IDLE;
                        //    $display("ifu_inst = 0x%08x", idu_inst);
                        end else begin
                            next_state = WAIT_IDU;  // IDU未准备好，进入等待状态
                        end
                    end
                    end
            end

            WAIT_IDU: begin
                // 在此状态中，我们已经有了指令数据，只是在等IDU准备好
                idu_valid = 1'b1;
                
                // 根据缓存的数据提供指令
                case (word_offset)
                    2'b00: idu_inst = temp_cache_data[31:0];
                    2'b01: idu_inst = temp_cache_data[63:32];
                    2'b10: idu_inst = temp_cache_data[95:64];
                    2'b11: idu_inst = temp_cache_data[127:96]; // 使用已缓存的最后一个word
                endcase
                
                // 只有当IDU准备好时才回到IDLE
                if (idu_ready) begin
                    next_state = IDLE;
                   // $display("ifu_inst = 0x%08x", idu_inst);
                end
            end
            
            default: begin
                next_state = IDLE;
            end
        endcase
    end

    // 其他输出信号直接赋值
    //assign io_master_araddr  = saved_pc;
    assign io_master_arid    = curr_id;
  //  assign io_master_arlen   = 8'b0;        // 单次传输
    assign io_master_arlen   = 8'd3;        // 4次传输(长度=传输次数-1)
    assign io_master_arsize  = 3'b010;      // 4字节
    assign io_master_arburst = 2'b01;       // INCR模式
  

endmodule



module ysyx_24090012_IDU(
  input [31:0] inst,
  input [31:0] ifu_to_idu_pc,
  
    input wire clock,        // 改用clock
    input wire reset,        // 改用reset
  //ifu interface
  output  ifu_ready,
  input  ifu_valid,


  //exu interface
  output reg exu_valid,   //尽量不要换成wire因为数据和控制冒险需要在always里，不然很麻烦
  input  exu_ready,
  output   [31:0] idu_to_exu_pc, 

   output  state_out,  // 添加state输出端口

  input [31:0] exu_next_pc,

  input [63:0] wbu_reg_num,//wbu中流水线寄存器的num
  input [63:0] exu_reg_num,//exu中流水线寄存器的num
  input [63:0] lsu_reg_num,//lsu中流水线寄存器的num

  input [31:0] wbu_hazard_result,//wbu中冒险结果
  input [31:0] exu_hazard_result,//exu中冒险结果
  input [31:0] lsu_hazard_result,//lsu中冒险结果

  output wire [31:0] idu_to_exu_inst,

  output wire control_hazard, //控制冒险信号
  output  wire [31:0] branch_target_pc, // 添加分支目标PC输出

  output wire [6:0] opcode,//pppppppp
  output wire [2:0] func3,
  output wire [6:0] func7,
  output wire [4:0] rs1,
  output wire [4:0] rs2,
  output wire [4:0] rd,//pppppppppppppp

  input [31:0] rs1_data,
  input [31:0] rs2_data,

  output wire [31:0] rs1_data_out,
  output wire [31:0] rs2_data_out,


  input [31:0] data_hazard_exu_inst,
  input [31:0] data_hazard_lsu_inst,
  input [31:0] data_hazard_wbu_inst,
  output wire rd_wen,//pppppppp
  
  output wire [5:0] alu_op,
  output wire [31:0] imm,
  output wire [11:0] csr_addr,

 
 
  input [63:0] num,
  output reg [63:0] num_r,
  input [63:0] wbu_num//wbu里面时序逻辑证明已经写入的标识num


);
 

   // 状态定义
    localparam IDLE = 1'b0;
    localparam BUSY = 1'b1;

    //reg state, next_state;
    reg state = IDLE;
    reg next_state = IDLE;
        // IDU流水线寄存器
    reg [31:0] inst_r;        // 指令寄存器
   
    reg [31:0] pc_r;         // PC寄存器



    // 性能计数器
    reg [31:0] idu_count;           // IDU处理指令总计数器
    reg [31:0] compute_inst_count;  // 计算类指令计数器
    reg [31:0] load_inst_count;     // 加载指令计数器
    reg [31:0] store_inst_count;    // 存储指令计数器
    reg [31:0] branch_inst_count;   // 分支指令计数器
    reg [31:0] jump_inst_count;     // 跳转指令计数器
    reg [31:0] csr_inst_count;      // CSR指令计数器
    reg [31:0] other_inst_count;    // 其他指令计数器



    wire [6:0] exu_opcode = data_hazard_exu_inst[6:0];
    wire [4:0] exu_rd = data_hazard_exu_inst[11:7];
    wire exu_is_load = (exu_opcode == 7'b0000011);
    wire exu_rd_wen = (exu_opcode == 7'b0010011 || exu_opcode == 7'b0110111 || 
                     exu_opcode == 7'b0010111 || exu_opcode == 7'b1110011 ||
                     exu_opcode == 7'b1101111 || exu_opcode == 7'b1100111 || 
                     exu_opcode == 7'b0110011 || exu_opcode == 7'b0000011);
    
    wire [6:0] lsu_opcode = data_hazard_lsu_inst[6:0];
    wire [4:0] lsu_rd = data_hazard_lsu_inst[11:7];
    wire lsu_is_load = (lsu_opcode == 7'b0000011);
    wire lsu_rd_wen = (lsu_opcode == 7'b0010011 || lsu_opcode == 7'b0110111 || 
                     lsu_opcode == 7'b0010111 || lsu_opcode == 7'b1110011 ||
                     lsu_opcode == 7'b1101111 || lsu_opcode == 7'b1100111 || 
                     lsu_opcode == 7'b0110011 || lsu_opcode == 7'b0000011);
    
    wire [6:0] wbu_opcode = data_hazard_wbu_inst[6:0];
    wire [4:0] wbu_rd = data_hazard_wbu_inst[11:7];
    wire wbu_rd_wen = (wbu_opcode == 7'b0010011 || wbu_opcode == 7'b0110111 || 
                     wbu_opcode == 7'b0010111 || wbu_opcode == 7'b1110011 ||
                     wbu_opcode == 7'b1101111 || wbu_opcode == 7'b1100111 || 
                     wbu_opcode == 7'b0110011 || wbu_opcode == 7'b0000011);
    

wire use_rs1 = (opcode != 7'b0110111 && opcode != 7'b0010111 && 
               opcode != 7'b1101111); // LUI, AUIPC, JAL不使用rs1
wire use_rs2 = (opcode == 7'b0110011 || opcode == 7'b1100011 || 
               opcode == 7'b0100011); // R-type, B-type, S-type使用rs2

               wire rs1_exu_hazard = use_rs1 && exu_rd_wen && (rs1 == exu_rd) && (exu_rd != 5'b0);
               wire rs1_lsu_hazard = use_rs1 && lsu_rd_wen && (rs1 == lsu_rd) && (lsu_rd != 5'b0);
               wire rs1_wbu_hazard = use_rs1 && wbu_rd_wen && (rs1 == wbu_rd) && (wbu_rd != 5'b0);
               
               wire rs2_exu_hazard = use_rs2 && exu_rd_wen && (rs2 == exu_rd) && (exu_rd != 5'b0);
               wire rs2_lsu_hazard = use_rs2 && lsu_rd_wen && (rs2 == lsu_rd) && (lsu_rd != 5'b0);
               wire rs2_wbu_hazard = use_rs2 && wbu_rd_wen && (rs2 == wbu_rd) && (wbu_rd != 5'b0);
               

               assign rs1_data_out = 
               (rs1_exu_hazard && !exu_is_load) ? exu_hazard_result :
               (rs1_lsu_hazard && !lsu_is_load) ? lsu_hazard_result :
               rs1_wbu_hazard ? wbu_hazard_result :
               rs1_data;
             
             assign rs2_data_out = 
               (rs2_exu_hazard && !exu_is_load) ? exu_hazard_result :
               (rs2_lsu_hazard && !lsu_is_load) ? lsu_hazard_result :
               rs2_wbu_hazard ? wbu_hazard_result :
               rs2_data;


    assign idu_to_exu_inst = inst_r;
    assign idu_to_exu_pc = pc_r;
    assign state_out = state;//向top模块输出当前state

   

  /*  wire csr_hazard = (csr_wen && csr_wen_r == 2'b1 && csr_addr == csr_addr_r && (alu_op != 6'b110010)) ||    //两个都是普通csr指令的情况触发冒险 
    (csr_wen_r == 2'd2 && (    
       csr_addr == 12'h341 || 
       csr_addr == 12'h342  ) && csr_wen && (alu_op != 6'b110010)); //mepc和mcause    //前一个指令是ecall，后面一个是普通csr指令(csrrs csrrw)触发冒险
*/



   /*assign control_hazard = (state == BUSY) && 
   ((exu_next_pc != 32'h0 && exu_next_pc != pc_r) || 
    (exu_next_pc == 32'h0 && exu_next_pc_r != 32'h0 && exu_next_pc_r != pc_r));*/

    assign control_hazard = (state == BUSY) && 
   (exu_next_pc != 32'h0 && exu_next_pc != pc_r);

   assign branch_target_pc = exu_next_pc;


   always @(posedge clock or posedge reset) begin
    if (ifu_valid && ifu_ready) begin
     //   inst_r <= inst;
      //  pc_r <= ifu_to_idu_pc;
      //  idu_count <= idu_count + 1;  // idu count计数器
      //  num_r <= num;
        end

   end






    always @(posedge clock or posedge reset) begin
        if (reset) begin
            inst_r <= 32'b0;
            pc_r <= 32'b0;
            num_r <= 64'h0;
           
           
            idu_count <= 32'h0;
            compute_inst_count <= 32'h0;
            load_inst_count <= 32'h0;
            store_inst_count <= 32'h0;
            branch_inst_count <= 32'h0;
            jump_inst_count <= 32'h0;
            csr_inst_count <= 32'h0;
            other_inst_count <= 32'h0;

        end 

    else begin  
          if (ifu_valid && ifu_ready) begin
               inst_r <= inst;
               pc_r <= ifu_to_idu_pc;
               idu_count <= idu_count + 1;  // idu count计数器
               num_r <= num;
               end
            end

    end


    always @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end







 


    assign    rd_wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1110011||
    opcode == 7'b1101111 || opcode == 7'b1100111 || opcode == 7'b0110011 || 
     opcode == 7'b0000011);//流水线流水线流水线

    assign opcode = inst_r[6:0];
    assign func3 = inst_r[14:12];
    assign func7 = inst_r[31:25];
    assign rs1 = inst_r[19:15];
    assign rs2 = inst_r[24:20];
    assign rd = inst_r[11:7];
    assign csr_addr = inst_r[31:20];

    wire is_r_type = (opcode == 7'b0110011);//1111111
    wire is_i_type = (opcode == 7'b0010011);//111111
    wire is_b_type = (opcode == 7'b1100011);//1111111
    wire is_load = (opcode == 7'b0000011);//11111111111
    wire is_store = (opcode == 7'b0100011);//11111111
    wire is_jal = (opcode == 7'b1101111);//11111
    wire is_jalr = (opcode == 7'b1100111);//111111
    wire is_lui = (opcode == 7'b0110111);//11111111
    wire is_auipc = (opcode == 7'b0010111);//1111111111
    wire is_system = (opcode == 7'b1110011);//11111

    wire [31:0] i_imm = {{20{inst_r[31]}}, inst_r[31:20]};
    wire [31:0] u_imm = {inst_r[31:12], 12'b0};//lui
    wire [31:0] auipc_imm = {inst_r[31:12], 12'b0};//auipc
    wire [31:0] jal_imm = {{12{inst_r[31]}}, inst_r[19:12], inst_r[20], inst_r[30:21], 1'b0};
    wire [31:0] jalr_imm = {{20{inst_r[31]}}, inst_r[31:20]};
    wire [31:0] b_imm = {{19{inst_r[31]}}, inst_r[31], inst_r[7], inst_r[30:25], inst_r[11:8], 1'b0};//branch
    wire [31:0] s_imm = {{20{inst_r[31]}}, inst_r[31:25], inst_r[11:7]};//store
    wire [31:0] l_imm = {{20{inst_r[31]}}, inst_r[31:20]};//load

    assign imm = is_i_type ? i_imm :         //imm可以在exu中计算出
    is_load ? l_imm :
    is_jalr ? jalr_imm :
    is_store ? s_imm :
    is_b_type ? b_imm :
    is_lui ? u_imm :
    is_auipc ? auipc_imm :
    is_jal ? jal_imm : 32'b0;



assign alu_op = 
// R-type指令
(opcode == 7'b0110011 && func3 == 3'b000 && func7 == 7'b0000000) ? 6'b000101 :  // ADD
(opcode == 7'b0110011 && func3 == 3'b000 && func7 == 7'b0100000) ? 6'b001100 :  // SUB
(opcode == 7'b0110011 && func3 == 3'b001 && func7 == 7'b0000000) ? 6'b001101 :  // SLL
(opcode == 7'b0110011 && func3 == 3'b111 && func7 == 7'b0000000) ? 6'b010000 :  // AND
(opcode == 7'b0110011 && func3 == 3'b011 && func7 == 7'b0000000 && rs2 == 5'b00000) ? 6'b010010 :  // SNEZ
(opcode == 7'b0110011 && func3 == 3'b011 && func7 == 7'b0000000) ? 6'b011100 :  // SLTU
(opcode == 7'b0110011 && func3 == 3'b110 && func7 == 7'b0000000) ? 6'b010100 :  // OR
(opcode == 7'b0110011 && func3 == 3'b100 && func7 == 7'b0000000) ? 6'b010111 :  // XOR
(opcode == 7'b0110011 && func3 == 3'b010 && func7 == 7'b0000000) ? 6'b011101 :  // SLT
(opcode == 7'b0110011 && func3 == 3'b101 && func7 == 7'b0100000) ? 6'b100001 :  // SRA
(opcode == 7'b0110011 && func3 == 3'b101 && func7 == 7'b0000000) ? 6'b100010 :  // SRL

// I-type指令
(opcode == 7'b0010011 && func3 == 3'b000) ? 6'b101111 :  // ADDI
(opcode == 7'b0010011 && func3 == 3'b110) ? 6'b100101 :  // ORI
(opcode == 7'b0010011 && func3 == 3'b010) ? 6'b100110 :  // SLTI
(opcode == 7'b0010011 && func3 == 3'b011) ? 6'b001010 :  // SEQZ
(opcode == 7'b0010011 && func3 == 3'b100) ? 6'b001110 :  // XORI
(opcode == 7'b0010011 && func3 == 3'b111 && inst_r[31:20] == 12'b000011111111) ? 6'b001111 :  // ZEXT.B
(opcode == 7'b0010011 && func3 == 3'b101 && func7 == 7'b0100000) ? 6'b010001 :  // SRAI
(opcode == 7'b0010011 && func3 == 3'b111) ? 6'b010011 :  // ANDI
(opcode == 7'b0010011 && func3 == 3'b101 && func7 == 7'b0000000) ? 6'b010110 :  // SRLI
(opcode == 7'b0010011 && func3 == 3'b001 && func7 == 7'b0000000) ? 6'b011001 :  // SLLI

// Load指令
(opcode == 7'b0000011 && func3 == 3'b000) ? 6'b100100 :  // LB
(opcode == 7'b0000011 && func3 == 3'b010) ? 6'b001000 :  // LW
(opcode == 7'b0000011 && func3 == 3'b100) ? 6'b011000 :  // LBU
(opcode == 7'b0000011 && func3 == 3'b001) ? 6'b011111 :  // LH
(opcode == 7'b0000011 && func3 == 3'b101) ? 6'b100000 :  // LHU

// Store指令
(opcode == 7'b0100011 && func3 == 3'b000) ? 6'b100011 :  // SB
(opcode == 7'b0100011 && func3 == 3'b001) ? 6'b110100 :  // SH
(opcode == 7'b0100011 && func3 == 3'b010) ? 6'b001001 :  // SW

// Branch指令
(opcode == 7'b1100011 && func3 == 3'b000) ? 6'b000110 :  // BEQ
(opcode == 7'b1100011 && func3 == 3'b001) ? 6'b000111 :  // BNE
(opcode == 7'b1100011 && func3 == 3'b101) ? 6'b010101 :  // BGE
(opcode == 7'b1100011 && func3 == 3'b111) ? 6'b011010 :  // BGEU
(opcode == 7'b1100011 && func3 == 3'b110) ? 6'b011011 :  // BLTU
(opcode == 7'b1100011 && func3 == 3'b100) ? 6'b011110 :  // BLT

// System指令
(opcode == 7'b1110011 && func3 == 3'b000 && inst_r[31:20] == 12'b0) ? 6'b110010 :  // ECALL
(opcode == 7'b1110011 && func3 == 3'b000 && inst_r[31:20] == 12'b001100000010) ? 6'b110011 :  // MRET
(opcode == 7'b1110011 && func3 == 3'b000 && inst_r[31:20] == 12'b000000000001) ? 6'b001011 :  // EBREAK
(opcode == 7'b1110011 && func3 == 3'b001) ? 6'b110000 :  // CSRRW
(opcode == 7'b1110011 && func3 == 3'b010) ? 6'b110001 :  // CSRRS

// 其他特殊指令
(opcode == 7'b0110111) ? 6'b000001 :  // LUI
(opcode == 7'b0010111) ? 6'b000010 :  // AUIPC
(opcode == 7'b1101111) ? 6'b000011 :  // JAL
(opcode == 7'b1100111) ? 6'b000100 :  // JALR

// 默认值
6'b001111;  // 未实现的操作




assign ifu_ready = (state == IDLE);



    always @(*) begin
       next_state = state;
        exu_valid = 1'b0;
     case (state)
            IDLE: begin
                if (ifu_valid) begin
                    next_state = BUSY;
                end
            end
            BUSY: begin
//先检测控制冒险
    if (exu_next_pc != 32'h0 && exu_next_pc != pc_r) begin
  // 有控制冒险，阻止指令继续并立即切换状态
  exu_valid = 1'b0;
  next_state = IDLE;
end

// 其次检测数据冒险       //wbu写入后wbu num才更新
else if (((rs1_exu_hazard && exu_is_load && exu_reg_num != wbu_reg_num) || 
    (rs2_exu_hazard && exu_is_load && exu_reg_num != wbu_reg_num) ||
    (rs1_lsu_hazard && lsu_is_load && lsu_reg_num != wbu_reg_num) || 
    (rs2_lsu_hazard && lsu_is_load && lsu_reg_num != wbu_reg_num)) ) begin
// 有加载指令冒险且未解决，阻止指令继续
exu_valid = 1'b0;
next_state = BUSY;

    end else begin
      // 无冒险或冒险已解决，指令可以继续
      exu_valid = 1'b1;
      if (exu_ready) begin
        next_state = IDLE;
      end else begin
        next_state = BUSY;  // 明确赋值
    end
    end
    
      end
            
            default: begin
                next_state = IDLE;
            end
        endcase
  end


endmodule





//删除了latch 和 wait ready状态   只保留idle 和 exec状态  但是没有处理 csr部分



module ysyx_24090012_EXU(
  input rst,
  input clk,  // 添加时钟输入
  input        idu_valid,      // 新增：IDU数据有效信号
  output    idu_ready,      // 新增：EXU就绪信号
  input [31:0] pc,
  output [1:0] state_out,
 
// LSU接口 (master)
    
    output  [31:0] mem_addr,
    output         mem_valid,
    output  [31:0] mem_wdata,
   
   
    input   wire         mem_ready,

    input [31:0] rs1_data,
    input [31:0] rs2_data,
  
   

   // output reg is_use_lsu,//流水线流水线流水线

    input [31:0] idu_to_exu_inst,
    output  [31:0] exu_to_lsu_inst,
    
    output wire [63:0] exu_reg_num,
  
    output wire [31:0] rd_data,
    
    output wire [31:0] next_pc,

    output wire [31:0] exu_hazard_result,


    // PC更新接口 (master)
   
    output [31:0] out_pc,

    output wire [31:0] data_hazard_exu_inst,

    


    input [31:0] mtvec,
    input [31:0] mepc,

  input [31:0] imm,
  input [5:0] alu_op,
  

 
    input [11:0] csr_addr,
    input  csr_wen,


    input [31:0] csr_rdata,//csr csr csr csr

    output  [11:0] out_csr_addr,



    output  wire [31:0] csr_wdata,//csr csr csr csr

    output  out_csr_wen,//csr csr csr csr
    input [63:0] num,
    output reg [63:0] num_r
   

 
);
 //import "DPI-C" function void pmem_write(input int addr, input int data, input int mask);
 //import "DPI-C" function int pmem_read(input int addr);


    // 状态定义
    localparam IDLE = 2'b00;

    localparam EXEC = 2'b11;


    //reg [1:0] state, next_state;
    reg [1:0] state = IDLE;
    reg [1:0] next_state;
       // 输入数据寄存器
    reg [31:0] pc_r;
    reg [31:0] rs1_data_r;
    reg [31:0] rs2_data_r;
  
    reg [31:0] imm_r;
    reg [5:0]  alu_op_r;
   
    
    // CSR输入数据寄存器
    reg [31:0] mtvec_r;
    reg [31:0] mepc_r;

    reg [31:0] csr_rdata_r;

  
    
    reg [31:0] exu_count;    // EXU执行指令计数器

    reg [31:0] idu_to_exu_inst_r;

    assign data_hazard_exu_inst = idu_to_exu_inst_r;

  assign exu_to_lsu_inst = idu_to_exu_inst_r;

  assign exu_reg_num = num_r;


  assign exu_hazard_result = rd_data;


 assign state_out = state; 


always @(posedge clk) begin
   // 当指令执行完成时，增加计数器

end

    // 状态转换
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            exu_count <= 0;
        end else begin
          
            state <= next_state;

            if (state == EXEC && next_state == IDLE) begin
              exu_count <= exu_count + 1;
          end
        end
    end
    
        // 流水线寄存器更新
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // 基本输入寄存器复位
            pc_r <= 32'b0;
            rs1_data_r <= 32'b0;
            rs2_data_r <= 32'b0;
            imm_r <= 32'b0;
            alu_op_r <= 6'b0;
           
            // CSR输入数据寄存器复位
            mtvec_r <= 32'b0;
            mepc_r <= 32'b0;
          
            csr_rdata_r <= 32'b0;
            num_r <= 64'h0;
            idu_to_exu_inst_r <= 32'b0;
        end else if (state == IDLE && idu_valid) begin
            // 基本输入寄存器更新
            pc_r <= pc;
            rs1_data_r <= rs1_data;
            rs2_data_r <= rs2_data;
            imm_r <= imm;
            alu_op_r <= alu_op;
           
            // CSR输入数据寄存器更新
            mtvec_r <= mtvec;
            mepc_r <= mepc;
           
      
            csr_rdata_r <= csr_rdata;
            num_r <= num;
            idu_to_exu_inst_r <= idu_to_exu_inst;
        end
    end



   /* always @(posedge clk) begin
      if (alu_op_r == 6'b010001) begin  // 当执行SRAI操作时打印
        
          $display("rs1_data_r = 32'h%h", rs1_data_r);
          $display("imm_r[4:0] = 5'b%b (Decimal: %0d)", imm_r[4:0], imm_r[4:0]);
          $display("num_r = 64'h%h", num_r);
          $display("rd_data = 32'h%h", rd_data);
        //  $display("srai_data = 32'h%h", srai_data);
          $display("shift result = 32'h%h", $signed(rs1_data_r) >>> imm_r[4:0]);

          $display("----------------------------------");
      end
  end*/


   wire [31:0] srai_data = $signed(rs1_data_r) >>> imm_r[4:0];
   wire [31:0] sra_data = $signed(rs1_data_r) >>> rs2_data_r[4:0];

    assign rd_data =      //没有s指令
    (alu_op_r == 6'b101111) ? rs1_data_r + imm_r :                                  // ADDI
    (alu_op_r == 6'b000001) ? imm_r :                                               // LUI
    (alu_op_r == 6'b000010) ? pc_r + imm_r :                                        // AUIPC
    (alu_op_r == 6'b000011) ? pc_r + 4 :                                            // JAL
    (alu_op_r == 6'b000100) ? pc_r + 4 :                                            // JALR
    (alu_op_r == 6'b000101) ? rs1_data_r + rs2_data_r :                             // ADD
    (alu_op_r == 6'b001010) ? (rs1_data_r == 0) ? 32'h1 : 32'h0 :                   // SEQZ
    (alu_op_r == 6'b001100) ? rs1_data_r - rs2_data_r :                             // SUB
    (alu_op_r == 6'b001101) ? rs1_data_r << rs2_data_r[4:0] :                       // SLL
    (alu_op_r == 6'b001110) ? rs1_data_r ^ imm_r :                                  // XORI
    (alu_op_r == 6'b001111) ? {24'b0, rs1_data_r[7:0]} :                            // ZEXT.B
    (alu_op_r == 6'b010000) ? rs1_data_r & rs2_data_r :                             // AND
    (alu_op_r == 6'b010001) ? srai_data :                  // SRAI
    (alu_op_r == 6'b010010) ? (rs2_data_r != 0) ? 32'h1 : 32'h0 :                   // SNEZ
    (alu_op_r == 6'b010011) ? rs1_data_r & imm_r :                                  // ANDI
    (alu_op_r == 6'b010100) ? rs1_data_r | rs2_data_r :                             // OR
    (alu_op_r == 6'b010110) ? rs1_data_r >> imm_r[4:0] :                            // SRLI
    (alu_op_r == 6'b010111) ? rs1_data_r ^ rs2_data_r :                             // XOR
    (alu_op_r == 6'b011001) ? rs1_data_r << imm_r[4:0] :                            // SLLI
    (alu_op_r == 6'b011100) ? (rs1_data_r < rs2_data_r) ? 32'h1 : 32'h0 :           // SLTU
    (alu_op_r == 6'b011101) ? ($signed(rs1_data_r) < $signed(rs2_data_r)) ? 32'h1 : 32'h0 : // SLT
    (alu_op_r == 6'b100001) ? sra_data :             // SRA
    (alu_op_r == 6'b100010) ? rs1_data_r >> rs2_data_r[4:0] :                       // SRL
    (alu_op_r == 6'b100101) ? rs1_data_r | imm_r :                                  // ORI
    (alu_op_r == 6'b100110) ? ($signed(rs1_data_r) < $signed(imm_r)) ? 32'h1 : 32'h0 : // SLTI
    (alu_op_r == 6'b110000) ? csr_rdata_r :                                         // CSRRW
    (alu_op_r == 6'b110001) ? csr_rdata_r :                                         // CSRRS
    32'h0; 


// 直接计算next_pc
    assign next_pc = 
    (alu_op_r == 6'b000011) ? pc_r + imm_r :                                       // JAL
    (alu_op_r == 6'b000100) ? (rs1_data_r + imm_r) & ~32'h1 :                      // JALR
    (alu_op_r == 6'b000110) ? (rs1_data_r == rs2_data_r) ? pc_r + imm_r : pc_r + 4 :  // BEQ
    (alu_op_r == 6'b000111) ? (rs1_data_r != rs2_data_r) ? pc_r + imm_r : pc_r + 4 :  // BNE
    (alu_op_r == 6'b010101) ? ($signed(rs1_data_r) >= $signed(rs2_data_r)) ? pc_r + imm_r : pc_r + 4 : // BGE
    (alu_op_r == 6'b011010) ? (rs1_data_r >= rs2_data_r) ? pc_r + imm_r : pc_r + 4 :  // BGEU
    (alu_op_r == 6'b011011) ? (rs1_data_r < rs2_data_r) ? pc_r + imm_r : pc_r + 4 :   // BLTU
    (alu_op_r == 6'b011110) ? ($signed(rs1_data_r) < $signed(rs2_data_r)) ? pc_r + imm_r : pc_r + 4 : // BLT
    (alu_op_r == 6'b110010) ? mtvec_r :                                            // ECALL
    (alu_op_r == 6'b110011) ? mepc_r :                                             // MRET
        
    (alu_op_r == 6'b000001) ? pc_r + 4 : // LUI
    (alu_op_r == 6'b000010) ? pc_r + 4 : // AUIPC
    (alu_op_r == 6'b000101) ? pc_r + 4 : // ADD
    (alu_op_r == 6'b001100) ? pc_r + 4 : // SUB
    (alu_op_r == 6'b001101) ? pc_r + 4 : // SLL
    (alu_op_r == 6'b010000) ? pc_r + 4 : // AND
    (alu_op_r == 6'b010010) ? pc_r + 4 : // SNEZ
    (alu_op_r == 6'b011100) ? pc_r + 4 : // SLTU
    (alu_op_r == 6'b010100) ? pc_r + 4 : // OR
    (alu_op_r == 6'b010111) ? pc_r + 4 : // XOR
    (alu_op_r == 6'b011101) ? pc_r + 4 : // SLT
    (alu_op_r == 6'b100001) ? pc_r + 4 : // SRA
    (alu_op_r == 6'b100010) ? pc_r + 4 : // SRL
    (alu_op_r == 6'b101111) ? pc_r + 4 : // ADDI
    (alu_op_r == 6'b100101) ? pc_r + 4 : // ORI
    (alu_op_r == 6'b100110) ? pc_r + 4 : // SLTI
    (alu_op_r == 6'b001010) ? pc_r + 4 : // SEQZ
    (alu_op_r == 6'b001110) ? pc_r + 4 : // XORI
    (alu_op_r == 6'b001111) ? pc_r + 4 : // ZEXT.B
    (alu_op_r == 6'b010001) ? pc_r + 4 : // SRAI
    (alu_op_r == 6'b010011) ? pc_r + 4 : // ANDI
    (alu_op_r == 6'b010110) ? pc_r + 4 : // SRLI
    (alu_op_r == 6'b011001) ? pc_r + 4 : // SLLI
    (alu_op_r == 6'b100100) ? pc_r + 4 : // LB
    (alu_op_r == 6'b001000) ? pc_r + 4 : // LW
    (alu_op_r == 6'b011000) ? pc_r + 4 : // LBU
    (alu_op_r == 6'b011111) ? pc_r + 4 : // LH
    (alu_op_r == 6'b100000) ? pc_r + 4 : // LHU
    (alu_op_r == 6'b100011) ? pc_r + 4 : // SB
    (alu_op_r == 6'b110100) ? pc_r + 4 : // SH
    (alu_op_r == 6'b001001) ? pc_r + 4 : // SW
    (alu_op_r == 6'b001011) ? pc_r + 4 : // EBREAK
    (alu_op_r == 6'b110000) ? pc_r + 4 : // CSRRW
    (alu_op_r == 6'b110001) ? pc_r + 4 : // CSRRS
    pc_r ; 



  

    // CSR写数据
    assign csr_wdata = 
        (alu_op_r == 6'b110000) ? rs1_data_r :          // CSRRW
        (alu_op_r == 6'b110001) ? csr_rdata_r | rs1_data_r :  // CSRRS
        32'h0;



    assign out_pc = pc_r;


    assign mem_valid = (state == EXEC);
    assign idu_ready = (state == IDLE);
    assign mem_addr = rs1_data_r + imm_r;
    assign mem_wdata = rs2_data_r;
 
    assign next_state = (state == EXEC && mem_ready) ? IDLE :
    (state == IDLE && idu_valid) ? EXEC :
    state; 
    
always @(*) begin

  
  //next_state = state;//mmmmmmmmmm

  
  case (state)
    IDLE: begin
      if (idu_valid && idu_ready) begin   //idu_ready在idle时一直为1
             // next_state = EXEC;
                end
            end
  
 EXEC: begin

   
    end
    
    default: begin
      
   //   $display("1114default:didnt match any inst from (exu.v)");    //综合需要注释
    end

  endcase
end




endmodule




module ysyx_24090012_CSR (
  input clk,
  input rst,
  input [11:0] csr_addr,//read

  input [31:0] csr_wdata,
 
  input [31:0] lsu_to_wbu_inst,

  input [31:0] pc,
   
  output  [31:0] csr_rdata,
  
  input wbu_csr_valid,
  output  wbu_csr_ready,

 

 
  
  output reg [31:0] mtvec,
  output reg [31:0] mepc,
  output reg [31:0] mstatus,
  
  output reg [31:0] mcause,
  
  
  output reg [31:0] mvendorid,
  output reg [31:0] marchid
);

  // CSR地址定义
  localparam MSTATUS = 12'h300;
  localparam MTVEC   = 12'h305;
  localparam MEPC    = 12'h341;
  localparam MCAUSE  = 12'h342;
  localparam MVENDORID = 12'hf11;
  localparam MARCHID = 12'hf12;

// 状态定义
  localparam IDLE = 1'b0;  // 空闲状态，等待请求
  localparam WRITE = 1'b1; // 写入状态，执行CSR操作
  
  // 状态寄存器
  reg state, next_state;
  
  // 保存CSR请求的寄存器

  reg [31:0] saved_csr_wdata;

 

  reg [31:0] saved_lsu_to_wbu_inst;
 
  reg [31:0] saved_pc;  // 用于ECALL保存PC


  wire [6:0] opcode = saved_lsu_to_wbu_inst[6:0];
  wire [2:0] func3 = saved_lsu_to_wbu_inst[14:12];
 
  
  wire [11:0] saved_csr_addr = saved_lsu_to_wbu_inst[31:20];

  wire is_ecall = (opcode == 7'b1110011) && (func3 == 3'b000) && (saved_lsu_to_wbu_inst[31:20] == 12'b0);
  wire is_mret = (opcode == 7'b1110011) && (func3 == 3'b000) && (saved_lsu_to_wbu_inst[31:20] == 12'b001100000010);
  wire is_csrrw = (opcode == 7'b1110011) && (func3 == 3'b001);
  wire is_csrrs = (opcode == 7'b1110011) && (func3 == 3'b010);
  
  // CSR写使能：CSRRW, CSRRS 或间接的 ECALL, MRET
  wire saved_csr_wen = is_csrrw || is_csrrs || is_ecall || is_mret;


  // CSR寄存器初始化和写入逻辑
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      mstatus <= 32'h0;  // MPP = 11 (M模式)
      mtvec   <= 32'h0;
      mepc    <= 32'h0;
      mcause  <= 32'h0;
      state <= IDLE;
   
      saved_csr_wdata <= 32'h0;
 
    
      saved_lsu_to_wbu_inst <= 32'h0;
      saved_pc <= 32'h0;
    end
    else begin
      // 状态更新
      state <= next_state;
            // 数据处理
      if (state == IDLE) begin
        if (wbu_csr_valid && wbu_csr_ready) begin
          // 保存CSR请求数据
         
          saved_csr_wdata <= csr_wdata;
        
       
          saved_lsu_to_wbu_inst <= lsu_to_wbu_inst;
          saved_pc <=  pc; // 对于ECALL，csr_wdata是当前PC
        end
      end
      else if (state == WRITE) begin
        // 执行CSR操作
        if(!is_ecall) begin
        if (saved_csr_wen) begin
          case (saved_csr_addr)
            MSTATUS: mstatus <= saved_csr_wdata;
            MTVEC:   mtvec   <= saved_csr_wdata;
            MEPC:    mepc    <= saved_csr_wdata;
            MCAUSE:  mcause  <= saved_csr_wdata;
            default: ;
          endcase
        end
      end
        
        // 处理特殊指令
        if (is_ecall) begin
          mepc <= saved_pc;        // 保存当前PC到mepc
          mcause <= 32'h0000000b;  // 环境调用异常码
        end
       
      end
    end
  end



assign wbu_csr_ready = (state == IDLE);

  // 状态机逻辑
  always @(*) begin
    // 默认值
    next_state = state;
   
    
    case (state)
      IDLE: begin
      
        // 在IDLE状态，如果有有效的CSR请求，保存数据并转到WRITE状态
        if (wbu_csr_valid && wbu_csr_ready) begin
          next_state = WRITE;
        end
      end
      
      WRITE: begin
        // 在WRITE状态，完成CSR操作后返回IDLE状态
        next_state = IDLE;
      end
    endcase
  end








// CSR读取逻辑使用wire信号
  wire [31:0] mstatus_rdata = (csr_addr == MSTATUS) ? mstatus : 32'h0;
  wire [31:0] mtvec_rdata = (csr_addr == MTVEC) ? mtvec : 32'h0;
  wire [31:0] mepc_rdata = (csr_addr == MEPC) ? mepc : 32'h0;
  wire [31:0] mcause_rdata = (csr_addr == MCAUSE) ? mcause : 32'h0;
  wire [31:0] mvendorid_rdata = (csr_addr == MVENDORID) ? mvendorid : 32'h0;
  wire [31:0] marchid_rdata = (csr_addr == MARCHID) ? marchid : 32'h0;
  
  // 所有寄存器的读取结果进行OR运算得到最终的csr_rdata
  assign csr_rdata = mstatus_rdata | mtvec_rdata | mepc_rdata | mcause_rdata | mvendorid_rdata | marchid_rdata;


  // CSR读取逻辑
/*  always @(*) begin
    case (csr_addr)
      MSTATUS: csr_rdata = mstatus;
      MTVEC:   csr_rdata = mtvec;
      MEPC:    csr_rdata = mepc;
      MCAUSE:  csr_rdata = mcause;
      MVENDORID: csr_rdata = mvendorid;
      MARCHID:  csr_rdata = marchid;
      default: csr_rdata = 32'h0;
    endcase
  end*/



  initial begin
    mvendorid = 32'h79737978;  // "ysyx"的ASCII
    marchid   = 32'h016F959E;  // 24090014的十六进制表示（0x16F959E扩展为32位）
end





endmodule





module ysyx_24090012_CLINT (
    input wire         clk,
    input wire         rst,
    
    // AXI4-Lite Slave Interface
    input  wire        s_axi_arvalid,
    output reg         s_axi_arready,
    input  wire [31:0] s_axi_araddr,
    
    output reg         s_axi_rvalid,
    input  wire        s_axi_rready,
    output reg [31:0]  s_axi_rdata,
    output wire [1:0]  s_axi_rresp
);

    // 配置参数（优化为更小的分频系数）
    localparam CLOCK_DIV_FACTOR = 64;  // 改为64=2^6 进一步减少面积
    localparam DIV_SHIFT = 6;          // 移位位数
    localparam DIV_COUNTER_WIDTH = 6;  // 分频计数器位宽
    
    // 状态定义
    localparam IDLE = 1'b0;
    localparam READ = 1'b1;
    
    //reg state;
    reg state = IDLE;
    reg [63:0] mtime;
    reg [31:0] addr_r;
    reg [DIV_COUNTER_WIDTH-1:0] div_counter;
    
    // mtime增量控制信号（新增）
    wire mtime_inc = (div_counter == 0);
    
    // 共享计算资源
    wire [63:0] divided_time = mtime >> DIV_SHIFT;
    
    // 简化地址解码
    wire sel_high_word = (addr_r[3:0] == 4'hC);
    
    // 分频计数器（新增）
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            div_counter <= 0;
        end else begin
            div_counter <= div_counter + 1;
        end
    end
    
    // mtime计数器（低频更新）
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mtime <= 64'h0;
            state <= IDLE;
            addr_r <= 32'h0;
        end else begin
            // 只在mtime_inc时更新计数器（关键修改）
            if (mtime_inc) mtime <= mtime + 64'h1;
            
            // 简化状态转移
            case (state)
                IDLE: if (s_axi_arvalid) state <= READ;
                READ: if (s_axi_rready) state <= IDLE;
            endcase
            
            // 地址锁存
            if (state == IDLE && s_axi_arvalid)
                addr_r <= s_axi_araddr;
        end
    end
    
    // 输出逻辑保持不变
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            s_axi_arready <= 1'b0;
            s_axi_rvalid <= 1'b0;
            s_axi_rdata <= 32'h0;
        end else begin
            s_axi_arready <= (state == IDLE);
            s_axi_rvalid <= (state == READ);
            
            if (state == READ) begin
                s_axi_rdata <= sel_high_word ? divided_time[63:32] : 
                                              divided_time[31:0];
            end
        end
    end

    assign s_axi_rresp = 2'b00;

endmodule


module ysyx_24090012_arbiter(
    input wire clk,
    input wire rst,

    // LSU Master Interface
    input  wire        lsu_awvalid,
    output wire        lsu_awready,
    input  wire [31:0] lsu_awaddr,
    input  wire [3:0]  lsu_awid,
    input  wire [7:0]  lsu_awlen,
    input  wire [2:0]  lsu_awsize,
    input  wire [1:0]  lsu_awburst,
    input  wire        lsu_wvalid,
    output wire        lsu_wready,
    input  wire [31:0] lsu_wdata,
    input  wire [3:0]  lsu_wstrb,
    input  wire        lsu_wlast,
    input  wire        lsu_bready,
    output wire        lsu_bvalid,
    output wire [1:0]  lsu_bresp,
    output wire [3:0]  lsu_bid,
    input  wire        lsu_arvalid,
    output wire        lsu_arready,
    input  wire [31:0] lsu_araddr,
    input  wire [3:0]  lsu_arid,
    input  wire [7:0]  lsu_arlen,
    input  wire [2:0]  lsu_arsize,
    input  wire [1:0]  lsu_arburst,
    input  wire        lsu_rready,
    output wire        lsu_rvalid,
    output wire [1:0]  lsu_rresp,
    output wire [31:0] lsu_rdata,
    output wire        lsu_rlast,
    output wire [3:0]  lsu_rid,

    // IFU Master Interface
 // IFU Master Interface (完整的AXI接口)
  
    
    // 读地址通道 使用
    input  wire        ifu_arvalid,
    output wire        ifu_arready,
    input  wire [31:0] ifu_araddr,
    input  wire [3:0]  ifu_arid,
    input  wire [7:0]  ifu_arlen,
    input  wire [2:0]  ifu_arsize,
    input  wire [1:0]  ifu_arburst,

    // 读数据通道 使用
    input  wire        ifu_rready,
    output wire        ifu_rvalid,
    output wire [1:0]  ifu_rresp,
    output wire [31:0] ifu_rdata,
    output wire        ifu_rlast,
    output wire [3:0]  ifu_rid,

    // AXI4 Slave Interface (to memory)
    output wire        io_master_awvalid,
    input  wire        io_master_awready,
    output wire [31:0] io_master_awaddr,
    output wire [3:0]  io_master_awid,
    output wire [7:0]  io_master_awlen,
    output wire [2:0]  io_master_awsize,
    output wire [1:0]  io_master_awburst,
    output wire        io_master_wvalid,
    input  wire        io_master_wready,
    output wire [31:0] io_master_wdata,
    output wire [3:0]  io_master_wstrb,
    output wire        io_master_wlast,
    output wire        io_master_bready,
    input  wire        io_master_bvalid,
    input  wire [1:0]  io_master_bresp,
    input  wire [3:0]  io_master_bid,
    output wire        io_master_arvalid,
    input  wire        io_master_arready,
    output wire [31:0] io_master_araddr,
    output wire [3:0]  io_master_arid,
    output wire [7:0]  io_master_arlen,
    output wire [2:0]  io_master_arsize,
    output wire [1:0]  io_master_arburst,
    output wire        io_master_rready,
    input  wire        io_master_rvalid,
    input  wire [1:0]  io_master_rresp,
    input  wire [31:0] io_master_rdata,
    input  wire        io_master_rlast,
    input  wire [3:0]  io_master_rid
);

    // 定义状态机状态
    localparam IDLE      = 2'b00;
    localparam LSU_READ  = 2'b01;
    localparam IFU_READ  = 2'b10;
    localparam LSU_WRITE  = 2'b11;
    
    //reg [1:0] current_state;
    reg [1:0] current_state = IDLE;
    reg [1:0] next_state = IDLE;

    // 状态转移逻辑
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            current_state <= IDLE;
        end else begin
            current_state <= next_state;
        end
    end

    // 次态逻辑
    always @(*) begin
        case (current_state)
            IDLE: begin
                if (lsu_awvalid)          // LSU写优先级最高
                next_state = LSU_WRITE;
            else if (lsu_arvalid)     // LSU读其次
                next_state = LSU_READ;
            else if (ifu_arvalid)     // IFU读优先级最低
                next_state = IFU_READ;
            else
                next_state = IDLE;
            end

            LSU_WRITE: begin
                if (io_master_bvalid && lsu_bready)
                    next_state = IDLE;
                else
                    next_state = LSU_WRITE;
            end
            
            LSU_READ: begin
                if (io_master_rvalid && io_master_rlast && lsu_rready)
                    next_state = IDLE;
                else
                    next_state = LSU_READ;
            end

            IFU_READ: begin
                if (io_master_rvalid && io_master_rlast && ifu_rready)
                    next_state = IDLE;
                else
                    next_state = IFU_READ;
            end
            
            default: next_state = IDLE;
        endcase
    end

    wire is_lsu_read  = (current_state == LSU_READ);
    wire is_lsu_write = (current_state == LSU_WRITE);
    wire is_ifu_read  = (current_state == IFU_READ);

    // 写通道连接 - 直接连接LSU
    assign io_master_awvalid = lsu_awvalid && is_lsu_write;
    assign io_master_awaddr  = lsu_awaddr;
    assign io_master_awid    = lsu_awid;
    assign io_master_awlen   = lsu_awlen;
    assign io_master_awsize  = lsu_awsize;
    assign io_master_awburst = lsu_awburst;
    assign lsu_awready      = io_master_awready && is_lsu_write;

    assign io_master_wvalid  = lsu_wvalid && is_lsu_write;
    assign io_master_wdata   = lsu_wdata;
    assign io_master_wstrb   = lsu_wstrb;
    assign io_master_wlast   = lsu_wlast;
    assign lsu_wready       = io_master_wready && is_lsu_write;

    assign io_master_bready  = lsu_bready && is_lsu_write;
    assign lsu_bvalid       = io_master_bvalid && is_lsu_write;
    assign lsu_bresp        = io_master_bresp;
    assign lsu_bid          = io_master_bid;

   

   // 状态信号


//wire use_lsu_addr = (current_state == IDLE && lsu_arvalid) || is_lsu_read; //流水线先注释掉，设计的有问题
//wire use_ifu_addr = (current_state == IDLE && ifu_arvalid) || is_ifu_read;

// 读通道连接 - 使用统一的选择信号
/*assign io_master_arvalid = (lsu_arvalid && (current_state == IDLE || is_lsu_read)) || 
                          (ifu_arvalid && (current_state == IDLE || is_ifu_read));*/   //流水线 注释掉 设计的有问题

assign io_master_arvalid = (lsu_arvalid && is_lsu_read) || 
                          (ifu_arvalid && is_ifu_read);

/*assign io_master_araddr  = use_lsu_addr ? lsu_araddr : ifu_araddr;
assign io_master_arid    = use_lsu_addr ? lsu_arid : ifu_arid;
assign io_master_arlen   = use_lsu_addr ? lsu_arlen : ifu_arlen;
assign io_master_arsize  = use_lsu_addr ? lsu_arsize : ifu_arsize;
assign io_master_arburst = use_lsu_addr ? lsu_arburst : ifu_arburst;*/
assign io_master_araddr  = is_lsu_read ? lsu_araddr : ifu_araddr;
assign io_master_arid    = is_lsu_read ? lsu_arid : ifu_arid;
assign io_master_arlen   = is_lsu_read ? lsu_arlen : ifu_arlen;
assign io_master_arsize  = is_lsu_read ? lsu_arsize : ifu_arsize;
assign io_master_arburst = is_lsu_read ? lsu_arburst : ifu_arburst;




   // assign lsu_arready      = io_master_arready && (current_state == IDLE || is_lsu_read);
    //assign ifu_arready      = io_master_arready && (current_state == IDLE || is_ifu_read);

 assign lsu_arready      = io_master_arready && is_lsu_read;
 assign ifu_arready      = io_master_arready && is_ifu_read;

    assign io_master_rready  = (lsu_rready && is_lsu_read) || (ifu_rready && is_ifu_read);

    // LSU读响应
    assign lsu_rvalid = io_master_rvalid && is_lsu_read;
    assign lsu_rresp  = io_master_rresp;
    assign lsu_rdata  = io_master_rdata;
    assign lsu_rlast  = io_master_rlast;
    assign lsu_rid    = io_master_rid;

    // IFU读响应
    assign ifu_rvalid = io_master_rvalid && is_ifu_read;
    assign ifu_rresp  = io_master_rresp;
    assign ifu_rdata  = io_master_rdata;
    assign ifu_rlast  = io_master_rlast;
    assign ifu_rid    = io_master_rid;

endmodule







