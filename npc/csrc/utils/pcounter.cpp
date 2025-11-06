// 一些性能计数器
#include<pcounter.h>

// TODO：规划四个函数，统计次数就可以了
uint64_t ifu_r_counter  = 0;
uint64_t lsu_r_counter  = 0;
uint64_t lsu_w_counter  = 0;
uint64_t exeu_counter   = 0;
uint64_t idu_cal_type   = 0;
uint64_t idu_mem_type   = 0;
uint64_t idu_jump_type  = 0;    // jal，jalr，B-type
uint64_t idu_csr_type   = 0;

// 指令的类别
uint64_t ins_type       = 0;
// 指令开始时间
uint64_t ins_start_time = 0;

// 读开始的时间
uint64_t read_start     = 0;
// 读取用的总时间
uint64_t read_time      = 0;

// 写开始的时间
uint64_t write_start    = 0;
// 写用的总时间
uint64_t write_time     = 0;

// cache 命中的总次数
int new_ins             = 1;
uint64_t cache_hit_cnt  = 0;
// cache 开始访问的时间
uint64_t cache_access_start = 0;
// cache 命中用的总时间，没有命中的使用读取所用的总时间就可以了
uint64_t cache_access_time_all  = 0;

// cache miss的总次数
uint64_t cache_miss_cnt = 0;
// cache miss了之后访问sdram的开始时间
uint64_t cache_miss_start = 0;
// cache miss后fill用的总时间
uint64_t cache_miss_time_all = 0;

// 用于绘图展示
FILE *perf_fp = NULL;
FILE *perf_time_fp = NULL;
const char *trace_csv = "tools/performance-trace/trace.csv";
const char *trace_csv2 = "tools/performance-trace/trace2.csv";

// 涉及axi的取指和访存模块
extern "C" void axi_handshake(svBit valid, svBit ready, svBit last, int operate_type){
    if(valid && ready && last){
        switch (operate_type)
        {
            // 读指令
            case 1: {
                ifu_r_counter++;
                break;
            }
            // 读数据
            case 2: {
                lsu_r_counter++;
                break;
            }
            // 写数据
            case 3: {
                lsu_w_counter++;
                break;
            }
            default:
                assert("cannot reach hear");
                break;
            }
    }
}

extern "C" void exeu_finish(svBit exe_valid){
    if(exe_valid){
        exeu_counter++;
    }
}

// 这个比ifu取指出来的结果会少1,因为没有考虑ebreak指令的译码操作
extern "C" void idu_instr_type(svBit id_valid, int opcode){
    if(id_valid){
        switch (opcode)
        {
            // 计算类型
            case 0x33: case 0x13: case 0x37: case 0x17: {
                idu_cal_type++;
                ins_type = 0;
                break;
            }
            // 访存类型
            case 0x23: {    // store类型
                idu_mem_type++;
                ins_type = 1;
                break;
            }
            case 0x3: {     // load类型
                idu_mem_type++;
                ins_type = 2;
                break;
            }
            // 跳转类型
            case 0x63: case 0x67: case 0x6f: {
                idu_jump_type++;
                ins_type = 3;
                break;
            }
            // csr类型
            case 0x73: {
                idu_csr_type++;
                ins_type = 4;
                break;
            }
            default:
                break;
        }
        // printf("idu_cal_type : %lu, idu_mem_type : %lu, idu_jump_type : %lu , idu_csr_type : %lu\n",idu_cal_type,idu_mem_type,idu_jump_type,idu_csr_type);
    }
}

extern "C" void ins_start(svBit new_ins_valid){
    if(new_ins_valid){
        // 这里的cycle是CPU运行的时钟周期数
        ins_start_time = cycle;
    }
}

// 使用的有效信号是arvalid/awvalid以及rready/bready，前者控制访存的开始，后者控制访存的结束
extern "C" void lsu_read_latency(svBit arvalid, svBit rvalid){
    if(arvalid){
        read_start = cycle;
    }

    if(rvalid){
        read_time += (cycle - read_start + 2);    // 加2是因为在使用DPI-C的时候，没有计数
    }
}

extern "C" void lsu_write_latency(svBit awvalid, svBit bvalid){
    if(awvalid){
        write_start = cycle;
    }

    if(bvalid){
        write_time += (cycle - write_start + 2);    // 加2是因为在使用DPI-C的时候，没有计数
    }
}

extern "C" void cache_hit(svBit valid,svBit hit){
    if(valid){
        new_ins = 1;
    }
    if(new_ins && hit){
        cache_hit_cnt++;
        new_ins = 0;
    }
}

extern "C" void cache_access_time(svBit arvalid,svBit rvalid){
    if(arvalid){
        cache_access_start = cycle;
    }

    if(rvalid){
        cache_access_time_all += (cycle - cache_access_start + 2);
    }
}

extern "C" void cache_miss_time(svBit cache_fill_start, svBit cache_fill_end){
    if(cache_fill_start){
        cache_miss_start = cycle;
        cache_miss_cnt   += 1;
    }

    if(cache_fill_end){
        cache_miss_time_all += (cycle - cache_miss_start + 2);
    }
}

void record_performance_trace(uint64_t cycle, uint64_t instCnt){
    if(cycle == 1 && perf_fp == NULL){
        perf_fp         = fopen(trace_csv   , "w");
        perf_time_fp    = fopen(trace_csv2  , "w");
        Assert(perf_time_fp, "Can not open '%s'", trace_csv2);
        Assert(perf_fp, "Can not open '%s'", trace_csv);
        fprintf(perf_fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n", "cpu Cycle", "指令数", "IFU获得指令", "EXU结束计算", "LSU获得数据", "计算指令", "访存指令", "跳转指令", "csr指令");
        fprintf(perf_time_fp, "%s,%s,%s,%s,%s\n", "总时间", "计算指令占用时间", "访存指令占用时间", "跳转指令占用时间", "csr指令占用时间");
    } else if(perf_fp != NULL) {
        fprintf(perf_fp, 
        "%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu\n",
        cycle, instCnt, ifu_r_counter, exeu_counter, (lsu_r_counter + lsu_w_counter),
        idu_cal_type, idu_mem_type, idu_jump_type, idu_csr_type);
    }
}

// 结束时调用的关闭函数
void close_csv() {
    fclose(perf_fp);
    fclose(perf_time_fp);
}