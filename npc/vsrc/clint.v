module ysyx_24090012_CLINT (
    input wire         clk,
    input wire         rst,
    
    // AXI4-Lite Slave Interface
    // Read Address Channel
    input  wire        s_axi_arvalid,
    output reg         s_axi_arready,
    input  wire [31:0] s_axi_araddr,
    
    // Read Data Channel
    output reg         s_axi_rvalid,
    input  wire        s_axi_rready,
    output reg [31:0]  s_axi_rdata,
    output wire [1:0]  s_axi_rresp
);

    // CLINT寄存器 - mtime是64位计数器
    reg [63:0] mtime;
    
    // AXI4-Lite状态机状态
    localparam IDLE = 1'b0;
    localparam READ = 1'b1;
    
    reg state;
    reg next_state;
    
    // 保存输入信号的寄存器
    reg [31:0] addr_r;  // 保存地址
    
    // mtime计数器 - 每个时钟周期加1
    always @(posedge clk) begin
        if (rst) begin
            mtime <= 64'h0;
        end else begin
            mtime <= mtime + 64'h1;
        end
    end
    
    // 状态寄存器更新
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    // 保存输入信号
    always @(posedge clk) begin
        if (rst) begin
            addr_r <= 32'h0;
        end else if (state == IDLE && s_axi_arvalid) begin
            addr_r <= s_axi_araddr;  // 在IDLE状态且有效地址时保存地址
        end
    end
    
    // 下一状态逻辑
    always @(*) begin
        case (state)
            IDLE: begin
                if (s_axi_arvalid) begin
                    next_state = READ;
                end else begin
                    next_state = IDLE;
                end
            end
            
            READ: begin
                if (s_axi_rready) begin
                    next_state = IDLE;
                end else begin
                    next_state = READ;
                end
            end
            
            default: next_state = IDLE;
        endcase
    end
    
    // 输出逻辑
    always @(posedge clk) begin
        if (rst) begin
            s_axi_arready <= 1'b0;
            s_axi_rvalid <= 1'b0;
            s_axi_rdata <= 32'h0;
        end else begin
            case (state)
                IDLE: begin
                    s_axi_arready <= 1'b1;  // 在IDLE状态下准备好接收地址
                    s_axi_rvalid <= 1'b0;   // 在IDLE状态下不提供数据
                end
                
                READ: begin
                    s_axi_arready <= 1'b0;  // 在READ状态下不接收新地址
                    s_axi_rvalid <= 1'b1;   // 在READ状态下提供数据
                    
                    // 地址解码
                    case (addr_r[3:0])
                        4'h8: s_axi_rdata <= mtime[31:0];   // mtime低32位
                        4'hC: s_axi_rdata <= mtime[63:32];  // mtime高32位
                        default: s_axi_rdata <= 32'h0;      // 无效地址返回0
                    endcase
                end
            endcase
        end
    end

    // 响应状态 - 始终为OK
    assign s_axi_rresp = 2'b00;

endmodule