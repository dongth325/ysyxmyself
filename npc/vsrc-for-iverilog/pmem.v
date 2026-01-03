module pmem (
    input  clk,
    input  reset,

    // AXI Slave (to NPC Master)
    // Write Address
    output reg        io_master_awready,
    input             io_master_awvalid,
    input  [31:0]     io_master_awaddr,
    input  [3:0]      io_master_awid,
    input  [7:0]      io_master_awlen,
    input  [2:0]      io_master_awsize,
    input  [1:0]      io_master_awburst,
    // Write Data
    output reg        io_master_wready,
    input             io_master_wvalid,
    input  [31:0]     io_master_wdata,
    input  [3:0]      io_master_wstrb,
    input             io_master_wlast,
    // Write Resp
    input             io_master_bready,
    output reg        io_master_bvalid,
    output reg [1:0]  io_master_bresp,
    output reg [3:0]  io_master_bid,

    // Read Address
    output reg        io_master_arready,
    input             io_master_arvalid,
    input  [31:0]     io_master_araddr,
    input  [3:0]      io_master_arid,
    input  [7:0]      io_master_arlen,
    input  [2:0]      io_master_arsize,
    input  [1:0]      io_master_arburst,
    // Read Data
    input             io_master_rready,
    output reg        io_master_rvalid,
    output reg [31:0] io_master_rdata, // Master最终拿到的数据 (大端序)
    output reg [1:0]  io_master_rresp,
    output reg        io_master_rlast,
    output reg [3:0]  io_master_rid
);

    // 参数与内存
    parameter MEM_BASE = 32'h80000000;
    parameter MEM_SIZE = 128 * 1024 * 1024 / 4;  // 128MB -> words
    
    reg [31:0] mem [0:MEM_SIZE-1]; // 内存以小端序格式存储数据

    // 写通道状态
    reg [1:0]  w_state;
    reg [31:0] w_addr;
    reg [3:0]  w_id;
    reg [31:0] w_idx;

    // 读通道状态
    reg [1:0]  r_state;
    reg [31:0] r_base_addr;
    reg [3:0]  r_id;
    reg [7:0]  r_len;     // << 新增：用于保存 ARLEN (8位)
    reg [1:0]  r_burst;   // << 新增：用于保存 ARBURST (2位)
    reg [7:0]  r_cnt;     // 使用 8 位计数器，可支持 AXI 标准的最大突发长度 (r_len最大255)
    reg [31:0] r_idx; 
    
    // 用于字节序转换的寄存器
    reg [31:0] r_data_le; // 从mem中取出的原始小端序数据
    reg [31:0] r_data_be; // 转换后的大端序数据

    integer i;

    // 初始化避免X传播
    initial begin
        for (i = 0; i < MEM_SIZE; i = i + 1) mem[i] = 32'h0;
        
       // $display("INFO: Attempting to load program.hex...");
        $readmemh("/home/dongtaiheng/desktopp/ffuck/ysyx-workbench/am-kernels/benchmarks/microbench/build/program.hex", mem);
        $display("INFO: Program load complete.");
        $display("DEBUG: First Instruction (mem[0]) should be: %h", mem[0]); 

        w_state = 0; w_addr = 0; w_id = 0; w_idx = 0;
        r_state = 0; r_base_addr = 0; r_id = 0; r_cnt = 0; r_idx = 0;
        r_len = 8'h0; r_burst = 2'b00; // 初始化新增的寄存器
        
        r_data_le = 32'h0; 
        r_data_be = 32'h0; 

        io_master_awready = 1'b1;
        io_master_wready  = 1'b1;
        io_master_bvalid  = 1'b0;
        io_master_bresp   = 2'b00;
        io_master_bid     = 4'b0;

        io_master_arready = 1'b1;
        io_master_rvalid  = 1'b0;
        io_master_rdata   = 32'h0;
        io_master_rresp   = 2'b00;
        io_master_rlast   = 1'b0;
        io_master_rid     = 4'b0;
    end

    // 写通道：单拍写即可 (保持不变)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            w_state <= 0;
            io_master_awready <= 1'b1;
            io_master_wready  <= 1'b1;
            io_master_bvalid  <= 1'b0;
            io_master_bresp   <= 2'b00;
        end else begin
            case (w_state)
                0: begin
                    if (io_master_awvalid && io_master_awready) begin
                        w_addr          <= io_master_awaddr;
                        w_id            <= io_master_awid;
                        io_master_awready <= 1'b0;
                        w_state         <= 1;
                    end
                end
                1: begin
                    if (io_master_wvalid && io_master_wready) begin
                        if (w_addr >= MEM_BASE && w_addr < MEM_BASE + (MEM_SIZE<<2)) begin
                            w_idx = (w_addr - MEM_BASE) >> 2;
                            
                            if (io_master_wstrb[0]) mem[w_idx][7:0]   <= io_master_wdata[31:24];
                            if (io_master_wstrb[1]) mem[w_idx][15:8]  <= io_master_wdata[23:16];
                            if (io_master_wstrb[2]) mem[w_idx][23:16] <= io_master_wdata[15:8];
                            if (io_master_wstrb[3]) mem[w_idx][31:24] <= io_master_wdata[7:0];
                        end

                         
                       
                        io_master_wready <= 1'b0;
                        io_master_bvalid <= 1'b1;
                        io_master_bresp  <= 2'b00;
                        io_master_bid    <= w_id;
                        w_state          <= 2;
                    end
                   
                end
                2: begin
                    if (io_master_bready) begin
                        io_master_bvalid  <= 1'b0;
                        io_master_awready <= 1'b1;
                        io_master_wready  <= 1'b1;
                        w_state           <= 0;
                    end
                end
                default: w_state <= 0;
            endcase
        end
    end


    // 读通道：动态长度 Burst (RLAST 和 字节序转换)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            // 重置所有寄存器和输出信号
            r_state           <= 0;
            io_master_arready <= 1'b1;  // 默认准备好接收 AR 请求
            io_master_rvalid  <= 1'b0;
            io_master_rlast   <= 1'b0;
            r_cnt             <= 0;
            
            // 新增的 AXI 信号捕获寄存器
            r_len             <= 8'h0;
            r_burst           <= 2'b00; 
            
            // 其它寄存器
            r_data_le         <= 32'h0;
            r_data_be         <= 32'h0;
        end else begin
            // rvalid 信号在状态 1 (数据传输) 期间拉高
            io_master_rvalid <= (r_state == 1); 
            
            case (r_state)
                // 状态 0: 等待 Read 地址请求 (AR)
                0: begin
                    io_master_rlast    <= 1'b0;
                    
                    if (io_master_arvalid && io_master_arready) begin
                        // 1. 捕获地址、ID、突发长度和类型
                        //r_base_addr        <= {io_master_araddr[31:4], 4'b0000}; // 对齐到 16 字节边界
                        r_base_addr        <= io_master_araddr;
                        r_id               <= io_master_arid;
                        r_len              <= io_master_arlen;    // << 捕获突发长度 ARLEN
                        r_burst            <= io_master_arburst;  // << 捕获突发类型 ARBURST
                        r_cnt              <= 0;
                        
                        // 2. 拉低 arready 并进入数据传输状态
                        io_master_arready  <= 1'b0;
                        r_state            <= 1; 
                    end else begin
                        io_master_arready  <= 1'b1; // 保持准备好接收
                    end
                end
                
                // 状态 1: 数据传输 (R)
                1: begin
                    // A. 地址计算：基于 r_base_addr 和 r_cnt
                    // 注意：这里只实现了 INCR 突发逻辑。FIXED 或 WRAP 需要更复杂的逻辑。
                    if (r_burst == 2'b01) begin // INCR 突发类型
                        // r_cnt 代表已经传输了多少拍，r_base_addr 是起始地址
                        r_idx = ((r_base_addr - MEM_BASE) >> 2) + r_cnt;
                    end else begin 
                        // 简单处理：对于非 INCR 类型，地址不递增，只取首地址数据
                        r_idx = (r_base_addr - MEM_BASE) >> 2; 
                    end

                    // B. 数据获取 (小端序)
                    if (r_base_addr >= MEM_BASE && r_base_addr < MEM_BASE + (MEM_SIZE<<2)) begin
                        r_data_le <= mem[r_idx];
                    end else begin
                        r_data_le <= 32'h0; // 地址越界返回 0
                    end
                    
                    // C. 大小端转换并输出 (从机通常输出大端序数据)
                    // 注意：这里直接使用了 mem[r_idx] 的组合逻辑输出，但 r_data_le 和 r_data_be 
                    // 寄存器通常用于流水线操作。为简化和避免可能的时序问题，**直接使用 mem[r_idx]**
                    // 进行组合逻辑输出，但这里我们沿用你的寄存器方式，需要在下一拍生效。
                    io_master_rdata  <= {
                        mem[r_idx][7:0],    // 原始 Byte 0 (最低地址) 变为最高位
                        mem[r_idx][15:8],   // 原始 Byte 1 
                        mem[r_idx][23:16],  // 原始 Byte 2
                        mem[r_idx][31:24]   // 原始 Byte 3 (最高地址) 变为最低位
                    };
                    
                    // D. 状态输出
                    io_master_rresp <= 2'b00; // OKAYAY 响应
                    io_master_rid   <= r_id;
                    
                    // E. 动态判断 RLAST：当传输计数 r_cnt 等于 ARLEN 寄存器 r_len 时，置位 RLAST
                    io_master_rlast <= (r_cnt == r_len); 

                    // F. 状态和计数器更新 (在 rready 握手成功后更新)
                    if (io_master_rready) begin
                        if (r_cnt == r_len) begin // 本次是最后一次传输
                            r_state           <= 0;
                            io_master_arready <= 1'b1; // 重新准备接收新的 AR 请求
                        end else begin
                            r_cnt <= r_cnt + 1; // 递增计数器
                            r_state <= 1;       // 保持在数据传输状态
                        end
                    end 
                end
                
                // 状态 default: 错误恢复
                default: begin
                    r_state           <= 0;
                    io_master_arready <= 1'b1;
                    io_master_rvalid  <= 1'b0;
                    io_master_rlast   <= 1'b0;
                end
            endcase
        end
    end

endmodule