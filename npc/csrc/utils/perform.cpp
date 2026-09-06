#include "common.h"

extern Npc *npc;
extern Cpu *cpu;
extern char *perf_output_file;

#include <fstream>
#include <ctime>

// 简单获取日期和时间字符串
static std::string now_date() {
    time_t t = time(nullptr);
    tm *lt = localtime(&t);
    char buf[16];
    strftime(buf, sizeof(buf), "%Y-%m-%d", lt);
    return buf;
}

static std::string now_time() {
    time_t t = time(nullptr);
    tm *lt = localtime(&t);
    char buf[16];
    strftime(buf, sizeof(buf), "%H:%M:%S", lt);
    return buf;
}

void dump_performance() {
     // 覆盖写入，文件中只保留最近一次的性能数据，使用 key=value 形式便于脚本解析
     std::ofstream ofs(perf_output_file, std::ios::out | std::ios::trunc);

  uint64_t total_inst   = npc->npc_commit_time;
  uint64_t total_cycle  = npc->cycs;
  double ipc            = (total_cycle == 0) ? 0.0
                                             : (double)total_inst / (double)total_cycle;

  // IFU 相关
  uint64_t ifu_total    = npc->ifu_work_cycle + npc->ifu_non_work_cycle;
  double ifu_occ        = (ifu_total == 0) ? 0.0
                                           : (double)npc->ifu_work_cycle / (double)ifu_total;
  double ifu_giveup_rate= (total_inst == 0) ? 0.0
                                            : (double)npc->ifu_giveup_bus_counter / (double)total_inst;

  // I-Cache
  uint64_t ic_hit       = total_inst - npc->icache_miss_time;
  double ic_hit_rate    = (total_inst == 0) ? 0.0
                                            : (double)ic_hit / (double)total_inst;
  double ic_amat        = 1.0 + (1.0 - ic_hit_rate) * (double)npc->ifu_mem_access_timer;

  // IDU / EXU 占用
  uint64_t idu_total    = npc->idu_work_cycle + npc->idu_non_work_cycle;
  double idu_occ        = (idu_total == 0) ? 0.0
                                           : (double)npc->idu_work_cycle / (double)idu_total;

  uint64_t exu_total    = npc->exu_work_cycle + npc->exu_non_work_cycle;
  double exu_occ        = (exu_total == 0) ? 0.0
                                           : (double)npc->exu_work_cycle / (double)exu_total;

  // LSU
  double lsu_occ        = (total_cycle == 0) ? 0.0
                                             : (double)npc->npc_io_timer / (double)(total_cycle * 2);

  ofs << "date="              << now_date() << '\n'
      << "time="              << now_time() << '\n'
      << "end_pc=0x"          << std::hex << cpu->con.pc << std::dec << '\n'
      << "total_cycle="       << total_cycle               << '\n'
      << "total_inst="        << total_inst                << '\n'
      << "ipc="               << ipc                       << '\n'
      << "ifu_occupy="        << ifu_occ                   << '\n'
      << "ifu_giveup_cnt="    << npc->ifu_giveup_bus_counter << '\n'
      << "ifu_giveup_rate="   << ifu_giveup_rate           << '\n'
      << "icache_hit_rate="   << ic_hit_rate               << '\n'
      << "icache_amat="       << ic_amat                   << '\n'
      << "idu_occupy="        << idu_occ                   << '\n'
      << "exu_occupy="        << exu_occ                   << '\n'
      << "lsu_occupy="        << lsu_occ                   << '\n'
      << "predict_miss="      << npc->predict_miss_time    << '\n';
}

void deal_statistic() {
    printf("ended at pc = 0x%08x\n", cpu->commit.pc);
    printf("the last inst is 0x%08x\n", cpu->inst);
  printf(COLOR_BLUE "statistic:\n");

  uint64_t total_inst  = npc->npc_commit_time;
  uint64_t total_cycle = npc->cycs;
  double ipc           = (total_cycle == 0) ? 0.0
                                            : (double)total_inst / (double)total_cycle;

  // IFU
  uint64_t ifu_total   = npc->ifu_work_cycle + npc->ifu_non_work_cycle;
  double ifu_occ       = (ifu_total == 0) ? 0.0
                                          : (double)npc->ifu_work_cycle / (double)ifu_total;
  printf("  total cycle: %lu\n", total_cycle);
  printf("  total inst  : %lu\n",   total_inst);
  printf("  ipc: %f\n", ipc);
  printf("  ifu work_cycle: %llu, non_work_cycle: %llu, occupy: %f\n",
         npc->ifu_work_cycle, npc->ifu_non_work_cycle, ifu_occ);
  printf("  ifu give-up cnt: %u\n", npc->ifu_giveup_bus_counter);

  // I-Cache
  uint64_t ic_hit      = total_inst - npc->icache_miss_time;
  double ic_hit_rate   = (total_inst == 0) ? 0.0
                                           : (double)ic_hit / (double)total_inst;
  double ic_amat       = 1.0 + (1.0 - ic_hit_rate) * (double)npc->ifu_mem_access_timer;
  printf("  icache hit: %lu, miss: %u, hit-rate: %f, AMAT: %f\n",
         ic_hit, npc->icache_miss_time, ic_hit_rate, ic_amat);

  // IDU / EXU
  uint64_t idu_total   = npc->idu_work_cycle + npc->idu_non_work_cycle;
  double idu_occ       = (idu_total == 0) ? 0.0
                                          : (double)npc->idu_work_cycle / (double)idu_total;
  uint64_t exu_total   = npc->exu_work_cycle + npc->exu_non_work_cycle;
  double exu_occ       = (exu_total == 0) ? 0.0
                                          : (double)npc->exu_work_cycle / (double)exu_total;
  printf("  idu occupy: %f, exu occupy: %f\n", idu_occ, exu_occ);

  // LSU
  double lsu_occ       = (total_cycle == 0) ? 0.0
                                            : (double)npc->npc_io_timer / (double)(total_cycle * 2);
  printf("  lsu occupy: %f (io_timer: %llu)\n", lsu_occ, npc->npc_io_timer);

  // Branch predictor
  printf("  predict miss: %u\n", npc->predict_miss_time);

  printf(COLOR_RESET);

  if (need_dump_perform()) {
        dump_performance();
    }
}
