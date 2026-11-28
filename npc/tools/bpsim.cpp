// bpsim.cpp —— 分支预测器设计空间模拟（离线，只读）
//
//   bpsim <反汇编.txt> <icachesim-itrace.bin> [--top N]
//
// 输入：
//   * 反汇编（objdump -d）：用指令编码解出每个 PC 是不是控制转移（branch/jal/jalr），
//     顺带解出 rd/rs1 以便模拟 RAS
//   * NEMU -i 生成的段记录 {start_pc, end_pc}（顺序段，展开即逐指令 PC 流）
//
// 模拟：与 npc/src/BPU/BPU.scala 逐条对齐
//   预测 = 项有效 && tag 命中 ? (jal || counter>=2) : 不跳
//   训练 = taken: 写 {tag,target,valid,jal}，命中且目标相同则 counter++，否则 counter:=2
//          不 taken 且命中：counter--
// 一次遍历同时跑完所有配置，最后打一张对比表。
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// ---------------------------------------------------------------- 反汇编
static const int KH = 1 << 13;           // 控制转移 PC 的哈希表（4096 条足够）
static uint32_t kpc[KH];
static uint8_t  kv[KH];                  // bit0-1: 1=branch 2=jal 3=jalr; bit2: call; bit3: ret

static inline uint32_t khash(uint32_t x) { return (x * 2654435761u) >> 19; }

static bool load_kind(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) { perror(path); return false; }
    char line[512];
    int nstatic = 0;
    while (fgets(line, sizeof line, f)) {
        unsigned addr, inst;
        if (sscanf(line, "%x: %x", &addr, &inst) != 2) continue;
        unsigned op = inst & 0x7f;
        uint8_t v = 0;
        if (op == 0x63) v = 1;                                          // 条件分支
        else if (op == 0x6f) {                                          // jal
            unsigned rd = (inst >> 7) & 0x1f;
            v = 2 | (rd == 1 ? 4 : 0);
        } else if (op == 0x67) {                                        // jalr
            unsigned rd = (inst >> 7) & 0x1f, rs1 = (inst >> 15) & 0x1f;
            v = 3 | (rd == 1 ? 4 : 0) | (rs1 == 1 && rd == 0 ? 8 : 0);
        }
        if (!v) continue;
        uint32_t h = khash(addr) & (KH - 1);
        while (kv[h] && kpc[h] != addr) h = (h + 1) & (KH - 1);
        kpc[h] = addr; kv[h] = v; nstatic++;
    }
    fclose(f);
    printf("反汇编：控制转移 %d 条\n", nstatic);
    return true;
}

static inline uint8_t kind_of(uint32_t pc) {
    uint32_t h = khash(pc) & (KH - 1);
    while (kv[h]) { if (kpc[h] == pc) return kv[h]; h = (h + 1) & (KH - 1); }
    return 0;
}

// ---------------------------------------------------------------- 预测器
struct Cfg {
    const char *name;
    int entries;      // 总项数（<0 表示"无限项/完美 BTB"）
    int ways;         // 相联度；等于 entries 即全相联
    bool xhash;       // 索引用 XOR 折叠
    int ras;          // RAS 深度（0 = 不用）
    int tagbits = 0;  // tag 位宽（0 = 全宽 30 位，即 word 地址全宽）
    int fold = 0;     // 1 = 先把高位移入低位（XOR 折叠）再截取，避免只看低位
};

struct BTB {
    int n, ways, sets, ib;
    bool xhash, infinite;
    int tb; uint32_t tagmask; int fold;
    std::vector<uint32_t> tag, tgt, age;
    std::vector<uint8_t> cnt, jal, val;
    uint32_t clk = 0;
    // RAS
    int rasn;
    std::vector<uint32_t> ras;
    int rastop = 0;
    // 统计
    uint64_t ctrl = 0, taken = 0, miss = 0, hit = 0;
    uint64_t dirNT = 0, dirT = 0, tgtbad = 0;     // 预测不跳实际跳 / 预测跳实际不跳 / 目标错
    uint64_t mb = 0, mj = 0, mi = 0;
    std::unordered_map<uint32_t, uint64_t> perpc; // 每个分支的误预测数（可选）

