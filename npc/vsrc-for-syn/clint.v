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

    // 配置参数
    localparam CLOCK_DIV_SHIFT = 16;  // 相当于除以65536 (2^16)
    localparam MTIME_WIDTH = 64;
    
    // 寄存器定义
    reg [MTIME_WIDTH-1:0] mtime;
    reg [1:0] state;
    
    // 状态定义
    localparam S_IDLE = 2'b00;
    localparam S_READ = 2'b01;
    
    // 分频计数器（减少mtime更新频率）
    reg [15:0] div_counter;
    wire mtime_inc = (div_counter == 0);
    
    // 分频计数逻辑
    always @(posedge clk) begin
        if (rst) div_counter <= 0;
        else div_counter <= div_counter + 1;
    end
    
    // mtime计数器（低频更新）
    always @(posedge clk) begin
        if (rst) mtime <= 0;
        else if (mtime_inc) mtime <= mtime + 1;
    end
    
    // AXI状态机
    always @(posedge clk) begin
        if (rst) begin
            state <= S_IDLE;
            s_axi_arready <= 1'b0;
            s_axi_rvalid <= 1'b0;
            s_axi_rdata <= 32'b0;
        end else begin
            case (state)
                S_IDLE: begin
                    s_axi_arready <= 1'b1;
                    s_axi_rvalid <= 1'b0;
                    
                    if (s_axi_arvalid) begin
                        state <= S_READ;
                        // 直接输出对应数据（组合逻辑简化）
                        s_axi_rdata <= (s_axi_araddr[3:0] == 4'h8) ? 
                                      mtime[31:0] : 
                                      mtime[63:32];
                    end
                end
                
                S_READ: begin
                    s_axi_arready <= 1'b0;
                    s_axi_rvalid <= 1'b1;
                    
                    if (s_axi_rready) begin
                        state <= S_IDLE;
                        s_axi_rvalid <= 1'b0;
                    end
                end
            endcase
        end
    end

    assign s_axi_rresp = 2'b00;  // 总是返回OK

endmodule