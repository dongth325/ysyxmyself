module ysyx_24090012_RegisterFile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
  input clock,
  input reset,
  input [31:0] next_pc,
  output reg [31:0] pc,
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
  //reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];  //综合需要实现16个而不是32个
  reg [DATA_WIDTH-1:0] rf [15:0];
  
  // 状态定义
  localparam IDLE = 1'b0;    // 空闲状态，等待写请求
  localparam WRITE = 1'b1;   // 写入状态，执行寄存器写入
  
  // 状态寄存器
  reg state, next_state;
  reg [31:0] saved_pc;
  // 保存写请求的寄存器
  reg [ADDR_WIDTH-1:0] saved_waddr;
  reg [DATA_WIDTH-1:0] saved_wdata;
  reg saved_wen;
  
  // 读出数据
  assign rdata1 = (raddr1[3:0] == 4'b0) ? 32'b0 : rf[raddr1[3:0]];
  assign rdata2 = (raddr2[3:0] == 4'b0) ? 32'b0 : rf[raddr2[3:0]];
  
  always @(posedge clock) begin
    if (reset) begin
      state <= IDLE;
      saved_waddr <= 0;
      saved_wdata <= 0;
      saved_wen <= 0;
      pc <= 32'h3000_0000;
    end else begin
      // 状态更新
      state <= next_state;
      
      // 数据处理
      if (state == IDLE) begin
        if (rd_valid && rd_ready) begin
          // 保存写请求数据
          saved_waddr <= waddr;
          saved_wdata <= wdata;
          saved_wen <= wen;
          saved_pc <= next_pc;
        end
      end else if (state == WRITE) begin

        pc <= saved_pc;
        // 执行写入操作
        if (saved_wen && saved_waddr[3:0] != 0) begin
          rf[saved_waddr[3:0]] <= saved_wdata;
        end
       
      end
    end
  end




  


















  
  // 状态机逻辑和数据保存
  always @(*) begin
    // 默认值
    next_state = state;
    rd_ready = 1'b0;
    
    case (state)
      IDLE: begin
        rd_ready = 1'b1;
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
  


  // 实现 get_reg0 函数以返回寄存器0的值
  function void get_reg0(output int reg0_value);
    reg0_value = rf[0];  // 假设 rf 存储寄存器值的数组
  endfunction

  //综合需要注释
  function int get_reg_value(input int reg_index);
    get_reg_value = rf[reg_index]; // 根据索引返回寄存器的值
  endfunction
 
endmodule






