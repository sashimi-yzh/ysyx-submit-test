#include <nvboard.h>
#include "VysyxSoCFull.h"

void nvboard_bind_all_pins(VysyxSoCFull* top) {
	nvboard_bind_pin( &top->externalPins_gpio_out, 16, LD15, LD14, LD13, LD12, LD11, LD10, LD9, LD8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->externalPins_gpio_in, 16, SW15, SW14, SW13, SW12, SW11, SW10, SW9, SW8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->externalPins_gpio_seg_0, 7, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
	nvboard_bind_pin( &top->externalPins_gpio_seg_1, 7, SEG1G, SEG1F, SEG1E, SEG1D, SEG1C, SEG1B, SEG1A);
	nvboard_bind_pin( &top->externalPins_gpio_seg_2, 7, SEG2G, SEG2F, SEG2E, SEG2D, SEG2C, SEG2B, SEG2A);
	nvboard_bind_pin( &top->externalPins_gpio_seg_3, 7, SEG3G, SEG3F, SEG3E, SEG3D, SEG3C, SEG3B, SEG3A);
	nvboard_bind_pin( &top->externalPins_gpio_seg_4, 7, SEG4G, SEG4F, SEG4E, SEG4D, SEG4C, SEG4B, SEG4A);
	nvboard_bind_pin( &top->externalPins_gpio_seg_5, 7, SEG5G, SEG5F, SEG5E, SEG5D, SEG5C, SEG5B, SEG5A);
	nvboard_bind_pin( &top->externalPins_gpio_seg_6, 7, SEG6G, SEG6F, SEG6E, SEG6D, SEG6C, SEG6B, SEG6A);
	nvboard_bind_pin( &top->externalPins_gpio_seg_7, 7, SEG7G, SEG7F, SEG7E, SEG7D, SEG7C, SEG7B, SEG7A);
	nvboard_bind_pin( &top->externalPins_uart_tx, 1, UART_TX);
	nvboard_bind_pin( &top->externalPins_uart_rx, 1, UART_RX);
	nvboard_bind_pin( &top->externalPins_ps2_data, 1, PS2_DAT);
	nvboard_bind_pin( &top->externalPins_ps2_clk, 1, PS2_CLK);
	nvboard_bind_pin( &top->externalPins_vga_r, 8, VGA_R7, VGA_R6, VGA_R5, VGA_R4, VGA_R3, VGA_R2, VGA_R1, VGA_R0);
	nvboard_bind_pin( &top->externalPins_vga_g, 8, VGA_G7, VGA_G6, VGA_G5, VGA_G4, VGA_G3, VGA_G2, VGA_G1, VGA_G0);
	nvboard_bind_pin( &top->externalPins_vga_b, 8, VGA_B7, VGA_B6, VGA_B5, VGA_B4, VGA_B3, VGA_B2, VGA_B1, VGA_B0);
	nvboard_bind_pin( &top->externalPins_vga_hsync, 1, VGA_HSYNC);
	nvboard_bind_pin( &top->externalPins_vga_vsync, 1, VGA_VSYNC);
	nvboard_bind_pin( &top->externalPins_vga_valid, 1, VGA_BLANK_N);
}
