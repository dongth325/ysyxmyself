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
    // 写地址通道（不使用）
   /* output wire        ifu_awready,
    input  wire        ifu_awvalid,
    input  wire [31:0] ifu_awaddr,
    input  wire [3:0]  ifu_awid,
    input  wire [7:0]  ifu_awlen,
    input  wire [2:0]  ifu_awsize,
    input  wire [1:0]  ifu_awburst,
    
    // 写数据通道（不使用）
    output wire        ifu_wready,
    input  wire        ifu_wvalid,
    input  wire [31:0] ifu_wdata,
    input  wire [3:0]  ifu_wstrb,
    input  wire        ifu_wlast,
    
    // 写响应通道（不使用）
    input  wire        ifu_bready,
    output wire        ifu_bvalid,
    output wire [1:0]  ifu_bresp,
    output wire [3:0]  ifu_bid,*/
    
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

    // 仲裁状态定义
    localparam IDLE = 2'b00;
    localparam LSU_ACCESS = 2'b01;
    localparam IFU_ACCESS = 2'b10;

    reg [1:0] state, next_state;
    reg is_lsu_read;  // 标记当前读事务是否来自LSU

    // 状态转换逻辑
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end

    // 组合逻辑：状态转换和仲裁决策
    always @(*) begin
        next_state = state;
        is_lsu_read = 1'b0;

        case (state)
            IDLE: begin
                if (lsu_awvalid || lsu_arvalid) begin
                    next_state = LSU_ACCESS;
                end else if (ifu_arvalid) begin
                    next_state = IFU_ACCESS;
                end
            end

            LSU_ACCESS: begin
                if (!lsu_awvalid && !lsu_arvalid && !io_master_rvalid && !io_master_bvalid) begin
                    next_state = IDLE;
                end
            end

            IFU_ACCESS: begin
                if (!ifu_arvalid && !io_master_rvalid) begin
                    next_state = IDLE;
                end else if (lsu_awvalid || lsu_arvalid) begin
                    next_state = LSU_ACCESS;  // LSU可以抢占IFU
                end
            end

            default: begin
                // 添加默认状态处理
                // 可以设置默认的输出值或返回到IDLE状态
                next_state = IDLE;
                // ... 设置其他信号的默认值 ...
            end
        endcase
    end

    // 写通道仲裁（只有LSU使用）
    assign io_master_awvalid = (state == LSU_ACCESS) ? lsu_awvalid : 1'b0;
    assign io_master_awaddr  = lsu_awaddr;
    assign io_master_awid    = lsu_awid;
    assign io_master_awlen   = lsu_awlen;
    assign io_master_awsize  = lsu_awsize;
    assign io_master_awburst = lsu_awburst;
    assign lsu_awready      = (state == LSU_ACCESS) ? io_master_awready : 1'b0;

    assign io_master_wvalid  = (state == LSU_ACCESS) ? lsu_wvalid : 1'b0;
    assign io_master_wdata   = lsu_wdata;
    assign io_master_wstrb   = lsu_wstrb;
    assign io_master_wlast   = lsu_wlast;
    assign lsu_wready       = (state == LSU_ACCESS) ? io_master_wready : 1'b0;

    assign io_master_bready  = (state == LSU_ACCESS) ? lsu_bready : 1'b0;
    assign lsu_bvalid       = (state == LSU_ACCESS) ? io_master_bvalid : 1'b0;
    assign lsu_bresp        = io_master_bresp;
    assign lsu_bid          = io_master_bid;

    // 读通道仲裁
    assign io_master_arvalid = (state == LSU_ACCESS) ? lsu_arvalid : 
                              (state == IFU_ACCESS) ? ifu_arvalid : 1'b0;
    assign io_master_araddr  = (state == LSU_ACCESS) ? lsu_araddr : ifu_araddr;
    assign io_master_arid    = (state == LSU_ACCESS) ? lsu_arid : ifu_arid;
    assign io_master_arlen   = (state == LSU_ACCESS) ? lsu_arlen : ifu_arlen;
    assign io_master_arsize  = (state == LSU_ACCESS) ? lsu_arsize : ifu_arsize;
    assign io_master_arburst = (state == LSU_ACCESS) ? lsu_arburst : ifu_arburst;

    assign lsu_arready      = (state == LSU_ACCESS) ? io_master_arready : 1'b0;
    assign ifu_arready      = (state == IFU_ACCESS) ? io_master_arready : 1'b0;

    // 读响应通道仲裁
    assign io_master_rready  = (state == LSU_ACCESS) ? lsu_rready : 
                              (state == IFU_ACCESS) ? ifu_rready : 1'b0;

// 读响应通道的完整仲裁逻辑
// LSU响应
assign lsu_rvalid = (state == LSU_ACCESS) ? io_master_rvalid : 1'b0;
assign lsu_rresp  = (state == LSU_ACCESS) ? io_master_rresp  : 2'b00;
assign lsu_rdata  = (state == LSU_ACCESS) ? io_master_rdata  : 32'b0;
assign lsu_rlast  = (state == LSU_ACCESS) ? io_master_rlast  : 1'b0;
assign lsu_rid    = (state == LSU_ACCESS) ? io_master_rid    : 4'b0;

// IFU响应
assign ifu_rvalid = (state == IFU_ACCESS) ? io_master_rvalid : 1'b0;
assign ifu_rresp  = (state == IFU_ACCESS) ? io_master_rresp  : 2'b00;
assign ifu_rdata  = (state == IFU_ACCESS) ? io_master_rdata  : 32'b0;
assign ifu_rlast  = (state == IFU_ACCESS) ? io_master_rlast  : 1'b0;
assign ifu_rid    = (state == IFU_ACCESS) ? io_master_rid    : 4'b0;

endmodule