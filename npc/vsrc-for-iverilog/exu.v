
//删除了latch 和 wait ready状态   只保留idle 和 exec状态  但是没有处理 csr部分



module ysyx_24090012_EXU(
  input rst,
  input clk,  // 添加时钟输入
  input        idu_valid,      // 新增：IDU数据有效信号
  output    idu_ready,      // 新增：EXU就绪信号
  input [31:0] pc,
  output [1:0] state_out,
 
// LSU接口 (master)
    
    output  [31:0] mem_addr,
    output         mem_valid,
    output  [31:0] mem_wdata,
   
   
    input   wire         mem_ready,

    input [31:0] rs1_data,
    input [31:0] rs2_data,
  
   

   // output reg is_use_lsu,//流水线流水线流水线

    input [31:0] idu_to_exu_inst,
    output  [31:0] exu_to_lsu_inst,
    
    output wire [63:0] exu_reg_num,
  
    output wire [31:0] rd_data,
    
    output wire [31:0] next_pc,

    output wire [31:0] exu_hazard_result,


    // PC更新接口 (master)
   
    output [31:0] out_pc,

    output wire [31:0] data_hazard_exu_inst,

    


    input [31:0] mtvec,
    input [31:0] mepc,

  input [31:0] imm,
  input [5:0] alu_op,
  

 
    input [11:0] csr_addr,
    input  csr_wen,


    input [31:0] csr_rdata,//csr csr csr csr

    output  [11:0] out_csr_addr,



    output  wire [31:0] csr_wdata,//csr csr csr csr

    output  out_csr_wen,//csr csr csr csr
    input [63:0] num,
    output reg [63:0] num_r
   

 
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
  
    reg [31:0] imm_r;
    reg [5:0]  alu_op_r;
   
    
    // CSR输入数据寄存器
    reg [31:0] mtvec_r;
    reg [31:0] mepc_r;

    reg [31:0] csr_rdata_r;

  
    
    reg [31:0] exu_count;    // EXU执行指令计数器

    reg [31:0] idu_to_exu_inst_r;

    assign data_hazard_exu_inst = idu_to_exu_inst_r;

  assign exu_to_lsu_inst = idu_to_exu_inst_r;

  assign exu_reg_num = num_r;


  assign exu_hazard_result = rd_data;


 assign state_out = state; 


always @(posedge clk) begin
   // 当指令执行完成时，增加计数器

end

    // 状态转换
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            exu_count <= 0;
        end else begin
          
            state <= next_state;

            if (state == EXEC && next_state == IDLE) begin
              exu_count <= exu_count + 1;
          end
        end
    end
    
        // 流水线寄存器更新
    always @(posedge clk or posedge rst) begin
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
          
            csr_rdata_r <= 32'b0;
            num_r <= 64'h0;
            idu_to_exu_inst_r <= 32'b0;
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
           
      
            csr_rdata_r <= csr_rdata;
            num_r <= num;
            idu_to_exu_inst_r <= idu_to_exu_inst;
        end
    end



   /* always @(posedge clk) begin
      if (alu_op_r == 6'b010001) begin  // 当执行SRAI操作时打印
        
          $display("rs1_data_r = 32'h%h", rs1_data_r);
          $display("imm_r[4:0] = 5'b%b (Decimal: %0d)", imm_r[4:0], imm_r[4:0]);
          $display("num_r = 64'h%h", num_r);
          $display("rd_data = 32'h%h", rd_data);
        //  $display("srai_data = 32'h%h", srai_data);
          $display("shift result = 32'h%h", $signed(rs1_data_r) >>> imm_r[4:0]);

          $display("----------------------------------");
      end
  end*/


   wire [31:0] srai_data = $signed(rs1_data_r) >>> imm_r[4:0];
   wire [31:0] sra_data = $signed(rs1_data_r) >>> rs2_data_r[4:0];

    assign rd_data =      //没有s指令
    (alu_op_r == 6'b101111) ? rs1_data_r + imm_r :                                  // ADDI
    (alu_op_r == 6'b000001) ? imm_r :                                               // LUI
    (alu_op_r == 6'b000010) ? pc_r + imm_r :                                        // AUIPC
    (alu_op_r == 6'b000011) ? pc_r + 4 :                                            // JAL
    (alu_op_r == 6'b000100) ? pc_r + 4 :                                            // JALR
    (alu_op_r == 6'b000101) ? rs1_data_r + rs2_data_r :                             // ADD
    (alu_op_r == 6'b001010) ? (rs1_data_r == 0) ? 32'h1 : 32'h0 :                   // SEQZ
    (alu_op_r == 6'b001100) ? rs1_data_r - rs2_data_r :                             // SUB
    (alu_op_r == 6'b001101) ? rs1_data_r << rs2_data_r[4:0] :                       // SLL
    (alu_op_r == 6'b001110) ? rs1_data_r ^ imm_r :                                  // XORI
    (alu_op_r == 6'b001111) ? {24'b0, rs1_data_r[7:0]} :                            // ZEXT.B
    (alu_op_r == 6'b010000) ? rs1_data_r & rs2_data_r :                             // AND
    (alu_op_r == 6'b010001) ? srai_data :                  // SRAI
    (alu_op_r == 6'b010010) ? (rs2_data_r != 0) ? 32'h1 : 32'h0 :                   // SNEZ
    (alu_op_r == 6'b010011) ? rs1_data_r & imm_r :                                  // ANDI
    (alu_op_r == 6'b010100) ? rs1_data_r | rs2_data_r :                             // OR
    (alu_op_r == 6'b010110) ? rs1_data_r >> imm_r[4:0] :                            // SRLI
    (alu_op_r == 6'b010111) ? rs1_data_r ^ rs2_data_r :                             // XOR
    (alu_op_r == 6'b011001) ? rs1_data_r << imm_r[4:0] :                            // SLLI
    (alu_op_r == 6'b011100) ? (rs1_data_r < rs2_data_r) ? 32'h1 : 32'h0 :           // SLTU
    (alu_op_r == 6'b011101) ? ($signed(rs1_data_r) < $signed(rs2_data_r)) ? 32'h1 : 32'h0 : // SLT
    (alu_op_r == 6'b100001) ? sra_data :             // SRA
    (alu_op_r == 6'b100010) ? rs1_data_r >> rs2_data_r[4:0] :                       // SRL
    (alu_op_r == 6'b100101) ? rs1_data_r | imm_r :                                  // ORI
    (alu_op_r == 6'b100110) ? ($signed(rs1_data_r) < $signed(imm_r)) ? 32'h1 : 32'h0 : // SLTI
    (alu_op_r == 6'b110000) ? csr_rdata_r :                                         // CSRRW
    (alu_op_r == 6'b110001) ? csr_rdata_r :                                         // CSRRS
    32'h0; 


// 直接计算next_pc
    assign next_pc = 
    (alu_op_r == 6'b000011) ? pc_r + imm_r :                                       // JAL
    (alu_op_r == 6'b000100) ? (rs1_data_r + imm_r) & ~32'h1 :                      // JALR
    (alu_op_r == 6'b000110) ? (rs1_data_r == rs2_data_r) ? pc_r + imm_r : pc_r + 4 :  // BEQ
    (alu_op_r == 6'b000111) ? (rs1_data_r != rs2_data_r) ? pc_r + imm_r : pc_r + 4 :  // BNE
    (alu_op_r == 6'b010101) ? ($signed(rs1_data_r) >= $signed(rs2_data_r)) ? pc_r + imm_r : pc_r + 4 : // BGE
    (alu_op_r == 6'b011010) ? (rs1_data_r >= rs2_data_r) ? pc_r + imm_r : pc_r + 4 :  // BGEU
    (alu_op_r == 6'b011011) ? (rs1_data_r < rs2_data_r) ? pc_r + imm_r : pc_r + 4 :   // BLTU
    (alu_op_r == 6'b011110) ? ($signed(rs1_data_r) < $signed(rs2_data_r)) ? pc_r + imm_r : pc_r + 4 : // BLT
    (alu_op_r == 6'b110010) ? mtvec_r :                                            // ECALL
    (alu_op_r == 6'b110011) ? mepc_r :                                             // MRET
        
    (alu_op_r == 6'b000001) ? pc_r + 4 : // LUI
    (alu_op_r == 6'b000010) ? pc_r + 4 : // AUIPC
    (alu_op_r == 6'b000101) ? pc_r + 4 : // ADD
    (alu_op_r == 6'b001100) ? pc_r + 4 : // SUB
    (alu_op_r == 6'b001101) ? pc_r + 4 : // SLL
    (alu_op_r == 6'b010000) ? pc_r + 4 : // AND
    (alu_op_r == 6'b010010) ? pc_r + 4 : // SNEZ
    (alu_op_r == 6'b011100) ? pc_r + 4 : // SLTU
    (alu_op_r == 6'b010100) ? pc_r + 4 : // OR
    (alu_op_r == 6'b010111) ? pc_r + 4 : // XOR
    (alu_op_r == 6'b011101) ? pc_r + 4 : // SLT
    (alu_op_r == 6'b100001) ? pc_r + 4 : // SRA
    (alu_op_r == 6'b100010) ? pc_r + 4 : // SRL
    (alu_op_r == 6'b101111) ? pc_r + 4 : // ADDI
    (alu_op_r == 6'b100101) ? pc_r + 4 : // ORI
    (alu_op_r == 6'b100110) ? pc_r + 4 : // SLTI
    (alu_op_r == 6'b001010) ? pc_r + 4 : // SEQZ
    (alu_op_r == 6'b001110) ? pc_r + 4 : // XORI
    (alu_op_r == 6'b001111) ? pc_r + 4 : // ZEXT.B
    (alu_op_r == 6'b010001) ? pc_r + 4 : // SRAI
    (alu_op_r == 6'b010011) ? pc_r + 4 : // ANDI
    (alu_op_r == 6'b010110) ? pc_r + 4 : // SRLI
    (alu_op_r == 6'b011001) ? pc_r + 4 : // SLLI
    (alu_op_r == 6'b100100) ? pc_r + 4 : // LB
    (alu_op_r == 6'b001000) ? pc_r + 4 : // LW
    (alu_op_r == 6'b011000) ? pc_r + 4 : // LBU
    (alu_op_r == 6'b011111) ? pc_r + 4 : // LH
    (alu_op_r == 6'b100000) ? pc_r + 4 : // LHU
    (alu_op_r == 6'b100011) ? pc_r + 4 : // SB
    (alu_op_r == 6'b110100) ? pc_r + 4 : // SH
    (alu_op_r == 6'b001001) ? pc_r + 4 : // SW
    (alu_op_r == 6'b001011) ? pc_r + 4 : // EBREAK
    (alu_op_r == 6'b110000) ? pc_r + 4 : // CSRRW
    (alu_op_r == 6'b110001) ? pc_r + 4 : // CSRRS
    pc_r ; 



  

    // CSR写数据
    assign csr_wdata = 
        (alu_op_r == 6'b110000) ? rs1_data_r :          // CSRRW
        (alu_op_r == 6'b110001) ? csr_rdata_r | rs1_data_r :  // CSRRS
        32'h0;



    assign out_pc = pc_r;


    assign mem_valid = (state == EXEC);
    assign idu_ready = (state == IDLE);
    assign mem_addr = rs1_data_r + imm_r;
    assign mem_wdata = rs2_data_r;
 
    assign next_state = (state == EXEC && mem_ready) ? IDLE :
    (state == IDLE && idu_valid) ? EXEC :
    state; 
    
always @(*) begin

  
  //next_state = state;//mmmmmmmmmm

  
  case (state)
    IDLE: begin
      if (idu_valid && idu_ready) begin   //idu_ready在idle时一直为1
             // next_state = EXEC;
                end
            end
  
 EXEC: begin

   
    end
    
    default: begin
      
      $display("1114default:didnt match any inst from (exu.v)");    //综合需要注释
    end

  endcase
end




endmodule
