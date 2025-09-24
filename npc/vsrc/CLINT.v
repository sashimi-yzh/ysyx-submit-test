module ysyx_25010008_CLINT (
    input clock,
    input reset,

    input [31:0] araddr,
    input arvalid,
    output reg arready,

    input rready,
    output reg [31:0] rdata,
    output reg [1:0] rresp,
    output reg rvalid
);

  parameter HANDLE_RADDR = 0;
  parameter HANDLE_RDATA = 1;

  reg rstate;

  reg [63:0] mtime;

  always @(posedge clock) begin
    if (reset) begin
      mtime   <= 0;
      arready <= 1;
      rresp   <= 0;
      rvalid  <= 0;
      rstate  <= HANDLE_RADDR;
    end else begin
      mtime <= mtime + 1;  // add 1 to simulate real time acorrding to speed of npc's simulation
      if (rstate == HANDLE_RADDR) begin
        if (arvalid) begin
          rdata   <= araddr[2] ? mtime[63:32] : mtime[31:0];
          arready <= 0;
          rvalid  <= 1;
          rstate  <= HANDLE_RDATA;
        end
      end else begin
        if (rready) begin
          rvalid  <= 0;
          arready <= 1;
          rstate  <= HANDLE_RADDR;
        end
      end
    end
  end

endmodule

