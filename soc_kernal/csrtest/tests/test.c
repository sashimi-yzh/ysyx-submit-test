#include <klib.h>
#include <stdint.h>

int main() {
  register uint32_t a = 0xabcdef12;
  register uint32_t b = 0x12345678;
  for (int i = 0; i < 16; i++) {
    asm volatile("csrw mtvec, %0" ::"r"(a) :);
    asm volatile("csrrw %0, mtvec, %1" ::"r"(a), "r"(b) :);

    asm volatile("csrw mepc, %0" ::"r"(a) :);
    asm volatile("csrrw %0, mepc, %1" ::"r"(a), "r"(b) :);
    a += 1;
    b -= 1;
  }
}