    void init(const Cfg &c, bool keep_pc) {
        infinite = c.entries < 0;
        n = infinite ? 0 : c.entries;
        ways = infinite ? 0 : (c.ways > 0 ? c.ways : 1);
        if (!infinite) {
            sets = n / ways;
            ib = 0; while ((1 << ib) < sets) ib++;
        }
        xhash = c.xhash; rasn = c.ras;
        tb = (c.tagbits > 0 && c.tagbits <= 30) ? c.tagbits : 30;
        fold = c.fold;
        tagmask = (tb >= 30) ? 0x3fffffffu : ((1u << tb) - 1);
        if (!infinite) {
            tag.assign(n, 0); tgt.assign(n, 0); age.assign(n, 0);
            cnt.assign(n, 0); jal.assign(n, 0); val.assign(n, 0);
        }
        ras.assign(rasn > 0 ? rasn : 1, 0);
        if (keep_pc) perpc.reserve(1024);
    }
    static inline uint32_t mix(uint32_t x) { return x ^ (x >> 8) ^ (x >> 16); }

    void step(uint32_t pcw, uint32_t nextw, uint8_t k, bool keep_pc) {
        ctrl++;
        bool taken = (nextw != pcw + 1);            // 传进来的是 word 地址，+1 即 +4 字节
        bool isBranch = (k & 3) == 1, isJal = (k & 3) == 2, isJalr = (k & 3) == 3;

        // ---- 预测 ----
        bool ptaken = false;
        uint32_t ptgt = 0;
        int hitway = -1;
        if (rasn > 0 && isJalr && (k & 8) && rastop > 0) {   // ret 用 RAS
            ptaken = true; ptgt = ras[rastop - 1];
        } else if (!infinite) {
            uint32_t idx = sets > 1 ? ((xhash ? mix(pcw) : pcw) & (sets - 1)) : 0;
            uint32_t base_tg = (fold || (xhash && sets > 1)) ? mix(pcw) : pcw;
            uint32_t tg = (base_tg >> ib) & tagmask;
            int base = idx * ways;
            for (int w = 0; w < ways; w++) {
                int e = base + w;
                if (val[e] && tag[e] == tg) { hitway = e; break; }
            }
            if (hitway >= 0) {
                ptaken = jal[hitway] || cnt[hitway] >= 2;
                ptgt = tgt[hitway];
            }
        } else {
            // 无限项：查哈希表
            auto it = infmap.find(pcw);
            if (it != infmap.end()) {
                hitway = 0;
                ptaken = it->second.jal || it->second.cnt >= 2;
                ptgt = it->second.tgt;
            }
        }
        if (hitway >= 0) hit++;

        // ---- 比对 ----
        bool wrong = false;
        if (ptaken != taken) {
            wrong = true;
            if (ptaken) dirT++; else dirNT++;
        } else if (taken && ptgt != nextw) { wrong = true; tgtbad++; }
        if (wrong) {
            miss++;
            if (isBranch) mb++; else if (isJal) mj++; else mi++;
            if (keep_pc) perpc[pcw << 2]++;
        }

        // ---- 训练 ----
        if (!infinite) {
            uint32_t idx = sets > 1 ? ((xhash ? mix(pcw) : pcw) & (sets - 1)) : 0;
            uint32_t base_tg2 = (fold || (xhash && sets > 1)) ? mix(pcw) : pcw;
            uint32_t tg = (base_tg2 >> ib) & tagmask;
            int e = hitway;
            if (taken) {
                if (e < 0) {   // 选 victim：无效项优先，否则 LRU
                    int base = idx * ways;
                    e = base;
                    for (int w = 0; w < ways; w++) if (!val[base + w]) { e = base + w; break; }
                    if (val[e]) { for (int w = 0; w < ways; w++) if (age[base + w] < age[e]) e = base + w; }
                    tag[e] = tg; val[e] = 1; cnt[e] = 2;
                } else {
                    if (tgt[e] == nextw) { if (cnt[e] < 3) cnt[e]++; }
                    else cnt[e] = 2;
                    tag[e] = tg;
                }
                tgt[e] = nextw;
                jal[e] = (isJal || isJalr);
                age[e] = ++clk;
            } else if (e >= 0) {
                if (cnt[e] > 0) cnt[e]--;
                age[e] = ++clk;
            }
        } else {
            auto &s = infmap[pcw];
            if (taken) {
                if (s.tgt == nextw) { if (s.cnt < 3) s.cnt++; } else s.cnt = 2;
                s.tgt = nextw; s.jal = (isJal || isJalr); s.valid = 1;
            } else if (s.valid) { if (s.cnt > 0) s.cnt--; }
        }

        // ---- RAS ----
        if (rasn > 0) {
            if (isJal && (k & 4)) {                 // 调用：压入返回地址
                if (rastop < rasn) ras[rastop++] = pcw + 1;
                else { for (int i = 1; i < rasn; i++) ras[i - 1] = ras[i]; ras[rasn - 1] = pcw + 1; }
            } else if (isJalr && (k & 8)) {          // ret：弹出
                if (rastop > 0) rastop--;
            }
        }
        if (taken) this->taken++;
    }

