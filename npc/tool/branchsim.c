#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define INDEX_WIDTH 3          // 3 位 => 8 组
#define BTB_SETS    (1 << INDEX_WIDTH)
// 预测算法类型
typedef enum {
    ALWAYS_TAKEN,      // 总是跳转
    ALWAYS_NOT_TAKEN,  // 总是不跳转
    BTFN               // Backward Taken, Forward Not-taken
} PredictionAlgorithm;

// BTB条目结构
typedef struct {
    uint32_t tag;       // 地址标签
    uint32_t target;    // 目标地址
    int valid;          // 有效位
} BTBEntry;

typedef struct {
    BTBEntry way[2];
} BTBSet;

// 分支指令信息
typedef struct {
    uint32_t pc;        // 指令地址
    uint32_t target_pc; // 目标地址
    uint32_t dnpc;      // 下一条指令地址
    int taken;          // 实际是否跳转
    int predicted;      // 预测是否跳转
    int btb_hit;        // BTB是否命中
    int correct;        // 预测是否正确
} BranchRecord;

// 分支预测模拟器
typedef struct {
    PredictionAlgorithm algorithm;  // 预测算法
    BranchRecord* records;          // 分支记录数组
    BTBSet* btb;                  // BTB表
    uint32_t btb_size;              // BTB大小
    uint32_t btb_index_bits;        // BTB索引位数
    uint64_t total_branches;        // 总分支指令数
    uint64_t correct_predictions;   // 正确预测数
    uint64_t btb_hits;              // BTB命中数
    uint64_t btb_misses;            // BTB未命中数
} BranchSim;

// 初始化BTB
void init_btb(BranchSim* sim) {
    sim->btb_size = BTB_SETS;          // = 8
    sim->btb      = (BTBSet*)calloc(BTB_SETS, sizeof(BTBSet));
    sim->btb_index_bits = INDEX_WIDTH; // = 3
    
}

// 计算BTB索引
uint32_t get_btb_index(uint32_t pc, uint32_t index_bits) {
    return (pc >> 2) & ((1 << index_bits) - 1);
}

// 计算BTB标签
uint32_t get_btb_tag(uint32_t pc, uint32_t index_bits) {
    return pc >> (index_bits + 2);
}

// 查询BTB
int query_btb(BranchSim* sim, uint32_t pc, uint32_t* target) {
    uint32_t idx = get_btb_index(pc, sim->btb_index_bits);
    uint32_t tag = get_btb_tag(pc, sim->btb_index_bits);

    for (int w = 0; w < 2; ++w) {
        const BTBEntry* e = &sim->btb[idx].way[w];
        if (e->valid && e->tag == tag) {
            *target = e->target;
            return 1;        // hit
        }
    }
    return 0;  
}

// 更新BTB
static uint32_t repl_counter = 0;   // 全局 1-bit LFSR/计数器

void update_btb(BranchSim* sim, uint32_t pc, uint32_t target) {
    uint32_t idx = get_btb_index(pc, sim->btb_index_bits);
    uint32_t tag = get_btb_tag(pc, sim->btb_index_bits);

    // 先看有没有 invalid way
    for (int w = 0; w < 2; ++w) {
        if (!sim->btb[idx].way[w].valid) {
            sim->btb[idx].way[w].valid  = 1;
            sim->btb[idx].way[w].tag    = tag;
            sim->btb[idx].way[w].target = target;
            return;
        }
    }

    // 两个都 valid：用计数器选择一条替换
    int way = repl_counter & 1;
    sim->btb[idx].way[way].tag    = tag;
    sim->btb[idx].way[way].target = target;

    repl_counter++;   // 翻转
}

// 初始化分支预测模拟器
void branchsim_init(BranchSim* sim, PredictionAlgorithm algo, uint32_t btb_size) {
    memset(sim, 0, sizeof(BranchSim));
    sim->algorithm = algo;
    sim->records = NULL;
    
    // 初始化BTB
    init_btb(sim);
}

