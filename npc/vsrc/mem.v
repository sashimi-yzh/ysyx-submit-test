`ifndef SYNTHESIS
import "DPI-C" function int npc_pmem_read(
  input int raddr, input byte rmask);
import "DPI-C" function void npc_pmem_write(
  input int waddr, input int wdata, input byte wmask);
`endif

module ysyx_24110012_mem (
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

reg w_once;
reg [31:0] awaddr_p;

reg [4:0] wready_delay_cnt;
reg [4:0] wready_lfsr = 5'b00101; // wready_lfsr for random delay

// mem write operation which requires all 4 byte aligned
always @(posedge clk) begin
`ifndef SYNTHESIS
  // assert (awaddr[1:0] == 2'b00) else
  //   $error("awaddr is %h not 4-byte aligned.", awaddr);
`endif

  if (awvalid) begin
    awaddr_p <= awaddr;
    awready <= 1'b1;
  end else begin
    awready <= 1'b0;
  end

  if (wvalid) begin
    if (w_once == 1'b0) begin
      npc_pmem_write(awaddr, wdata, {4'b0, wstrb});
      wready_lfsr <= {wready_lfsr[3:0], wready_lfsr[4] ^ wready_lfsr[3] ^wready_lfsr[2] ^ wready_lfsr[0]};
    end
    w_once <= 1'b1;
    if (wready_delay_cnt == wready_lfsr) begin
      wready_delay_cnt <= 5'b0;
      wready <= 1'b1;
    end
    wready_delay_cnt <= wready_delay_cnt + 1;
  end

  if(wready) begin
    bresp <= 2'b00; // OKAY response
    bvalid <= 1'b1; // indicate write response is valid
    wready <= 1'b0;
    awready <= 1'b0;
  end else if (bready) begin
    wready <= 1'b0;
    w_once <= 1'b0;
    bvalid <= 1'b0; // clear bvalid when bready is asserted
  end
end

reg [31:0] araddr_p;
reg [4:0] r_delay_cnt;
reg [4:0] r_lfsr = 5'b00011;
reg r_once;

// mem read operation only supports 4-byte aligned read
always @(posedge clk) begin

  if(arvalid) begin
    arready <= 1'b1;
    araddr_p <= araddr;
    // generate new lfsr here assuming arvalid once high
    if (r_once == 1'b0) begin
    r_lfsr <= {r_lfsr[3:0], r_lfsr[3] ^ r_lfsr[2] ^ r_lfsr[0]};
    end
  end else begin
    arready <= 1'b0;
  end

  if (arvalid && arready) begin
    rdata <= npc_pmem_read(araddr, {5'b0, 3'b111});
    arready <= 1'b0;
    r_once <= 1'b1;  // add this for test purpose
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
    rdata <= 32'b0;
  end
end

endmodule