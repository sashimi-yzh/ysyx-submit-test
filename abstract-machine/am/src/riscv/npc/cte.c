#include <npc.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c)
{
    if (user_handler) {
        Event ev = {0};
        switch (c->mcause) {
        case 11:
            ev.event = EVENT_YIELD;
            // printf("ecall from M-mode\n");
            c->mepc += 4; // skip ecall instruction
            break;
        default:
            ev.event = EVENT_ERROR;
            break;
        }

        // for (int i=0; i<32; i++) printf("context reg[%d] = 0x%08x\n", i, c->gpr[i]);
        // printf("context mcause = 0x%08x\n", c->mcause);
        // printf("context mstatus = 0x%08x\n", c->mstatus);
        // printf("context mepc = 0x%08x\n", c->mepc);

        // halt(1);


        c = user_handler(ev, c);

        // printf("sp = 0x%08x\n", (uintptr_t)c->gpr[2]);
        assert(c != NULL);
    }

    return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *))
{
    // initialize exception entry
    asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
    // printf("mtvec set to %p\n", __am_asm_trap);

    // register event handler
    user_handler = handler;

    return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg)
{
    Context *c = (Context *)kstack.end - 1;
    c = (Context *)((uintptr_t)c & ~0xF); // align to 16 bytes

    // c->gpr[2] = (uintptr_t)kstack.end; // sp
    c->gpr[10] = (uintptr_t)arg; // a0
    c->mstatus = 0x00001800; // MPP = 11 (machine mode)
    c->mepc = (uintptr_t)entry;

    // printf("kstack.end = 0x%08x\n", (uintptr_t)kstack.end);
    // printf("sp  = 0x%08x\n", (uintptr_t)c->gpr[2]);
    // printf("c = 0x%08x\n", (uintptr_t)c);

    return c;

}

void yield()
{
#ifdef __riscv_e
    asm volatile("li a5, -1; ecall");
#else
    asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled()
{
    return false;
}

void iset(bool enable)
{
}