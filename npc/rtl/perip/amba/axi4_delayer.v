module axi4_delayer(
  input         clock,
  input         reset,

  output reg       in_arready,
  input         in_arvalid,
  input  [3:0]  in_arid,
  input  [31:0] in_araddr,
  input  [7:0]  in_arlen,
  input  [2:0]  in_arsize,
  input  [1:0]  in_arburst,
  input         in_rready,
  output reg       in_rvalid,
  output [3:0]  in_rid,
  output [31:0] in_rdata,
  output [1:0]  in_rresp,
  output reg       in_rlast,
  output reg       in_awready,
  input         in_awvalid,
  input  [3:0]  in_awid,
  input  [31:0] in_awaddr,
  input  [7:0]  in_awlen,
  input  [2:0]  in_awsize,
  input  [1:0]  in_awburst,
  output reg       in_wready,
  input         in_wvalid,
  input  [31:0] in_wdata,
  input  [3:0]  in_wstrb,
  input         in_wlast,
                in_bready,
  output reg      in_bvalid,
  output [3:0]  in_bid,
  output [1:0]  in_bresp,

  input         out_arready,
  output reg       out_arvalid,
  output [3:0]  out_arid,
  output [31:0] out_araddr,
  output [7:0]  out_arlen,
  output [2:0]  out_arsize,
  output [1:0]  out_arburst,
  output reg       out_rready,
  input         out_rvalid,
  input  [3:0]  out_rid,
  input  [31:0] out_rdata,
  input  [1:0]  out_rresp,
  input         out_rlast,
  input         out_awready,
  output reg      out_awvalid,
  output [3:0]  out_awid,
  output [31:0] out_awaddr,
  output [7:0]  out_awlen,
  output [2:0]  out_awsize,
  output [1:0]  out_awburst,
  input         out_wready,
  output reg       out_wvalid,
  output [31:0] out_wdata,
  output [3:0]  out_wstrb,
  output        out_wlast,
                out_bready,
  input         out_bvalid,
  input  [3:0]  out_bid,
  input  [1:0]  out_bresp
);

