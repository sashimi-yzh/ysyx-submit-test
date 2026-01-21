#include "../../include/common.h"
#include <getopt.h> //,包含解析命令行参数的库函数

VerilatedFstC *tfp = NULL;
VysyxSoCFull *top = NULL;
FILE *log_fp = NULL;
bool batch_mode = false; // 默认sdb模式

static char *log_file = NULL;        // 日志文件
static char *ref_so_file = NULL;     // difftest的ref的动态库文件
static int ref_so_port = 1234;       // difftest的ref端口
static std::string elf_file = "";    // ftrace的elf文件
static char *ftrace_log_file = NULL; // ftrace的日志文件
static char *img_file = NULL;        // 程序源文件指针
//=====================================================
// 用于解析命令行参数
//=====================================================
static int parse_args(int argc, char *argv[])
{
  const struct option table[] = {
      {"batch", no_argument, NULL, 'b'},
      {"log", required_argument, NULL, 'l'},
      {"diff", required_argument, NULL, 'd'},
      {"port", required_argument, NULL, 'p'},
      {"elf", required_argument, NULL, 'e'},
      {"elf-log", required_argument, NULL, 'g'},
      {"image", required_argument, NULL, 'i'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bhl:d:p:e:g:i:", table, NULL)) != -1)
  {
    switch (o)
    {
    case 'b':
      batch_mode = true;
      break;
    case 'l':
      log_file = optarg;
      break;
    case 'd':
      ref_so_file = optarg;
      break;
    case 'p':
      ref_so_port = atoi(optarg);
      break;
    case 'e':
      elf_file = optarg;
      break;
    case 'g':
      ftrace_log_file = optarg;
      break;
    case 'i':
      img_file = optarg;
      break;
    default:
      printf("Usage: %s [OPTION...] [args]\n\n", argv[0]);
      printf("\t-b,--batch                run with batch mode\n");
      printf("\t-l,--log=FILE             output log to FILE\n");
      printf("\t-d,--diff=REF_SO          run DiffTest with reference REF_SO\n");
      printf("\t-p,--port=PORT            run DiffTest with port PORT\n");
      printf("\t-e,--elf=ELF_FILE         load elf file for ftrace\n");
      printf("\t-g,--elf-log=FTRACER_FILE ftracer output log to FTRACER_FILE\n");
      printf("\t-i,--image=IMG_FILE       load program from IMG_FILE\n");
      printf("\n");
      exit(0);
    }
  }
  return 0;
}
//=====================================================
// 用于初始化verilator仿真
//=====================================================
// 函数声明
	void nvboard_bind_all_pins(VysyxSoCFull* top);
static void init_verilator(int argc, char *argv[])
{
  // 传递参数给verilator,建议在创建任何模型之前使用
  Verilated::commandArgs(argc, argv);
  // 构建一个名为ysyx_25050136_NPC的仿真模型
  top = new VysyxSoCFull;
#ifdef CONFIG_FST
  // 创建一个fst波形文件指针
  tfp = new VerilatedFstC;
  // 启用跟踪
  Verilated::traceEverOn(true);
  // 采样深度为5
  top->trace(tfp, 10);
  // 打开波形文件
  tfp->open("build/log/waveform.fst");
#endif
#ifdef CONFIG_TARGET_NVBOARD
  // NVBOARD初始化引脚
  nvboard_bind_all_pins(top);
  // NVBOARD初始化
  nvboard_init();
#endif
}
//=====================================================
// 用于初始化cpu
//=====================================================
void cpu_init()
{
  npcstate.state = NPC_RUNNING;
  stop_time = sim_time;
  pc__ = 0;
  top->clock = 0;
  top->reset = 1;
}
//=====================================================
// 用于初始化输出日志
//=====================================================
void init_log(const char *log_file)
{
  log_fp = stdout;
  if (log_file != NULL)
  {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "无法打开日志文件 '%s'", log_file);
    log_fp = fp;
  }
  Log("日志被输出到了 %s", log_file ? log_file : "stdout");
}
//=====================================================
// 一些输出日志函数
//=====================================================
void printf_statu()
{
    // ICache统计
    uint64_t icache_total_count = npc_perC.icache_flash_count + npc_perC.icache_sram_count + npc_perC.icache_sdram_count;
    uint64_t icache_total_miss = npc_perC.icache_flash_miss + npc_perC.icache_sram_miss + npc_perC.icache_sdram_miss;
    uint64_t icache_total_misscycle = npc_perC.icache_flash_misscycle + npc_perC.icache_sram_misscycle + npc_perC.icache_sdram_misscycle;
    // 只考虑SDRAM的命中率
    float icache_hit_rate = (npc_perC.icache_sdram_count == 0) ? 0 : ((float)(npc_perC.icache_sdram_count - npc_perC.icache_sdram_miss) * 100 / (float)npc_perC.icache_sdram_count);
    // 只考虑SDRAM的缺失代价
    uint64_t icache_miss_penalty = (npc_perC.icache_sdram_miss == 0) ? 0 : (npc_perC.icache_sdram_misscycle / npc_perC.icache_sdram_miss);
    // 只考虑SDRAM的AMAT
    float icache_amat = (icache_total_count == 0) ? 0 : 1 + (float)npc_perC.icache_sdram_misscycle / (float)icache_total_count;
    
    // ICache各介质平均访问周期
    float icache_flash_avg = (npc_perC.icache_flash_count == 0) ? 0 : (float)npc_perC.icache_flash_misscycle / (float)npc_perC.icache_flash_count;
    float icache_sram_avg = (npc_perC.icache_sram_count == 0) ? 0 : (float)npc_perC.icache_sram_misscycle / (float)npc_perC.icache_sram_count;
    float icache_sdram_avg = (npc_perC.icache_sdram_count == 0) ? 0 : (float)npc_perC.icache_sdram_misscycle / (float)npc_perC.icache_sdram_count;
    
    // DCache统计(无缓存实现,仅统计访问次数和周期)
    uint64_t dcache_total_rcount = npc_perC.dcache_flash_count + npc_perC.dcache_sram_rcount + npc_perC.dcache_sdram_rcount;
    uint64_t dcache_total_wcount = npc_perC.dcache_sram_wcount + npc_perC.dcache_sdram_wcount;
    uint64_t dcache_total_count = dcache_total_rcount + dcache_total_wcount;
    uint64_t dcache_total_misscycle = npc_perC.dcache_flash_misscycle + npc_perC.dcache_sram_wmisscycle + npc_perC.dcache_sram_rmisscycle + npc_perC.dcache_sdram_wmisscycle + npc_perC.dcache_sdram_rmisscycle;
    
    // DCache各介质平均访问周期
    float dcache_flash_avg = (npc_perC.dcache_flash_count == 0) ? 0 : (float)npc_perC.dcache_flash_misscycle / (float)npc_perC.dcache_flash_count;
    float dcache_sram_r_avg = (npc_perC.dcache_sram_rcount == 0) ? 0 : (float)npc_perC.dcache_sram_rmisscycle / (float)npc_perC.dcache_sram_rcount;
    float dcache_sram_w_avg = (npc_perC.dcache_sram_wcount == 0) ? 0 : (float)npc_perC.dcache_sram_wmisscycle / (float)npc_perC.dcache_sram_wcount;
    float dcache_sdram_r_avg = (npc_perC.dcache_sdram_rcount == 0) ? 0 : (float)npc_perC.dcache_sdram_rmisscycle / (float)npc_perC.dcache_sdram_rcount;
    float dcache_sdram_w_avg = (npc_perC.dcache_sdram_wcount == 0) ? 0 : (float)npc_perC.dcache_sdram_wmisscycle / (float)npc_perC.dcache_sdram_wcount;
    
    // 性能统计
    uint64_t total_cycles = (sim_time - 1) / 2;
    uint64_t all_delay = (npc_perC.commit_count == 0) ? 0 : (total_cycles / npc_perC.commit_count);
    float ipc = (total_cycles == 0) ? 0 : (float)npc_perC.commit_count / (float)total_cycles;
    uint64_t total_branches = npc_perC.jump_count + npc_perC.branch_count;
    float guess_rate = (total_branches == 0) ? 0 : (float)(total_branches - npc_perC.predict_miss_count) * 100 / (float)total_branches;

    Log("执行平均延迟: %ld", all_delay);
    Log("IPC (Instructions Per Cycle): %.6f", ipc);
    Log("NPC的性能计数器如下:");
    Log("  提交指令数: %ld, 取指数: %ld", npc_perC.commit_count, npc_perC.fetch_count);
    Log("  Load数: %ld, Store数: %ld", npc_perC.load_count, npc_perC.store_count);
    Log("  Jump数: %ld, Branch数: %ld", npc_perC.jump_count, npc_perC.branch_count);
    Log("  ALU数: %ld, System数: %ld", npc_perC.alu_count, npc_perC.system_count);
    Log("  预测错误数: %ld, 预测非跳转数: %ld, 预测成功率: %.4f", npc_perC.predict_miss_count, npc_perC.predict_not_jump_count, guess_rate);
    Log("  相关性延迟周期: %ld", npc_perC.related_delay_count);
    
    Log("ICache相关:");
    Log("  总访问次数 = %ld (Flash: %ld, SRAM: %ld, SDRAM: %ld)", 
        icache_total_count, npc_perC.icache_flash_count, npc_perC.icache_sram_count, npc_perC.icache_sdram_count);
    Log("  总缺失次数 = %ld (Flash: %ld, SRAM: %ld, SDRAM: %ld)", 
        icache_total_miss, npc_perC.icache_flash_miss, npc_perC.icache_sram_miss, npc_perC.icache_sdram_miss);
    Log("  总缺失周期 = %ld (Flash: %ld, SRAM: %ld, SDRAM: %ld)", 
        icache_total_misscycle, npc_perC.icache_flash_misscycle, npc_perC.icache_sram_misscycle, npc_perC.icache_sdram_misscycle);
    Log("  平均访问周期 (Flash: %.2f, SRAM: %.2f, SDRAM: %.2f)", 
        icache_flash_avg, icache_sram_avg, icache_sdram_avg);
    Log("  命中率 = %.2f%%, SDRAM缺失代价: %ld, SDRAM_AMAT = %.2f", icache_hit_rate, icache_miss_penalty, icache_amat);
    
    Log("DCache相关(无缓存实现):");
    Log("  读访问次数 = %ld (Flash: %ld, SRAM: %ld, SDRAM: %ld)", 
        dcache_total_rcount, npc_perC.dcache_flash_count, npc_perC.dcache_sram_rcount, npc_perC.dcache_sdram_rcount);
    Log("  写访问次数 = %ld (SRAM: %ld, SDRAM: %ld)", 
        dcache_total_wcount, npc_perC.dcache_sram_wcount, npc_perC.dcache_sdram_wcount);
    Log("  总访问次数 = %ld", dcache_total_count);
    Log("  总访问周期 = %ld (Flash: %ld, SRAM_R: %ld, SRAM_W: %ld, SDRAM_R: %ld, SDRAM_W: %ld)", 
        dcache_total_misscycle, npc_perC.dcache_flash_misscycle, npc_perC.dcache_sram_rmisscycle, 
        npc_perC.dcache_sram_wmisscycle, npc_perC.dcache_sdram_rmisscycle, npc_perC.dcache_sdram_wmisscycle);
    Log("  平均访问周期 (Flash: %.2f, SRAM_R: %.2f, SRAM_W: %.2f, SDRAM_R: %.2f, SDRAM_W: %.2f)", 
        dcache_flash_avg, dcache_sram_r_avg, dcache_sram_w_avg, dcache_sdram_r_avg, dcache_sdram_w_avg);
    
    Log("PC = 0x%08x, halt = %d, NPC 的结束状态是%s", npcstate.halt_pc, npcstate.halt_ret,
        (npcstate.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) : 
        (npcstate.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : 
        ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))));
    Log("仿真时间为 %lu 次, 仿真周期为 %lu 个", sim_time - 1, (sim_time - 1) / 2);
    Log("指令数量为 %lu 条", inst_count);
    Log("程序时间 = %ld us", g_timer);
}

