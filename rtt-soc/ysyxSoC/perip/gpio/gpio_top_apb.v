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

  localparam GPIO_OUT     = 4'h0;
  localparam GPIO_IN      = 4'h4;
  localparam GPIO_SEGMENT = 4'h8;
  
  reg [7:0] seg_decoder [0:15];
  
  reg [15:0] gpio_out_reg;
  reg [31:0] gpio_segment_reg;
  
  reg [31:0] prdata_reg;
  reg        pready_reg;
  reg        pslverr_reg;
  
  initial begin
    seg_decoder[4'h0]  = 8'b11111100;
    seg_decoder[4'h1]  = 8'b01100000;
    seg_decoder[4'h2]  = 8'b11011010;
    seg_decoder[4'h3]  = 8'b11110010;
    seg_decoder[4'h4]  = 8'b01100110;
    seg_decoder[4'h5]  = 8'b10110110;
    seg_decoder[4'h6]  = 8'b10111110;
    seg_decoder[4'h7]  = 8'b11100000;
    seg_decoder[4'h8]  = 8'b11111110;
    seg_decoder[4'h9]  = 8'b11110110;
    seg_decoder[4'ha]  = 8'b11101110;
    seg_decoder[4'hb]  = 8'b00111110;
    seg_decoder[4'hc]  = 8'b10011100;
    seg_decoder[4'hd]  = 8'b01111010;
    seg_decoder[4'he]  = 8'b10011110;
    seg_decoder[4'hf]  = 8'b10001110;
  end
  
  assign in_pready  = pready_reg;
  assign in_prdata  = prdata_reg;
  assign in_pslverr = pslverr_reg;
  
  assign gpio_out = gpio_out_reg;
  
  assign gpio_seg_0 = ~seg_decoder[gpio_segment_reg[ 3: 0]];
  assign gpio_seg_1 = ~seg_decoder[gpio_segment_reg[ 7: 4]];
  assign gpio_seg_2 = ~seg_decoder[gpio_segment_reg[11: 8]];
  assign gpio_seg_3 = ~seg_decoder[gpio_segment_reg[15:12]];
  assign gpio_seg_4 = ~seg_decoder[gpio_segment_reg[19:16]];
  assign gpio_seg_5 = ~seg_decoder[gpio_segment_reg[23:20]];
  assign gpio_seg_6 = ~seg_decoder[gpio_segment_reg[27:24]];
  assign gpio_seg_7 = ~seg_decoder[gpio_segment_reg[31:28]];
  
  always @(posedge clock or posedge reset) begin
    if (reset) begin
      gpio_out_reg <= 16'h0000;
      gpio_segment_reg   <= 32'h00000000;
      prdata_reg    <= 32'h00000000;
      pready_reg    <= 1'b0;
      pslverr_reg   <= 1'b0;
    end else begin
      pready_reg   <= 1'b0;
      pslverr_reg  <= 1'b0;
      
      if (in_psel && !in_penable) begin
        if (in_pwrite) begin
          pready_reg <= 1'b1;
          
          case (in_paddr[3:0])
            GPIO_OUT: begin
              if (in_pstrb[0]) gpio_out_reg[ 7:0]  <= in_pwdata[ 7:0];
              if (in_pstrb[1]) gpio_out_reg[15:8]  <= in_pwdata[15:8];
            end
            
            GPIO_SEGMENT: begin
              if (in_pstrb[0]) gpio_segment_reg[ 7: 0]   <= in_pwdata[ 7: 0];
              if (in_pstrb[1]) gpio_segment_reg[15: 8]   <= in_pwdata[15: 8];
              if (in_pstrb[2]) gpio_segment_reg[23:16]   <= in_pwdata[23:16];
              if (in_pstrb[3]) gpio_segment_reg[31:24]   <= in_pwdata[31:24];
            end
            
            default: begin
              pslverr_reg <= 1'b1;
            end
          endcase
        end else begin
          pready_reg <= 1'b1;
          
          case (in_paddr[3:0])
            GPIO_OUT: begin
              prdata_reg <= {16'h0000, gpio_out_reg};
            end
            GPIO_IN: begin
              prdata_reg <= {16'h0000, gpio_in};
            end
            GPIO_SEGMENT: begin
              prdata_reg <= gpio_segment_reg;
            end
            default: begin
              prdata_reg  <= 32'h00000000;
              pslverr_reg <= 1'b1;
            end
          endcase
        end
      end
    end
  end

endmodule
    