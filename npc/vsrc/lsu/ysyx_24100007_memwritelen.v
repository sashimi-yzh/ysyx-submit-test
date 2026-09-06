module ysyx_24100007_memwritelen(
    input [31:0] awaddr,
    input [2:0] wirtelen,
    output [3:0] wstrb,
    output [2:0] awsize,
    output [1:0] wdata_offset
);
    wire [3:0] base_wstrb = (wirtelen == 3'b001) ? 4'b0001 :
                            (wirtelen == 3'b010) ? 4'b0011 :
                            (wirtelen == 3'b100) ? 4'b1111 :
                            4'b0000;

    assign awsize = (wirtelen == 3'b001) ? 3'b000 :
                    (wirtelen == 3'b010) ? 3'b001 :
                    (wirtelen == 3'b100) ? 3'b010 :
                    3'b000;
    assign wdata_offset = awaddr[1:0];
    assign wstrb = base_wstrb << awaddr[1:0];

endmodule
