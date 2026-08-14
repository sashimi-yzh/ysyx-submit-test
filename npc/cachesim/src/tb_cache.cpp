#include "ref_cache.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <utility>

class CacheTester {
private:
    RefCache*   ref_;
    std::vector<uint32_t> trace_;
    
    uint64_t    dut_misses_;
    uint64_t    dut_accesses_;
    uint64_t    sim_time_;
    
public:
    CacheTester() : ref_(nullptr),
                    dut_misses_(0),
                    dut_accesses_(0),
                    sim_time_(0) {
    }
    
    ~CacheTester() {
        delete ref_;
    }

    // 加载二进制格式的PC trace
    bool loadTraceBinary(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open binary trace file: " 
                      << filename << std::endl;
            return false;
        }
        
        file.seekg(0, std::ios::end);
        size_t file_size = file.tellg();
        file.seekg(0, std::ios::beg);
        
        if (file_size % sizeof(uint32_t) != 0) {
            std::cerr << "Error: Binary file size is not multiple of 4 bytes" 
                      << std::endl;
            return false;
        }
        
        size_t num_pcs = file_size / sizeof(uint32_t);
        trace_.resize(num_pcs);
        
        if (!file.read(reinterpret_cast<char*>(trace_.data()), file_size)) {
            std::cerr << "Error: Failed to read binary trace file" << std::endl;
            return false;
        }
        
        file.close();
        std::cout << "Loaded " << num_pcs << " PC addresses from binary file" 
                  << std::endl;
        
        if (num_pcs > 0) {
            std::cout << "First 5 PCs: ";
            for (size_t i = 0; i < std::min(num_pcs, size_t(5)); i++) {
                std::cout << "0x" << std::hex << std::setw(8) 
                          << std::setfill('0') << trace_[i] << " ";
            }
            std::cout << std::dec << std::endl;
        }
        
        return true;
    }
    
    // 生成测试trace（用于调试）
    void generateTestTrace() {
        trace_.push_back(0x00000000);
        trace_.push_back(0x00000100);
        trace_.push_back(0x00000200);
        trace_.push_back(0x00000300);
        trace_.push_back(0x00000000);
        trace_.push_back(0x00000400);
        trace_.push_back(0x00000100);
        trace_.push_back(0x00000040);
        trace_.push_back(0x00000040);
        
        std::cout << "Generated test trace with " << trace_.size() 
                  << " addresses" << std::endl;
    }
    
    // 测试单个配置
    void testConfig(const RefCache::Config& config, const std::string& config_name) {
        delete ref_;
        ref_ = new RefCache(config);
        ref_->reset();
        ref_->processTrace(trace_);
        
        std::cout << "Config: " << config_name << std::endl;
        std::cout << "  Block Size: " << config.BLOCK_SIZE << "B, "
                  << "Sets: " << config.NUM_SETS << ", "
                  << "Ways: " << config.WAYS << std::endl;
        std::cout << "  Accesses: " << ref_->getTotal() << std::endl;
        std::cout << "  Hits: " << ref_->getHits() << std::endl;
        std::cout << "  Misses: " << ref_->getMisses() << std::endl;
        std::cout << "  Hit Rate: " << std::fixed << std::setprecision(3) 
                  << ref_->getHitRate() << "%" << std::endl;
        std::cout << std::endl;
    }
    
    // 遍历所有参数组合（cache大小固定为1KB）
    void testAllConfigurations() {
        const uint32_t CACHE_SIZE = 64;  // 1KB
        
        // 参数范围
        std::vector<uint32_t> block_sizes = {8, 16};
        std::vector<uint32_t> ways = {1, 2, 4, 8};  // 包括直接映射、2路、4路、8路、16路
        
        std::cout << "\n=== Testing All Cache Configurations (1KB Cache) ===" << std::endl;
        std::cout << "Trace size: " << trace_.size() << " addresses\n" << std::endl;
        
        // 存储结果用于比较
        std::map<std::pair<uint32_t, uint32_t>, double> results;
        
        for (uint32_t block_size : block_sizes) {
            uint32_t num_blocks = CACHE_SIZE / block_size;
            
            for (uint32_t way : ways) {
                // 检查配置是否有效：ways必须能整除num_blocks
                if (num_blocks % way != 0) continue;
                
                uint32_t num_sets = num_blocks / way;
                
                // 只测试合理范围的配置（sets >= 1）
                if (num_sets < 1) continue;
                
                RefCache::Config config(block_size, num_blocks, way);
                
                std::string config_name = "B" + std::to_string(block_size) + 
                                         "_S" + std::to_string(num_sets) + 
                                         "_W" + std::to_string(way);
                
                testConfig(config, config_name);
                
                // 保存结果用于汇总
                results[{block_size, way}] = ref_->getHitRate();
            }
        }
        
        // 打印汇总表格
        printSummary(results);
    }
    
    // 打印汇总表格
    void printSummary(const std::map<std::pair<uint32_t, uint32_t>, double>& results) {
        std::cout << "\n=== Performance Summary ===" << std::endl;
        std::cout << "Hit Rate (%)\n" << std::endl;
        std::cout << "Block\\Ways";
        for (uint32_t w : {1, 2, 4, 8, 16}) {
            std::cout << std::setw(8) << std::setfill(' ') << w << "W";
        }
        std::cout << std::endl;
        std::cout << std::string(55, '-') << std::endl;
        
        for (uint32_t block_size : {4, 8, 16}) {
            std::cout << std::setw(9) << block_size << "B";
            for (uint32_t way : {1, 2, 4, 8, 16}) {
                auto it = results.find({block_size, way});
                if (it != results.end()) {
                    std::cout << std::setw(9) << std::fixed << std::setprecision(2) 
                              << it->second;
                } else {
                    std::cout << std::setw(10) << "-";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    // 运行单个配置测试（兼容原有接口）
    void run(const std::string& trace_file = "", bool test_all = false) {
        if (!trace_file.empty()) {
            if (!loadTraceBinary(trace_file)) {
                std::cout << "fail to load trace_file\n";
                return;
            }
        } else {
            generateTestTrace();
        }
        
        if (test_all) {
            testAllConfigurations();
        } else {
            // 使用默认配置
            RefCache::Config default_config;
            testConfig(default_config, "Default (16B, 4 sets, 4-way)");
        }
    }
};

int main(int argc, char** argv) {
    CacheTester tester;
    
    std::string trace_file = (argc > 1) ? argv[1] : "";
    bool test_all = (argc > 2 && std::string(argv[2]) == "--all");
    
    if (test_all) {
        std::cout << "Running all configuration tests..." << std::endl;
    }
    
    tester.run(trace_file, test_all);
    
    return 0;
}