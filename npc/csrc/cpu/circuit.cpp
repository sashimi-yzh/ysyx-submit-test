#include <stdio.h>
#include <stdint.h>


#include <circuit.h>
#include <wave.h>
#include <mem.h>
#include <common.h>
#include <utils.h>
#include "../monitor/sdb/sdb.h"

#include <lightsss.h> // 确保路径正确
#define FORK_INTERVAL 500 // 示例：每 10,00 个周期 fork 一次

#ifdef NPCCONFIG_PERF
/*temp val*/
unsigned long long int cyc_start_time = 0;//ifu req new inst
unsigned long long int cyc_end_time = 0;//wbu out fire

unsigned long long int pre_cycle_num_ifu_getinst = 0;
unsigned long long int pre_cycle_num_lsu_readdata = 0;
unsigned long long int pre_cycle_num_lsu_writedata = 0;
unsigned long long int pre_cycle_num_exu_fshcal = 0;
unsigned char ifu_getinst_flag = 0;
unsigned char lsu_readdata_flag = 0;
unsigned char lsu_writedata_flag = 0;
unsigned char exu_fshcal_flag = 0;

unsigned char jump_flag = 0;
unsigned char branch_flag = 0;
unsigned char store_flag = 0;
unsigned char load_flag = 0;
unsigned char csr_flag = 0;
unsigned char other_flag = 0;
unsigned long long int pre_cycle_num_jump = 0;
unsigned long long int pre_cycle_num_branch = 0;
unsigned long long int pre_cycle_num_store = 0;
unsigned long long int pre_cycle_num_load = 0;
unsigned long long int pre_cycle_num_csr = 0;
unsigned long long int pre_cycle_num_other = 0;

unsigned long long int pre_cycle_num_icache_hit = 0;
unsigned long long int pre_cycle_num_icache_miss = 0;
unsigned char icache_hit_flag = 0;
unsigned char icache_miss_flag = 0;

/*counters*/
unsigned long long int cycle_num = 0;
unsigned long long int inst_num = 0;

unsigned long long int ev_ifu_getinst_cnt = 0;
unsigned long long int ev_lsu_readdata_cnt = 0;
unsigned long long int ev_lsu_writedata_cnt = 0;
unsigned long long int ev_exu_fshcal_cnt = 0;
unsigned long long int cyc_ifu_getinst_cnt = 0;
unsigned long long int cyc_lsu_readdata_cnt = 0;
unsigned long long int cyc_lsu_writedata_cnt = 0;
unsigned long long int cyc_exu_fshcal_cnt = 0;

unsigned long long int ev_is_jump_cnt = 0;
unsigned long long int ev_is_branch_cnt = 0;
unsigned long long int ev_is_store_cnt = 0;
unsigned long long int ev_is_load_cnt = 0;
unsigned long long int ev_is_csr_cnt = 0;
unsigned long long int ev_is_other_cnt = 0;
unsigned long long int cyc_is_jump_cnt = 0;
unsigned long long int cyc_is_branch_cnt = 0;
unsigned long long int cyc_is_store_cnt = 0;
unsigned long long int cyc_is_load_cnt = 0;
unsigned long long int cyc_is_csr_cnt = 0;
unsigned long long int cyc_is_other_cnt = 0;

unsigned long long int ev_iCache_hit_cnt = 0;
unsigned long long int cyc_iCache_hit_cnt = 0;
unsigned long long int ev_iCache_miss_cnt = 0;
unsigned long long int cyc_iCache_miss_cnt = 0;

