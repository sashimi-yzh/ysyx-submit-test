#ifndef __DPI_CSR_HPP__
#define __DPI_CSR_HPP__
#include <stdint.h>

extern "C" void sim_exit(int code);
extern "C" int pmem_read(int raddr);
extern "C" void pmem_write(int waddr, int wdata, uint8_t wmask);
extern "C" void itrace(int inst, int pc);
extern "C" void ftrace(int pc, int npc);
extern "C" void flash_read(int32_t addr, int32_t *data);
extern "C" void mrom_read(int32_t addr, int32_t *data);

#endif