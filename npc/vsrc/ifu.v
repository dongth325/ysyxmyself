module ysyx_24090012_IFU(
  input clk,
  input rst,
  input [31:0] pc,
  output reg [31:0] inst,
  output reg idu_valid,
  input idu_ready,
  input [31:0] mem_data
);
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



        always @(posedge clk) begin
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
    end
endmodule
