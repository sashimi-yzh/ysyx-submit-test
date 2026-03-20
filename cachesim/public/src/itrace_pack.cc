#include "../include/itrace_pack.h"
#include <assert.h>
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

#define EXTERN_C extern "C"

#define ONE_PC_STEP 4

struct pc_record {
  uint32_t pc = 0;
  // count of consequtive occurrences
  // 0 means [pc]
  // 1 means [pc, pc + 1]
  // etc.
  uint8_t count = 0;
  // TODO:
  // if count reaches 255, split into multiple records
};

struct PackHeader {
  size_t size = 0;
  size_t nRecords = 0;
};

struct itrace_pack_imp {
  bool isCreate = false;
  PackHeader header;
  FILE *fp;
  pc_record current;
};

#define ASSERT_READ_ONE(n)                                                     \
  do {                                                                         \
    auto _n = fread((n), sizeof(*(n)), 1, pack->fp);                           \
    assert(_n == 1 && "itrace_pack: file read error");                         \
  } while (0)
#define ASSERT_WRITE_ONE(n)                                                    \
  do {                                                                         \
    auto _n = fwrite((n), sizeof(*(n)), 1, pack->fp);                          \
    assert(_n == 1 && "itrace_pack: file write error");                        \
  } while (0)

EXTERN_C itrace_pack_t itrace_pack_create(const char *filename) {
  itrace_pack_t pack = new itrace_pack_imp;
  pack->fp = fopen(filename, "wb");
  assert(pack->fp != nullptr);
  // skip header for now write dummy now
  ASSERT_WRITE_ONE(&pack->header);
  pack->isCreate = true;
  return pack;
}
static void load_one_record(itrace_pack_t pack) {
  assert(!pack->isCreate);
  ASSERT_READ_ONE(&pack->current.pc);
  ASSERT_READ_ONE(&pack->current.count);
}
static void save_one_record(itrace_pack_t pack) {
  assert(pack->isCreate);
  ASSERT_WRITE_ONE(&pack->current.pc);
  ASSERT_WRITE_ONE(&pack->current.count);
  pack->header.nRecords++;
}
static void init_from_file(itrace_pack_t pack) {
  ASSERT_READ_ONE(&pack->header);
  // load the first record
  if (pack->header.nRecords > 0) {
    load_one_record(pack);
  }
}
EXTERN_C itrace_pack_t itrace_pack_openfp(FILE *fp) {
  assert(fp != nullptr);
  itrace_pack_t pack = new itrace_pack_imp;
  pack->fp = fp;
  init_from_file(pack);
  return pack;
}
EXTERN_C itrace_pack_t itrace_pack_open(const char *filename) {
  return itrace_pack_openfp(fopen(filename, "rb"));
}
EXTERN_C void itrace_pack_close(itrace_pack_t pack) {
  if (pack->isCreate) {
    if (pack->current.pc != 0)
      save_one_record(pack);
    // write header
    printf("itrace_pack: saved %zu records, total pc record %zu\n",
           pack->header.nRecords, pack->header.size);
    fseek(pack->fp, 0, SEEK_SET);
    ASSERT_WRITE_ONE(&pack->header);
  }
  fclose(pack->fp);
  delete pack;
}
EXTERN_C size_t itrace_pack_size(itrace_pack_t pack) {
  return pack->header.size;
}
EXTERN_C size_t itrace_pack_nrecords(itrace_pack_t pack) {
  return pack->header.nRecords;
}
EXTERN_C void itrace_pack_add(itrace_pack_t pack, uint32_t pc) {
  if (pack->current.pc + pack->current.count + ONE_PC_STEP == pc) {
    if (pack->current.count == 0xff) {
      assert(false && "itrace_pack_add: pc_record count overflow unhandled");
    }
    pack->current.count += 1;
  } else {
    // printf("consecutive pc broken: prev=%08x count=%u new=%08x\n",
    // pack->current.pc, pack->current.count, pc);
    if (pack->current.pc != 0)
      save_one_record(pack);
    pack->current.pc = pc;
    pack->current.count = 0;
  }
  pack->header.size += 1;
}
EXTERN_C uint32_t itrace_pack_pickone(itrace_pack_t pack) {
  if (pack->header.size == 0) {
    return 0;
  }
  uint32_t pc = pack->current.pc + pack->current.count * ONE_PC_STEP;
  if (pack->current.count == 0) {
    if (pack->header.size > 1) {
      load_one_record(pack);
    }
  } else {
    pack->current.count -= 1;
  }
  pack->header.size -= 1;
  return pc;
}
