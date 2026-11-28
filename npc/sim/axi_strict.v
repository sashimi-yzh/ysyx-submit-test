
module axi_strict #(
  parameter [31:0] BASE  = 32'h8000_0000,
  parameter        WORDS = 4*1024*1024
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

  reg [31:0] lfsr;
  always @(posedge clock) begin
    if (reset) lfsr <= 32'h1;
    else       lfsr <= {lfsr[30:0], lfsr[31] ^ lfsr[21] ^ lfsr[1] ^ lfsr[0]};
  end
  function [3:0] rnd4(input [31:0] v);
    rnd4 = {1'b0, v[3:0]} & 4'h7;
  endfunction

  reg        aw_got = 1'b0, w_got = 1'b0, b_valid = 1'b0;
  reg [31:0] aw_addr; reg [3:0] aw_id; reg [7:0] aw_len;
  reg [31:0] w_data;  reg [3:0] w_strb;
  reg [3:0]  aw_dly = 4'd1, w_dly = 4'd5, b_dly = 4'd1;
  reg [7:0]  w_beat = 8'd0;

  wire aw_ready_now = (aw_dly == 4'd0);
  wire w_ready_now  = (w_dly  == 4'd0);

  assign awready = aw_ready_now && !aw_got && !b_valid;
  assign wready  = w_ready_now  && !w_got  && !b_valid;
  assign bvalid  = b_valid;
  assign bresp   = 2'b00;
  assign bid     = aw_id;

  wire aw_is_mem  = (aw_addr[31:26] == 6'b100000);
  wire aw_is_uart = (aw_addr[31:2]  == 30'h0400_0000);

  always @(posedge clock) begin
    if (reset) begin
      aw_got <= 1'b0; w_got <= 1'b0; b_valid <= 1'b0;
      aw_dly <= 4'd1; w_dly <= 4'd5; b_dly <= 4'd1;
      w_beat <= 8'd0;
    end else begin
      if (aw_dly != 4'd0) aw_dly <= aw_dly - 4'd1;
      if (w_dly  != 4'd0) w_dly  <= w_dly  - 4'd1;
      if (b_dly  != 4'd0) b_dly  <= b_dly  - 4'd1;

      if (awvalid && awready) begin
        aw_got  <= 1'b1;
        aw_addr <= awaddr;
        aw_id   <= awid;
        aw_len  <= awlen;
        aw_dly  <= rnd4(lfsr) + 4'd1;
      end
      if (wvalid && wready) begin
        w_got  <= 1'b1;
        w_data <= wdata;
        w_strb <= wstrb;
        w_beat <= w_beat + 8'd1;
        w_dly  <= rnd4(lfsr) + 4'd2;
      end
      if (aw_got && w_got && !b_valid && (b_dly == 4'd0)) begin
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
        end
        b_valid <= 1'b1;
        aw_got  <= 1'b0;
        w_got   <= 1'b0;
        w_beat  <= 8'd0;
        b_dly   <= rnd4(lfsr) + 4'd1;
        aw_dly  <= rnd4(lfsr) + 4'd3;
        w_dly   <= rnd4(lfsr) + 4'd3;
      end
      if (b_valid && bready) b_valid <= 1'b0;
    end
  end

  reg        r_busy = 1'b0, r_valid = 1'b0;
  reg [31:0] r_addr; reg [7:0] r_len; reg [7:0] r_beat; reg [3:0] r_id;
  reg [3:0]  ar_dly = 4'd2, r_dly = 4'd1;

  assign arready = (ar_dly == 4'd0) && !r_busy;
  assign rvalid  = r_valid;
  assign rid     = r_id;
  assign rlast   = r_valid && (r_len == 8'd0);
  assign rresp   = 2'b00;

  wire r_is_mem  = (r_addr[31:26] == 6'b100000);
  wire r_is_boot0 = (r_addr == 32'h3000_0000);
  wire r_is_boot1 = (r_addr == 32'h3000_0004);
  wire [31:0] r_data_mux =
      r_is_boot0 ? 32'h800002B7 :
      r_is_boot1 ? 32'h00028067 :
      r_is_mem   ? mem[r_addr[25:2]] : 32'h0;

  assign rdata = r_data_mux;

  always @(posedge clock) begin
    if (reset) begin
      r_busy <= 1'b0; r_valid <= 1'b0; ar_dly <= 4'd2; r_dly <= 4'd1;
      r_addr <= 32'h0; r_len <= 8'd0; r_beat <= 8'd0; r_id <= 4'd0;
    end else begin
      if (ar_dly != 4'd0) ar_dly <= ar_dly - 4'd1;
      if (r_dly  != 4'd0) r_dly  <= r_dly  - 4'd1;

      if (arvalid && arready) begin
        r_busy  <= 1'b1;
        r_addr  <= araddr;
        r_len   <= arlen;
        r_beat  <= 8'd0;
        r_id    <= arid;
        r_valid <= 1'b0;
        ar_dly  <= rnd4(lfsr) + 4'd1;
        r_dly   <= rnd4(lfsr) + 4'd1;
      end else if (r_busy) begin
        if (!r_valid && (r_dly == 4'd0)) begin
          r_valid <= 1'b1;
        end else if (r_valid && rready) begin
          if (r_len == 8'd0) begin
            r_valid <= 1'b0;
            r_busy  <= 1'b0;
            r_dly   <= rnd4(lfsr) + 4'd1;
          end else begin
            r_addr  <= r_addr + 32'd4;
            r_len   <= r_len - 8'd1;
            r_beat  <= r_beat + 8'd1;
            r_valid <= 1'b0;
            r_dly   <= rnd4(lfsr) + 4'd1;
          end
        end
      end
    end
  end
endmodule


module axi_protocol_check(
  input clock,
  input reset,
  input        arvalid, input        arready,
  input [31:0] araddr,  input [7:0]  arlen,
  input [2:0]  arsize,  input [1:0]  arburst, input [3:0] arid,
  input        awvalid, input        awready,
  input [31:0] awaddr,  input [7:0]  awlen,
  input [2:0]  awsize,  input [1:0]  awburst,
  input        wvalid,  input        wready,
  input [31:0] wdata,   input [3:0]  wstrb,  input wlast,
  input        bvalid,  input        bready, input [3:0] bid,
  input        rvalid,  input        rready, input [3:0] rid
);
  integer viol = 0;
  task bad(input [1023:0] msg);
    begin
      viol = viol + 1;
      $display("[AXI-VIOLATION] %0s  @%0t", msg, $time);
      if (viol > 5) $finish;
    end
  endtask

  reg        arvalid_q = 1'b0, arready_q = 1'b0;
  reg [31:0] araddr_q = 32'h0; reg [7:0] arlen_q = 8'h0;
  reg [2:0]  arsize_q = 3'h0;  reg [1:0] arburst_q = 2'h0; reg [3:0] arid_q = 4'h0;

  reg        awvalid_q = 1'b0, awready_q = 1'b0;
  reg [31:0] awaddr_q = 32'h0; reg [7:0] awlen_q = 8'h0;
  reg [2:0]  awsize_q = 3'h0;  reg [1:0] awburst_q = 2'h0;

  reg        wvalid_q = 1'b0, wready_q = 1'b0;
  reg [31:0] wdata_q = 32'h0;  reg [3:0] wstrb_q = 4'h0; reg wlast_q = 1'b0;

  reg [7:0] w_cnt = 8'h0;
  reg [7:0] w_total = 8'h1;
  reg       w_open = 1'b0;

  wire [12:0] ar_last = {1'b0, araddr[11:0]} + (({1'b0, arlen} + 9'd1) << arsize) - 13'd1;
  wire [12:0] aw_last = {1'b0, awaddr[11:0]} + (({1'b0, awlen} + 9'd1) << awsize) - 13'd1;

  always @(posedge clock) begin
    if (!reset) begin
      // 1) VALID 拉高后到 READY 之前不能撤销
      if (arvalid_q && !arready_q && !arvalid)
        bad("ARVALID dropped before ARREADY");
      if (awvalid_q && !awready_q && !awvalid)
        bad("AWVALID dropped before AWREADY");
      if (wvalid_q && !wready_q && !wvalid)
        bad("WVALID dropped before WREADY");

      // 2) 握手前 payload 必须保持稳定
      if (arvalid_q && !arready_q) begin
        if (araddr !== araddr_q) bad("ARADDR changed before handshake");
        if (arlen  !== arlen_q)  bad("ARLEN changed before handshake");
        if (arsize !== arsize_q) bad("ARSIZE changed before handshake");
        if (arburst!== arburst_q)bad("ARBURST changed before handshake");
        if (arid   !== arid_q)   bad("ARID changed before handshake");
      end
      if (awvalid_q && !awready_q) begin
        if (awaddr !== awaddr_q) bad("AWADDR changed before handshake");
        if (awlen  !== awlen_q)  bad("AWLEN changed before handshake");
        if (awsize !== awsize_q) bad("AWSIZE changed before handshake");
        if (awburst!== awburst_q)bad("AWBURST changed before handshake");
      end
      if (wvalid_q && !wready_q) begin
        if (wdata !== wdata_q) bad("WDATA changed before handshake");
        if (wstrb !== wstrb_q) bad("WSTRB changed before handshake");
        if (wlast !== wlast_q) bad("WLAST changed before handshake");
      end

      // 3) 4KB 边界
      if (arvalid && arready && ar_last[12])
        bad("read burst crosses 4KB boundary");
      if (awvalid && awready && aw_last[12])
        bad("write burst crosses 4KB boundary");

      // 4) 突发类型与长度合法
      if (arvalid && arready && (arburst == 2'b00) && (arlen != 8'd0))
        bad("FIXED burst with len != 0");
      if (awvalid && awready && (awburst == 2'b00) && (awlen != 8'd0))
        bad("FIXED burst with len != 0");

      // 5) 写数据：我们的设计只有单拍写，WLAST 必须跟着每一拍
      if (wvalid && wready) begin
        if (!wlast) bad("WLAST not asserted on write beat");
      end

    end

    arvalid_q <= arvalid; arready_q <= arready;
    araddr_q  <= araddr;  arlen_q   <= arlen; arsize_q <= arsize;
    arburst_q <= arburst; arid_q    <= arid;
    awvalid_q <= awvalid; awready_q <= awready;
    awaddr_q  <= awaddr;  awlen_q   <= awlen; awsize_q <= awsize; awburst_q <= awburst;
    wvalid_q  <= wvalid;  wready_q  <= wready; wdata_q <= wdata; wstrb_q <= wstrb; wlast_q <= wlast;
  end
endmodule
