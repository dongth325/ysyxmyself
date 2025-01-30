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
    reg        ifu_sram_valid;
    wire        ifu_sram_ready;
    wire [31:0] ifu_sram_rdata;


    // 状态定义
    localparam IDLE = 1'b0;        // 空闲状态，可以发起新的取指请求
    localparam WAIT_READY = 1'b1;  // 等待SRAM返回数据状态

    reg state, next_state;
   // assign sram_addr = input_pc;


    // 状态转换（时序）
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            inst <= 32'b0;
            idu_valid <= 1'b0;
        end else begin
            state <= next_state;
            
            // 更新指令和valid信号
            if (state == WAIT_READY && ifu_sram_ready) begin
                inst <= ifu_sram_rdata;
                idu_valid <= 1'b1;
            end
            else if (idu_valid && idu_ready) begin
                idu_valid <= 1'b0;
            end
        end
    end

  reg test;
    // 组合逻辑：控制信号生成
    always @(*) begin
        // 默认值
        next_state = state;
        ifu_sram_valid = 1'b0;
        
        ifu_sram_addr = input_pc;

        case (state)
            IDLE: begin
                if (input_valid && !idu_valid) begin  // 当前指令执行完且没有未处理的指令
                    ifu_sram_valid = 1'b1;
                  test = 1;
                    next_state = WAIT_READY;
                end
            end

            WAIT_READY: begin
                ifu_sram_valid = 1'b1;  // 保持读请求有效
                if (ifu_sram_ready) begin
                    next_state = IDLE;
                    ifu_sram_valid = 1'b0;
                end
            end
        endcase
    end



  // 将从外部存储器传入的 mem_data 作为当前指令
 // assign inst = mem_data;
    // 使用 always 块打印信息
  
   /* always @(posedge clk) begin
        if (rst) begin
            idu_valid <= 0;
        end else begin
            idu_valid <= 1;       // 新指令到来时置1
            if (idu_valid) begin
                idu_valid <= 0;   // 下一周期立即清零
            end
        end

    end*/



      /*  always @(posedge clk) begin
        if (rst) begin
            idu_valid <= 0;
            inst <= 0;
        end else begin
            if (mem_data != inst) begin  // 检测到新指令
                inst <= mem_data;
                idu_valid <= 1;          // 新指令到来时置1
            end else if (idu_valid && idu_ready) begin
                idu_valid <= 0;          // 握手成功后立即清零
            end
        end
    end*/




    // IFU专用的SRAM实例
    ysyx_24090012_SRAM inst_sram(
        .clk(clk),
        .rst(rst),
        .addr(ifu_sram_addr),
        .valid(ifu_sram_valid),
        .ready(ifu_sram_ready),
        .rdata(ifu_sram_rdata),
        // 写相关信号全部置0
        .wdata(32'b0),
        .wmask(4'b0),
        .wen(1'b0)
    );







endmodule
