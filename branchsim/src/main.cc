#include "../public/btrace_pack.h"
#include <bit>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <functional>

uint32_t GetBTypeIMMFrom(uint32_t code) {
  uint32_t imm12 = (code >> 31) & 1;
  uint32_t imm11 = (code >> 7) & 1;
  uint32_t imm10to5 = (code >> 25) & 0x3f;
  uint32_t imm4to1 = (code >> 8) & 0xf;
  return (imm12 << 12) | (imm11 << 11) | (imm10to5 << 5) | (imm4to1 << 1);
}
uint32_t GetFunc3tFrom(uint32_t code) { return (code >> 12) & 0x7; }

bool isJAL(uint32_t code) { return (code & 0x7f) == 0x6f; }

struct BTBEntry {
  uint32_t tag;
  uint32_t target;
  bool isJAL;
  bool valid;
};

struct history_entry_t {
  bool valid = false;
  bool isJAL = false;
  uint32_t target = 0;
};
class BTB {
public:
  std::vector<BTBEntry> entries;
  const uint32_t N_BITS_INDEX;
  const uint32_t N_BITS_TAG =
      32 - 2 - N_BITS_INDEX; // 2 bits for word alignment
  BTB(size_t size) : entries(size), N_BITS_INDEX(std::countr_zero(size) + 1) {
    assert(std::has_single_bit(size) && "BTB size must be a power of 2");
  }

  uint32_t get_index(uint32_t pc) { return (pc >> 2) % entries.size(); }
  uint32_t get_tag(uint32_t pc) { return pc >> (2 + N_BITS_INDEX); }

  bool hit(uint32_t pc, uint32_t &target, bool &isJAL) {
    auto index = get_index(pc);
    auto tag = get_tag(pc);
    auto &entry = entries[index];
    if (entry.valid && entry.tag == tag) {
      target = entry.target;
      isJAL = entry.isJAL;
      return true;
    }
    return false;
  }

  history_entry_t query(uint32_t pc) {
    history_entry_t res;
    res.valid = hit(pc, res.target, res.isJAL);
    return res;
  }

  void update(uint32_t pc, uint32_t target, bool isJAL) {
    auto index = get_index(pc);
    auto tag = get_tag(pc);
    entries[index] = {tag, target, isJAL, true};
  }
};

using algo_t = std::function<uint32_t(uint32_t pc, history_entry_t entry)>;

// uint32_t algo_always_take(uint32_t, history_entry_t) { return true; }
uint32_t algo_always_not_take(uint32_t pc, history_entry_t) { return pc + 4; }
uint32_t algo_BTFN(uint32_t pc, history_entry_t entry) {
  // BTFN: Backward Taken, Forward Not taken
  if (entry.valid && (entry.isJAL || entry.target < pc)) {
    return entry.target;
  }
  return pc + 4;
}

void test_algo(algo_t algo, size_t btb_size = 4) {
  btrace_pack_t pack = btrace_pack_open("../nemu/btrace_pack.bin");
  btrace_record_t record;

  size_t total = 0, wrong = 0;

  BTB btb(btb_size);

  while (true) {
    if (btrace_pack_pick(pack, &record) == 0)
      break;
    // uint32_t code = record.code;
    // uint32_t imm = GetBTypeIMMFrom(code);
    // uint32_t func3t = GetFunc3tFrom(code);
    //   bool ans_taken = record.nxt_pc != (record.pc + 4);
    //   bool pred_taken = algo(record.pc, func3t, imm);

    auto ans = record.nxt_pc;
    auto pred = algo(record.pc, btb.query(record.pc));

    if (ans != pred) {
      wrong++;
      // printf(
      //     "Wrong prediction at pc: %08x, func3t: %d, imm: %d, code: %08x,
      //     ans: %d nxt_pc: %08x\n", record.pc, func3t, imm, code, ans_taken,
      //     record.nxt_pc);
    }
    total++;
		// Update BTB
		if(record.nxt_pc != record.pc + 4) {
			btb.update(record.pc, record.nxt_pc, isJAL(record.code));
		}
  }
  btrace_pack_close(pack);
  size_t correct = total - wrong;
  printf("Total: %zu, Wrong: %zu, Correct: %zu, Accuracy: %.2f%%\n", total,
         wrong, correct, (double)correct / total * 100);
}

int main() {
  printf("Testing always not take algorithm:\n");
  test_algo(algo_always_not_take);
	
	size_t btb_sizes[] = {2, 4, 8, 16};
	for(size_t size : btb_sizes) {
		printf("Testing BTFN algorithm: BTB size = %zu:\n", size);
		test_algo(algo_BTFN, size);
	}

  return 0;
}
