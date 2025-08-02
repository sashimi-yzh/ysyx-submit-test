// define this macro to enable fast behavior simulation
// for flash by skipping SPI transfers
// `define FAST_FLASH

module spi_top_apb #(
  parameter flash_addr_start = 32'h30000000,
  parameter flash_addr_end   = 32'h3fffffff,
  parameter spi_ss_num       = 8
) (
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

  output                  spi_sck,
  output [spi_ss_num-1:0] spi_ss,
  output                  spi_mosi,
  input                   spi_miso,
  output                  spi_irq_out
);

`ifdef FAST_FLASH

wire [31:0] data;
parameter invalid_cmd = 8'h0;
flash_cmd flash_cmd_i(
  .clock(clock),
  .valid(in_psel && !in_penable),
  .cmd(in_pwrite ? invalid_cmd : 8'h03),
  .addr({8'b0, in_paddr[23:2], 2'b0}),
  .data(data)
);
assign spi_sck    = 1'b0;
assign spi_ss     = 8'b0;
assign spi_mosi   = 1'b1;
assign spi_irq_out= 1'b0;
assign in_pslverr = 1'b0;
assign in_pready  = in_penable && in_psel && !in_pwrite;
assign in_prdata  = data[31:0];

`else

wire  [4:0]   wb_adr_i  ;
wire  [31:0]  wb_dat_i  ;
wire  [31:0]  wb_dat_o  ;
wire  [3:0]   wb_sel_i  ;
wire          wb_we_i   ;
wire          wb_stb_i  ;
wire          wb_cyc_i  ;
wire          wb_ack_o  ;
wire          wb_err_o  ;

reg   [4:0]   paddr_xip   ;
reg   [31:0]  pwdata_xip  ;
wire  [31:0]  prdata_xip  ;
reg   [3:0]   pstrb_xip   ;
reg           pwrite_xip  ;
reg           psel_xip    ;
reg           penable_xip ;
wire          pready_xip  ;
wire          pslverr_xip ;

wire          trans_done  ;
reg   [23:0]  addr_xip    ;

localparam  IDLE      = 0 ;
localparam  SET_SS    = 1 ;
localparam  WRITE_TX  = 2 ;
localparam  START     = 3 ;
localparam  WAIT      = 4 ;
localparam  RST_SS    = 5 ;
localparam  READ      = 6 ;

reg [2:0] cur_state ;
reg [2:0] nxt_state ;

always @(posedge clock ) begin
  if(reset)
    cur_state <=  IDLE  ;
  else
    cur_state <=  nxt_state ;
end

