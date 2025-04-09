

module ysyx_24090012(
    input         clock,          // 改名：clk -> clock
    input         reset,          // 改名：rst -> reset
    input         io_interrupt,   // 外部中断信号，永0

    // AXI4 Master Interface
    input         io_master_awready,
    output        io_master_awvalid,
    output [31:0] io_master_awaddr,
    output [3:0]  io_master_awid,
    output [7:0]  io_master_awlen,
    output [2:0]  io_master_awsize,
    output [1:0]  io_master_awburst,
    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [3:0]  io_master_wstrb,
    output        io_master_wlast,
    output        io_master_bready,
    input         io_master_bvalid,
    input  [1:0]  io_master_bresp,
    input  [3:0]  io_master_bid,
    input         io_master_arready,
    output        io_master_arvalid,
    output [31:0] io_master_araddr,
    output [3:0]  io_master_arid,
    output [7:0]  io_master_arlen,
    output [2:0]  io_master_arsize,
    output [1:0]  io_master_arburst,
    output        io_master_rready,
    input         io_master_rvalid,
    input  [1:0]  io_master_rresp,
    input  [31:0] io_master_rdata,
    input         io_master_rlast,
    input  [3:0]  io_master_rid,

    // AXI4 Slave Interface
    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [31:0] io_slave_awaddr,
    input  [3:0]  io_slave_awid,
    input  [7:0]  io_slave_awlen,
    input  [2:0]  io_slave_awsize,
    input  [1:0]  io_slave_awburst,
    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [3:0]  io_slave_wstrb,
    input         io_slave_wlast,
    input         io_slave_bready,
    output        io_slave_bvalid,
    output [1:0]  io_slave_bresp,
    output [3:0]  io_slave_bid,
    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [31:0] io_slave_araddr,
    input  [3:0]  io_slave_arid,
    input  [7:0]  io_slave_arlen,
    input  [2:0]  io_slave_arsize,
    input  [1:0]  io_slave_arburst,
    input         io_slave_rready,
    output        io_slave_rvalid,
    output [1:0]  io_slave_rresp,
    output [31:0] io_slave_rdata,
    output        io_slave_rlast,
    output [3:0]  io_slave_rid
);
  import "DPI-C" context function void ebreak(input int exit_code);

  wire [4:0] rs1, rs2, rd;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [6:0] func7;
  wire [31:0] imm;
  wire [5:0] alu_op;
  wire [31:0] rs1_data, rs2_data, result, next_pc;
  wire wen;
  wire [31:0] inst;


   //wire idu_valid;//ifu to idu
   //wire idu_ready;//idu to ifu

   //wire        exu_valid;
   //wire        exu_ready;
   wire ifu_to_idu_valid;   // IFU向IDU发出的有效信号
   wire idu_to_ifu_ready;

   wire idu_to_exu_valid;  // IDU向EXU发出的有效信号
   wire exu_to_idu_ready;  // EXU向IDU发出的就绪信号

    wire idu_state;  // IDU状态信号
    wire [1:0] exu_state;  // EXU状态信号
    wire [1:0] ifu_state;  // IFU状态信号

   wire csr_rd_valid;
   wire csr_rd_ready;

    // PC更新接口
   wire if_allow_in = !reset && pc_ready && rd_ready && idu_state == 1'b0 && exu_state == 2'b00 && ifu_state == 2'b00;


// 使用组合逻辑(wire)实现mem_unsigned
wire mem_unsigned;//将idu解码信息进行判断，传给lsu用于无符号读取指令的逻辑处理

