module LSU(
  input clk,
  input rst,

  input        req,
  input        wen,
  input  [2:0] f3,
  input [31:0] addr,
  input [31:0] wdata,
  output [31:0] rdata,
  output        done,

  // AXI4 AR
  output        lsu_arvalid,
  input         lsu_arready,
  output [31:0] lsu_araddr,
  output [3:0]  lsu_arid,
  output [7:0]  lsu_arlen,
  output [2:0]  lsu_arsize,
  output [1:0]  lsu_arburst,

  // AXI4 R
  input         lsu_rvalid,
  output        lsu_rready,
  input  [1:0]  lsu_rresp,
  input  [31:0] lsu_rdata,
  input         lsu_rlast,
  input  [3:0]  lsu_rid,

  // AXI4 AW
  output        lsu_awvalid,
  input         lsu_awready,
  output [31:0] lsu_awaddr,
  output [3:0]  lsu_awid,
  output [7:0]  lsu_awlen,
  output [2:0]  lsu_awsize,
  output [1:0]  lsu_awburst,

  // AXI4 W
  output        lsu_wvalid,
  input         lsu_wready,
  output [31:0] lsu_wdata,
  output [3:0]  lsu_wstrb,
  output        lsu_wlast,

  // AXI4 B
  input         lsu_bvalid,
  output        lsu_bready,
  input  [1:0]  lsu_bresp,
  input  [3:0]  lsu_bid
);

  localparam R_IDLE = 1'b0, R_WAIT = 1'b1;
  localparam W_IDLE = 1'b0, W_WAIT = 1'b1;

  reg r_state, w_state;
  reg aw_done, w_done;

  wire [1:0] size  = f3[1:0];
  wire [1:0] off = addr[1:0];

  assign lsu_arvalid = req && !wen && (r_state == R_IDLE) && !lsu_rvalid;
  assign lsu_araddr  = addr;
  assign lsu_arid    = 4'b0010;
  assign lsu_arlen   = 8'b0;
  assign lsu_arsize  = {1'b0, size};
  assign lsu_arburst = 2'b01;

  assign lsu_rready  = req && !wen;

  assign lsu_awvalid = req && wen && (w_state == W_IDLE) && !aw_done && !lsu_bvalid;
  assign lsu_awaddr  = addr;
  assign lsu_awid    = 4'b0010;
  assign lsu_awlen   = 8'b0;
  assign lsu_awsize  = {1'b0, size};
  assign lsu_awburst = 2'b01;

  assign lsu_wvalid  = req && wen && (w_state == W_IDLE) && !w_done && !lsu_bvalid;
  assign lsu_wlast   = lsu_wvalid;

  assign lsu_bready  = req && wen;

  assign done = req &&
                ((!wen && lsu_rvalid && lsu_rready && lsu_rlast) ||
                 ( wen && lsu_bvalid && lsu_bready));

  always @(posedge clk) begin
    if (rst) begin
      r_state <= R_IDLE;
      w_state <= W_IDLE;
      aw_done <= 1'b0;
      w_done  <= 1'b0;
    end else begin
      case (r_state)
        R_IDLE: if (lsu_arvalid && lsu_arready) r_state <= R_WAIT;
        R_WAIT: begin
          if (!req) r_state <= R_IDLE;
          else if (lsu_rvalid && lsu_rready && lsu_rlast) r_state <= R_IDLE;
        end
        default: r_state <= R_IDLE;
      endcase

      case (w_state)
        W_IDLE: begin
          if (lsu_awvalid && lsu_awready) aw_done <= 1'b1;
          if (lsu_wvalid  && lsu_wready)  w_done  <= 1'b1;
          if ((aw_done || (lsu_awvalid && lsu_awready)) &&
              (w_done  || (lsu_wvalid  && lsu_wready))) begin
            w_state <= W_WAIT;
            aw_done <= 1'b0;
            w_done  <= 1'b0;
          end
        end
        W_WAIT: begin
          if (!req) begin
            w_state <= W_IDLE;
            aw_done <= 1'b0;
            w_done  <= 1'b0;
          end else if (lsu_bvalid && lsu_bready) begin
            w_state <= W_IDLE;
          end
        end
        default: w_state <= W_IDLE;
      endcase
    end
  end

  // ---- load data extraction / extension ----
  wire [7:0]  byte_lane = lsu_rdata[8*off +: 8];
  wire [15:0] half_lane = off[1] ? lsu_rdata[31:16] : lsu_rdata[15:0];
  wire        is_unsigned = f3[2];

  reg [31:0] load_ext;
  always @(*) begin
    case (size)
      2'b00: load_ext = is_unsigned ? {24'b0, byte_lane}
                                    : {{24{byte_lane[7]}}, byte_lane};
      2'b01: load_ext = is_unsigned ? {16'b0, half_lane}
                                    : {{16{half_lane[15]}}, half_lane};
      default: load_ext = lsu_rdata;
    endcase
  end
  assign rdata = load_ext;

  // ---- store data alignment ----
  reg [31:0] store_data;
  reg [3:0]  store_strb;
  always @(*) begin
    case (size)
      2'b00: begin
        store_data = wdata << {off, 3'b000};
        store_strb = 4'b0001 << off;
      end
      2'b01: begin
        if (off[1]) begin
          store_data = wdata << 16;
          store_strb = 4'b1100;
        end else begin
          store_data = wdata;
          store_strb = 4'b0011;
        end
      end
      default: begin
        store_data = wdata;
        store_strb = 4'b1111;
      end
    endcase
  end
  assign lsu_wdata = store_data;
  assign lsu_wstrb = store_strb;

endmodule
