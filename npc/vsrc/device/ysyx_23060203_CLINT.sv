module ysyx_23060203_CLINT (
  input clock, reset,

  ysyx_23060203_axi_if.in read
);

  reg [63:0] uptime, uptime_next;

  always @(posedge clock) begin
    if (reset) begin
      uptime <= 0;
    end else begin
      uptime <= uptime_next;
    end
  end

  always_comb begin
    uptime_next = uptime + 1;
  end

  assign read.arready = 1;
  assign read.rvalid = 1;
  assign read.rresp = 0;
  assign read.rdata = read.araddr[2] ? uptime[63:32] : uptime[31:0];
  assign read.rlast = 1;
  assign read.rid = 0;
endmodule
