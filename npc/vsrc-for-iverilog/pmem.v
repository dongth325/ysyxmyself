module pmem (
    input clk,
    input reset,

    // AXI 接口（从master视角命名，但pmem是slave：input master的valid/addr等，output ready/resp等）
    // Write Address Channel
    output reg   io_master_awready,  // out: slave ready
    input        io_master_awvalid,  // in: master valid
    input [31:0] io_master_awaddr,   // in
    input [3:0]  io_master_awid,     // in
    input [7:0]  io_master_awlen,    // in (假设=0)
    input [2:0]  io_master_awsize,   // in
    input [1:0]  io_master_awburst,  // in (忽略)

    // Write Data Channel
    output reg   io_master_wready,   // out
    input        io_master_wvalid,   // in
    input [31:0] io_master_wdata,    // in
    input [3:0]  io_master_wstrb,    // in
    input        io_master_wlast,    // in (假设=1)

    // Write Response Channel
    input        io_master_bready,   // in
    output reg   io_master_bvalid,   // out
    output reg [1:0] io_master_bresp,// out
    output reg [3:0] io_master_bid,  // out

    // Read Address Channel
    output reg   io_master_arready,  // out
    input        io_master_arvalid,  // in
    input [31:0] io_master_araddr,   // in
    input [3:0]  io_master_arid,     // in
    input [7:0]  io_master_arlen,    // in (假设=0)
    input [2:0]  io_master_arsize,   // in
    input [1:0]  io_master_arburst,  // in (忽略)

    // Read Data Channel
    input        io_master_rready,   // in
    output reg   io_master_rvalid,   // out
    output reg [31:0] io_master_rdata,// out
    output reg [1:0]  io_master_rresp,// out
    output reg        io_master_rlast,// out
    output reg [3:0]  io_master_rid   // out
);

parameter MEM_BASE = 32'h80000000;
parameter MEM_SIZE = 128 * 1024 * 1024 / 4;
reg [31:0] mem [0:MEM_SIZE-1];

// 状态reg (去除任何初始=0, 全移到initial)
reg [1:0] write_state;
reg [31:0] w_temp_addr;
reg [3:0] w_temp_id;

reg [1:0] read_state;
reg [31:0] r_temp_addr;
reg [3:0] r_temp_id;
reg [31:0] r_temp_data;

// 初始化块 (消除warning: explicit initial all to 0, 防X传播)
initial begin
    integer i;
    for (i = 0; i < MEM_SIZE; i = i + 1) begin
        mem[i] = 32'h0;  // Explicit 0 for mem
    end
    $readmemh("/home/dongtaiheng/desktopp/ffuck/ysyx-workbench/am-kernels/tests/cpu-tests/build/program.hex", mem);

    // 状态初始 (修复lines 94/130 warning)
    write_state = 0;
    w_temp_addr = 0;
    w_temp_id = 0;
    read_state = 0;
    r_temp_addr = 0;
    r_temp_id = 0;
    r_temp_data = 0;

    // ready/valid初始 (防X)
    io_master_awready = 1;
    io_master_wready = 1;
    io_master_bvalid = 0;
    io_master_arready = 1;
    io_master_rvalid = 0;
    io_master_rlast = 0;
end

// 写通道 always (不变, 焦点line ~78: case开始)
always @(posedge clk or posedge reset) begin
    if (reset) begin
        write_state <= 0;
        io_master_awready <= 1;
        io_master_wready <= 1;
        io_master_bvalid <= 0;
    end else begin
        case (write_state)
            0: if (io_master_awvalid) begin  // in: master valid
                w_temp_addr <= io_master_awaddr - MEM_BASE;
                w_temp_id <= io_master_awid;
                write_state <= 1;
                io_master_awready <= 0;  // out: busy
            end
            1: if (io_master_wvalid) begin  // in: master valid
                integer idx = w_temp_addr >> 2;
                if (io_master_wstrb[0]) mem[idx][7:0] <= io_master_wdata[7:0];
                if (io_master_wstrb[1]) mem[idx][15:8] <= io_master_wdata[15:8];
                if (io_master_wstrb[2]) mem[idx][23:16] <= io_master_wdata[23:16];
                if (io_master_wstrb[3]) mem[idx][31:24] <= io_master_wdata[31:24];
                write_state <= 2;
                io_master_wready <= 0;   // out: busy
                io_master_bvalid <= 1;   // out: valid
                io_master_bresp <= 2'b00;
                io_master_bid <= w_temp_id;
            end
            2: if (io_master_bready) begin  // in: master ready
                write_state <= 0;
                io_master_bvalid <= 0;
                io_master_awready <= 1;
                io_master_wready <= 1;
            end
        endcase
    end
end

// 读通道 always (不变)
always @(posedge clk or posedge reset) begin
    if (reset) begin
        read_state <= 0;
        io_master_arready <= 1;
        io_master_rvalid <= 0;
    end else begin
        case (read_state)
            0: if (io_master_arvalid) begin
                r_temp_addr <= io_master_araddr - MEM_BASE;
                r_temp_id <= io_master_arid;
                read_state <= 1;
                io_master_arready <= 0;
            end
            1: begin
                integer idx = r_temp_addr >> 2;
                r_temp_data <= mem[idx];
                read_state <= 2;
                io_master_rvalid <= 1;
                io_master_rdata <= mem[idx];
                io_master_rresp <= 2'b00;
                io_master_rlast <= 1'b1;
                io_master_rid <= r_temp_id;
            end
            2: if (io_master_rready) begin
                read_state <= 0;
                io_master_rvalid <= 0;
                io_master_arready <= 1;
            end
        endcase
    end
end

endmodule