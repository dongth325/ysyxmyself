module ysyx_24090012_NPC(
  input clk,
  input rst,
  output reg [31:0] pc,
  input [31:0] mem_data,
  output reg ebreak_flag,
  output reg [31:0] exit_code
);
  import "DPI-C" function void ebreak(input int exit_code);

  wire [4:0] rs1, rs2, rd;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [6:0] func7;
  wire [31:0] imm;
  wire [3:0] alu_op;
  wire [31:0] rs1_data, rs2_data, result, next_pc;
  wire wen;
  wire [31:0] inst;

  // 实例化各个模块
  ysyx_24090012_IFU ifu(.clk(clk), .rst(rst), .pc(pc), .inst(inst), .mem_data(mem_data));
  ysyx_24090012_IDU idu(.inst(inst), .rs1(rs1), .rs2(rs2), .rd(rd), .imm(imm), .opcode(opcode), .func3(func3), .func7(func7), .alu_op(alu_op));
  ysyx_24090012_RegisterFile regfile(
    .clk(clk),
    .rst(rst),
    .raddr1(rs1),
    .raddr2(rs2),
    .waddr(rd),
    .wdata(result),
    .wen(wen),
    .rdata1(rs1_data),
    .rdata2(rs2_data)
  );
  ysyx_24090012_EXU exu(.pc(pc), .rs1_data(rs1_data), .imm(imm), .alu_op(alu_op), .result(result), .next_pc(next_pc));

  // 写使能信号
  assign wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1101111 || opcode == 7'b1100111);

  // 更新 PC
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      pc <= 32'h80000000;
      ebreak_flag <= 0;

    end else if (inst == 32'h00100073) begin  // ebreak 指令
      ebreak_flag <= 1;
      exit_code <= regfile.rf[10];  // 获取 a0 寄存器的值
      ebreak(regfile.rf[10]);       // 调用 DPI-C 函数
      
    end else if (alu_op == 4'b0011 || alu_op == 4'b0100) begin  // JAL 或 JALR
      pc <= next_pc;
    end else begin
      pc <= next_pc;
    end
  end
endmodule

