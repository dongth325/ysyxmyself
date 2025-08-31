module ysyx_24090012_RegisterFile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
  input clock,
  input reset,
  input [31:0] pc,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
  input [ADDR_WIDTH-1:0] waddr,
  input [DATA_WIDTH-1:0] wdata,
  input wen,
  input  rd_valid, // 来自EXU的写请求
  output reg  rd_ready,  // 写就绪信号 
  output [DATA_WIDTH-1:0] rdata1,
  output [DATA_WIDTH-1:0] rdata2
);
 

  

  // 导出函数供C语言访问
  export "DPI-C" function get_reg_value;    //综合需要注释
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];  //综合需要实现16个而不是32个
//reg [DATA_WIDTH-1:0] rf [15:0];
  // 读出数据
  assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];
  assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];
      

  // 写数据
  /*always @(posedge clk) begin
    if (wen && rd_valid && rd_ready && waddr != 5'b0) begin
     // $display("At time %t: Writing to  (rf[%d]), old value = %h from (registerfile.v11111)", $time, waddr,rf[waddr]);
      rf[waddr] <= wdata;  // 忽略对x0寄存器的写操作
 
    end
  end*/
    always @(posedge clock) begin
        if (reset) begin
            rd_ready <= 1;
        end else if (rd_valid && rd_ready) begin
            // 握手成功，写入数据并拉低ready
            
            if (waddr != 0) begin
                rf[waddr] <= wdata;
            end
            rd_ready <= 0;  // 写入过程中拉低ready
        end else if (!rd_ready) begin
            // 写入已完成，重新拉高readys
            rd_ready <= 1;
        end
    end


 

 // 实现 get_reg0 函数以返回寄存器0的值
  function void get_reg0(output int reg0_value);
    reg0_value = rf[0];  // 假设 rf 存储寄存器值的数组
  endfunction

                                                  //综合需要注释

function int get_reg_value(input int reg_index);
  get_reg_value = rf[reg_index]; // 根据索引返回寄存器的值
  
endfunction
 
 
endmodule



