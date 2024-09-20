module ysyx_24090012_EXU(
  input [31:0] rs1_data,
  input [31:0] imm,
  output [31:0] result
);

  // addi指令的执行：加法运算
  assign result = rs1_data + imm;

endmodule
