module ysyx_24090012_IFU (
    input  wire         clock,
    input  wire         reset,
    
    // Control Interface
    input  wire         if_allow_in,    // 允许取指信号
    input  wire [31:0]  if_next_pc,     // 外部传入的下一条指令地址  //if next pc(真实pc用不到了)

    input control_hazard,
    input [31:0] branch_target_pc,
    
    // IDU Interface
    input  wire         idu_ready,      // IDU准备好接收新指令
    output reg         idu_valid,      // 指令有效信号
    output reg [31:0]  idu_pc,         // 当前指令PC
    output reg [31:0]  idu_inst,       // 当前指令

    // AXI4 Interface for MROM
    input  wire         io_master_arready,
    output          io_master_arvalid,
    output wire [31:0]  io_master_araddr,
    output wire [3:0]   io_master_arid,
    output wire [7:0]   io_master_arlen,
    output wire [2:0]   io_master_arsize,
    output wire [1:0]   io_master_arburst,
    
    output reg [2:0] state_out,

    input  wire         io_master_rvalid,
    input  wire [31:0]  io_master_rdata,
    input  wire [3:0]   io_master_rid,
    input  wire         io_master_rlast,//暂时不用
    input  wire [1:0]   io_master_rresp,//暂时不用
    output          io_master_rready,
    output reg  [63:0]  num
);

localparam FENCE_I_INST = 32'h0000100F;  // fence.i 指令编码

    // icache配置参数

//原来的23100面积
localparam CACHE_LINES = 2;                // 缓存块数量
localparam INDEX_BITS = 1;                  // 索引位数 (2^4 = 16)


//localparam CACHE_LINES = 1048576;                // 缓存块数量
//localparam INDEX_BITS = 20;                  // 索引位数 (2^20 = 1048576)  这里是将icache扩大到可以可以容纳dummy所有指令触发缓存一致性问题

//localparam OFFSET_BITS = 2;                 // 偏移位数 (4B块大小)
localparam OFFSET_BITS = 4;                 // 突发传输icache
localparam TAG_BITS = 32 - INDEX_BITS - OFFSET_BITS; // 标签位数

// 状态定义 - 简化的三状态机
localparam IDLE        = 3'b000;  // 空闲状态
localparam CHECK_CACHE = 3'b001;  // 第1步：检查缓存是否命中
localparam FETCH_ADDR  = 3'b010;  // 第2-3步：发起总线请求取数据
localparam FETCH_DATA  = 3'b011;  // 第4-5步：接收数据并响应
localparam WAIT_IDU    = 3'b100;






    // 寄存器定义
    reg [2:0] state;
    reg [2:0] next_state;
    reg [31:0] saved_pc;    // 锁存的PC
    reg [3:0]  curr_id;     // 当前事务ID

    reg [31:0] ifu_count;  // IFU取指计数器
    reg [31:0] hit_count;   // 缓存命中计数
    reg [31:0] miss_count;  // 缓存未命中计数


    reg [1:0] burst_count;  // 突发传输计数器  突发传输icache
    reg [TAG_BITS-1:0] cache_tags [0:CACHE_LINES-1];  // 标签数组
    reg cache_valid [0:CACHE_LINES-1];                // 有效位数组
    //reg [31:0] cache_data [0:CACHE_LINES-1];          // 数据数组
    reg [127:0] cache_data [0:CACHE_LINES-1];   //突发传输icache
    // 添加临时缓存数据