void PerfAnalysis(){
    cycle_num ++;
    if(CYC_START){
        inst_num++;
        cyc_start_time = cycle_num;
    }
    if(CYC_END){
        cyc_end_time = cycle_num;
    }
    if(EV_IFU_GETINST_FIRE){
        ev_ifu_getinst_cnt++;
        ifu_getinst_flag = 1;
        pre_cycle_num_ifu_getinst = cycle_num;
    }
    if(EV_LSU_READDATA_FIRE){
        ev_lsu_readdata_cnt++;
        lsu_readdata_flag = 1;
        pre_cycle_num_lsu_readdata = cycle_num;
    }
    if(EV_LSU_WRITEDATA_FIRE){
        ev_lsu_writedata_cnt++;
        lsu_writedata_flag = 1;
        pre_cycle_num_lsu_writedata = cycle_num;
    }
    if(EV_EXU_FSHCAL_FIRE){
        ev_exu_fshcal_cnt++;
        exu_fshcal_flag = 1;
        pre_cycle_num_exu_fshcal = cycle_num;
    }
    if(IFU_GETINST_DONE && ifu_getinst_flag){
            ifu_getinst_flag = 0;
            cyc_ifu_getinst_cnt += cycle_num - pre_cycle_num_ifu_getinst;
            pre_cycle_num_ifu_getinst = 0;
    }
    if(LSU_READDATA_DONE && lsu_readdata_flag){
            lsu_readdata_flag = 0;
            cyc_lsu_readdata_cnt += cycle_num - pre_cycle_num_lsu_readdata;
            pre_cycle_num_lsu_readdata = 0;
    }
    if(LSU_WRITEDATA_DONE && lsu_writedata_flag){
            lsu_writedata_flag = 0;
            cyc_lsu_writedata_cnt += cycle_num - pre_cycle_num_lsu_writedata;
            pre_cycle_num_lsu_writedata = 0;
    }
    if(EXU_FSHCAL_DONE && exu_fshcal_flag){
            exu_fshcal_flag = 0;
            cyc_exu_fshcal_cnt += cycle_num - pre_cycle_num_exu_fshcal;
            pre_cycle_num_exu_fshcal = 0;
    }
    if(INST_VALID && IS_JUMP){
        ev_is_jump_cnt++;
        jump_flag = 1;
        pre_cycle_num_jump = cycle_num;

    }
    if(INST_VALID && IS_BRANCH){
        ev_is_branch_cnt++;
        branch_flag = 1;
        pre_cycle_num_branch = cycle_num;
    }
    if(INST_VALID && IS_STORE){
        ev_is_store_cnt++;
        store_flag = 1;
        pre_cycle_num_store = cycle_num;
    }
    if(INST_VALID && IS_LOAD){
        ev_is_load_cnt++;
        load_flag = 1;
        pre_cycle_num_load = cycle_num;
    }
    if(INST_VALID && IS_CSR){
        ev_is_csr_cnt++;
        csr_flag = 1;
        pre_cycle_num_csr = cycle_num;
    }
    if(INST_VALID && IS_OTHER){
        ev_is_other_cnt++;
        other_flag = 1;
        pre_cycle_num_other = cycle_num;
    }

    if(CYC_END){
        if(jump_flag  )   {jump_flag = 0; cyc_is_jump_cnt += (cyc_end_time - pre_cycle_num_jump); pre_cycle_num_jump = 0;}
        if(branch_flag)   {branch_flag = 0; cyc_is_branch_cnt += (cyc_end_time - pre_cycle_num_branch); pre_cycle_num_branch = 0;}
        if(store_flag )   {store_flag = 0; cyc_is_store_cnt += (cyc_end_time - pre_cycle_num_store); pre_cycle_num_store = 0;}
        if(load_flag  )   {load_flag = 0; cyc_is_load_cnt += (cyc_end_time - pre_cycle_num_load); pre_cycle_num_load = 0;}
        if(csr_flag   )   {csr_flag = 0; cyc_is_csr_cnt += (cyc_end_time - pre_cycle_num_csr); pre_cycle_num_csr = 0;}
        if(other_flag )   {other_flag = 0; cyc_is_other_cnt += (cyc_end_time - pre_cycle_num_other); pre_cycle_num_other = 0;}
    }
    if(EV_ICACHE_FIRE){
        icache_hit_flag = 1;
        icache_miss_flag = 1;
        pre_cycle_num_icache_hit = cycle_num;
        pre_cycle_num_icache_miss = cycle_num;
    }
    if(EV_ICACHE_HIT_FIRE && icache_hit_flag){
        ev_iCache_hit_cnt++;
        icache_hit_flag = 0;
        icache_miss_flag = 0;
        cyc_iCache_hit_cnt += cycle_num - pre_cycle_num_icache_hit;
        pre_cycle_num_icache_hit = 0;
    }
    if(EV_ICACHE_MISS_FIRE && icache_miss_flag){
        ev_iCache_miss_cnt++;
        icache_hit_flag = 0;
        icache_miss_flag = 0;
        cyc_iCache_miss_cnt += cycle_num - pre_cycle_num_icache_miss;
        pre_cycle_num_icache_miss = 0;
    }
}

