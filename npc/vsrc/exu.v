module ysyx_24090012_EXU(
  input [31:0] pc,
  input [31:0] rs1_data,
  input [31:0] rs2_data,
  input [31:0] imm,
  input [3:0] alu_op,
  output reg [31:0] result,
  output reg [31:0] next_pc
);
 import "DPI-C" function void pmem_write(input int addr, input int data, input int mask);
 import "DPI-C" function int pmem_read(input int addr);

  
    always @(next_pc) begin
     // $display("next_pc change to = 0x%08x", $time, next_pc);
    end
    always @(*) begin
    // 初始化默认值，防止锁存器推断
    result = 32'b0;
   // $display("At time %t: exu touch before PC = 0x%08x", $time, pc);
     // 根据 alu_op 判断是否需要在 case 中单独赋值 next_pc
    if (alu_op == 4'b0011 || alu_op == 4'b0100 || alu_op == 4'b0110 || alu_op == 4'b0111) begin
      // 对于需要单独处理的指令，在 case 中赋值 next_pc
      // 为了防止锁存器推断，先给 next_pc 赋一个默认值
     next_pc = 32'b0;
      //$display("At time %t: exu middle PC = 0x%08x", $time, pc);
    end else begin
      // 对于其他指令，统一赋值 next_pc = pc + 4
      next_pc = pc + 4;
      //$display("At time %t: exu after next_pc = 0x%08x", $time, next_pc);
      //$display("At time %t: exu after PC = 0x%08x", $time, pc);
    end
    
    case (alu_op)
      4'b0000: begin
        // ADDI
        result = rs1_data + imm;
      end
      4'b0001: begin
        // LUI
        result = imm;
      end
      4'b0010: begin
        // AUIPC
        result = pc + imm;
      end
      4'b0011: begin
        // JAL
        result = pc + 4;          // 保存返回地址
        next_pc = pc + imm;       // 跳转到目标地址
       // $display("At time %t: exu  jal pc = 0x%08x", $time, pc);
       // $display("At time %t: exu next_pc = 0x%08x", $time, next_pc);
      end
      4'b0100: begin
        // JALR
        result = pc + 4;                                 // 保存返回地址
        next_pc = (rs1_data + imm) & ~1;                // 计算跳转地址（必须是偶数地址）
      end
      4'b0101: begin
        // ADD (R-type)
        result = rs1_data + rs2_data;
      end
      4'b0110: begin
        // BEQ
        if (rs1_data == rs2_data)
          next_pc = pc + imm;     // 跳转地址
      end
      4'b0111: begin
        // BNE
        if (rs1_data != rs2_data)
          next_pc = pc + imm;     // 跳转地址
      end
      4'b1000: begin
        // LW
         result = pmem_read(rs1_data + imm);// 计算内存地址并从该地址读取数据
      end
      4'b1001: begin
        // SW
        result = rs1_data + imm;  // 计算存储地址
         pmem_write(result, rs2_data, 4);  // 将 rs2_data 写入 result 指定的地址，mask为4表示写入4个字节
      end
      4'b1010: begin
        // SEQZ (Set Equal to Zero)
        result = (rs1_data == 0) ? 1 : 0;
      end
      4'b1011: begin
        // EBREAK
        // 不需要在 EXU 中进行操作，在 NPC 中处理
      end
      4'b1100: begin
        // SUB (R-type)
        result = rs1_data - rs2_data;
      end
      default: begin
        // NOP 或未实现的操作
        // 已经在开始时赋值了 result 和 next_pc 的默认值
      end
    endcase
  end
endmodule
