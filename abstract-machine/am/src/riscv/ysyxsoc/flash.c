#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>

#define FLASH_BASE 0x30000000
#define FLASH_SIZE 0x10000000

#define FLASH_RX0 (*(volatile uint8_t *)(FLASH_BASE + 0))   // R  Data Receive reg0
#define FLASH_RX1 (*(volatile uint8_t *)(FLASH_BASE + 4))   // R  Data Receive reg1
#define FLASH_RX2 (*(volatile uint8_t *)(FLASH_BASE + 8))   // R  Data Receive reg2
#define FLASH_RX3 (*(volatile uint8_t *)(FLASH_BASE + 12))  // R  Data Receive reg3

#define FLASH_TX0 (*(volatile uint8_t *)(FLASH_BASE + 0))   // RW  Data Transmit reg0
#define FLASH_TX1 (*(volatile uint8_t *)(FLASH_BASE + 4))   // RW  Data Transmit reg1
#define FLASH_TX2 (*(volatile uint8_t *)(FLASH_BASE + 8))   // RW  Data Transmit reg2
#define FLASH_TX3 (*(volatile uint8_t *)(FLASH_BASE + 0xc)) // RW  Data Transmit reg3

#define FLASH_CTRL (*(volatile uint8_t *)(FLASH_BASE + 0x10)) // RW  Control and Status reg
#define FLASH_DIV  (*(volatile uint8_t *)(FLASH_BASE + 0x14)) // RW  Clock Divider reg
#define FLASH_SS   (*(volatile uint8_t *)(FLASH_BASE + 0x18)) // RW  Slave Select reg


