module ysyx_24090012_LSU (
    input wire         clock,
    input wire         reset,

    // EXU Interface (slave)
    input  wire [31:0] mem_addr,
    input  wire        mem_valid,
    input  wire [31:0] mem_wdata,
    input  wire [3:0]  mem_wmask,
    input  wire        mem_wen,
    output reg         mem_ready,
    output reg  [31:0] mem_rdata,

    // AXI4 Master Interface
    // Write Address Channel
    input  wire        io_master_awready,
    output reg         io_master_awvalid,
    output reg  [31:0] io_master_awaddr,
    output reg  [3:0]  io_master_awid,     // 传递事务ID
    output reg  [7:0]  io_master_awlen,
    output reg  [2:0]  io_master_awsize,
    output reg  [1:0]  io_master_awburst,

    // Write Data Channel
    input  wire        io_master_wready,
    output reg         io_master_wvalid,
    output reg  [31:0] io_master_wdata,
    output reg  [3:0]  io_master_wstrb,
    output reg         io_master_wlast,     // 单次传输永远为1

    // Write Response Channel
    output reg         io_master_bready,
    input  wire        io_master_bvalid,
    input  wire [1:0]  io_master_bresp,    // 写响应状态
    input  wire [3:0]  io_master_bid,      // 写响应ID

    // Read Address Channel
    input  wire        io_master_arready,
    output reg         io_master_arvalid,
    output reg  [31:0] io_master_araddr,
    output reg  [3:0]  io_master_arid,     // 传递事务ID
    output reg  [7:0]  io_master_arlen,
    output reg  [2:0]  io_master_arsize,
    output reg  [1:0]  io_master_arburst,

    // Read Data Channel
    output reg         io_master_rready,
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

    // 寄存器定义
    reg [2:0] state;
    reg [31:0] saved_addr;
    reg [31:0] saved_wdata;
    reg [3:0]  saved_wmask;
    reg [3:0]  curr_id;    // 当前事务ID

    // 时序逻辑：状态更新和数据保存
    always @(posedge clock) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;
        end else begin
            // 在IDLE状态且有新请求时保存数据
            if (state == IDLE && mem_valid) begin
                saved_addr <= mem_addr;
                saved_wdata <= mem_wdata;
                saved_wmask <= mem_wmask;
                curr_id <= curr_id + 4'h1;  // 递增事务ID
            end
            state <= next_state;
        end
    end

    // 组合逻辑：状态转换和控制信号生成
    reg [2:0] next_state;
    always @(*) begin
        // 默认值
        next_state = state;
        io_master_awvalid = 0;
        io_master_wvalid  = 0;
        io_master_bready  = 0;
        io_master_arvalid = 0;
        io_master_rready  = 0;
        mem_ready = 0;
        mem_rdata = io_master_rdata;
        
        // 固定值
        io_master_awid    = curr_id;        // 使用当前事务ID
        io_master_awlen   = 8'd0;           // 单次传输
        io_master_awsize  = 3'b010;         // 4字节
        io_master_awburst = 2'b01;          // INCR模式
        io_master_arid    = curr_id;        // 使用当前事务ID
        io_master_arlen   = 8'd0;           // 单次传输
        io_master_arsize  = 3'b010;         // 4字节
        io_master_arburst = 2'b01;          // INCR模式
        
        // 地址和数据连接
        io_master_awaddr = saved_addr;
        io_master_araddr = saved_addr;
        io_master_wdata  = saved_wdata;
        io_master_wstrb  = saved_wmask;
        io_master_wlast  = 1'b1;            // 单次传输永远为1
        
        // 状态转换和控制信号生成
        case (state)
            IDLE: begin
                if (mem_valid) begin
                    next_state = mem_wen ? WRITE_ADDR : READ_ADDR;
                end
            end
            
            WRITE_ADDR: begin
                io_master_awvalid = 1'b1;
                if (io_master_awready) begin
                    next_state = WRITE_DATA;
                end
            end
            
            WRITE_DATA: begin
                io_master_wvalid = 1'b1;
                if (io_master_wready) begin
                    next_state = WRITE_RESP;
                end
            end
            
                 WRITE_RESP: begin
                io_master_bready = 1'b1;
                if (io_master_bvalid) begin
                    // 检查响应和ID
                    if (io_master_bid == curr_id && io_master_bresp == 2'b00) begin
                        mem_ready = 1'b1;
                    end
                    next_state = IDLE;
                end
            end
            
            READ_ADDR: begin
                io_master_arvalid = 1'b1;
                if (io_master_arready) begin
                    next_state = READ_DATA;
                end
            end
            
            READ_DATA: begin
                io_master_rready = 1'b1;
                if (io_master_rvalid) begin
                    // 检查响应和ID
                    if (io_master_rid == curr_id && io_master_rresp == 2'b00) begin
                        mem_ready = 1'b1;
                        mem_rdata = io_master_rdata;
                    end
                    next_state = IDLE;
                end
            end
            
            default: next_state = IDLE;
        endcase
    end

endmodule






































































/*module ysyx_24090012_LSU (
    input clk,
    input rst,
    
    // EXU接口 (slave)
    input [31:0]  addr,       // 地址
    input         valid,      // 请求有效 (exu -> lsu)
    output reg    ready,      // 请求完成 (lsu -> exu)
    output reg [31:0] rdata,  // 读出的数据
    input [31:0]  wdata,      // 写入的数据
    input [3:0]   wmask,      // 写掩码
    input         wen,        // 写使能
    
    // SRAM接口 (master)
    output reg [31:0] sram_addr,  // SRAM地址
    output reg        arvalid,    // 地址有效 (lsu -> sram)
    input             arready,    // 地址准备好 (sram -> lsu)
    input [31:0]      sram_rdata, // 从SRAM读出的数据
    input             rvalid,     // 数据有效 (sram -> lsu)
    output reg        rready,     // 数据准备好 (lsu -> sram)
    output reg [31:0] sram_wdata, // 写入SRAM的数据
    output reg [3:0]  sram_wmask, // SRAM写掩码
    output reg        sram_wen    // SRAM写使能
);
    // 状态定义
    localparam IDLE      = 2'b00;  // 空闲状态
    localparam ADDR_PHASE = 2'b01; // 地址握手阶段
    localparam DATA_PHASE = 2'b10; // 数据握手阶段
    
    reg [1:0] state, next_state;   // 状态寄存器
    
    // 状态转换
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    // 状态机逻辑
    always @(*) begin
        // 默认值
        next_state = state;
        ready = 0;
        rdata = sram_rdata;
        sram_addr = addr;
        sram_wdata = wdata;
        sram_wmask = wmask;
        sram_wen = wen;
        arvalid = 0;
        rready = 0;
        
        case (state)
            IDLE: begin
                if (valid) begin
                    arvalid = 1;  // 地址有效
                    next_state = ADDR_PHASE;
                end
            end
            
            ADDR_PHASE: begin
                arvalid = 1;  // 保持地址有效
                if (arready) begin
                    arvalid = 0;  // 地址已接收
                    next_state = DATA_PHASE;
                end
            end
            
            DATA_PHASE: begin
                rready = 1;  // 准备好接收数据
                if (rvalid) begin
                    ready = 1;  // 数据已接收
                    rready = 0; // 复位 rready
                    next_state = IDLE;
                end
            end
        endcase
    end
endmodule*/



