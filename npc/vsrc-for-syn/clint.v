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
    
    reg state;
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
    always @(posedge clk) begin
        if (rst) div_counter <= 0;
        else div_counter <= div_counter + 1;
    end
    
    // mtime计数器（低频更新）
    always @(posedge clk) begin
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
    always @(posedge clk) begin
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