`ifdef ysyx_23060299_AXI_DELAY

  localparam R_INT = 4.35;            // 频率比的整数部分
  localparam SCALE = 8;           // 缩放因子，用于表示小数部分 2^8
  localparam ADDER = $rtoi(R_INT * (2 ** SCALE));

  reg [3:0]   cur_state_write     , cur_state_read  ;
  reg [3:0]   nxt_state_write     , nxt_state_read  ;
  reg [3:0]   cur_state_W         , nxt_state_W     ;
  reg [3:0]   cur_state_B         , nxt_state_B     ;
  reg [3:0]   cur_state_R         , nxt_state_R     ;
  reg [31:0]  delay_counter_write , delay_counter_read  , delay_counter_W , delay_counter_B;

  localparam IDLE = 4'd0, AW_SUM = 4'd1, AW_ANS = 4'd2, W_SUM = 4'd3 , W_ANS = 4'd4 , B_SUM = 4'd5 , B_ANS = 4'd6 ;
  localparam AW2W = 4'd7, W2B = 4'd8 , SHIFT_AW = 4'd9 , SHIFT_W = 4'd10 , SHIFT_B = 4'd11  ;
  localparam AR_SUM = 4'd1, AR_ANS = 4'd2;
  localparam AR2R = 4'd5, SHIFT_AR = 4'd6 , SHIFT_R = 4'd7;

  always @(posedge clock ) begin
    if(reset) begin
      cur_state_write <=  IDLE  ;
      cur_state_read  <=  IDLE  ;
      cur_state_W     <=  IDLE  ;
      cur_state_B     <=  IDLE  ;
      cur_state_R     <=  IDLE  ;
    end
    else begin
      cur_state_write <=  nxt_state_write ;
      cur_state_read  <=  nxt_state_read  ;
      cur_state_W     <=  nxt_state_W     ;
      cur_state_B     <=  nxt_state_B     ;
      cur_state_R     <=  nxt_state_R     ;
    end
  end

  always @(*) begin
    case (cur_state_W)
      IDLE:
        if(out_wvalid)
          nxt_state_W = W_SUM ;
        else
          nxt_state_W = IDLE ;
      W_SUM:
        if(out_wready)
          nxt_state_W = SHIFT_W ;
        else
          nxt_state_W = W_SUM ;
      SHIFT_W:
          nxt_state_W = W_ANS ;
      W_ANS:
        if(delay_counter_write == 0)
          nxt_state_W = B_SUM ;
        else
          nxt_state_W = W_ANS ;
      B_SUM:
        if(out_bvalid)
          nxt_state_W = SHIFT_B ;
        else
          nxt_state_W = B_SUM ;
      SHIFT_B:
        nxt_state_W = B_ANS ;
      B_ANS:
        if(delay_counter_write == 0)
          nxt_state_W = IDLE ;
        else
          nxt_state_W = B_ANS ;
      default:
        nxt_state_W = IDLE ;
    endcase
  end

  always @(*) begin
    case (cur_state_write)
      IDLE:
        if(out_awvalid)
          nxt_state_write = AW_SUM ;
        else
          nxt_state_write = IDLE ;
      AW_SUM:
        if(out_awready)
          nxt_state_write = SHIFT_AW ;
        else
          nxt_state_write = AW_SUM ;
      SHIFT_AW:
          nxt_state_write = AW_ANS ;
      AW_ANS:
        if(delay_counter_write == 0)
          nxt_state_write = IDLE ;
        else
          nxt_state_write = AW_ANS ;
      default:
        nxt_state_write = IDLE ;
    endcase
  end

  always @(*) begin
    case (cur_state_B)
      IDLE:
        if(out_wready && out_wvalid)
          nxt_state_B = B_SUM ;
        else
          nxt_state_B = IDLE ;
      B_SUM:
        if(out_bvalid)
          nxt_state_B = SHIFT_B ;
        else
          nxt_state_B = B_SUM ;
      SHIFT_B:
        if(in_wvalid && in_wready)
          nxt_state_B = B_ANS ;
        else
          nxt_state_B = SHIFT_B ;
      B_ANS:
        if(delay_counter_B == 0)
          nxt_state_B = IDLE ;
        else
          nxt_state_B = B_ANS ;
      default:
        nxt_state_B = IDLE ;
    endcase
  end

  /* verilator lint_off REALCVT */
  always @(posedge clock ) begin
    if(reset)
      delay_counter_write <=  'd0 ;
    else begin
      if(cur_state_write == AW_SUM)
        delay_counter_write <=  delay_counter_write + ADDER;
      else if(cur_state_write == SHIFT_AW)
        delay_counter_write <=  delay_counter_write >> SCALE;
      else if(cur_state_write == AW_ANS) begin
        if(delay_counter_write != 0)
          delay_counter_write <=  delay_counter_write - 1;
      end
      else if(cur_state_write == IDLE)
        delay_counter_write <=  0;
    end
  end

  always @(posedge clock ) begin
    if(reset)
      delay_counter_W <=  'd0 ;
    else begin
      if(cur_state_W == W_SUM)
        delay_counter_W <=  delay_counter_write + ADDER;
      else if(cur_state_W == SHIFT_W)
        delay_counter_W <=  delay_counter_W >> SCALE;
      else if(cur_state_W == W_ANS) begin
        if(delay_counter_W != 0)
          delay_counter_W <=  delay_counter_W - 1;
      end
      else if(cur_state_W == IDLE)
        delay_counter_W <=  0;
    end
  end

  always @(posedge clock ) begin
    if(reset)
      delay_counter_B <=  'd0 ;
    else begin
      if(cur_state_B == B_SUM)
        delay_counter_B <=  delay_counter_B + ADDER;
      else if(cur_state_B == SHIFT_B && nxt_state_B == B_ANS)
        delay_counter_B <=  delay_counter_B >> SCALE;
      else if(cur_state_B == B_ANS) begin
        if(delay_counter_B != 0)
          delay_counter_B <=  delay_counter_B - 1;
      end
      else if(cur_state_W == IDLE)
        delay_counter_B <=  0;
    end
  end
  /* verilator lint_on REALCVT */

  always @(posedge clock ) begin
    if(reset)
      in_awready  <=  1'b0  ;
    else if(delay_counter_write == 0 && cur_state_write == AW_ANS)
      in_awready  <=  1'b1  ;
    else
      in_awready  <=  1'b0  ;
  end

  always @(posedge clock ) begin
    if(reset)
      in_wready  <=  1'b0  ;
    else if(delay_counter_W == 0 && cur_state_W == W_ANS)
      in_wready  <=  1'b1  ;
    else
      in_wready  <=  1'b0  ;
  end

  always @(posedge clock ) begin
    if(reset)
      out_awvalid <=  1'b0  ;
    else if(cur_state_write == IDLE && cur_state_B == IDLE)
      out_awvalid <=  in_awvalid ;
    else if(out_awvalid && out_awready)
      out_awvalid <=  1'b0  ;
  end

  always @(posedge clock ) begin
    if(reset)
      out_wvalid <=  1'b0  ;
    else if(cur_state_write == IDLE && cur_state_B == IDLE)
      out_wvalid <=  in_wvalid ;
    else if(out_wvalid && out_wready)
      out_wvalid <=  1'b0  ;
  end

  assign out_awid = in_awid;
  assign out_awaddr = in_awaddr;
  assign out_awlen = in_awlen;
  assign out_awsize = in_awsize;
  assign out_awburst = in_awburst;

  assign out_wdata = in_wdata;
  assign out_wstrb = in_wstrb;
  assign out_wlast = in_wlast;

  always @(posedge clock ) begin
    if(reset)
      in_bvalid  <=  1'b0  ;
    else if(delay_counter_B == 0 && cur_state_B == B_ANS)
      in_bvalid  <=  1'b1  ;
    else
      in_bvalid  <=  1'b0  ;
  end

  assign out_bready = in_bready;

  assign in_bid = out_bid;
  assign in_bresp = out_bresp;

  always @(*) begin
    case (cur_state_read)
      IDLE:
        if(out_arvalid)
          nxt_state_read = AR_SUM ;
        else
          nxt_state_read = IDLE ;
      AR_SUM:
        if(out_arready)
          nxt_state_read = SHIFT_AR ;
        else
          nxt_state_read = AR_SUM ;
      SHIFT_AR:
          nxt_state_read = AR_ANS ;
      AR_ANS:
        if(delay_counter_read == 0)
          nxt_state_read = IDLE ;
        else
          nxt_state_read = AR_ANS ;
      default:
        nxt_state_read = IDLE ;
    endcase
  end

  always @(posedge clock ) begin
    if(reset)
      out_arvalid <=  1'b0  ;
    else if(cur_state_read == IDLE && !in_arready)
      out_arvalid <=  in_arvalid  ;
    else if(out_arvalid && out_arready)
      out_arvalid <=  1'b0  ;
  end

  always @(posedge clock ) begin
    if(reset)
      delay_counter_read <=  'd0 ;
    else begin
      if(cur_state_read == AR_SUM)
        delay_counter_read <=  delay_counter_read + ADDER;
      else if(cur_state_read == SHIFT_AR)
        delay_counter_read <=  delay_counter_read >> SCALE;
      else if(cur_state_read == AR_ANS) begin
        if(delay_counter_read != 0)
          delay_counter_read <=  delay_counter_read - 1;
      end
      else if(cur_state_read == IDLE)
        delay_counter_read <=  0;
    end
  end

  reg [7:0] ar_len_r    ;
  reg [7:0] ar_len_in_r ;

  always @(posedge clock ) begin
    if(reset)
      ar_len_r  <=  'd0 ;
    else if(out_arvalid && out_arready)
      ar_len_r  <=  out_arlen + 1;
    else if(out_rvalid  &&  out_rready)
      ar_len_r  <=  ar_len_r  - 1 ;
  end

  always @(posedge clock ) begin
    if(reset)
      ar_len_in_r <=  'd0 ;
    else if(out_arvalid && out_arready)
      ar_len_in_r <=  out_arlen + 1;
    else if(in_rvalid  &&  in_rready)
      ar_len_in_r <=  ar_len_in_r  - 1 ;
  end

  always @(posedge clock ) begin
    if(reset)
      in_arready  <=  1'b0  ;
    else if(delay_counter_read == 0 && cur_state_read == AR_ANS)
      in_arready  <=  1'b1  ;
    else
      in_arready  <=  1'b0  ;
  end

  always @(posedge clock ) begin
    if(reset)
      out_rready  <=  1'b0  ;
    else if(in_arready && in_arvalid)
      out_rready  <=  1'b1  ;
    else if(out_rready && out_rvalid && out_rlast)
      out_rready  <=  1'b0  ;
  end

  localparam R_SUM = 4'd1, R_SHIFT = 4'd2, R0_ANS = 4'd3, R0_DELAY = 4'd4, R1_ANS = 4'd5;
  localparam R1_DELAY = 4'd6, R2_ANS = 4'd7, R2_DELAY = 4'd8, R3_ANS = 4'd9 ;

  reg [31:0]  delay_cycle_AR2R  ;
  reg [31:0]  delay_cycle_R0  ;
  reg [31:0]  delay_cycle_R1  ;
  reg [31:0]  delay_cycle_R2  ;

  always @(*) begin
    case (cur_state_R)
      IDLE: if(out_arvalid && out_arready)  nxt_state_R =  R_SUM  ; else  nxt_state_R =  IDLE ;
      R_SUM:  if(out_rvalid)  nxt_state_R = R_SHIFT ;  else  nxt_state_R =  R_SUM ;
      R_SHIFT:  if(in_arvalid && in_arready || cur_state_read == IDLE) nxt_state_R =  R0_ANS ; else nxt_state_R =  R_SHIFT ;
      R0_ANS: begin
        if(delay_cycle_AR2R == 0)
          if(ar_len_in_r != 1) nxt_state_R = R0_DELAY ;  else  nxt_state_R =  IDLE ;
        else
          nxt_state_R =  R0_ANS ;
      end

      R0_DELAY: if(delay_cycle_R0 == 0) nxt_state_R = R1_ANS ;  else  nxt_state_R =  R0_DELAY ;

      R1_ANS: if(ar_len_in_r != 0) nxt_state_R = R1_DELAY ;  else  nxt_state_R =  IDLE ;

      R1_DELAY: if(delay_cycle_R1 == 0) nxt_state_R = R2_ANS ;  else  nxt_state_R =  R1_DELAY ;
      R2_ANS: if(ar_len_in_r != 0) nxt_state_R = R2_DELAY ;  else  nxt_state_R =  IDLE ;
      R2_DELAY: if(delay_cycle_R2 == 0) nxt_state_R = R3_ANS ;  else  nxt_state_R =  R2_DELAY ;
      R3_ANS: nxt_state_R =  IDLE ;
      default: nxt_state_R =  IDLE ;
    endcase
  end

  always @(posedge clock ) begin
    if(reset)
      delay_cycle_AR2R  <=  'd0 ;
    else  if(cur_state_R == R_SUM)
      delay_cycle_AR2R <=  delay_cycle_AR2R + ADDER;
    else if(cur_state_R == R_SHIFT && nxt_state_R == R0_ANS)
      delay_cycle_AR2R <=  delay_cycle_AR2R >> SCALE;
    else if(cur_state_R == R0_ANS) begin
      if(delay_cycle_AR2R != 0)
        delay_cycle_AR2R <=  delay_cycle_AR2R - 1;
    end
    else if(cur_state_R == IDLE)
      delay_cycle_AR2R <=  0;
  end

  always @(posedge clock ) begin
    if(reset || cur_state_R == IDLE)
      delay_cycle_R0  <=  ADDER ;
    else  if(ar_len_r == 3 && out_rvalid == 0)
      delay_cycle_R0 <=  delay_cycle_R0 + ADDER;
    else  if((cur_state_R == R0_ANS && delay_cycle_AR2R == 0))
      delay_cycle_R0 <=  delay_cycle_R0 >> SCALE;
    else if(cur_state_R == R0_DELAY)
      if(delay_cycle_R0 != 0)
        delay_cycle_R0 <=  delay_cycle_R0 - 1;
  end

  wire condi1 = reset;
  wire condi2 = ar_len_r == 2 && out_rvalid == 0;
  wire condi3 = (cur_state_R == R0_ANS && delay_cycle_AR2R == 0);
  wire condi4 = cur_state_R == R1_DELAY;
  wire condi5 = cur_state_R == IDLE;

  always @(posedge clock ) begin
    if(reset || cur_state_R == IDLE)
      delay_cycle_R1  <=  ADDER ;
    else  if(ar_len_r == 2 && out_rvalid == 0)
      delay_cycle_R1 <=  delay_cycle_R1 + ADDER;
    else  if((cur_state_R == R0_ANS && delay_cycle_AR2R == 0))
      delay_cycle_R1 <=  delay_cycle_R1 >> SCALE;
    else if(cur_state_R == R1_DELAY)
      if(delay_cycle_R1 != 0)
        delay_cycle_R1 <=  delay_cycle_R1 - 1;
  end

  always @(posedge clock ) begin
    if(reset || cur_state_R == IDLE)
      delay_cycle_R2  <=  ADDER ;
    else  if(ar_len_r == 1 && out_rvalid == 0)
      delay_cycle_R2 <=  delay_cycle_R2 + ADDER;
    else  if((cur_state_R == R0_ANS && delay_cycle_AR2R == 0))
      delay_cycle_R2 <=  delay_cycle_R2 >> SCALE;
    else if(cur_state_R == R2_DELAY)
      if(delay_cycle_R2 != 0)
        delay_cycle_R2 <=  delay_cycle_R2 - 1;
  end

  always @(posedge clock ) begin
    if(reset)
      in_rvalid <=  1'b0  ;
    else if((cur_state_R == R0_ANS && delay_cycle_AR2R == 0) || cur_state_R == R1_ANS || cur_state_R == R2_ANS || cur_state_R == R3_ANS)
      in_rvalid <=  1'b1  ;
    else
      in_rvalid <=  1'b0  ;
  end

  always @(posedge clock ) begin
    if(reset)
      in_rlast  <=  'd0 ;
    else if(((cur_state_R == R0_ANS && delay_cycle_AR2R == 0) || cur_state_R == R1_ANS || cur_state_R == R2_ANS || cur_state_R == R3_ANS) && ar_len_in_r == 1)
      in_rlast  <=  'd1 ;
    else
      in_rlast  <=  'd0 ;
  end

  assign out_arid = in_arid;
  assign out_araddr = in_araddr;
  assign out_arlen = in_arlen;
  assign out_arsize = in_arsize;
  assign out_arburst = in_arburst;

  assign in_rid = out_rid;
  assign in_rresp = out_rresp;

sync_fifo_count #(
  .DATA_WIDTH(32) ,
  .DATA_DEPTH(16)
)
u_sync_fifo_count (
  .clk(clock),
  .rst_n (!reset),
  .data_in(out_rdata),
  .rd_en(((cur_state_R == R0_ANS && delay_cycle_AR2R == 0) || cur_state_R == R1_ANS || cur_state_R == R2_ANS || cur_state_R == R3_ANS)),
  .wr_en(out_rvalid && out_rready),
  .data_out(in_rdata),
  .empty(),
  .full(),
  .fifo_cnt()
);

endmodule

//计数器法实现同步FIFO
module	sync_fifo_count
#(
	parameter   DATA_WIDTH = 'd8  ,							//FIFO位宽
    parameter   DATA_DEPTH = 'd16 							//FIFO深度
)
(
	input									clk		,		//系统时钟
	input									rst_n	,       //低电平有效的复位信号
	input	[DATA_WIDTH-1:0]				data_in	,       //写入的数据
	input									rd_en	,       //读使能信号，高电平有效
	input									wr_en	,       //写使能信号，高电平有效
															
	output	reg	[DATA_WIDTH-1:0]			data_out,	    //输出的数据
	output									empty	,	    //空标志，高电平表示当前FIFO已被写满
	output									full	,       //满标志，高电平表示当前FIFO已被读空
	output	reg	[$clog2(DATA_DEPTH) : 0]	fifo_cnt		//$clog2是以2为底取对数	
);
 
//reg define
reg [DATA_WIDTH - 1 : 0] fifo_buffer[DATA_DEPTH - 1 : 0];	//用二维数组实现RAM	
reg [$clog2(DATA_DEPTH) - 1 : 0]	wr_addr;				//写地址
reg [$clog2(DATA_DEPTH) - 1 : 0]	rd_addr;				//读地址
 
//读操作，更新读地址
always @ (posedge clk or negedge rst_n) begin
	if (!rst_n)
		rd_addr <= 0;
	else if (!empty && rd_en)begin							//读使能有效且非空
		rd_addr <= rd_addr + 1'd1;
		data_out <= fifo_buffer[rd_addr];
	end
end
//写操作,更新写地址
always @ (posedge clk or negedge rst_n) begin
	if (!rst_n)
		wr_addr <= 0;
	else if (!full && wr_en)begin							//写使能有效且非满
		wr_addr <= wr_addr + 1'd1;
		fifo_buffer[wr_addr]<=data_in;
	end
end
//更新计数器
always @ (posedge clk or negedge rst_n) begin
	if (!rst_n)
		fifo_cnt <= 0;
	else begin
		case({wr_en,rd_en})									//拼接读写使能信号进行判断
			2'b00:fifo_cnt <= fifo_cnt;						//不读不写
			2'b01:	                               			//仅仅读
				if(fifo_cnt != 0)				   			//fifo没有被读空
					fifo_cnt <= fifo_cnt - 1'b1;   			//fifo个数-1
			2'b10:                                 			//仅仅写
				if(fifo_cnt != DATA_DEPTH)         			//fifo没有被写满
					fifo_cnt <= fifo_cnt + 1'b1;   			//fifo个数+1
			2'b11:fifo_cnt <= fifo_cnt;	           			//读写同时
			default:;                              	
		endcase
	end
end
//依据计数器状态更新指示信号
//依据不同阈值还可以设计半空、半满 、几乎空、几乎满
assign full  = (fifo_cnt == DATA_DEPTH) ? 1'b1 : 1'b0;		//满信号
assign empty = (fifo_cnt == 0)? 1'b1 : 1'b0;				//空信号

`else

assign in_arready = out_arready;
assign out_arvalid = in_arvalid;
assign out_arid = in_arid;
assign out_araddr = in_araddr;
assign out_arlen = in_arlen;
assign out_arsize = in_arsize;
assign out_arburst = in_arburst;
assign out_rready = in_rready;
assign in_rvalid = out_rvalid;
assign in_rid = out_rid;
assign in_rdata = out_rdata;
assign in_rresp = out_rresp;
assign in_rlast = out_rlast;
assign in_awready = out_awready;
assign out_awvalid = in_awvalid;
assign out_awid = in_awid;
assign out_awaddr = in_awaddr;
assign out_awlen = in_awlen;
assign out_awsize = in_awsize;
assign out_awburst = in_awburst;
assign in_wready = out_wready;
assign out_wvalid = in_wvalid;
assign out_wdata = in_wdata;
assign out_wstrb = in_wstrb;
assign out_wlast = in_wlast;
assign out_bready = in_bready;
assign in_bvalid = out_bvalid;
assign in_bid = out_bid;
assign in_bresp = out_bresp;

`endif 
 
endmodule
