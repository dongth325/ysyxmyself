module ysyx_24090012_IDU(
  input [31:0] inst,
  input [31:0] pc,
  
  output reg [6:0] opcode,
  output reg [2:0] func3,
  output reg [6:0] func7,
  output reg [4:0] rs1,
  output reg [4:0] rs2,
  output reg [4:0] rd,
  
  output reg [5:0] alu_op,
  output reg [31:0] imm,

output reg [11:0] csr_addr,//csr csr csr
output reg csr_wen,//csr csr csr
output reg is_ecall,//csr csr csr
output reg is_mret//csr csr csr

);

    always @(*) begin
    opcode = inst[6:0];
    func3  = inst[14:12];
    
    func7  = inst[31:25];
    rs1    = inst[19:15];
    rs2    = inst[24:20];
    rd     = inst[11:7];
      is_ecall = 0;
      is_mret = 0;
      csr_wen = 0;
    //$display("rs1 = %d from (idu.v)",rs1);
    //$display("rs2 = %d from (idu.v)",rs2);
    //$display("pc = %h from (idu.v)",pc);
    //$display("inst = %h from (idu.v)",inst);
    //$display("func3 = %b from (idu.v)",func3);
   // $display("func7 = %b from (idu.v)",func7);
    //$display("opcode = %b from (idu.v)",opcode);
   // $display("At time %t: idu touch PC = 0x%08x", $time, pc);

    // 根据指令类型，提取立即数和 ALU 操作码
    case (opcode)

  7'b1110011: begin  // 系统指令
  // 默认值设置
  imm = 32'b0;
  csr_wen = 0;
  is_ecall = 0;
  is_mret = 0;
  
  if (func3 == 3'b000) begin  // ECALL/MRET/EBREAK
    if (inst[31:20] == 12'b000000000001) begin
      alu_op = 6'b001011;  // EBREAK
    end
    else if (inst[31:20] == 12'b0) begin
      alu_op = 6'b110010;  // ECALL
      is_ecall = 1;
        rs1 = 5'd17;  // a7寄存器的地址
    end
    else if (inst[31:20] == 12'b001100000010) begin
      alu_op = 6'b110011;  // MRET
      is_mret = 1;
    end
  end
  else begin  // CSR instructions
    case (func3)
      3'b001: begin  // CSRRW
        alu_op = 6'b110000;
        csr_addr = inst[31:20];
        csr_wen = 1;
       // $display("csr_addr1 = %08x from (idu.v)",csr_addr);
      end
      3'b010: begin  // CSRRS
        alu_op = 6'b110001;
        csr_addr = inst[31:20];
        csr_wen = 1;
       // $display("csr_addr2 = %08x from (idu.v)",csr_addr);
       // $display("rd = %d from (idu.v) from (idu.v)",rd);
      end
      default: alu_op = 6'b001111;  // 未实现的操作
    endcase
  end
end












         7'b0010011: begin  // I-type (ADDI, SEQZ)
        imm = {{20{inst[31]}}, inst[31:20]};
        if (func3 == 3'b000) begin
        
          alu_op = 6'b000000;  // ADDI
         // $display("addi alu_op = 0x%08x from (idu.v)\n",alu_op);
        end  else if (func3 == 3'b110) begin
        alu_op = 6'b100101;  // ORI//ddddddddddddddddddddddddddddddddddddddddd
        end else if (func3 == 3'b010) begin
         alu_op = 6'b100110;  // SLTI
       end
      
        else if (func3 == 3'b011) begin
          alu_op = 6'b001010;  // SEQZ
        
        end else if (func3 == 3'b100) begin
      alu_op = 6'b001110;  // XORI
    end else if (func3 == 3'b111 && inst[31:25] == 7'b0100000) begin
        alu_op = 6'b001111;  // ZEXT.B  注意  若都不匹配的情况alu_op也是001111 注意不要弄混
    end else if (func3 == 3'b101 && func7 == 7'b0100000) begin
  alu_op = 6'b010001;  // SRAI
     end
     else if (func3 == 3'b111) begin
    alu_op = 6'b010011;  // ANDI
     end
     else if (func3 == 3'b101 && func7 == 7'b0000000) begin
        alu_op = 6'b010110;  // SRLI
    end
    else if (func3 == 3'b001 && func7 == 7'b0000000) begin
        alu_op = 6'b011001;  // SLLI
    end
        else begin
          alu_op = 6'b001111;  // 未实现的操作
         // $display("got this place....... from (idu.v)");//ddddddddddd
          
        end
      end
      7'b0110111: begin  // LUI
        imm = {inst[31:12], 12'b0};
        alu_op = 6'b000001;  // LUI
      end
      7'b0110011: begin  // R-type (ADD, SUB)
        imm = 32'b0;  // R-type 没有立即数
        if (func3 == 3'b000 && func7 == 7'b0000000) begin
          alu_op = 6'b000101;  // ADD
        end else if (func3 == 3'b000 && func7 == 7'b0100000) begin
          alu_op = 6'b001100;  // SUB
        end 
        else if (func3 == 3'b001 && func7 == 7'b0000000) begin
      alu_op = 6'b001101;  // SLL
    end else if (func3 == 3'b111 && func7 == 7'b0000000) begin
        alu_op = 6'b010000;  // AND
    end
   else if (func3 == 3'b011 && func7 == 7'b0000000) begin
        if (rs2 == 5'b00000) begin
            alu_op = 6'b010010;  // SNEZ (Set Not Equal to Zero)
        end else begin
            alu_op = 6'b011100;  // SLTU (Set Less Than Unsigned)
        end
    end   else if (func3 == 3'b110 && func7 == 7'b0000000) begin
        alu_op = 6'b010100;  // OR
    end
     else if (func3 == 3'b100 && func7 == 7'b0000000) begin
        alu_op = 6'b010111;  // XOR
    end
    else if (func3 == 3'b010 && func7 == 7'b0000000) begin
        alu_op = 6'b011101;  // SLT
    end else if (func3 == 3'b101 && func7 == 7'b0100000) begin
        alu_op = 6'b100001;  // SRA
    end else if (func3 == 3'b101 && func7 == 7'b0000000) begin
    alu_op = 6'b100010;  // SRL
    end

    else begin
          alu_op = 6'b001111;  // 未实现的操作
          
        end
      end
      7'b0010111: begin  // AUIPC
        imm = {inst[31:12], 12'b0};
        alu_op = 6'b000010;  // AUIPC
      end
      7'b1101111: begin  // JAL
        imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
        //$display("At time %t: idu   jal  imm= 0x%08x", $time, imm);
        alu_op = 6'b000011;  // JAL
      end
      7'b1100111: begin  // JALR
        imm = {{20{inst[31]}}, inst[31:20]};
        alu_op = 6'b000100;  // JALR
      end
      7'b1100011: begin  // B-type (BEQ, BNE)
        imm = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
        if (func3 == 3'b000) begin
          alu_op = 6'b000110;  // BEQ
         // $display("BEQ imm = %h",imm);
        end else if (func3 == 3'b001) begin
          alu_op = 6'b000111;  // BNE
        end  else if (func3 == 3'b101) begin
        alu_op = 6'b010101;  // BGE
       end else if (func3 == 3'b111) begin
        alu_op = 6'b011010;  // BGEU (无符号大于等于)
       end
       else if (func3 == 3'b110) begin
        alu_op = 6'b011011;  // BLTU (无符号小于)
      end
      else if (func3 == 3'b100) begin
        alu_op = 6'b011110;  // BLT
      end
        else begin
          alu_op = 6'b001111;  // 未实现的操作
          
        end
      end
      7'b0000011: begin  // I-type (LW)
        imm = {{20{inst[31]}}, inst[31:20]};
       // $display("imm of L = %d",imm);//ddddddddddd
         case (func3)
           3'b000: alu_op = 6'b100100;  // LB (Load Byte)
        3'b010: alu_op = 6'b001000;  // LW (Load Word)
        3'b100: alu_op = 6'b011000;  // LBU (Load Byte Unsigned)
          3'b001: alu_op = 6'b011111;  // LH (Load Halfword)
            3'b101: alu_op = 6'b100000;  // LHU (Load Halfword Unsigned)
        default: begin
            alu_op = 6'b001111; // 未实现的操作
           // $display("Unimplemented LOAD operation in IDU.");
            
        end
    endcase
      end
      7'b0100011: begin  // S-type (SW)
        imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
        case (func3)
        3'b000: alu_op = 6'b100011;  // SB (Store Byte)
          3'b001: alu_op = 6'b110100;  // SH (Store Halfword)
        3'b010: alu_op = 6'b001001;  // SW (Store Word)
        // 添加其他S-type指令处理...
        default: begin
            alu_op = 6'b001111;  // 未实现的操作
           // $display("Unimplemented STORE operation in IDU.");
            
        end
    endcase
      end
     /* 7'b1110011: begin  // SYSTEM (EBREAK)
        imm = 32'b0;
        alu_op = 6'b001011;  // EBREAK
      end*/

      // 其他指令类型
      default: begin
        imm = 32'b0;
        alu_op = 6'b001111;  // NOP 或未实现
       // $display("default default from (idu.v)");
        
      end
    endcase
    
    //$display("alu_op = %b from (idu.v)",alu_op);
  end
    
endmodule
