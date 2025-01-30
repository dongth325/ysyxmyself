module ysyx_24090012_NPC(
  input clk,
  input rst,
  input [31:0] mem_data,

  output reg [31:0] pc,
  output reg ebreak_flag,
  output reg [31:0] exit_code
);
  import "DPI-C" function void ebreak(input int exit_code);

  wire [4:0] rs1, rs2, rd;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [6:0] func7;
  wire [31:0] imm;
  wire [5:0] alu_op;
  wire [31:0] rs1_data, rs2_data, result, next_pc;
  wire wen;
  wire [31:0] inst;

    // SRAM接口信号
    wire [31:0] sram_addr;
    wire        sram_valid;
    wire        sram_ready;
    wire [31:0] sram_rdata;
    wire [31:0] sram_wdata;
    wire [3:0]  sram_wmask;
    wire       sram_wen;


   wire idu_valid;
   wire idu_ready;

   
   wire csr_rd_valid;
   wire csr_rd_ready;
    // PC更新接口
   
    wire        pc_valid;
      reg pc_ready;

        // LSU接口
    wire [31:0] mem_addr;
    wire        mem_valid;
    wire [31:0] mem_wdata;
    wire [3:0]  mem_wmask;
    wire        mem_wen;
    wire        mem_ready;
    wire [31:0] mem_rdata;

        // RegisterFile写回接口
    wire [4:0]  rd_addr;
    wire [31:0] rd_data;
    wire        rd_valid;
    wire        rd_ready;

    // CSR相关信号
reg [11:0] csr_addr3;
reg [31:0] csr_wdata3;
reg csr_wen3;
reg [11:0] csr_addr1;
reg [31:0] csr_wdata1;
reg csr_wen1;
reg [11:0] csr_addr2;
reg [31:0] csr_wdata2;
reg csr_wen2;
reg [11:0] csr_addr;
reg [31:0] csr_wdata;
reg csr_wen;
reg [31:0] mstatus_new;//用于mret指令对mstatus寄存器访问取值后的保存............





wire is_ecall, is_mret;
wire [31:0] csr_rdata;
wire [31:0] mstatus;
wire [31:0] mtvec;
wire [31:0] mepc;
wire [31:0] mcause;

 
  wire exec_enable = !clk && !rst;  // 在时钟低电平且非复位时有效




  // 实例化各个模块
  ysyx_24090012_IFU ifu(.clk(clk), .rst(rst), .pc(pc), .inst(inst), .mem_data(mem_data),.idu_valid(idu_valid),.idu_ready(idu_ready));
  ysyx_24090012_IDU idu(.inst(inst), .rs1(rs1), .rs2(rs2), .pc(pc), .rd(rd), .imm(imm), .opcode(opcode), .func3(func3), .func7(func7), .alu_op(alu_op),    .csr_addr(csr_addr),
    .csr_wen(csr_wen),
    .is_ecall(is_ecall),
    .is_mret(is_mret));
  ysyx_24090012_RegisterFile regfile(
    .pc(pc),
    .clk(clk),
    
    .rst(rst),
    .raddr1(rs1),
    .raddr2(rs2),
    .waddr(rd),
    .wdata(result),
    .wen(wen),
          .rd_valid(rd_valid),
        .rd_ready(rd_ready),

    .rdata1(rs1_data),
    .rdata2(rs2_data));
  
  ysyx_24090012_EXU exu(
    .rst(rst),
    .clk(clk),
  .pc(pc),
  .rs1_data(rs1_data),
  .rs2_data(rs2_data),  // 添加 rs2_data 连接
  .imm(imm),
  .alu_op(alu_op),
  .exec_enable(exec_enable),

  .idu_valid(idu_valid),
  .idu_ready(idu_ready),
          // LSU接口
        .mem_addr(mem_addr),
        .mem_valid(mem_valid),
        .mem_wdata(mem_wdata),
        .mem_wmask(mem_wmask),
        .mem_wen(mem_wen),
        .mem_ready(mem_ready),
        .mem_rdata(mem_rdata),

                // RegisterFile写回接口
        .rd_addr(rd_addr),
        .rd_data(rd_data),
        .rd_valid(rd_valid),
        .rd_ready(rd_ready),
        // PC更新接口
        .pc_valid(pc_valid),
        .pc_ready(pc_ready),

    .mstatus(mstatus),
    .mtvec(mtvec),
    .mcause(mcause),
    .mepc(mepc),



  .result(result),
  .next_pc(next_pc),
   .csr_rdata(csr_rdata),

    .csr_wdata(csr_wdata),
    .csr_wen(csr_wen),
      .csr_addr(csr_addr),
     
        .csr_addr1(csr_addr1),
        .csr_wdata1(csr_wdata1),
        .csr_wen1(csr_wen1),

        .csr_addr2(csr_addr2),
        .csr_wdata2(csr_wdata2),
        .csr_wen2(csr_wen2),

        .csr_addr3(csr_addr3),
        .csr_wdata3(csr_wdata3),
        .csr_wen3(csr_wen3),

        .csr_rd_valid(csr_rd_valid),
        .csr_rd_ready(csr_rd_ready)
       
);
   ysyx_24090012_CSR csr(
         .csr_rd_valid(csr_rd_valid),    // 添加这行
        .csr_rd_ready(csr_rd_ready),    // 添加这行
  .clk(clk),
  .rst(rst),
  .csr_addr(csr_addr),
  .csr_wdata(csr_wdata),
  .csr_wen(csr_wen),
   .csr_addr1(csr_addr1),
  .csr_wdata1(csr_wdata1),
  .csr_wen1(csr_wen1),
   .csr_addr2(csr_addr2),
  .csr_wdata2(csr_wdata2),
  .csr_wen2(csr_wen2),
  .csr_addr3(csr_addr3),
  .csr_wdata3(csr_wdata3),
  .csr_wen3(csr_wen3),
  .csr_rdata(csr_rdata),
  .mstatus(mstatus),
  .mtvec(mtvec),
  .mepc(mepc),
  .mcause(mcause)
);

    // 实例化LSU
    ysyx_24090012_LSU lsu(
        .clk(clk),
        .rst(rst),
        .addr(mem_addr),
        .valid(mem_valid),
        .wdata(mem_wdata),
        .wmask(mem_wmask),
        .wen(mem_wen),
        .ready(mem_ready),
        .rdata(mem_rdata),
          // SRAM接口
        .sram_addr(sram_addr),
        .sram_valid(sram_valid),
        .sram_ready(sram_ready),
        .sram_rdata(sram_rdata),
        .sram_wdata(sram_wdata),
        .sram_wmask(sram_wmask),
        .sram_wen(sram_wen)
    );
    ysyx_24090012_SRAM sram(
        .clk(clk),
        .rst(rst),
        .addr(sram_addr),      // 暂时只连接LSU
        .valid(sram_valid),
        .ready(sram_ready),
        .rdata(sram_rdata),
        .wdata(sram_wdata),
        .wmask(sram_wmask),
        .wen(sram_wen)
    );
