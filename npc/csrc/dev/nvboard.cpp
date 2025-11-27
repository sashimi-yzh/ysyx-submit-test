#ifdef RUNSOC

#include "VysyxSoCFull.h"

#include <nvboard.h>


static void nvboard_bind_all_pins(VysyxSoCFull* top)
{
    nvboard_bind_pin( &top->externalPins_vga_vsync, 1, VGA_VSYNC);
    nvboard_bind_pin( &top->externalPins_vga_hsync, 1, VGA_HSYNC);
    nvboard_bind_pin( &top->externalPins_vga_valid, 1, VGA_BLANK_N);
    nvboard_bind_pin( &top->externalPins_vga_r, 8, VGA_R7, VGA_R6, VGA_R5, VGA_R4, VGA_R3, VGA_R2, VGA_R1, VGA_R0);
    nvboard_bind_pin( &top->externalPins_vga_g, 8, VGA_G7, VGA_G6, VGA_G5, VGA_G4, VGA_G3, VGA_G2, VGA_G1, VGA_G0);
    nvboard_bind_pin( &top->externalPins_vga_b, 8, VGA_B7, VGA_B6, VGA_B5, VGA_B4, VGA_B3, VGA_B2, VGA_B1, VGA_B0);
    nvboard_bind_pin( &top->externalPins_gpio_out, 16, LD15, LD14, LD13, LD12, LD11, LD10, LD9, LD8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
    nvboard_bind_pin( &top->externalPins_gpio_in, 16, SW15, SW14, SW13, SW12, SW11, SW10, SW9, SW8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
    // nvboard_bind_pin( &top->btn, 5, BTNL, BTNU, BTNC, BTND, BTNR);
    nvboard_bind_pin( &top->externalPins_gpio_seg_0, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
    nvboard_bind_pin( &top->externalPins_gpio_seg_1, 8, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
    nvboard_bind_pin( &top->externalPins_gpio_seg_2, 8, SEG2A, SEG2B, SEG2C, SEG2D, SEG2E, SEG2F, SEG2G, DEC2P);
    nvboard_bind_pin( &top->externalPins_gpio_seg_3, 8, SEG3A, SEG3B, SEG3C, SEG3D, SEG3E, SEG3F, SEG3G, DEC3P);
    nvboard_bind_pin( &top->externalPins_gpio_seg_4, 8, SEG4A, SEG4B, SEG4C, SEG4D, SEG4E, SEG4F, SEG4G, DEC4P);
    nvboard_bind_pin( &top->externalPins_gpio_seg_5, 8, SEG5A, SEG5B, SEG5C, SEG5D, SEG5E, SEG5F, SEG5G, DEC5P);
    nvboard_bind_pin( &top->externalPins_gpio_seg_6, 8, SEG6A, SEG6B, SEG6C, SEG6D, SEG6E, SEG6F, SEG6G, DEC6P);
    nvboard_bind_pin( &top->externalPins_gpio_seg_7, 8, SEG7A, SEG7B, SEG7C, SEG7D, SEG7E, SEG7F, SEG7G, DEC7P);
    nvboard_bind_pin( &top->externalPins_ps2_clk, 1, PS2_CLK);
    nvboard_bind_pin( &top->externalPins_ps2_data, 1, PS2_DAT);
    nvboard_bind_pin( &top->externalPins_uart_tx, 1, UART_TX);
    nvboard_bind_pin( &top->externalPins_uart_rx, 1, UART_RX);
}


void nvboard_initialize(VysyxSoCFull *top)
{
    nvboard_bind_all_pins(top);
    nvboard_init();
}


void nvboard_renew()
{
    nvboard_update();
}


void nvboard_free()
{
    nvboard_quit();
}

#endif