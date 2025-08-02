module gpio_top_apb(
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

  output [15:0] gpio_out,
  input  [15:0] gpio_in,
  output [7:0]  gpio_seg_0,
  output [7:0]  gpio_seg_1,
  output [7:0]  gpio_seg_2,
  output [7:0]  gpio_seg_3,
  output [7:0]  gpio_seg_4,
  output [7:0]  gpio_seg_5,
  output [7:0]  gpio_seg_6,
  output [7:0]  gpio_seg_7
);

  reg   [15:0] led_reg;
  wire  [15:0] switch_wire;
  reg   [31:0] seg_reg;

  assign  switch_wire = gpio_in ;

  // APB write operation
  always @(posedge clock) begin
    if (reset) begin
      led_reg   <= 16'b0;
      seg_reg   <= 32'b0;
    end else if (in_psel && in_penable && in_pwrite) begin
      case (in_paddr[3:0])
        4'h0: led_reg <= in_pwdata[15:0];           // LED 控制
        4'h8: seg_reg <= in_pwdata[31:0];           // 7段数码管控制
        default : led_reg <= led_reg;
      endcase
    end
  end

  // APB read operation
  assign in_prdata = (in_paddr[3:0] == 4'h0) ? {16'b0, led_reg} :
                     (in_paddr[3:0] == 4'h4) ? {16'b0, switch_wire} :
                     (in_paddr[3:0] == 4'h8) ? seg_reg : 32'b0;
  assign in_pready = 1'b1;
  assign in_pslverr = 1'b0;

  // GPIO outputs
  assign  gpio_out  = led_reg ;

hex2seg seg0(
  .hex  (seg_reg[3:0])  ,
  .seg0 (gpio_seg_0 ) 
);

hex2seg seg1(
  .hex  (seg_reg[7:4])  ,
  .seg0 (gpio_seg_1 ) 
);

hex2seg seg2(
  .hex  (seg_reg[11:8])  ,
  .seg0 (gpio_seg_2 ) 
);

hex2seg seg3(
  .hex  (seg_reg[15:12])  ,
  .seg0 (gpio_seg_3 ) 
);

hex2seg seg4(
  .hex  (seg_reg[19:16])  ,
  .seg0 (gpio_seg_4 ) 
);

hex2seg seg5(
  .hex  (seg_reg[23:20])  ,
  .seg0 (gpio_seg_5 ) 
);

hex2seg seg6(
  .hex  (seg_reg[27:24])  ,
  .seg0 (gpio_seg_6 ) 
);

hex2seg seg7(
  .hex  (seg_reg[31:28])  ,
  .seg0 (gpio_seg_7 ) 
);

endmodule

module hex2seg (
  input       [3:0] hex ,
  output  reg [7:0] seg0 
);

always @(*) begin
	case(hex)
		4'd0: seg0 = 8'b00000011;
		4'd1: seg0 = 8'b10011111;
		4'd2: seg0 = 8'b00100101;
		4'd3: seg0 = 8'b00001101;
		4'd4: seg0 = 8'b10011001;
		4'd5: seg0 = 8'b01001001;
		4'd6: seg0 = 8'b01000001;
		4'd7: seg0 = 8'b00011111;
		4'd8: seg0 = 8'b00000001;
		4'd9: seg0 = 8'b00001001;
		4'd10: seg0 = 8'b00010001;
		4'd11: seg0 = 8'b11000001;
		4'd12: seg0 = 8'b01100011;
		4'd13: seg0 = 8'b10000101;
		4'd14: seg0 = 8'b00100001;
		4'd15: seg0 = 8'b01110001;
	endcase
end
  
endmodule
