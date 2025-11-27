`ifndef YOSYS_STA
`ifndef RUNSOC

`ifndef __ICARUS__
`include "HDR/ysyx_25040111_dpic.vh"
`endif

`define READY_TIME 8'd1

module ysyx_25040111_sram(
    input           clock,
    input           reset,
    input [31:0]    araddr,
    input [2:0]     arsize,
    input [7:0]     arlen,
    input           arvalid,
    output          arready,
    input [1:0]     arburst,

    output [31:0]   rdata,
    output reg      rvalid,
    input           rready,

    input [31:0]    awaddr,
    input           awvalid,
    input [2:0]     awsize,
    output          awready,

    input [31:0]    wdata,
    input [3:0]     wstrb,
    input           wvalid,
    input           wlast,
    output          wready,
    output          bvalid,
    input           bready
);
    reg reading;
    reg [7:0] rcount;
    reg [31:0] raddr;

    // memory read
    reg [31:0] rdata_t;
    assign arready = 1;

    `ifdef NETLIST
    assign rdata = raddr == 32'h30000000 ? 32'h800002B7 :
                   raddr == 32'h30000004 ? 32'h00028067 :
                   raddr <  32'h80000000 ? 32'd0 : rdata_t;
    `else
    assign rdata = rdata_t;
    `endif


`ifdef __ICARUS__
    reg [7:0] mem [0:67108864];
    integer i;
    initial begin
        for (i = 0; i < 6291456 * 4 + 1; i = i + 1)
            mem[i] = 8'h00;
        $display("read hex from %s", `HEX_PATH);
        $readmemh(`HEX_PATH, mem);
        $display("read end");
    end
    wire [31:0] iaraddr = raddr & {4'b0, {26{1'b1}}, 2'b0};
    wire [31:0] mrdata = {mem[iaraddr | 32'b11], mem[iaraddr | 32'b10], mem[iaraddr | 32'b01], mem[iaraddr]};
`endif // __ICARUS__

    wire rend = rcount == arlen;
    always @(posedge clock) begin
        if (reset)
            reading <= 1'b0;
        else if (arvalid & arready)
            reading <= 1'b1;
        else if (rvalid & rready & rend)
            reading <= 1'b0;
    end

    always @(posedge clock) begin
        if (reset)
            rcount <= 8'b0;
        else if (arvalid & arready)
            rcount <= 8'b0;
        else if (rvalid & rready)
            rcount <= rend ? 8'b0 : rcount + 1;
    end

    always @(posedge clock) begin
        if (arvalid & arready)
            raddr <= araddr;
        else if (rvalid & rready)
            raddr <= raddr + 32'd4;
    end

    always @(posedge clock) begin
        if (reset)begin
            rdata_t <= 0;
            rvalid <= 1'b0;            
        end
        else if (reading & ~rvalid) begin
            // $display("[%h <==> %h]  %d  %d  vr:%b%b en:%b%b", araddr, raddr, rcount, arlen, arvalid, arready, reading,rend);

            `ifdef __ICARUS__
                rdata_t <= mrdata;
                // $display("read iaddr %h data %h", araddr, mrdata);
            `else
                rdata_t <= pmem_read(raddr);
            `endif // __ICARUS__
            rvalid  <= 1'b1;
        end
        else if (rvalid & rready) begin
            rvalid <= 1'b0;
        end
    end
    
    assign awready = 1;
    assign wready = 1;
    assign bvalid = wready & wvalid;
    // memory write
    `ifdef __ICARUS__
        wire [31:0] iawaddr = awaddr & {4'b0, {26{1'b1}}, 2'b0};
    `else
        wire [7:0] wmask = {4'b0, wstrb};
    `endif

    always @(posedge clock) begin
        if (awvalid & awready & wvalid & wready & wlast & bready) begin
            `ifdef __ICARUS__
                // $display("write mem %h", awaddr);
                if (awaddr == 32'ha00003f8)
                    $write("%c", wdata[7:0]);
                else begin
                    if (wstrb[0]) mem[iawaddr] <= wdata[7:0];
                    if (wstrb[1]) mem[iawaddr | 32'b01] <= wdata[15:8];
                    if (wstrb[2]) mem[iawaddr | 32'b10] <= wdata[23:16];
                    if (wstrb[3]) mem[iawaddr | 32'b11] <= wdata[31:24];
                end
            `else
                pmem_write(awaddr, wdata, wmask);
            `endif // __ICARUS__
        end
    end

endmodule

`endif // RUNSOC
`endif // YOSYS_STA
