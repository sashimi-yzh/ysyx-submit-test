
module axi_mem #(
  parameter [31:0] BASE  = 32'h8000_0000,
  parameter        WORDS = 16*1024*1024      // 64MB
)(
  input  clock,
  input  reset,
  // AW
  output awready, input awvalid, input [31:0] awaddr, input [3:0] awid,
  input [7:0] awlen, input [2:0] awsize, input [1:0] awburst,
  // W
  output wready,  input wvalid,  input [31:0] wdata, input [3:0] wstrb, input wlast,
  // B
  input  bready,  output bvalid, output [1:0] bresp, output [3:0] bid,
  // AR
  output arready, input arvalid, input [31:0] araddr, input [3:0] arid,
  input [7:0] arlen, input [2:0] arsize, input [1:0] arburst,
  // R
  input  rready,  output rvalid, output [1:0] rresp, output [31:0] rdata,
  output [3:0] rid, output rlast
);

  reg [31:0] mem [0:WORDS-1];

  integer zi;
  initial begin
    for (zi = 0; zi < WORDS; zi = zi + 1) mem[zi] = 32'h0;
  end

  reg [9:0]  cyc_frac  = 10'd0;
  reg [63:0] uptime_us = 64'd0;
  always @(posedge clock) begin
    if (reset) begin
      cyc_frac  <= 10'd0;
      uptime_us <= 64'd0;
    end else if (cyc_frac == 10'd799) begin
      cyc_frac  <= 10'd0;
      uptime_us <= uptime_us + 64'd1;
    end else begin
      cyc_frac <= cyc_frac + 10'd1;
    end
  end

  // ---------------- 写 ----------------
  reg        aw_got = 1'b0, w_got = 1'b0, b_valid = 1'b0;
  reg [31:0] aw_addr; reg [3:0] aw_id;
  reg [31:0] w_data;  reg [3:0] w_strb;
  reg        warned = 1'b0;

  wire aw_is_mem  = (aw_addr[31:26] == 6'b100000);   // 0x8000_0000..0x83FF_FFFF
  wire aw_is_uart = (aw_addr[31:2]  == 30'h0400_0000);   // 0x1000_0000..0x1000_0003
  wire aw_is_rtc  = (aw_addr[31:3]  == 29'h0200_0006);   // 0x1000_0030..0x1000_0037

  assign awready = !aw_got && !b_valid;
  assign wready  = !w_got  && !b_valid;
  assign bvalid  = b_valid;
  assign bresp   = 2'b00;
  assign rresp   = 2'b00;
  assign bid     = aw_id;

  reg        r_busy = 1'b0, r_valid = 1'b0;
  reg [31:0] r_addr; reg [7:0] r_len; reg [3:0] r_id; reg [31:0] r_data;

  assign arready = !r_busy;
  assign rvalid  = r_valid;
  assign rdata   = r_data;
  assign rid     = r_id;
  assign rlast   = (r_len == 8'd0);

  wire r_is_mem  = (r_addr[31:26] == 6'b100000);
  wire r_is_rtc0 = (r_addr[31:2]  == 30'h0400_000C);   // 0x1000_0030
  wire r_is_rtc1 = (r_addr[31:2]  == 30'h0400_000D);   // 0x1000_0034

  wire r_is_boot0 = (r_addr == 32'h3000_0000);
  wire r_is_boot1 = (r_addr == 32'h3000_0004);

  wire [31:0] r_data_mux =
      r_is_boot0 ? 32'h800002B7 :
      r_is_boot1 ? 32'h00028067 :
      r_is_rtc0 ? uptime_us[31:0] :
      r_is_rtc1 ? uptime_us[63:32] :
      r_is_mem  ? mem[r_addr[25:2]] : 32'h0;

  always @(posedge clock) begin
    if (reset) begin
      aw_got <= 1'b0; w_got <= 1'b0; b_valid <= 1'b0;
      r_busy <= 1'b0; r_valid <= 1'b0;
      warned <= 1'b0;
    end else begin

      if (awvalid && awready) begin aw_got <= 1'b1; aw_addr <= awaddr; aw_id <= awid; end
      if (wvalid  && wready)  begin w_got  <= 1'b1; w_data  <= wdata;  w_strb <= wstrb; end
      if (aw_got && w_got && !b_valid) begin
        if (aw_is_uart) begin
          if (w_strb[0]) $write("%c", w_data[7:0]);
          if (w_strb[1]) $write("%c", w_data[15:8]);
          if (w_strb[2]) $write("%c", w_data[23:16]);
          if (w_strb[3]) $write("%c", w_data[31:24]);
        end else if (aw_is_mem) begin
          if (w_strb[0]) mem[aw_addr[25:2]][7:0]   <= w_data[7:0];
          if (w_strb[1]) mem[aw_addr[25:2]][15:8]  <= w_data[15:8];
          if (w_strb[2]) mem[aw_addr[25:2]][23:16] <= w_data[23:16];
          if (w_strb[3]) mem[aw_addr[25:2]][31:24] <= w_data[31:24];
        end else if (!aw_is_rtc && !warned) begin

          $display("[axi_mem] 未映射的写: 0x%08x = 0x%08x（已忽略）", aw_addr, w_data);
          warned <= 1'b1;
        end
        b_valid <= 1'b1;
        aw_got  <= 1'b0;
        w_got   <= 1'b0;
      end
      if (b_valid && bready) b_valid <= 1'b0;

      // --- 读通道 ---
      if (arvalid && arready) begin
        r_busy  <= 1'b1;
        r_addr  <= araddr;
        r_len   <= arlen;
        r_id    <= arid;
        r_valid <= 1'b0;
      end else if (r_busy) begin
        if (!r_valid) begin
          r_data  <= r_data_mux;
          r_valid <= 1'b1;
        end else if (rready) begin
          r_valid <= 1'b0;
          r_addr  <= r_addr + 32'd4;
          r_len   <= r_len - 8'd1;
          if (r_len == 8'd0) r_busy <= 1'b0;
        end
      end
    end
  end
endmodule
