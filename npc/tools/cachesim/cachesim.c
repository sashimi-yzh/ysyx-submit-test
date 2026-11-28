// icachesim: 模拟 npc 的 icache，统计取指缺失，并归账到 AXI 读通道 / 交付时间
//
// 输入：NEMU -i 生成的 icachesim-itrace.bin（顺序段记录，
//       每段 8 字节小端 {uint32 start_pc, uint32 end_pc}，展开即逐指令 PC）
// 模拟：与 npc/src/icache/icache.scala 一致（直接映射：
//       index = addr[off+idxb-1:off]，tag = addr[31:off+idxb]，valid+tag 比较）
//
// 用法: cachesim [-b block_size] [-n block_num] [-l lat] [-c ratio]
//                [-m mode] [-P policy] [-s] <file>
//   -b/-n  几何（默认 16 / 8，即当前 npc 配置）
//   -l     设备固定延迟（设备拍，默认 9：AR→首 beat）
//   -c     CPU/设备时钟倍率（默认 8，对应 ysyxSoC AXI4Delayer 的 r=8）
//   -m     行交付模型 0=整行到达才放行（当前 npc） 1=critical-word-first
//   -P     预取 0=不预取 1=缺失时顺序预取下一条行
//   -s     扫描内建几何表（同数据位预算下的候选）
//
// 输出两个口径：
//   chan = AXI 读通道被 refill 占用的拍数（硬地板：总周期不可能低于它）
//   cyc  = 单流时序模型（一次一条取指、阻塞式 IFU）估计的总拍数
// 两者都在"无错误路径取指、不含 LSU 访存"的理想化单流下成立，只用于几何比较。

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static int log2_ceil(int v) {
  int n = 0;
  while ((1 << n) < v) n++;
  return n;
}

typedef struct {
  int bs, bn;
} Geom;

typedef struct {
  uint64_t acc, hit, miss, refill, chan, cyc;
  uint64_t pf_issued, pf_useful, partial;
  uint64_t off_hist[8];
} Stat;

