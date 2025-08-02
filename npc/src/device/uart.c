#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern "C" void uart_putchar(uint32_t data) {
    putchar(data);
}
