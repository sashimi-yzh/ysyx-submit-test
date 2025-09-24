#include <iostream>
#include <cmath>
#include <vector>
#include <getopt.h>
#include <fstream>

class ICACHE {
    private:
        std::vector<uint32_t> tag;
        std::vector<uint32_t> valid;

        int entry_num;
        int entry_size_width;

        struct {
            uint64_t inst_num = 0;
            uint64_t miss_num = 0;
            double penalty_time;
        } sta_data;

        double div(uint64_t a, uint64_t b) {
            return (double)a / (double)b;
        }

        double mul(uint64_t a, uint64_t b) {
            return (double)a * (double)b;
        }

    public:
        ICACHE(size_t _entry_num, size_t _entry_size, double _penalty_time) 
            : entry_num(_entry_num), tag(_entry_num, 0), valid(_entry_num, 0) {
            entry_size_width = static_cast<int>(log2(_entry_size));
            std::cout << "ICACHE initialized:   " << "Set Num: " << entry_num 
                      << ", Set Size: " << _entry_size/4 << std::endl;
            sta_data.penalty_time = _penalty_time;
        }
    
        void readAndUpdate(uint32_t addr) {
            sta_data.inst_num++;

            uint32_t index = (addr >> entry_size_width) % entry_num;
            uint32_t tag = (addr >> entry_size_width) / entry_num;

            if (valid[index] == 0 || this->tag[index] != tag) {
                this->tag[index] = tag;
                valid[index] = 1;
                sta_data.miss_num++;
            }
        }

        void print() {
            std::cout << "ICACHE Statistics:" << std::endl;
            std::cout << "Inst Num: " << sta_data.inst_num << std::endl;
            std::cout << "Miss Num: " << sta_data.miss_num << std::endl;
            std::cout << "Miss Rate: " 
                      << div(sta_data.miss_num, sta_data.inst_num) * 100 << "%" << std::endl;
            std::cout << "Totel Miss Time: " << mul(sta_data.penalty_time, sta_data.miss_num) << std::endl
            << std::endl;
        }
};

static char *log_file = NULL;
static int entry_num = 4;
static int entry_size = 16;
static double penalty_time = 30.0;

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
      {"log", required_argument, NULL, 'l'},
      {"entry_num", required_argument, NULL, 'n'},
      {"entry_size", required_argument, NULL, 's'},
      {"penalty_time", required_argument, NULL, 'p'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-l:n:s:p:", table, NULL)) != -1) {
    switch (o) {
    case 'l':
        log_file = optarg;
        break;
    case 'n':
        entry_num = atoi(optarg);
        break;
    case 's':
        entry_size = atoi(optarg)*4;
        break;
    case 'p':
        penalty_time = atof(optarg);
        break;
    default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);

        printf("\t-l,--log=FILE           access mem log\n");
        printf("\t-n,--entry_num=NUM      set the number of cache entries (default: %d)\n", entry_num);
        printf("\t-s,--entry_size=SIZE    set the size of each cache entry (default: %d)\n", entry_size);
        printf("\t-p,--penalty_time=TIME  set the penalty time for cache miss (default: %.2f)\n", penalty_time);
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
    parse_args(argc, argv);

    ICACHE icache(entry_num, entry_size, penalty_time);

    std::ifstream file(log_file, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << log_file << "\n";
        return 1;
    }

    while(!file.eof()) {
        uint32_t pc;
        file.read(reinterpret_cast<char*>(&pc), sizeof(pc));
        if (file.gcount() == sizeof(pc)) {
            icache.readAndUpdate(pc);
        }
    }

    file.close();

    icache.print();

    return 0;
}