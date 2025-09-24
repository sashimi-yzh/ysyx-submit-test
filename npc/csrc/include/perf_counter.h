#ifndef __PERF_COUNTER_H__
#define __PERF_COUNTER_H__

#include <common.h>
#include <fstream>
#include <iostream>
#include <iomanip>  // for std::setw()

class PerfCounter {
    private:
        std::string file_name;

        /** CPU */
        uint64_t cycle_num;
        uint64_t inst_num;
        /** IFU */
        struct IFU {
            uint64_t old_cycle_num;
            bool     already_set_old = false;
            uint64_t fetch_inst_num;
            uint64_t fetch_totel_cycle_num;
            struct ICACAHE {
                uint64_t req_num;
                uint64_t hit_num;
                uint64_t miss_num;
                uint64_t totel_miss_penalty;
                uint64_t hit_rate;
            } icache;
        } ifu;
        /** IDU */
        struct IDU {
            uint64_t raw_stall_cycles;
            uint64_t j_inst_num;
            uint64_t br_inst_num;
            uint64_t ld_inst_num;
            uint64_t st_inst_num;
            uint64_t alu_inst_num;
            uint64_t csr_inst_num;
            uint64_t trap_inst_num;
        } idu;
        /** EXU */
        struct EXU {
            uint64_t complete_num;
            uint64_t control_inst_num;
            uint64_t flush_cycles;
            uint64_t bubbles;
        } exu;
        /** LSU */
        struct LSU {
            uint64_t old_cycle_num;
            uint64_t fetch_data_num;
            uint64_t acc_mem_totel_cycle_num;
        } lsu;

        double cal_div(uint64_t a, uint64_t b) {
            return (double)a / (double)b;
        }
    
    public:
        PerfCounter() {}

        #ifdef CONFIG_FAST_SIM

        void setFileName(std::string filename){}
        void updatePerfCounter(){}
        void logToFile(bool append = false){}

        #else

        void setFileName(std::string filename) {
            file_name = filename;
        }

        /** This function is called per cycle to update performance counter. */
        void updatePerfCounter() {
            cycle_num++;
            if (lsu_valid()) inst_num++;
            /** IFU */
            if (ifu_icache_handshake()) ifu.fetch_inst_num++;
            if (ifu_icache_valid() && !ifu.already_set_old) {
                ifu.already_set_old = true;
                ifu.old_cycle_num = cycle_num;
                ifu.icache.req_num++;
                IFDEF(CONFIG_PCTRACE, log_pc((uint32_t)ifu_icache_pc()));
                if (icache_hit()) ifu.icache.hit_num++;
                else {
                    ifu.icache.miss_num++;
                    IFDEF(CONFIG_ICACHE_MISS_PCTRACE, trace_write("0x%.8x\n", ifu_icache_pc()));
                }
            }
            if (ifu_icache_handshake()) {
                assert(ifu.already_set_old);
                ifu.already_set_old = false;
                ifu.fetch_totel_cycle_num += cycle_num - ifu.old_cycle_num + 1; /** "+1" for cache hit is 1 cycle latency. */
                ifu.icache.totel_miss_penalty += cycle_num - ifu.old_cycle_num;
            }
            /** IDU */
            if (raw_stall()) idu.raw_stall_cycles++;
            if (idu_is_jump() && idu_exu_handshake()) idu.j_inst_num++;
            if (idu_exu_handshake()) {
                if (idu_is_branch()) idu.br_inst_num++;
                if (idu_is_load()) idu.ld_inst_num++;
                if (idu_is_store()) idu.st_inst_num++;
                if (idu_is_alu()) idu.alu_inst_num++;
                if (idu_is_csr()) idu.csr_inst_num++;
                if (idu_is_trap()) idu.trap_inst_num++;
            }
            /** EXU */
            if (exu_lsu_handshake()) {
                exu.complete_num++;
                if (is_control()) {
                    exu.control_inst_num++;
                }
            }
            if (lsu_flush()) exu.flush_cycles++;
            if (!idu_valid()) exu.bubbles++;
            /** LSU */
            if (xbar_lsu_r_handshake()) lsu.fetch_data_num++;
            if (lsu_Xbar_ar_handshake() || lsu_Xbar_aw_handshake()) lsu.old_cycle_num = cycle_num;
            if (xbar_lsu_r_handshake() || xbar_lsu_b_handshake()) lsu.acc_mem_totel_cycle_num += cycle_num - lsu.old_cycle_num;
        }

