module with_clkgate (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [7:0]  data_in,
    input  wire        enable,
    output reg  [7:0]  data_out
);

reg [7:0] reg1, reg2, reg3, reg4;

wire [7:0] reg1_next, reg2_next, reg3_next, reg4_next;

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        reg1 <= 8'h0;
        reg2 <= 8'h0;
        reg3 <= 8'h0;
        reg4 <= 8'h0;
    end
    else begin
        reg1 <= reg1_next;
        reg2 <= reg2_next;
        reg3 <= reg3_next;
        reg4 <= reg4_next;
    end
end
//数据选择器
assign reg1_next = enable ? data_in       : reg1;
assign reg2_next = enable ? data_in + 1   : reg2;
assign reg3_next = enable ? data_in + 3   : reg3;
assign reg4_next = enable ? data_in + 3   : reg4;

assign data_out = reg1;

endmodule
