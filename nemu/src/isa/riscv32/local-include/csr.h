#ifndef RISCV32_LOCAL_CSR_H
#define RISCV32_LOCAL_CSR_H

#include <stdbool.h>
#include <stdint.h>

void riscv_csr_reset(void);
bool riscv_csr_read(uint32_t csr_num, uint32_t *data);
bool riscv_csr_write(uint32_t csr_num, uint32_t data);
uint32_t riscv_csr_mip_value(void);
void riscv_csr_set_device_pending(uint32_t mask, bool pending);

#endif