        void logToFile(bool append = false) {
            std::ofstream logfile;
            
            // 打开文件（追加或覆盖模式）
            logfile.open(file_name, append ? std::ios::app : std::ios::out);
            
            if (!logfile.is_open()) {
                std::cerr << "Error: Failed to open log file: " << file_name << std::endl;
                return;
            }

            double icache_hit_rate = cal_div(ifu.icache.hit_num, ifu.icache.req_num);
            double icache_miss_rate = cal_div(ifu.icache.miss_num, ifu.icache.req_num);
            double icache_miss_penalty = cal_div(ifu.icache.totel_miss_penalty, ifu.icache.miss_num);

            logfile << "=== PerfCounter Log ================================\n";
            logfile << std::left
                    << "\n-- CPU ---------------------------\n"
                    << std::setw(24) << "Cycles:" << cycle_num << "\n"
                    << std::setw(24) << "IPC:" << cal_div(inst_num, cycle_num) << "\n"
                    << "\n-- IFU ---------------------------\n"
                    << std::setw(24) << "Fetch Inst Num:" << ifu.fetch_inst_num << "\n"
                    << std::setw(24) << "Average Fetch Cycles:" << cal_div(ifu.fetch_totel_cycle_num, ifu.fetch_inst_num) << "\n"
                    << "\n-- ICACHE ------------------------\n"
                    << std::setw(24) << "Request Num:" << ifu.icache.req_num << "\n"
                    << std::setw(24) << "Hit Rate:" << icache_hit_rate * 100 << "%\n"
                    << std::setw(24) << "Miss Rate:" << icache_miss_rate * 100 << "%\n"
                    << std::setw(24) << "Miss Penalty:" << icache_miss_penalty << "\n"
                    << std::setw(24) << "AMAT:" << icache_miss_rate * icache_miss_penalty << "\n"
                    << "\n-- BPU ---------------------------\n"
                    << std::setw(24) << "Miss Rate:" << cal_div(exu.flush_cycles, exu.control_inst_num) * 100 << "%\n"
                    << "\n-- IDU ---------------------------\n"
                    << std::setw(24) << "Raw Stall Cycles:" << idu.raw_stall_cycles << "\n"
                    << std::setw(24) << "J-type Inst Num:"<< std::setw(15)  << idu.j_inst_num    
                                     << cal_div(idu.j_inst_num, inst_num) * 100 << "%"
                                     << "\n"
                    << std::setw(24) << "Branch Inst Num:" << std::setw(15) << idu.br_inst_num   
                                     << cal_div(idu.br_inst_num, inst_num) * 100   << "%"
                                     << "\n"
                    << std::setw(24) << "Load Inst Num:" << std::setw(15)   << idu.ld_inst_num   
                                     << cal_div(idu.ld_inst_num, inst_num) * 100   << "%"
                                     << "\n"
                    << std::setw(24) << "Store Inst Num:" << std::setw(15)  << idu.st_inst_num   
                                     << cal_div(idu.st_inst_num, inst_num) * 100   << "%"
                                     << "\n"
                    << std::setw(24) << "ALU Inst Num:" << std::setw(15)    << idu.alu_inst_num  
                                     << cal_div(idu.alu_inst_num, inst_num) * 100  << "%"
                                     << "\n"
                    << std::setw(24) << "CSR Inst Num:" << std::setw(15)    << idu.csr_inst_num  
                                     << cal_div(idu.csr_inst_num, inst_num) * 100  << "%"
                                     << "\n"
                    << std::setw(24) << "Trap Inst Num:" << std::setw(15)   << idu.trap_inst_num 
                                     << cal_div(idu.trap_inst_num, inst_num) * 100 << "%"
                                     << "\n"
                    << "\n-- EXU ---------------------------\n"
                    << std::setw(24) << "Complete Inst Num:" << exu.complete_num << "\n"
                    << std::setw(24) << "Control Inst Num:" << exu.control_inst_num  << "\n"
                    << std::setw(24) << "Flush Inst Num:" << exu.flush_cycles << "\n"
                    << std::setw(24) << "Bubbles:" << exu.bubbles << "\n"
                    << "\n-- LSU ---------------------------\n"
                    << std::setw(24) << "Fetch Data Num:" << lsu.fetch_data_num << "\n"
                    << std::setw(24) << "Average Mem Latency:" << cal_div(lsu.acc_mem_totel_cycle_num, idu.ld_inst_num + idu.st_inst_num) << "\n"
                    << "\n===================================================\n";

            logfile.close();
        }

        #endif
};

#endif