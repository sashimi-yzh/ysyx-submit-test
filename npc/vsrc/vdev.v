/*
import "DPI-C" function void difftest_skip_ref();

module ysyx_24110012_vuart (
    input clk,

    // AR
    input wire [31:0] araddr,
    input wire arvalid,
    output reg arready,

    // R
    output reg [31:0] rdata,
    output reg rvalid,
    input wire rready,

    // AW
    input wire [31:0] awaddr,
    input wire awvalid,
    output reg awready,

    // W
    input reg [31:0] wdata,
    input wire [3:0] wstrb,
    input wire wvalid,
    output reg wready,

    // B
    output reg [1:0] bresp,
    output reg bvalid,
    input wire bready
);

  reg r_done, w_done;
  reg w_once;
  reg [31:0] awaddr_p;

  reg [4:0] wready_delay_cnt;
  reg [4:0] wready_lfsr = 5'b00101;  // wready_lfsr for random delay

  always @(posedge clk) begin
    w_done <= 1'b0;
    assert (awaddr[1:0] == 2'b00)
    else $error("awaddr is %h not 4-byte aligned.", awaddr);

    if (awvalid) begin
      awaddr_p <= awaddr;
      awready  <= 1'b1;
    end else begin
      awready <= 1'b0;
    end

    if (wvalid) begin
      if (w_once == 1'b0) begin
        // the offset of the uart data is 0x0
        $write("%c", wdata[7:0]);
        // skip the difftest when uart write happens since nemu does not suppor device as ref
        difftest_skip_ref();
        wready_lfsr <= {
          wready_lfsr[3:0], wready_lfsr[4] ^ wready_lfsr[3] ^ wready_lfsr[2] ^ wready_lfsr[0]
        };
      end
      w_once <= 1'b1;
      if (wready_delay_cnt == wready_lfsr) begin
        wready_delay_cnt <= 5'b0;
        wready <= 1'b1;
      end
      wready_delay_cnt <= wready_delay_cnt + 1;
    end

    if (wready) begin
      bresp   <= 2'b00;  // OKAY response
      bvalid  <= 1'b1;  // indicate write response is valid
      wready  <= 1'b0;
      awready <= 1'b0;
    end else if (bready) begin
      wready <= 1'b0;
      w_once <= 1'b0;
      bvalid <= 1'b0;  // clear bvalid when bready is asserted
      w_done <= 1'b1;
    end
  end

  reg [31:0] araddr_p;
  reg [4:0] r_delay_cnt;
  reg [4:0] r_lfsr = 5'b00011;
  reg r_once;

  // should not be used for uart read in current design
  always @(posedge clk) begin
    r_done <= 1'b0;  // default not done
    if (arvalid) begin
      arready  <= 1'b1;
      araddr_p <= araddr;
      // generate new lfsr here assuming arvalid once high
      if (r_once == 1'b0) begin
        r_lfsr <= {r_lfsr[3:0], r_lfsr[3] ^ r_lfsr[2] ^ r_lfsr[0]};
      end
    end else begin
      arready <= 1'b0;
    end

    if (arvalid && arready) begin
      rdata   <= 32'b0;
      arready <= 1'b0;
      r_once  <= 1'b1;  // add this for test purpose
    end

    if (r_once) begin
      if (r_delay_cnt == r_lfsr) begin
        r_delay_cnt <= 5'b0;
        rvalid <= 1'b1;
        r_once <= 1'b0;
      end
      r_delay_cnt <= r_delay_cnt + 1;
    end

    if (rvalid && rready) begin
      rvalid <= 1'b0;
      rdata  <= 32'b0;
      r_done <= 1'b1;
    end
  end

endmodule
*/

