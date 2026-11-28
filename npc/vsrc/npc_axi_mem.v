module npc_axi_mem(
  input  clock,
  input  reset,
  output        awready, input awvalid, input [31:0] awaddr, input [3:0] awid,
  input  [7:0]  awlen,   input [2:0] awsize, input [1:0] awburst,
  output        wready,  input wvalid,  input [31:0] wdata, input [3:0] wstrb,
  input         wlast,
  input         bready,  output bvalid, output [1:0] bresp, output [3:0] bid,
  output        arready, input arvalid, input [31:0] araddr, input [3:0] arid,
  input  [7:0]  arlen,   input [2:0] arsize, input [1:0] arburst,
  input         rready,  output rvalid, output [1:0] rresp, output [31:0] rdata,
  output [3:0]  rid,     output rlast
);
  import "DPI-C" function void npc_mem_read(input int addr, output int data);
  import "DPI-C" function void npc_mem_write(input int addr, input int data, input byte strb);

  reg        aw_got = 1'b0, w_got = 1'b0, b_valid = 1'b0;
  reg [31:0] aw_addr; reg [3:0] aw_id;
  reg [31:0] w_data;  reg [7:0] w_strb;

  assign awready = !aw_got && !b_valid;
  assign wready  = !w_got  && !b_valid;
  assign bvalid  = b_valid;
  assign bresp   = 2'b00;
  assign bid     = aw_id;

  reg        r_busy = 1'b0, r_valid = 1'b0;
  reg [31:0] r_addr; reg [7:0] r_len; reg [3:0] r_id; reg [31:0] r_data;
  reg [31:0] rd_word;
  reg [2:0]  ar_size;
  reg [31:0] rd_mask;

  assign arready = !r_busy;
  assign rvalid  = r_valid;
  assign rdata   = r_data;
  assign rid     = r_id;
  assign rresp   = 2'b00;
  assign rlast   = (r_len == 8'd0);

  always @(*) begin
    case (ar_size)
      3'd0:    rd_mask = 32'h000000ff << {r_addr[1:0], 3'b000};
      3'd1:    rd_mask = 32'h0000ffff << {r_addr[1:0], 3'b000};
      default: rd_mask = 32'hffffffff;
    endcase
  end

  always @(posedge clock) begin
    if (reset) begin
      aw_got  <= 1'b0;
      w_got   <= 1'b0;
      b_valid <= 1'b0;
      r_busy  <= 1'b0;
      r_valid <= 1'b0;
    end else begin
      if (awvalid && awready) begin aw_got <= 1'b1; aw_addr <= awaddr; aw_id <= awid; end
      if (wvalid  && wready)  begin w_got  <= 1'b1; w_data  <= wdata;  w_strb <= {4'b0, wstrb}; end
      if (aw_got && w_got && !b_valid) begin
        npc_mem_write(aw_addr, w_data, w_strb);
        b_valid <= 1'b1;
        aw_got  <= 1'b0;
        w_got   <= 1'b0;
      end
      if (b_valid && bready) b_valid <= 1'b0;

      if (arvalid && arready) begin
        r_busy  <= 1'b1;
        r_addr  <= araddr;
        ar_size <= arsize;
        r_len   <= arlen;
        r_id    <= arid;
        r_valid <= 1'b0;
      end else if (r_busy) begin
        if (!r_valid) begin
          npc_mem_read(r_addr, rd_word);
          r_data  <= rd_word & rd_mask;
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
