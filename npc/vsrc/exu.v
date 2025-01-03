module ysyx_24090012_EXU(
    input clk,  // 添加时钟输入
  input [31:0] pc,
  input [31:0] rs1_data,
  input [31:0] rs2_data,
  input [31:0] imm,
  input [5:0] alu_op,
    input [31:0] mtvec,//csr csr
    input [31:0] mepc,//csr csr
  output reg [31:0] result,
  input [31:0] csr_rdata,//csr csr csr csr
output reg [31:0] csr_wdata,//csr csr csr csr
output reg csr_wen,//csr csr csr csr

  output reg [31:0] next_pc
);
 import "DPI-C" function void pmem_write(input int addr, input int data, input int mask);
 import "DPI-C" function int pmem_read(input int addr);

  
    always @(next_pc) begin
     // $display("next_pc change to = 0x%08x", $time, next_pc);
    end
    always @(posedge clk) begin
      
    // 初始化默认值，防止锁存器推断
    result = 32'b0;
   // $display("At time %t: exu touch before PC = 0x%08x", $time, pc);
     // 根据 alu_op 判断是否需要在 case 中单独赋值 next_pc
    if (alu_op == 6'b000011 || alu_op == 6'b000100 || alu_op == 6'b000110 || alu_op == 6'b000111 || alu_op == 6'b110010) begin
      // 对于需要单独处理的指令，在 case 中赋值 next_pc
      // 为了防止锁存器推断，先给 next_pc 赋一个默认值
     next_pc = 32'b0;
      //$display("At time %t: exu middle PC = 0x%08x", $time, pc);
    end else begin
      // 对于其他指令，统一赋值 next_pc = pc + 4
      next_pc = pc + 4;
     
    end
    //$display("4444444444");
    case (alu_op)
      6'b000000: begin
        // ADDI
        result = rs1_data + imm;
        
      end
      6'b000001: begin
        // LUI
        result = imm;
      end
      6'b000010: begin
        // AUIPC
        result = pc + imm;
      end
      6'b000011: begin
        // JAL
        result = pc + 4;          // 保存返回地址
        next_pc = pc + imm;       // 跳转到目标地址
       // $display("At time %t: exu  jal pc = 0x%08x", $time, pc);
       // $display("At time %t: exu next_pc = 0x%08x", $time, next_pc);
      end
      6'b000100: begin
        // JALR
        result = pc + 4;                                 // 保存返回地址
        next_pc = (rs1_data + imm) & ~1;                // 计算跳转地址（必须是偶数地址）
      end
      6'b000101: begin
        // ADD (R-type)
        result = rs1_data + rs2_data;
      end
      6'b000110: begin
        // BEQ
        if (rs1_data == rs2_data)
          next_pc = pc + imm;     // 跳转地址
        else
        next_pc = pc + 4;
      end
      6'b000111: begin
        // BNE
        if (rs1_data != rs2_data)
          next_pc = pc + imm;     // 跳转地址
         else
        next_pc = pc + 4;  
      end
      6'b001000: begin
        // LW
       // $display("Memory at 0x80000220 = %h", pmem_read(32'h80000220));
        


       // $display( "rs1_data = %h from (exu.v)",  rs1_data);
        //$display( "rs2_data = %h from (exu.v)",  rs2_data);
        //$display( "imm = %h from (exu.v)",  imm);
         result = pmem_read(rs1_data + imm);// 计算内存地址并从该地址读取数据
        // $display( "result = %h from (exu.v)",  result);
      end
      6'b001001: begin
        // SW
        result = rs1_data + imm;  // 计算存储地址
         pmem_write(result, rs2_data, 4);  // 将 rs2_data 写入 result 指定的地址，mask为4表示写入4个字节
      end

      6'b001010: begin
        // SEQZ (Set Equal to Zero)
        
        result = (rs1_data == 0) ? 1 : 0;
       
      end
      6'b001011: begin
        // EBREAK
        // 不需要在 EXU 中进行操作，在 NPC 中处理
      end
      6'b001100: begin
        // SUB (R-type)
        result = rs1_data - rs2_data;
      end
      6'b001101: begin
    result = rs1_data << rs2_data[4:0];  // SLL 使用 rs2_data 的低 5 位作为移位位数
      end
      6'b001110: begin
        // XORI
        result = rs1_data ^ imm;
    end
    6'b001111: begin
    // ZEXT.B (Zero Extend Byte)
    result = {24'b0, rs1_data[7:0]};  // 提取 rs1_data 的最低 8 位，并将其扩展为 32 位
    end
    6'b010000: begin
    // AND (R-type)
    result = rs1_data & rs2_data;
    end 
    6'b010001: begin
  // SRAI (算术右移，带符号扩展)
  result = $signed(rs1_data) >>> imm[4:0];  // 使用立即数的低 5 位作为移位位数
    end
    6'b010010: begin
  // SNEZ (Set Not Equal to Zero)
  result = (rs2_data != 0) ? 32'b1 : 32'b0;
  //$display("rrrrrrrrrrrs1data = %h from (exu.v)",rs1_data);
  //$display("rrrrrrrrrrrs2data = %h from (exu.v)",rs2_data);
    end
    6'b010011: begin
  // ANDI (按位与立即数)
  result = rs1_data & imm;
    end 6'b010100: begin
    // OR (R-type)
    result = rs1_data | rs2_data;
    end 
    6'b010101: begin
    // BGE (Branch if Greater or Equal)
    if ($signed(rs1_data) >= $signed(rs2_data)) begin
        next_pc = pc + imm;  // 跳转地址
    end else begin
        next_pc = pc + 4;    // 不跳转，继续执行下一指令
    end
    end
    6'b010110: begin
    // SRLI (Shift Right Logical Immediate)
    result = rs1_data >> imm[4:0];  // 右移逻辑，移位位数由 imm 的低 5 位决定
    end
    6'b010111: begin
    // XOR (R-type)
    result = rs1_data ^ rs2_data;  // 计算两个寄存器的按位异或
    end
    6'b011000: begin
    // LBU (Load Byte Unsigned)
   // $display("Executing LBU operation in EXU.");
    result = {24'b0, pmem_read(rs1_data + imm)[7:0]};  // 提取最低字节并零扩展

   // $display("1111111 rsdata = %h",pmem_read(rs1_data + imm));
    //$display("2222222 result = %h",result);
    
    end
    6'b011001: begin
    // SLLI (Shift Left Logical Immediate)
   // $display("Executing SLLI operation in EXU.");
    result = rs1_data << imm[4:0];  // SLLI 使用 imm 的低 5 位进行移位操作
    end
    6'b011010: begin
    // BGEU (Branch if Greater Than or Equal, Unsigned)
   // $display("Executing BGEU operation in EXU.");
    if (rs1_data >= rs2_data) begin
        next_pc = pc + imm;  // 跳转到目标地址
    end else begin
        next_pc = pc + 4;  // 不满足条件，跳转到下一条指令
    end
    end
    6'b011011: begin
    // BLTU (Branch if Less Than, Unsigned)
   // $display("Executing BLTU operation in EXU.");
    if (rs1_data < rs2_data) begin
        next_pc = pc + imm;  // 跳转到目标地址
    end else begin
        next_pc = pc + 4;  // 不满足条件，跳转到下一条指令
    end
    end
    6'b011100: begin
    // SLTU (Set Less Than Unsigned)
    result = (rs1_data < rs2_data) ? 32'b1 : 32'b0;
    end
    6'b011101: begin
    // SLT (Set Less Than)
    result = ($signed(rs1_data) < $signed(rs2_data)) ? 32'b1 : 32'b0;
    end
    6'b011110: begin
    // BLT (Branch if Less Than)
    if ($signed(rs1_data) < $signed(rs2_data)) begin
        next_pc = pc + imm;  // 跳转到目标地址
    end else begin
        next_pc = pc + 4;  // 否则跳转到下一条指令
    end
    end
    6'b011111: begin
    // LH (Load Halfword)
   // $display("Executing LH operation in EXU.");
    result = {{16{pmem_read(rs1_data + imm)[15]}}, pmem_read(rs1_data + imm)[15:0]};  // 读取半字并符号扩展为32位
    end
    6'b100000: begin
    // LHU (Load Halfword Unsigned)
   // $display("Executing LHU operation in EXU.");
    result = {16'b0, pmem_read(rs1_data + imm)[15:0]};  // 读取半字并零扩展为32位
    end
    6'b100001: begin
    // SRA (算术右移，带符号扩展)
    result = $signed(rs1_data) >>> rs2_data[4:0];  // 使用 rs2_data 的低 5 位作为移位位数
    end 
    6'b100010: begin
    // SRL (逻辑右移)
    result = rs1_data >> rs2_data[4:0];  // 使用 rs2_data 的低 5 位作为移位位数
    end
    6'b100011: begin
    // SB (Store Byte)
    result = rs1_data + imm;  // 计算存储地址
    pmem_write(result, rs2_data, 1);  // 将 rs2_data 的低8位写入 result 指定的地址，mask为1表示写入1个字节
   // $display("Executing SB operation in EXU. Writing %h to address %h", rs2_data[7:0], result);
    end
    6'b100100: begin
  // LB (Load Byte)
  result = {{24{pmem_read(rs1_data + imm)[7]}}, pmem_read(rs1_data + imm)[7:0]};  // 从内存读取字节并符号扩展到32位
    end
    6'b100101: begin
  // ORI (按位或立即数)
  result = rs1_data | imm;
   end
   6'b100110: begin
  // SLTI (Set Less Than Immediate)
  result = ($signed(rs1_data) < $signed(imm)) ? 32'b1 : 32'b0;
   end

   6'b110000: begin  // CSRRW
  result = csr_rdata;
  //$display("csr_rdata1 = %08x from (exu.v)",csr_rdata);
  csr_wdata = rs1_data;
  csr_wen = 1;
end
6'b110001: begin  // CSRRS
  result = csr_rdata;
  csr_wdata = csr_rdata | rs1_data;
  csr_wen = 1;
 // $display("csr_rdata2 = %08x from (exu.v)",csr_rdata);
end
6'b110010: begin  // ECALL
  next_pc = mtvec;
  // 在CSR模块中设置mcause和mepc
end
6'b110011: begin  // MRET
  next_pc = mepc;
end
6'b110100: begin
    // SH (Store Halfword)
   
  result = rs1_data + imm;  // 先计算存储地址
    pmem_write(result, rs2_data, 2);  // 将rs2_data的低16位写入计算出的地址
end





















      default: begin
        $display("default:didnt match any inst from (exu.v)");
        // NOP 或未实现的操作
        // 已经在开始时赋值了 result 和 next_pc 的默认值
      end
    endcase
  end
endmodule
