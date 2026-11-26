/***************************************************************************************
 * cachesim - 指令 cache 元数据模拟器
 *
 * 读取 NEMU 通过 -c/--cachesim-trace 导出的 PC 序列(每指令一个 uint32_t),
 * 按给定的 (sets, ways, block) 回放, 统计命中/缺失次数与总缺失时间 TMT.
 *
 * 只模拟元数据(valid/tag/LRU), 不保存指令内容 —— 缺失次数与访存内容无关,
 * 因此它的运行速度比 Verilator 仿真快几个数量级, 可用于快速的设计空间探索,
 * 也可作为 NPC 性能计数器的参考(性能 DiffTest).
 ***************************************************************************************/

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {

// 与 npc/vsrc/top.v 的 ifu_cacheable 保持一致:
// 只有落在这两个区间内的取指才经过 ICache, 其余直接 bypass 到总线上.
constexpr uint32_t CACHEABLE_LO_A = 0x30000000u, CACHEABLE_HI_A = 0x31000000u;  // FLASH (XIP)
constexpr uint32_t CACHEABLE_LO_B = 0xa0000000u, CACHEABLE_HI_B = 0xa2000000u;  // SDRAM

inline bool ifu_cacheable(uint32_t pc) {
  return (pc >= CACHEABLE_LO_A && pc < CACHEABLE_HI_A) ||
         (pc >= CACHEABLE_LO_B && pc < CACHEABLE_HI_B);
}

inline bool is_pow2(uint64_t v) { return v != 0 && (v & (v - 1)) == 0; }

inline uint32_t log2u(uint64_t v) {
  uint32_t n = 0;
  while ((uint64_t(1) << n) < v) { n++; }
  return n;
}

struct Config {
  const char *trace = nullptr;
  uint32_t sets = 16;
  uint32_t ways = 1;
  uint32_t block = 4;
  uint32_t miss_penalty = 30;  // 一次缺失折算的周期数, 用于估算 TMT
  bool     miss_penalty_set = false;  // 命令行是否显式给了 --miss-penalty
  uint32_t bus_bytes  = 4;    // 总线数据位宽（字节）
  bool     burst      = false;
  uint32_t fixed_cost = 28;   // 突发的一次性开销（CPU 周期）
  uint32_t beat_cost  = 5;    // 每个 beat 的边际成本（CPU 周期，≈ r）

  bool csv = false;         // 只输出一行 CSV, 供参数扫描脚本汇总
};

class CacheSim {
 public:
  explicit CacheSim(const Config &cfg)
      : cfg_(cfg),
        offset_bits_(log2u(cfg.block)),
        index_bits_(log2u(cfg.sets)),
        tag_(size_t(cfg.sets) * cfg.ways, 0),
        lru_(size_t(cfg.sets) * cfg.ways, 0),
        valid_(size_t(cfg.sets) * cfg.ways, 0) {}

  void access(uint32_t pc) {
    if (!ifu_cacheable(pc)) { bypass_++; return; }
    access_++;

    const uint32_t index = (pc >> offset_bits_) & (cfg_.sets - 1);
    const uint32_t tag   = pc >> (offset_bits_ + index_bits_);
    const size_t base    = size_t(index) * cfg_.ways;

    // 组内查找命中的路, 并刷新它的 LRU 时间戳
    for (uint32_t w = 0; w < cfg_.ways; w++) {
      if (valid_[base + w] && tag_[base + w] == tag) {
        hit_++;
        lru_[base + w] = ++clock_;
        return;
      }
    }

    // 缺失: 优先填充组内无效路(compulsory), 否则替换最久未用的路(replace)
    miss_++;
    uint32_t victim = cfg_.ways;
    for (uint32_t w = 0; w < cfg_.ways; w++) {
      if (!valid_[base + w]) { victim = w; compulsory_++; break; }
    }
    if (victim == cfg_.ways) {
      victim = 0;
      for (uint32_t w = 1; w < cfg_.ways; w++) {
        if (lru_[base + w] < lru_[base + victim]) { victim = w; }
      }
      replace_++;
    }
    valid_[base + victim] = 1;
    tag_[base + victim] = tag;
    lru_[base + victim] = ++clock_;
  }

  // 一次缺失的代价：显式给出的 --miss-penalty 优先，否则按实测标定的模型计算
  uint64_t penalty() const {
    if (cfg_.miss_penalty_set) return cfg_.miss_penalty;
    const uint64_t n = cfg_.block / cfg_.bus_bytes;
    return cfg_.burst ? (cfg_.fixed_cost + n * cfg_.beat_cost)
                      : (n * (cfg_.fixed_cost + cfg_.beat_cost));
  }

  void report(double elapsed_ms) const {
    const uint64_t fetched = access_ + bypass_;
    const uint64_t pen     = penalty();
    const uint64_t tmt     = miss_ * pen;

    printf("config: sets=%u ways=%u block=%uB bus=%uB %s miss_penalty=%llu%s\n",
           cfg_.sets, cfg_.ways, cfg_.block, cfg_.bus_bytes,
           cfg_.burst ? "burst" : "independent", u64(pen),
           cfg_.miss_penalty_set ? " (explicit)" : " (model)");
    printf("\n[ICache behavior]\n");
    printf("  access / hit / miss: %llu / %llu / %llu\n",
           u64(access_), u64(hit_), u64(miss_));
    printf("  hit rate / miss rate: %.2f%% / %.2f%%\n", pct(hit_, access_), pct(miss_, access_));
    printf("  compulsory / replace: %llu / %llu (%s)\n",
           u64(compulsory_), u64(replace_), compulsory_ + replace_ == miss_ ? "OK" : "MISMATCH");

    printf("\n[Fetch traffic]\n");
    printf("  cacheable (access)  : %llu\n", u64(access_));
    printf("  bypass (uncached)   : %llu\n", u64(bypass_));
    printf("  total fetched       : %llu\n", u64(fetched));

    printf("\n[Miss cost]\n");
    if (!cfg_.miss_penalty_set) {
      printf("  model              : %s, n=%llu beats, fixed=%u, per-beat=%u (CPU cycles)\n",
             cfg_.burst ? "burst" : "independent", u64(cfg_.block / cfg_.bus_bytes),
             cfg_.fixed_cost, cfg_.beat_cost);
    }
    printf("  miss penalty        : %llu cycles\n", u64(pen));
    printf("  TMT                 : %llu cycles\n", u64(tmt));
    printf("  misses per 1k inst  : %.2f\n", fetched ? double(miss_) * 1000.0 / double(fetched) : 0.0);

    printf("\n[Simulation]\n");
    printf("  trace PCs           : %llu\n", u64(fetched));
    printf("  wall time           : %.1f ms\n", elapsed_ms);
  }

  // 单行 CSV: block,ways,sets,burst,hit_rate,miss,tmt
  void report_csv() const {
    printf("%u,%u,%u,%u,%.2f,%llu,%llu\n", cfg_.block, cfg_.ways, cfg_.sets,
           cfg_.burst ? 1u : 0u, pct(hit_, access_), u64(miss_), u64(miss_ * penalty()));
  }

 private:
  static unsigned long long u64(uint64_t v) { return (unsigned long long)v; }
  static double pct(double num, double den) { return den > 0 ? num / den * 100.0 : 0.0; }

  Config cfg_;
  uint32_t offset_bits_;
  uint32_t index_bits_;
  std::vector<uint32_t> tag_;
  std::vector<uint64_t> lru_;
  std::vector<uint8_t> valid_;
  uint64_t clock_ = 0;  // 单调递增的 LRU 时间戳

  uint64_t access_ = 0, hit_ = 0, miss_ = 0;
  uint64_t compulsory_ = 0, replace_ = 0, bypass_ = 0;
};

void usage(const char *argv0) {
  printf("Usage: %s --trace FILE [options]\n\n", argv0);
  printf("  --trace FILE       NEMU -c 导出的二进制 PC 序列 (必填)\n");
  printf("  --sets N           组数, 2 的幂 (默认 16)\n");
  printf("  --ways N           相联度, 2 的幂 (默认 1)\n");
  printf("  --block BYTES      块大小, 2 的幂且 >= 4 (默认 4)\n");
  printf("  --csv              只输出一行 CSV: block,ways,sets,burst,hit_rate,miss,tmt\n");
  printf("\n缺失代价模型 (CPU 周期, 由 ysyxSoC 实测标定):\n");
  printf("  --miss-penalty N   直接指定每次缺失的周期数 (指定后忽略下面的模型)\n");
  printf("  --bus-bytes N      总线数据位宽 (默认 4)\n");
  printf("  --burst 0|1        1 = 一次 AR 拉起整块 (默认 0 = 逐字独立事务)\n");
  printf("  --fixed N          突发的一次性开销 (默认 28)\n");
  printf("  --beat N           每多一个 beat 的边际成本 (默认 5)\n");
  printf("                     突发: fixed + n*beat;  独立: n*(fixed+beat),  n=block/bus\n");
  printf("                     默认值由 F=51 (r=5.1) 下 4B/8B/16B 三组实测标定\n");
  printf("\nExample: %s --trace ../build/microbench-train.pc --sets 16 --ways 1 --block 4\n",
         argv0);
}

// 每次读入 2MB, 使内存占用与 trace 文件大小无关
constexpr size_t READ_CHUNK = 2u << 20;

bool replay(const Config &cfg) {
  FILE *fp = fopen(cfg.trace, "rb");
  if (fp == nullptr) {
    fprintf(stderr, "Error: cannot open trace '%s'\n", cfg.trace);
    return false;
  }

  const auto t0 = std::chrono::steady_clock::now();

  CacheSim sim(cfg);
  std::vector<uint32_t> buf(READ_CHUNK / sizeof(uint32_t));
  size_t n;
  while ((n = fread(buf.data(), sizeof(uint32_t), buf.size(), fp)) > 0) {
    for (size_t i = 0; i < n; i++) { sim.access(buf[i]); }
  }
  const bool read_error = ferror(fp) != 0;
  fclose(fp);

  const auto t1 = std::chrono::steady_clock::now();
  const double elapsed_ms = std::chrono::duration<double, std::milli>(t1 - t0).count();

  if (read_error) {
    fprintf(stderr, "Error: read '%s' failed\n", cfg.trace);
    return false;
  }

  if (cfg.csv) { sim.report_csv(); } else { sim.report(elapsed_ms); }
  return true;
}
}  // namespace

