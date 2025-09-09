
//删除了latch 和 wait ready状态   只保留idle 和 exec状态  但是没有处理 csr部分



module ysyx_24090012_EXU(
  input rst,
  input clk,  // 添加时钟输入
  input        idu_valid,      // 新增：IDU数据有效信号
  output reg   idu_ready,      // 新增：EXU就绪信号
  input [31:0] pc,
  output [1:0] state_out,
  output reg        mem_unsigned,  // 新增：无符号加载指令标志
// LSU接口 (master)
    
    output reg [31:0] mem_addr,
    output reg        mem_valid,
    output reg [31:0] mem_wdata,
    output reg [3:0]  mem_wmask,
    output reg        mem_wen,
    input   wire         mem_ready,
  
    output reg [2:0] mem_arsize,//新增axi对size判断
    output reg [2:0] mem_awsize,//新增axi对size判断  exu顶层信号

    output reg is_use_lsu,//流水线流水线流水线
    
    
    input  [4:0]  rd_addr,//流水线流水线流水线
    output  [4:0]  rd_addr_out,
    output reg [31:0] rd_data,
    output reg [31:0] result,//流水线流水线流水线，貌似重复了 rd data和result，可以删去一个
    output reg [31:0] next_pc,


    input        rd_wen,    //流水线流水线流水线
    output       rd_wen_out,//流水线流水线流水线

    // PC更新接口 (master)
   
    output [31:0] out_pc,
    


    input [31:0] mtvec,
    input [31:0] mepc,


  input [31:0] rs1_data,
  input [31:0] rs2_data,
  input [31:0] imm,
  input [5:0] alu_op,
  
  output reg  is_ecall,
  output reg is_mret,
 
    input [11:0] csr_addr,
    input  csr_wen,


    input [31:0] csr_rdata,//csr csr csr csr

    output  [11:0] out_csr_addr,

    output  reg [31:0] csr_wdata,//csr csr csr csr

    output  out_csr_wen//csr csr csr csr
   

 
);
 //import "DPI-C" function void pmem_write(input int addr, input int data, input int mask);
 //import "DPI-C" function int pmem_read(input int addr);


    // 状态定义
    localparam IDLE = 2'b00;

    localparam EXEC = 2'b11;


    reg [1:0] state, next_state;
       // 输入数据寄存器
    reg [31:0] pc_r;
    reg [31:0] rs1_data_r;
    reg [31:0] rs2_data_r;
    reg [4:0] rd_addr_r;
    reg [31:0] imm_r;
    reg [5:0]  alu_op_r;
    reg rd_wen_r;//流水线流水线流水线
    
    // CSR输入数据寄存器
    reg [31:0] mtvec_r;
    reg [31:0] mepc_r;

    reg [31:0] csr_rdata_r;
    reg [11:0] csr_addr_r;
    reg csr_wen_r;
    
    reg [31:0] exu_count;    // EXU执行指令计数器


  


 assign state_out = state; 


always @(posedge clk) begin
   // 当指令执行完成时，增加计数器
  if (state == EXEC && next_state == IDLE) begin
    exu_count <= exu_count + 1;
end
end

    // 状态转换
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            exu_count <= 0;
        end else begin
          
            state <= next_state;
        end
    end
    
        // 流水线寄存器更新
    always @(posedge clk) begin
        if (rst) begin
            // 基本输入寄存器复位
            pc_r <= 32'b0;
            rs1_data_r <= 32'b0;
            rs2_data_r <= 32'b0;
            imm_r <= 32'b0;
            alu_op_r <= 6'b0;
            rd_wen_r <= 1'b0;//流水线流水线流水线
            rd_addr_r <= 5'b0;//流水线流水线流水线
            // CSR输入数据寄存器复位
            mtvec_r <= 32'b0;
            mepc_r <= 32'b0;
            csr_addr_r <= 12'b0;
            csr_wen_r <= 1'b0;
            csr_rdata_r <= 32'b0;
            
        end else if (state == IDLE && idu_valid) begin
            // 基本输入寄存器更新
            pc_r <= pc;
            rs1_data_r <= rs1_data;
            rs2_data_r <= rs2_data;
            imm_r <= imm;
            alu_op_r <= alu_op;
            rd_wen_r <= rd_wen; //流水线流水线流水线
            rd_addr_r <= rd_addr;
            // CSR输入数据寄存器更新
            mtvec_r <= mtvec;
            mepc_r <= mepc;
            csr_addr_r <= csr_addr;
            csr_wen_r <= csr_wen;
      
            csr_rdata_r <= csr_rdata;
        end
    end




    always @(*) begin
      case (alu_op_r)
        6'b001000,  // LW
        6'b001001,  // SW
        6'b011000,  // LBU
        6'b011111,  // LH
        6'b100000,  // LHU
        6'b100011,  // SB
        6'b100100,  // LB
        6'b110100:  // SH
          is_use_lsu = 1'b1;
        default:
          is_use_lsu = 1'b0;
      endcase
    end














 
