#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <soc.h>

#define UART_TIMEOUT 1

const uart_config_t uart_config_115200_8n1 = {.baud_rate = 115200,
                                              .data_bits = UART_BITS_8,
                                              .stop_bits = UART_STOP_1,
                                              .parity    = UART_PARITY_NONE};

int uart_set_baud_rate(uint32_t baud_rate) {
  uint16_t divisor;
  uint8_t  lcr;

  if (baud_rate == 0) {
    return -1;
  }
  divisor = UART_CLOCK / (16 * baud_rate);

  // check range
  if (divisor == 0 || divisor > 0xFFFF) {
    return -1;
  }

  // get current LCR value
  lcr = inb(LCR_REG);

  // set DLAB bit to access DLL and DLM
  outb(LCR_REG, lcr | LCR_DLAB);

  // set divisor low byte and high byte
  outb(DLL_REG, divisor & 0xFF);
  outb(DLM_REG, (divisor >> 8) & 0xFF);

  // restore LCR value and clear DLAB bit
  outb(LCR_REG, lcr);
  return 0;
}

int uart_set_line_control(uart_data_bits_t data_bits,
                          uart_stop_bits_t stop_bits, uart_parity_t parity) {
  uint8_t lcr = 0;

  switch (data_bits) {
  case UART_BITS_5:
    lcr |= LCR_BITS_5;
    break;
  case UART_BITS_6:
    lcr |= LCR_BITS_6;
    break;
  case UART_BITS_7:
    lcr |= LCR_BITS_7;
    break;
  case UART_BITS_8:
    lcr |= LCR_BITS_8;
    break;
  default:
    return -1;
  }

  switch (stop_bits) {
  case UART_STOP_1:
    lcr |= LCR_STOP_1;
    break;
  case UART_STOP_2:
    lcr |= LCR_STOP_2;
    break;
  default:
    return -1;
  }

  switch (parity) {
  case UART_PARITY_NONE:
    lcr |= LCR_PARITY_NONE;
    break;
  case UART_PARITY_ODD:
    lcr |= LCR_PARITY_ODD;
    break;
  case UART_PARITY_EVEN:
    lcr |= LCR_PARITY_EVEN;
    break;
  case UART_PARITY_MARK:
    lcr |= LCR_PARITY_MARK;
    break;
  case UART_PARITY_SPACE:
    lcr |= LCR_PARITY_SPACE;
    break;
  default:
    return -1;
  }

  //outb(LCR_REG, lcr);

  return 0;
}

int uart_init(const uart_config_t *config) {
  // 1. disable intr
  //outb(IER_REG, 0x00);

  // 2. set baud rate
  if (uart_set_baud_rate(config->baud_rate) != 0) {
    return -1;
  }

  // 3. set line control
  if (uart_set_line_control(config->data_bits, config->stop_bits,
                            config->parity) != 0) {
    return -1;
  }

  // 4. enable FIFO with 14-byte threshold
  //outb(FCR_REG, 0xC7); // enable FIFO, clear, 14-byte trigger level

  // 5. set modem control register
  //outb(MCR_REG, 0x0B); // IRQs enabled, RTS/DSR set

  // 6. restore to normal mode
  //outb(MCR_REG, 0x0F);

  return 0;
}

int __am_uart_init(void) {
  return uart_init(&uart_config_115200_8n1);
}

void putch(char ch) {
  uint32_t timeout = UART_TIMEOUT;
  while (!(inb(LSR_REG) & LSR_THRE)) {
    ;
    if (--timeout == 0)
      break;
  }
  outb(SERIAL_PORT, ch);
}

void __am_uart_tx(AM_UART_TX_T *uart) {
  putch(uart->data);
}

char getch(void) {
  uint32_t timeout = UART_TIMEOUT;

  while (!(inb(LSR_REG) & LSR_DR)) {
    if (--timeout == 0)
      return 0xff;
  }

  return (char)inb(SERIAL_PORT);
}

void __am_uart_rx(AM_UART_RX_T *uart) {
  char ch = getch();
  if (!ch)
    ch = 0xff;
  uart->data = ch;
}