int main(int argc, char **argv) {
  Config cfg;

  for (int i = 1; i < argc; i++) {
    const char *a = argv[i];
    auto value = [&](const char *name) -> const char * {
      if (i + 1 >= argc) {
        fprintf(stderr, "Error: %s requires a value\n", name);
        exit(1);
      }
      return argv[++i];
    };

    if (strcmp(a, "-h") == 0 || strcmp(a, "--help") == 0) { usage(argv[0]); return 0; }
    else if (strcmp(a, "--csv") == 0)          { cfg.csv = true; }
    else if (strcmp(a, "--trace") == 0)        { cfg.trace = value(a); }
    else if (strcmp(a, "--sets") == 0)         { cfg.sets = (uint32_t)strtoul(value(a), nullptr, 0); }
    else if (strcmp(a, "--ways") == 0)         { cfg.ways = (uint32_t)strtoul(value(a), nullptr, 0); }
    else if (strcmp(a, "--block") == 0)        { cfg.block = (uint32_t)strtoul(value(a), nullptr, 0); }
    else if (strcmp(a, "--miss-penalty") == 0) { cfg.miss_penalty = (uint32_t)strtoul(value(a), nullptr, 0);
                                                  cfg.miss_penalty_set = true; }
    else if (strcmp(a, "--bus-bytes") == 0)    { cfg.bus_bytes = (uint32_t)strtoul(value(a), nullptr, 0); }
    else if (strcmp(a, "--burst") == 0)        { cfg.burst = (strtoul(value(a), nullptr, 0) != 0); }
    else if (strcmp(a, "--fixed") == 0)        { cfg.fixed_cost = (uint32_t)strtoul(value(a), nullptr, 0); }
    else if (strcmp(a, "--beat") == 0)         { cfg.beat_cost = (uint32_t)strtoul(value(a), nullptr, 0); }
    else {
      fprintf(stderr, "Error: unknown argument '%s'\n", a);
      usage(argv[0]);
      return 1;
    }
  }

  if (cfg.trace == nullptr) { usage(argv[0]); return 1; }
  if (!is_pow2(cfg.sets) || !is_pow2(cfg.ways) || !is_pow2(cfg.block) || cfg.block < 4) {
    fprintf(stderr, "Error: sets/ways must be powers of two, block must be a power of two >= 4\n");
    return 1;
  }
  if (!is_pow2(cfg.bus_bytes) || cfg.bus_bytes < 4) {
    fprintf(stderr, "Error: --bus-bytes must be a power of two >= 4\n");
    return 1;
  }
  if (cfg.block < cfg.bus_bytes) {
    fprintf(stderr, "Error: block (%u) must be >= bus width (%u)\n", cfg.block, cfg.bus_bytes);
    return 1;
  }

  return replay(cfg) ? 0 : 1;
}