reg [127:0] temp_cache_data;  // 临时数据寄存器用于累积突发传输数据   突发传输icache
wire [1:0] word_offset = saved_pc[3:2];  // 添加: 块内字偏移，用于选择正确的32位指令  突发传输icache

      // 地址解析
    wire [TAG_BITS-1:0] req_tag = saved_pc[31:INDEX_BITS+OFFSET_BITS];
    wire [INDEX_BITS-1:0] req_index = saved_pc[INDEX_BITS+OFFSET_BITS-1:OFFSET_BITS];
    wire [OFFSET_BITS-1:0] req_offset = saved_pc[OFFSET_BITS-1:0]; // 对于指令总是为0
    
    // 缓存命中判断
    wire cache_hit = cache_valid[req_index] && (cache_tags[req_index] == req_tag);





    always @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;
            saved_pc <= 32'h2FFFFFFC; // 初始PC值 是30000000 - 4.为了下面默认saved pc = saved pc +4初始值
            ifu_count <= 32'h0;
            hit_count <= 32'h0;
            miss_count <= 32'h0;
            num <= 64'h1;//必须为1,要不然前两条指令发生数据冒险的时候，idu中的num rr会和wbu num的默认值0相同，巧合的破解了数据冒险

            burst_count <= 2'b00;  // 初始化burst计数器   突发传输icache
            temp_cache_data <= 128'h0;  // 初始化临时数  突发传输icache

            for (integer i = 0; i < CACHE_LINES; i = i + 1) begin
                cache_valid[i] <= 1'b0;
                cache_tags[i] <= {TAG_BITS{1'b0}};
                cache_data[i] <= 128'h0;
            end
        end
        
        else begin

            if ((state == CHECK_CACHE && cache_hit && next_state == IDLE) || 
            (state == FETCH_DATA && io_master_rvalid && io_master_rready && next_state == IDLE)) begin
            ifu_count <= ifu_count + 32'h1;
            end


            state <= next_state;
            
                       // 当进入CHECK_CACHE状态时，锁存PC
            if (state == IDLE && next_state == CHECK_CACHE) begin

                if (control_hazard) begin  //控制冒险判断
                    saved_pc <= branch_target_pc;
                end
              else begin 
                // saved_pc <= if_next_pc; //if next pc(真实pc用不到了)

                saved_pc <= saved_pc + 4;

              end
            end
            
            // 当请求发送时更新事务ID
            if (state == CHECK_CACHE && next_state == FETCH_ADDR) begin
                curr_id <= curr_id + 4'h1;
            end

            // 计数器更新
            if (state == CHECK_CACHE) begin    //计数器在实现控制冒险之后会统计错误，因为取出错误的指令冲刷流水线后count记数不会减去
                if (cache_hit) begin
                    hit_count <= hit_count + 32'h1;
                   // $display("hit_count: %d", hit_count);
                end else begin
                    miss_count <= miss_count + 32'h1;
                   // $display("miss_count: %d", miss_count);
                end
            end
            
     // 在IDU握手成功时增加指令序列号
            if (idu_valid && idu_ready) begin
                num <= num + 64'h1;
            end

              // 在FETCH_DATA状态更新缓存
          /*  if (state == FETCH_DATA && io_master_rvalid && io_master_rready) begin
                cache_tags[req_index] <= req_tag;
                cache_valid[req_index] <= 1'b1;
                cache_data[req_index] <= io_master_rdata;
            end*/


            if (state == FETCH_DATA && io_master_rvalid && io_master_rready) begin
                case (burst_count)
                    2'b00: begin
                        temp_cache_data[31:0] <= io_master_rdata;
                        burst_count <= burst_count + 1;
                    end
                    2'b01: begin
                        temp_cache_data[63:32] <= io_master_rdata;
                        burst_count <= burst_count + 1;
                    end
                    2'b10: begin
                        temp_cache_data[95:64] <= io_master_rdata;
                        burst_count <= burst_count + 1;
                    end
                    2'b11: begin
                        // 最后一个传输，完成缓存更新
                        cache_tags[req_index] <= req_tag;
                        cache_valid[req_index] <= 1'b1;
                        cache_data[req_index] <= {io_master_rdata, temp_cache_data[95:0]};
                        burst_count <= 2'b00;  // 重置计数器
                    end
                endcase
            end

            if (state == CHECK_CACHE && cache_hit && idu_inst == FENCE_I_INST) begin
                for (integer i = 0; i < CACHE_LINES; i = i + 1) begin
                    cache_valid[i] <= 1'b0;  // 无效化所有缓存行
                end
            end else if (state == FETCH_DATA && io_master_rvalid && io_master_rready && io_master_rlast && idu_inst == FENCE_I_INST) begin
                for (integer i = 0; i < CACHE_LINES; i = i + 1) begin
                    cache_valid[i] <= 1'b0;  // 无效化所有缓存行
                end
            end

        end

        
        
    end


    assign io_master_arvalid = (state == FETCH_ADDR);
    assign io_master_rready = (state == FETCH_DATA);
    assign io_master_araddr =   {saved_pc[31:4], 4'b0000};

    // 组合逻辑：状态转换和所有输出信号生成
    always @(*) begin
        // 默认值
        next_state = state;
        //io_master_araddr =   {saved_pc[31:4], 4'b0000};
      //  io_master_arvalid = 1'b0;
       // io_master_rready = 1'b0;
        idu_valid = 1'b0;
        idu_pc = saved_pc;//当前pc
        idu_inst = 32'h0;//在后面赋值
        state_out = state;

        if (control_hazard) begin
            next_state = IDLE;
        end

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
                  //  idu_inst = cache_data[req_index];
                    case (word_offset)    //突发传输icache
                    2'b00: idu_inst = cache_data[req_index][31:0];
                    2'b01: idu_inst = cache_data[req_index][63:32];
                    2'b10: idu_inst = cache_data[req_index][95:64];
                    2'b11: idu_inst = cache_data[req_index][127:96];
                endcase   
                    
                    if (idu_ready) begin
                        next_state = IDLE;
                    end
                end else begin
                    // 缓存未命中，发起内存访问
                    next_state = FETCH_ADDR;
                end
            end


            FETCH_ADDR: begin
              //  io_master_arvalid = 1'b1;
               // io_master_araddr =   {saved_pc[31:4], 4'b0000};
                if (io_master_arready) begin
                    next_state = FETCH_DATA;
                end
            end
            
            FETCH_DATA: begin
              //  io_master_rready = 1'b1;
                if (io_master_rvalid && (io_master_rid == curr_id)) begin

                    if (io_master_rlast) begin
                        // 根据word_offset选择正确的指令
                        case (word_offset)
                            2'b00: idu_inst = temp_cache_data[31:0];
                            2'b01: idu_inst = temp_cache_data[63:32];
                            2'b10: idu_inst = temp_cache_data[95:64];
                            2'b11: idu_inst = io_master_rdata; // 最后一个word
                        endcase
                      
                        idu_valid = 1'b1;
                        if (idu_ready) begin
                            next_state = IDLE;
                        end else begin
                            next_state = WAIT_IDU;  // IDU未准备好，进入等待状态
                        end
                    end
                    end
            end

            WAIT_IDU: begin
                // 在此状态中，我们已经有了指令数据，只是在等IDU准备好
                idu_valid = 1'b1;
                
                // 根据缓存的数据提供指令
                case (word_offset)
                    2'b00: idu_inst = temp_cache_data[31:0];
                    2'b01: idu_inst = temp_cache_data[63:32];
                    2'b10: idu_inst = temp_cache_data[95:64];
                    2'b11: idu_inst = temp_cache_data[127:96]; // 使用已缓存的最后一个word
                endcase
                
                // 只有当IDU准备好时才回到IDLE
                if (idu_ready) begin
                    next_state = IDLE;
                end
            end
            
            default: begin
                next_state = IDLE;
            end
        endcase
    end

    // 其他输出信号直接赋值
    //assign io_master_araddr  = saved_pc;
    assign io_master_arid    = curr_id;
  //  assign io_master_arlen   = 8'b0;        // 单次传输
    assign io_master_arlen   = 8'd3;        // 4次传输(长度=传输次数-1)
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
