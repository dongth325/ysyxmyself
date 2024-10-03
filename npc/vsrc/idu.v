module ysyx_24090012_IDU(
  input [31:0] inst,
  output reg [4:0] rs1,
  output reg [4:0] rs2,
  output reg [4:0] rd,
  output reg [31:0] imm,
  output reg [6:0] opcode,
  output reg [2:0] func3,
  output reg [6:0] func7,
  output reg [3:0] alu_op
);

  always @(*) begin
    opcode = inst[6:0];
    func3  = inst[14:12];
    func7  = inst[31:25];
    rs1    = inst[19:15];
    rs2    = inst[24:20];
    rd     = inst[11:7];

    // 根据指令类型，提取立即数和 ALU 操作码
    case (opcode)
           7'b0010011: begin  // I-type (e.g., addi)
        imm = {{20{inst[31]}}, inst[31:20]};
        alu_op = 4'b0000;  // ADD
      end
        7'b0110111: begin  // LUI
        imm = {inst[31:12], 12'b0};
        alu_op = 4'b0001;  // LUI
      end


      7'b0010111: begin  // AUIPC
        imm = {inst[31:12], 12'b0};
        alu_op = 4'b0010;  // AUIPC
      end
        7'b1101111: begin  // JAL
        imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
        alu_op = 4'b0011;  // JAL
      end
      7'b1100111: begin  // JALR
        imm = {{20{inst[31]}}, inst[31:20]};
        alu_op = 4'b0100;  // JALR
      end
      // 其他指令类型
      default: begin
        imm = 32'b0;
        alu_op = 4'b1111;  // NOP 或未实现
      end
    endcase
  end
endmodule
