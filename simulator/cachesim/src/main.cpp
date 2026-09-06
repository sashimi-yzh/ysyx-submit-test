// main.cpp
#include "Cache.h"
#include "Cfgparser.h"
#include "Itraceparser.h"
#include "Mtraceparser.h"

#include <cstdint>
#include <exception>
#include <iostream>
#include <iomanip>
#include <string>

DEFINE_CONFIG_BLOCK_TYPE(icache);
DEFINE_CONFIG_BLOCK_TYPE(dcache);

int icache_sim(cfglang::Config<CFGLANG_TYPE(icache)> *cfg) {
    try {
        cachesim::CacheConfig config;
        config.cache_type = cachesim::CacheConfig::CacheTypeEnum::DirectMapped;
        config.block_offset_bits = cfg->get<uint32_t>("offset-len");
        config.set_index_bits = cfg->get<uint32_t>("index-len");

        std::string trace_file = cfg->get("log");
        
        cachesim::Cache cache(config);
        cachesim::ItraceParser parser(trace_file);
        
        if (!parser.is_open()) {
            std::cerr << "Error: Cannot open file: " << trace_file << std::endl;
            return 1;
        }

        cache.print_config();
        
        std::cout << "Processing " << trace_file << "..." << std::endl;
        
        uint64_t instruction_count = 0;
        parser.parse([&cache, &instruction_count](uint32_t pc) {
            cache.access(pc);
            ++instruction_count;
            
            // 每处理 10000 条指令输出一次进度（可选）
            if (instruction_count % 10000 == 0) {
                std::cout << "  Processed " << instruction_count << " instructions..." << std::endl;
            }
        });
        
        std::cout << "\n=== Cache Simulation Results ===" << std::endl;
        std::cout << "Total instructions: " << instruction_count << std::endl;
        std::cout << "Cache hits: " << cache.get_hit_time() << std::endl;
        std::cout << "Cache misses: " << cache.get_miss_time() << std::endl;
        std::cout << "Hit rate: " << std::fixed << std::setprecision(2)
                  << (1.0 - cache.get_miss_rate()) * 100.0 << "%" << std::endl;
        std::cout << "Miss rate: " << std::fixed << std::setprecision(2)
                  << cache.get_miss_rate() * 100.0 << "%" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

int dcache_sim(cfglang::Config<CFGLANG_TYPE(dcache)> *cfg) {
    try {
        cachesim::CacheConfig config;
        config.cache_type = cachesim::CacheConfig::CacheTypeEnum::DirectMapped;
        config.block_offset_bits = cfg->get<uint32_t>("offset-len");
        config.set_index_bits = cfg->get<uint32_t>("index-len");

        std::string trace_file = cfg->get("log");
        
        cachesim::Cache cache(config);
        cachesim::MtraceParser parser(trace_file);
        
        if (!parser.is_open()) {
            std::cerr << "Error: Cannot open file: " << trace_file << std::endl;
            return 1;
        }

        cache.print_config();
        
        std::cout << "Processing " << trace_file << "..." << std::endl;
        
        uint64_t dcache_count = 0;

        parser.parse([&cache, &dcache_count](bool is_write, uint32_t addr) {
            bool in_sram = (addr >= 0x0f000000) && (addr <= 0x0fffffff);
            if(!in_sram) {
                if(is_write) {
                    cache.reset(addr);
                } else {
                    cache.access(addr);
                }
                ++ dcache_count;

                if(dcache_count % 10000 == 0) {
                    std::cout << "  Processed " << dcache_count << " dcache access" << std::endl;
                }
            } else {
                printf("sram overlook\n");
            }
        });
        
        std::cout << "\n=== Data Cache Simulation Results ===" << std::endl;
        std::cout << "Total memory accesses: " << dcache_count << std::endl;
        std::cout << "Cache hits: " << cache.get_hit_time() << std::endl;
        std::cout << "Cache misses: " << cache.get_miss_time() << std::endl;
        std::cout << "Cache resets: " << cache.get_reset_time() << std::endl;
        std::cout << "Hit rate: " << std::fixed << std::setprecision(2)
                  << (1.0 - cache.get_miss_rate()) * 100.0 << "%" << std::endl;
        std::cout << "Miss rate: " << std::fixed << std::setprecision(2)
                  << cache.get_miss_rate() * 100.0 << "%" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    std::string cfg_file = "./cfg.txt";
    
    // 简单的命令行参数解析
    if (argc < 2) {
        std::cout << "[Usage] cachesim dcache/icache {option:log}";
        return 0;
    }
    std::string sim_type = argv[1];

    if (argc > 2) {
        cfg_file = argv[2];        
    }

    if(sim_type == "icache") {
        cfglang::Config<CFGLANG_TYPE(icache)> *icache_cfg = \
            new cfglang::Config<CFGLANG_TYPE(icache)>(cfg_file);
        return icache_sim(icache_cfg);
    } else if(sim_type == "dcache") {
        cfglang::Config<CFGLANG_TYPE(dcache)> *dcache_cfg = \
            new cfglang::Config<CFGLANG_TYPE(dcache)>(cfg_file);
        return dcache_sim(dcache_cfg);
    } else {
        std::cerr << "Error: Invalid simulation type '" << sim_type << "'" << std::endl;
        std::cout << "Usage: " << argv[0] << " <dcache|icache> [config_file]" << std::endl;
        std::cout << "  Valid types: dcache, icache" << std::endl;
        return 1;
    }
}