// 使用case语句为所有加载指令类型分配mem_unsigned值
assign mem_unsigned = (alu_op == 6'b011000) || // LBU (Load Byte Unsigned)
                      (alu_op == 6'b100000);   // LHU (Load Halfword Unsigned)
//将idu解码信息进行判断，传给lsu用于无符号读取指令的逻辑处理





    wire [31:0] ifu_to_idu_pc;    // IFU传给IDU的PC
    wire [31:0] idu_to_exu_pc;    // IDU传给EXU的PC
    reg  [31:0] pc;  
    wire        pc_valid;
    reg         pc_ready;


        // LSU接口
    wire [31:0] mem_addr;
    wire        mem_valid;
    wire [31:0] mem_wdata;
    wire [3:0]  mem_wmask;
    wire        mem_wen;
    wire        mem_ready;
    wire [31:0] mem_rdata;
    wire [2:0]  mem_arsize;
    wire [2:0]  mem_awsize;


 

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
/* verilator lint_off MULTIDRIVEN */
reg [11:0] csr_addr;
reg csr_wen;
/* verilator lint_on MULTIDRIVEN */
reg [31:0] csr_wdata;
reg [31:0] mstatus_new;//用于mret指令对mstatus寄存器访问取值后的保存............





wire is_ecall, is_mret;
wire [31:0] csr_rdata;
wire [31:0] mstatus;
wire [31:0] mtvec;
wire [31:0] mepc;
wire [31:0] mcause;
wire [31:0] mvendorid;
wire [31:0] marchid;
// LSU到arbiter的接口线
wire        lsu_awvalid;
wire        lsu_awready;
wire [31:0] lsu_awaddr;
wire [3:0]  lsu_awid;
wire [7:0]  lsu_awlen;
wire [2:0]  lsu_awsize;
wire [1:0]  lsu_awburst;
wire        lsu_wvalid;
wire        lsu_wready;
wire [31:0] lsu_wdata;
wire [3:0]  lsu_wstrb;
wire        lsu_wlast;
wire        lsu_bready;
wire        lsu_bvalid;
wire [1:0]  lsu_bresp;
wire [3:0]  lsu_bid;
wire        lsu_arvalid;
wire        lsu_arready;
wire [31:0] lsu_araddr;
wire [3:0]  lsu_arid;
wire [7:0]  lsu_arlen;
wire [2:0]  lsu_arsize;
wire [1:0]  lsu_arburst;
wire        lsu_rready;
wire        lsu_rvalid;
wire [1:0]  lsu_rresp;
wire [31:0] lsu_rdata;
wire        lsu_rlast;
wire [3:0]  lsu_rid;



// IFU到arbiter的接口线
wire        ifu_arvalid;
wire        ifu_arready;
wire [31:0] ifu_araddr;
wire [3:0]  ifu_arid;
wire [7:0]  ifu_arlen;
wire [2:0]  ifu_arsize;
wire [1:0]  ifu_arburst;
wire        ifu_rready;
wire        ifu_rvalid;
wire [1:0]  ifu_rresp;
wire [31:0] ifu_rdata;
wire        ifu_rlast;
wire [3:0]  ifu_rid;

// 实例化arbiter
ysyx_24090012_arbiter arbiter(
    .clk(clock),
    .rst(reset),

    // LSU Master Interface
    .lsu_awvalid(lsu_awvalid),
    .lsu_awready(lsu_awready),
    .lsu_awaddr(lsu_awaddr),
    .lsu_awid(lsu_awid),
    .lsu_awlen(lsu_awlen),
    .lsu_awsize(lsu_awsize),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid),
    .lsu_wready(lsu_wready),
    .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb),
    .lsu_wlast(lsu_wlast),
    .lsu_bready(lsu_bready),
    .lsu_bvalid(lsu_bvalid),
    .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid),
    .lsu_arvalid(lsu_arvalid),
    .lsu_arready(lsu_arready),
    .lsu_araddr(lsu_araddr),
    .lsu_arid(lsu_arid),
    .lsu_arlen(lsu_arlen),
    .lsu_arsize(lsu_arsize),
    .lsu_arburst(lsu_arburst),
    .lsu_rready(lsu_rready),
    .lsu_rvalid(lsu_rvalid),
    .lsu_rresp(lsu_rresp),
    .lsu_rdata(lsu_rdata),
    .lsu_rlast(lsu_rlast),
    .lsu_rid(lsu_rid),

        // IFU Master Interface
    .ifu_arvalid(ifu_arvalid),
    .ifu_arready(ifu_arready),
    .ifu_araddr(ifu_araddr),
    .ifu_arid(ifu_arid),
    .ifu_arlen(ifu_arlen),
    .ifu_arsize(ifu_arsize),
    .ifu_arburst(ifu_arburst),
    .ifu_rready(ifu_rready),
    .ifu_rvalid(ifu_rvalid),
    .ifu_rresp(ifu_rresp),
    .ifu_rdata(ifu_rdata),
    .ifu_rlast(ifu_rlast),
    .ifu_rid(ifu_rid),

    // AXI4 Slave Interface (to memory)
    .io_master_awvalid(io_master_awvalid),
    .io_master_awready(io_master_awready),
    .io_master_awaddr(io_master_awaddr),
    .io_master_awid(io_master_awid),
    .io_master_awlen(io_master_awlen),
    .io_master_awsize(io_master_awsize),
    .io_master_awburst(io_master_awburst),
    .io_master_wvalid(io_master_wvalid),
    .io_master_wready(io_master_wready),
    .io_master_wdata(io_master_wdata),
    .io_master_wstrb(io_master_wstrb),
    .io_master_wlast(io_master_wlast),
    .io_master_bready(io_master_bready),
    .io_master_bvalid(io_master_bvalid),
    .io_master_bresp(io_master_bresp),
    .io_master_bid(io_master_bid),
    .io_master_arvalid(io_master_arvalid),
    .io_master_arready(io_master_arready),
    .io_master_araddr(io_master_araddr),
    .io_master_arid(io_master_arid),
    .io_master_arlen(io_master_arlen),
    .io_master_arsize(io_master_arsize),
    .io_master_arburst(io_master_arburst),
    .io_master_rready(io_master_rready),
    .io_master_rvalid(io_master_rvalid),
    .io_master_rresp(io_master_rresp),
    .io_master_rdata(io_master_rdata),
    .io_master_rlast(io_master_rlast),
    .io_master_rid(io_master_rid)
);




  // 实例化各个模块
  ysyx_24090012_IFU ifu(
    .clock(clock),
    .reset(reset),
    .state_out(ifu_state),
        // Control Interface
    .if_allow_in(if_allow_in),    // 暂时设为常开
    .if_next_pc(pc),
    
    // IDU Interface
    .idu_ready(idu_to_ifu_ready),//与idu握手信号和信息传输
    .idu_valid(ifu_to_idu_valid),
    .idu_pc(ifu_to_idu_pc),
    .idu_inst(inst),

    // AXI4 Interface
    .io_master_arready(ifu_arready),
    .io_master_arvalid(ifu_arvalid),
    .io_master_araddr(ifu_araddr),
    .io_master_arid(ifu_arid),
    .io_master_arlen(ifu_arlen),
    .io_master_arsize(ifu_arsize),
    .io_master_arburst(ifu_arburst),
    .io_master_rvalid(ifu_rvalid),
    .io_master_rdata(ifu_rdata),
    .io_master_rid(ifu_rid),
    .io_master_rlast(ifu_rlast),
    .io_master_rresp(ifu_rresp),
    .io_master_rready(ifu_rready)
);
 // 修改IDU实例化
