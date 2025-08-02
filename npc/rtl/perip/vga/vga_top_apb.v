module vga_top_apb(
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

  output [7:0]  vga_r,
  output [7:0]  vga_g,
  output [7:0]  vga_b,
  output        vga_hsync,
  output        vga_vsync,
  output        vga_valid
);

reg   [31:0]  frame_buffer  [640*480 - 1: 0];
wire  [23:0]  vga_data  ;
wire  [9:0]   h_addr    ;
wire  [9:0]   v_addr    ;
wire  [18:0]  frame_buffer_addr ;

wire  [18:0]  addr  ;
wire  [31:0]  in_paddr_shift  ;


assign  in_paddr_shift  = (in_paddr >>  2)  ;
assign    addr  = in_paddr_shift[18:0]  ;

always @(posedge clock ) begin
  if(in_psel  &&  in_penable  &&  in_pwrite)
    frame_buffer[addr]  <=  in_pwdata ;
end


assign  frame_buffer_addr = (v_addr[8:0] * 640 + {9'd0, h_addr});

assign  vga_data  = frame_buffer[frame_buffer_addr][23:0];

assign in_pready = 1'b1;
assign in_pslverr = 1'b0;

vga_ctrl vga_ctrl (
  .pclk       (clock      ),    
  .reset      (reset      ),   
  .vga_data   (vga_data   ),
  .h_addr     (h_addr     ),  
  .v_addr     (v_addr     ),
  .hsync      (vga_hsync  ),   
  .vsync      (vga_vsync  ),
  .valid      (vga_valid  ),   
  .vga_r      (vga_r      ),   
  .vga_g      (vga_g      ),
  .vga_b      (vga_b      )
);

endmodule
