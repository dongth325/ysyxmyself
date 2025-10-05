module ysyx_24090012_RegisterFile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
  input clock,
  input reset,
  input [31:0] next_pc,
  output reg [31:0] pc,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
 // input [ADDR_WIDTH-1:0] waddr,
  input [DATA_WIDTH-1:0] wdata,

  output wire [31:0] wbu_hazard_result,
  //input wen,
  input [31:0] lsu_to_wbu_inst,
  output wire [31:0] data_hazard_wbu_inst,
  input  rd_valid, // 来自EXU的写请求
  output   rd_ready,  // 写就绪信号 
  output [DATA_WIDTH-1:0] rdata1,
  output [DATA_WIDTH-1:0] rdata2,
  input [63:0] num,
  input [31:0] sim_lsu_addr,//lsu传来用于仿真环境判断读写访问地址是否跳过difftest
  output reg instr_completed,  // 新增：指令完成标志
  output reg [63:0] wbu_back_to_idu_num,
  output wire [63:0] wbu_reg_num  
);
 

  reg [DATA_WIDTH-1:0] rf [15:0];
  
  // 状态定义
  localparam IDLE = 1'b0;    // 空闲状态，等待写请求
  localparam WRITE = 1'b1;   // 写入状态，执行寄存器写入
  
  // 状态寄存器
  reg state, next_state;
  reg [31:0] saved_pc;
  // 保存写请求的寄存器
 // reg [ADDR_WIDTH-1:0] saved_waddr;
 
 // reg saved_wen;
  reg [63:0] num_r;
  reg [DATA_WIDTH-1:0] saved_wdata;
  reg [31:0] saved_sim_lsu_addr;
  reg [31:0] saved_lsu_to_wbu_inst;
  // 读出数据
  assign rdata1 = (raddr1[3:0] == 4'b0) ? 32'b0 : rf[raddr1[3:0]];
  assign rdata2 = (raddr2[3:0] == 4'b0) ? 32'b0 : rf[raddr2[3:0]];


  assign data_hazard_wbu_inst = saved_lsu_to_wbu_inst;

  assign wbu_reg_num = num_r;

  assign wbu_hazard_result = saved_wdata;




  wire [4:0] saved_waddr = saved_lsu_to_wbu_inst[11:7];
  wire [6:0] opcode = saved_lsu_to_wbu_inst[6:0];


  wire saved_wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1110011||
  opcode == 7'b1101111 || opcode == 7'b1100111 || opcode == 7'b0110011 || 
   opcode == 7'b0000011);//流水线流水线流水线
  
  always @(posedge clock or posedge reset) begin
    if (reset) begin
      state <= IDLE;
     
      saved_wdata <= 0;
     
      pc <= 32'h7FFFFFFC;
      num_r <= 64'h0;
      instr_completed <= 1'b0;  
      saved_sim_lsu_addr <= 32'h0;
      saved_lsu_to_wbu_inst <= 32'h0;
    end else begin
      // 状态更新
      state <= next_state;
      
   

      // 数据处理
      if (state == IDLE) begin
        if (rd_valid && rd_ready) begin
          // 保存写请求数据
       
          saved_wdata <= wdata;
        
          saved_pc <= next_pc;
          num_r <= num;
          saved_sim_lsu_addr <= sim_lsu_addr;
          saved_lsu_to_wbu_inst <= lsu_to_wbu_inst;
        end
        instr_completed <= 1'b0;
      end else if (state == WRITE) begin

        pc <= saved_pc;
        // 执行写入操作
        if (saved_wen && saved_waddr[3:0] != 0) begin
          rf[saved_waddr[3:0]] <= saved_wdata;
          if (saved_waddr[3:0] == 4'd2) begin
           // $display(">> WBU: Writing SP (x2) <<");
         // $display(" | PC: %h | INST: %h | WDATA: %h | NUM: %d", saved_pc, saved_lsu_to_wbu_inst, saved_wdata, num_r);
            end
        end


        wbu_back_to_idu_num <= num_r;

            // 在WRITE状态完成时设置指令完成标志
        instr_completed <= 1'b1;
       
      end
    end
  end




  
















assign rd_ready = (state == IDLE);

  
  // 状态机逻辑和数据保存
  always @(*) begin
    // 默认值
    next_state = state;
   
    
    case (state)
      IDLE: begin
       
        // 在IDLE状态，如果有有效的写请求，保存数据并转到WRITE状态
        if (rd_valid && rd_ready) begin
          next_state = WRITE;
        end
      end
      
      WRITE: begin
        // 在WRITE状态，完成写入后返回IDLE状态
        next_state = IDLE;
      end
    endcase
  end
  




endmodule





