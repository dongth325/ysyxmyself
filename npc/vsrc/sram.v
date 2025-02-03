module ysyx_24090012_SRAM (
    input clk,
    input rst,
    
    // 总线接口 (slave)
    input [31:0]  addr,
    input         arvalid,      // master -> slave
    output reg    arready,      // slave -> master
    output reg [31:0] rdata,  // 读出的数据
    input [31:0]  wdata,      // 写入的数据
    input [3:0]   wmask,      // 写掩码
    input         wen,         // 写使能
      output reg    rvalid,     // 数据有效 (slave -> master)
    input         rready      // 数据准备好 (master -> slave)
);
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input int wmask);

   // 状态定义
    localparam IDLE      = 2'b00;  // 空闲状态
    localparam ADDR_PHASE = 2'b01; // 地址握手阶段
    localparam DATA_PHASE = 2'b10; // 数据握手阶段

    reg [1:0] state, next_state;
    
    // 状态转换
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    // 读写操作
    always @(posedge clk) begin
        if (rst) begin
            rdata <= 32'b0;
        end else if (state == ADDR_PHASE ) begin
            if (wen) begin  // 写操作
                pmem_write(addr, wdata, {{28{1'b0}}, wmask});
            end else begin  // 读操作
                rdata <= pmem_read(addr);
            end
        end
    end
    
  // 状态机逻辑
    always @(*) begin
        // 默认值
        next_state = state;
        arready = 0;
        rvalid = 0;
        
        case (state)
            IDLE: begin
                if (arvalid) begin
                    arready = 1;  // 地址准备好
                    next_state = ADDR_PHASE;
                end
            end
            
            ADDR_PHASE: begin
                arready = 1;  // 保持地址准备好
                if (arvalid) begin
                    arready = 0;  // 地址已接收
                    next_state = DATA_PHASE;
                end
            end
            
            DATA_PHASE: begin
                rvalid = 1;  // 数据有效
                if (rready) begin
                    rvalid = 0;  // 数据已接收
                    next_state = IDLE;
                end
            end
        endcase
    end
endmodule