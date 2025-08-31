module ysyx_24090012_IDU(
  input [31:0] inst,
  input [31:0] ifu_to_idu_pc,
  
    input wire clock,        // 改用clock
    input wire reset,        // 改用reset
  //ifu interface
  output reg ifu_ready,
  input  ifu_valid,


  //exu interface
  output reg exu_valid,
  input  exu_ready,
  output reg  [31:0] idu_to_exu_pc, 

   output  state_out,  // 添加state输出端口

  

  output reg [6:0] opcode,
  output reg [2:0] func3,
  output reg [6:0] func7,
  output reg [4:0] rs1,
  output reg [4:0] rs2,
  output reg [4:0] rd,

  output reg rd_wen,//流水线流水线流水线
  
  output reg [5:0] alu_op,
  output reg [31:0] imm,

  output reg [11:0] csr_addr,
  output reg  csr_wen


);
 

   // 状态定义
    localparam IDLE = 1'b0;
    localparam BUSY = 1'b1;

    reg state, next_state;
        // IDU流水线寄存器
    reg [31:0] inst_r;        // 指令寄存器
   
    reg [31:0] pc_r;         // PC寄存器



    // 性能计数器
    reg [31:0] idu_count;           // IDU处理指令总计数器
    reg [31:0] compute_inst_count;  // 计算类指令计数器
    reg [31:0] load_inst_count;     // 加载指令计数器
    reg [31:0] store_inst_count;    // 存储指令计数器
    reg [31:0] branch_inst_count;   // 分支指令计数器
    reg [31:0] jump_inst_count;     // 跳转指令计数器
    reg [31:0] csr_inst_count;      // CSR指令计数器
    reg [31:0] other_inst_count;    // 其他指令计数器



  
    assign idu_to_exu_pc = ifu_to_idu_pc;
    assign state_out = state;//向top模块输出当前state

   


always @(posedge clock) begin
   // 当指令被EXU接收执行时，根据opcode更新指令类型计数器
    if (state == BUSY && next_state == IDLE) begin

    case (opcode)
        7'b0010011, 7'b0110111, 7'b0110011, 7'b0010111: begin
            // 计算类指令: I-type, LUI, R-type, AUIPC
            compute_inst_count <= compute_inst_count + 1;
        end
        
        7'b0000011: begin
            // 加载指令: LW, LB, LH, LBU, LHU
            load_inst_count <= load_inst_count + 1;
        end
        
        7'b0100011: begin
            // 存储指令: SW, SB, SH
            store_inst_count <= store_inst_count + 1;
        end
        
        7'b1100011: begin
            // 分支指令: BEQ, BNE, BLT, BGE, BLTU, BGEU
            branch_inst_count <= branch_inst_count + 1;
        end
        
        7'b1101111, 7'b1100111: begin
            // 跳转指令: JAL, JALR
            jump_inst_count <= jump_inst_count + 1;
        end
        
        7'b1110011: begin
            // CSR指令: CSRRW, CSRRS, ECALL, MRET
            csr_inst_count <= csr_inst_count + 1;
        end
        
        default: begin
            // 其他指令
            other_inst_count <= other_inst_count + 1;
        end
    endcase
