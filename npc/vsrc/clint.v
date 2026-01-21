module ysyx_25050136_CLINT(
    input            clk   ,
    input            reset ,
    input   [31:0]   addr_i,
    output  [31:0]   data_o
);
    reg [63:0] mtime;
    always @(posedge clk) begin
        if (reset) begin
            mtime <= 0;
        end else begin
            mtime <= mtime + 64'd1;
        end
    end
    assign data_o = (addr_i == 32'h0200_0000) ? mtime[31:0] :
                    (addr_i == 32'h0200_0004) ? mtime[63:32] : 32'b0;
endmodule
