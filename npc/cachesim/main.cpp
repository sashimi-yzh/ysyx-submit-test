#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo)                                                        \
  (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog

typedef unsigned word_t;
typedef unsigned vaddr_t;

typedef struct {
  bool valid;
  int cnt;
  word_t tag;
} cache_block;

vector<vector<cache_block>> icache;
int tag_right_range;
int index_left_range;
int index_right_range;
int fetch_success = 0;
int total_fetch = 0;

cache_block *get_cache_block(vaddr_t addr) {
  word_t tag = BITS(addr, 31, tag_right_range);
  word_t index = BITS(addr, index_left_range, index_right_range);
  for (auto &tmp : icache[index]) {
    if (tmp.valid && tmp.tag == tag) {
      return &tmp;
    }
  }
  return nullptr;
}

void cache_fetch(vaddr_t addr) {
  total_fetch++;
  if (BITS(addr, 31, 24) == 0x0f) {
    return;
  }

  word_t tag = BITS(addr, 31, tag_right_range);
  word_t index = BITS(addr, index_left_range, index_right_range);
  bool success = false;
  for (auto &tmp : icache[index]) {
    if (tmp.valid) {
      if (tmp.tag == tag) {
        success = true;
        tmp.cnt = 0;
      } else {
        tmp.cnt++;
      }
    }
  }
  if (success) {
    fetch_success++;
    return;
  }
  auto &tmp = icache[index];
  int replace = 0;
  for (int i = 0; i < tmp.size(); i++) {
    if (!tmp[i].valid) {
      tmp[i].valid = 1;
      tmp[i].tag = tag;
      tmp[i].cnt = 0;
      return;
    } else {
      if (tmp[i].cnt > tmp[replace].cnt) {
        replace = i;
      }
    }
  }

  icache[index][replace].valid = 1;
  icache[index][replace].tag = tag;
  icache[index][replace].cnt = 0;
}

int main(int argc, char **argv) {
  map<string, pair<string, int>> options;
  options["size"] = {"set cache block size", 16};
  options["len"] = {"set cache block data length", 4};
  options["group"] = {
      "set cache block group size, should be factor of cache size", 16};
  options["mem"] = {"set memory sim mode", 0};
  stringstream help_info;
  help_info << "Usage:\n"
            << argv[0] << " [options] file\n"
            << "Options:\n";
  for (auto &[k, v] : options) {
    help_info << "\t--" << k << "\t\t" << v.first << "\n";
  }

  string filename;
  int index = 1;
  while (index < argc) {
    string option = argv[index++];
    if (option.substr(0, 2) == "--") {
      option = option.substr(2);
      if (options.find(option) != options.end() && index < argc) {
        options[option].second = stoi(argv[index++]);
      } else {
        cout << help_info.str() << endl;
        return -1;
      }
    } else {
      if (filename.empty()) {
        filename = option;
      } else {
        cout << help_info.str() << endl;
        return -1;
      }
    }
  }
  ifstream file(filename, ios::binary);
  if (!file.is_open()) {
    cout << help_info.str() << endl;
    return -1;
  }
  int cache_size = options["size"].second;
  int group_size = options["group"].second;
  icache = vector(group_size, vector<cache_block>(cache_size / group_size));
  index_right_range = log2(options["len"].second);
  index_left_range = index_right_range + log2(group_size) - 1;
  tag_right_range = index_left_range + 1;
  cout << "cache size:" << cache_size << endl;
  cout << "group size:" << group_size << endl;
  cout << "tag range:[31," << tag_right_range << "]" << endl;
  cout << "index range:[" << index_left_range << "," << index_right_range << "]"
       << endl;

  bool mem_mode = options["mem"].second;
  while (!file.eof()) {
    if (mem_mode) {
      int read = 0;
      vaddr_t addr;
      file.read((char *)&read, 1);
      file.read((char *)&addr, 4);

      if (read) {
        cache_fetch(addr);
      } else {
        if (auto tmp = get_cache_block(addr)) {
          tmp->valid = 0;
        }
      }
    } else {
      vaddr_t pc;
      int follow;
      file.read((char *)&pc, 4);
      file.read((char *)&follow, 4);
      while (follow-- >= 0) {
        cache_fetch(pc);
        pc += 4;
      }
    }
  }
  cout << "fetch_success:" << fetch_success << endl;
  cout << "total fetch:" << total_fetch << endl;
  return 0;
}