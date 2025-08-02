module ps2_top_apb(
  input              clock,
  input              reset,
  input       [31:0] in_paddr,
  input              in_psel,
  input              in_penable,
  input       [2:0]  in_pprot,
  input              in_pwrite,
  input       [31:0] in_pwdata,
  input       [3:0]  in_pstrb,
  output reg         in_pready,
  output      [31:0] in_prdata,
  output             in_pslverr,

  input              ps2_clk,
  input              ps2_data
);

// APB read operation
assign in_pslverr = 1'b0;

reg [9:0] buffer;        // ps2_data bits
reg [3:0] count;  // count ps2_data bits
reg [2:0] ps2_clk_sync;
reg [5:0] idle_cnt  ;
reg       is_idle   ;

always @(posedge clock) begin
    ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
end

wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

always @(posedge clock) begin
    if (reset == 1)
        count <= 0;
    else begin
        if (sampling) begin
          if (count == 4'd10)
            count <= 0;     // for next
          else begin
            buffer[count] <= ps2_data;  // store ps2_data
            count <= count + 3'b1;
          end
        end
    end
end

wire  wr_en ;
reg   rd_en ;
reg   rd_en_msk ;
wire  empty ;
reg   empty_r ;
wire  [7:0] data_out  ;

assign  wr_en = sampling  &&  (count == 4'd10)  &&  ((buffer[0] == 0) &&  (ps2_data)  &&  (^buffer[9:1]));

always @(posedge clock ) begin
  if(reset)
    is_idle <=  1'b0  ;
  else  if(idle_cnt == 6'd63)
    is_idle <=  1'b1  ;
  else
    is_idle <=  1'b0  ;
end

always @(posedge clock ) begin
  if(reset)
    idle_cnt <=  6'b0  ;
  else  if(!ps2_clk) begin
    if(idle_cnt != 6'd63)
      idle_cnt <=  idle_cnt + 6'b1  ;
  end
  else  if(ps2_clk)
    idle_cnt <=  6'b0  ;
end

always @(posedge clock ) begin
  if(reset)
    empty_r <=  'd0 ;
  else
    empty_r <=  empty ;
end

always @(posedge clock ) begin
  if(reset)
    rd_en <=  'd0 ;
  else if(in_psel && !in_penable && is_idle)
    rd_en <=  'd1 ;
  else
    rd_en <=  'd0 ;
end

always @(posedge clock ) begin
  if(reset)
    rd_en_msk <=  'd0 ;
  else if(in_psel && !in_penable)
    rd_en_msk <=  'd1 ;
  else
    rd_en_msk <=  'd0 ;
end

always @(posedge clock) begin
  if(reset)
    in_pready <=  1'b0  ;
  else  if(rd_en_msk)
    in_pready <=  1'b1  ;
  else
    in_pready <=  1'b0  ;
end

assign in_prdata = (empty_r ||  !is_idle)  ? 32'd0 : {24'd0,  data_out};

sync_fifo_cnt sync_fifo_cnt(
  .clk		    (clock        ),
  .rst   	    (reset        ),
  .data_in	  (buffer[8:1]  ),
  .rd_en	    (rd_en        ),
  .wr_en		  (wr_en        ),
  .data_out   (data_out     ),
  .empty	    (empty        ),
  .full	      (),
  .fifo_cnt   ()
);

endmodule
