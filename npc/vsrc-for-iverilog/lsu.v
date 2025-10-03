module ysyx_24090012_LSU (
    input wire         clock,
    input wire         reset,
    output reg [2:0] state_out,   //换成wire
  
   // input   mem_unsigned,

    input [31:0] lsu_in_pc,
    output  [31:0] lsu_out_pc,   //不清楚是否需要，或许可以去掉

    // EXU Interface (slave)
    input  wire [31:0] mem_addr,
    input  wire        mem_valid,
    input  wire [31:0] mem_wdata,

    output          mem_ready,

    output wire [31:0] data_hazard_lsu_inst,
    output wire [31:0]  lsu_hazard_result,

    input [31:0] mem_result,    // 流水线流水线流水线
    input wire [31:0] next_pc,

    output [31:0] wbu_data,    // 流水线流水线流水线

    input [31:0] csr_wdata,
 
    output [31:0] wbu_csr_wdata,
    input [31:0] exu_to_lsu_inst,
    output [31:0] lsu_to_wbu_inst,
 
    output     wbu_csr_valid,
    output        wbu_csr_ready,

    output     wbu_valid,   // 流水线流水线流水线
    input         wbu_ready,   // 流水线流水线流水线
    output [31:0] wbu_next_pc, // 流水线流水线流水线

    output wire [63:0] lsu_reg_num,


    input [63:0] num,
    output reg [63:0] num_r,

    output reg [31:0] sim_lsu_addr,//用于流水线仿真环境取出写入地址判断是否跳过difftest


    // AXI4 Master Interface
    // Write Address Channel
    input  wire        io_master_awready,
    output          io_master_awvalid,
    output   [31:0] io_master_awaddr,
    output   [3:0]  io_master_awid,     // 传递事务ID
    output   [7:0]  io_master_awlen,
    output   [2:0]  io_master_awsize,
    output   [1:0]  io_master_awburst,

    // Write Data Channel
    input  wire        io_master_wready,
    output          io_master_wvalid,
    output reg  [31:0] io_master_wdata,
    output reg  [3:0]  io_master_wstrb,
    output          io_master_wlast,     // 单次传输永远为1

    // Write Response Channel
    output          io_master_bready,
    input  wire        io_master_bvalid,
    input  wire [1:0]  io_master_bresp,    // 写响应状态
    input  wire [3:0]  io_master_bid,      // 写响应ID

    // Read Address Channel
    input  wire        io_master_arready,
    output          io_master_arvalid,
    output   [31:0] io_master_araddr,
    output   [3:0]  io_master_arid,     // 传递事务ID
    output   [7:0]  io_master_arlen,
    output   [2:0]  io_master_arsize,
    output   [1:0]  io_master_arburst,

    // Read Data Channel
    output          io_master_rready,
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
    localparam WBU_WAIT    = 3'd6;
    localparam SAVE_STATE  = 3'd7; 


assign lsu_to_wbu_inst = exu_to_lsu_inst_r;
assign data_hazard_lsu_inst = exu_to_lsu_inst_r;

assign lsu_hazard_result = saved_result;

assign lsu_reg_num = num_r;

wire [6:0] opcode = exu_to_lsu_inst_r[6:0];
wire [2:0] func3 = exu_to_lsu_inst_r[14:12];


wire saved_mem_unsigned = 
    (opcode == 7'b0000011 && func3 == 3'b100) || // LBU
    (opcode == 7'b0000011 && func3 == 3'b101);   // LHU

wire saved_is_use_lsu = (opcode == 7'b0000011) || (opcode == 7'b0100011);  
wire saved_wen = (opcode == 7'b0100011);


   wire [2:0] saved_arsize = 
    (opcode == 7'b0000011 && (func3 == 3'b000 || func3 == 3'b100)) ? 3'b000 :  // LB/LBU
    (opcode == 7'b0000011 && (func3 == 3'b001 || func3 == 3'b101)) ? 3'b001 :  // LH/LHU
    (opcode == 7'b0000011 && func3 == 3'b010) ? 3'b010 :                       // LW
    3'b000;      

    wire [2:0] saved_awsize = 
    (opcode == 7'b0100011 && func3 == 3'b000) ? 3'b000 :  // SB
    (opcode == 7'b0100011 && func3 == 3'b001) ? 3'b001 :  // SH
    (opcode == 7'b0100011 && func3 == 3'b010) ? 3'b010 :  // SW
    3'b000;     


    reg [31:0] exu_to_lsu_inst_r;

    // 寄存器定义
    reg [2:0] state;
    reg [31:0] saved_addr;//读写地址
    reg [31:0] saved_wdata;
    
     // 组合逻辑：状态转换和控制信号生成
    reg [2:0] next_state;
    reg [31:0] processed_rdata;//用于对读出数据进行寄存，最后赋值给mem rdata

    reg [3:0]  curr_id;    // 当前事务ID
  
   // reg [4:0]  saved_rd;//流水线流水线流水线
   // reg        saved_rd_wen;//流水线流水线流水线
    reg [31:0] saved_result;//流水线流水线流水线    
 
    reg [31:0] saved_next_pc;
   

    reg  [31:0] saved_pc;

  
 
    //reg [11:0] saved_csr_addr;
    reg [31:0] saved_csr_wdata;
    //reg saved_csr_wen;

    reg [31:0] lsu_count;          // LSU总操作计数器
    reg [31:0] read_count;         // 读操作计数器
    reg [31:0] write_count;        // 写操作计数器

always @(posedge clock) begin
    // 写响应检测
    if (io_master_bresp != 2'b00) begin
        $display("LSU error! bid expected: %h, received: %h, bresp: %b", 
                curr_id, 
                io_master_bid, 
                io_master_bresp);     //综合需要注释
    end
    
    // 读响应检测
    if (io_master_rresp != 2'b00) begin
        $display("LSU read ID wrong! curr_id: %h, rid: %h, rresp: %b",
                curr_id,
                io_master_rid,
                io_master_rresp);   //综合需要注释
    end
end


    // 时序逻辑：状态更新和数据保存
    always @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            curr_id <= 4'h0;

            lsu_count <= 32'h0;
            read_count <= 32'h0;
            write_count <= 32'h0;

        end else begin
            // 在IDLE状态且有新请求时保存数据
            if (state == IDLE && mem_valid) begin
                saved_addr <= mem_addr;//读写地址
                saved_wdata <= mem_wdata;//写数据
             
              
              
                curr_id <= curr_id + 4'h1;  // 递增事务ID
             
                saved_result <= mem_result;   
             
                saved_next_pc <= next_pc;
               
                saved_csr_wdata <= csr_wdata;
                saved_pc <= lsu_in_pc;//                           不确定是否需要
            
                num_r <= num;
                exu_to_lsu_inst_r <= exu_to_lsu_inst;
            end

   // 更新计数器 - 当读操作完成时
            if (state == READ_DATA && next_state == IDLE) begin
                read_count <= read_count + 1;
                lsu_count <= lsu_count + 1;
            end
            
            // 更新计数器 - 当写操作完成时
            if (state == WRITE_RESP && next_state == IDLE) begin
                write_count <= write_count + 1;
                lsu_count <= lsu_count + 1;
            end

            if (state == READ_DATA && io_master_rvalid && io_master_rresp == 2'b00) begin
                saved_result <= processed_rdata;
            end

            state <= next_state;
        end
    end

   assign mem_ready = (state == IDLE);
   assign wbu_valid = (state == WBU_WAIT);
   assign wbu_csr_valid = (state == WBU_WAIT);
   assign  lsu_out_pc = saved_pc;

   assign io_master_awvalid = (state == WRITE_ADDR);
   assign io_master_awaddr = saved_addr;
   assign io_master_araddr = saved_addr;
   assign io_master_awsize = saved_awsize;
   assign io_master_arsize = saved_arsize;
   assign io_master_awlen = 8'b0;
   assign io_master_arlen = 8'b0;
   assign io_master_awid = curr_id;
   assign io_master_arid = curr_id;
   assign io_master_awburst = 2'b01;
   assign io_master_arburst = 2'b01;
   assign io_master_wvalid = (state == WRITE_DATA);
   assign io_master_wlast = 1'b1;//单次传输为1
   assign io_master_bready = (state == WRITE_RESP);
   assign io_master_rready = (state == READ_DATA);
   assign io_master_arvalid = (state == READ_ADDR);
  

    always @(*) begin

      state_out = state;

        // 默认值
        next_state = state;
       // io_master_awvalid = 0;
       // io_master_wvalid  = 0;
       // io_master_bready  = 0;
       // io_master_arvalid = 0;
       // io_master_rready  = 0;
      //  mem_ready = 0;
       
        
        // 固定值
       // io_master_awid    = curr_id;        // 使用当前事务ID
      //  io_master_awlen   = 8'd0;           // 单次传输
       // io_master_awsize  = saved_awsize;  
            
       // io_master_awburst = 2'b01;          // INCR模式
       //io_master_arid    = curr_id;        // 使用当前事务ID
      //  io_master_arlen   = 8'd0;           // 单次传输
       // io_master_arsize  = saved_arsize;  
          
      //  io_master_arburst = 2'b01;          // INCR模式
        
        // 地址和数据连接
       // io_master_awaddr = saved_addr;
       // io_master_araddr = saved_addr;
       // io_master_wdata  = saved_wdata;    //综合需要注释 （下面的wstrb不是）


        //io_master_wstrb  = saved_wmask;
       // io_master_wlast  = 1'b1;            // 单次传输永远为1


      // wbu_rd = saved_rd;//流水线流水线流水线
      // wbu_rd_wen = saved_rd_wen;//流水线流水线流水线
       wbu_data = saved_result;//流水线流水线流水线
       wbu_next_pc = saved_next_pc;
      // wbu_valid = 1'b0;
     //  wbu_csr_valid = 1'b0;

     //  wbu_csr_addr = saved_csr_addr;
       wbu_csr_wdata = saved_csr_wdata;
    //   wbu_csr_wen = saved_csr_wen;

      
   

       sim_lsu_addr = saved_addr;
      
        
        // 状态转换和控制信号生成
        case (state)
            IDLE: begin
              //  mem_ready = 1'b1;//改为wire assign
                if (mem_valid) begin//流水线流水线流水线
                    // 有新请求，进入保存状态
                   
                    next_state = SAVE_STATE;
                end
            end

            SAVE_STATE: begin
                // 在这个状态下，saved_is_use_lsu已经被更新
                if (!saved_is_use_lsu) begin    //如果不使用lsu直接到wbu wait状态和wbu握手
                    // 非内存操作，直接传递给WBU
                    next_state = WBU_WAIT;
                end else begin                   //如果使用lsu就正常执行
                    // 内存操作，进入相应状态
                    next_state = saved_wen ? WRITE_ADDR : READ_ADDR;
                end
            end

            WBU_WAIT: begin //流水线流水线流水线    
               // wbu_valid = 1'b1; 
              //  wbu_csr_valid = 1'b1;
                if (wbu_ready  && wbu_csr_ready) begin
                    // WBU已就绪，完成操作
                    next_state = IDLE;
                end else begin
                    // WBU未就绪，等待
                    next_state = WBU_WAIT;
                end
            end
            
            WRITE_ADDR: begin
               // io_master_awvalid = 1'b1;
                if (io_master_awready) begin
                    next_state = WRITE_DATA;
                end
            end
            
            WRITE_DATA: begin
               // io_master_wvalid = 1'b1;
                if (io_master_wready) begin
                    next_state = WRITE_RESP;
                end
            end
            

            




                 WRITE_RESP: begin
              //  io_master_bready = 1'b1;
                if (io_master_bvalid) begin
                    // 检查响应和ID
                    if (io_master_bid == curr_id && io_master_bresp == 2'b00) begin
                    
                        
                        //mem_ready = 1'b1;流水线流水线流水线
                        next_state = WBU_WAIT;//流水线流水线流水线
                        //流水线流水线流水线

                    end

                   else begin
            // 写操作失败，记录错误
            $display("LSU write error! bid expected: %h, received: %h, bresp: %b", 
                    curr_id, 
                    io_master_bid, 
                    io_master_bresp);     //综合需要注释
            
            // 返回IDLE状态
                   next_state = IDLE;
                        end
                end
            end
            
            READ_ADDR: begin
               // io_master_arvalid = 1'b1;
                if (io_master_arready) begin
                    next_state = READ_DATA;
                end
            end
            
            READ_DATA: begin
              //  io_master_rready = 1'b1;
                if (io_master_rvalid) begin
                    // 检查响应和ID
                    //if (io_master_rid == curr_id && io_master_rresp == 2'b00) begin
                     if (io_master_rresp == 2'b00) begin//在初始化串口发现id不匹配先不对比id
                        //mem_ready = 1'b1;流水线流水线流水线
                      
                      //  mem_rdata = processed_rdata; 流水线流水线流水线
                       //$display("mem_rdata is %h from lsu.v line:197", mem_rdata);
                      
                          // 读操作成功完成，更新计数器
                        next_state = WBU_WAIT;//流水线流水线流水线
           
                    end
                    else begin
                        // 写操作失败，记录错误
                        $display("LSU write error! bid expected: %h, received: %h, bresp: %b", 
                                curr_id, 
                                io_master_bid, 
                                io_master_bresp);     //综合需要注释
                        
                        // 返回IDLE状态
                        next_state = IDLE;
                    end
                end
                
            end
            
            default: next_state = IDLE;
        endcase
    end






   wire is_mrom_region = (saved_addr[31:24] == 8'h20);
   wire is_uart_region = (saved_addr[31:24] == 8'h10);

//这里processed data和 下面的io master信号也能换成wire

always @(*) begin
    // 默认值
    processed_rdata = 32'b0;
        // 判断地址区间 - MROM区域通常在0x2000_0000开始
   



    // 根据读操作类型处理数据
    case (saved_arsize)
        3'b000: begin // 字节访问 lb lbu
        if(is_mrom_region) begin


        processed_rdata = {{24{io_master_rdata[7]}}, io_master_rdata[7:0]};
        //$display("processed_rdata is %h from lsu.v line:236", processed_rdata);

        end
        else  if (!saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{24{io_master_rdata[7]}}, io_master_rdata[7:0]};
                2'b01: processed_rdata = {{24{io_master_rdata[15]}}, io_master_rdata[15:8]};
                2'b10: processed_rdata = {{24{io_master_rdata[23]}}, io_master_rdata[23:16]};
                2'b11: processed_rdata = {{24{io_master_rdata[31]}}, io_master_rdata[31:24]};
            endcase
          
        end

        else if (saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{24{1'b0}}, io_master_rdata[7:0]};
                2'b01: processed_rdata = {{24{1'b0}}, io_master_rdata[15:8]};
                2'b10: processed_rdata = {{24{1'b0}}, io_master_rdata[23:16]};
                2'b11: processed_rdata = {{24{1'b0}}, io_master_rdata[31:24]};
            endcase
        end

        end
        3'b001: begin // 半字访问 lh lhu
        if(is_mrom_region) begin



        processed_rdata = {{16{io_master_rdata[15]}}, io_master_rdata[15:0]};


        end

        else  if (!saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{16{io_master_rdata[15]}}, io_master_rdata[15:0]};
                2'b10: processed_rdata = {{16{io_master_rdata[31]}}, io_master_rdata[31:16]};
                default: begin
                    processed_rdata = 32'b0;
                    $display("error!!!!! half word read is not aligned");        //综合需要注释
                end
            endcase
        end

        else if (saved_mem_unsigned) begin
            case (saved_addr[1:0])
                2'b00: processed_rdata = {{16{1'b0}}, io_master_rdata[15:0]};
                2'b10: processed_rdata = {{16{1'b0}}, io_master_rdata[31:16]};
                default: begin
                    processed_rdata = 32'b0;
                    $display("error!!!!! half word read is not aligned");        //综合需要注释
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
                    $display("saved_addr is %h from lsu.v line:303", saved_addr);    //综合需要注释
                end
            endcase
        end
        end
        default: begin
            processed_rdata = 32'b0;
            $display("wrong!!!!! unknown read size");    //综合需要注释
        end
    endcase
