#include "include/difftest.h"
#include "include/CPU.h"

CPU_State dut_CPU_state;

DiffTest::DiffTest()
{
    handle = dlopen("/home/hy5un/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        exit(1);
    }

    difftest_memcpy = (difftest_memcpy_t)dlsym(handle, "difftest_memcpy");
    difftest_regcpy = (difftest_regcpy_t)dlsym(handle, "difftest_regcpy");
    difftest_exec = (difftest_exec_t)dlsym(handle, "difftest_exec");
    difftest_init = (difftest_init_t)dlsym(handle, "difftest_init");

    if (!difftest_memcpy || !difftest_regcpy || !difftest_exec)
    {
        fprintf(stderr, "dlsym error: %s\n", dlerror());
        dlclose(handle);
        exit(1);
    }

#if USE_YSYXSOC
    difftest_memcpy(0x30000000, flash, bin_size, DIFFTEST_TO_REF);
    dut_CPU_state.nextPc = 0x30000000;
#else
    difftest_memcpy(0x80000000, memory, bin_size, DIFFTEST_TO_REF);
    dut_CPU_state.nextPc = 0x80000000;
#endif
    difftest_init(&dut_CPU_state);

}

DiffTest::~DiffTest()
{
    dlclose(handle);
}

bool DiffTest::step()
{
    total_step_count++;
    difftest_exec(1);
    difftest_regcpy(&ref_CPU_state, DIFFTEST_TO_DUT);

    bool mismatch = false;
    if (ref_CPU_state.nextPc != dut_CPU_state.nextPc)
    {
        printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): nextPC mismatch: DUT=0x%08x, REF=0x%08x\n",
               cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, dut_CPU_state.nextPc, ref_CPU_state.nextPc);
        mismatch = true;
    }

    for (int i = 0; i < 16; i++)
    {
        if (dut_CPU_state.gpr[i] != ref_CPU_state.gpr[i])
        {
            printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): GPR x%d mismatch: DUT=0x%08x, REF=0x%08x\n",
                   cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, i,
                   dut_CPU_state.gpr[i], ref_CPU_state.gpr[i]);
            mismatch = true;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (dut_CPU_state.csr[i] != ref_CPU_state.csr[i])
        {
            printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): CSR %d mismatch at pc 0x%08x: DUT=0x%08x, REF=0x%08x\n",
                   cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, i, ref_CPU_state.nextPc,
                   dut_CPU_state.csr[i], ref_CPU_state.csr[i]);
            mismatch = true;
        }
    }

    // if (dut_CPU_state.memRValid || ref_CPU_state.memRValid)
    // {
    //     if (dut_CPU_state.memRValid != ref_CPU_state.memRValid)
    //     {
    //         printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): MEM Read Valid mismatch: DUT=%d, REF=%d\n",
    //                cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, dut_CPU_state.memRValid, ref_CPU_state.memRValid);
    //         mismatch = true;
    //     }
    //     else
    //     {
    //         if (dut_CPU_state.memAddr != ref_CPU_state.memAddr)
    //         {
    //             printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): MEM Read Addr mismatch: DUT=0x%08x, REF=0x%08x\n",
    //                    cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, dut_CPU_state.memAddr, ref_CPU_state.memAddr);
    //             mismatch = true;
    //         }
    //         if(dut_CPU_state.memRdata != ref_CPU_state.memRdata)
    //         {
    //             printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): MEM Read Data mismatch: DUT=0x%08x, REF=0x%08x\n",
    //                    cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, dut_CPU_state.memRdata, ref_CPU_state.memRdata);
    //             mismatch = true;
    //         }
    //     }
    // }
    if (dut_CPU_state.memWValid || ref_CPU_state.memWValid)
    {
        if (dut_CPU_state.memWValid != ref_CPU_state.memWValid)
        {
            printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): MEM Write Valid mismatch: DUT=%d, REF=%d\n",
                   cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, dut_CPU_state.memWValid, ref_CPU_state.memWValid);
            mismatch = true;
        }
        else
        {
            if (dut_CPU_state.memAddr != ref_CPU_state.memAddr)
            {
                printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): MEM Write Addr mismatch: DUT=0x%08x, REF=0x%08x\n",
                       cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, dut_CPU_state.memAddr, ref_CPU_state.memAddr);
                mismatch = true;
            }
            if(dut_CPU_state.memWdata != ref_CPU_state.memWdata)
            {
                printf("\n[NPC] Difftest(PC: 0x%08x Tag: 0x%02x Step: %lld Cycle: %lld): MEM Write Data mismatch: DUT=0x%08x, REF=0x%08x\n",
                       cpu->pc, cpu->pc_tag, total_step_count, cpu->cycle_count, dut_CPU_state.memWdata, ref_CPU_state.memWdata);
                mismatch = true;
            }
        }
    }


    if (mismatch)
    {
        cpu->reg_print();
    }

    return !mismatch;
}

void dpic_save_cpu_state(int nextPC, int pc, char pc_tag, int inst, int memAddr, int memRdata, int memWdata, svBit memRValid, svBit memWValid, int csr_0, int csr_1, int csr_2, int csr_3)
{
    dut_CPU_state.nextPc = (word_t)nextPC;
    dut_CPU_state.memAddr = (word_t)memAddr;
    dut_CPU_state.memRdata = (word_t)memRdata;
    dut_CPU_state.memWdata = (word_t)memWdata;
    dut_CPU_state.memRValid = (bool)memRValid;
    dut_CPU_state.memWValid = (bool)memWValid;

    dut_CPU_state.csr[0] = (word_t)csr_0;
    dut_CPU_state.csr[1] = (word_t)csr_1;
    dut_CPU_state.csr[2] = (word_t)csr_2;
    dut_CPU_state.csr[3] = (word_t)csr_3;

    cpu->pc = (word_t)pc;
    cpu->pc_tag = (uint8_t)pc_tag;
    cpu->nextPc = (word_t)nextPC;
    cpu->inst = (word_t)inst;
}

void dpic_save_gprs(
    int gpr0, int gpr1, int gpr2, int gpr3,
    int gpr4, int gpr5, int gpr6, int gpr7,
    int gpr8, int gpr9, int gpr10, int gpr11,
    int gpr12, int gpr13, int gpr14, int gpr15)
{
    dut_CPU_state.gpr[0] = (word_t)gpr0;
    dut_CPU_state.gpr[1] = (word_t)gpr1;
    dut_CPU_state.gpr[2] = (word_t)gpr2;
    dut_CPU_state.gpr[3] = (word_t)gpr3;
    dut_CPU_state.gpr[4] = (word_t)gpr4;
    dut_CPU_state.gpr[5] = (word_t)gpr5;
    dut_CPU_state.gpr[6] = (word_t)gpr6;
    dut_CPU_state.gpr[7] = (word_t)gpr7;
    dut_CPU_state.gpr[8] = (word_t)gpr8;
    dut_CPU_state.gpr[9] = (word_t)gpr9;
    dut_CPU_state.gpr[10] = (word_t)gpr10;
    dut_CPU_state.gpr[11] = (word_t)gpr11;
    dut_CPU_state.gpr[12] = (word_t)gpr12;
    dut_CPU_state.gpr[13] = (word_t)gpr13;
    dut_CPU_state.gpr[14] = (word_t)gpr14;
    dut_CPU_state.gpr[15] = (word_t)gpr15;
}
