module ysyx_24090012_LSU (
    input clk,
    input rst,
    
    // EXU接口 (slave)
    input [31:0]  addr,
    input         valid,      // exu -> lsu
    output reg    ready,      // lsu -> exu
    output reg [31:0] rdata,  // 读出的数据
    input [31:0]  wdata,      // 写入的数据
    input [3:0]   wmask,      // 写掩码
    input         wen,        // 写使能
    
    // SRAM接口 (master)
    output reg [31:0] sram_addr,
    output reg        sram_valid,    // lsu -> sram
    input            sram_ready,     // sram -> lsu
    input [31:0]     sram_rdata,    // 从SRAM读出的数据
    output reg [31:0] sram_wdata,    // 写入SRAM的数据
    output reg [3:0]  sram_wmask,    // SRAM写掩码
    output reg        sram_wen       // SRAM写使能
);
    // 状态定义
    localparam IDLE = 1'b0;
    localparam WAIT_READY = 1'b1;
    
    reg state, next_state;
    
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
        sram_valid = 0;
        sram_addr = addr;
        sram_wdata = wdata;
        sram_wmask = wmask;
        sram_wen = wen;
        
        case (state)
            IDLE: begin
                if (valid) begin
                    sram_valid = 1;
                    next_state = WAIT_READY;
                end
            end
            
            WAIT_READY: begin
                sram_valid = 1;
                if (sram_ready) begin
                    ready = 1;
                    sram_valid = 0;
                    
                        next_state = IDLE;
                  
                end
            end
        endcase
    end
endmodule