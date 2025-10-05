module ysyx_24090012(
    input         clock,          // 综合需要改成clk
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



  assign io_slave_awready = 1'b0;
  assign io_slave_wready = 1'b0;
  assign io_slave_bvalid = 1'b0;
  assign io_slave_bresp = 2'b00;
  assign io_slave_bid = 4'b0;
  assign io_slave_arready = 1'b0;
  assign io_slave_rvalid = 1'b0;
  assign io_slave_rresp = 2'b00;
  assign io_slave_rdata = 32'b0;
  assign io_slave_rlast = 1'b0;
  assign io_slave_rid = 4'b0;



  wire [4:0] rs1, rs2, rd;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [6:0] func7;
  wire [31:0] imm;
  wire [5:0] alu_op;

  wire [31:0] rs1_data, rs2_data, result, next_pc;
  wire wen;
  wire [31:0] inst;

  wire [31:0] pc;

  wire [4:0] wbu_rd;
  wire wbu_rd_wen;
  wire [31:0] wbu_data;
  wire wbu_valid;
  wire wbu_ready;
  wire [31:0] wbu_next_pc;

  wire [11:0] wbu_csr_addr;
  wire [31:0] wbu_csr_wdata;
  wire wbu_csr_wen;

  wire wbu_csr_valid;
  wire wbu_csr_ready;

 wire control_hazard;
 wire [31:0] branch_target_pc;

  wire out_is_ecall;
  wire out_is_mret;


  wire [31:0] rs1_data_out;
  wire [31:0] rs2_data_out;


wire instr_completed;

  wire [31:0] exu_out_pc;
  wire [31:0] lsu_out_pc;

  wire [31:0] idu_to_exu_inst;
  wire [31:0] exu_to_lsu_inst;
  wire [31:0] lsu_to_wbu_inst;
   wire ifu_to_idu_valid;   // IFU向IDU发出的有效信号
   wire idu_to_ifu_ready;
/* verilator lint_off UNOPTFLAT */
   wire idu_to_exu_valid;  // IDU向EXU发出的有效信号
/* verilator lint_on UNOPTFLAT */
   wire exu_to_idu_ready;  // EXU向IDU发出的就绪信号

   wire is_use_lsu;
   wire [4:0] rd_addr_out;
   wire rd_wen_out;

    wire idu_state;  // IDU状态信号
    wire [1:0] exu_state;  // EXU状态信号
    wire [2:0] ifu_state;  // IFU状态信号
    wire [2:0] lsu_state;

    wire [31:0] sim_lsu_addr;



    wire [31:0] data_hazard_exu_inst;
    wire [31:0] data_hazard_lsu_inst;
    wire [31:0] data_hazard_wbu_inst;
   

    // PC更新接口
  // wire if_allow_in = !reset && wbu_ready && idu_state == 1'b0 && exu_state == 2'b00 && ifu_state == 2'b00  && lsu_state == 3'b00;
    wire if_allow_in = 1;  //流水线可以一直取指令

// 使用组合逻辑(wire)实现mem_unsigned
wire mem_unsigned;//将idu解码信息进行判断，传给lsu用于无符号读取指令的逻辑处理




   



    wire [31:0] ifu_to_idu_pc;    // IFU传给IDU的PC
    wire [31:0] idu_to_exu_pc;    // IDU传给EXU的PC
 



        // LSU接口
    wire [31:0] mem_addr;
     // verilator lint_off UNOPTFLAT
    wire        mem_valid;
    // verilator lint_on UNOPTFLAT
    wire [31:0] mem_wdata;
    wire [3:0]  mem_wmask;
    wire        mem_wen;
    // verilator lint_off UNOPTFLAT
    wire        mem_ready;
    // verilator lint_on UNOPTFLAT

    wire [2:0]  mem_arsize;
    wire [2:0]  mem_awsize;


 

wire [63:0] ifu_to_idu_num;//流水线下传
wire [63:0] idu_to_exu_num;
wire [63:0] exu_to_lsu_num;
wire [63:0] lsu_to_wbu_num;
wire [63:0] wbu_back_to_idu_num;


wire [63:0] wbu_reg_num;//冒险上传
wire [63:0] exu_reg_num;
wire [63:0] lsu_reg_num;

wire [31:0] wbu_hazard_result;//冒险上传
wire [31:0] exu_hazard_result;
wire [31:0] lsu_hazard_result;

 
    wire [31:0] rd_data;

    wire        rd_wen;



wire [11:0] out_csr_addr;
wire out_csr_wen;

wire [11:0] csr_addr;
wire [31:0] csr_wdata;

wire csr_wen;



wire is_ecall;
wire is_mret;
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
// verilator lint_off UNOPTFLAT
wire        lsu_rvalid;
// verilator lint_on UNOPTFLAT

// verilator lint_off UNOPTFLAT
wire [1:0]  lsu_rresp;
// verilator lint_on UNOPTFLAT
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










// CLINT地址范围定义
localparam CLINT_BASE = 32'ha000_0000;
localparam CLINT_SIZE = 32'h0001_0000;  // 64KB空间

// 从arbiter获取的原始arvalid信号
wire        arbiter_arvalid;
wire [31:0] arbiter_araddr;
wire [3:0]  arbiter_arid;
wire [7:0]  arbiter_arlen;
wire [2:0]  arbiter_arsize;
wire [1:0]  arbiter_arburst;
wire        arbiter_rready;

// 判断地址是否在CLINT范围内
wire is_clint_addr = (io_master_araddr >= CLINT_BASE) && (io_master_araddr < CLINT_BASE + CLINT_SIZE);

// 判断是否访问CLINT - 只处理读请求
wire is_clint_read = arbiter_arvalid && is_clint_addr;

// CLINT AXI4-Lite接口信号
wire        clint_arvalid;
wire        clint_arready;
wire [31:0] clint_araddr;
wire        clint_rvalid;
wire        clint_rready;
wire [31:0] clint_rdata;
wire [1:0]  clint_rresp;

// 连接CLINT接口
assign clint_arvalid = arbiter_arvalid && is_clint_addr;
assign clint_araddr = io_master_araddr;
assign clint_rready = io_master_rready;

// 连接到外部设备的信号
assign io_master_arvalid = arbiter_arvalid && !is_clint_addr;//如果不是clint地址，就不发送到外部，不确定这一个信号能否全部阻塞
assign io_master_araddr = arbiter_araddr;
assign io_master_arid = arbiter_arid;
assign io_master_arlen = arbiter_arlen;
assign io_master_arsize = arbiter_arsize;
assign io_master_arburst = arbiter_arburst;
assign io_master_rready = arbiter_rready;

// 返回给arbiter的信号
// verilator lint_off UNOPTFLAT
wire        arbiter_arready = is_clint_addr ? clint_arready : io_master_arready;
// verilator lint_on UNOPTFLAT
wire        arbiter_rvalid = is_clint_addr ? clint_rvalid : io_master_rvalid;
wire [1:0]  arbiter_rresp = is_clint_addr ? clint_rresp : io_master_rresp;
wire [31:0] arbiter_rdata = is_clint_addr ? clint_rdata : io_master_rdata;
wire        arbiter_rlast = is_clint_addr ? 1'b1 : io_master_rlast;  //对于clint直接返回1
wire [3:0]  arbiter_rid = is_clint_addr ? arbiter_arid : io_master_rid;  // 对于CLINT，使用请求ID作为响应ID
//id原路返回，不确定实现流水线后是否正确

ysyx_24090012_CLINT clint_inst (
    .clk           (clock),
    .rst           (reset),
    .s_axi_arvalid (clint_arvalid),
    .s_axi_arready (clint_arready),
    .s_axi_araddr  (clint_araddr),
    .s_axi_rvalid  (clint_rvalid),
    .s_axi_rready  (clint_rready),
    .s_axi_rdata   (clint_rdata),
    .s_axi_rresp   (clint_rresp)
);


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
   // .io_master_arvalid(io_master_arvalid),
   // .io_master_arready(io_master_arready),
  //  .io_master_araddr(io_master_araddr),
 //  .io_master_arid(io_master_arid),
   // .io_master_arlen(io_master_arlen),
   // .io_master_arsize(io_master_arsize),
   // .io_master_arburst(io_master_arburst),
  //  .io_master_rready(io_master_rready),
   // .io_master_rvalid(io_master_rvalid),
   // .io_master_rresp(io_master_rresp),
   // .io_master_rdata(io_master_rdata),
    //.io_master_rlast(io_master_rlast),
    //.io_master_rid(io_master_rid)
    .io_master_arvalid(arbiter_arvalid),
    .io_master_arready(arbiter_arready),
    .io_master_araddr(arbiter_araddr),
    .io_master_arid(arbiter_arid),
    .io_master_arlen(arbiter_arlen),
    .io_master_arsize(arbiter_arsize),
    .io_master_arburst(arbiter_arburst),
    .io_master_rready(arbiter_rready),
    .io_master_rvalid(arbiter_rvalid),
    .io_master_rresp(arbiter_rresp),
    .io_master_rdata(arbiter_rdata),
    .io_master_rlast(arbiter_rlast),
    .io_master_rid(arbiter_rid)
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

    .control_hazard(control_hazard),
    .branch_target_pc(branch_target_pc),

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
    .io_master_rready(ifu_rready),
    .num(ifu_to_idu_num)
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
    .rs1_data(rs1_data),
    .rs2_data(rs2_data),


    .data_hazard_exu_inst(data_hazard_exu_inst),
    .data_hazard_lsu_inst(data_hazard_lsu_inst),
    .data_hazard_wbu_inst(data_hazard_wbu_inst),


    .exu_hazard_result(exu_hazard_result),
    .lsu_hazard_result(lsu_hazard_result),
    .wbu_hazard_result(wbu_hazard_result),
    // EXU Interface
    .exu_ready(exu_to_idu_ready),    // input: EXU是否准备好接收新指令
    .exu_valid(idu_to_exu_valid),    // output: 向EXU提供的指令是否有效
    
    .csr_addr(csr_addr),
   
    .rs1_data_out(rs1_data_out),
    .rs2_data_out(rs2_data_out),
    .wbu_reg_num(wbu_reg_num),
    .lsu_reg_num(lsu_reg_num),
    .exu_reg_num(exu_reg_num),

    .exu_next_pc(next_pc),
    .control_hazard(control_hazard),
    .branch_target_pc(branch_target_pc),
    // Instruction Information
    .inst(inst),              // input: 指令

    .idu_to_exu_inst(idu_to_exu_inst),
    
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
    .rd_wen(rd_wen),      // output
    .num(ifu_to_idu_num),
    .num_r(idu_to_exu_num),
    .wbu_num(wbu_back_to_idu_num)
  
);
  ysyx_24090012_RegisterFile regfile(

    .lsu_to_wbu_inst(lsu_to_wbu_inst),
    .next_pc(wbu_next_pc),
    .clock(clock),
    .pc(pc),
    .reset(reset),
    .raddr1(rs1),
    .raddr2(rs2),
    //.waddr(wbu_rd),
    .wdata(wbu_data),
   // .wen(wbu_rd_wen),
          .rd_valid(wbu_valid),
        .rd_ready(wbu_ready),


        .wbu_hazard_result(wbu_hazard_result),

        .data_hazard_wbu_inst(data_hazard_wbu_inst),

        .wbu_reg_num(wbu_reg_num),
   
    .sim_lsu_addr(sim_lsu_addr),
   

    .rdata1(rs1_data),
    .rdata2(rs2_data),
    .num(lsu_to_wbu_num),
    .wbu_back_to_idu_num(wbu_back_to_idu_num),
    .instr_completed(instr_completed)
    
    );





  
  ysyx_24090012_EXU exu(
    .rst(reset),
    .clk(clock),

  .pc(idu_to_exu_pc),
  .rs1_data(rs1_data_out),
  .rs2_data(rs2_data_out),  // 添加 rs2_data 连接
  .imm(imm),

  .out_pc(exu_out_pc),
  .alu_op(alu_op),
   .state_out(exu_state),

   .exu_reg_num(exu_reg_num),

   .exu_hazard_result(exu_hazard_result),

   .data_hazard_exu_inst(data_hazard_exu_inst),

 //  .is_use_lsu(is_use_lsu),

  .idu_valid(idu_to_exu_valid),
  .idu_ready(exu_to_idu_ready),

  .idu_to_exu_inst(idu_to_exu_inst),
  .exu_to_lsu_inst(exu_to_lsu_inst),
          // LSU接口
        .mem_addr(mem_addr),
        .mem_valid(mem_valid),
        .mem_wdata(mem_wdata),
      
       
        .mem_ready(mem_ready),
      
   
                // RegisterFile写回接口
       
        .rd_data(rd_data),

       

 
        // PC更新接口
       

  
    .mtvec(mtvec),
   
    .mepc(mepc),

   

  
  .next_pc(next_pc),
   .csr_rdata(csr_rdata),

   .csr_addr(csr_addr),
   .csr_wen(csr_wen),

    .csr_wdata(csr_wdata),
   
    .out_csr_addr(out_csr_addr),
    .out_csr_wen(out_csr_wen),
     
   

      .num(idu_to_exu_num),
      .num_r(exu_to_lsu_num)
       
);




   ysyx_24090012_CSR csr(
  
  .wbu_csr_valid(wbu_csr_valid),
  .wbu_csr_ready(wbu_csr_ready),
  .pc(lsu_out_pc),
  .clk(clock),
  .rst(reset),
  .csr_addr(csr_addr),

  .csr_wdata(wbu_csr_wdata),
 
  .lsu_to_wbu_inst(lsu_to_wbu_inst),
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
     .next_pc(next_pc),
   // .mem_unsigned(mem_unsigned),  // 无符号处理flag 
    .state_out(lsu_state),
    // EXU Interface
    .mem_addr(mem_addr),
    .mem_valid(mem_valid),
    .mem_wdata(mem_wdata),

    .lsu_hazard_result(lsu_hazard_result),



    .lsu_reg_num(lsu_reg_num),
  


    .data_hazard_lsu_inst(data_hazard_lsu_inst),
  //  .mem_wen(mem_wen),
    .mem_ready(mem_ready),

    .lsu_in_pc(exu_out_pc),
    .lsu_out_pc(lsu_out_pc),

   // .mem_arsize(mem_arsize),
   // .mem_awsize(mem_awsize),

    //.is_ecall(is_ecall),
   // .is_mret(is_mret),
   // .out_is_ecall(out_is_ecall),
   // .out_is_mret(out_is_mret),
   
   // .mem_rd(rd_addr_out),
   // .mem_rd_wen(rd_wen_out),
    .mem_result(rd_data),
   // .is_use_lsu(is_use_lsu),

    //.wbu_rd(wbu_rd),
    //.wbu_rd_wen(wbu_rd_wen),
    .wbu_data(wbu_data),

    .wbu_valid(wbu_valid),
    .wbu_ready(wbu_ready),
    .wbu_next_pc(wbu_next_pc),

    .num(exu_to_lsu_num),
    .num_r(lsu_to_wbu_num),

    //.csr_addr(out_csr_addr),
    .csr_wdata(csr_wdata),
   // .csr_wen(out_csr_wen),

    .exu_to_lsu_inst(exu_to_lsu_inst),
    .lsu_to_wbu_inst(lsu_to_wbu_inst),

   // .wbu_csr_addr(wbu_csr_addr),
    .wbu_csr_wdata(wbu_csr_wdata),
   // .wbu_csr_wen(wbu_csr_wen),

    .wbu_csr_valid(wbu_csr_valid),
    .wbu_csr_ready(wbu_csr_ready),

    .sim_lsu_addr(sim_lsu_addr),

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


    always @(posedge clock) begin// 更新 PC
      if (inst == 32'h00100073 && ifu_to_idu_valid == 1) begin  // ebreak 指令  用于没有cache的ifu，如果不加这个判断会在bootloader取到ebreak就会停止仿真
            $display("pc = 0x%08x from NPC", pc);
            $display("inst = 0x%08x from NPC",inst);
            $display("HIT GOOD TRAP");
         // ebreak(regfile.rf[10]);       // 调用 DPI-C 函数     综合需要注释
        end 
      end





endmodule