end
end







    always @(posedge clock) begin
        if (reset) begin
            inst_r <= 32'b0;
            pc_r <= 32'b0;
           
            idu_count <= 32'h0;
            compute_inst_count <= 32'h0;
            load_inst_count <= 32'h0;
            store_inst_count <= 32'h0;
            branch_inst_count <= 32'h0;
            jump_inst_count <= 32'h0;
            csr_inst_count <= 32'h0;
            other_inst_count <= 32'h0;

        end 

        else if (ifu_valid && ifu_ready) begin
          inst_r <= inst;
          pc_r <= ifu_to_idu_pc;
          idu_count <= idu_count + 1;  // idu count计数器
          end
    end







   // 状态转换
    always @(posedge clock) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end




    always @(*) begin

       next_state = state;
        ifu_ready = 1'b0;
        exu_valid = 1'b0;

        alu_op = 6'b111111;  //默认为没有实现的操作
        imm = 32'b0;         //默认0     综合需要去除检测出来的锁存器 yosys

       csr_addr = inst_r[31:20];
       csr_wen = 0;

    opcode = inst_r[6:0];
    func3  = inst_r[14:12];
    func7  = inst_r[31:25];
    rs1    = inst_r[19:15];
    rs2    = inst_r[24:20];
    rd     = inst_r[11:7];
    
    
      rd_wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1110011||
      opcode == 7'b1101111 || opcode == 7'b1100111 || opcode == 7'b0110011 || 
       opcode == 7'b0000011);//流水线流水线流水线
     
     case (state)


            IDLE: begin
                ifu_ready = 1'b1;
                if (ifu_valid) begin
                    next_state = BUSY;
                end
            end
 
            BUSY: begin
             
    // 根据指令类型，提取立即数和 ALU 操作码
    case (opcode)

  7'b1110011: begin  // 系统指令
  // 默认值设置
  imm = 32'b0;
 
  
  if (func3 == 3'b000) begin  // ECALL/MRET/EBREAK
    if (inst_r[31:20] == 12'b000000000001) begin
      alu_op = 6'b001011;  // EBREAK
    end
    else if (inst_r[31:20] == 12'b0) begin
      alu_op = 6'b110010;  // ECALL
      csr_wen = 1;
        rs1 = 5'd17;  // a7寄存器的地址
    end
    else if (inst_r[31:20] == 12'b001100000010) begin
      alu_op = 6'b110011;  // MRET
     
    end
  end
  else begin  // CSR instructions
    case (func3)
      3'b001: begin  // CSRRW
        alu_op = 6'b110000;
        csr_addr = inst_r[31:20];
        csr_wen = 1;
       
      end
      3'b010: begin  // CSRRS
        alu_op = 6'b110001;
        csr_addr = inst_r[31:20];
        csr_wen = 1;
     
      end
      default: alu_op = 6'b001111;  // 未实现的操作
    endcase
  end
    

end












         7'b0010011: begin  // I-type (ADDI, SEQZ)
    
        imm = {{20{inst_r[31]}}, inst_r[31:20]};
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
    //end else if (func3 == 3'b111 && inst[31:25] == 7'b0100000) begin
   end else if (func3 == 3'b111 && inst_r[31:20] == 12'b000011111111) begin
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
  
        imm = {inst_r[31:12], 12'b0};
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
        imm = {inst_r[31:12], 12'b0};
     
        alu_op = 6'b000010;  // AUIPC
      end
      7'b1101111: begin  // JAL
        imm = {{12{inst_r[31]}}, inst_r[19:12], inst_r[20], inst_r[30:21], 1'b0};
        //$display("At time %t: idu   jal  imm= 0x%08x", $time, imm);
        alu_op = 6'b000011;  // JAL
      end
      7'b1100111: begin  // JALR
        imm = {{20{inst_r[31]}}, inst_r[31:20]};
        alu_op = 6'b000100;  // JALR
      end
      7'b1100011: begin  // B-type (BEQ, BNE)
        imm = {{19{inst_r[31]}}, inst_r[31], inst_r[7], inst_r[30:25], inst_r[11:8], 1'b0};
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
        imm = {{20{inst_r[31]}}, inst_r[31:20]};
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
        imm = {{20{inst_r[31]}}, inst_r[31:25], inst_r[11:7]};
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
    

      // 其他指令类型
      default: begin
        imm = 32'b0;
        alu_op = 6'b001111;  // NOP 或未实现
       // $display("default default from (idu.v)");
        
      end

      
    endcase


     exu_valid = 1'b1;
                if (exu_ready) begin
                    next_state = IDLE;
                end

      end
            
            default: begin
                next_state = IDLE;
            end


        endcase
   
  end
    
export "DPI-C"  function get_inst_r;  //获取当前指令
function int get_inst_r();
  get_inst_r = inst_r; // 假设idu是IDU模块的实例名
endfunction




    
// 导出DPI-C函数，供C++仿真环境访问
export "DPI-C" function get_idu_count;
export "DPI-C" function get_compute_inst_count;
export "DPI-C" function get_load_inst_count;
export "DPI-C" function get_store_inst_count;
export "DPI-C" function get_branch_inst_count;
export "DPI-C" function get_jump_inst_count;
export "DPI-C" function get_csr_inst_count;
export "DPI-C" function get_other_inst_count;

// DPI-C函数实现
function int get_idu_count();
    return idu_count;
endfunction

function int get_compute_inst_count();
    return compute_inst_count;
endfunction

function int get_load_inst_count();
    return load_inst_count;
endfunction

function int get_store_inst_count();
    return store_inst_count;
endfunction

function int get_branch_inst_count();
    return branch_inst_count;
endfunction

function int get_jump_inst_count();
    return jump_inst_count;
endfunction

function int get_csr_inst_count();
    return csr_inst_count;
endfunction

function int get_other_inst_count();
    return other_inst_count;
endfunction





endmodule