    struct InfE { uint32_t tgt = 0; uint8_t cnt = 0, jal = 0, valid = 0; };
    std::unordered_map<uint32_t, InfE> infmap;
};

// ---------------------------------------------------------------- 主流程
int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "用法: bpsim <反汇编.txt> <icachesim-itrace.bin> [--top N]\n");
        return 1;
    }
    int topn = 0;
    const char *topname = "";
    for (int i = 3; i < argc; i++) {
        if (!strcmp(argv[i], "--top") && i + 1 < argc) topn = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--topcfg") && i + 1 < argc) topname = argv[++i];
    }

    if (!load_kind(argv[1])) return 1;

    FILE *f = fopen(argv[2], "rb");
    if (!f) { perror(argv[2]); return 1; }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    size_t rec = sz / 8;
    std::vector<uint32_t> seg(rec * 2);
    if (fread(seg.data(), 8, rec, f) != rec) { fprintf(stderr, "读 trace 失败\n"); return 1; }
    fclose(f);
    printf("段记录：%zu 条（%.1f MB）\n", rec, sz / 1e6);

    struct Desc { const char *name; Cfg c; };
    std::vector<Cfg> cfgs = {
        {"dm1   1 项(修索引前)", 1, 1, false, 0},
        {"fa2   2 路全相联", 2, 2, false, 0},
        {"fa3   3 路全相联", 3, 3, false, 0},
        {"dm8x  8 项 + XOR 索引", 8, 1, true, 0},
        {"dm4   4 项直接映射(现在)", 4, 1, false, 0},
        {"dm4x  4 项 + XOR 索引", 4, 1, true, 0},
        {"dm8   8 项直接映射", 8, 1, false, 0},
        {"dm16  16 项直接映射", 16, 1, false, 0},
        {"dm32  32 项直接映射", 32, 1, false, 0},
        {"sa4   2 组 x 2 路", 4, 2, false, 0},
        {"fa4   4 路全相联", 4, 4, false, 0},
        {"sa8   4 组 x 2 路", 8, 2, false, 0},
        {"fa8   8 路全相联", 8, 8, false, 0},
        {"fa4+r 4 路全相联 + RAS4", 4, 4, false, 4},
        {"fa4+r8 4 路全相联 + RAS8", 4, 4, false, 8},
        {"dm16+r 16 项 + RAS4", 16, 1, false, 4},
        {"fa4 t16", 4, 4, false, 0, 16},
        {"fa4 t14", 4, 4, false, 0, 14},
        {"fa4 t12", 4, 4, false, 0, 12},
        {"fa4 t10", 4, 4, false, 0, 10},
        {"fa4 t9 ", 4, 4, false, 0, 9},
        {"fa4 t8 ", 4, 4, false, 0, 8},
        {"fa4 t7 ", 4, 4, false, 0, 7},
        {"fa4 t6 ", 4, 4, false, 0, 6},
        {"fa4 t5 ", 4, 4, false, 0, 5},
        {"fa4 t4 ", 4, 4, false, 0, 4},
        {"fa4 t3 ", 4, 4, false, 0, 3},
        {"fa4 t2 ", 4, 4, false, 0, 2},
        {"fa4 t8f", 4, 4, false, 0, 8, 1},
        {"fa4 t7f", 4, 4, false, 0, 7, 1},
        {"fa4 t6f", 4, 4, false, 0, 6, 1},
        {"fa4 t5f", 4, 4, false, 0, 5, 1},
        {"fa4 t4f", 4, 4, false, 0, 4, 1},
        {"fa4 t3f", 4, 4, false, 0, 3, 1},
        {"fa8 t6f", 8, 8, false, 0, 6, 1},
        {"fa8 t6 ", 8, 8, false, 0, 6},
        {"fa8 t12", 8, 8, false, 0, 12},
        {"INF   无限项(完美BTB)", -1, 0, false, 0},
        {"INF+r  无限项 + RAS4", -1, 0, false, 4},
    };
    int topcfg = -1;
    for (size_t i = 0; i < cfgs.size(); i++)
        if (topn > 0 && !strncmp(cfgs[i].name, topname, strlen(topname))) { topcfg = (int)i; break; }
    std::vector<BTB> sim(cfgs.size());
    for (size_t i = 0; i < cfgs.size(); i++) sim[i].init(cfgs[i], (int)i == topcfg);

    uint64_t n_instr = 0, n_ctrl = 0, bad_seg = 0;
    uint32_t prev = 0;
    bool prev_valid = false;
    for (size_t i = 0; i < rec; i++) {
        uint32_t s = seg[2 * i], e = seg[2 * i + 1];
        for (uint32_t pc = s;; pc += 4) {
            if (prev_valid) {
                uint8_t k = kind_of(prev);
                if (k) {
                    n_ctrl++;
                    uint32_t pw = prev >> 2, nw = pc >> 2;
                    for (size_t c = 0; c < sim.size(); c++) sim[c].step(pw, nw, k, (int)c == topcfg);
                } else if (pc != prev + 4) {
                    bad_seg++;                    // 段边界落在非控制转移上 = trace/反汇编对不上
                }
            }
            prev = pc; prev_valid = true; n_instr++;
            if (pc == e) break;
        }
    }
    printf("指令数：%llu   控制转移：%llu   段边界非控制转移：%llu (%.2f%%)\n\n",
           (unsigned long long)n_instr, (unsigned long long)n_ctrl,
           (unsigned long long)bad_seg, 100.0 * bad_seg / std::max<uint64_t>(rec, 1));

    const double CPF = 3.0;   // 每次误预测约 3 拍（丢 1 条错误路径指令 + 重定向重取）
    printf("%-24s | %11s | %8s | %8s | %9s | %8s | %8s | %8s | %9s\n",
           "配置", "误预测", "误预测率", "vs dm4", "估省周期", "分支错", "jal错", "jalr错", "命中率");
    printf("-------------------------+-------------+----------+----------+-----------+----------+----------+----------+-----------\n");
    double base = 0;
    for (size_t i = 0; i < cfgs.size(); i++) if (!strncmp(cfgs[i].name, "dm4 ", 4)) base = sim[i].miss;
    if (base == 0) base = 1;
    for (size_t i = 0; i < cfgs.size(); i++) {
        BTB &b = sim[i];
        printf("%-24s | %11llu | %7.2f%% | %+7.1f%% | %8.0fM | %8llu | %8llu | %8llu | %8.1f%%\n",
               cfgs[i].name, (unsigned long long)b.miss, 100.0 * b.miss / b.ctrl,
               100.0 * (b.miss - base) / base, (base - b.miss) * CPF / 1e6,
               (unsigned long long)b.mb, (unsigned long long)b.mj, (unsigned long long)b.mi,
               100.0 * b.hit / b.ctrl);
    }
    printf("\n（每次误预测按 %.0f 拍折算；“vs dm4” 是相对当前 4 项直接映射的变化）\n", CPF);

    if (topn > 0) {
        if (topcfg >= 0) {
            std::vector<std::pair<uint64_t, uint32_t>> v;
            for (auto &kv2 : sim[topcfg].perpc) v.push_back({kv2.second, kv2.first});
            std::sort(v.rbegin(), v.rend());
            printf("\n%s 误预测最多的分支：\n", cfgs[topcfg].name);
            for (int i = 0; i < topn && i < (int)v.size(); i++)
                printf("   %#010x  %10llu\n", v[i].second, (unsigned long long)v[i].first);
        }
    }
    return 0;
}
