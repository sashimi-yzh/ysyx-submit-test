
module __sim_bus (
    input         clock,
    reset,
    output        fetch_port_aw_ready,
    input         fetch_port_aw_valid,
    input  [31:0] fetch_port_aw_addr,
    input  [ 3:0] fetch_port_aw_id,
    output        fetch_port_w_ready,
    input         fetch_port_w_valid,
    input  [31:0] fetch_port_w_data,
    input  [ 3:0] fetch_port_w_strb,
    input         fetch_port_w_last,
    fetch_port_b_ready,
    output        fetch_port_b_valid,
    output [ 3:0] fetch_port_b_id,
    output        fetch_port_ar_ready,
    input         fetch_port_ar_valid,
    input  [31:0] fetch_port_ar_addr,
    input  [ 3:0] fetch_port_ar_id,
    input  [ 7:0] fetch_port_ar_len,
    input  [ 2:0] fetch_port_ar_size,
    input         fetch_port_r_ready,
    output        fetch_port_r_valid,
    output [31:0] fetch_port_r_data,
    output        fetch_port_r_last,
    output [ 3:0] fetch_port_r_id,
    output [31:0] io_raddr,
    io_waddr,
    io_wdata,
    output [ 3:0] io_wmask,
    output        io_valid,
    io_wen,
    input  [31:0] io_rdata
);

  wire        fetch_port_r_last_0;
  reg         has_aw;
  reg         has_ar;
  wire        fire_ar_fire = fetch_port_ar_valid & ~has_ar;
  wire        fire_r_fire = fetch_port_r_ready & has_ar;
  wire        fire_r_burst_last = fetch_port_r_last_0 & fire_r_fire;
  wire        io_wen_0 = fetch_port_w_valid & has_aw;
  reg         has_w;
  reg  [31:0] burst_read_cnt;
  reg  [ 3:0] rid_r;
  reg  [31:0] raddr_r;
  assign fetch_port_r_last_0 = burst_read_cnt == 32'h0 & has_ar;
  reg  [ 3:0] wid_r;
  reg  [31:0] waddr_r;

  wire        fire_b_fire = fetch_port_b_ready & has_w;
  wire        fire_aw_fire = fetch_port_aw_valid & ~has_aw;
  always @(posedge clock) begin
    if (reset) begin
      has_ar <= 1'h0;
      has_aw <= 1'h0;
      has_w  <= 1'h0;
    end else begin
      has_ar <= fire_ar_fire | ~fire_r_burst_last & has_ar;
      has_aw <= fire_aw_fire | ~fire_b_fire & has_aw;
      has_w  <= fetch_port_w_last & io_wen_0 | ~fire_b_fire & has_w;
    end
    if (fire_ar_fire) begin
      burst_read_cnt <= {24'h0, fetch_port_ar_len};
      rid_r <= fetch_port_ar_id;
      raddr_r <= fetch_port_ar_addr + 32'h4;
    end else if (fire_r_fire) begin
      burst_read_cnt <= burst_read_cnt - 32'h1;
      raddr_r <= raddr_r + 32'h4;
    end
    if (fire_aw_fire) begin
      wid_r   <= fetch_port_aw_id;
      waddr_r <= fetch_port_aw_addr;
    end else if (io_wen_0) waddr_r <= waddr_r + 32'h4;
  end  // always @(posedge)
  assign fetch_port_aw_ready = ~has_aw;
  assign fetch_port_w_ready = has_aw;
  assign fetch_port_b_valid = has_w;
  assign fetch_port_b_id = wid_r;
  assign fetch_port_ar_ready = ~has_ar;
  assign fetch_port_r_valid = has_ar;
  assign fetch_port_r_data = io_rdata;
  assign fetch_port_r_last = fetch_port_r_last_0;
  assign fetch_port_r_id = rid_r;
  assign io_raddr = fire_ar_fire ? fetch_port_ar_addr : raddr_r;
  assign io_waddr = waddr_r;
  assign io_wdata = fetch_port_w_data;
  assign io_wmask = fetch_port_w_strb;
  assign io_valid = fire_ar_fire | ~fire_r_burst_last & fire_r_fire;
  assign io_wen = io_wen_0;
endmodule

