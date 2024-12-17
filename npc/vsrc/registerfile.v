module ysyx_24090012_RegisterFile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
  input clk,
  input rst,
  input [31:0] pc,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
  input [ADDR_WIDTH-1:0] waddr,
  input [DATA_WIDTH-1:0] wdata,
  input wen,
  output [DATA_WIDTH-1:0] rdata1,
  output [DATA_WIDTH-1:0] rdata2
);
 
always @(*) begin
    //  $display("At time %t: rigister touch PC = 0x%08x", $time, pc);
    end



  // 导出函数供C语言访问
export "DPI-C" function get_reg_value;
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
  // 读出数据
  assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];
  assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];
      

  // 写数据
  always @(posedge clk) begin
    if (wen && waddr != 5'b0) begin
     // $display("At time %t: Writing to  (rf[%d]), old value = %h from (registerfile.v11111)", $time, waddr,rf[waddr]);
      rf[waddr] <= wdata;  // 忽略对x0寄存器的写操作

      //  $display("At time %t: Writing to  (rf[%d]), new value = %h from (registerfile.v22222)", $time, waddr,wdata);
       // $display("At time %t: Writing to  (rf[%d]), new value = %h from (registerfile.v22222)", $time, waddr,rf[waddr]);
     // end
     if(pc == 32'h80001324) begin
      //  $display(" addr = %08x     wdata = %08x   rf[waddr] = %08x from (registerfile.v)",waddr,wdata,rf[waddr]);
    end
    if(pc == 32'h80001328) begin
     //   $display(" addr =  %08x     wdata = %08x   rf[waddr] = %08x from (reginsterfile.v)",waddr,wdata,rf[waddr]);
    end
    if(pc == 32'h8000132c) begin
       // $display(" addr =   %08x    wdata = %08x   rf[waddr] = %08x from (registerfile.v)",waddr,wdata,rf[waddr]);
    end
    end
  end

    // 调试语句：监控 raddr1 和 raddr2 的读取
  always @(posedge clk) begin
    if (raddr1 == 15) begin  // 当读取  寄存器时
      //$display("At time %t: Reading from a (rf[15]), value = %h from (registerfile.v)", $time, rdata1);
    end
    if (raddr2 == 15) begin  // 当从 raddr2 读取  寄存器时
      //$display("At time %t: Reading from a (rf[15]), value = %h", $time, rdata2);
    end
  end

 // 实现 get_reg0 函数以返回寄存器0的值
  function void get_reg0(output int reg0_value);
    reg0_value = rf[0];  // 假设 rf 存储寄存器值的数组
  endfunction



function int get_reg_value(input int reg_index);
  get_reg_value = rf[reg_index]; // 根据索引返回寄存器的值
  
endfunction
 
 
endmodule



