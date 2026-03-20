#include <bit>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <itrace_pack.h>
#include <vector>

#include <thread>

#include <fstream>

uint32_t extractBits(uint32_t num, int high, int low) {
  assert(high >= low);
  assert(high < 32);
  assert(low >= 0);
  assert((high - low + 1) < 32);
  return (num >> low) & ((1u << (high - low + 1)) - 1);
}

class ICacheSim {
public:
  const size_t blockSize;
  const size_t blockNum;

  const uint32_t blockSizeWidth = std::countr_zero(blockSize);
  const uint32_t blockNumWidth = std::countr_zero(blockNum);
  const uint32_t tagWidth = 32 - blockSizeWidth - blockNumWidth;

  using addr_t = uint32_t;

  // store tag only
  std::vector<addr_t> blocks;
  std::vector<bool> valid;

  size_t totalMissCount = 0;
  size_t totalAccessCount = 0;

  size_t getBlockIndex(addr_t addr) {
    return extractBits(addr, blockSizeWidth + blockNumWidth - 1,
                       blockSizeWidth);
  }
  addr_t getTag(addr_t addr) {
    return extractBits(addr, 31, blockSizeWidth + blockNumWidth);
  }
  size_t getBlockOffset(addr_t addr) {
    return extractBits(addr, blockSizeWidth - 1, 0);
  }

  ICacheSim(size_t bSize, size_t bNum) : blockSize(bSize), blockNum(bNum) {
    blocks.resize(blockNum, 0);
    valid.resize(blockNum, false);
    printf("ICacheSim: blockSize=%zu, blockNum=%zu\n", blockSize, blockNum);
    assert(std::has_single_bit(blockSize));
    assert(std::has_single_bit(blockNum));
  }
  void access(addr_t addr) {
    totalAccessCount++;
    size_t bIndex = getBlockIndex(addr);
    addr_t tag = getTag(addr);
    if (!valid[bIndex] || blocks[bIndex] != tag) {
      // miss
      totalMissCount++;
      blocks[bIndex] = tag;
      valid[bIndex] = true;
    }
  }

  void dumpStats(double missPenalty) {
    std::string filename = "icache_stat_" + std::to_string(blockSize) + "_" +
                           std::to_string(blockNum) + ".txt";
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
      std::cerr << "Failed to open file: " << filename << std::endl;
      return;
    }
    ofs << "block_size: " << blockSize << "\n";
    ofs << "block_num: " << blockNum << "\n";
    ofs << "total_access: " << totalAccessCount << "\n";
    ofs << "total_miss: " << totalMissCount << "\n";

    double hitCount = totalAccessCount - totalMissCount;
		// Assume no use brust
    double totalMissTime = totalMissCount * missPenalty * blockSize / 4.0;

    ofs << "hit_rate: " << (hitCount / totalAccessCount * 100.0) << "\n";
    ofs << "total_miss_time: " << totalMissTime << " (based on " << missPenalty
        << " cycles per miss)\n";
    ofs.close();
    std::cout << "ICache simulation stats written to " << filename << std::endl;
  }
};

void sim(size_t blockSize, size_t blockNum) {
  auto fp = popen("bzip2 -dc ../nemu/itrace_pack.bin.bz2", "r");
  itrace_pack_t pack = itrace_pack_openfp(fp);
  assert(pack != NULL);

  ICacheSim icache(blockSize, blockNum);

  printf("Simulating ICache with %zu records...\n", itrace_pack_nrecords(pack));

  uint32_t pc = 0;
  do {
    pc = itrace_pack_pickone(pack);
    if (pc != 0) {
      // printf("%08x\n", pc);
      icache.access(pc);
    }
  } while (pc != 0);
  icache.dumpStats(24.7324);

  itrace_pack_close(pack);
}

int main() {
	struct parm {
		size_t blockSize;
		size_t blockNum;
	};

	std::vector<parm> parmlist;
	for(size_t bs = 4; bs <= 256; bs *= 2) {
		// 4 8 16 32 64 128 256
		for(size_t bn = 16; bn <= 512; bn *= 2) {
			// 16 32 64 128 256 512
			parmlist.push_back({bs, bn});
		}
	}
	// 6*7=42 combinations
	
	constexpr size_t numThreads = 14;
	constexpr size_t tasksPerThread = 3;

	std::thread threads[numThreads];

	for(size_t i = 0; i < numThreads; i++) {
		threads[i] = std::thread([i, &parmlist]() {
			for(size_t j = 0; j < tasksPerThread; j++) {
				size_t index = i * tasksPerThread + j;
				sim(parmlist[index].blockSize, parmlist[index].blockNum);
			}
		});
	}

	for(size_t i = 0; i < numThreads; i++) {
		threads[i].join();
	}

	return 0;


}
