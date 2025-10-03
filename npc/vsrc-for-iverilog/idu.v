module ysyx_24090012_IDU(
  input [31:0] inst,
  input [31:0] ifu_to_idu_pc,
  
    input wire clock,        // 改用clock
    input wire reset,        // 改用reset
  //ifu interface
  output  ifu_ready,
  input  ifu_valid,


  //exu interface
  output reg exu_valid,   //尽量不要换成wire因为数据和控制冒险需要在always里，不然很麻烦
  input  exu_ready,
  output   [31:0] idu_to_exu_pc, 

   output  state_out,  // 添加state输出端口

  input [31:0] exu_next_pc,

  input [63:0] wbu_reg_num,//wbu中流水线寄存器的num
  input [63:0] exu_reg_num,//exu中流水线寄存器的num
  input [63:0] lsu_reg_num,//lsu中流水线寄存器的num

  input [31:0] wbu_hazard_result,//wbu中冒险结果
  input [31:0] exu_hazard_result,//exu中冒险结果
  input [31:0] lsu_hazard_result,//lsu中冒险结果

  output wire [31:0] idu_to_exu_inst,

  output wire control_hazard, //控制冒险信号
  output  wire [31:0] branch_target_pc, // 添加分支目标PC输出

  output wire [6:0] opcode,//pppppppp
  output wire [2:0] func3,
  output wire [6:0] func7,
  output wire [4:0] rs1,
  output wire [4:0] rs2,
  output wire [4:0] rd,//pppppppppppppp

  input [31:0] rs1_data,
  input [31:0] rs2_data,

  output wire [31:0] rs1_data_out,
  output wire [31:0] rs2_data_out,


  input [31:0] data_hazard_exu_inst,
  input [31:0] data_hazard_lsu_inst,
  input [31:0] data_hazard_wbu_inst,
  output wire rd_wen,//pppppppp
  
  output wire [5:0] alu_op,
  output wire [31:0] imm,
  output wire [11:0] csr_addr,

 
 
  input [63:0] num,
  output reg [63:0] num_r,
  input [63:0] wbu_num//wbu里面时序逻辑证明已经写入的标识num


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



    wire [6:0] exu_opcode = data_hazard_exu_inst[6:0];
    wire [4:0] exu_rd = data_hazard_exu_inst[11:7];
    wire exu_is_load = (exu_opcode == 7'b0000011);
    wire exu_rd_wen = (exu_opcode == 7'b0010011 || exu_opcode == 7'b0110111 || 
                     exu_opcode == 7'b0010111 || exu_opcode == 7'b1110011 ||
                     exu_opcode == 7'b1101111 || exu_opcode == 7'b1100111 || 
                     exu_opcode == 7'b0110011 || exu_opcode == 7'b0000011);
    
    wire [6:0] lsu_opcode = data_hazard_lsu_inst[6:0];
    wire [4:0] lsu_rd = data_hazard_lsu_inst[11:7];
    wire lsu_is_load = (lsu_opcode == 7'b0000011);
    wire lsu_rd_wen = (lsu_opcode == 7'b0010011 || lsu_opcode == 7'b0110111 || 
                     lsu_opcode == 7'b0010111 || lsu_opcode == 7'b1110011 ||
                     lsu_opcode == 7'b1101111 || lsu_opcode == 7'b1100111 || 
                     lsu_opcode == 7'b0110011 || lsu_opcode == 7'b0000011);
    
    wire [6:0] wbu_opcode = data_hazard_wbu_inst[6:0];
    wire [4:0] wbu_rd = data_hazard_wbu_inst[11:7];
    wire wbu_rd_wen = (wbu_opcode == 7'b0010011 || wbu_opcode == 7'b0110111 || 
                     wbu_opcode == 7'b0010111 || wbu_opcode == 7'b1110011 ||
                     wbu_opcode == 7'b1101111 || wbu_opcode == 7'b1100111 || 
                     wbu_opcode == 7'b0110011 || wbu_opcode == 7'b0000011);
    

wire use_rs1 = (opcode != 7'b0110111 && opcode != 7'b0010111 && 
               opcode != 7'b1101111); // LUI, AUIPC, JAL不使用rs1
wire use_rs2 = (opcode == 7'b0110011 || opcode == 7'b1100011 || 
               opcode == 7'b0100011); // R-type, B-type, S-type使用rs2

               wire rs1_exu_hazard = use_rs1 && exu_rd_wen && (rs1 == exu_rd) && (exu_rd != 5'b0);
               wire rs1_lsu_hazard = use_rs1 && lsu_rd_wen && (rs1 == lsu_rd) && (lsu_rd != 5'b0);
               wire rs1_wbu_hazard = use_rs1 && wbu_rd_wen && (rs1 == wbu_rd) && (wbu_rd != 5'b0);
               
               wire rs2_exu_hazard = use_rs2 && exu_rd_wen && (rs2 == exu_rd) && (exu_rd != 5'b0);
               wire rs2_lsu_hazard = use_rs2 && lsu_rd_wen && (rs2 == lsu_rd) && (lsu_rd != 5'b0);
               wire rs2_wbu_hazard = use_rs2 && wbu_rd_wen && (rs2 == wbu_rd) && (wbu_rd != 5'b0);
               

               assign rs1_data_out = 
               (rs1_exu_hazard && !exu_is_load) ? exu_hazard_result :
               (rs1_lsu_hazard && !lsu_is_load) ? lsu_hazard_result :
               rs1_wbu_hazard ? wbu_hazard_result :
               rs1_data;
             
             assign rs2_data_out = 
               (rs2_exu_hazard && !exu_is_load) ? exu_hazard_result :
               (rs2_lsu_hazard && !lsu_is_load) ? lsu_hazard_result :
               rs2_wbu_hazard ? wbu_hazard_result :
               rs2_data;


    assign idu_to_exu_inst = inst_r;
    assign idu_to_exu_pc = pc_r;
    assign state_out = state;//向top模块输出当前state

   

  /*  wire csr_hazard = (csr_wen && csr_wen_r == 2'b1 && csr_addr == csr_addr_r && (alu_op != 6'b110010)) ||    //两个都是普通csr指令的情况触发冒险 
    (csr_wen_r == 2'd2 && (    
       csr_addr == 12'h341 || 
       csr_addr == 12'h342  ) && csr_wen && (alu_op != 6'b110010)); //mepc和mcause    //前一个指令是ecall，后面一个是普通csr指令(csrrs csrrw)触发冒险
*/



   /*assign control_hazard = (state == BUSY) && 
   ((exu_next_pc != 32'h0 && exu_next_pc != pc_r) || 
    (exu_next_pc == 32'h0 && exu_next_pc_r != 32'h0 && exu_next_pc_r != pc_r));*/

    assign control_hazard = (state == BUSY) && 
   (exu_next_pc != 32'h0 && exu_next_pc != pc_r);

   assign branch_target_pc = exu_next_pc;

always @(posedge clock) begin
   // 当指令被EXU接收执行时，根据opcode更新指令类型计数器
   
end







    always @(posedge clock or posedge reset) begin
        if (reset) begin
            inst_r <= 32'b0;
            pc_r <= 32'b0;
            num_r <= 64'h0;
           
            idu_count <= 32'h0;
            compute_inst_count <= 32'h0;
            load_inst_count <= 32'h0;
            store_inst_count <= 32'h0;
            branch_inst_count <= 32'h0;
            jump_inst_count <= 32'h0;
            csr_inst_count <= 32'h0;
            other_inst_count <= 32'h0;

        end 
        else begin
            
            if (state == BUSY && next_state == IDLE && exu_valid && exu_ready) begin

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

         if (ifu_valid && ifu_ready) begin
          inst_r <= inst;
          pc_r <= ifu_to_idu_pc;
          idu_count <= idu_count + 1;  // idu count计数器
          num_r <= num;
          end

    end







   // 状态转换
    always @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end


    assign    rd_wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1110011||
    opcode == 7'b1101111 || opcode == 7'b1100111 || opcode == 7'b0110011 || 
     opcode == 7'b0000011);//流水线流水线流水线

    assign opcode = inst_r[6:0];
    assign func3 = inst_r[14:12];
    assign func7 = inst_r[31:25];
    assign rs1 = inst_r[19:15];
    assign rs2 = inst_r[24:20];
    assign rd = inst_r[11:7];
    assign csr_addr = inst_r[31:20];

    wire is_r_type = (opcode == 7'b0110011);//1111111
    wire is_i_type = (opcode == 7'b0010011);//111111
    wire is_b_type = (opcode == 7'b1100011);//1111111
    wire is_load = (opcode == 7'b0000011);//11111111111
    wire is_store = (opcode == 7'b0100011);//11111111
    wire is_jal = (opcode == 7'b1101111);//11111
    wire is_jalr = (opcode == 7'b1100111);//111111
    wire is_lui = (opcode == 7'b0110111);//11111111
    wire is_auipc = (opcode == 7'b0010111);//1111111111
    wire is_system = (opcode == 7'b1110011);//11111

    wire [31:0] i_imm = {{20{inst_r[31]}}, inst_r[31:20]};
    wire [31:0] u_imm = {inst_r[31:12], 12'b0};//lui
    wire [31:0] auipc_imm = {inst_r[31:12], 12'b0};//auipc
    wire [31:0] jal_imm = {{12{inst_r[31]}}, inst_r[19:12], inst_r[20], inst_r[30:21], 1'b0};
    wire [31:0] jalr_imm = {{20{inst_r[31]}}, inst_r[31:20]};
    wire [31:0] b_imm = {{19{inst_r[31]}}, inst_r[31], inst_r[7], inst_r[30:25], inst_r[11:8], 1'b0};//branch
    wire [31:0] s_imm = {{20{inst_r[31]}}, inst_r[31:25], inst_r[11:7]};//store
    wire [31:0] l_imm = {{20{inst_r[31]}}, inst_r[31:20]};//load
 
    assign imm = is_i_type ? i_imm :         //imm可以在exu中计算出
    is_load ? l_imm :
    is_jalr ? jalr_imm :
    is_store ? s_imm :
    is_b_type ? b_imm :
    is_lui ? u_imm :
    is_auipc ? auipc_imm :
    is_jal ? jal_imm : 32'b0;


    // 直接根据指令类型和功能码分配ALU操作码
assign alu_op = 
// R-type指令
(opcode == 7'b0110011 && func3 == 3'b000 && func7 == 7'b0000000) ? 6'b000101 :  // ADD
(opcode == 7'b0110011 && func3 == 3'b000 && func7 == 7'b0100000) ? 6'b001100 :  // SUB
(opcode == 7'b0110011 && func3 == 3'b001 && func7 == 7'b0000000) ? 6'b001101 :  // SLL
(opcode == 7'b0110011 && func3 == 3'b111 && func7 == 7'b0000000) ? 6'b010000 :  // AND
(opcode == 7'b0110011 && func3 == 3'b011 && func7 == 7'b0000000 && rs2 == 5'b00000) ? 6'b010010 :  // SNEZ
(opcode == 7'b0110011 && func3 == 3'b011 && func7 == 7'b0000000) ? 6'b011100 :  // SLTU
(opcode == 7'b0110011 && func3 == 3'b110 && func7 == 7'b0000000) ? 6'b010100 :  // OR
(opcode == 7'b0110011 && func3 == 3'b100 && func7 == 7'b0000000) ? 6'b010111 :  // XOR
(opcode == 7'b0110011 && func3 == 3'b010 && func7 == 7'b0000000) ? 6'b011101 :  // SLT
(opcode == 7'b0110011 && func3 == 3'b101 && func7 == 7'b0100000) ? 6'b100001 :  // SRA
(opcode == 7'b0110011 && func3 == 3'b101 && func7 == 7'b0000000) ? 6'b100010 :  // SRL

// I-type指令
(opcode == 7'b0010011 && func3 == 3'b000) ? 6'b101111 :  // ADDI
(opcode == 7'b0010011 && func3 == 3'b110) ? 6'b100101 :  // ORI
(opcode == 7'b0010011 && func3 == 3'b010) ? 6'b100110 :  // SLTI
(opcode == 7'b0010011 && func3 == 3'b011) ? 6'b001010 :  // SEQZ
(opcode == 7'b0010011 && func3 == 3'b100) ? 6'b001110 :  // XORI
(opcode == 7'b0010011 && func3 == 3'b111 && inst_r[31:20] == 12'b000011111111) ? 6'b001111 :  // ZEXT.B
(opcode == 7'b0010011 && func3 == 3'b101 && func7 == 7'b0100000) ? 6'b010001 :  // SRAI
(opcode == 7'b0010011 && func3 == 3'b111) ? 6'b010011 :  // ANDI
(opcode == 7'b0010011 && func3 == 3'b101 && func7 == 7'b0000000) ? 6'b010110 :  // SRLI
(opcode == 7'b0010011 && func3 == 3'b001 && func7 == 7'b0000000) ? 6'b011001 :  // SLLI

// Load指令
(opcode == 7'b0000011 && func3 == 3'b000) ? 6'b100100 :  // LB
(opcode == 7'b0000011 && func3 == 3'b010) ? 6'b001000 :  // LW
(opcode == 7'b0000011 && func3 == 3'b100) ? 6'b011000 :  // LBU
(opcode == 7'b0000011 && func3 == 3'b001) ? 6'b011111 :  // LH
(opcode == 7'b0000011 && func3 == 3'b101) ? 6'b100000 :  // LHU

// Store指令
(opcode == 7'b0100011 && func3 == 3'b000) ? 6'b100011 :  // SB
(opcode == 7'b0100011 && func3 == 3'b001) ? 6'b110100 :  // SH
(opcode == 7'b0100011 && func3 == 3'b010) ? 6'b001001 :  // SW

// Branch指令
(opcode == 7'b1100011 && func3 == 3'b000) ? 6'b000110 :  // BEQ
(opcode == 7'b1100011 && func3 == 3'b001) ? 6'b000111 :  // BNE
(opcode == 7'b1100011 && func3 == 3'b101) ? 6'b010101 :  // BGE
(opcode == 7'b1100011 && func3 == 3'b111) ? 6'b011010 :  // BGEU
(opcode == 7'b1100011 && func3 == 3'b110) ? 6'b011011 :  // BLTU
(opcode == 7'b1100011 && func3 == 3'b100) ? 6'b011110 :  // BLT

// System指令
(opcode == 7'b1110011 && func3 == 3'b000 && inst_r[31:20] == 12'b0) ? 6'b110010 :  // ECALL
(opcode == 7'b1110011 && func3 == 3'b000 && inst_r[31:20] == 12'b001100000010) ? 6'b110011 :  // MRET
(opcode == 7'b1110011 && func3 == 3'b000 && inst_r[31:20] == 12'b000000000001) ? 6'b001011 :  // EBREAK
(opcode == 7'b1110011 && func3 == 3'b001) ? 6'b110000 :  // CSRRW
(opcode == 7'b1110011 && func3 == 3'b010) ? 6'b110001 :  // CSRRS

// 其他特殊指令
(opcode == 7'b0110111) ? 6'b000001 :  // LUI
(opcode == 7'b0010111) ? 6'b000010 :  // AUIPC
(opcode == 7'b1101111) ? 6'b000011 :  // JAL
(opcode == 7'b1100111) ? 6'b000100 :  // JALR

// 默认值
6'b001111;  // 未实现的操作




assign ifu_ready = (state == IDLE);

    always @(*) begin

       next_state = state;
      
        exu_valid = 1'b0;



   
     
     case (state)


            IDLE: begin
              
                if (ifu_valid) begin
                    next_state = BUSY;
                end
            end
 
            BUSY: begin
             
    
   
//先检测控制冒险
    if (exu_next_pc != 32'h0 && exu_next_pc != pc_r) begin
  // 有控制冒险，阻止指令继续并立即切换状态
  exu_valid = 1'b0;
  next_state = IDLE;
end

// 其次检测数据冒险       //wbu写入后wbu num才更新
else if (((rs1_exu_hazard && exu_is_load && exu_reg_num != wbu_reg_num) || 
    (rs2_exu_hazard && exu_is_load && exu_reg_num != wbu_reg_num) ||
    (rs1_lsu_hazard && lsu_is_load && lsu_reg_num != wbu_reg_num) || 
    (rs2_lsu_hazard && lsu_is_load && lsu_reg_num != wbu_reg_num)) ) begin
// 有加载指令冒险且未解决，阻止指令继续
exu_valid = 1'b0;
    end else begin
      // 无冒险或冒险已解决，指令可以继续
      exu_valid = 1'b1;
      if (exu_ready) begin
        next_state = IDLE;
      end
    end
    
      end
            
            default: begin
                next_state = IDLE;
            end


        endcase
   
  end









endmodule
