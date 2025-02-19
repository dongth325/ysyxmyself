module ysyx_24090012_IFU(
  input clk,
  input rst,
  input [31:0] pc,
  input reg [31:0] input_pc,
  input inst_done,
  
  input input_valid,

  output reg [31:0] inst,
  output reg idu_valid,
  input idu_ready

  //input [31:0] mem_data,



     /* output reg [31:0] ifu_sram_addr,
    output reg ifu_sram_valid,
    input ifu_sram_ready,
    input [31:0] ifu_sram_rdata

    output reg [31:0] ifu_sram_wdata,
    output reg [3:0] ifu_sram_wmask,
    output reg ifu_sram_wen*/

);
    reg [31:0] ifu_sram_addr;
     reg        ifu_arvalid;    // 地址有效
    wire       ifu_arready;    // 地址准备好
   wire        ifu_rvalid;    // 数据有效
    wire [31:0] ifu_rdata;     // 读出的数据;
    reg         ifu_rready;    // 数据准备好


      // 状态定义
    localparam IDLE       = 2'b00;  // 空闲状态
    localparam ADDR_PHASE = 2'b01;  // 地址握手阶段
    localparam DATA_PHASE = 2'b10;  // 数据握手阶段

    reg [1:0] state, next_state;
   


    // 状态转换（时序）
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            inst <= 32'b0;
            idu_valid <= 1'b0;
            ifu_rready <= 1'b0;
        end else begin
            state <= next_state;

            // 更新指令和valid信号
            if (state == DATA_PHASE && ifu_rvalid && ifu_rready) begin
                inst <= ifu_rdata;  // 从SRAM读取指令
                idu_valid <= 1'b1;  // 指令有效
                ifu_rready <= 1'b0; // 复位rready
            end
            else if (idu_valid && idu_ready) begin
                idu_valid <= 1'b0;  // 指令已被IDU接收
            end
        end
    end

  reg test;
    // 组合逻辑：控制信号生成
    always @(*) begin
        // 默认值
        next_state = state;
        ifu_arvalid = 1'b0;
        ifu_rready = 1'b0;
        ifu_sram_addr = input_pc;

         case (state)
            IDLE: begin
                if (input_valid && !idu_valid) begin  // 当前指令执行完且没有未处理的指令
                    ifu_arvalid = 1'b1;  // 地址有效
                    next_state = ADDR_PHASE;
                end
            end

            ADDR_PHASE: begin
                ifu_arvalid = 1'b1;  // 保持地址有效
                if (ifu_arready) begin
                    ifu_arvalid = 1'b0;  // 地址已接收
                    next_state = DATA_PHASE;
                end
            end

            DATA_PHASE: begin
                ifu_rready = 1'b1;  // 准备好接收数据
                if (ifu_rvalid && ifu_rready) begin
                    next_state = IDLE;
                end
            end
        endcase
    end







    ysyx_24090012_SRAM inst_sram(
        .clk(clk),
        .rst(rst),
        .addr(ifu_sram_addr),      // 地址
        .arvalid(ifu_arvalid),     // 地址有效
        .arready(ifu_arready),     // 地址准备好
        .rdata(ifu_rdata),         // 读出的数据
        .rvalid(ifu_rvalid),       // 数据有效
        .rready(ifu_rready),       // 数据准备好
        // 写相关信号全部置0
        .wdata(32'b0),
        .wmask(4'b0),
        .wen(1'b0)
    );




endmodule
