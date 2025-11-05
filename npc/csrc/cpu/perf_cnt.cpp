#include "verilator.h"
#include <locale.h>
#include <color.h>
#include <debug.h>

#define IFU (NPC_CPU->ifu)
#define IDU (NPC_CPU->idu)
#define EXU (NPC_CPU->exu)
#define LSU (NPC_CPU->lsu)
#define WBU (NPC_CPU->wbu)
#define ICACHE (NPC_CPU->icache)


#define PERF_IFU_CNT(_) \
_(ifu_cnt) _(flush_cnt) _(branch_predict_failed_cnt) _(flush_cycle_cnt) _(jmp_cnt) _(branch_cnt)

#define PERF_IDU_CNT(_) \
_(inst_compute_cnt) _(inst_branch_cnt) _(inst_jump_cnt) _(inst_ldst_cnt) _(inst_csr_cnt) \
_(cycle_compute_cnt) _(cycle_branch_cnt) _(cycle_jump_cnt) _(cycle_ldst_cnt) _(cycle_csr_cnt) \
_(stall_cnt) 

#define PERF_EXU_CNT(_) \
_(alu_arith_cnt) _(alu_logic_cnt) _(alu_shift_cnt) _(alu_cmp_cnt) _(alu_copy_cnt)

#define PERF_LSU_CNT(_) \
_(load_cnt) _(store_cnt) _(cycle_load_cnt) _(cycle_store_cnt)

#define PERF_WBU_CNT(_) \
_(inst_cnt) _(cycle_cnt)

#define PERF_ICACHE_CNT(_) \
_(icache_access_cnt) _(icache_hit_cnt) _(icache_bypass_cnt) _(icache_hit_access_time_cnt) _(icache_miss_penalty_cnt)


#define CPU_UNIT(_) \
_(IDU) _(EXU) _(LSU) _(WBU) _(ICACHE)



#define PERF_CNT_DECL(counter) static uint64_t counter = 0;

PERF_IFU_CNT(PERF_CNT_DECL)
PERF_IDU_CNT(PERF_CNT_DECL)
PERF_EXU_CNT(PERF_CNT_DECL)
PERF_LSU_CNT(PERF_CNT_DECL)
PERF_WBU_CNT(PERF_CNT_DECL)
PERF_ICACHE_CNT(PERF_CNT_DECL)


void perf_get_data(){

#define PERF_IFU_GET(counter) counter = IFU->counter;
#define PERF_IDU_GET(counter) counter = IDU->counter;
#define PERF_EXU_GET(counter) counter = EXU->counter;
#define PERF_LSU_GET(counter) counter = LSU->counter;
#define PERF_WBU_GET(counter) counter = WBU->counter;
#define PERF_ICACHE_GET(counter) counter = ICACHE->counter;
#ifdef CONFIG_PERF_CNT
    PERF_IFU_CNT(PERF_IFU_GET)
    PERF_IDU_CNT(PERF_IDU_GET)
    PERF_EXU_CNT(PERF_EXU_GET)
    PERF_LSU_CNT(PERF_LSU_GET)
    PERF_WBU_CNT(PERF_WBU_GET)
    IFDEF(CONFIG_USE_ICACHE, PERF_ICACHE_CNT(PERF_ICACHE_GET))
#endif 
}

FILE *fp;

#define PRINT_PERF(name, cnt, process_cnt, unit) \
    printf("%24s: %'14lu         # %10.4lf %s\n", \
           name, (uint64_t)cnt, process_cnt, unit);\
    fprintf(fp, "%24s: %'14lu         # %10.4lf %s\n", \
           name, (uint64_t)cnt, process_cnt, unit);