void npc_end()
{
  
  IFDEF(CONFIG_TARGET_NVBOARD, nvboard_quit(););
  IFDEF(CONFIG_ITRACE, print_iringbuf());
  // 输出完成状态
  printf_statu();
  // 关闭波形文件
  IFDEF(CONFIG_FST, tfp->close());
  // 删除指针
  delete top;
}

static void welcome()
{
  Log("ITrace: %s", MUXDEF(CONFIG_ITRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("MTrace: %s", MUXDEF(CONFIG_MTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("FTrace: %s", MUXDEF(CONFIG_FTRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Difftest: %s", MUXDEF(CONFIG_DIFFTEST, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Watchpoint: %s", MUXDEF(CONFIG_WATCHPOINT, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Wavefst: %s", MUXDEF(CONFIG_FST, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FMT("RISCV32e", ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}
//=====================================================
// 调试相关函数
//=====================================================
void init_main(int argc, char **argv)
{
  // 初始化时钟模型
  init_rand();
  // 解析命令行参数
  parse_args(argc, argv);
  // 输出日志初始化
  init_log(log_file);
  // ITRACE
  IFDEF(CONFIG_ITRACE, init_disasm());
  // Verilator 仿真初始化
  init_verilator(argc, argv);
  // 加载内存
  long size = init_imem(img_file);
  // CPU初始化
  cpu_init();
  // Difftest
  IFDEF(CONFIG_DIFFTEST, init_difftest(ref_so_file, size, ref_so_port));
  // FTRACE
  IFDEF(CONFIG_FTRACE, load_elf(elf_file));
  IFDEF(CONFIG_FTRACE, init_ftracer_log(ftrace_log_file));
  // sdb初始化
  init_sdb();
  //
  welcome();
}