module ysyx_24110012_vclint (
    input clk,

    // AR
    input wire [31:0] araddr,
    input wire arvalid,
    output reg arready,

    // R
    output reg [31:0] rdata,
    output reg rvalid,
    input wire rready,

    // AW
    input wire [31:0] awaddr,
    input wire awvalid,
    output reg awready,

    // W
    input reg [31:0] wdata,
    input wire [3:0] wstrb,
    input wire wvalid,
    output reg wready,

    // B
    output reg [1:0] bresp,
    output reg bvalid,
    input wire bready
);
  reg r_done, w_done;
  reg [31:0] awaddr_p;

`ifdef LFSR_SIM
  reg w_once;
  reg [4:0] wready_delay_cnt;
  reg [4:0] wready_lfsr = 5'b00101;  // wready_lfsr for random delay
`endif

  always @(posedge clk) begin
    w_done <= 1'b0;
`ifndef SYNTHESIS 
    assert (awaddr[1:0] == 2'b00)
    else $error("awaddr is %h not 4-byte aligned.", awaddr);
`endif

    if (awvalid) begin
      awaddr_p <= awaddr;
      awready  <= 1'b1;
    end else begin
      awready <= 1'b0;
    end

    if (wvalid) begin
`ifdef LFSR_SIM
      if (w_once == 1'b0) begin
        // skip the difftest when uart write happens since nemu does not suppor device as ref
        difftest_skip_ref();
        wready_lfsr <= {
          wready_lfsr[3:0], wready_lfsr[4] ^ wready_lfsr[3] ^ wready_lfsr[2] ^ wready_lfsr[0]
        };
      end
      w_once <= 1'b1;
      if (wready_delay_cnt == wready_lfsr) begin
        wready_delay_cnt <= 5'b0;
        wready <= 1'b1;
      end
      wready_delay_cnt <= wready_delay_cnt + 1;
`else
      wready <= 1'b1;
`endif
    end

    if (wready) begin
      bresp   <= 2'b00;  // OKAY response
      bvalid  <= 1'b1;  // indicate write response is valid
      wready  <= 1'b0;
      awready <= 1'b0;
    end else if (bready) begin
      wready <= 1'b0;
      bvalid <= 1'b0;  // clear bvalid when bready is asserted
      w_done <= 1'b1;
`ifdef LFSR_SIM
      w_once <= 1'b0;
`endif
    end
  end

  reg [31:0] araddr_p;
  reg [63:0] mtime;
`ifdef LFSR_SIM
  reg [4:0] r_delay_cnt;
  reg [4:0] r_lfsr = 5'b00011;
  reg r_once;
`endif

  // should not be used for uart read in current design
  always @(posedge clk) begin
    mtime  <= mtime + 1;
    r_done <= 1'b0;  // default not done
    if (arvalid) begin
      arready  <= 1'b1;
      araddr_p <= araddr;
`ifdef LFSR_SIM
      difftest_skip_ref();
      // generate new lfsr here assuming arvalid once high
      if (r_once == 1'b0) begin
        r_lfsr <= {r_lfsr[3:0], r_lfsr[3] ^ r_lfsr[2] ^ r_lfsr[0]};
      end
`endif
    end else begin
      arready <= 1'b0;
    end

    if (arvalid && arready) begin
      if (araddr_p[7:0] == 8'h0) begin
        rdata <= mtime[31:0];
      end else if (araddr_p[7:0] == 8'h04) begin
        rdata <= mtime[63:32];
      end else begin
        rdata <= 32'b0;
      end
      rvalid  <= 1'b1;
      arready <= 1'b0;
`ifdef LFSR_SIM
      r_once  <= 1'b1;  // add this for test purpose
`endif
    end

`ifdef LFSR_SIM
    if (r_once) begin
      if (r_delay_cnt == r_lfsr) begin
        r_delay_cnt <= 5'b0;
        rvalid <= 1'b1;
        r_once <= 1'b0;
      end
      r_delay_cnt <= r_delay_cnt + 1;
    end
`endif

    if (rvalid && rready) begin
      rvalid <= 1'b0;
      rdata <= 32'b0;
      r_done <= 1'b1;
      araddr_p <= 32'b0;
    end
  end

endmodule
