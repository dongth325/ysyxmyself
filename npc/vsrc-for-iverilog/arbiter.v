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
    
    reg [1:0] current_state;
    reg [1:0] next_state;

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