// 直接映射 icache + （简化）单通道时序模型
static Stat simulate(const Geom *g, int lat, int ratio, int mode, int pol, const char *file) {
  Stat st;
  memset(&st, 0, sizeof(st));

  const int off = log2_ceil(g->bs);
  const int idxb = log2_ceil(g->bn);
  const int nbeats = g->bs / 4;
  const int refill_cyc = ratio * (lat + nbeats - 1);  // 一次 refill 占用读通道的拍数

  memset(st.off_hist, 0, sizeof(st.off_hist));
  uint8_t *valid = calloc(g->bn, 1);
  uint32_t *tag = calloc(g->bn, sizeof(uint32_t));
  // CWF：正在逐 beat 填充的行（word j 在 fill0 + ratio*(lat+j) 可用）
  uint8_t *filling = calloc(g->bn, 1);
  uint64_t *fill0 = calloc(g->bn, sizeof(uint64_t));

  FILE *fp = fopen(file, "rb");
  if (fp == NULL) {
    fprintf(stderr, "can not open %s\n", file);
    exit(1);
  }

  uint64_t t = 0;          // 模型时间（拍）
  uint64_t chan_free = 0;  // 读通道空闲时刻
  uint8_t pf_valid = 0;    // 在途预取（一条）
  uint64_t pf_ready = 0;
  int pf_idx = 0;
  uint32_t pf_tag = 0;

  uint32_t start, end;
  while (fread(&start, 4, 1, fp) == 1 && fread(&end, 4, 1, fp) == 1) {
    for (uint32_t pc = start; pc <= end; pc += 4) {
      st.acc++;

      // 结算已完成的预取
      if (pf_valid && t >= pf_ready) {
        valid[pf_idx] = 1;
        tag[pf_idx] = pf_tag;
        pf_valid = 0;
      }

      const int idx = (pc >> off) & (g->bn - 1);
      const uint32_t tg = pc >> (off + idxb);
      const int w = (pc >> 2) & (nbeats - 1);
      (void)w;

      if (valid[idx] && tag[idx] == tg) {  // 命中
        st.hit++;
        if (pf_valid && idx == pf_idx && tg == pf_tag) st.pf_useful++;
        t += 1;
        continue;
      }

      if (filling[idx] && tag[idx] == tg) {  // 该行仍在逐 beat 填充（CWF 部分命中）
        uint64_t ready = fill0[idx] + (uint64_t)ratio * (lat + w);
        st.partial++;
        if (t < ready) t = ready;
        if (w == nbeats - 1) filling[idx] = 0;
        t += 1;
        continue;
      }

      // 该行已有在途预取：等它到齐即可，不重复占一次通道（否则模型会双重惩罚预取）
      if (pf_valid && idx == pf_idx && tg == pf_tag) {
        if (t < pf_ready) t = pf_ready;
        valid[idx] = 1;
        tag[idx] = tg;
        pf_valid = 0;
        st.miss++;
        st.pf_useful++;
        t += 1;
        continue;
      }

      // 真缺失：占用读通道一次 refill
      st.miss++;
      st.refill++;
      st.off_hist[w & 7]++;
      uint64_t r_start = (t > chan_free) ? t : chan_free;
      st.chan += refill_cyc;
      chan_free = r_start + refill_cyc + 1;

      valid[idx] = 1;
      tag[idx] = tg;
      if (mode == 0) {
        t = r_start + refill_cyc;  // 等整行最后一个 beat
      } else {
        filling[idx] = 1;          // critical-word-first：只等本 word
        fill0[idx] = r_start;
        uint64_t ready = r_start + (uint64_t)ratio * (lat + w);
        t = (t > ready) ? t : ready;
        if (w == nbeats - 1) filling[idx] = 0;
      }

      // 顺序预取下一行
      if (pol == 1) {
        uint32_t npc = ((pc >> off) + 1) << off;
        const int nidx = (npc >> off) & (g->bn - 1);
        const uint32_t ntg = npc >> (off + idxb);
        if (!(valid[nidx] && tag[nidx] == ntg) && !pf_valid) {
          st.pf_issued++;
          uint64_t p_start = chan_free;
          st.chan += refill_cyc;
          chan_free = p_start + refill_cyc + 1;
          pf_valid = 1;
          pf_idx = nidx;
          pf_tag = ntg;
          pf_ready = p_start + refill_cyc;
        }
      }
    }
  }

  fclose(fp);
  free(valid);
  free(tag);
  free(filling);
  free(fill0);
  st.cyc = t;
  return st;
}

