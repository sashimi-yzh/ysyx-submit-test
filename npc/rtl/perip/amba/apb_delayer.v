module apb_delayer #(
    parameter R_INT = 4.35,            // 频率比的整数部分
    parameter SCALE = 8,           // 缩放因子，用于表示小数部分 2^8
    parameter ADDER = R_INT * (2 ** SCALE)
)(
    input         clock,
    input         reset,
    
    // APB 输入端口
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

    // APB 输出端口
    output      [31:0]  out_paddr,
    output reg          out_psel,
    output reg          out_penable,
    output [2:0]        out_pprot,
    output              out_pwrite,
    output [31:0]       out_pwdata,
    output [3:0]        out_pstrb,
    
    input         out_pready,
    input  [31:0] out_prdata,
    input         out_pslverr
);

`ifdef ysyx_23060299_APB_DELAY

localparam  IDLE   =  3'd0  ;
localparam  SUM    =  3'd1  ;
localparam  DELAY  =  3'd2  ;
localparam  WAIT   =  3'd3  ;
localparam  ANS    =  3'd4  ;

reg   [2:0] cur_state ;
reg   [2:0] nxt_state ;

reg [31:0]  delay_counter ;

// 存储响应数据 
reg [31:0] stored_prdata;
reg        stored_pslverr;

always @(posedge clock ) begin
  if(reset)
    stored_prdata <=  'd0 ;
  else if(out_pready)
    stored_prdata <=  out_prdata  ;
end

always @(posedge clock ) begin
  if(reset)
    stored_pslverr <=  'd0 ;
  else if(out_pready)
    stored_pslverr <=  out_pslverr  ;
end

always @(posedge clock ) begin
  if(reset)
    cur_state <=  IDLE  ;
  else
    cur_state <=  nxt_state ;
end

always @(*) begin
  case (cur_state)
    IDLE: begin 
      if(in_psel  &&  in_penable)
        nxt_state = SUM ;
      else
        nxt_state = IDLE ;
    end
    SUM: begin 
      if(out_pready)
        nxt_state = WAIT ;
      else
        nxt_state = SUM ;
    end
    WAIT: begin 
        nxt_state = DELAY ;
    end
    DELAY: begin 
      if(delay_counter  ==  0)
        nxt_state = ANS ;
      else
        nxt_state = DELAY ;
    end
    ANS: begin 
      nxt_state = IDLE ;
    end
    default:
      nxt_state = IDLE ;
  endcase
end

/* verilator lint_off REALCVT */
always @(posedge clock ) begin
  if(reset)
    delay_counter <=  'd0 ;
  else  if(cur_state  ==  SUM)
    delay_counter <=  delay_counter + ADDER;
  else  if(cur_state  ==  WAIT)
    delay_counter <=  delay_counter >> SCALE;
  else  if(cur_state  ==  DELAY)
    delay_counter <=  delay_counter - 1;
  else  if(cur_state  ==  ANS)
    delay_counter <=  'd0 ;
end
/* verilator lint_on REALCVT */

// 信号赋值
assign out_paddr   = in_paddr;
assign out_pprot   = in_pprot;
assign out_pwrite  = in_pwrite;
assign out_pwdata  = in_pwdata;
assign out_pstrb   = in_pstrb;

always @(posedge clock ) begin
  if(reset)
    out_psel  <=  'd0 ;
  else  if(cur_state == IDLE)
    out_psel  <=  in_psel ;
  else  if(out_pready)
    out_psel  <=  'd0 ;
end

always @(posedge clock ) begin
  if(reset)
    out_penable  <=  'd0 ;
  else  if(cur_state == IDLE)
    out_penable  <=  in_penable ;
  else  if(out_pready)
    out_penable  <=  'd0 ;
end

assign in_prdata   = stored_prdata;
assign in_pslverr  = stored_pslverr;

// 控制 in_pready 信号
assign in_pready = (cur_state == ANS);

`else

assign out_paddr   = in_paddr;
assign out_psel    = in_psel;
assign out_penable = in_penable;
assign out_pprot   = in_pprot;
assign out_pwrite  = in_pwrite;
assign out_pwdata  = in_pwdata;
assign out_pstrb   = in_pstrb;
assign in_pready   = out_pready;
assign in_prdata   = out_prdata;
assign in_pslverr  = out_pslverr;


`endif

endmodule
