#include "npc.h"
#include "tpdef.h"
#include "util.h"
#include "memory.h"

#include <assert.h>
#include <cstdio>
#include <dlfcn.h>

typedef void (*diff_memcpy)(paddr_t, void *, size_t , bool);
diff_memcpy ref_difftest_memcpy  = nullptr;
typedef void (*diff_regcpy)(void *, bool);
diff_regcpy ref_difftest_regcpy = nullptr;
typedef void (*diff_exec)(uint64_t);
diff_exec ref_difftest_exec = nullptr;
typedef uint64_t (*diff_sim)(word_t*, word_t*);
diff_sim ref_difftest_sim = nullptr;
typedef void (*diff_raise_intr)(uint64_t);
diff_raise_intr ref_difftest_raise_intr = nullptr;
typedef void (*diff_nop)(void*, word_t);
diff_nop ref_difftest_nop = nullptr;
typedef void (*diff_init)(int, word_t);
diff_init ref_difftest_init = nullptr;


void nemu_init(long img_size, int port)
{
#ifdef RUNSOC
    ref_difftest_init(port, 0x30000000);
#else
    ref_difftest_init(port, 0x80000000);
#endif

    ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
    
    word_t regbuf[32] = {};
    reg_value(regbuf);
    ref_difftest_regcpy(regbuf, DIFFTEST_TO_REF);
}


void init_difftest(long img_size, int port) 
{
    char path[512];
    const char *npc_home = getenv("NPC_HOME");
    assert(npc_home);

    snprintf(path, sizeof(path), "%s/riscv32-nemu-interpreter-so", npc_home);

    void *handle = dlopen(path, RTLD_LAZY);
    assert(handle);

    ref_difftest_memcpy = (diff_memcpy)dlsym(handle, "difftest_memcpy");
    assert(ref_difftest_memcpy);
  
    ref_difftest_regcpy = (diff_regcpy)dlsym(handle, "difftest_regcpy");
    assert(ref_difftest_regcpy);
  
    ref_difftest_exec = (diff_exec)dlsym(handle, "difftest_exec");
    assert(ref_difftest_exec);

    ref_difftest_sim = (diff_sim)dlsym(handle, "difftest_sim");
    assert(ref_difftest_sim);
  
    ref_difftest_raise_intr = (diff_raise_intr)dlsym(handle, "difftest_raise_intr");
    assert(ref_difftest_raise_intr);

    ref_difftest_nop = (diff_nop)dlsym(handle, "difftest_nop");
    assert(ref_difftest_nop);
    
    ref_difftest_init = (diff_init)dlsym(handle, "difftest_init");
    assert(ref_difftest_init);

    nemu_init(img_size, port);
}
  

bool difftest_step(paddr_t pc)
{
    bool ret = true;

    word_t nemu_reg[32] = {};
    word_t npc_reg[32] = {};
    
    ref_difftest_exec(1);
    ref_difftest_regcpy(nemu_reg, DIFFTEST_TO_DUT);
    reg_value(npc_reg);

    for (int i = 0; i < 16; i++)
    {
        if (nemu_reg[i] != npc_reg[i])
        {
            printf(ANSI_FMT("0x%08x reg: [%s] error [npc: 0x%08x] [nemu: 0x%08x]\n", ANSI_FG_RED), 
                pc, reg_name(i), npc_reg[i], nemu_reg[i]);
            ret = false;
        }
    }
    
    return ret;
}


void difftest_nop(word_t pc)
{
    word_t regs[16] = { 0 };
    reg_value(regs);
    ref_difftest_nop(regs, pc);
}