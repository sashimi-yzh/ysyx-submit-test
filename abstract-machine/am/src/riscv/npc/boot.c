#include <am.h>
#include <klib.h>
#include "include/npc.h"

void putch(char ch) {
  volatile uint8_t *uart = (volatile uint8_t *)(uintptr_t)NPC_UART_ADDR;
  *uart = ch;
}

void halt(int code) {
  *(volatile uint32_t *)NPC_EXIT_MMIO_ADDR = (uint32_t)code;
  asm volatile("mv a0, %0; ebreak" :: "r"(code));
  while (1) {}
}

void print_boot_banner(void) {
  printf("[boot] NPC runtime ready\n");
}