static void save2csv(const char *filename){
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "|**指标**|**数值**|\n");
    fprintf(file, "|:---:|:---:|\n");
    fprintf(file, "|总周期数|%llu|\n",
            cycle_num);
    fprintf(file, "|总指令数|%llu|\n",
            inst_num);
    fprintf(file, "|IPC|%.2lf|\n",
            (double)inst_num / cycle_num);
    fprintf(file, "|CPI|%.2lf|\n",
            (double)cycle_num / inst_num);





    fprintf(file, "\n\n");





    fprintf(file, "|**行为事件**|**事件数量(个)**|**周期数量(个)**|**平均需要周期(个)**|\n");
    fprintf(file, "|:---:|:---:|:---:|:---:|\n");
    fprintf(file, "|IFU取指令|%llu|%llu|%.2lf|\n", \
            ev_ifu_getinst_cnt, \
            cyc_ifu_getinst_cnt, \
            (double)cyc_ifu_getinst_cnt / ev_ifu_getinst_cnt);
    fprintf(file, "|LSU读数据|%llu|%llu|%.2lf|\n", \
            ev_lsu_readdata_cnt, \
            cyc_lsu_readdata_cnt, \
            (double)cyc_lsu_readdata_cnt / ev_lsu_readdata_cnt);
    fprintf(file, "|LSU写数据|%llu|%llu|%.2lf|\n", \
            ev_lsu_writedata_cnt, \
            cyc_lsu_writedata_cnt, \
            (double)cyc_lsu_writedata_cnt / ev_lsu_writedata_cnt);
    fprintf(file, "|EXU计算结果|%llu|%llu|%.2lf|\n", \
            ev_exu_fshcal_cnt, \
            cyc_exu_fshcal_cnt, \
            (double)cyc_exu_fshcal_cnt / ev_exu_fshcal_cnt);





    fprintf(file, "\n\n");




    /*这里的指令相关周期是 : 得到指令直到完成指令执行(IFU取到指令 --> WBU写回完成握手), 不包括IFU的取指等待时间*/
    /*所以将消耗周期占比的分母换成周期数量的总和, 而不是总的周期数量*/
    unsigned long long int cyc_sum_0 = cyc_is_jump_cnt + cyc_is_branch_cnt + cyc_is_store_cnt + cyc_is_load_cnt + cyc_is_csr_cnt + cyc_is_other_cnt;
    fprintf(file, "|**指令事件**|**事件数量(个)**|**指令占比(%%)**|**周期数量(个)**|**平均需要周期(个)**|**消耗周期占比(%%)**|\n");
    fprintf(file, "|:---:|:---:|:---:|:---:|:---:|:---:|\n");
    fprintf(file, "|跳转|%llu|%.2lf%%|%llu|%.2lf|%.2lf%%|\n", \
            ev_is_jump_cnt, \
            (double)ev_is_jump_cnt * 100 / inst_num, \
            cyc_is_jump_cnt, \
            (double)cyc_is_jump_cnt / ev_is_jump_cnt, \
            (double)cyc_is_jump_cnt * 100 / cyc_sum_0);
    fprintf(file, "|分支|%llu|%.2lf%%|%llu|%.2lf|%.2lf%%|\n", \
            ev_is_branch_cnt, \
            (double)ev_is_branch_cnt * 100 / inst_num, \
            cyc_is_branch_cnt, \
            (double)cyc_is_branch_cnt / ev_is_branch_cnt, \
            (double)cyc_is_branch_cnt * 100 / cyc_sum_0);
    fprintf(file, "|存储|%llu|%.2lf%%|%llu|%.2lf|%.2lf%%|\n", \
            ev_is_store_cnt, \
            (double)ev_is_store_cnt * 100 / inst_num, \
            cyc_is_store_cnt, \
            (double)cyc_is_store_cnt / ev_is_store_cnt, \
            (double)cyc_is_store_cnt * 100 / cyc_sum_0);
    fprintf(file, "|加载|%llu|%.2lf%%|%llu|%.2lf|%.2lf%%|\n", \
            ev_is_load_cnt, \
            (double)ev_is_load_cnt * 100 / inst_num, \
            cyc_is_load_cnt, \
            (double)cyc_is_load_cnt / ev_is_load_cnt, \
            (double)cyc_is_load_cnt * 100 / cyc_sum_0);
    fprintf(file, "|CSR|%llu|%.2lf%%|%llu|%.2lf|%.2lf%%|\n", \
            ev_is_csr_cnt, \
            (double)ev_is_csr_cnt * 100 / inst_num, \
            cyc_is_csr_cnt, \
            (double)cyc_is_csr_cnt / ev_is_csr_cnt, \
            (double)cyc_is_csr_cnt * 100 / cyc_sum_0);
    fprintf(file, "|其他|%llu|%.2lf%%|%llu|%.2lf|%.2lf%%|\n", \
            ev_is_other_cnt, \
            (double)ev_is_other_cnt * 100 / inst_num, \
            cyc_is_other_cnt, \
            (double)cyc_is_other_cnt / ev_is_other_cnt, \
            (double)cyc_is_other_cnt * 100 / cyc_sum_0);





    fprintf(file, "\n\n");




    fprintf(file, "|**----**|**命中数量(个)**|**Cache命中平均访问周期(个)**|**缺失数量(个)**|**Cache缺失平均访问周期(个)**|**命中率(%%)**|**AMAT**|\n");
    fprintf(file, "|:---:|:---:|:---:|:---:|:---:|:---:|:---:|\n");
    fprintf(file, "|iCache|%llu|%.2lf|%llu|%.2lf|%.2lf%%|%.2lf|\n", \
            ev_iCache_hit_cnt, \
            (double)cyc_iCache_hit_cnt / ev_iCache_hit_cnt, \
            ev_iCache_miss_cnt, \
            (double)cyc_iCache_miss_cnt / ev_iCache_miss_cnt, \
            (double)ev_iCache_hit_cnt * 100 / ev_ifu_getinst_cnt, \
            (double)cyc_iCache_hit_cnt / (double)ev_iCache_hit_cnt + (1 - (double)ev_iCache_hit_cnt / (double)ev_ifu_getinst_cnt) * ((double)cyc_iCache_miss_cnt / (double)ev_iCache_miss_cnt));

    fclose(file);
}

