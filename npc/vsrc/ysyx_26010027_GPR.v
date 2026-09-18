module ysyx_26010027_GPR #(
    // parameter ADDR_WIDTH = 4,
    parameter DATA_WIDTH = 32
) (
    input               clock,
    input               reset,
    input       [ 3:0]  waddr,
    input       [31:0]  wdata,
    input               wen,
    input       [ 3:0]  raddr1,
    input       [ 3:0]  raddr2,
    output      [31:0]  rdata1,
    output      [31:0]  rdata2
);

    reg [DATA_WIDTH-1:0] rf [15:0];
    integer r;

    always @(posedge clock or posedge reset) begin
        if (reset)
            for (r = 1; r < 16; r = r + 1)
                rf[r] <= {DATA_WIDTH{1'b0}};
        else if (wen && (waddr != 0)) begin
            rf[waddr] <= wdata;
`ifdef NPC_SIM
            get_reg({28'b0, waddr}, wdata);
`endif
        end
    end

    assign rdata1 = (raddr1 == 0) ? 32'b0 :
                    (wen && (waddr == raddr1)) ? wdata :
                    rf[raddr1];
    assign rdata2 = (raddr2 == 0) ? 32'b0 :
                    (wen && (waddr == raddr2)) ? wdata :
                    rf[raddr2];

endmodule
