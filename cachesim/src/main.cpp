#include <common.h>
#include <replace_strategy.h>
#include <fstream>
#include <iostream>
#include <cstdint>

// argc 是参数数量
// argv[0] 是程序名称
// argv[1] 是传入的 trace 文件路径
int main(int argc, char **argv) {
    // 检查参数
    if(argc != 6){
        std::cerr << "Usage: " << argv[0] << " <trace_file> <sets> <ways> <block_size> <replace_policy>" << std::endl;
        // std::cout<<argv[1]<<argv[2]<<argv[3]<<argv[4]<<argv[5]<<std::endl;
        std::cerr << "Example: ./cachesim trace.bin 4 8 4 FIFO" << std::endl;
        std::cerr << "You should first run the ysyxsoc.bin file with nemu to generate the itraceicache.log file. " << std::endl;
        return -1;
    }

    std::string filename = argv[1];
    int sets = atoi(argv[2]);
    int ways = atoi(argv[3]);
    int block_size = atoi(argv[4]);
    std::string policy = argv[5];

    if (sets <= 0 || ways <= 0 || block_size <= 0) {
        std::cerr << "Error: All parameters must be positive integers.\n";
        return -1;
    }

    // ?个缓存组，?路，一个块大小为?
    Cache cache(sets, ways, block_size); // sets ways block_size
    // 输出配置信息
    std::cout << "Running CacheSim with Configuration:\n";
    std::cout << "  Sets:        " << sets << "\n";
    std::cout << "  Ways:        " << ways << "\n";
    std::cout << "  Block Size:  " << block_size << "\n";
    std::cout << "  Policy:      " << policy << "\n";
    std::cout << "  Offset bits: " << cache.offBits() << "\n";
    std::cout << "  Index bits:  " << cache.idxBits() << "\n";
    std::cout << "  Tag bits:    " << cache.tagBits() << "\n";

    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        std::cerr << "Error opening trace file: " << filename << std::endl;
        return 0;
    }

    uint32_t start_pc;
    uint16_t run_length;
    while (in.read(reinterpret_cast<char*>(&start_pc), sizeof(start_pc)) && 
           in.read(reinterpret_cast<char*>(&run_length), sizeof(run_length))) {

        // 处理序列中的每个 PC
        for(uint16_t i = 0;i < run_length;i++){
            uint32_t pc = start_pc + i * 4;

            // 跳过 SRAM 区域 (与压缩时一致)
            if (pc >= 0x0f000000 && pc < 0x0fffffff) {
                continue;
            }

            // 执行缓存访问
            // index是第几个缓存组,tag是用于缓存组中找元素
            // printf("index is %x,tag is %x\n",cache.INDEX(pc),cache.TAG(pc));
            // printf("pc is %x\n",pc);
            
            if(policy == "fifo"){
                fifo_replace(&cache, cache.decode(pc), cache.TAG(pc));
            } else if(policy == "lru"){
                lru_replace(&cache, cache.decode(pc), cache.TAG(pc));
            } else {
                std::cerr << "Error: Unknown policy '" << policy << "'. Use 'fifo' or 'lru'.\n";
                return -1;
            }
        }
    }

    cache.statistic();
    if (!in.eof()) {
        std::cerr << "Warning: Trace file may be incomplete or corrupt" << std::endl;
    }
    in.close();
    return 0;
}

// replace_way      sets     ways    block_size      hit_ratio
//     fifo          16       1          4             70.8%
//     fifo           8       2          4             69.1692%
//     fifo          16       2          4             85.5906%
//     fifo           8       4          4             85.2670%
//     fifo           4       8          4             84.2216%
//     fifo          16       3          4             
//     fifo          16       4          4             96.3198%

//     lru           16       1          4             70.8073%
//     lru            8       2          4             69.0425%
//     lru           16       2          4             85.5766%
//     lru            8       4          4             85.4041%
//     lru            4       8          4             
//     lru           16       4          4             