module axi4_delayer(
  input         clock,
  input         reset,

  output        in_arready,
  input         in_arvalid,
  input  [3:0]  in_arid,
  input  [31:0] in_araddr,
  input  [7:0]  in_arlen,
  input  [2:0]  in_arsize,
  input  [1:0]  in_arburst,
  input         in_rready,
  output        in_rvalid,
  output [3:0]  in_rid,
  output [31:0] in_rdata,
  output [1:0]  in_rresp,
  output        in_rlast,
  output        in_awready,
  input         in_awvalid,
  input  [3:0]  in_awid,
  input  [31:0] in_awaddr,
  input  [7:0]  in_awlen,
  input  [2:0]  in_awsize,
  input  [1:0]  in_awburst,
  output        in_wready,
  input         in_wvalid,
  input  [31:0] in_wdata,
  input  [3:0]  in_wstrb,
  input         in_wlast,
                in_bready,
  output        in_bvalid,
  output [3:0]  in_bid,
  output [1:0]  in_bresp,

  input         out_arready,
  output        out_arvalid,
  output [3:0]  out_arid,
  output [31:0] out_araddr,
  output [7:0]  out_arlen,
  output [2:0]  out_arsize,
  output [1:0]  out_arburst,
  output        out_rready,
  input         out_rvalid,
  input  [3:0]  out_rid,
  input  [31:0] out_rdata,
  input  [1:0]  out_rresp,
  input         out_rlast,
  input         out_awready,
  output        out_awvalid,
  output [3:0]  out_awid,
  output [31:0] out_awaddr,
  output [7:0]  out_awlen,
  output [2:0]  out_awsize,
  output [1:0]  out_awburst,
  input         out_wready,
  output        out_wvalid,
  output [31:0] out_wdata,
  output [3:0]  out_wstrb,
  output        out_wlast,
                out_bready,
  input         out_bvalid,
  input  [3:0]  out_bid,
  input  [1:0]  out_bresp
);

  // assign out_arvalid = in_arvalid;
  // assign out_arid    = in_arid;
  // assign out_araddr  = in_araddr;
  // assign out_arlen   = in_arlen;
  // assign out_arsize  = in_arsize;
  // assign out_arburst = in_arburst;
  // assign in_arready  = out_arready;

  // assign in_rvalid = out_rvalid;
  // assign in_rid    = out_rid;
  // assign in_rdata  = out_rdata;
  // assign in_rresp  = out_rresp;
  // assign in_rlast  = out_rlast;
  // assign out_rready = in_rready;

  // assign out_awvalid = in_awvalid;
  // assign out_awid    = in_awid;
  // assign out_awaddr  = in_awaddr;
  // assign out_awlen   = in_awlen;
  // assign out_awsize  = in_awsize;
  // assign out_awburst = in_awburst;
  // assign in_awready  = out_awready;

  // assign out_wvalid = in_wvalid;
  // assign out_wdata  = in_wdata;
  // assign out_wstrb  = in_wstrb;
  // assign out_wlast  = in_wlast;
  // assign in_wready  = out_wready;

  // assign in_bvalid = out_bvalid;
  // assign in_bid    = out_bid;
  // assign in_bresp  = out_bresp;
  // assign out_bready = in_bready;

  // Fmax: 502MHz, Perip: 100MHz, r = 5.02
  // set s = 32, r*s = 160.64 -> 161
  // wait perip resp: counter 每周期加(r-1)*s=128.64，取整为129
  // wait apb delayer done: counter先/s = 129/32*k, 每周期-1

  localparam delay_cnt = 129;
  
  localparam AR_IDLE      = 2'b00;
  localparam AR_WAIT      = 2'b01;
  localparam R_WAIT       = 2'b10;
  localparam R_DELAY      = 2'b11;

  localparam AW_IDLE      = 2'b00;
  localparam AW_WAIT      = 2'b01;
  localparam W_WAIT       = 2'b10;
  localparam W_DELAY      = 2'b11;

  reg [ 1:0] r_state;
  reg [31:0] r_counter;
  reg [31:0] r_burst_num;
  reg        r_burst_start;
  reg        r_burst_end;
  reg [31:0] r_burst_counter;

  reg [ 1:0] w_state;
  reg [31:0] w_counter;
  reg [31:0] w_burst_num;
  reg        w_burst_start;
  reg        w_burst_end;
  reg [31:0] w_burst_counter;

  reg  [33:0] r_req_data;
  wire [33:0] r_req_out;

  reg  [ 1:0] w_req_data;
  wire [ 1:0] w_req_out;

  fifo
  #(
    .WIDTH   (34),
    .DEPTH   (8),
    .ADDR_W  (3)
  ) u_requests (
    .clk_i    (clock),
    .rst_i    (reset),
    .data_in_i (r_req_data),
    .push_i   (out_rvalid),
    .pop_i    (in_rvalid),
    .data_out_o (r_req_out),
    .accept_o (),
    .valid_o  ()
  );
  fifo
  #(
    .WIDTH   (2),
    .DEPTH   (8),
    .ADDR_W  (3)
  ) u_response (
    .clk_i    (clock),
    .rst_i    (reset),
    .data_in_i (w_req_data),
    .push_i   (out_wvalid),
    .pop_i    (in_wvalid),
    .data_out_o (w_req_out),
    .accept_o (),
    .valid_o  ()
  );

  always @(*) begin
    r_req_data = {out_rresp, out_rdata};
    w_req_data = {out_bresp};
  end

  assign out_arid     = in_arid;
  assign out_araddr   = in_araddr;
  assign out_arlen    = in_arlen;
  assign out_arsize   = in_arsize;
  assign out_arburst  = in_arburst;
  assign out_arvalid  = (r_state == AR_WAIT) ? in_arvalid : 1'b0;
  assign in_arready   = (r_state == R_WAIT) ? 1'b1 : 1'b0;
  
  assign out_rready   = in_rready;
  assign in_rid       = out_rid;
  assign in_rdata     = r_req_out[31: 0];
  assign in_rresp     = r_req_out[33:32];
  assign in_rlast     = (r_state == R_DELAY && r_counter == 32'b1 && r_burst_num == 32'b1) ? 1'b1 : 1'b0;
  assign in_rvalid    = (r_state == R_DELAY && r_counter == 32'b1) ? 1'b1 : 1'b0;
  
  assign out_awid     = in_awid;
  assign out_awaddr   = in_awaddr;
  assign out_awlen    = in_awlen;
  assign out_awsize   = in_awsize;
  assign out_awburst  = in_awburst;
  assign out_awvalid  = (w_state == AW_WAIT) ? in_awvalid : 1'b0;
  assign in_awready   = (w_state == W_WAIT) ? 1'b1 : 1'b0;
  assign out_wdata    = in_wdata;
  assign out_wstrb    = in_wstrb;
  assign out_wlast    = in_wlast;
  assign out_wvalid   = (w_state == AW_WAIT) ? in_wvalid : 1'b0;
  assign in_wready    = (w_state == W_WAIT) ? 1'b1 : 1'b0;
  
  assign out_bready   = in_bready;
  assign in_bid       = out_bid;
  assign in_bresp     = w_req_out[1:0];
  assign in_bvalid    = (w_state == W_DELAY && w_counter == 32'b1) ? 1'b1 : 1'b0;

  always @(posedge clock) begin
    if (reset) begin
      r_state <= AR_IDLE;
      r_counter <= 32'b0;
    end else begin
      case (r_state)
        AR_IDLE: begin
          if (in_arvalid) begin
            r_state <= AR_WAIT;
            r_counter <= r_counter + delay_cnt;
          end
        end
        AR_WAIT: begin
          if (out_arready) begin
            r_state <= R_WAIT;
          end
          r_counter <= r_counter + delay_cnt;
        end
        R_WAIT: begin
          if (out_rlast & out_rvalid) begin
            r_state <= R_DELAY;
            r_burst_num <= r_burst_num + 32'b1;
            r_counter <= (r_counter + delay_cnt) >> 5;
            r_burst_counter <= (r_burst_counter + delay_cnt) >> 5;
          end else begin
            if(out_rvalid) begin
              r_burst_start <= 1'b1;
              r_burst_end <= r_burst_start ? 1'b1 : 1'b0;
              r_burst_num <= r_burst_num + 32'b1;
            end
            r_burst_counter <= (r_burst_start ^ r_burst_end) ? r_burst_counter + delay_cnt : r_burst_counter;
            r_counter <= r_burst_start ? r_counter : r_counter + delay_cnt;
          end
        end
        R_DELAY: begin
          if (r_counter == 32'b1) begin
            if(r_burst_num == 32'b1) begin
              r_state <= AR_IDLE;
              r_burst_num <= 32'b0;
              r_counter <= 32'b0;
              r_burst_counter <= 32'b0;
              r_burst_start <= 1'b0;
              r_burst_end <= 1'b0;
            end else begin
              r_burst_num <= r_burst_num - 32'b1;
              r_counter <= r_burst_counter;
            end
          end else begin
            r_counter <= r_counter - 1'b1;
          end
        end
        default: r_state <= AR_IDLE;
      endcase
    end
  end

  always @(posedge clock) begin
    if (reset) begin
      w_state <= AW_IDLE;
      w_counter <= 32'b0;
    end else begin
      case (w_state)
        AW_IDLE: begin
          if (in_awvalid) begin
            w_state <= AW_WAIT;
            w_counter <= w_counter + delay_cnt;
          end
        end
        AW_WAIT: begin
          w_counter <= w_counter + delay_cnt;
          if (out_awready) begin
            w_state <= W_WAIT;
          end
          w_counter <= w_counter + delay_cnt;
        end
        W_WAIT: begin
          if (out_bvalid) begin
            w_state <= W_DELAY;
            w_counter <= (w_counter + delay_cnt) >> 5;
          end else begin
            w_counter <= w_counter + delay_cnt;
          end
        end
        W_DELAY: begin
          if (w_counter == 32'b1) begin
            if (in_wlast) begin
              w_state <= AW_IDLE;
              w_counter <= 32'b0;
            end else begin
              w_state <= W_WAIT;
              w_counter <= 32'b0;
            end
          end else begin
            w_counter <= w_counter - 1'b1;
          end
        end
        default: w_state <= AW_IDLE;
      endcase
    end
  end

endmodule

module fifo
#(
  parameter WIDTH   = 32,
  parameter DEPTH   = 8,
  parameter ADDR_W  = 3
) (
   input               clk_i
  ,input               rst_i
  ,input  [WIDTH-1:0]  data_in_i
  ,input               push_i
  ,input               pop_i

  ,output [WIDTH-1:0]  data_out_o
  ,output              accept_o
  ,output              valid_o
);

localparam COUNT_W = ADDR_W + 1;

reg [WIDTH-1:0]         ram [DEPTH-1:0];
reg [ADDR_W-1:0]        rd_ptr;
reg [ADDR_W-1:0]        wr_ptr;
reg [COUNT_W-1:0]       count;

always @ (posedge clk_i or posedge rst_i)
if (rst_i)
begin
    count   <= {(COUNT_W) {1'b0}};
    rd_ptr  <= {(ADDR_W) {1'b0}};
    wr_ptr  <= {(ADDR_W) {1'b0}};
end
else
begin
    if (push_i & accept_o)
    begin
      ram[wr_ptr] <= data_in_i;
      wr_ptr      <= wr_ptr + 1;
    end

    if (pop_i & valid_o)
      rd_ptr      <= rd_ptr + 1;

    if ((push_i & accept_o) & ~(pop_i & valid_o))
        count <= count + 1;
    else if (~(push_i & accept_o) & (pop_i & valid_o))
        count <= count - 1;
end

assign accept_o   = (count != DEPTH);
assign valid_o    = (count != 0);

assign data_out_o = ram[rd_ptr];

endmodule
