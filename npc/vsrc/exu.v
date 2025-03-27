module ysyx_24090012_EXU(
  input rst,
  input clk,  // 添加时钟输入
      input        idu_valid,      // 新增：IDU数据有效信号
    output reg   idu_ready,      // 新增：EXU就绪信号
  input [31:0] pc,
 output [1:0] state_out,

// LSU接口 (master)
    
    output reg [31:0] mem_addr,
    output reg        mem_valid,
    output reg [31:0] mem_wdata,
    output reg [3:0]  mem_wmask,
    output reg        mem_wen,
    input            mem_ready,
    input [31:0]     mem_rdata,
    output reg [2:0] mem_arsize,//新增axi对size判断
    output reg [2:0] mem_awsize,//新增axi对size判断  exu顶层信号
    
    // RegisterFile写回接口 (master)
    output reg [4:0]  rd_addr,
    output reg [31:0] rd_data,
    output reg        rd_valid,
    input            rd_ready,

    // PC更新接口 (master)
   
    output reg        pc_valid,
    input            pc_ready,
    
    output reg        csr_rd_valid,
    input            csr_rd_ready,


    input [31:0] mtvec,
    input [31:0] mepc,
    input [31:0] mstatus,
    input [31:0] mcause,

  input [31:0] rs1_data,
  input [31:0] rs2_data,
  input [31:0] imm,
  input [5:0] alu_op,
 
 
  output reg [31:0] result,

    input [31:0] csr_rdata,//csr csr csr csr

    output reg [11:0] csr_addr,
    output reg [31:0] csr_wdata,//csr csr csr csr
    output reg csr_wen,//csr csr csr csr
    output reg [11:0] csr_addr1,
    output reg [31:0] csr_wdata1,
    output reg csr_wen1,
    output reg [11:0] csr_addr2,
    output reg [31:0] csr_wdata2,
    output reg csr_wen2,
    output reg [11:0] csr_addr3,
    output reg [31:0] csr_wdata3,
    output reg csr_wen3,

  output reg [31:0] next_pc
);
 import "DPI-C" function void pmem_write(input int addr, input int data, input int mask);
 import "DPI-C" function int pmem_read(input int addr);


    // 状态定义
    localparam IDLE = 2'b00;
    localparam WAIT_READY = 2'b01;
    localparam LATCH = 2'b10;
    localparam EXEC = 2'b11;
     reg [31:0] mstatus_new;
    reg [1:0] state, next_state;
       // 输入数据寄存器
    reg [31:0] pc_r;
    reg [31:0] rs1_data_r;
    reg [31:0] rs2_data_r;
    reg [31:0] imm_r;
    reg [5:0]  alu_op_r;
    
    // CSR输入数据寄存器
    reg [31:0] mtvec_r;
    reg [31:0] mepc_r;
    reg [31:0] mstatus_r;
    reg [31:0] mcause_r;
    reg [31:0] csr_rdata_r;
    

 assign state_out = state; 

    // 状态转换
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
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
            
            // CSR输入数据寄存器复位
            mtvec_r <= 32'b0;
            mepc_r <= 32'b0;
            mstatus_r <= 32'b0;
            mcause_r <= 32'b0;
            csr_rdata_r <= 32'b0;
            
        end else if (state == IDLE && idu_valid) begin
            // 基本输入寄存器更新
            pc_r <= pc;
            rs1_data_r <= rs1_data;
            rs2_data_r <= rs2_data;
            imm_r <= imm;
            alu_op_r <= alu_op;
            
            // CSR输入数据寄存器更新
            mtvec_r <= mtvec;
            mepc_r <= mepc;
            mstatus_r <= mstatus;
            mcause_r <= mcause;
            csr_rdata_r <= csr_rdata;
        end
    end


   // always @(posedge clk) begin
        //always @(posedge exec_enable) begin//用来模拟时钟周期下降延