// 使用指定算法预测分支
int predict_branch(BranchSim* sim, uint32_t pc, uint32_t target_pc) {
    switch (sim->algorithm) {
        case ALWAYS_TAKEN:
            return 1; // 总是预测跳转
            
        case ALWAYS_NOT_TAKEN:
            return 0; // 总是预测不跳转
            
        case BTFN:
            // BTFN: 向后跳转预测跳转，向前跳转预测不跳转
            return (target_pc < pc) ? 1 : 0;
            
        default:
            return 0; // 默认预测不跳转
    }
}

// 处理分支指令
void process_branch(BranchSim* sim, uint32_t pc, uint32_t target_pc, uint32_t dnpc) {
    // 分配更多内存存储记录
    BranchRecord* new_records = realloc(sim->records, 
                                       (sim->total_branches + 1) * sizeof(BranchRecord));
    if (!new_records) {
        perror("内存分配失败");
        return;
    }
    
    sim->records = new_records;
    BranchRecord* record = &sim->records[sim->total_branches];
    
    // 记录分支信息
    record->pc = pc;
    record->target_pc = target_pc;
    record->dnpc = dnpc;
    
    // 判断实际是否跳转 (dnpc != pc+4 表示跳转)
    record->taken = (dnpc != pc + 4);
    
    // 查询BTB
    uint32_t btb_target;
    record->btb_hit = query_btb(sim, pc, &btb_target);
    
    if (record->btb_hit) {
        sim->btb_hits++;
        // 如果BTB命中，使用BTB中的目标地址进行预测
        record->predicted = predict_branch(sim, pc, btb_target);//(btb_target != pc + 4);
    } else {
        sim->btb_misses++;
        // 如果BTB未命中，使用静态预测算法
        record->predicted = predict_branch(sim, pc, target_pc);
    }
    
    // 检查预测是否正确
    record->correct = (record->predicted == record->taken);
    
    // 如果实际跳转，更新BTB
    if (record->taken) {
        update_btb(sim, pc, target_pc);
    }
    
    // 更新统计信息
    sim->total_branches++;
    if (record->correct) {
        sim->correct_predictions++;
    }
}

// 从btrace文件加载分支记录
void load_btrace(BranchSim* sim, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("无法打开btrace文件");
        return;
    }
    
    // 获取文件大小
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // 计算记录数 (每条记录12字节: pc(4) + target_pc(4) + dnpc(4))
    long num_entries = file_size / 12;
    printf("文件大小: %ld 字节, 分支记录数: %ld\n", file_size, num_entries);
    
    uint32_t pc, target_pc, dnpc;
    
    for (long i = 0; i < num_entries; i++) {
        // 读取分支记录
        if (fread(&pc, sizeof(pc), 1, file) != 1) {
            perror("读取PC失败");
            break;
        }
        if (fread(&target_pc, sizeof(target_pc), 1, file) != 1) {
            perror("读取目标地址失败");
            break;
        }
        if (fread(&dnpc, sizeof(dnpc), 1, file) != 1) {
            perror("读取下一条PC失败");
            break;
        }
        
        // 处理分支指令
        process_branch(sim, pc, target_pc, dnpc);
        
        // 每10万条记录显示进度
        // if (i % 100000 == 0 && i > 0) {
        //     printf("已处理 %ld 条分支记录...\n", i);
        // }
    }
    
    fclose(file);
}

