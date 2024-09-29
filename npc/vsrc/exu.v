module ysyx_24090012_EXU(
  input [31:0] pc,
  input [31:0] rs1_data,
  input [31:0] imm,
  input [3:0] alu_op,
  output reg [31:0] result,
  output reg [31:0] next_pc
);
  always @(*) begin
    case (alu_op)
      4'b0000: result = rs1_data + imm;  // ADDI
      4'b0001: result = imm;             // LUI
      4'b0010: result = pc + imm;        // AUIPC
      4'b0011: begin                     // JAL
        result = pc + 4;                 // 保存返回地址
        next_pc = pc + imm;              // 跳转
      end
      4'b0100: begin                     // JALR
        result = pc + 4;                 // 保存返回地址
        next_pc = (rs1_data + imm) & ~1; // 跳转
      end
      default: result = 32'b0;           // 未实现的操作
    endcase
  end
endmodule