always @(*) begin

    // $display("\n[Time %t] EXU: entering clock edge", $time);
   // $display("Current PC = %h, alu_op = %b", pc, alu_op);
    // 初始化默认值，防止锁存器推断
     next_state = state;
  mstatus_new = mstatus_r;//可能会出错，比如因为更新再触发刷新一次always
  idu_ready = (state == IDLE);

       // LSU接口默认值
        mem_valid = 0;
        mem_addr = 0;
        mem_wdata = 0;
        mem_wmask = 0;
        mem_wen = 0;
        mem_awsize = 0;
        mem_arsize = 0;
        
      // RegFile写回接口默认值
        rd_addr = 0;
        rd_data = 0;
        rd_valid = 0;
        
              csr_addr = 12'h0;
        csr_wdata = 32'h0;
        csr_wen = 1'b0;
        
        csr_addr1 = 12'h0;
        csr_wdata1 = 32'h0;
        csr_wen1 = 1'b0;
        
        csr_addr2 = 12'h0;
        csr_wdata2 = 32'h0;
        csr_wen2 = 1'b0;
        
        csr_addr3 = 12'h0;
        csr_wdata3 = 32'h0;
        csr_wen3 = 1'b0;  
      csr_rd_valid = 0;//dddddddddddd


      //pc接口默认值
      pc_valid = 0;

    result = 32'b0;
    next_pc = pc;  // 默认是顺序执行的下一条指令
    csr_wdata = 32'b0;
    csr_wen = 1'b0;
  
  case (state)
    IDLE: begin
      if (idu_valid && idu_ready) begin   //idu_ready在idle时一直为1
              next_state = LATCH;
                end
            end
   LATCH: begin
                next_state = EXEC;
            end
 EXEC: begin

    case (alu_op_r)
      6'b000000: begin
        // ADDI
        result = rs1_data_r + imm_r;
        next_pc = pc_r + 4;

        rd_data = result;
        rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态

      end
      6'b000001: begin
        // LUI
        result = imm_r;
        next_pc = pc_r + 4;
        rd_data = result;
        rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态
      end
      6'b000010: begin
        // AUIPC
        result = pc_r + imm_r;
       
        next_pc = pc_r + 4;
        rd_data = result;
        rd_valid = 1;
        pc_valid = 1;
        next_state = WAIT_READY;  // 进入等待状态
      end
      6'b000011: begin
        // JAL
        result = pc_r + 4;          // 保存返回地址
        next_pc = pc_r + imm_r;       // 跳转到目标地址
        rd_data = result;
        rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态
      end
      6'b000100: begin
        // JALR
        result = pc_r + 4;                                 // 保存返回地址
        next_pc = (rs1_data_r + imm_r) & ~1;                // 计算跳转地址（必须是偶数地址）
        rd_data = result;
        rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态
      end
      6'b000101: begin
        // ADD (R-type)
        result = rs1_data_r + rs2_data_r;
        next_pc = pc_r + 4;
        rd_data = result;
        rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态
      end
      6'b000110: begin
        // BEQ
        /*if (rs1_data == rs2_data)
          next_pc = pc + imm;     // 跳转地址
        else
        next_pc = pc + 4;*/

            result = 0;
            next_pc = (rs1_data_r == rs2_data_r) ? pc_r + imm_r : pc_r + 4;
            pc_valid = 1;
         
       next_state = WAIT_READY;  // 进入等待状态

      end
      6'b000111: begin
        // BNE
        /*if (rs1_data != rs2_data)
          next_pc = pc + imm;     // 跳转地址
         else
        next_pc = pc + 4;  */

            result = 0;
            next_pc = (rs1_data_r != rs2_data_r) ? pc_r + imm_r : pc_r + 4;
            pc_valid = 1;
             next_state = WAIT_READY;  // 进入等待状态

      end
      6'b001000: begin
        // LW
       // $display("Memory at 0x80000220 = %h", pmem_read(32'h80000220));
        


       // $display( "rs1_data = %h from (exu.v)",  rs1_data);
        //$display( "rs2_data = %h from (exu.v)",  rs2_data);
        //$display( "imm = %h from (exu.v)",  imm);
         //result = pmem_read(rs1_data + imm);// 计算内存地址并从该地址读取数据
         //next_pc = pc + 4;
        // $display( "result = %h from (exu.v)",  result);

         mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b010;
                    next_state = WAIT_READY;



      end
      6'b001001: begin
        // SW
        //result = rs1_data + imm;  // 计算存储地址
        // pmem_write(result, rs2_data, 4);  // 将 rs2_data 写入 result 指定的地址，mask为4表示写入4个字节
        // next_pc = pc + 4;
         mem_addr = rs1_data_r + imm_r;
                    mem_wdata = rs2_data_r;
                    mem_valid = 1;
                    mem_wen = 1;
                    mem_wmask = 4;
                    mem_awsize = 3'b010;
                    next_state = WAIT_READY;
      end

      6'b001010: begin
        // SEQZ (Set Equal to Zero)
        
        result = (rs1_data_r == 0) ? 1 : 0;
       next_pc = pc_r + 4;
       rd_data = result;
       rd_valid = 1;
       pc_valid = 1;
        next_state = WAIT_READY;  // 进入等待状态
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
        rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态
      end
      6'b001101: begin
    result = rs1_data_r << rs2_data_r[4:0];  // SLL 使用 rs2_data 的低 5 位作为移位位数
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
      end
      6'b001110: begin
        // XORI
        result = rs1_data_r ^ imm_r;
        next_pc = pc_r + 4;
        rd_data = result;
        rd_valid = 1;
        pc_valid = 1;
         next_state = WAIT_READY;  // 进入等待状态
    end
    6'b001111: begin
    // ZEXT.B (Zero Extend Byte)
    result = {24'b0, rs1_data_r[7:0]};  // 提取 rs1_data 的最低 8 位，并将其扩展为 32 位
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
     
        //    $display("rs1_data = %h", rs1_data);
         //   $display("imm = %h", imm);
         //   $display("result = %h", result);
    end
    6'b010000: begin
    // AND (R-type)
    result = rs1_data_r & rs2_data_r;
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end 
    6'b010001: begin
  // SRAI (算术右移，带符号扩展)
  result = $signed(rs1_data_r) >>> imm_r[4:0];  // 使用立即数的低 5 位作为移位位数
  next_pc = pc_r + 4;
  rd_data = result;
  rd_valid = 1;
  pc_valid = 1;
   next_state = WAIT_READY;  // 进入等待状态
    end
    6'b010010: begin
  // SNEZ (Set Not Equal to Zero)
  result = (rs2_data_r != 0) ? 32'b1 : 32'b0;
  next_pc = pc_r + 4;
  rd_data = result;
  rd_valid = 1;
  pc_valid = 1;
   next_state = WAIT_READY;  // 进入等待状态
    end
    6'b010011: begin
  // ANDI (按位与立即数)
  result = rs1_data_r & imm_r;
  next_pc = pc_r + 4;
  rd_data = result;
  rd_valid = 1;
  pc_valid = 1;
   next_state = WAIT_READY;  // 进入等待状态
         //$display("ANDI operation:");
        //    $display("rs1_data = %h", rs1_data);    // 应该是 0x43
         //   $display("imm = %h", imm);              // 应该是 0x400
          //  $display("result = %h", rs1_data & imm);// 应该是 0x0
    end 6'b010100: begin
    // OR (R-type)
    result = rs1_data_r | rs2_data_r;
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end 
    6'b010101: begin
    // BGE (Branch if Greater or Equal)
    if ($signed(rs1_data_r) >= $signed(rs2_data_r)) begin
        next_pc = pc_r + imm_r;  // 跳转地址
    end else begin
        next_pc = pc_r + 4;    // 不跳转，继续执行下一指令
    end
   
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b010110: begin
    // SRLI (Shift Right Logical Immediate)
    result = rs1_data_r >> imm_r[4:0];  // 右移逻辑，移位位数由 imm 的低 5 位决定
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b010111: begin
    // XOR (R-type)
    result = rs1_data_r ^ rs2_data_r;  // 计算两个寄存器的按位异或
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b011000: begin
    // LBU (Load Byte Unsigned)
   // $display("Executing LBU operation in EXU.");
    //result = {24'b0, pmem_read(rs1_data + imm)[7:0]};  // 提取最低字节并零扩展
    //next_pc = pc + 4;
    mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b000;
                    next_state = WAIT_READY;

   // $display("1111111 rsdata = %h",pmem_read(rs1_data + imm));
    //$display("2222222 result = %h",result);
    
    end
    6'b011001: begin
    // SLLI (Shift Left Logical Immediate)
   // $display("Executing SLLI operation in EXU.");
    result = rs1_data_r << imm_r[4:0];  // SLLI 使用 imm 的低 5 位进行移位操作
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b011010: begin
    // BGEU (Branch if Greater Than or Equal, Unsigned)
   // $display("Executing BGEU operation in EXU.");
    if (rs1_data_r >= rs2_data_r) begin
        next_pc = pc_r + imm_r;  // 跳转到目标地址
    end else begin
        next_pc = pc_r + 4;  // 不满足条件，跳转到下一条指令
    end
  
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b011011: begin
    // BLTU (Branch if Less Than, Unsigned)
   // $display("Executing BLTU operation in EXU.");
    if (rs1_data_r < rs2_data_r) begin
        next_pc = pc_r + imm_r;  // 跳转到目标地址
    end else begin
        next_pc = pc_r + 4;  // 不满足条件，跳转到下一条指令
    end
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b011100: begin
    // SLTU (Set Less Than Unsigned)
    result = (rs1_data_r < rs2_data_r) ? 32'b1 : 32'b0;
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b011101: begin
    // SLT (Set Less Than)
    result = ($signed(rs1_data_r) < $signed(rs2_data_r)) ? 32'b1 : 32'b0;
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b011110: begin
    // BLT (Branch if Less Than)
    if ($signed(rs1_data_r) < $signed(rs2_data_r)) begin
        next_pc = pc_r + imm_r;  // 跳转到目标地址
    end else begin
        next_pc = pc_r + 4;  // 否则跳转到下一条指令
    end
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b011111: begin
    // LH (Load Halfword)
   // $display("Executing LH operation in EXU.");
    //result = {{16{pmem_read(rs1_data + imm)[15]}}, pmem_read(rs1_data + imm)[15:0]};  // 读取半字并符号扩展为32位
    //next_pc = pc + 4;
         mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b001;
                    next_state = WAIT_READY;
    end
    6'b100000: begin
    // LHU (Load Halfword Unsigned)
   // $display("Executing LHU operation in EXU.");
    //result = {16'b0, pmem_read(rs1_data + imm)[15:0]};  // 读取半字并零扩展为32位
    //next_pc = pc + 4;
     mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b001;
                    next_state = WAIT_READY;
    end
    6'b100001: begin
    // SRA (算术右移，带符号扩展)
    result = $signed(rs1_data_r) >>> rs2_data_r[4:0];  // 使用 rs2_data 的低 5 位作为移位位数
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end 
    6'b100010: begin
    // SRL (逻辑右移)
    result = rs1_data_r >> rs2_data_r[4:0];  // 使用 rs2_data 的低 5 位作为移位位数
    next_pc = pc_r + 4;
    rd_data = result;
    rd_valid = 1;
    pc_valid = 1;
     next_state = WAIT_READY;  // 进入等待状态
    end
    6'b100011: begin
    // SB (Store Byte)
   // result = rs1_data + imm;  // 计算存储地址
    //next_pc = pc + 4;
    //pmem_write(result, rs2_data, 1);  // 将 rs2_data 的低8位写入 result 指定的地址，mask为1表示写入1个字节
   // $display("Executing SB operation in EXU. Writing %h to address %h", rs2_data[7:0], result);
   mem_addr = rs1_data_r + imm_r;
                    mem_wdata = rs2_data_r;
                    mem_valid = 1;
                    mem_wen = 1;
                    mem_wmask = 1;
                    mem_awsize = 3'b000;
                    next_state = WAIT_READY;

    end
    6'b100100: begin
  // LB (Load Byte)
  //result = {{24{pmem_read(rs1_data + imm)[7]}}, pmem_read(rs1_data + imm)[7:0]};  // 从内存读取字节并符号扩展到32位
  //next_pc = pc + 4;
   mem_addr = rs1_data_r + imm_r;
                    mem_valid = 1;
                    mem_wen = 0;
                    mem_wmask = 0;
                    mem_arsize = 3'b000;
                    next_state = WAIT_READY;
    end
    6'b100101: begin
  // ORI (按位或立即数)
  result = rs1_data_r | imm_r;
  next_pc = pc_r + 4;
  rd_data = result;
  rd_valid = 1;
  pc_valid = 1;
   next_state = WAIT_READY;  // 进入等待状态
   end
   6'b100110: begin
  // SLTI (Set Less Than Immediate)
  result = ($signed(rs1_data_r) < $signed(imm_r)) ? 32'b1 : 32'b0;
  next_pc = pc_r + 4;
  rd_data = result;
  rd_valid = 1;
  pc_valid = 1;
   next_state = WAIT_READY;  // 进入等待状态
   end

   6'b110000: begin  // CSRRW
  result = csr_rdata_r;
  rd_data = result;
  csr_wdata = rs1_data_r;
  csr_wen = 1;
  next_pc = pc_r + 4;
  
  rd_valid = 1;
  pc_valid = 1;

  csr_rd_valid = 1;
   next_state = WAIT_READY;  // 进入等待状态
end
6'b110001: begin  // CSRRS
  result = csr_rdata_r;
  rd_data = result;
  csr_wdata = csr_rdata_r | rs1_data_r;
  csr_wen = 1;
 
  next_pc = pc_r + 4;
    rd_valid = 1;
  pc_valid = 1;
  csr_rd_valid = 1;
   next_state = WAIT_READY;  // 进入等待状态
end
6'b110010: begin  // ECALL
       csr_addr2 = 12'h341;            // MEPC 地址
      csr_wdata2 = pc_r;                 // 当前 PC
      csr_wen2 = 1;                    // 使能写入

      // 写入 mcause
      
      csr_addr1 = 12'h342;              // MCAUSE 地址
      csr_wdata1 = 32'd17;        // ECALL 的原因码（根据需求调整）
      csr_wen1 = 1;                      // 使能写入

csr_rd_valid = 1;
  next_pc = mtvec_r;
  pc_valid = 1;
  next_state = WAIT_READY;
  // 在CSR模块中设置mcause和mepc
end
6'b110011: begin  // MRET
 
 // 修改mstatus
   // reg [31:0] mstatus_new;
   // mstatus_new = mstatus_r;  // 先复制当前值
    
    // 1. 将MPIE（位3）的值复制到MIE（位7）
    if ((mstatus_new & 32'h80) != 0) begin  // 如果MPIE为1
        mstatus_new = mstatus_new | 32'h8;  // 设置MIE位
    end else begin
        mstatus_new = mstatus_new & ~32'h8; // 清除MIE位
    end
    
    // 2. 设置MPIE为1
    mstatus_new = mstatus_new | 32'h80;
    
    // 3. 清除MPP字段（bits 12:11）
    mstatus_new = mstatus_new & 32'hFFFFE7FF;

     csr_addr3 = 12'h300;
  csr_wdata3 = mstatus_new;
  csr_wen3 = 1;
  




  csr_rd_valid = 1;
  pc_valid = 1;
  next_pc = mepc_r;
  next_state = WAIT_READY;
end
6'b110100: begin
    // SH (Store Halfword)
   
 // result = rs1_data + imm;  // 先计算存储地址
   // pmem_write(result, rs2_data, 2);  // 将rs2_data的低16位写入计算出的地址
   // next_pc = pc + 4;

         // SH
                    mem_addr = rs1_data_r + imm_r;
                    mem_wdata = rs2_data_r;
                    mem_valid = 1;
                    mem_wen = 1;
                    mem_wmask = 2;
                    mem_awsize = 3'b001;
                    next_state = WAIT_READY;
                

end

    default: begin
        $display("111default:didnt match any inst from (exu.v)");
        // NOP 或未实现的操作
        // 已经在开始时赋值了 result 和 next_pc 的默认值

      end

    endcase
    end
    //end



WAIT_READY: begin
    case (alu_op_r)
        // 需要写回寄存器和更新PC的指令
        6'b000000,      // ADDI
        6'b000001,      // LUI
        6'b000010,      // AUIPC
        6'b000011,      // JAL
        6'b000100,      // JALR
        6'b000101,      // ADD
        6'b001100,      // SUB
        6'b001101,      // SLL
        6'b001110,      // XORI
        6'b010000,      // AND
        6'b010001,      // SRAI
        6'b010010,      // SNEZ
        6'b010011,      // ANDI
        6'b010100,      // OR
        6'b010110,      // SRLI
        6'b010111,      // XOR
        6'b011001,      // SLLI
        6'b011100,      // SLTU
        6'b011101,      // SLT
        6'b100101,      // ORI
        6'b100110:begin      // SLTI
       
            rd_valid = 1;
            pc_valid = 1;
            if (rd_ready && pc_ready) begin
                next_state = IDLE;
                rd_valid = 0;
                pc_valid = 0;
            end
        end



         6'b110000,      // CSRRW
        6'b110001: begin // CSRRS
           rd_valid = 1;
            pc_valid = 1;
            csr_rd_valid = 1;
            if (rd_ready && pc_ready && csr_rd_ready) begin
                next_state = IDLE;
                rd_valid = 0;
                pc_valid = 0;
                csr_rd_valid = 0;
            end
        end



        // 只需要更新PC的指令
        6'b000110,      // BEQ
        6'b000111,      // BNE
        6'b010101,      // BGE
        6'b011010,      // BGEU
        6'b011011,      // BLTU
        6'b011110: begin      // BLT
     
            pc_valid = 1;

            if (pc_ready) begin
                next_state = IDLE;
                pc_valid = 0;
            end
        end

   6'b110010 : begin      // ECALL
     csr_rd_valid = 1;
     pc_valid = 1;
     if(csr_rd_ready && pc_ready && rd_ready)begin
      next_state = IDLE;
      csr_rd_valid = 0;
      pc_valid = 0;

     end

   end
        6'b110011: begin // MRET
       csr_rd_valid = 1;
       pc_valid = 1;
       if(csr_rd_ready && pc_ready && rd_ready) begin
        next_state = IDLE;
        csr_rd_valid  = 0;
        pc_valid = 0;
        end
        end







  6'b001000: begin  // LW
                mem_valid = 1;
                if (mem_ready) begin
                    result = mem_rdata;
                    rd_data = result;
                    rd_valid = 1;
                    next_pc = pc + 4;
                    pc_valid = 1;
                    if (rd_ready && pc_ready) begin
                        //inst_ready = 1;
                        next_state = IDLE;
                            //rd_valid = 0;
                            //pc_valid = 0;
                            //csr_rd_valid = 0;
                    end
                end
            end

          6'b011000: begin  // LBU
                mem_valid = 1;
                if (mem_ready) begin
                    result = {24'b0, mem_rdata[7:0]};//lbu无符号加载字节，需要手动 exu 进行处理，0补位（lb是高位补位，具体逻辑在lsu中）
                   // $display("result is %h from exu.v line:212", result);
                   // $display("mem_rdata is %h from exu.v line:212", mem_rdata);
                    rd_data = result;
                    rd_valid = 1;
                    next_pc = pc + 4;
                    pc_valid = 1;
                  //  $display("rd_ready and pc_ready is %d and %d from exu.v line:212", rd_ready, pc_ready);
                    if (rd_ready && pc_ready) begin
                       // inst_ready = 1;
                        next_state = IDLE;
                    end
                end
            end

            6'b001001, 6'b100011, 6'b110100: begin  // SW, SB, SH
                mem_valid = 1;
                if (mem_ready) begin
                    next_pc = pc + 4;
                    pc_valid = 1;
                    if (pc_ready) begin
                       // inst_ready = 1;
                        next_state = IDLE;
                          //  rd_valid = 0;
                          //  pc_valid = 0;
                            //csr_rd_valid = 0;
                    end
                end
            end
  
                6'b100100: begin  // LB
            mem_valid = 1;
            if (mem_ready) begin
                //result = {{24{mem_rdata[7]}}, mem_rdata[7:0]};  // 符号扩展
                result = mem_rdata;//在lsu中已扩展可直接赋值
                rd_data = result;
                rd_valid = 1;
                next_pc = pc + 4;
                pc_valid = 1;
                if (rd_ready && pc_ready) begin
                   // inst_ready = 1;
                    next_state = IDLE;
                end
            end
        end
         
                 6'b011111: begin  // LH
            mem_valid = 1;
            if (mem_ready) begin
               // result = {{16{mem_rdata[15]}}, mem_rdata[15:0]};  // 符号扩展 
                result = mem_rdata;//在lsu中已扩展可直接赋值
                rd_data = result;
                rd_valid = 1;
                next_pc = pc + 4;
                pc_valid = 1;
                if (rd_ready && pc_ready) begin
                  //  inst_ready = 1;
                    next_state = IDLE;
                end
            end
        end
       

               6'b100000: begin  // LHU
            mem_valid = 1;
            if (mem_ready) begin
                result = {16'b0, mem_rdata[15:0]};  // 需手动在exu补0扩展
               // result = mem_rdata;
                rd_data = result;
                rd_valid = 1;
                next_pc = pc + 4;
                pc_valid = 1;
                if (rd_ready && pc_ready) begin
                  //  inst_ready = 1;
                    next_state = IDLE;
                end
            end
        end



      default: begin
        //$display("222default:didnt match any inst from (exu.v)");
        // NOP 或未实现的操作
        // 已经在开始时赋值了 result 和 next_pc 的默认值
        next_state = IDLE;

      end
    endcase
    
  end
  endcase
end

       
endmodule
