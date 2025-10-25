`ifdef RUNSOC
`define CLINT_ADDR 32'h02000048
`else
`define CLINT_ADDR 32'ha0000048
`endif

module ysyx_25040111_clint(
    input           clock,
    input           reset,    

    input [31:0]    araddr,
    input           arvalid,
    output          arready,

    output [31:0]   rdata,
    output          rvalid,
    input           rready
);

    // time read
    reg        tvalid;
    reg [63:0] mtime;

    assign arready = 1'b1;
    assign rvalid  = tvalid;
    assign rdata   = tvalid ? (araddr[3:0] == 4'd8) ? mtime[31:0] : mtime[63:32] : 32'b0;
    
    always @(posedge clock) begin
        if (reset) begin
            mtime <= 0;
            tvalid   <= 0;
        end else begin
            mtime <= mtime + 1;

            if (arvalid & arready) begin
                tvalid <= 1;
            end else if (rvalid & rready) begin
                tvalid <= 0;
            end
        end
    end

endmodule
