#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define PSRAM_START 0x80000000
#define PSRAM_SIZE 4 * 1024 * 1024 // 4MB PSRAM
#define SRAM_START 0x0f000000
#define SRAM_SIZE 8 * 1024 // 8KB SRAM
#define SDRAM_START 0xa0000000
#define SDRAM_SIZE 128 * 1024 * 1024 // 128MB SDRAM
#define FLASH_START 0x30000000
#define FLASH_SIZE 256 * 1024 * 1024 // 256MB Flash
#define UART_START 0x10000000
#define UART_SIZE 0x8
uint8_t psram[PSRAM_SIZE];
uint8_t sram[SRAM_SIZE];
uint8_t sdram[SDRAM_SIZE];
extern "C" void flash_read(int32_t addr, int32_t *data);
extern "C" void soc_write(uint32_t addr, uint8_t strb, uint32_t data)
{
	addr = addr & ~0x3; // 对齐到4字节
	uint8_t *write_addr = NULL;
	if (addr >= PSRAM_START && addr < PSRAM_START + PSRAM_SIZE)
	{
		write_addr = psram + (addr - PSRAM_START);
	}
	else if (addr >= SRAM_START && addr < SRAM_START + SRAM_SIZE)
	{
		write_addr = sram + (addr - SRAM_START);
	}
	else if (addr >= SDRAM_START && addr < SDRAM_START + SDRAM_SIZE)
	{
		write_addr = sdram + (addr - SDRAM_START);
	}

	else if (addr >= UART_START && addr < UART_START + UART_SIZE)
	{
		putc(data & 0xFF, stderr); // UART write
		return;
	}
	else
	{
		printf("soc_write: Invalid address 0x%08x\n", addr);
		assert(0 && "Invalid address for soc_write");
		return;
	}
	switch (strb)
	{
	case 0b0001:
		*((uint8_t *)write_addr) = data & 0xFF;
		break;
	case 0b0010:
		*(((uint8_t *)write_addr) + 1) = (data & 0xFF00) >> 8;
		break;
	case 0b0100:
		*(((uint8_t *)write_addr) + 2) = (data & 0xFF0000) >> 16;
		break;
	case 0b1000:
		*(((uint8_t *)write_addr) + 3) = (data & 0xFF000000) >> 24;
		break;
	case 0b0011:
		*((uint16_t *)write_addr) = data & 0xFFFF;
		break;
	case 0b1100:
		*(((uint16_t *)write_addr) + 1) = (data & 0xFFFF0000) >> 16;
		break;
	case 0b1111:
		*((uint32_t *)write_addr) = data;
		break;
	default:
		printf("soc_write: Invalid strb 0x%02x for address 0x%08x\n", strb, addr);
#ifdef WAVE

#endif
		assert(0 && "Invalid strb for soc_write");
		break;
	}
}
extern "C" uint32_t soc_read(uint32_t addr)
{

	addr = addr & ~0x3;
	uint8_t *read_addr = NULL;
	if (addr >= PSRAM_START && addr < PSRAM_START + PSRAM_SIZE)
	{
		read_addr = psram + (addr - PSRAM_START);
	}
	else if (addr >= SRAM_START && addr < SRAM_START + SRAM_SIZE)
	{
		read_addr = sram + (addr - SRAM_START);
	}
	else if (addr >= SDRAM_START && addr < SDRAM_START + SDRAM_SIZE)
	{
		read_addr = sdram + (addr - SDRAM_START);
	}
	else if (addr >= FLASH_START && addr < FLASH_START + FLASH_SIZE)
	{
		int32_t res = 0;
		flash_read(addr - FLASH_START, &res);
		return res;
	}
	else
	{
		printf("soc_read: Invalid address 0x%08x\n", addr);
		assert(0 && "Invalid address for soc_read");
		return 0;
	}
	return *(uint32_t *)read_addr;
}