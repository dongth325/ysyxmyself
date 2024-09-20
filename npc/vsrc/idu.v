module ysyx_24090012_IDU(
  input [31:0] inst,
  output [4:0] rs1,
  output [4:0] rd,
  output [31:0] imm
);

  // 提取立即数、源寄存器和目标寄存器
  assign rs1 = inst[19:15];  // 源寄存器
  assign rd  = inst[11:7];   // 目标寄存器
  assign imm = {{20{inst[31]}}, inst[31:20]};  // 立即数扩展

endmodule
