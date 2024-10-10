module ysyx_24090012_RegisterFile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
  input clk,
  input rst,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
  input [ADDR_WIDTH-1:0] waddr,
  input [DATA_WIDTH-1:0] wdata,
  input wen,
  output [DATA_WIDTH-1:0] rdata1,
  output [DATA_WIDTH-1:0] rdata2
);
   // 导出 get_rf 任务
  export "DPI-C" task get_rf;

  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
  // 读出数据
  assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];
  assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];
      

  // 写数据
  always @(posedge clk) begin
    if (wen && waddr != 5'b0) begin
      rf[waddr] <= wdata;  // 忽略对x0寄存器的写操作

         if (waddr == 10) begin  // 10 是 a0 寄存器的地址
        $display("At time %t: Writing to a0 (rf[10]), new value = %h", $time, wdata);
      end


    end
  end

    // 调试语句：监控 raddr1 和 raddr2 的读取
  always @(posedge clk) begin
    if (raddr1 == 10) begin  // 当读取 a0 寄存器时
      $display("At time %t: Reading from a0 (rf[10]), value = %h", $time, rdata1);
    end
    if (raddr2 == 10) begin  // 当从 raddr2 读取 a0 寄存器时
      $display("At time %t: Reading from a0 (rf[10]), value = %h", $time, rdata2);
    end
  end


  // 实现 get_rf 任务
  task get_rf(output reg [31:0] regs [0:31]);
    integer i;
    begin
      for (i = 0; i < 32; i = i + 1) begin
        regs[i] = rf[i];
      end
    end
  endtask
 
endmodule



