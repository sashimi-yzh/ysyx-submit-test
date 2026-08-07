#include <am.h>
#include <stdio.h>
static int phase = 0;

static Context *trap_handler(Event ev, Context *ctx) {
  switch (ev.event) {
  case EVENT_ERROR:
    if (phase == 0 && ctx->mcause == 0) {
      printf("hit InstructionAddressMisaligned\n");
      phase = 1;
      ctx->mepc += 4;
      return ctx;
    }
    if (phase == 1 && ctx->mcause == 4) {
      printf("hit LoadAddressMisaligned\n");
      phase = 2;
      ctx->mepc += 4;
      return ctx;
    }
    if (phase == 2 && ctx->mcause == 6) {
      printf("hit Store_AMO_AddressMisaligned\n");
      halt(0);
    }
    break;
  default:
    break;
  }
  printf("hit null\n");
  halt(1);
  return ctx;
}

int main() {
  uint32_t buf[4] __attribute__((aligned(16))) = {0};

  cte_init(trap_handler);

  asm volatile("li  t0, 0x2\n\t"
               "jalr zero, t0, 0\n\t"

               "addi t0, %[ptr], 1\n\t"
               "lw   t1, 0(t0)\n\t"

               "addi t0, %[ptr], 1\n\t"
               "li   t1, 0xdeadbeef\n\t"
               "sw   t1, 0(t0)\n\t"
               :
               : [ptr] "r"(buf)
               : "t0", "t1", "memory");

  halt(1);
  return 0;
}
