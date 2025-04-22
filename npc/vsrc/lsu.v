module ysyx_24090012_LSU (
    input wire         clock,
    input wire         reset,
    
    input wire         mem_unsigned,


    // EXU Interface (slave)
    input  wire [31:0] mem_addr,
    input  wire        mem_valid,
    input  wire [31:0] mem_wdata,
    input  wire [3:0]  mem_wmask,
    input  wire        mem_wen,
    output reg         mem_ready,
    output reg  [31:0] mem_rdata,
    input  wire [2:0]  mem_awsize,
    input  wire [2:0]  mem_arsize,

    // AXI4 Master Interface
    // Write Address Channel
    input  wire        io_master_awready,
    output reg         io_master_awvalid,
    output reg  [31:0] io_master_awaddr,
    output reg  [3:0]  io_master_awid,     // 传递事务ID
    output reg  [7:0]  io_master_awlen,
    output reg  [2:0]  io_master_awsize,
    output reg  [1:0]  io_master_awburst,

    // Write Data Channel
    input  wire        io_master_wready,
    output reg         io_master_wvalid,
    output reg  [31:0] io_master_wdata,
    output reg  [3:0]  io_master_wstrb,
    output reg         io_master_wlast,     // 单次传输永远为1

    // Write Response Channel
    output reg         io_master_bready,
    input  wire        io_master_bvalid,
    input  wire [1:0]  io_master_bresp,    // 写响应状态
    input  wire [3:0]  io_master_bid,      // 写响应ID

    // Read Address Channel
    input  wire        io_master_arready,
    output reg         io_master_arvalid,
    output reg  [31:0] io_master_araddr,
    output reg  [3:0]  io_master_arid,     // 传递事务ID
    output reg  [7:0]  io_master_arlen,
    output reg  [2:0]  io_master_arsize,
    output reg  [1:0]  io_master_arburst,

    // Read Data Channel
    output reg         io_master_rready,
    input  wire        io_master_rvalid,
    input  wire [31:0] io_master_rdata,
    input  wire [1:0]  io_master_rresp,    // 读响应状态
    input  wire [3:0]  io_master_rid       // 读响应ID
);

    // 状态定义
    localparam IDLE        = 3'd0;
    localparam WRITE_ADDR  = 3'd1;
    localparam WRITE_DATA  = 3'd2;
    localparam WRITE_RESP  = 3'd3;
    localparam READ_ADDR   = 3'd4;
    localparam READ_DATA   = 3'd5;

    // 寄存器定义
    reg [2:0] state;
    reg [31:0] saved_addr;
    reg [31:0] saved_wdata;
    reg [3:0]  saved_wmask;
    reg [2:0]  saved_arsize;
    reg [2:0]  saved_awsize;
    reg [3:0]  curr_id;    // 当前事务ID
    reg saved_unsigned;

