#include "branch_sim.h"
#include <fstream>
#include <vector>
#include <cstring>

// 从二进制文件加载 BranchRecord
bool loadBranchTrace(const std::string& filename, 
                     std::vector<BranchRecord>& trace) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << std::endl;
        return false;
    }

    // 每记录 9 字节：1(flags) + 4(PC) + 4(target)
    constexpr size_t REC_SIZE = 9;
    file.seekg(0, std::ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (file_size % REC_SIZE != 0) {
        std::cerr << "Error: File size is not a multiple of " << REC_SIZE << " bytes\n";
        return false;
    }

    size_t num_records = file_size / REC_SIZE;
    trace.resize(num_records);

    for (size_t i = 0; i < num_records; ++i) {
        uint8_t flags;
        uint32_t pc, target;
        if (!file.read(reinterpret_cast<char*>(&flags), sizeof(flags)) ||
            !file.read(reinterpret_cast<char*>(&pc), sizeof(pc)) ||
            !file.read(reinterpret_cast<char*>(&target), sizeof(target))) {
            std::cerr << "Error reading record " << i << std::endl;
            return false;
        }
        trace[i].pc = pc;
        trace[i].target_pc = target;
        trace[i].taken = (flags & 0x01) != 0;
    }

    file.close();
    std::cout << "Loaded " << num_records << " branch records\n";
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <branch_trace.bin>\n";
        return 1;
    }

    std::vector<BranchRecord> trace;
    if (!loadBranchTrace(argv[1], trace)) {
        return 1;
    }

    BranchSimulator sim;
    sim.processTrace(trace);
    sim.printReport();

    return 0;
}