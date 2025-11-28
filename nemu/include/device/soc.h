
#ifndef __DEVICE_SOC_H__
#define __DEVICE_SOC_H__

#include <common.h>

void uart_write(paddr_t addr, int len, word_t data);

word_t clint_read(paddr_t addr, int len);

#endif