module ysyx_24090012_IFU(
  input clk,
  input rst,
  input [31:0] pc,
  output [31:0] inst,
  input [31:0] mem_data
);
  // 将从外部存储器传入的 mem_data 作为当前指令
  assign inst = mem_data;
    // 使用 always 块打印信息
    always @(*) begin
      //$display("At time %t: ifu touch PC = 0x%08x", $time, pc);
    end

  always @(posedge clk) begin
    //$display("At time %t: ifu PC = 0x%08x", $time, pc);
  end
endmodule
