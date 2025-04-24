#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

//#define HAS_VICTIM_CACHE

#define OFFSET_BITS 2
#define WORD_IDX_BITS 2
#define IDX_BITS 2
#define NR_WAY 1
#define TAG_BITS (32 - OFFSET_BITS - WORD_IDX_BITS - IDX_BITS)

#define NR_SET (1 << IDX_BITS)
#define NR_WORD_IN_LINE (1 << WORD_IDX_BITS)
#define CORE_MHZ 1143.066
#define SDRAM_READ_CYCLE (6 + 2 * (NR_WORD_IN_LINE - 1))
#define FILL_LINE_LATENCY (int)(SDRAM_READ_CYCLE * CORE_MHZ / 100)

typedef union {
  struct {
    uint32_t offset  : OFFSET_BITS;
#if WORD_IDX_BITS != 0
    uint32_t wordIdx : WORD_IDX_BITS;
#endif
#if IDX_BITS != 0
    uint32_t idx     : IDX_BITS;
#endif
    uint32_t tag     : TAG_BITS;
  };
  uint32_t addr;
} addr_t;

typedef struct {
  uint32_t tag;
  bool valid;
  bool used;
  bool dirty;
} meta_t;

static meta_t meta[NR_SET][NR_WAY];
static uint64_t nr_hit, nr_miss, nr_writeback;
#ifdef HAS_VICTIM_CACHE
static meta_t victim_cache;
static uint64_t nr_victim_hit;
#endif

#define FLASH_BASE 0x30000000
#define FLASH_SIZE 0x1000000

static bool is_cachable(uint32_t addr) {
  bool in_flash = (FLASH_BASE <= addr && addr < FLASH_BASE + FLASH_SIZE);
  return (addr >= 0x80000000) || in_flash;
}

static void access_cache(uint32_t addr, bool is_write) {
  if (!is_cachable(addr)) return;

  addr_t a = (addr_t){ .addr = addr };
#if IDX_BITS == 0
  int idx = 0;
#else
  int idx = a.idx;
#endif
  meta_t *m = &meta[idx][0];
  int i = 0, victim = 0;
  for (; i < NR_WAY; i ++) {
#if NR_WAY > 1
    if (m[i].used == false) victim = i;
#endif
    if (m[i].valid && (m[i].tag == a.tag)) break;
  }
  bool hit = (i < NR_WAY);
  if (hit) {
    nr_hit ++;
  } else {
#ifdef HAS_VICTIM_CACHE
    // check victim cache
    if (victim_cache.valid && victim_cache.tag == a.tag) {
      nr_hit ++;
      nr_victim_hit ++;
      victim_cache.dirty = is_write;

      //i = victim;
      //meta_t tmp;
      //tmp = m[i];
      //m[i] = victim_cache;
      //victim_cache = tmp;
      return;
    }
    if (victim_cache.dirty) nr_writeback ++;
    i = victim;
    victim_cache.tag = m[i].tag;
    victim_cache.dirty = m[i].dirty;
    victim_cache.valid = true;
#endif

    nr_miss ++;
    i = victim;
    if (m[i].dirty) nr_writeback ++;
    m[i].tag = a.tag;
    m[i].valid = true;
  }
  m[i].dirty = is_write;
  
#if NR_WAY > 1
  m[i].used = true;
  bool update_used_bit = true;
  for (int j = 0; j < NR_WAY; j ++) {
    update_used_bit &= m[j].used;
  }
  if (update_used_bit) {
    for (int j = 0; j < NR_WAY; j ++) {
      m[j].used = false;
    }
    m[i].used = true;
  }
#endif
  //printf("0x%x %s\n", addr, (hit ? "hit" : "miss"));
}

static void replay_itrace(uint32_t pc, int nr_inst) {
  for (int i = 0; i < nr_inst; i ++) {
    access_cache(pc + i * 4, false);
  }
}

static void load_itrace(const char *file) {
  FILE *fp = fopen(file, "r");
  assert(fp);
  uint32_t pc;
  short nr_inst;
  do {
    int ret1 = fread(&pc, sizeof(pc), 1, fp);
    int ret2 = fread(&nr_inst, sizeof(nr_inst), 1, fp);
    if (ret1 == 1 && ret2 == 1) { replay_itrace(pc, nr_inst); }
    else break;
  } while (1);
  fclose(fp);
}

static void load_mtrace(const char *file) {
  FILE *fp = fopen(file, "r");
  assert(fp);
  uint32_t addr;
  bool is_write;
  do {
    int ret1 = fread(&addr, sizeof(addr), 1, fp);
    int ret2 = fread(&is_write, sizeof(is_write), 1, fp);
    if (ret1 == 1 && ret2 == 1) { access_cache(addr, is_write); }
    else break;
  } while (1);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  assert(argc >= 3);
  if (strcmp(argv[1], "icache") == 0) {
    load_itrace(argv[2]);
  } else if (strcmp(argv[1], "dcache") == 0) {
    load_mtrace(argv[2]);
  } else { assert(0); }
  uint64_t access = nr_hit + nr_miss;
  printf("%s: hit rate = %ld/%ld = %lf, # writeback = %ld, miss cycles = %ld\n", argv[1], nr_hit, access, (double)nr_hit / access, nr_writeback, nr_miss * FILL_LINE_LATENCY);
#ifdef HAS_VICTIM_CACHE
  printf("%s: victim cache hit time = %ld\n", argv[1], nr_victim_hit);
#endif
  return 0;
}
