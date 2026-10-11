module ysyx_26040117_RegisterFile #(ADDR_WIDTH = 4, DATA_WIDTH = 32) (clk,
    raddr1,raddr2,rdata1,rdata2,
    wdata,waddr,wen
);
    input clk;
    input wen;
    input [ADDR_WIDTH-1:0] waddr,raddr1,raddr2;
    input [DATA_WIDTH-1:0] wdata;
    output reg[DATA_WIDTH-1:0] rdata1,rdata2;
    reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
    always @(posedge clk) begin
        if (wen&&(waddr != 0))begin
            rf[waddr] <= wdata;
        end
    end
    /*
    assign rdata1 = (raddr1 == 0) ? 32'b0 : rf[raddr1];
    assign rdata2 = (raddr2 == 0) ? 32'b0 : rf[raddr2];
    */
    integer i;
    always @(*) begin
        rdata1=32'd0;
        rdata2=32'd0;
        for(i=1;i<2**ADDR_WIDTH;i++)begin
            rdata1=rdata1|(rf[i]&{DATA_WIDTH{raddr1==i[ADDR_WIDTH-1:0]}});
            rdata2=rdata2|(rf[i]&{DATA_WIDTH{raddr2==i[ADDR_WIDTH-1:0]}});
        end
    end
endmodule