#endif







uint64_t total_cyc = 0;
int child_first_in = 0;
word_t pre_pc, now_pc;

LightSSS lightsss;
uint64_t light_cycle_num = 0;



#ifdef NPCCONFIG_TOP_IS_YSYXSOC
VysyxSoCFull *top = init_top();
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
VNPC *top = init_top();
#endif

static uint8_t opcode;
static uint8_t rd;
static uint8_t src1;

void difftest_step();
extern "C" void npc_trap();
void single_cycle(){

    top->clock = 0;
    top->eval();

#if defined(NPCCONFIG_DUMPWAVE) || defined(NPCCONFIG_LIGHTSSS)
#ifdef NPCCONFIG_LIGHTSSS
    char wave_path[1024];
    snprintf(wave_path, sizeof(wave_path), "%s/build/wave_child.fst", npc_home_path);
    if(lightsss.is_child()){
        if(child_first_in == 0){
            child_first_in = 1;
            init_wave(wave_path);
            printf("============LIGHTSSS初始化成功!============\n");
        }
        dump_wave();
    }
#else
    dump_wave();
#endif
#endif


#ifdef NPCCONFIG_ITRACE
    if(top->reset == 0 && DIFFVALID == 1)
        itrace_init(PC, INSTR);
#endif


    top->clock = 1;
    top->eval();
    if(ISEBREAK == 1) npc_trap();


#if defined(NPCCONFIG_DUMPWAVE) || defined(NPCCONFIG_LIGHTSSS)
#ifdef NPCCONFIG_LIGHTSSS
        if(lightsss.is_child()){
            dump_wave();
        }
#else
        dump_wave();
#endif
#endif


#ifdef NPCCONFIG_LIGHTSSS
    light_cycle_num++;
#endif

    total_cyc++;
}



