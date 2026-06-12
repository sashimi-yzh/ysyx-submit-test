#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

#define BITMASK(bits) ((1ul << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1))
#define SEXT(x, len) ({ struct { int32_t n : len; } __x = { .n = x }; (uint32_t)__x.n; })
#define SEXT_DYN(x, len) ({ ((x) & (1ul << ((len) - 1))) ? ((x) | ~BITMASK(len)) : (x); })

static void misaligned_load_store(Context *c, bool is_load) {
  printf("Misaligned %s!\n", is_load ? "load" : "store");
  uint32_t inst;
  memcpy(&inst, (void *)c->mepc, 4);
  bool is_w = (inst >> 13) & 1u;
  int len = is_w ? 4 : 2;
  bool is_unsigned = (inst >> 14) & 1u;
  
  uint32_t rd, rs1, src1, rs2, src2, imm;
  rd = BITS(inst, 11, 7);
  rs1 = BITS(inst, 19, 15);
  rs2 = BITS(inst, 24, 20);
  src1 = c->gpr[rs1];

  if (is_load) {
    imm = BITS(inst, 31, 20);
    imm = SEXT(imm, 12);
    char *mem = (char *)(imm + src1);
    c->gpr[rd] = 0;
    memcpy(c->gpr + rd, mem, len);
    if (!is_unsigned && !is_w) {
      c->gpr[rd] = SEXT_DYN(c->gpr[rd], len * 8);
    }
  } else {
    imm = (BITS(inst, 31, 25) << 5) | BITS(inst, 11, 7);
    imm = SEXT(imm, 12);
    src2 = c->gpr[rs2];
    char *mem = (char *)(imm + src1);
    memcpy(mem, &src2, len);
  }
}

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  // int i;
  // for (i = 0; i < NR_REGS; i++) {
  //   printf("x%d: 0x%08x\n", i, c->gpr[i]);
  // }
  // printf("mstatus%d: 0x%08x\n", i, c->mstatus);
  // printf("mcause%d: 0x%08x\n", i, c->mcause);
  // printf("mepc%d: 0x%08x\n", i, c->mepc);
  Event ev = {0};
  switch (c->mcause) {
    case 4u: // Load address misaligned
      misaligned_load_store(c, true);
      c->mepc += 4;
      return c;
    case 6u: // Store/AMO address misaligned
      misaligned_load_store(c, false);
      c->mepc += 4;
      return c;
    case 11u: // Environment call from M-mode
      ev.event = EVENT_YIELD; 
      c->mepc += 4;
      break;
    default: 
      if (user_handler) {
        ev.event = EVENT_ERROR; break;
      } else {
        printf("Unknown trap: mcause=%u\n", c->mcause); 
        assert(0);
      }
  }

  if (user_handler) {
    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

// extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  // asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *ctx = (Context *)((uintptr_t)kstack.end - sizeof(Context));
  ctx->mstatus = 0x1800;
  ctx->mepc = (uintptr_t)entry;
  ctx->gpr[10] = (uintptr_t)arg;
  return ctx;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
