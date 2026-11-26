module CLINT(
  input         clk,
  input         rst,
  input  [63:0] mtime,

  // AXI4 AR
  input         clint_arvalid,
  output        clint_arready,
  input  [31:0] clint_araddr,
  input  [ 3:0] clint_arid,
  input  [ 7:0] clint_arlen,
  input  [ 2:0] clint_arsize,
  input  [ 1:0] clint_arburst,

  // AXI4 R
  output        clint_rvalid,
  input         clint_rready,
  output [31:0] clint_rdata,
  output [ 1:0] clint_rresp,
  output        clint_rlast,
  output [ 3:0] clint_rid
);

  localparam R_IDLE = 1'b0;
  localparam R_WAIT = 1'b1;

  reg        r_state;
  reg [31:0] rdata_latch;
  reg [ 3:0] rid_latch;
  reg        rlast_latch;

  wire [15:0] raddr_off = clint_araddr[15:0];
  wire is_mtime_lo = (raddr_off == 16'hbff8);
  wire is_mtime_hi = (raddr_off == 16'hbffc);

  assign clint_arready = !rst && (r_state == R_IDLE);
  assign clint_rvalid  = !rst && (r_state == R_WAIT);
  assign clint_rdata   = rdata_latch;
  assign clint_rresp   = 2'b00;
  assign clint_rlast   = rlast_latch;
  assign clint_rid     = rid_latch;

  always @(posedge clk) begin
    if (rst) begin
      r_state     <= R_IDLE;
      rdata_latch <= 32'b0;
      rid_latch   <= 4'b0;
      rlast_latch <= 1'b0;
    end else begin
      case (r_state)
        R_IDLE: begin
          if (clint_arvalid) begin
            rid_latch   <= clint_arid;
            rlast_latch <= (clint_arlen == 8'd0);
            if (is_mtime_lo)
              rdata_latch <= mtime[31:0];
            else if (is_mtime_hi)
              rdata_latch <= mtime[63:32];
            else
              rdata_latch <= 32'b0;
            r_state <= R_WAIT;
          end
        end
        R_WAIT: begin
          if (clint_rready)
            r_state <= R_IDLE;
        end
        default: r_state <= R_IDLE;
      endcase
    end
  end

endmodule
