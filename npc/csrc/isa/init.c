#include <memory/paddr.h>
#include <common.h>

static const uint32_t img [] = {
  0x00500093, // ADDI x1, x0, 5   # x1 = x0 + 5 = 0 + 5 = 5
  0xffd08113, // ADDI x2, x1, -3  # x2 = x1 + (-3) = x1 - 3
  0x00018193, // ADDI x3, x3, 0   # x3 = x3 + 0 = x3（无操作，可用于寄存器依赖同步）
  0x7ff20213, // ADDI x4, x4, 2047  # x4 = x4 + 2047
  0x80028293, // ADDI x5, x5, -2048  # x5 = x5 - 2048
  0x00100073, // ebreak
};

void init_isa() {
  /* Load built-in image. */
  #ifdef PLATFORM_YSYXSOC
  memcpy(mrom_guest_to_host(MROM_RESET_VECTOR), img, sizeof(img));
  #else
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  #endif
}