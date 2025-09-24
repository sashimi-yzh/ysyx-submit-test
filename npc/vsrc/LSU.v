`ifdef __VERILATOR__
import "DPI-C" function void set_skip_ref_inst();
import "DPI-C" function void lsu_record0(
  int addr,
  int data,
  int delay
);
import "DPI-C" function void lsu_record1(
  int addr,
  int data,
  int mask,
  int delay
);
`endif

module ysyx_25010008_LSU (
    input clock,
    input reset,

    input suffix_b,
    input suffix_h,
    input sext,

    input ren,
    input wen,

    input [31:0] exu_pc,
    output reg [31:0] lsu_pc,

    input [31:0] addr,
    input [31:0] wsrc,
    input [31:0] exu_r_wdata,
    output reg [31:0] r_wdata,
    output reg block,

    input execute_valid,
    output reg ls_valid,

    output reg arvalid,
    output [31:0] araddr,
    output [2:0] arsize,
    input arready,

    output reg rready,
    input [31:0] rdata,
    input [1:0] rresp,
    input rvalid,

    output reg awvalid,
    output [31:0] awaddr,
    output [2:0] awsize,
    input awready,

    output reg wvalid,
    output [31:0] wdata,
    output [3:0] wstrb,
    input wready,

    output reg bready,
    input [1:0] bresp,
    input bvalid,

    input clear_pipeline,
    output reg load_addr_misaligned,
    output reg store_addr_misaligned
);

  reg ren_q, wen_q;
  reg [31:0] addr_q;
  reg suffix_b_q;
  reg suffix_h_q;
  reg sext_q;
  reg [31:0] wsrc_q;

  wire addr_misaligned = suffix_h_q ? (addr_q[1:0] == 3) : suffix_b_q ? 0 : addr_q[1:0] != 0;
  assign araddr = addr_q;
  assign arsize = suffix_b_q ? 0 : suffix_h_q ? 1 : 2;

  assign awaddr = addr_q;
  assign awsize = suffix_b_q ? 0 : suffix_h_q ? 1 : 2;

  assign wdata  = wsrc_q << {addr_q[1:0], 3'b0};
  assign wstrb  = (suffix_b_q ? 4'b0001 : (suffix_h_q ? 4'b0011 : 4'b1111)) << addr_q[1:0];

  wire [31:0] real_rdata = rdata >> {addr_q[1:0], 3'b0};
  wire [31:0] sextb = {{24{real_rdata[7]}}, real_rdata[7:0]};
  wire [31:0] sexth = {{16{real_rdata[15]}}, real_rdata[15:0]};
  wire [31:0] sign_data = suffix_b_q ? sextb : sexth;
  wire [31:0] extb = {24'b0, real_rdata[7:0]};
  wire [31:0] exth = {16'b0, real_rdata[15:0]};
  wire [31:0] unsign_data = suffix_b_q ? extb : (suffix_h_q ? exth : real_rdata);

`ifdef __VERILATOR__
  integer delay;
`endif

  always @(posedge clock) begin
    if (reset) begin
      arvalid <= 0;
      rready <= 0;

      awvalid <= 0;
      wvalid <= 0;
      bready <= 0;

      block <= 0;

      load_addr_misaligned <= 0;
      store_addr_misaligned <= 0;

`ifdef __VERILATOR__
      delay = 0;
`endif
    end else begin
      if (block) begin
        if (clear_pipeline) begin
          block <= 0;
          load_addr_misaligned <= 0;
          store_addr_misaligned <= 0;
        end else begin
          if (ren_q) begin
            ren_q <= 0;
            load_addr_misaligned <= addr_misaligned;
            arvalid <= addr_misaligned ? 0 : 1;
          end

          if (wen_q) begin
            wen_q <= 0;
            store_addr_misaligned <= addr_misaligned;
            // must assert in the same time for sdram axi
            awvalid <= addr_misaligned ? 0 : 1;
            wvalid <= addr_misaligned ? 0 : 1;
          end

`ifdef __VERILATOR__
          delay = delay + 1;
`endif
        end

        if (arvalid & arready) begin

`ifdef __VERILATOR__
          if (araddr[31:12] == 20'h1_0000 || araddr[31:24] == 8'h02 || araddr[31:12] == 20'h1_0001 || araddr[31:12] == 20'h1_0002 || araddr[31:12] == 20'h1_0011)
            set_skip_ref_inst();  //uart clint spi gpio ps2
`endif

          rready  <= 1;
          arvalid <= 0;
        end

        if (rready & rvalid) begin
          rready <= 0;
          r_wdata <= sext_q ? sign_data : unsign_data;
          block <= 0;
          ls_valid <= 1;

`ifdef __VERILATOR__
          lsu_record0(araddr, sext_q ? sign_data : unsign_data, delay);
          delay = 0;
`endif
        end

        if (awvalid & awready) begin

`ifdef __VERILATOR__
          if (awaddr[31:12] == 20'h1_0000 || araddr[31:12] == 20'h1_0001 || araddr[31:12] == 20'h1_0002 || araddr[31:24] == 8'h21)
            set_skip_ref_inst();  //uart spi gpio vga
`endif

          awvalid <= 0;
        end

        if (wvalid & wready) begin
          wvalid <= 0;
          bready <= 1;
        end

        if (bready & bvalid) begin
          bready <= 0;
          block <= 0;
          ls_valid <= 1;

`ifdef __VERILATOR__
          lsu_record1(araddr, wdata, {28'b0, wstrb}, delay);
          delay = 0;
`endif
        end
      end else begin
        addr_q <= addr;
        suffix_b_q <= suffix_b;
        suffix_h_q <= suffix_h;
        sext_q <= sext;
        wsrc_q <= wsrc;

        lsu_pc <= exu_pc;
        r_wdata <= exu_r_wdata;

        ren_q <= ren;
        wen_q <= wen;

        ls_valid <= (clear_pipeline | ren | wen) ? 0 : execute_valid;
        block <= (ren | wen) & !clear_pipeline;
      end
    end
  end

endmodule
