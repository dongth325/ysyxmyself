module ysyx_24090012_IFU (
    input  wire         clock,
    input  wire         reset,
    
    // Control Interface
    input  wire         if_allow_in,    // 允许取指信号
    input  wire [31:0]  if_next_pc,     // 外部传入的下一条指令地址
    
    // IDU Interface
    input  wire         idu_ready,      // IDU准备好接收新指令
    output wire         idu_valid,      // 指令有效信号
    output wire [31:0]  idu_pc,         // 当前指令PC
    output wire [31:0]  idu_inst,       // 当前指令

    // AXI4 Interface for MROM
    input  wire         io_master_arready,
    output wire         io_master_arvalid,
    output wire [31:0]  io_master_araddr,
    output wire [3:0]   io_master_arid,
    output wire [7:0]   io_master_arlen,
    output wire [2:0]   io_master_arsize,
    output wire [1:0]   io_master_arburst,
    
    input  wire         io_master_rvalid,
    input  wire [31:0]  io_master_rdata,
    input  wire [3:0]   io_master_rid,
    input  wire         io_master_rlast,
    input  wire [1:0]   io_master_rresp,
    output wire         io_master_rready
);

    // 状态定义
    localparam IDLE       = 2'b00;
    localparam FETCH_ADDR = 2'b01;
    localparam FETCH_DATA = 2'b10;

    // 寄存器定义
    reg [1:0] state;
    reg [1:0] next_state;
    reg [31:0] saved_pc;    // 锁存的PC
    reg [3:0]  curr_id;     // 当前事务ID

    // 时序逻辑：仅更新状态和锁存数据
    always @(posedge clock) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;
            saved_pc <= 32'h0;
        end else begin
            state <= next_state;
            
            if (next_state == FETCH_ADDR) begin
                saved_pc <= if_next_pc;
                curr_id <= curr_id + 4'h1;
            end
        end
    end

    // 组合逻辑：状态转换和所有输出信号生成
    always @(*) begin
        // 默认值
        next_state = state;
        io_master_arvalid = 1'b0;
        io_master_rready = 1'b0;
        idu_valid = 1'b0;

        case (state)
            IDLE: begin
                if (if_allow_in) begin
                    next_state = FETCH_ADDR;
                end
            end
            
            FETCH_ADDR: begin
                io_master_arvalid = 1'b1;
                if (io_master_arready) begin
                    next_state = FETCH_DATA;
                end
            end
            
            FETCH_DATA: begin
                io_master_rready = 1'b1;
                if (io_master_rvalid && (io_master_rid == curr_id)) begin
                    idu_valid = 1'b1;
                    if (idu_ready) begin
                        next_state = IDLE;
                    end
                end
            end
            
            default: begin
                next_state = IDLE;
            end
        endcase
    end

    // 其他输出信号直接赋值
    assign io_master_araddr  = saved_pc;
    assign io_master_arid    = curr_id;
    assign io_master_arlen   = 8'b0;        // 单次传输
    assign io_master_arsize  = 3'b010;      // 4字节
    assign io_master_arburst = 2'b01;       // INCR模式
    assign idu_pc    = saved_pc;
    assign idu_inst  = io_master_rdata;

endmodule