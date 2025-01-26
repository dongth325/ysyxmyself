module ysyx_24090012_SRAM (
    input clk,
    input rst,
    
    // 总线接口 (slave)
    input [31:0]  addr,
    input         valid,      // master -> slave
    output reg    ready,      // slave -> master
    output reg [31:0] rdata,  // 读出的数据
    input [31:0]  wdata,      // 写入的数据
    input [3:0]   wmask,      // 写掩码
    input         wen         // 写使能
);
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input int wmask);

    // 状态定义
    localparam IDLE = 1'b0;
    localparam BUSY = 1'b1;
    
    reg state, next_state;
    
    // 状态转换
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    // 读写操作和状态控制
    always @(posedge clk) begin
        if (rst) begin
            rdata <= 32'b0;
        end else if (state == IDLE && valid) begin
            if (wen) begin  // 写操作
                pmem_write(addr, wdata, {{28{1'b0}}, wmask});
            end else begin  // 读操作
                rdata <= pmem_read(addr);
            end
        end
    end
    
    // 状态机和ready信号控制
    always @(*) begin
        ready = 1'b0;
        next_state = state;
        
        case (state)
            IDLE: begin
                if (valid) begin
                    next_state = BUSY;
                end
            end
            
            BUSY: begin
                ready = 1'b1;  // 操作完成，发出ready信号
                if (!valid) begin
                    next_state = IDLE;
                end
            end
        endcase
    end

endmodule