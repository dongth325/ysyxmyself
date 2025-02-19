module ysyx_24090012_LSU (
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
endmodule