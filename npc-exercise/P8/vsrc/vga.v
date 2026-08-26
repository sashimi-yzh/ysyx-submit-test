module vga(
	input clk,
	input reset,
	output vsync,
	output hsync,
	output valid,
	output [7:0]vga_r,
	output [7:0]vga_g,
	output [7:0]vga_b
);
wire [9:0] v_addr;
wire [9:0] h_addr;
reg [23:0] vga_data;
image_rom_640x480 u_rom(clk,reset,v_addr,h_addr,vga_data);
vga_ctrl u_vga_ctrl (clk,reset,vga_data,h_addr,v_addr,hsync,vsync,valid,vga_r,vga_g,vga_b);
endmodule
