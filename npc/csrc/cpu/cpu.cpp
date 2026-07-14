#include "include/common.h"
#include "include/trace.h"
#include "include/CPU.h"
#include "config.h"
#include <chrono>
#ifdef USE_NVBOARD
#include "nvboard.h"
#endif

static bool dpic_ebreak_triggered = false;
static bool dpic_inst_finish_flag = false;
static std::chrono::steady_clock::time_point prog_start = std::chrono::steady_clock::now();
static std::chrono::steady_clock::time_point last_print = prog_start;

CPU::CPU(int argc, char **argv)
{
    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new VysyxSoCFull{contextp};

#ifdef ENABLE_DIFFTEST
    difftest = new DiffTest();
    if (difftest == nullptr)
    {
        std::cerr << "Failed to initialize DiffTest." << std::endl;
        exit(1);
    }
#endif
    fst_init(top);
#ifdef USE_NVBOARD
    void nvboard_bind_all_pins(VysyxSoCFull * top);
    nvboard_bind_all_pins(top);
    nvboard_init();
#endif
#ifdef RECORD_PCTRACE
    if (!pctrace_write_init())
    {
        printf("pctrace_write_init failed\n");
        exit(1);
    }
#endif
#ifdef RECORD_BRTRACE
    if (!branchtrace_write_init())
    {
        printf("branchtrace_write_init failed\n");
        exit(1);
    }
#endif
}

CPU::~CPU()
{
#ifdef USE_NVBOARD
    nvboard_quit();
#endif

    fst_close();
    delete top;
    delete contextp;
}

const char *reg_names[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"};

void CPU::reg_print()
{
    for (int i = 0; i < REG_NUM; i++)
    {
        if (i % 8 == 0 && i != 0)
            printf("\n");
        printf("\tx%-2d(%s): 0x%08x ", i, reg_names[i], dut_CPU_state.gpr[i]);
    }
    printf("\n");
}

void CPU::reset(int n)
{
    top->reset = 1;
    for (int i = 0; i < n; i++)
    {
        top->clock = 0;
        top->eval();
        // #ifdef ENABLE_FST
        //         fst_dump_once();
        // #endif
        top->clock = 1;
        top->eval();
#ifdef USE_NVBOARD
        nvboard_update();
#endif
        cycle_count++;
#ifdef ENABLE_FST
        fst_dump_once();
#endif
    }
    top->reset = 0;
    top->clock = 0;
    top->eval();

#ifdef ENABLE_FTRACE
    if (ftrace_enabled)
    {
        get_init_func_symbols(pc);
    }

#endif
}

bool CPU::execute(uint64_t steps)
{
    for (; steps > 0 && !contextp->gotFinish() && !dpic_ebreak_triggered; steps--)
    {
        if (!execute_once())
        {
            printf("CPU execution failed at PC = 0x%08x\n", dut_CPU_state.nextPc);

            return false;
        }
    }
    return true;
}

bool CPU::execute_once()
{

    top->clock = 0;
    top->eval();
#ifdef USE_NVBOARD
    // nvboard_update();
#endif
#ifdef ENABLE_FST
    fst_dump_once();
#endif
    top->clock = 1;
    top->eval();
#ifdef USE_NVBOARD
    nvboard_update();
#endif
#ifdef ENABLE_FST
    fst_dump_once();
#endif
// ================= 性能监控与超时管理 =================
    if (cycle_count % 500000 == 0) 
    {
        auto now = std::chrono::steady_clock::now();

        // 1. 处理超时停机逻辑
        auto elapsed_mins = std::chrono::duration_cast<std::chrono::minutes>(now - prog_start).count();
        if (elapsed_mins >= MAX_SIM_TIME_MINUTES) 
        {
            printf("\n======================================================\n");
            printf(">>> [TIMEOUT] 仿真已运行 %ld 分钟，达到最大允许时长！\n", elapsed_mins);
            printf(">>> 强制停机！(PC = 0x%08x)\n", dut_CPU_state.nextPc);
            printf("======================================================\n");
            exit(1); 
        }

        // 2. 处理 5 秒打印一次平均频率逻辑
        if (std::chrono::duration_cast<std::chrono::seconds>(now - last_print).count() >= 5)
        {
            double sec = std::chrono::duration<double>(now - prog_start).count();
            printf("\n[FREQ] time=%.2fs  cycles=%llu  inst_cnt=%llu  avg_freq=%.2f Hz\n",
                   sec, (unsigned long long)cycle_count, (unsigned long long)inst_count, cycle_count / sec);
            last_print = now;
        }
    }
    // =========================================================
    cycle_count++;
    contextp->timeInc(1);

    if (dpic_ebreak_triggered)
    {

#ifdef ENABLE_DIFFTEST
        difftest->in_mismatch = false;
#endif
        fst_close();
        if (dut_CPU_state.gpr[10] == 0)
        {
            printf(">>> HIT GOOD TRAP!\n");
        }
        else
        {
            reg_print();
            printf(">>> HIT BAD TRAP! x10 = 0x%08x\n", dut_CPU_state.gpr[10]);
        }
        printf(">>> pc= 0x%08x  总周期=%llu  总指令=%llu    ipc=%.4f\n", dut_CPU_state.nextPc, cycle_count, inst_count, (float)inst_count / cycle_count);
#ifdef RECORD_PCTRACE
        if (pctrace_write_close())
        {
            printf("pctrace_write_close success\n");
        }
        else
        {
            printf("pctrace_write_close failed\n");
        }
#endif
#ifdef RECORD_BRTRACE
        if (branchtrace_write_close())
        {
            printf("branchtrace_write_close success\n");
        }
        else
        {
            printf("branchtrace_write_close failed\n");
        }
#endif
    }
    if (dpic_inst_finish_flag)
    {
        dpic_inst_finish_flag = false;
        inst_count++;
// printf("%llu ", cycle_count); //  打印周期数
#ifdef RECORD_PCTRACE
        pctrace_write_record(pc);
#endif
#ifdef RECORD_BRTRACE
        branchtrace_write_record(pc, inst);
#endif

#ifdef ENABLE_ITRACE
        itrace_write(pc, inst);
        trace_log();

#endif

#ifdef ENABLE_FTRACE

        if (ftrace_enabled)
        {
            int rd = (inst >> 7) & 0x1F;
            int rs1 = (inst >> 15) & 0x1F;
            if (was_jal())
                ftrace_record(pc, true);

            else if (was_jalr())
                ftrace_record(pc, false);

            save_prev_state(pc, inst, rd, rs1);
        }

#endif

#ifdef ENABLE_DIFFTEST
        if (difftest->in_mismatch)
        {
            if (difftest->steps_after_mismatch-- > 0)
            {
                return true;
            }
            fst_close();
            return false;
        }
        if (!difftest->step())
        {
            difftest->in_mismatch = true;
            if (difftest->steps_after_mismatch > 0)
            {
                return true;
            }
            fst_close();
            return false;
        }
#endif
    }

    return true;
}

void dpic_ebreak()
{
    dpic_ebreak_triggered = true;
}
void dpic_inst_finish()
{
    dpic_inst_finish_flag = true;
}