ysyx_24090012_IDU idu(
    .clock(clock),
    .reset(reset),
      .ifu_to_idu_pc(ifu_to_idu_pc),  // 从IFU来的PC
      .idu_to_exu_pc(idu_to_exu_pc),  // 输出到EXU的PC
    // IFU Interface
    .ifu_ready(idu_to_ifu_ready),    // output: 告诉IFU是否准备好接收新指令
    .ifu_valid(ifu_to_idu_valid),    // input: IFU提供的指令是否有效
    
    // EXU Interface
    .exu_ready(exu_to_idu_ready),    // input: EXU是否准备好接收新指令
    .exu_valid(idu_to_exu_valid),    // output: 向EXU提供的指令是否有效
    
    // Instruction Information
    .inst(inst),              // input: 指令
    
    .state_out(idu_state),  // 连接状态输出
    // Decoded Information
    .rs1(rs1),               // output
    .rs2(rs2),               // output
    .rd(rd),                 // output
    .imm(imm),               // output
    .opcode(opcode),         // output
    .func3(func3),           // output
    .func7(func7),           // output
    .alu_op(alu_op),         // output
    
    // CSR Related
    .csr_addr(csr_addr),     // output
    .csr_wen(csr_wen),       // output
    .is_ecall(is_ecall),     // output
    .is_mret(is_mret)        // output
);
  ysyx_24090012_RegisterFile regfile(
    .pc(pc),
    .clock(clock),
    
    .reset(reset),
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
    .rst(reset),
    .clk(clock),
  .pc(idu_to_exu_pc),
  .rs1_data(rs1_data),
  .rs2_data(rs2_data),  // 添加 rs2_data 连接
  .imm(imm),
  .alu_op(alu_op),
   .state_out(exu_state),

  .idu_valid(idu_to_exu_valid),
  .idu_ready(exu_to_idu_ready),
          // LSU接口
        .mem_addr(mem_addr),
        .mem_valid(mem_valid),
        .mem_wdata(mem_wdata),
        .mem_wmask(mem_wmask),
        .mem_wen(mem_wen),
        .mem_ready(mem_ready),
        .mem_rdata(mem_rdata),
        .mem_arsize(mem_arsize),
        .mem_awsize(mem_awsize),

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
  .clk(clock),
  .rst(reset),
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
  .mcause(mcause),
  .mvendorid(mvendorid),
  .marchid(marchid)
);

    // 实例化LSU
    ysyx_24090012_LSU lsu(
    .clock(clock),
    .reset(reset),
     
    .mem_unsigned(mem_unsigned),  // 无符号处理flag 

    // EXU Interface
    .mem_addr(mem_addr),
    .mem_valid(mem_valid),
    .mem_wdata(mem_wdata),
    .mem_wmask(mem_wmask),
    .mem_wen(mem_wen),
    .mem_ready(mem_ready),
    .mem_rdata(mem_rdata),
    .mem_arsize(mem_arsize),
    .mem_awsize(mem_awsize),

    // AXI4 Interface
    .io_master_awready(lsu_awready),
    .io_master_awvalid(lsu_awvalid),
    .io_master_awaddr(lsu_awaddr),
    .io_master_awid(lsu_awid),
    .io_master_awlen(lsu_awlen),
    .io_master_awsize(lsu_awsize),
    .io_master_awburst(lsu_awburst),
    .io_master_wready(lsu_wready),
    .io_master_wvalid(lsu_wvalid),
    .io_master_wdata(lsu_wdata),
    .io_master_wstrb(lsu_wstrb),
    .io_master_wlast(lsu_wlast),
    .io_master_bready(lsu_bready),
    .io_master_bvalid(lsu_bvalid),
    .io_master_bresp(lsu_bresp),
    .io_master_bid(lsu_bid),
    .io_master_arready(lsu_arready),
    .io_master_arvalid(lsu_arvalid),
    .io_master_araddr(lsu_araddr),
    .io_master_arid(lsu_arid),
    .io_master_arlen(lsu_arlen),
    .io_master_arsize(lsu_arsize),
    .io_master_arburst(lsu_arburst),
    .io_master_rready(lsu_rready),
    .io_master_rvalid(lsu_rvalid),
    .io_master_rdata(lsu_rdata),
    .io_master_rresp(lsu_rresp),
    .io_master_rid(lsu_rid)
    );




   assign wen = (opcode == 7'b0010011 || opcode == 7'b0110111 || opcode == 7'b0010111 || opcode == 7'b1110011||
                opcode == 7'b1101111 || opcode == 7'b1100111 || opcode == 7'b0110011 || 
                 opcode == 7'b0000011);

 




  
  always @(posedge clock) begin// 更新 PC
      
    if (reset) begin
      pc <= 32'h3000_0000;
     
    end 
else begin 
        

     if (inst == 32'h00100073 && ifu_rvalid) begin  // ebreak 指令
        $display("pc = 0x%08x from NPC", pc);
        $display("inst = 0x%08x from NPC",inst);
      ebreak(regfile.rf[10]);       // 调用 DPI-C 函数
    end 







  /* else if (pc_valid && pc_ready) begin  // 普通指令
                pc <= next_pc;
            end*/

    //$display("At time %t: NPC after update-pc PC = 0x%08x", $time, pc);*/
end
  end
// 添加reset状态变化监控
always @(reset) begin
    $display("RESET CHANGED TO %d from NPC \n", reset);
end

      always @(posedge clock) begin
     //   $display("5555pc = %08x",pc);
      //  $display("6666next pc = %08x",next_pc);
      //  $display("7777pc valid = %08x",pc_valid);
      //  $display("8888pc ready = %08x",pc_ready);
      //  $display("9999 reset = %08x",reset);
        
        if (reset) begin
           $display("reset = %d ", reset);
            pc <= 32'h3000_0000;
            pc_ready <= 1;

        end else if (pc_valid && pc_ready) begin
            // 握手成功，更新PC并拉低ready
          //  $display("4444pc = %08x",next_pc);
            pc <= next_pc;
            pc_ready <= 0;  // 更新过程中拉低ready
          //  $display("9999pc = %08x",pc);
        end else if (!pc_ready) begin
            // 更新已完成，重新拉高ready
            pc_ready <= 1;
        end
    end


export "DPI-C"  function get_pc_value;

// 实现获取PC值的函数
function int get_pc_value();
  get_pc_value = pc; // 返回当前PC值
endfunction

export "DPI-C"  function get_if_allow_in;
function int get_if_allow_in();
  get_if_allow_in = {31'b0, if_allow_in}; // 返回if_allow_in信号
endfunction

endmodule

