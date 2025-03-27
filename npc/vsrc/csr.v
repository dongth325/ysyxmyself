module ysyx_24090012_CSR (
  input clk,
  input rst,
  input [11:0] csr_addr,
  input [31:0] csr_wdata,
  input csr_wen,
    input [11:0] csr_addr1,
  input [31:0] csr_wdata1,
  input csr_wen1,
    input [11:0] csr_addr2,
  input [31:0] csr_wdata2,
  input csr_wen2,
   input [11:0] csr_addr3,
  input [31:0] csr_wdata3,
  input csr_wen3,
  output reg [31:0] csr_rdata,
  
  input csr_rd_valid,
  output reg csr_rd_ready,
 
  
  
  // CSR寄存器
  output reg [31:0] mstatus,
  output reg [31:0] mtvec,
  output reg [31:0] mepc,
  output reg [31:0] mcause,
  output reg [31:0] mvendorid,
  output reg [31:0] marchid
);
export "DPI-C" function get_csr_reg_value;
  // CSR地址定义
  localparam MSTATUS = 12'h300;
  localparam MTVEC   = 12'h305;
  localparam MEPC    = 12'h341;
  localparam MCAUSE  = 12'h342;
  localparam MVENDORID = 12'hf11;
  localparam MARCHID = 12'hf12;

// 初始化标志
   //reg initialized;     //明天再来弄  使通过difftest

  // CSR寄存器初始化和写入逻辑
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      mstatus <= 32'h0;  // MPP = 11 (M模式)
      mtvec   <= 32'h0;
      mepc    <= 32'h0;
      mcause  <= 32'h0;
      csr_rd_ready <= 1;
    end

 else if (csr_rd_valid && csr_rd_ready) begin

     if (csr_wen) begin
      case (csr_addr)
        MSTATUS: mstatus <= csr_wdata;
        MTVEC:   mtvec   <= csr_wdata;
        MEPC:    mepc    <= csr_wdata;
        MCAUSE:  mcause  <= csr_wdata;
         default: ; 
      endcase
    end
      if (csr_wen1) begin
      case (csr_addr1)
        MSTATUS: mstatus <= csr_wdata1;
        MTVEC:   mtvec   <= csr_wdata1;
        MEPC:    mepc    <= csr_wdata1;
        MCAUSE:  mcause  <= csr_wdata1;
       
         default: ; 
      endcase
        //$display("csr_wdata1 = %08x",csr_wdata1);
        //$display("mcause = %08x",mcause);
    end
      if (csr_wen2) begin
      case (csr_addr2)
        MSTATUS: mstatus <= csr_wdata2;
        MTVEC:   mtvec   <= csr_wdata2;
        MEPC:    mepc    <= csr_wdata2;
        MCAUSE:  mcause  <= csr_wdata2;
         default: ; 
      endcase
        //$display("csr_wdata2 = %08x",csr_wdata2);
        //$display("mepc = %08x",mepc);
    end
    if (csr_wen3) begin
      case (csr_addr3)
        MSTATUS: mstatus <= csr_wdata3;
        MTVEC:   mtvec   <= csr_wdata3;
        MEPC:    mepc    <= csr_wdata3;
        MCAUSE:  mcause  <= csr_wdata3;
         default: ; 
      endcase
        //$display("csr_wdata2 = %08x",csr_wdata2);
        //$display("mepc = %08x",mepc);
    end
    csr_rd_ready <= 0;
 end
 else if (!csr_rd_ready) begin
            // 写入已完成，重新拉高readys
            csr_rd_ready <= 1;
        end
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
    marchid   = 32'h016F959E;  // 24090014的十六进制表示（0x16F90AE扩展为32位）
end




function int get_csr_reg_value(input int csr_reg_index);
  case (csr_reg_index)
     1:   get_csr_reg_value = mcause; // 根据索引返回寄存器的值
     2:   get_csr_reg_value = mtvec;
     3:   get_csr_reg_value = mepc;
     4:   get_csr_reg_value = mstatus;
  endcase
endfunction

endmodule