// 打印预测结果
void print_results(BranchSim* sim) {
    printf("\n分支预测算法: ");
    switch (sim->algorithm) {
        case ALWAYS_TAKEN: printf("总是跳转\n"); break;
        case ALWAYS_NOT_TAKEN: printf("总是不跳转\n"); break;
        case BTFN: printf("BTFN (向后跳转预测跳转，向前跳转预测不跳转)\n"); break;
    }
    
    printf("BTB大小: %u 条目\n", sim->btb_size);
    printf("分支指令数: %lu\n", sim->total_branches);
    printf("正确预测数: %lu\n", sim->correct_predictions);
    printf("BTB命中数: %lu\n", sim->btb_hits);
    printf("BTB未命中数: %lu\n", sim->btb_misses);
    
    if (sim->total_branches > 0) {
        printf("预测准确率: %.2f%%\n", 
               (double)sim->correct_predictions / sim->total_branches * 100);
        printf("BTB命中率: %.2f%%\n", 
               (double)sim->btb_hits / sim->total_branches * 100);
        
        // 计算性能收益 (假设错误预测代价为2周期)
        double penalty_per_miss = 2.0;
        double total_penalty = (sim->total_branches - sim->correct_predictions) * penalty_per_miss;
        printf("总惩罚周期: %.0f\n", total_penalty);
        printf("平均每分支指令惩罚周期: %.4f\n", total_penalty / sim->total_branches);
    } else {
        printf("未发现分支指令\n");
    }
    
    // 打印前几条记录的详细信息 (用于调试)
    printf("\n前10条分支记录的详细信息:\n");
    printf("PC        | Target   | Next PC | Actual | Predicted | BTB Hit | Correct\n");
    printf("----------+----------+---------+--------+-----------+---------+--------\n");
    
    int num_to_show = (sim->total_branches < 10) ? sim->total_branches : 10;
    for (int i = 0; i < num_to_show; i++) {
        BranchRecord* record = &sim->records[i];
        printf("%08x | %08x | %08x | %6s | %9s | %7s | %6s\n",
               record->pc, record->target_pc, record->dnpc,
               record->taken ? "跳转" : "不跳转",
               record->predicted ? "跳转" : "不跳转",
               record->btb_hit ? "是" : "否",
               record->correct ? "是" : "否");
    }
    
    // 打印BTB内容 (用于调试)
    printf("\nBTB内容:\n");
    printf("Index | Valid | Tag        | Target\n");
    printf("------+-------+------------+------------\n");
    
    // for (uint32_t i = 0; i < sim->btb_size; i++) {
    //     if (sim->btb[i].valid) {
    //         printf(" %4u |    %d   | 0x%08x | 0x%08x\n", 
    //                i, sim->btb[i].valid, sim->btb[i].tag, sim->btb[i].target);
    //     }
    // }
}

// 释放分配的内存
void branchsim_free(BranchSim* sim) {
    if (sim->records) {
        free(sim->records);
        sim->records = NULL;
    }
    
    if (sim->btb) {
        free(sim->btb);
        sim->btb = NULL;
    }
}



int main(int argc, char* argv[]) {
    
    
    // 设置默认值
    PredictionAlgorithm algo = BTFN;
    uint32_t btb_size = 1024;
    
    algo = ALWAYS_TAKEN;
    //algo = BTFN;
    // 解析BTB大小参数
    if (argc >= 4) {
        btb_size = atoi(argv[3]);
    }
    
    // 确保BTB大小是2的幂
    if ((btb_size & (btb_size - 1)) != 0) {
        printf("错误: BTB大小必须是2的幂\n");
        return 1;
    }
    
    BranchSim sim;
    branchsim_init(&sim, algo, btb_size);
    
    printf("开始处理B类指令跟踪文件: %s\n", argv[1]);
    printf("使用算法: ");
    switch (sim.algorithm) {
        case ALWAYS_TAKEN: printf("总是跳转\n"); break;
        case ALWAYS_NOT_TAKEN: printf("总是不跳转\n"); break;
        case BTFN: printf("BTFN\n"); break;
    }
    printf("BTB大小: %u\n", sim.btb_size);
    
    // 处理btrace文件
    load_btrace(&sim, argv[1]);
    
    // 输出结果
    print_results(&sim);
    
    // 释放内存
    branchsim_free(&sim);
    
    return 0;
}