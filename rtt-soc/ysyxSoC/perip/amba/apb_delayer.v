module apb_delayer(
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  output [31:0] out_paddr,
  output        out_psel,
  output        out_penable,
  output [2:0]  out_pprot,
  output        out_pwrite,
  output [31:0] out_pwdata,
  output [3:0]  out_pstrb,
  input         out_pready,
  input  [31:0] out_prdata,
  input         out_pslverr
);

  // assign out_paddr  = in_paddr;
  // assign out_psel   = in_psel;
  // assign out_penable = in_penable;
  // assign out_pprot  = in_pprot;
  // assign out_pwrite = in_pwrite;
  // assign out_pwdata = in_pwdata;
  // assign out_pstrb  = in_pstrb;

  // assign in_pready  = out_pready;
  // assign in_prdata  = out_prdata;
  // assign in_pslverr = out_pslverr;

  localparam IDLE  = 2'b00;
  localparam WAIT  = 2'b01;
  localparam DELAY = 2'b10;

  reg [ 1:0] state;
  reg [31:0] counter;
  reg [31:0] prdata_r;
  reg pslverr_r;

  assign out_paddr   = in_paddr;
  assign out_psel    = in_psel && state != DELAY;
  assign out_penable = in_penable;
  assign out_pprot   = in_pprot;
  assign out_pwrite  = in_pwrite;
  assign out_pwdata  = in_pwdata;
  assign out_pstrb   = in_pstrb;
  // assign in_pready   = out_pready;
  // assign in_prdata   = out_prdata;
  // assign in_pslverr  = out_pslverr;

  // Fmax: 502MHz, Perip: 100MHz, r = 5.02
  // set s = 32, r*s = 160.64 -> 161
  // wait perip resp: counter 每周期加(r-1)*s=128.64，取整为129
  // wait apb delayer done: counter先/s = 129/32*k, 每周期-1

  localparam delay_cnt = 129;

  always @(posedge clock) begin
    if(reset) begin
      state <= IDLE;
      counter <= 32'b0;
    end else begin
      case(state)
        IDLE: begin
          if(in_psel) begin
            state <= WAIT;
            counter <= counter + delay_cnt;
          end
        end
        WAIT: begin
          if(out_pready) begin
            state <= DELAY;
            counter <= (counter + delay_cnt) >> 5;
          end else begin
            counter <= counter + delay_cnt;
          end
        end
        DELAY: begin
          if(counter == 32'b1) begin
            state <= IDLE;
            counter <= 32'b0;
          end else begin
            counter <= counter - 1'b1;
          end
        end
        default: state <= IDLE;
      endcase
    end
  end

  always @(posedge clock) begin
    if(reset) begin
      prdata_r <= 32'b0;
      pslverr_r <= 1'b0;
    end else if(out_pready) begin
      prdata_r <= out_prdata;
      pslverr_r <= out_pslverr;
    end
  end


  assign in_pready = state == DELAY && counter == 32'b1;
  assign in_prdata   = prdata_r;
  assign in_pslverr  = pslverr_r;

endmodule