always @(*) begin

  csr_wdata = 32'b0;
    // 初始化默认值，防止锁存器推断
  next_state = state;

  idu_ready = (state == IDLE);

  mem_unsigned = 1'b0;

  out_pc = pc_r;

  rd_addr_out = rd_addr_r;//流水线流水线流水线
  rd_wen_out = rd_wen_r;//流水线流水线流水线
       // LSU接口默认值
        mem_valid = 0;
        mem_addr = 0;
        mem_wdata = 0;
        mem_wmask = 0;
        mem_wen = 0;
        mem_awsize = 0;
        mem_arsize = 0;
        
      // RegFile写回接口默认值
      
        rd_data = 0;
       
        
       
        csr_wdata = 32'h0;
       
        out_csr_addr = csr_addr_r;
        out_csr_wen = csr_wen_r;
   


       is_ecall = 1'b0;
       is_mret = 1'b0;

      
    result = 32'b0;
    next_pc = pc;  // 默认是顺序执行的下一条指令

  
  case (state)
    IDLE: begin
      if (idu_valid && idu_ready) begin   //idu_ready在idle时一直为1
              next_state = EXEC;
                end
            end
  
 EXEC: begin

    case (alu_op_r)
      6'b000000: begin
        // ADDI
        result = rs1_data_r + imm_r;
        next_pc = pc_r + 4;

        rd_data = result;
   

         
         mem_valid = 1'b1;
         if(mem_ready) begin
           next_state = IDLE;
         end//流水线流水线流水线

      end
      6'b000001: begin
        // LUI
        result = imm_r;
        next_pc = pc_r + 4;
        rd_data = result;
     
         
         mem_valid = 1'b1;
         if(mem_ready) begin
           next_state = IDLE;
         end//流水线流水线流水线

      end
      6'b000010: begin
        // AUIPC
        result = pc_r + imm_r;
       
        next_pc = pc_r + 4;
        rd_data = result;
   


        mem_valid = 1'b1;
        if(mem_ready) begin
          next_state = IDLE;
        end//流水线流水线流水线

      end
      6'b000011: begin
        // JAL
        result = pc_r + 4;          // 保存返回地址
        next_pc = pc_r + imm_r;       // 跳转到目标地址
        rd_data = result;
    


         mem_valid = 1'b1;
         if(mem_ready) begin
           next_state = IDLE;
         end//流水线流水线流水线

      end
      6'b000100: begin
        // JALR
        result = pc_r + 4;                                 // 保存返回地址
        next_pc = (rs1_data_r + imm_r) & ~1;                // 计算跳转地址（必须是偶数地址）
        rd_data = result;
   


         mem_valid = 1'b1;
         if(mem_ready) begin
           next_state = IDLE;
         end//流水线流水线流水线

      end
      6'b000101: begin
        // ADD (R-type)
        result = rs1_data_r + rs2_data_r;
        next_pc = pc_r + 4;
        rd_data = result;
     

         mem_valid = 1'b1;
         if(mem_ready) begin
           next_state = IDLE;
         end//流水线流水线流水线

      end
      6'b000110: begin
        // BEQ
     

            result = 0;
            next_pc = (rs1_data_r == rs2_data_r) ? pc_r + imm_r : pc_r + 4;
          


       mem_valid = 1'b1;
       if(mem_ready) begin
         next_state = IDLE;
       end//流水线流水线流水线



      end
      6'b000111: begin
        // BNE
     

            result = 0;
            next_pc = (rs1_data_r != rs2_data_r) ? pc_r + imm_r : pc_r + 4;
         
             mem_valid = 1'b1;
             if(mem_ready) begin
               next_state = IDLE;
             end//流水线流水线流水线



      end
      6'b001000: begin
        // LW
     

         mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b010;
                    next_pc = pc + 4;

                mem_valid = 1;
                if(mem_ready) begin
                  
                  next_state = IDLE;
                end



      end
      6'b001001: begin
        // SW
    
         mem_addr = rs1_data_r + imm_r;
                    mem_wdata = rs2_data_r;
                    mem_valid = 1;
                    mem_wen = 1;
                    mem_wmask = 4;
                    mem_awsize = 3'b010;
            


                    next_pc = pc + 4;
                    mem_valid = 1;
                if(mem_ready) begin
                 
                  next_state = IDLE;
                end
      end

      6'b001010: begin
        // SEQZ (Set Equal to Zero)
        
        result = (rs1_data_r == 0) ? 1 : 0;
       next_pc = pc_r + 4;
       rd_data = result;
       
      
     mem_valid = 1'b1;
     if(mem_ready) begin
       next_state = IDLE;
     end//流水线流水线流水线

      end
      6'b001011: begin
        // EBREAK
        // 不需要在 EXU 中进行操作，在 NPC 中处理
       next_pc = pc_r + 4;
      end
      6'b001100: begin
        // SUB (R-type)
        result = rs1_data_r - rs2_data_r;
        next_pc = pc_r + 4;
        rd_data = result;
     


         mem_valid = 1'b1;
         if(mem_ready) begin
           next_state = IDLE;
         end//流水线流水线流水线


      end
      6'b001101: begin
    result = rs1_data_r << rs2_data_r[4:0];  // SLL 使用 rs2_data 的低 5 位作为移位位数
    next_pc = pc_r + 4;
    rd_data = result;
  


     mem_valid = 1'b1;
     if(mem_ready) begin
       next_state = IDLE;
     end//流水线流水线流水线


      end
      6'b001110: begin
        // XORI
        result = rs1_data_r ^ imm_r;
        next_pc = pc_r + 4;
        rd_data = result;
       /* rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态*/


         mem_valid = 1'b1;
         if(mem_ready) begin
           next_state = IDLE;
         end//流水线流水线流水线




    end
    6'b001111: begin
    // ZEXT.B (Zero Extend Byte)
    result = {24'b0, rs1_data_r[7:0]};  // 提取 rs1_data 的最低 8 位，并将其扩展为 32 位
    next_pc = pc_r + 4;
    rd_data = result;
  

    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线

    end
    6'b010000: begin
    // AND (R-type)
    result = rs1_data_r & rs2_data_r;
    next_pc = pc_r + 4;
    rd_data = result;
  
     mem_valid = 1'b1;
     if(mem_ready) begin
       next_state = IDLE;
     end//流水线流水线流水线


    end 
    6'b010001: begin
  // SRAI (算术右移，带符号扩展)
  result = $signed(rs1_data_r) >>> imm_r[4:0];  // 使用立即数的低 5 位作为移位位数
  next_pc = pc_r + 4;
  rd_data = result;
 


   mem_valid = 1'b1;
   if(mem_ready) begin
     next_state = IDLE;
   end//流水线流水线流水线


    end
    6'b010010: begin
  // SNEZ (Set Not Equal to Zero)
  result = (rs2_data_r != 0) ? 32'b1 : 32'b0;
  next_pc = pc_r + 4;
  rd_data = result;
 


   mem_valid = 1'b1;
   if(mem_ready) begin
      next_state = IDLE;
   end//流水线流水线流水线

    end
    6'b010011: begin
  // ANDI (按位与立即数)
  result = rs1_data_r & imm_r;
  next_pc = pc_r + 4;
  rd_data = result;



   
   mem_valid = 1'b1;
   if(mem_ready) begin
     next_state = IDLE;
   end//流水线流水线流水线
        
    end
    
    6'b010100: begin
    // OR (R-type)
    result = rs1_data_r | rs2_data_r;
    next_pc = pc_r + 4;
    rd_data = result;
   


     mem_valid = 1'b1;
     if(mem_ready) begin
       next_state = IDLE;
     end//流水线流水线流水线



    end 
    6'b010101: begin
    // BGE (Branch if Greater or Equal)
    if ($signed(rs1_data_r) >= $signed(rs2_data_r)) begin
        next_pc = pc_r + imm_r;  // 跳转地址
    end else begin
        next_pc = pc_r + 4;    // 不跳转，继续执行下一指令
    end
   

    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线




    end
    6'b010110: begin
    // SRLI (Shift Right Logical Immediate)
    result = rs1_data_r >> imm_r[4:0];  // 右移逻辑，移位位数由 imm 的低 5 位决定
    next_pc = pc_r + 4;
    rd_data = result;
  


     mem_valid = 1'b1;
     if(mem_ready) begin
        next_state = IDLE;
     end//流水线流水线流水线


    end
    6'b010111: begin
    // XOR (R-type)
    result = rs1_data_r ^ rs2_data_r;  // 计算两个寄存器的按位异或
    next_pc = pc_r + 4;
    rd_data = result;


    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线


    end
    6'b011000: begin
    // LBU (Load Byte Unsigned)
 
    mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b000;
                    //next_state = WAIT_READY;
  mem_unsigned = 1'b1; 
  next_pc = pc + 4;
                    mem_valid = 1;
                if(mem_ready) begin
                  
                  next_state = IDLE;
                end

    
    end
    6'b011001: begin
    // SLLI (Shift Left Logical Immediate)

    result = rs1_data_r << imm_r[4:0];  // SLLI 使用 imm 的低 5 位进行移位操作
    next_pc = pc_r + 4;
    rd_data = result;


    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线



    end
    6'b011010: begin
    // BGEU (Branch if Greater Than or Equal, Unsigned)
 
    if (rs1_data_r >= rs2_data_r) begin
        next_pc = pc_r + imm_r;  // 跳转到目标地址
    end else begin
        next_pc = pc_r + 4;  // 不满足条件，跳转到下一条指令
    end
  
  

    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线



    end
    6'b011011: begin
    // BLTU (Branch if Less Than, Unsigned)
  
    if (rs1_data_r < rs2_data_r) begin
        next_pc = pc_r + imm_r;  // 跳转到目标地址
    end else begin
        next_pc = pc_r + 4;  // 不满足条件，跳转到下一条指令
    end
 

    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线



    end
    6'b011100: begin
    // SLTU (Set Less Than Unsigned)
    result = (rs1_data_r < rs2_data_r) ? 32'b1 : 32'b0;
    next_pc = pc_r + 4;
    rd_data = result;
  


     mem_valid = 1'b1;
     if(mem_ready) begin
       next_state = IDLE;
     end//流水线流水线流水线



    end
    6'b011101: begin
    // SLT (Set Less Than)
    result = ($signed(rs1_data_r) < $signed(rs2_data_r)) ? 32'b1 : 32'b0;
    next_pc = pc_r + 4;
    rd_data = result;
  


     mem_valid = 1'b1;
     if(mem_ready) begin
       next_state = IDLE;
     end//流水线流水线流水线


    end
    6'b011110: begin
    // BLT (Branch if Less Than)
    if ($signed(rs1_data_r) < $signed(rs2_data_r)) begin
        next_pc = pc_r + imm_r;  // 跳转到目标地址
    end else begin
        next_pc = pc_r + 4;  // 否则跳转到下一条指令
    end


    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线


    end
    6'b011111: begin
    // LH (Load Halfword)
 
         mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b001;
                

                    mem_valid = 1;
                    if(mem_ready) begin
                      next_pc = pc + 4;
                      next_state = IDLE;
                    end


    end
    6'b100000: begin
    // LHU (Load Halfword Unsigned)
  
     mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b001;
                   // next_state = WAIT_READY;
                    mem_unsigned = 1'b1; 
                    mem_valid = 1;
                    if(mem_ready) begin
                      next_pc = pc + 4;
                      next_state = IDLE;
                    end



    end
    6'b100001: begin
    // SRA (算术右移，带符号扩展)
    result = $signed(rs1_data_r) >>> rs2_data_r[4:0];  // 使用 rs2_data 的低 5 位作为移位位数
    next_pc = pc_r + 4;
    rd_data = result;
 
    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线

    end 
    6'b100010: begin
    // SRL (逻辑右移)
    result = rs1_data_r >> rs2_data_r[4:0];  // 使用 rs2_data 的低 5 位作为移位位数
    next_pc = pc_r + 4;
    rd_data = result;
  
   
    mem_valid = 1'b1;
    if(mem_ready) begin
      next_state = IDLE;
    end//流水线流水线流水线

    end
    6'b100011: begin
    // SB (Store Byte)
  
   mem_addr = rs1_data_r + imm_r;
                    mem_wdata = rs2_data_r;
                    mem_valid = 1;
                    mem_wen = 1;
                    mem_wmask = 1;
                    mem_awsize = 3'b000;
                 


                    mem_valid = 1;
                if(mem_ready) begin
                  next_pc = pc + 4;
                  next_state = IDLE;
                end

    end
    6'b100100: begin
  // LB (Load Byte)

   mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b000;
                  

                    mem_valid = 1;
                    if(mem_ready) begin
                      next_pc = pc + 4;
                      next_state = IDLE;
                    end



    end
    6'b100101: begin
  // ORI (按位或立即数)
  result = rs1_data_r | imm_r;
  next_pc = pc_r + 4;
  rd_data = result;
  


   mem_valid = 1'b1;
   if(mem_ready) begin
     next_state = IDLE;
   end//流水线流水线流水线



   end
   6'b100110: begin
  // SLTI (Set Less Than Immediate)
  result = ($signed(rs1_data_r) < $signed(imm_r)) ? 32'b1 : 32'b0;
  next_pc = pc_r + 4;
  rd_data = result;
  


   mem_valid = 1'b1;
   if(mem_ready) begin
     next_state = IDLE;
   end//流水线流水线流水线



   end

   6'b110000: begin  // CSRRW
  result = csr_rdata_r;
  rd_data = result;

  csr_wdata = rs1_data_r;
 
  next_pc = pc_r + 4;

  mem_valid = 1'b1;
  if(mem_ready) begin
    next_state = IDLE;
  end//流水线流水线流水线

 
end
6'b110001: begin  // CSRRS
  result = csr_rdata_r;
  rd_data = result;
  csr_wdata = csr_rdata_r | rs1_data_r;
  
 
  next_pc = pc_r + 4;
  mem_valid = 1'b1;
   if(mem_ready) begin
     next_state = IDLE;
   end//流水线流水线流水线

end
6'b110010: begin  // ECALL
                           

is_ecall = 1'b1;
  next_pc = mtvec_r;

  mem_valid = 1'b1;

  if(mem_ready) begin
    next_state = IDLE;
  end//流水线流水线流水线

 
end
6'b110011: begin  // MRET


  is_mret = 1'b1;

  next_pc = mepc_r;

  mem_valid = 1'b1;

  if(mem_ready) begin
    next_state = IDLE;
  end//流水线流水线流水线

  
end
6'b110100: begin
    // SH (Store Halfword)


         // SH
                    mem_addr = rs1_data_r + imm_r;
                    mem_wdata = rs2_data_r;
                    mem_valid = 1;
                    mem_wen = 1;
                    mem_wmask = 2;
                    mem_awsize = 3'b001;
                


                    mem_valid = 1;
                    if(mem_ready) begin
                      next_pc = pc + 4;
                      next_state = IDLE;
                    end

                

end

    default: begin
        $display("111default:didnt match any inst from (exu.v)");    //综合需要注释
        // NOP 或未实现的操作
        // 已经在开始时赋值了 result 和 next_pc 的默认值

      end

    endcase
    end
    //end


    default: begin
      
      $display("1114default:didnt match any inst from (exu.v)");    //综合需要注释
    end

































  endcase
end



    // 导出DPI-C函数，供C++仿真环境访问
export "DPI-C" function get_exu_count;
    
// DPI-C函数实现
function int get_exu_count();
    return exu_count;
endfunction






       
endmodule