void reset(int i) {
    top->reset = 1;
     while (i -- > 0){
        single_cycle();
     }
    top->reset = 0;
}


static void trace_and_difftest(){

#ifdef NPCCONFIG_DIFFTEST
    difftest_step();
#endif

#ifdef NPCCONFIG_WATCHPOINT
    wp_difftest();
#endif

#ifdef NPCCONFIG_FTRACE
    opcode = BITS(INSTR, 6, 0);
    rd = BITS(INSTR, 11, 7);
    if(opcode == JAL && rd == 0b00001){
        display_call_func(PC, PC);
    }
    else if(opcode == JALR){
        src1 = BITS(INSTR, 19, 15);
        if(rd == 0b00001){
            display_call_func(PC, PC);
        }
        else if(rd == 0b00000 && gpr[src1] == gpr[1]){
            display_ret_func(PC);
        }
    }
 #endif

}



static void exec_once(){
#ifdef NV_BOARD
    nvboard_update();
#endif
    single_cycle();
}

void cpu_exec(uint64_t n){
    while(n > 0){





#ifdef NPCCONFIG_LIGHTSSS
    if (light_cycle_num % FORK_INTERVAL == 0 && !lightsss.is_child()) {
        int fork_ret = lightsss.do_fork();
        if (fork_ret == FORK_ERROR) {
            // 处理 fork 错误
            printf("LightSSS fork error!\n");
            assert(0);
        }
    }
#endif

    exec_once();
    get_reg();

#ifdef NPCCONFIG_PERF
    PerfAnalysis();
#endif

#ifdef NPCCONFIG_DIFFTEST
    if(DIFFVALID){
        trace_and_difftest();
    }
#endif

    n--;
    }
}

extern "C" void npc_trap(){
#if defined(NPCCONFIG_DUMPWAVE) || defined(NPCCONFIG_LIGHTSSS)
#ifdef NPCCONFIG_DUMPWAVE
    dump_wave();
    close_wave(1);
    printf("=====================波形正常退出, 查看father波形=====================\n");
#else
    if(lightsss.is_child()){
        dump_wave();
        close_wave(1);
        printf("=====================波形正常退出, 查看child波形=====================\n");
    }else{
        lightsss.wakeup_child(light_cycle_num);
    }
#endif
#endif
    bool success;
    int code = isa_reg_str2val("a0",&success);
    if(code == 0){
        printf("\033[1;32mHIT GOOD TRAP\033[0m at pc = 0x%x\n", PC);
    }
    else{
        printf("\033[1;31mHIT BAD TRAP\033[0m at pc = 0x%x\nexit code = %d\n",PC, code);
    }

#ifdef NPCCONFIG_ITRACE
    itrace_init(PC, INSTR);
    display_inst();
#endif

#ifdef NPCCONFIG_PERF
    char perf_path[1024];
    snprintf(perf_path, sizeof(perf_path), "%s/build/perf.md", npc_home_path);
    save2csv(perf_path)
#endif
    printf("total cyc = %ld\n", total_cyc);
    exit(0);
}
