module ysyx_24090012_IDU(
  input [31:0] inst,
  input [31:0] pc,
  
  output reg [6:0] opcode,
  output reg [2:0] func3,
  output reg [6:0] func7,
  output reg [4:0] rs1,
  output reg [4:0] rs2,
  output reg [4:0] rd,
  output reg [3:0] alu_op,
  output reg [31:0] imm
);

    always @(*) begin
    opcode = inst[6:0];
    func3  = inst[14:12];
    func7  = inst[31:25];
    rs1    = inst[19:15];
    rs2    = inst[24:20];
    rd     = inst[11:7];
   // $display("At time %t: idu touch PC = 0x%08x", $time, pc);

    // 根据指令类型，提取立即数和 ALU 操作码
    case (opcode)
         7'b0010011: begin  // I-type (ADDI, SEQZ)
        imm = {{20{inst[31]}}, inst[31:20]};
        if (func3 == 3'b000) begin
          alu_op = 4'b0000;  // ADDI
        end else if (func3 == 3'b110) begin
          alu_op = 4'b1010;  // SEQZ
        end else begin
          alu_op = 4'b1111;  // 未实现的操作
        end
      end
      7'b0110111: begin  // LUI
        imm = {inst[31:12], 12'b0};
        alu_op = 4'b0001;  // LUI
      end
      7'b0110011: begin  // R-type (ADD, SUB)
        imm = 32'b0;  // R-type 没有立即数
        if (func3 == 3'b000 && func7 == 7'b0000000) begin
          alu_op = 4'b0101;  // ADD
        end else if (func3 == 3'b000 && func7 == 7'b0100000) begin
          alu_op = 4'b1100;  // SUB
        end else begin
          alu_op = 4'b1111;  // 未实现的操作
        end
      end
      7'b0010111: begin  // AUIPC
        imm = {inst[31:12], 12'b0};
        alu_op = 4'b0010;  // AUIPC
      end
      7'b1101111: begin  // JAL
        imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
        //$display("At time %t: idu   jal  imm= 0x%08x", $time, imm);
        alu_op = 4'b0011;  // JAL
      end
      7'b1100111: begin  // JALR
        imm = {{20{inst[31]}}, inst[31:20]};
        alu_op = 4'b0100;  // JALR
      end
      7'b1100011: begin  // B-type (BEQ, BNE)
        imm = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
        if (func3 == 3'b000) begin
          alu_op = 4'b0110;  // BEQ
        end else if (func3 == 3'b001) begin
          alu_op = 4'b0111;  // BNE
        end else begin
          alu_op = 4'b1111;  // 未实现的操作
        end
      end
      7'b0000011: begin  // I-type (LW)
        imm = {{20{inst[31]}}, inst[31:20]};
        alu_op = 4'b1000;  // LW
      end
      7'b0100011: begin  // S-type (SW)
        imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
        alu_op = 4'b1001;  // SW
      end
      7'b1110011: begin  // SYSTEM (EBREAK)
        imm = 32'b0;
        alu_op = 4'b1011;  // EBREAK
      end

      // 其他指令类型
      default: begin
        imm = 32'b0;
        alu_op = 4'b1111;  // NOP 或未实现
      end
    endcase
  end
endmodule