/*reg [4:0] test;
reg [4:0] test1;
reg [4:0] test2;
reg [4:0] test3;

always @(posedge clk) begin
  if(test == 5'd8)
  test3 <= 2;
  else if(test == 5'd2)
  test3 <= 3;

end


always @(posedge clk) begin
  test <= rd;
  test2 <= test;
end
always @(*) begin
  test1 = test;
end*/

   assign wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1110011||
                opcode == 7'b1101111 || opcode == 7'b1100111 || opcode == 7'b0110011 || 
                 opcode == 7'b0000011);

   /* always @(*) begin
     // 默认值
    csr_addr = 12'b0;
    csr_wdata = 32'b0;
    csr_wen = 1'b0;

    csr_addr1 = 12'b0;
    csr_wdata1 = 32'b0;
    csr_wen1 = 1'b0;

    csr_addr2 = 12'b0;
    csr_wdata2 = 32'b0;
    csr_wen2 = 1'b0;

    csr_addr3 = 12'b0;
    csr_wdata3 = 32'b0;
    csr_wen3 = 1'b0;
mstatus_new = mstatus; // 为 mstatus_new 赋予默认值，避免锁存器

            if (is_ecall) begin//csr csr csr cssr csr
      
      // 设置mepc
      csr_addr2 = 12'h341;            // MEPC 地址
      csr_wdata2 = pc;                 // 当前 PC
      csr_wen2 = 1;                    // 使能写入

      // 写入 mcause
      
      csr_addr1 = 12'h342;              // MCAUSE 地址
      csr_wdata1 = 32'd17;        // ECALL 的原因码（根据需求调整）
      csr_wen1 = 1;                      // 使能写入
       
           end   else if (is_mret) begin
            // 处理 MRET
            // 直接访问 mstatus 寄存器，并根据逻辑修改 mstatus_new
          
            if ((mstatus_new & 32'h80) != 0) begin
                mstatus_new = mstatus_new | 32'h8;    // 设置 MPIE 位（位 3）
            end 
            else begin
                mstatus_new = mstatus_new & 32'hFFFFFFF7; // 清除 MPIE 位（位 3）
            end

            mstatus_new = mstatus_new | 32'h80;       // 设置 MIE 位（位 7）
            mstatus_new = mstatus_new & 32'hFFFFE7FF; // 根据掩码清除特定位

            // 将修改后的 mstatus 写回 CSR
            csr_addr3 = 12'h300;
            csr_wdata3 = mstatus_new;
            csr_wen3   = 1'b1; // 启用写入
        end
    
    end*/





  
  always @(posedge clk) begin// 更新 PC
      
    if (rst) begin
      pc <= 32'h80000000;
      ebreak_flag <= 0;
    end 
else begin 
          //csr_wen1 <= 1'b0;
        //csr_wen2 <= 1'b0;

     if (inst == 32'h00100073) begin  // ebreak 指令
      ebreak_flag <= 1;
      exit_code <= regfile.rf[10];  // 获取 a0 寄存器的值
      ebreak(regfile.rf[10]);       // 调用 DPI-C 函数
    end 


       /* else if (is_ecall) begin//csr csr csr cssr csr
      pc <= mtvec;
      // 设置mepc
     // csr_addr2 <= 12'h341;            // MEPC 地址
     // csr_wdata2 <= pc;                 // 当前 PC
     // csr_wen2 <= 1;                    // 使能写入

      // 写入 mcause
     // csr_addr1 <= 12'h342;              // MCAUSE 地址
     // csr_wdata1 <= 32'd17;        // ECALL 的原因码（根据需求调整）
     // csr_wen1 <= 1;                      // 使能写入
       
    end
    else if (is_mret) begin
      pc <= mepc;
    end//csr csr csr csr csr csr csr





   else if (pc_valid && pc_ready) begin  // 普通指令
                pc <= next_pc;
            end

    //$display("At time %t: NPC after update-pc PC = 0x%08x", $time, pc);*/
end
  end
      always @(posedge clk) begin
        if (rst) begin
            pc <= 32'h80000000;
            pc_ready <= 1;
        end else if (pc_valid && pc_ready) begin
            // 握手成功，更新PC并拉低ready
            pc <= next_pc;
            pc_ready <= 0;  // 更新过程中拉低ready
        end else if (!pc_ready) begin
            // 更新已完成，重新拉高ready
            pc_ready <= 1;
        end
    end
endmodule

