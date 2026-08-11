#include <klib-macros.h>

#include "include/npc.h"

// Image boundaries supplied by the ysyxSoC linker script.
extern char _data_load_start;
extern char _data_start;
extern char _data_end;
extern char _bss_start;
extern char _bss_end;

#define SSBL_CODE __attribute__((section(".ssbl.text"), noinline, used))
#define SSBL_INLINE static inline __attribute__((always_inline))

enum {
  SSBL_UART_POLL_LIMIT = 100000u,
  SSBL_PROGRESS_WIDTH = 32u,
};

SSBL_INLINE void ssbl_uart_init(void) {
  volatile uint8_t *registers =
      (volatile uint8_t *)(uintptr_t)YSYXSOC_UART_BASE;
  registers[UART_LINE_CONTROL_OFFSET] = UART_CONTROL_DLAB;
  registers[UART_DIVISOR_LOW_OFFSET] = UART_DIVISOR_LOW_VALUE;
  registers[UART_DIVISOR_HIGH_OFFSET] = UART_DIVISOR_HIGH_VALUE;
  registers[UART_FIFO_CONTROL_OFFSET] = UART_FIFO_INIT_VALUE;
  registers[UART_LINE_CONTROL_OFFSET] = UART_CONTROL_8N1;
}

SSBL_INLINE void ssbl_uart_putc(uint8_t ch) {
  volatile uint8_t *registers =
      (volatile uint8_t *)(uintptr_t)YSYXSOC_UART_BASE;
  uint32_t remaining_polls = SSBL_UART_POLL_LIMIT;

  while ((registers[UART_LINE_STATUS_OFFSET] & UART_STATUS_TX_READY) == 0u) {
    remaining_polls--;
    if (remaining_polls == 0u) {
      return;
    }
  }
  registers[UART_TX_DATA_OFFSET] = ch;
}

SSBL_INLINE void ssbl_print_load_label(void) {
  ssbl_uart_putc('L');
  ssbl_uart_putc('O');
  ssbl_uart_putc('A');
  ssbl_uart_putc('D');
  ssbl_uart_putc(' ');
  ssbl_uart_putc('[');
}

SSBL_INLINE void ssbl_bar_init(void) {
  ssbl_print_load_label();
  for (uint32_t cell = 0; cell < SSBL_PROGRESS_WIDTH; cell++) {
    ssbl_uart_putc(' ');
  }
  ssbl_uart_putc(']');
  ssbl_uart_putc('\r');
  ssbl_print_load_label();
}

SSBL_INLINE void ssbl_bar_close(void) {
  ssbl_uart_putc(']');
  ssbl_uart_putc('\n');
}

SSBL_CODE void __am_ssbl_load(void) {
  uintptr_t source = (uintptr_t)&_data_load_start;
  uintptr_t destination = (uintptr_t)&_data_start;
  const uintptr_t destination_end = (uintptr_t)&_data_end;
  const uintptr_t copy_bytes = destination_end - destination;
  const uintptr_t aligned_copy_bytes = copy_bytes & ~(uintptr_t)3u;
  uintptr_t progress_step =
      (aligned_copy_bytes / SSBL_PROGRESS_WIDTH) & ~(uintptr_t)3u;
  uintptr_t next_progress;
  uint32_t completed_cells = 0;

  if (progress_step < 4u) {
    progress_step = 4u;
  }
  next_progress = destination + progress_step;

  ssbl_uart_init();
  ssbl_bar_init();

  while (destination + 4u <= destination_end) {
    const uint32_t value = *(volatile const uint32_t *)source;
    *(volatile uint32_t *)destination = value;
    source += 4u;
    destination += 4u;

    if (completed_cells < SSBL_PROGRESS_WIDTH &&
        destination >= next_progress) {
      ssbl_uart_putc('=');
      completed_cells++;
      next_progress += progress_step;
    }
  }

  while (destination < destination_end) {
    const uint8_t value = *(volatile const uint8_t *)source;
    *(volatile uint8_t *)destination = value;
    source++;
    destination++;
  }

  while (completed_cells < SSBL_PROGRESS_WIDTH) {
    ssbl_uart_putc('=');
    completed_cells++;
  }
  ssbl_bar_close();

  uintptr_t bss = (uintptr_t)&_bss_start;
  const uintptr_t bss_end = (uintptr_t)&_bss_end;

  while (bss + 4u <= bss_end) {
    *(volatile uint32_t *)bss = 0u;
    bss += 4u;
  }

  while (bss < bss_end) {
    *(volatile uint8_t *)bss = 0u;
    bss += 1u;
  }
}
