module ysyx_24090012_CSR (
  input clk,
  input rst,
  input [11:0] csr_addr,//read

  input [31:0] csr_wdata,
 
  input [31:0] lsu_to_wbu_inst,

  input [31:0] pc,
   
  output  [31:0] csr_rdata,
  
  input wbu_csr_valid,
  output  wbu_csr_ready,

 

 
  
  output reg [31:0] mtvec,
  output reg [31:0] mepc,
  output reg [31:0] mstatus,
  
  output reg [31:0] mcause,
  
  
  output reg [31:0] mvendorid,
  output reg [31:0] marchid
);
export "DPI-C" function get_csr_reg_value; //综合需要注释
  // CSR地址定义
  localparam MSTATUS = 12'h300;
  localparam MTVEC   = 12'h305;
  localparam MEPC    = 12'h341;
  localparam MCAUSE  = 12'h342;
  localparam MVENDORID = 12'hf11;
  localparam MARCHID = 12'hf12;

// 状态定义
  localparam IDLE = 1'b0;  // 空闲状态，等待请求
  localparam WRITE = 1'b1; // 写入状态，执行CSR操作
  
  // 状态寄存器
  reg state, next_state;
  
  // 保存CSR请求的寄存器

  reg [31:0] saved_csr_wdata;

 

  reg [31:0] saved_lsu_to_wbu_inst;
 
  reg [31:0] saved_pc;  // 用于ECALL保存PC


  wire [6:0] opcode = saved_lsu_to_wbu_inst[6:0];
  wire [2:0] func3 = saved_lsu_to_wbu_inst[14:12];
 
  
  wire [11:0] saved_csr_addr = saved_lsu_to_wbu_inst[31:20];

  wire is_ecall = (opcode == 7'b1110011) && (func3 == 3'b000) && (saved_lsu_to_wbu_inst[31:20] == 12'b0);
  wire is_mret = (opcode == 7'b1110011) && (func3 == 3'b000) && (saved_lsu_to_wbu_inst[31:20] == 12'b001100000010);
  wire is_csrrw = (opcode == 7'b1110011) && (func3 == 3'b001);
  wire is_csrrs = (opcode == 7'b1110011) && (func3 == 3'b010);
  
  // CSR写使能：CSRRW, CSRRS 或间接的 ECALL, MRET
  wire saved_csr_wen = is_csrrw || is_csrrs || is_ecall || is_mret;


  // CSR寄存器初始化和写入逻辑
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      mstatus <= 32'h0;  // MPP = 11 (M模式)
      mtvec   <= 32'h0;
      mepc    <= 32'h0;
      mcause  <= 32'h0;
      state <= IDLE;
   
      saved_csr_wdata <= 32'h0;
 
    
      saved_lsu_to_wbu_inst <= 32'h0;
      saved_pc <= 32'h0;
    end
    else begin
      // 状态更新
      state <= next_state;
            // 数据处理
      if (state == IDLE) begin
        if (wbu_csr_valid && wbu_csr_ready) begin
          // 保存CSR请求数据
         
          saved_csr_wdata <= csr_wdata;
        
       
          saved_lsu_to_wbu_inst <= lsu_to_wbu_inst;
          saved_pc <=  pc; // 对于ECALL，csr_wdata是当前PC
        end
      end
      else if (state == WRITE) begin
        // 执行CSR操作
        if(!is_ecall) begin
        if (saved_csr_wen) begin
          case (saved_csr_addr)
            MSTATUS: mstatus <= saved_csr_wdata;
            MTVEC:   mtvec   <= saved_csr_wdata;
            MEPC:    mepc    <= saved_csr_wdata;
            MCAUSE:  mcause  <= saved_csr_wdata;
            default: ;
          endcase
        end
      end
        
        // 处理特殊指令
        if (is_ecall) begin
          mepc <= saved_pc;        // 保存当前PC到mepc
          mcause <= 32'h0000000b;  // 环境调用异常码
        end
       
      end
    end
  end



assign wbu_csr_ready = (state == IDLE);

  // 状态机逻辑
  always @(*) begin
    // 默认值
    next_state = state;
   
    
    case (state)
      IDLE: begin
      
        // 在IDLE状态，如果有有效的CSR请求，保存数据并转到WRITE状态
        if (wbu_csr_valid && wbu_csr_ready) begin
          next_state = WRITE;
        end
      end
      
      WRITE: begin
        // 在WRITE状态，完成CSR操作后返回IDLE状态
        next_state = IDLE;
      end
    endcase
  end








// CSR读取逻辑使用wire信号
  wire [31:0] mstatus_rdata = (csr_addr == MSTATUS) ? mstatus : 32'h0;
  wire [31:0] mtvec_rdata = (csr_addr == MTVEC) ? mtvec : 32'h0;
  wire [31:0] mepc_rdata = (csr_addr == MEPC) ? mepc : 32'h0;
  wire [31:0] mcause_rdata = (csr_addr == MCAUSE) ? mcause : 32'h0;
  wire [31:0] mvendorid_rdata = (csr_addr == MVENDORID) ? mvendorid : 32'h0;
  wire [31:0] marchid_rdata = (csr_addr == MARCHID) ? marchid : 32'h0;
  
  // 所有寄存器的读取结果进行OR运算得到最终的csr_rdata
  assign csr_rdata = mstatus_rdata | mtvec_rdata | mepc_rdata | mcause_rdata | mvendorid_rdata | marchid_rdata;


  // CSR读取逻辑
/*  always @(*) begin
    case (csr_addr)
      MSTATUS: csr_rdata = mstatus;
      MTVEC:   csr_rdata = mtvec;
      MEPC:    csr_rdata = mepc;
      MCAUSE:  csr_rdata = mcause;
      MVENDORID: csr_rdata = mvendorid;
      MARCHID:  csr_rdata = marchid;
      default: csr_rdata = 32'h0;
    endcase
  end*/



  initial begin
    mvendorid = 32'h79737978;  // "ysyx"的ASCII
    marchid   = 32'h016F959E;  // 24090014的十六进制表示（0x16F959E扩展为32位）
end




function int get_csr_reg_value(input int csr_reg_index);
  case (csr_reg_index)
     1:   get_csr_reg_value = mcause; // 根据索引返回寄存器的值
     2:   get_csr_reg_value = mtvec;
     3:   get_csr_reg_value = mepc;
     4:   get_csr_reg_value = mstatus;
  endcase
endfunction   //综合需要注释

endmodule
