module ysyx_24090012_NPC(
  input clk,
  input rst,
  output reg [31:0] pc,      // 将 pc 定义为输出端口
  input [31:0] mem_data,     // 将 mem_data 定义为输入端口 
  output reg ebreak_flag          // 将 ebreak 定义为输出端口
);
   import "DPI-C" function void ebreak();



  //wire [31:0] pc;
  wire [31:0] inst;
  wire [4:0] rs1, rd;
  wire [31:0] imm;
  wire [31:0] rs1_data, result;
  //wire [31:0] mem_data;

  // 实例化各个模块
  ysyx_24090012_IFU ifu(.clk(clk), .rst(rst), .pc(pc), .inst(inst), .mem_data(mem_data));
  ysyx_24090012_IDU idu(.inst(inst), .rs1(rs1), .rd(rd), .imm(imm));
  ysyx_24090012_RegisterFile regfile(.clk(clk), .rst(rst), .raddr1(rs1), .raddr2(5'b0), .waddr(rd), .wdata(result), .wen(1'b1), .rdata1(rs1_data), .rdata2());
  ysyx_24090012_EXU exu(.rs1_data(rs1_data), .imm(imm), .result(result));


    always @(posedge clk or posedge rst) begin
    if (rst) begin
      ebreak_flag <= 0;  // 复位 ebreak
    end else if (inst == 32'h00100073) begin  // 检测到 ebreak 指令
      ebreak_flag <= 1;
      ebreak();
    end else begin
            ebreak_flag <= 1'b0;  // 否则，ebreak 信号复位
        end
  end

endmodule