void perf_statistic(){
#ifdef CONFIG_PERF_CNT
    perf_get_data();
    char buf[300];
    sprintf(buf, "%s/build/perf_statistic.txt", getenv("NPC_HOME"));
    fp = fopen(buf,"w");
    fprintf(fp, "\n================================= PERF STATISTIC =================================\n");
    printf("\n================================= PERF STATISTIC =================================\n");
    setlocale(LC_NUMERIC, "en_US.UTF-8");
    
    PRINT_PERF("Total Cycles", cycle_cnt, 0.0, "");
    printf(L_BLUE);
    PRINT_PERF("Total Insts", inst_cnt, (double)inst_cnt/cycle_cnt, "IPC");
    printf(COLOR_NONE);
    printf("\n----------------------------------- Inst Fetch -----------------------------------\n");
    PRINT_PERF("Inst Fetch CNT", ifu_cnt, (double)ifu_cnt/inst_cnt*100, "% of inst");
    printf("\n----------------------------------- Inst Type ------------------------------------\n");
    PRINT_PERF("Compute Insts CNT", inst_compute_cnt, (double)inst_compute_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Branch  Insts CNT", inst_branch_cnt, (double)inst_branch_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Jump    Insts CNT", inst_jump_cnt, (double)inst_jump_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("ld/st   Insts CNT", inst_ldst_cnt, (double)inst_ldst_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("CSR     Insts CNT", inst_csr_cnt, (double)inst_csr_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Compute Cyeles CNT", cycle_compute_cnt, (double)cycle_compute_cnt/inst_compute_cnt, "cycle per inst");
    PRINT_PERF("Branch  Cyeles CNT", cycle_branch_cnt, (double)cycle_branch_cnt/inst_branch_cnt, "cycle per inst");
    PRINT_PERF("Jump    Cyeles CNT", cycle_jump_cnt, (double)cycle_jump_cnt/inst_jump_cnt, "cycle per inst");
    PRINT_PERF("ld/st   Cyeles CNT", cycle_ldst_cnt, (double)cycle_ldst_cnt/inst_ldst_cnt, "cycle per inst");
    PRINT_PERF("CSR     Cyeles CNT", cycle_csr_cnt, 
                                    inst_csr_cnt != 0 ? (double)cycle_csr_cnt/inst_csr_cnt: 0.0 , "cycle per inst");

    printf("\n----------------------------------- ALUOP Type ------------------------------------\n");
    PRINT_PERF("Alu Arith CNT", alu_arith_cnt, (double)alu_arith_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Alu Logic CNT", alu_logic_cnt, (double)alu_logic_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Alu Shift CNT", alu_shift_cnt, (double)alu_shift_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Alu Cmp   CNT", alu_cmp_cnt, (double)alu_cmp_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Alu Copy  CNT", alu_copy_cnt, (double)alu_copy_cnt/inst_cnt*100, "% of inst");

    printf("\n---------------------------------- Load / Store -----------------------------------\n");
    PRINT_PERF("Load CNT", load_cnt, (double)load_cnt/inst_ldst_cnt*100, "% of ld/st inst");
    PRINT_PERF("Store CNT", store_cnt, (double)store_cnt/inst_ldst_cnt*100, "% of ld/st inst");
    PRINT_PERF("Load Cycles CNT", cycle_load_cnt, (double)cycle_load_cnt/load_cnt, "cycle per load");
    PRINT_PERF("Store Cycles CNT", cycle_store_cnt, (double)cycle_store_cnt/store_cnt, "cycle per store");
#ifdef CONFIG_USE_ICACHE
    printf("\n-------------------------------------- ICache --------------------------------------\n");
    if(icache_access_cnt != 0){
    double hit_rate = (double)icache_hit_cnt/icache_access_cnt;
    PRINT_PERF("ICache IFetch CNT", icache_access_cnt+icache_bypass_cnt, 0.0, ""); 
    uint64_t icache_miss_cnt = icache_access_cnt-icache_hit_cnt;
    PRINT_PERF("ICache Access CNT", icache_access_cnt, 
        ((double)icache_hit_access_time_cnt/icache_access_cnt + (1-hit_rate)*icache_miss_penalty_cnt/icache_miss_cnt), "AMAT");
    PRINT_PERF("ICache hit CNT", icache_hit_cnt, hit_rate*100, "% hit rate");
    PRINT_PERF("ICache Bypass CNT", icache_bypass_cnt, (double)icache_bypass_cnt/
                                            (icache_access_cnt+icache_bypass_cnt)*100, "% of ifetch");
    PRINT_PERF("ICache Access Time CNT", icache_hit_access_time_cnt, 
                                    (double)icache_hit_access_time_cnt/icache_access_cnt, "cycle per hit");
    PRINT_PERF("ICache Miss Penalty CNT", icache_miss_penalty_cnt, 
                    (double)icache_miss_penalty_cnt/icache_miss_cnt, "cycle per miss");
    }else{
        printf("No data\n");
    }
#endif 
    printf("\n------------------------------------- Pipeline -------------------------------------\n");
    PRINT_PERF("Flush Cycles CNT", flush_cycle_cnt, (double)flush_cycle_cnt/cycle_cnt*100, "% of total cycles");
    PRINT_PERF("Stall Cycles CNT", stall_cnt, (double)stall_cnt/cycle_cnt*100, "% of total cycles");

    printf("\n--------------------------------------- BPU --------------------------------------\n");
    PRINT_PERF("Branch CNT", branch_cnt, (double)branch_cnt/ifu_cnt*100, "% of ifetch");
    //PRINT_PERF("  Jump CNT", inst_jump_cnt, (double)inst_jump_cnt/inst_cnt*100, "% of inst");
    PRINT_PERF("Predict Faild CNT", branch_predict_failed_cnt, 0.0, "")
    PRINT_PERF("Predict Succ CNT", branch_cnt - branch_predict_failed_cnt,
                 (double)(branch_cnt - branch_predict_failed_cnt)/( branch_cnt )*100, "% of branch");

    fclose(fp);
#endif // CONFIG_PERF_CNT
}
