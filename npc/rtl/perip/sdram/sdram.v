module sdram(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [12:0] a,
  input [ 1:0] ba,
  input [ 1:0] dqm,
  inout [15:0] dq
);

reg   [15:0]  sdram [2**24 - 1: 0];



reg   [12:0]  row_addr  [3:0];

wire  [8:0]   col_addr  ;
reg   [8:0]   read_addr ;
reg   [1:0]   ba_addr   ;
reg           command_write_d0  ;
reg   [1:0]   latency_cnt       ;

wire  [15:0]  din     ;
reg   [15:0]  dout    ;
reg           dout_en ;

wire  command_active  ;  
wire  command_read    ;
wire  command_write   ;
wire  command_burst_terminate ;
wire  command_load_mode_reg   ;

wire  [1:0]   cas_latency ;
wire  [3:0]   burst_length  ;

reg   [12:0]  mode_reg  ;

assign  col_addr  = a[8:0]  ;

assign  command_active  = !cs &&  !ras  &&  cas &&  we  ;
assign  command_read    = !cs &&  ras  &&  !cas &&  we  ;
assign  command_write   = !cs &&  ras  &&  !cas &&  !we  ;
assign  command_burst_terminate = !cs &&  ras  &&  cas &&  !we  ;
assign  command_load_mode_reg = !cs &&  !ras  &&  !cas &&  !we  ;

assign  din = dq  ;
assign  dq = dout_en ? dout  : 16'bz;

assign  cas_latency   = (mode_reg[6:4] ==  3'b010)  ? 2'd2  :
                        (mode_reg[6:4] ==  3'b011)  ? 2'd3  :
                        'd2 ;

assign  burst_length  = (mode_reg[2:0] ==  3'b000)  ? 4'd1  :
                        (mode_reg[2:0] ==  3'b001)  ? 4'd2  :
                        (mode_reg[2:0] ==  3'b010)  ? 4'd4  :
                        (mode_reg[2:0] ==  3'b011)  ? 4'd8  :
                        'd1 ;

always @(posedge clk) begin
  if(command_load_mode_reg)
    mode_reg  <=  a ;
end

always @(posedge clk ) begin
  if(command_active)
    row_addr[ba]  <=  a ;
end

always @(posedge clk ) begin
  if(command_load_mode_reg)
    command_write_d0  <=  'd0 ;
  else
    command_write_d0  <=  command_write ;
end

always @(posedge clk ) begin
  case (dqm)
    2'b00 : begin
      if(command_write)
        sdram[{ba,  row_addr[ba], col_addr}]  <=  din ;
      else  if(command_write_d0)
        sdram[{ba,  row_addr[ba], (col_addr + 1'b1)}]  <=  din ;
    end
    2'b01 : begin
      if(command_write)
        sdram[{ba,  row_addr[ba], col_addr}][15:8]  <=  din[15:8] ;
      else  if(command_write_d0)
        sdram[{ba,  row_addr[ba], (col_addr + 1'b1)}][15:8]  <=  din[15:8] ;
    end
    2'b10 : begin
      if(command_write)
        sdram[{ba,  row_addr[ba], col_addr}][7:0]  <=  din[7:0] ;
      else  if(command_write_d0)
        sdram[{ba,  row_addr[ba], (col_addr + 1'b1)}][7:0]  <=  din[7:0] ;
    end
    2'b11 : sdram[{ba,  row_addr[ba], col_addr}]  <=  sdram[{ba,  row_addr[ba], col_addr}];
  endcase
end

always @(posedge clk ) begin
  if(command_load_mode_reg)
    latency_cnt <=  'd0 ;
  if(command_read)
    latency_cnt <=  'd1 ;
  else  if(latency_cnt  !=  0)
    latency_cnt <=  latency_cnt + 1'b1  ;
end

always @(posedge clk ) begin
  if(command_read) begin
    read_addr <=  col_addr ;
    ba_addr <=  ba  ;
  end
end

always @(posedge clk ) begin
  if(latency_cnt  ==  cas_latency - 1) begin
    dout  <=  sdram[{ba_addr,  row_addr[ba_addr], read_addr}];
    dout_en <= 1'b1 ;
  end
  else  if(latency_cnt  ==  cas_latency) begin
    dout  <=  sdram[{ba_addr,  row_addr[ba_addr], (read_addr + 1'b1)}];
    dout_en <= 1'b1 ;
  end
  else
    dout_en <=  1'b0  ;
end


endmodule