static void report(const Geom *g, const Stat *st, int lat, int ratio, int mode, int pol, int quiet) {
  const int nbeats = g->bs / 4;
  const double ipc_cyc = st->cyc ? (double)st->acc / (double)st->cyc : 0.0;
  const double ipc_chan = st->chan ? (double)st->acc / (double)st->chan : 0.0;
  if (quiet) {
    printf("%3d x %-4d | %10lu | %9lu | %6.3f%% | %8lu | %10lu | %11lu | %.4f | %.4f\n",
           g->bs, g->bn, (unsigned long)st->acc, (unsigned long)st->miss,
           100.0 * (double)st->miss / (double)st->acc, (unsigned long)st->refill,
           (unsigned long)st->chan, (unsigned long)st->cyc, ipc_cyc, ipc_chan);
  } else {
    printf("geom block_size=%d block_num=%d (data=%dB, beats=%d)\n", g->bs, g->bn, g->bs * g->bn, nbeats);
    printf("  lat=%d device cyc, ratio=%d, deliver=%s, prefetch=%s\n", lat, ratio,
           mode == 0 ? "whole-line" : "critical-word-first", pol ? "next-line" : "none");
    printf("  accesses = %lu, misses = %lu (%.4f%%), refills = %lu\n", (unsigned long)st->acc,
           (unsigned long)st->miss, 100.0 * (double)st->miss / (double)st->acc, (unsigned long)st->refill);
    printf("  read-channel cycles = %lu (%.1f%% of modeled total)\n", (unsigned long)st->chan,
           100.0 * (double)st->chan / (double)st->cyc);
    printf("  modeled cycles      = %lu -> IPC ceiling = %.4f (chan) / %.4f (model)\n",
           (unsigned long)st->cyc, ipc_chan, ipc_cyc);
    if (st->pf_issued)
      printf("  prefetch issued = %lu, useful = %lu\n", (unsigned long)st->pf_issued,
             (unsigned long)st->pf_useful);
    if (st->partial) printf("  partial-line hits (CWF) = %lu\n", (unsigned long)st->partial);
    {
      uint64_t tot = 0;
      for (int i = 0; i < nbeats; i++) tot += st->off_hist[i];
      printf("  缺失的 行内字序号 分布（每次 refill 的潜在早放行量 = 8*(beats-1-offset) 拍）:\n");
      for (int i = 0; i < nbeats; i++)
        printf("    offset=%d : %10lu  %5.1f%%\n", i, (unsigned long)st->off_hist[i],
               tot ? 100.0 * st->off_hist[i] / tot : 0.0);
      double save = 0;
      for (int i = 0; i < nbeats; i++) save += (double)(ratio * (nbeats - 1 - i)) * st->off_hist[i];
      printf("    -> 潜在早放行量 平均 %.2f 拍/refill（上界，未计入 refill 单元的串行化）\n",
             tot ? save / tot : 0.0);
    }
  }
}

int main(int argc, char *argv[]) {
  int bs = 16, bn = 8;
  int lat = 9, ratio = 8, mode = 0, pol = 0, sweep = 0;
  const char *file = NULL;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-b") == 0 && i + 1 < argc) bs = atoi(argv[++i]);
    else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) bn = atoi(argv[++i]);
    else if (strcmp(argv[i], "-l") == 0 && i + 1 < argc) lat = atoi(argv[++i]);
    else if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) ratio = atoi(argv[++i]);
    else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) mode = atoi(argv[++i]);
    else if (strcmp(argv[i], "-P") == 0 && i + 1 < argc) pol = atoi(argv[++i]);
    else if (strcmp(argv[i], "-s") == 0) sweep = 1;
    else file = argv[i];
  }
  if (file == NULL) {
    fprintf(stderr, "usage: %s [-b bs] [-n bn] [-l lat] [-c ratio] [-m mode] [-P pol] [-s] <trace>\n",
            argv[0]);
    return 1;
  }

  if (sweep) {
    static const Geom table[] = {
      {16, 4}, {32, 2},                                      // 64B
      {16, 8}, {32, 4}, {64, 2}, {128, 1},                   // 128B（16x8 = 当前配置）
      {16, 16}, {32, 8}, {64, 4}, {128, 2},                  // 256B
      {32, 16}, {64, 8},                                     // 512B
      {64, 16},                                              // 1KB
    };
    printf("model: lat=%d dev-cyc, ratio=%d, deliver=%s, prefetch=%s\n", lat, ratio,
           mode == 0 ? "whole-line" : "critical-word-first", pol ? "next-line" : "none");
    printf("blk x num  |  accesses  |    misses | miss%%  |  refills |  chan_cyc  |   model_cyc | IPC_cyc | IPC_chan\n");
    printf("-----------+------------+-----------+--------+----------+------------+-------------+---------+---------\n");
    for (unsigned i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
      Stat st = simulate(&table[i], lat, ratio, mode, pol, file);
      report(&table[i], &st, lat, ratio, mode, pol, 1);
    }
    return 0;
  }

  Geom g = {bs, bn};
  Stat st = simulate(&g, lat, ratio, mode, pol, file);
  report(&g, &st, lat, ratio, mode, pol, 0);
  return 0;
}
