module GPR #(ADDR_WIDTH = 4, DATA_WIDTH = 32) (
    input clk,
    input reset,
    input [DATA_WIDTH-1:0] wdata,
    input [ADDR_WIDTH-1:0] waddr,
    input wen,
    input [ADDR_WIDTH-1:0] raddr1,
    output [DATA_WIDTH-1:0]rdata1,
    input [ADDR_WIDTH-1:0] raddr2,
    output [DATA_WIDTH-1:0]rdata2
);
    reg [DATA_WIDTH-1:0] gpr [2**ADDR_WIDTH-1:0];
    integer i;

    always @(posedge clk) begin
        if(reset) begin
            for(i=0; i<2**ADDR_WIDTH; i=i+1) begin
                gpr[i] <= {DATA_WIDTH{1'b0}};
            end
        end
        else if(wen) gpr[waddr] <= (waddr == 4'b0) ? {DATA_WIDTH{1'b0}} : wdata;
    end

    assign rdata1 = gpr[raddr1];
    assign rdata2 = gpr[raddr2];
endmodule