end












//

always @(*) begin
    // 默认值
    io_master_wdata  = saved_wdata;//综合锁存器需要 yosys
  //is_uart_region = (saved_addr[31:24] == 8'h10);
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
            $display("error!!!!! half word access is not aligned");   //综合需要注释
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
            $display("error!!!!! half word access is not aligned");   //综合需要注释
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
                $display("saved_addr is %h from lsu.v line:237", saved_addr);    //综合需要注释
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
                $display("saved_addr is %h from lsu.v line:237", saved_addr);     //综合需要注释
                // 应该触发非对齐
            end
        endcase
    end
    end
        default: begin
            io_master_wstrb = 4'b0000;
           $display("wrong!!!!!!!saved awsizes is unknown number from lsu.v line:230");
            $display("saved_awsize is %h from lsu.v line:231", saved_awsize);   //综合需要注释
        end
    endcase
end   



















always @(reset) begin
    $display("RESET CHANGED TO %d from lsu \n", reset);    //综合需要注释
end

export "DPI-C"  function get_saved_addr;
function int get_saved_addr();
  get_saved_addr = saved_addr; // 假设lsu是LSU模块的实例名
endfunction




    // 导出DPI-C函数，供C++仿真环境访问
export "DPI-C" function get_lsu_count;
export "DPI-C" function get_read_count;
export "DPI-C" function get_write_count;

// DPI-C函数实现
function int get_lsu_count();
    return lsu_count;
endfunction

function int get_read_count();
    return read_count;
endfunction

function int get_write_count();
    return write_count;
endfunction







endmodule


