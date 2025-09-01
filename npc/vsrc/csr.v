module ysyx_24090012_CSR (
  input clk,
  input rst,
  input [11:0] csr_addr,//read
  input [11:0] wbu_csr_addr,//write
  input [31:0] csr_wdata,
  input csr_wen,

  input [31:0] pc,
   
  output reg [31:0] csr_rdata,
  
  input wbu_csr_valid,
  output reg wbu_csr_ready,

  input is_ecall,

 
  
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
  reg [11:0] saved_csr_addr;
  reg [31:0] saved_csr_wdata;
  reg saved_csr_wen;
  reg saved_is_ecall;
 
  reg [31:0] saved_pc;  // 用于ECALL保存PC

  // CSR寄存器初始化和写入逻辑
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      mstatus <= 32'h0;  // MPP = 11 (M模式)
      mtvec   <= 32'h0;
      mepc    <= 32'h0;
      mcause  <= 32'h0;
      state <= IDLE;
      saved_csr_addr <= 12'h0;
      saved_csr_wdata <= 32'h0;
      saved_csr_wen <= 1'b0;
      saved_is_ecall <= 1'b0;
     
      saved_pc <= 32'h0;
    end
    else begin
      // 状态更新
      state <= next_state;
            // 数据处理
      if (state == IDLE) begin
        if (wbu_csr_valid && wbu_csr_ready) begin
          // 保存CSR请求数据
          saved_csr_addr <= wbu_csr_addr;
          saved_csr_wdata <= csr_wdata;
          saved_csr_wen <= csr_wen;
          saved_is_ecall <= is_ecall;
         
          saved_pc <=  pc; // 对于ECALL，csr_wdata是当前PC
        end
      end
      else if (state == WRITE) begin
        // 执行CSR操作
        if(!saved_is_ecall) begin
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
        if (saved_is_ecall) begin
          mepc <= saved_pc;        // 保存当前PC到mepc
          mcause <= 32'h0000000b;  // 环境调用异常码
        end
       
      end
    end
  end





  // 状态机逻辑
  always @(*) begin
    // 默认值
    next_state = state;
    wbu_csr_ready = 1'b0;
    
    case (state)
      IDLE: begin
        wbu_csr_ready = 1'b1;
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











  // CSR读取逻辑
  always @(*) begin
    case (csr_addr)
      MSTATUS: csr_rdata = mstatus;
      MTVEC:   csr_rdata = mtvec;
      MEPC:    csr_rdata = mepc;
      MCAUSE:  csr_rdata = mcause;
      MVENDORID: csr_rdata = mvendorid;
      MARCHID:  csr_rdata = marchid;
      default: csr_rdata = 32'h0;
    endcase
  end



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