always @(*) begin
  case (cur_state)
    IDLE: begin
      if((in_paddr[31:28] ==  4'd3) &&  !in_pwrite  &&  in_psel)
        nxt_state = SET_SS ;
      else
        nxt_state = IDLE  ;
    end
    SET_SS: begin
      if(pready_xip)
        nxt_state = WRITE_TX ;
      else
        nxt_state = SET_SS ;
    end
    WRITE_TX: begin
      if(pready_xip)
        nxt_state = START ;
      else
        nxt_state = WRITE_TX  ;
    end
    START: begin
      if(pready_xip)
        nxt_state = WAIT ;
      else
        nxt_state = START ;
    end
    WAIT: begin
      if(pready_xip &&  trans_done)
        nxt_state = RST_SS ;
      else
        nxt_state = WAIT  ;
    end
    RST_SS: begin
      if(pready_xip)
        nxt_state = READ ;
      else
        nxt_state = RST_SS ;
    end
    READ: begin
      if(pready_xip)
        nxt_state = IDLE ;
      else
        nxt_state = READ ;
    end
    default:
      nxt_state = IDLE  ;
  endcase
end

always @(*) begin
  if(cur_state  ==  IDLE) begin
    paddr_xip   = 'h0 ;
    pwdata_xip  = 'h0 ;
    pwrite_xip  = 'h0 ;
    psel_xip    = 'h0 ;
  end
  else if(cur_state  ==  SET_SS) begin
    paddr_xip   = 'h18 ;
    pwdata_xip  = 'h1 ;
    pwrite_xip  = 'h1 ;
    psel_xip    = 'h1 ;
  end
  else if(cur_state  ==  WRITE_TX) begin
    paddr_xip   = 'h4 ;
    pwdata_xip  = {8'h03, addr_xip} ;
    pwrite_xip  = 'h1 ;
    psel_xip    = 'h1 ;
  end
  else if(cur_state  ==  START) begin
    paddr_xip   = 'h10 ;
    pwdata_xip  = 'h540 ;
    pwrite_xip  = 'h1 ;
    psel_xip    = 'h1 ;
  end
  else if(cur_state  ==  WAIT) begin
    paddr_xip   = 'h10 ;
    pwdata_xip  = 'h0 ;
    pwrite_xip  = 'h0 ;
    psel_xip    = 'h1 ;
  end
  else if(cur_state  ==  RST_SS) begin
    paddr_xip   = 'h18 ;
    pwdata_xip  = 'h0 ;
    pwrite_xip  = 'h1 ;
    psel_xip    = 'h1 ;
  end
  else if(cur_state  ==  READ) begin
    paddr_xip   = 'h0 ;
    pwdata_xip  = 'h0 ;
    pwrite_xip  = 'h0 ;
    psel_xip    = 'h1 ;
  end
  else begin
    paddr_xip   = 'h0 ;
    pwdata_xip  = 'h0 ;
    pwrite_xip  = 'h0 ;
    psel_xip    = 'h0 ;
  end
end

always @(posedge clock ) begin
  if(reset)
    penable_xip <=  1'b0  ;
  else  if(psel_xip)
    penable_xip <=  1'b1  ;
  else  if(pready_xip)
    penable_xip <=  1'b0  ;
end

always @(posedge clock ) begin
  if(nxt_state  ==  SET_SS)
    addr_xip  <=  in_paddr[23:0]  ;
end

assign  wb_adr_i    = (cur_state  ==  IDLE) ? in_paddr[4:0] : paddr_xip ;
assign  wb_dat_i    = (cur_state  ==  IDLE) ? in_pwdata : pwdata_xip  ;
assign  in_prdata   = (cur_state  ==  IDLE) ? wb_dat_o  : prdata_xip  ;
assign  prdata_xip  = (cur_state  ==  READ) ? {wb_dat_o[7:0], wb_dat_o[15:8], wb_dat_o[23:16],  wb_dat_o[31:24]}  : 'd0 ;
assign  wb_sel_i    = (cur_state  ==  IDLE) ? in_pstrb  : pstrb_xip ;
assign  wb_we_i     = (cur_state  ==  IDLE) ? in_pwrite : pwrite_xip  ;
assign  wb_stb_i    = (cur_state  ==  IDLE) ? in_psel   : psel_xip  ;
assign  wb_cyc_i    = (cur_state  ==  IDLE) ? in_penable  : penable_xip ;
assign  in_pready   = (cur_state  ==  IDLE) ? wb_ack_o  : ((cur_state  ==  READ)  &&  (pslverr_xip  ==  0)  &&  (nxt_state  ==  IDLE)) ;
assign  pready_xip  = (cur_state  !=  IDLE) ? wb_ack_o  : 'd0 ;
assign  in_pslverr  = (cur_state  ==  IDLE) ? wb_err_o  : 'd0 ;
assign  pslverr_xip = (cur_state  !=  IDLE) ? wb_err_o  : 'd0 ;
assign  pstrb_xip   = (cur_state  ==  IDLE) ? 4'h0      : 4'hF  ;

assign  trans_done  = (cur_state  ==  WAIT) &&  (!wb_dat_o[8])  ;

spi_top u0_spi_top (
  .wb_clk_i(clock         ),
  .wb_rst_i(reset         ),
  .wb_adr_i(wb_adr_i      ),
  .wb_dat_i(wb_dat_i      ),
  .wb_dat_o(wb_dat_o      ),
  .wb_sel_i(wb_sel_i      ),
  .wb_we_i (wb_we_i       ),
  .wb_stb_i(wb_stb_i      ),
  .wb_cyc_i(wb_cyc_i      ),
  .wb_ack_o(wb_ack_o      ),
  .wb_err_o(wb_err_o      ),
  .wb_int_o(spi_irq_out   ),

  .ss_pad_o(spi_ss),
  .sclk_pad_o(spi_sck),
  .mosi_pad_o(spi_mosi),
  .miso_pad_i(spi_miso)
);

`endif // FAST_FLASH

endmodule