always @(posedge clock) begin
    // 写响应检测
    if (io_master_bresp != 2'b00) begin
        $display("LSU error! bid expected: %h, received: %h, bresp: %b", 
                curr_id, 
                io_master_bid, 
                io_master_bresp);
    end
    
    // 读响应检测
    if (io_master_rresp != 2'b00) begin
        $display("LSU read ID wrong! curr_id: %h, rid: %h, rresp: %b",
                curr_id,
                io_master_rid,
                io_master_rresp);
    end
end


    // 时序逻辑：状态更新和数据保存
    always @(posedge clock) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;
        end else begin
            // 在IDLE状态且有新请求时保存数据
            if (state == IDLE && mem_valid) begin
                saved_addr <= mem_addr;
                saved_wdata <= mem_wdata;
                saved_wmask <= mem_wmask;
                saved_arsize <= mem_arsize;
                saved_awsize <= mem_awsize;
                saved_unsigned <= mem_unsigned;
                curr_id <= curr_id + 4'h1;  // 递增事务ID
            end
            state <= next_state;
        end
    end

    // 组合逻辑：状态转换和控制信号生成
    reg [2:0] next_state;
    reg [31:0] processed_rdata;//用于对读出数据进行寄存，最后赋值给mem rdata
    always @(*) begin
        // 默认值
        next_state = state;
        io_master_awvalid = 0;
        io_master_wvalid  = 0;
        io_master_bready  = 0;
        io_master_arvalid = 0;
        io_master_rready  = 0;
        mem_ready = 0;
        mem_rdata = io_master_rdata;
        
        // 固定值
        io_master_awid    = curr_id;        // 使用当前事务ID
        io_master_awlen   = 8'd0;           // 单次传输
        io_master_awsize  = saved_awsize;  
            
        io_master_awburst = 2'b01;          // INCR模式
        io_master_arid    = curr_id;        // 使用当前事务ID
        io_master_arlen   = 8'd0;           // 单次传输
        io_master_arsize  = saved_arsize;  
       //io_master_arsize  = 1;       
        io_master_arburst = 2'b01;          // INCR模式
        
        // 地址和数据连接
        io_master_awaddr = saved_addr;
        io_master_araddr = saved_addr;
        io_master_wdata  = saved_wdata;
        //io_master_wstrb  = saved_wmask;
        io_master_wlast  = 1'b1;            // 单次传输永远为1
        
        // 状态转换和控制信号生成
        case (state)
            IDLE: begin
                if (mem_valid) begin
                    next_state = mem_wen ? WRITE_ADDR : READ_ADDR;
                end
            end
            
            WRITE_ADDR: begin
                io_master_awvalid = 1'b1;
                if (io_master_awready) begin
                    next_state = WRITE_DATA;
                end
            end
            
            WRITE_DATA: begin
                io_master_wvalid = 1'b1;
                if (io_master_wready) begin
                    next_state = WRITE_RESP;
                end
            end
            
                 WRITE_RESP: begin
                io_master_bready = 1'b1;
                if (io_master_bvalid) begin
                    // 检查响应和ID
                    if (io_master_bid == curr_id && io_master_bresp == 2'b00) begin
                    
                        
                        mem_ready = 1'b1;
                    end
                    next_state = IDLE;
                end
            end
            
            READ_ADDR: begin
                io_master_arvalid = 1'b1;
                if (io_master_arready) begin
                    next_state = READ_DATA;
                end
            end
            
            READ_DATA: begin
                io_master_rready = 1'b1;
                if (io_master_rvalid) begin
                    // 检查响应和ID
                    //if (io_master_rid == curr_id && io_master_rresp == 2'b00) begin
                     if (io_master_rresp == 2'b00) begin//在初始化串口发现id不匹配先不对比id
                        mem_ready = 1'b1;
                        
                        mem_rdata = processed_rdata; 
                       //$display("mem_rdata is %h from lsu.v line:197", mem_rdata);
                         
           
                    end
                    next_state = IDLE;
                end
                
            end
            
            default: next_state = IDLE;
        endcase
    end

always @(state) begin
//$display("state is %h from lsu line:213", state);
end

always @(processed_rdata) begin
 //$display("processed_rdata is %h from lsu.v line:217", processed_rdata);
end

always @(mem_rdata) begin
//$display("mem_rdata is %h from lsu.v line:212", mem_rdata);
//$display("state is %h from lsu.v line:212", state);
//$display("io_master_rresp is %h from lsu.v line:212", io_master_rresp);
//$display("io_master_rvalid is %h from lsu.v line:212", io_master_rvalid);

end




reg is_mrom_region;
reg is_uart_region;
always @(*) begin
    // 默认值
    processed_rdata = 32'b0;
        // 判断地址区间 - MROM区域通常在0x2000_0000开始
   
 is_mrom_region = (saved_addr[31:24] == 8'h20);
 is_uart_region = (saved_addr[31:24] == 8'h10);


    // 根据读操作类型处理数据
    case (saved_arsize)
        3'b000: begin // 字节访问 lb lbu
        if(is_mrom_region) begin


        processed_rdata = {{24{io_master_rdata[7]}}, io_master_rdata[7:0]};
        //$display("processed_rdata is %h from lsu.v line:236", processed_rdata);

        end
        else begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{24{io_master_rdata[7]}}, io_master_rdata[7:0]};
                2'b01: processed_rdata = {{24{io_master_rdata[15]}}, io_master_rdata[15:8]};
                2'b10: processed_rdata = {{24{io_master_rdata[23]}}, io_master_rdata[23:16]};
                2'b11: processed_rdata = {{24{io_master_rdata[31]}}, io_master_rdata[31:24]};
            endcase
           // $display("processed_rdata is %h from lsu.v line:246", processed_rdata);
           // $display("io_master_rid is %h from lsu.v line:246", io_master_rid);
          //  $display("io_master_rresp is %h from lsu.v line:246", io_master_rresp);
            //$display("curr_id is %h from lsu.v line:246", curr_id);
        end

        end
        3'b001: begin // 半字访问 lh lhu
        if(is_mrom_region) begin



        processed_rdata = {{16{io_master_rdata[15]}}, io_master_rdata[15:0]};


        end

        else begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{16{io_master_rdata[15]}}, io_master_rdata[15:0]};
                2'b10: processed_rdata = {{16{io_master_rdata[31]}}, io_master_rdata[31:16]};
                default: begin
                    processed_rdata = 32'b0;
                    $display("error!!!!! half word read is not aligned");
                end
            endcase
        end
        end
        3'b010: begin // 字访问 lw
        if(is_mrom_region) begin



        processed_rdata = io_master_rdata;

        end
        else begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = io_master_rdata;
                default: begin
                    processed_rdata = 32'b0;
                    $display("error!!!!! word read is not aligned");
                    $display("saved_addr is %h from lsu.v line:303", saved_addr);
                end
            endcase
        end
        end
        default: begin
            processed_rdata = 32'b0;
            $display("wrong!!!!! unknown read size");
        end
    endcase
end













/*always @(*) begin
    // 默认值
    processed_rdata = 32'b0;
        // 判断地址区间 - MROM区域通常在0x2000_0000开始
   
    // 根据读操作类型处理数据
    case (saved_arsize)
        3'b000: begin // 字节访问 lb lbu
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{24{io_master_rdata[7]}}, io_master_rdata[7:0]};
                2'b01: processed_rdata = {{24{io_master_rdata[15]}}, io_master_rdata[15:8]};
                2'b10: processed_rdata = {{24{io_master_rdata[23]}}, io_master_rdata[23:16]};
                2'b11: processed_rdata = {{24{io_master_rdata[31]}}, io_master_rdata[31:24]};
            endcase
        end
        3'b001: begin // 半字访问 lh lhu
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{16{io_master_rdata[15]}}, io_master_rdata[15:0]};
                2'b10: processed_rdata = {{16{io_master_rdata[31]}}, io_master_rdata[31:16]};
                default: begin
                    processed_rdata = 32'b0;
                    $display("error!!!!! half word read is not aligned");
                end
            endcase
        end
        3'b010: begin // 字访问 lw
            case (saved_addr[1:0])
                2'b00: processed_rdata = io_master_rdata;
                default: begin
                    processed_rdata = 32'b0;
                    $display("error!!!!! word read is not aligned");
                end
            endcase
        end
        default: begin
            processed_rdata = 32'b0;
            $display("wrong!!!!! unknown read size");
        end
    endcase
end*/







always @(*) begin
    // 默认值

  is_uart_region = (saved_addr[31:24] == 8'h10);
    io_master_wstrb = 4'b0000;
 //io_master_wstrb = 1;

    // 根据写操作的大小和地址计算 wstrb
    case (saved_awsize)
    3'b000: begin // 1 字节 sb
        if(is_uart_region) begin
           case (saved_addr[1:0])//sram write
            2'b00: begin
                io_master_wstrb = 4'b0001;
                io_master_wdata = {24'b0, saved_wdata[7:0]}; // 数据在低8位
            end
            2'b01: begin
                io_master_wstrb = 4'b0010;
                io_master_wdata = {16'b0, saved_wdata[7:0], 8'b0}; // 数据在8-15位
            end
            2'b10: begin
                io_master_wstrb = 4'b0100;
                io_master_wdata = {8'b0, saved_wdata[7:0], 16'b0}; // 数据在16-23位
            end
            2'b11: begin
                io_master_wstrb = 4'b1000;
                io_master_wdata = {saved_wdata[7:0], 24'b0}; // 数据在高8位
            end
        endcase
        end
        else begin
        case (saved_addr[1:0])//sram write
            2'b00: begin
                io_master_wstrb = 4'b0001;
                io_master_wdata = {24'b0, saved_wdata[7:0]}; // 数据在低8位
            end
            2'b01: begin
                io_master_wstrb = 4'b0010;
                io_master_wdata = {16'b0, saved_wdata[7:0], 8'b0}; // 数据在8-15位
            end
            2'b10: begin
                io_master_wstrb = 4'b0100;
                io_master_wdata = {8'b0, saved_wdata[7:0], 16'b0}; // 数据在16-23位
            end
            2'b11: begin
                io_master_wstrb = 4'b1000;
                io_master_wdata = {saved_wdata[7:0], 24'b0}; // 数据在高8位
            end
        endcase
    end
    end
3'b001: begin // 半字访问  sh
    if(is_uart_region) begin
       case (saved_addr[1:0])
        2'b00: begin

            io_master_wstrb = 4'b0011;  // 写入低两字节
            io_master_wdata = {16'b0, saved_wdata[15:0]}; // 数据保持低位
        end
        2'b10: begin
            io_master_wstrb = 4'b1100;  // 写入高两字节
            io_master_wdata = {saved_wdata[15:0], 16'b0}; // 数据左移16位
        end
        default: begin 
            io_master_wstrb = 4'b0000;
            $display("error!!!!! half word access is not aligned");
        end
    endcase
    end
    else begin
    case (saved_addr[1:0])
        2'b00: begin

            io_master_wstrb = 4'b0011;  // 写入低两字节
            io_master_wdata = {16'b0, saved_wdata[15:0]}; // 数据保持低位
        end
        2'b10: begin
            io_master_wstrb = 4'b1100;  // 写入高两字节
            io_master_wdata = {saved_wdata[15:0], 16'b0}; // 数据左移16位
        end
        default: begin 
            io_master_wstrb = 4'b0000;
            $display("error!!!!! half word access is not aligned");
        end
    endcase
    end
end
    3'b010: begin // 字访问  sw
    if(is_uart_region) begin
       case (saved_addr[1:0])
            2'b00: io_master_wstrb = 4'b1111;
            default: begin
                io_master_wstrb = 4'b0000;
                $display("error!!!!! word access is not aligned from lsu.v line:236");
                $display("saved_addr is %h from lsu.v line:237", saved_addr);
                // 应该触发非对齐
            end
        endcase
    end
    else begin
        case (saved_addr[1:0])
            2'b00: io_master_wstrb = 4'b1111;
            default: begin
                io_master_wstrb = 4'b0000;
                $display("error!!!!! word access is not aligned from lsu.v line:236");
                $display("saved_addr is %h from lsu.v line:237", saved_addr);
                // 应该触发非对齐
            end
        endcase
    end
    end
        default: begin
            io_master_wstrb = 4'b0000;
            $display("wrong!!!!!!!saved awsizes is unknown number from lsu.v line:230");
            $display("saved_awsize is %h from lsu.v line:231", saved_awsize);
        end
    endcase
end   


//always @(io_master_wstrb) begin
    //$display("io_master_wstrb CHANGED TO %d from lsu \n", io_master_wstrb);
//end




always @(reset) begin
    $display("RESET CHANGED TO %d from lsu \n", reset);
end

export "DPI-C"  function get_saved_addr;
function int get_saved_addr();
  get_saved_addr = saved_addr; // 假设lsu是LSU模块的实例名
endfunction

endmodule






































































/*module ysyx_24090012_LSU (
    input clk,
    input rst,
    
    // EXU接口 (slave)
    input [31:0]  addr,       // 地址
    input         valid,      // 请求有效 (exu -> lsu)
    output reg    ready,      // 请求完成 (lsu -> exu)
    output reg [31:0] rdata,  // 读出的数据
    input [31:0]  wdata,      // 写入的数据
    input [3:0]   wmask,      // 写掩码
    input         wen,        // 写使能
    
    // SRAM接口 (master)
    output reg [31:0] sram_addr,  // SRAM地址
    output reg        arvalid,    // 地址有效 (lsu -> sram)
    input             arready,    // 地址准备好 (sram -> lsu)
    input [31:0]      sram_rdata, // 从SRAM读出的数据
    input             rvalid,     // 数据有效 (sram -> lsu)
    output reg        rready,     // 数据准备好 (lsu -> sram)
    output reg [31:0] sram_wdata, // 写入SRAM的数据
    output reg [3:0]  sram_wmask, // SRAM写掩码
    output reg        sram_wen    // SRAM写使能
);
    // 状态定义
    localparam IDLE      = 2'b00;  // 空闲状态
    localparam ADDR_PHASE = 2'b01; // 地址握手阶段
    localparam DATA_PHASE = 2'b10; // 数据握手阶段
    
    reg [1:0] state, next_state;   // 状态寄存器
    
    // 状态转换
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    // 状态机逻辑
    always @(*) begin
        // 默认值
        next_state = state;
        ready = 0;
        rdata = sram_rdata;
        sram_addr = addr;
        sram_wdata = wdata;
        sram_wmask = wmask;
        sram_wen = wen;
        arvalid = 0;
        rready = 0;
        
        case (state)
            IDLE: begin
                if (valid) begin
                    arvalid = 1;  // 地址有效
                    next_state = ADDR_PHASE;
                end
            end
            
            ADDR_PHASE: begin
                arvalid = 1;  // 保持地址有效
                if (arready) begin
                    arvalid = 0;  // 地址已接收
                    next_state = DATA_PHASE;
                end
            end
            
            DATA_PHASE: begin
                rready = 1;  // 准备好接收数据
                if (rvalid) begin
                    ready = 1;  // 数据已接收
                    rready = 0; // 复位 rready
                    next_state = IDLE;
                end
            end
        endcase
    end
endmodule*/



