module AXIMemory #(
  parameter RESET_VECTOR = 32'h8000_0000,
  parameter MEM_SIZE     = 32'h0800_0000
) (
  input         clock,
  input         reset,

  input         awvalid,
  output        awready,
  input  [31:0] awaddr,
  input  [ 3:0] awid,
  input  [ 7:0] awlen,
  input  [ 2:0] awsize,
  input  [ 1:0] awburst,

  input         wvalid,
  output        wready,
  input  [31:0] wdata,
  input  [ 3:0] wstrb,
  input         wlast,

  output        bvalid,
  input         bready,
  output [ 1:0] bresp,
  output [ 3:0] bid,

  input         arvalid,
  output        arready,
  input  [31:0] araddr,
  input  [ 3:0] arid,
  input  [ 7:0] arlen,
  input  [ 2:0] arsize,
  input  [ 1:0] arburst,

  output        rvalid,
  input         rready,
  output [ 1:0] rresp,
  output [31:0] rdata,
  output        rlast,
  output [ 3:0] rid
);

  localparam MEM_DEPTH = MEM_SIZE / 4;
  reg [31:0] mem [0:MEM_DEPTH-1];

  initial begin
    integer i;
    for (i = 0; i < MEM_DEPTH; i = i + 1) mem[i] = 32'h0;
    $readmemh("mem.hex", mem);
    $display("AXIMemory: range [%h, %h] (%0d KB)",
             RESET_VECTOR, RESET_VECTOR + MEM_SIZE - 1, MEM_SIZE / 1024);
  end

  function automatic [31:0] addr_to_idx(input [31:0] addr);
    addr_to_idx = (addr - RESET_VECTOR) >> 2;
  endfunction

  function automatic in_range(input [31:0] addr);
    in_range = (addr >= RESET_VECTOR) && (addr < RESET_VECTOR + MEM_SIZE);
  endfunction

  reg [31:0] w_addr;
  reg [ 3:0] w_id;

  assign awready = 1'b1;
  assign wready  = 1'b1;
  wire aw_fire = awvalid && awready;
  wire w_fire  = wvalid && wready;

  always @(posedge clock) begin
    if (reset) begin
      w_addr <= 0;
      w_id   <= 0;
    end else begin
      if (aw_fire) begin
        w_addr <= awaddr;
        w_id   <= awid;
      end
      if (w_fire && in_range(aw_fire ? awaddr : w_addr)) begin
        if (wstrb[0]) mem[addr_to_idx(aw_fire ? awaddr : w_addr)][ 7: 0] <= wdata[7:0];
        if (wstrb[1]) mem[addr_to_idx(aw_fire ? awaddr : w_addr)][15: 8] <= wdata[15:8];
        if (wstrb[2]) mem[addr_to_idx(aw_fire ? awaddr : w_addr)][23:16] <= wdata[23:16];
        if (wstrb[3]) mem[addr_to_idx(aw_fire ? awaddr : w_addr)][31:24] <= wdata[31:24];
      end
    end
  end

  reg b_valid_reg;
  assign bvalid = b_valid_reg;
  assign bresp  = 2'b00;
  assign bid    = w_id;

  always @(posedge clock) begin
    if (reset)
      b_valid_reg <= 0;
    else if (w_fire && wlast)
      b_valid_reg <= 1;
    else if (bvalid && bready)
      b_valid_reg <= 0;
  end

  reg [31:0] r_addr;
  reg [ 3:0] r_id;
  reg [ 7:0] r_len;
  reg [ 7:0] r_beat;
  reg [ 1:0] r_burst;

  assign arready = 1'b1;
  wire ar_fire = arvalid && arready;

  always @(posedge clock) begin
    if (reset) begin
      r_addr  <= 0;
      r_id    <= 0;
      r_len   <= 0;
      r_burst <= 0;
    end else if (ar_fire) begin
      r_addr  <= araddr;
      r_id    <= arid;
      r_len   <= arlen;
      r_burst <= arburst;
    end
  end

  reg r_valid_reg;
  reg [31:0] r_data_reg;
  reg r_last_reg;

  assign rvalid = r_valid_reg;
  assign rdata  = r_data_reg;
  assign rresp  = 2'b00;
  assign rlast  = r_last_reg;
  assign rid    = r_id;

  function automatic [31:0] next_r_addr(input [31:0] current, input [1:0] burst_type);
    next_r_addr = (burst_type == 2'b01) ? current + 4 : current;
  endfunction

  always @(posedge clock) begin
    if (reset) begin
      r_valid_reg <= 0;
      r_beat      <= 0;
    end else begin
      if (ar_fire) begin
        r_valid_reg <= 1;
        r_data_reg  <= in_range(araddr) ? mem[addr_to_idx(araddr)] : 32'h0;
        r_last_reg  <= (arlen == 0);
        r_beat      <= 0;
      end else if (rvalid && rready) begin
        if (r_last_reg) begin
          r_valid_reg <= 0;
        end else begin
          r_beat <= r_beat + 1;
          r_data_reg <= in_range(next_r_addr(r_addr + r_beat*4, r_burst))
                          ? mem[addr_to_idx(next_r_addr(r_addr + r_beat*4, r_burst))]
                          : 32'h0;
          r_last_reg <= (r_beat + 1 == r_len);
        end
      end
    end
  end

endmodule
