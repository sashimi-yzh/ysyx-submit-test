module image_rom_640x480 (
    input wire clk,
    input wire reset,
    input wire [9:0] v_addr,
    input wire [9:0] h_addr,
    output reg [23:0] vga_data
);

localparam WIDTH = 640;
localparam HEIGHT = 480;
localparam TOTAL_PIXELS = WIDTH * HEIGHT;

reg [23:0] rom [0:TOTAL_PIXELS-1];

wire [18:0] linear_addr; 
reg [18:0] addr_reg;

assign linear_addr = v_addr * 10'd640 + {9'd0, h_addr};
always @(posedge clk or posedge reset) begin
    if (reset) begin
        vga_data <= 24'h000000;
        addr_reg <= 19'd0;
    end else begin
        addr_reg <= linear_addr;
        
        if (v_addr < HEIGHT && h_addr < WIDTH) begin
            vga_data <= rom[addr_reg];
        end else begin
            vga_data <= 24'h000000;
        end
    end
end

initial begin
    $readmemh("image_data.mif", rom);
end

endmodule
