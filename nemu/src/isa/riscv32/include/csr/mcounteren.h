#ifndef __CSR_MCOUNTEREN_H__
#define __CSR_MCOUNTEREN_H__

#include <stdbool.h>
#include <stdint.h>

#define MCOUNTEREN_CY (1u << 0)
#define MCOUNTEREN_TM (1u << 1)
#define MCOUNTEREN_IR (1u << 2)
#define MCOUNTEREN_MASK (MCOUNTEREN_CY | MCOUNTEREN_TM | MCOUNTEREN_IR)

static inline uint32_t counteren_bit_from_csr(uint32_t csr_num) {
  switch (csr_num & 0xfffu) {
  case 0xc00:
  case 0xc80:
    return MCOUNTEREN_CY;
  case 0xc01:
  case 0xc81:
    return MCOUNTEREN_TM;
  case 0xc02:
  case 0xc82:
    return MCOUNTEREN_IR;
  default:
    return 0;
  }
}

static inline bool counteren_allows(CPU_MODE priv, uint32_t mcounteren,
                                    uint32_t scounteren, uint32_t bit) {
  if (bit == 0) {
    return true;
  }

  switch (priv) {
  case M_MODE:
    return true;
  case S_MODE:
    return (mcounteren & bit) != 0;
  case U_MODE:
    return (mcounteren & bit) != 0 && (scounteren & bit) != 0;
  default:
    return false;
  }
}

#endif
