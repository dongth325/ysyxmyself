module ysyx_24090012_IFU (
    input  wire         clock,
    input  wire         reset,
    
    // Control Interface
    input  wire         if_allow_in,    // 允许取指信号
    input  wire [31:0]  if_next_pc,     // 外部传入的下一条指令地址
    
    // IDU Interface
    input  wire         idu_ready,      // IDU准备好接收新指令
    output reg         idu_valid,      // 指令有效信号
    output reg [31:0]  idu_pc,         // 当前指令PC
    output reg [31:0]  idu_inst,       // 当前指令

    // AXI4 Interface for MROM
    input  wire         io_master_arready,
    output reg         io_master_arvalid,
    output wire [31:0]  io_master_araddr,
    output wire [3:0]   io_master_arid,
    output wire [7:0]   io_master_arlen,
    output wire [2:0]   io_master_arsize,
    output wire [1:0]   io_master_arburst,
    
    output reg [1:0] state_out,

    input  wire         io_master_rvalid,
    input  wire [31:0]  io_master_rdata,
    input  wire [3:0]   io_master_rid,
    input  wire         io_master_rlast,//暂时不用
    input  wire [1:0]   io_master_rresp,//暂时不用
    output reg         io_master_rready
);


    // icache配置参数
localparam CACHE_LINES = 16;                // 缓存块数量
localparam INDEX_BITS = 4;                  // 索引位数 (2^4 = 16)
localparam OFFSET_BITS = 2;                 // 偏移位数 (4B块大小)
localparam TAG_BITS = 32 - INDEX_BITS - OFFSET_BITS; // 标签位数

// 状态定义 - 简化的三状态机
localparam IDLE        = 2'b00;  // 空闲状态
localparam CHECK_CACHE = 2'b01;  // 第1步：检查缓存是否命中
localparam FETCH_ADDR  = 2'b10;  // 第2-3步：发起总线请求取数据
localparam FETCH_DATA  = 2'b11;  // 第4-5步：接收数据并响应







    // 寄存器定义
    reg [1:0] state;
    reg [1:0] next_state;
    reg [31:0] saved_pc;    // 锁存的PC
    reg [3:0]  curr_id;     // 当前事务ID

    reg [31:0] ifu_count;  // IFU取指计数器
    reg [31:0] hit_count;   // 缓存命中计数
    reg [31:0] miss_count;  // 缓存未命中计数

    reg [TAG_BITS-1:0] cache_tags [0:CACHE_LINES-1];  // 标签数组
    reg cache_valid [0:CACHE_LINES-1];                // 有效位数组
    reg [31:0] cache_data [0:CACHE_LINES-1];          // 数据数组

      // 地址解析
    wire [TAG_BITS-1:0] req_tag = saved_pc[31:INDEX_BITS+OFFSET_BITS];
    wire [INDEX_BITS-1:0] req_index = saved_pc[INDEX_BITS+OFFSET_BITS-1:OFFSET_BITS];
    wire [OFFSET_BITS-1:0] req_offset = saved_pc[OFFSET_BITS-1:0]; // 对于指令总是为0
    
    // 缓存命中判断
    wire cache_hit = cache_valid[req_index] && (cache_tags[req_index] == req_tag);

    // 时序逻辑：仅更新状态和锁存数据
always @(posedge clock) begin
    

   /* if(state == FETCH_DATA && next_state == IDLE) begin
        ifu_count <= ifu_count + 32'h1;//ifu指令计数器++
    end*/

         // 完成一次取指
    if ((state == CHECK_CACHE && cache_hit && next_state == IDLE) || 
    (state == FETCH_DATA && io_master_rvalid && io_master_rready && next_state == IDLE)) begin
    ifu_count <= ifu_count + 32'h1;
end
end



    always @(posedge clock) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;
            saved_pc <= 32'h0;
            ifu_count <= 32'h0;
            hit_count <= 32'h0;
            miss_count <= 32'h0;


            for (integer i = 0; i < CACHE_LINES; i = i + 1) begin
                cache_valid[i] <= 1'b0;
                cache_tags[i] <= {TAG_BITS{1'b0}};
                cache_data[i] <= 32'h0;
            end
        end
        
        else begin


            state <= next_state;
            
                       // 当进入CHECK_CACHE状态时，锁存PC
            if (state == IDLE && next_state == CHECK_CACHE) begin
                saved_pc <= if_next_pc;
            end
            
            // 当请求发送时更新事务ID
            if (state == CHECK_CACHE && next_state == FETCH_ADDR) begin
                curr_id <= curr_id + 4'h1;
            end

            // 计数器更新
            if (state == CHECK_CACHE) begin
                if (cache_hit) begin
                    hit_count <= hit_count + 32'h1;
                end else begin
                    miss_count <= miss_count + 32'h1;
                end
            end
            


              // 在FETCH_DATA状态更新缓存
            if (state == FETCH_DATA && io_master_rvalid && io_master_rready) begin
                cache_tags[req_index] <= req_tag;
                cache_valid[req_index] <= 1'b1;
                cache_data[req_index] <= io_master_rdata;
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
        idu_pc = saved_pc;//当前pc
        idu_inst = 32'h0;//在后面赋值
        state_out = state;
        case (state)
            IDLE: begin
                if (if_allow_in) begin
                    next_state = CHECK_CACHE;
                end
            end
            
            CHECK_CACHE: begin
                if (cache_hit) begin
                    // 缓存命中，直接响应
                    idu_valid = 1'b1;
                    idu_inst = cache_data[req_index];
                    
                    if (idu_ready) begin
                        next_state = IDLE;
                    end
                end else begin
                    // 缓存未命中，发起内存访问
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

               
                    idu_inst = io_master_rdata;
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
  




    export "DPI-C" function get_ifu_count;

    export "DPI-C" function get_hit_count;
    export "DPI-C" function get_miss_count;

    // DPI-C函数实现
    function int get_ifu_count();
        return ifu_count;
    endfunction   //综合需要注释

    function int get_hit_count();
    return hit_count;
    endfunction

    function int get_miss_count();
    return miss_count;
    endfunction

endmodule 