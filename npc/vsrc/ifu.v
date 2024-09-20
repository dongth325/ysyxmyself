module IFU(
    input clk,
    input rst,
    output reg [31:0] pc,
    output [31:0] inst,
    input [31:0] mem_data  // 从C++侧存储器传来的数据
);

  // 初始化PC值
  initial begin
    pc = 32'h80000000;
  end

  // 每个时钟周期更新PC值，并从外部接收指令
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      pc <= 32'h80000000;  // 复位PC
    end else begin
      pc <= pc + 4;  // 每次递增PC，假设指令长度为4字节
    end
  end

  // 将从外部存储器传入的mem_data作为当前指令
  assign inst = mem_data;

endmodule
