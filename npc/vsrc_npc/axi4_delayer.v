module axi4_delayer(
    input           clock,
    input           reset,

    output          in_arready,
    input           in_arvalid,
    input   [3:0]   in_arid,
    input   [31:0]  in_araddr,
    input   [7:0]   in_arlen,
    input   [2:0]   in_arsize,
    input   [1:0]   in_arburst,
    input           in_rready,
    output          in_rvalid,
    output  [3:0]   in_rid,
    output  [31:0]  in_rdata,
    output  [1:0]   in_rresp,
    output          in_rlast,
    output          in_awready,
    input           in_awvalid,
    input   [3:0]   in_awid,
    input   [31:0]  in_awaddr,
    input   [7:0]   in_awlen,
    input   [2:0]   in_awsize,
    input   [1:0]   in_awburst,
    output          in_wready,
    input           in_wvalid,
    input   [31:0]  in_wdata,
    input   [3:0]   in_wstrb,
    input           in_wlast,
                    in_bready,
    output          in_bvalid,
    output  [3:0]   in_bid,
    output  [1:0]   in_bresp,

    input           out_arready,
    output          out_arvalid,
    output  [3:0]   out_arid,
    output  [26:0]  out_araddr,
    output  [7:0]   out_arlen,
    output  [2:0]   out_arsize,
    output  [1:0]   out_arburst,
    output          out_rready,
    input           out_rvalid,
    input   [3:0]   out_rid,
    input   [31:0]  out_rdata,
    input   [1:0]   out_rresp,
    input           out_rlast,
    input           out_awready,
    output          out_awvalid,
    output  [3:0]   out_awid,
    output  [26:0]  out_awaddr,
    output  [7:0]   out_awlen,
    output  [2:0]   out_awsize,
    output  [1:0]   out_awburst,
    input           out_wready,
    output          out_wvalid,
    output  [31:0]  out_wdata,
    output  [3:0]   out_wstrb,
    output          out_wlast,
                    out_bready,
    input           out_bvalid,
    input   [3:0]   out_bid,
    input   [1:0]   out_bresp,

    input           uart_awready,
    output          uart_awvalid,
    output  [3:0]   uart_awid,
    output  [26:0]  uart_awaddr,
    output  [7:0]   uart_awlen,
    output  [2:0]   uart_awsize,
    output  [1:0]   uart_awburst,
    input           uart_wready,
    output          uart_wvalid,
    output  [31:0]  uart_wdata,
    output  [3:0]   uart_wstrb,
    output          uart_wlast,
                    uart_bready,
    input           uart_bvalid,
    input   [3:0]   uart_bid,
    input   [1:0]   uart_bresp
);

    wire addr = (in_awaddr[31:28] == 4'ha);

    assign  in_arready = out_arready; // 地址不用等，读通道不用分
    assign  out_arvalid = in_arvalid;
    assign  out_arid = in_arid;
    assign  out_araddr = in_araddr[26:0];
    assign  out_arlen = in_arlen;
    assign  out_arsize = in_arsize;
    assign  out_arburst = in_arburst;
    assign  in_rresp = out_rresp;

    assign  in_awready  = (addr == 1'b1) ? uart_awready : out_awready;
    assign  out_awvalid = (addr == 1'b1) ? 0 : in_awvalid;
    assign  uart_awvalid = (addr == 1'b1) ? in_awvalid : 0;

    assign  out_awid    = (addr == 1'b1) ? 0 : in_awid;
    assign  uart_awid   = (addr == 1'b1) ? in_awid : 0;

    assign  out_awaddr  = (addr == 1'b1) ? 0 : in_awaddr[26:0];
    assign  uart_awaddr = (addr == 1'b1) ? in_awaddr[26:0] : 0;

    assign  out_awlen   = in_awlen;
    assign  uart_awlen  = in_awlen;
    
    assign  out_awsize  = in_awsize;
    assign  uart_awsize = in_awsize;

    assign  out_awburst = in_awburst;
    assign  uart_awburst = in_awburst;

    assign  in_wready   = out_wready || uart_wready;

    assign  out_wvalid  = in_wvalid;
    assign  uart_wvalid = in_wvalid;  

    assign  out_wdata   = in_wdata;
    assign  out_wstrb   = in_wstrb;
    assign  out_wlast   = in_wlast;

    assign  uart_wdata   = in_wdata;
    assign  uart_wstrb   = in_wstrb;
    assign  uart_wlast   = in_wlast;

    // read
    reg   [31:0]    total_read_0;
    reg   [31:0]    counter_read_0;

    reg   [31:0]    total_read_1;
    reg   [31:0]    counter_read_1;

    // write
    reg   [31:0]    total_wr;
    reg   [31:0]    counter_wr;

    localparam  R   = 4;

    localparam  IDLE_READ       = 0;
    localparam  WAIT_OUT_RREADY = 2;
    localparam  BACK_READ       = 1;

    localparam  IDLE_READ1      = 0;
    localparam  WAIT_OUT_RREADY1 = 2;
    localparam  BACK_READ1      = 1;

    localparam  IDLE_WR         = 0;
    localparam  WAIT_OUT_BREADY = 2;
    localparam  BACK_WR         = 1;

    reg   [31:0]  latency_read  [7:0];
    reg   [31:0]  fifo_rdata    [7:0];
    reg   [3:0]   fifo_rid      [7:0];
    reg   [0:0]   fifo_rlast    [7:0];

    reg   [2:0]   wpt_r;
    reg   [2:0]   rpt_r;
    reg   [1:0]   current_read;
    reg   [1:0]   next_read;
    reg   [1:0]   state_rd_1;
    reg   [1:0]   state_wr;

  always @(posedge clock) begin
    if(reset) begin
      current_read  <= IDLE_READ;
    end
    else begin
      current_read  <= next_read;
    end
  end

  always @(*) begin // rid = 0
    case(current_read)
      IDLE_READ: begin // address 
        if(in_arvalid == 1'b1 && in_arid == 4'h0) begin
          next_read    = WAIT_OUT_RREADY;
        end
        else begin
          next_read    = IDLE_READ;
        end
      end

      WAIT_OUT_RREADY: begin
        if(out_rlast == 1'b1 && out_rvalid == 1'b1 && out_rready == 1'b1 && out_rid == 4'h0) begin
          next_read    = BACK_READ;
        end
        else begin
          next_read    = WAIT_OUT_RREADY;
        end
      end

      BACK_READ: begin
        if(in_rlast == 1'b1 && in_rvalid == 1'b1 && in_rready == 1'b1 && in_rid == 4'h0) begin
          next_read    = IDLE_READ;
        end
        else begin
          next_read    = BACK_READ;
        end
      end

      default: begin
        next_read   = IDLE_READ;
      end
    endcase
  end

  always @(posedge clock) begin // rid = 1
    if(reset) begin
      state_rd_1    <= IDLE_READ1;
    end
    else begin
      case(state_rd_1)

        IDLE_READ1: begin
          if(in_arvalid == 1'b1 && in_arid == 4'h1) begin
            state_rd_1    <= WAIT_OUT_RREADY1;
          end
          else begin
            state_rd_1    <= IDLE_READ1;
          end 
        end

        WAIT_OUT_RREADY1: begin
          if(out_rlast == 1'b1 && out_rvalid == 1'b1 && out_rready == 1'b1 && out_rid == 4'h1) begin
            state_rd_1    <= BACK_READ1;
          end
          else begin
            state_rd_1    <= WAIT_OUT_RREADY1;
          end
        end

        BACK_READ1: begin
          if(in_rlast == 1'b1 && in_rvalid == 1'b1 && in_rready == 1'b1 && in_rid == 4'h1) begin
            state_rd_1    <= IDLE_READ1;
          end
          else begin
            state_rd_1    <= BACK_READ1;
          end
        end

        default: begin
          state_rd_1    <= IDLE_READ1;
        end
      endcase
    end
  end

  always @(posedge clock) begin
    if(reset) begin
      wpt_r   <= 3'h0;
    end
    else begin
      if(out_rvalid && out_rready) begin
        wpt_r               <= wpt_r + 1;
        fifo_rdata[wpt_r]   <= out_rdata;
        latency_read[wpt_r] <= (out_rid == 4'h0) ? total_read_0 : total_read_1; // 时间
        fifo_rid[wpt_r]     <= out_rid;
        fifo_rlast[wpt_r]   <= out_rlast;
      end
    end
  end

  wire  [31:0]  counter_read;
  wire  [1:0]   state;

  always @(posedge clock) begin
    if(reset) begin
      rpt_r   <= 3'h0;
    end
    else begin
      if((in_rvalid && in_rready) && (state == BACK_READ)) begin
        rpt_r <= rpt_r + 1;
      end
    end
  end

  always @(posedge clock) begin
    if(rpt_r == wpt_r + 1) begin
      $display("%h, %h", rpt_r, wpt_r);
      $stop;
    end
  end

  assign  counter_read  = (fifo_rid[rpt_r] == 4'h0) ? counter_read_0 : counter_read_1;
  assign  state         = (fifo_rid[rpt_r] == 4'h0) ? current_read : state_rd_1;
  assign  in_rdata    = fifo_rdata[rpt_r];
  assign  in_rvalid   = (latency_read[rpt_r] <= counter_read) && (state == BACK_READ);
  assign  in_rid      = fifo_rid[rpt_r];
  assign  in_rlast    = ((latency_read[rpt_r] <= counter_read) && (state == BACK_READ)) ? fifo_rlast[rpt_r] : 1'b0;
  assign  out_rready  = (current_read == WAIT_OUT_RREADY) || (state_rd_1 == WAIT_OUT_RREADY1);

  always @(posedge clock) begin
    if(reset) begin
      total_read_0    <= 32'h0;
      counter_read_0  <= 32'h0;
    end
    else begin
      if(current_read == WAIT_OUT_RREADY) begin
        total_read_0     <= total_read_0 + R;
        counter_read_0   <= counter_read_0 + 1;
      end
      else if(current_read == BACK_READ) begin
        if(counter_read_0 == total_read_0) begin
          counter_read_0   <= counter_read_0;
          total_read_0     <= total_read_0;
        end
        else begin
          counter_read_0   <= counter_read_0 + 1;
          total_read_0     <= total_read_0;
        end
      end
      else if (current_read == IDLE_READ) begin
        total_read_0   <= 32'h0;
        counter_read_0 <= 32'h0;
      end
    end
  end

  always @(posedge clock) begin // rid = 1
    if(reset) begin
      total_read_1    <= 32'h0;
      counter_read_1  <= 32'h0;
    end
    else begin
      if(state_rd_1 == WAIT_OUT_RREADY1) begin
        total_read_1     <= total_read_1 + R;
        counter_read_1   <= counter_read_1 + 1;
      end
      else if(state_rd_1 == BACK_READ) begin
        if(counter_read_1 == total_read_1) begin
          counter_read_1   <= counter_read_1;
          total_read_1     <= total_read_1;
        end
        else begin
          counter_read_1   <= counter_read_1 + 1;
          total_read_1     <= total_read_1;
        end
      end
      else if (state_rd_1 == IDLE_READ1) begin
        total_read_1   <= 32'h0;
        counter_read_1 <= 32'h0;
      end
    end
  end

  reg   [31:0]  latency_wr;
  reg   [1:0]   fifo_bresp;
  reg   [3:0]   fifo_bid;

  always @(posedge clock) begin
    if(reset) begin
      state_wr    <= IDLE_WR;
    end 
    else begin
      case(state_wr)
        IDLE_WR: begin
          if(in_awvalid) begin
            state_wr    <= WAIT_OUT_BREADY;
          end
          else begin
            state_wr    <= IDLE_WR;
          end 
        end

        WAIT_OUT_BREADY: begin
          if(out_bvalid || uart_bvalid) begin
            state_wr    <= BACK_WR;
          end
          else begin
            state_wr    <= WAIT_OUT_BREADY;
          end
        end

        BACK_WR: begin
          if(in_bvalid && in_bready) begin
            state_wr    <= IDLE_WR;
          end
          else begin
            state_wr    <= BACK_WR;
          end
        end

        default: begin
          state_wr    <= IDLE_WR;
        end

      endcase
    end
  end

  always @(posedge clock) begin
    if(reset) begin
      total_wr    <= 32'h0;
      counter_wr  <= 32'h0;
    end
    else begin
      if(state_wr == WAIT_OUT_BREADY) begin
        total_wr     <= total_wr + R;
        counter_wr   <= counter_wr + 1;
      end

      else if(state_wr == BACK_WR) begin
        if(counter_wr == total_wr) begin
          total_wr     <= total_wr;
          counter_wr   <= counter_wr;
        end
        else begin
          total_wr     <= total_wr;
          counter_wr   <= counter_wr + 1;
        end
      end

      else if (state_wr == IDLE_WR) begin
        total_wr   <= 32'h0;
        counter_wr <= 32'h0;
      end
    end
  end

  always @(posedge clock) begin
    if(reset == 1'b1 || state_wr == IDLE_WR) begin
      latency_wr    <= 0;
    end
    else begin 
      if((out_bvalid && out_bready) || (uart_bvalid && uart_bready)) begin
        fifo_bresp   <= (out_bresp | uart_bresp);
        latency_wr   <= total_wr;
        fifo_bid     <= (out_bid | uart_bid);
      end
    end
  end

  assign  in_bresp    = fifo_bresp;
  assign  in_bvalid   = (latency_wr <= counter_wr) && (counter_wr != 0);
  assign  in_bid      = fifo_bid;
  assign  out_bready  = (state_wr == WAIT_OUT_BREADY);
  assign  uart_bready = (state_wr == WAIT_OUT_BREADY);


endmodule
