#include <assert.h>
#include <stdio.h>

#include <memory/paddr.h>
#include <isa.h>
#include <difftest-def.h>
#include <memory/host.h>
#include <platform/platform.h>

static uint8_t pmem[NPC_PMEM_SIZE] = {};
static long img_size = 0;

static bool in_npc_pmem(uint32_t addr) {
  return addr >= NPC_PMEM_BASE && addr < NPC_PMEM_BASE + NPC_PMEM_SIZE;
}

void platform_log_memory() {
  Log("Memory: PMEM [0x%08x, 0x%08x]", NPC_PMEM_BASE, NPC_PMEM_BASE + NPC_PMEM_SIZE - 1);
}

void platform_init() {}
void platform_cleanup() {}
void platform_update() {}
void platform_set_external_idle(SimTop *top) { (void)top; }
uint32_t platform_reset_pc() { return NPC_RESET_PC_NPC; }

long platform_load_image(const char *img_file) {
  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  Assert(size > 0 && size <= NPC_PMEM_SIZE, "bad image size %ld", size);
  int ret = fread(pmem, size, 1, fp);
  Assert(ret == 1, "failed to read image '%s': size=%ld ret=%d", img_file, size, ret);
  fclose(fp);
  img_size = size;
  /*
  Log("The image is %s, size = %ld", img_file, size);
  */
  return size;
}

bool platform_read(paddr_t addr, int len, word_t *data) {
  if (len <= 0 || !in_npc_pmem(addr) || addr > NPC_PMEM_BASE + NPC_PMEM_SIZE - len) return false;
  *data = host_read(pmem + addr - NPC_PMEM_BASE, len);
  return true;
}

bool platform_write(paddr_t addr, int len, word_t data) {
  if (len <= 0 || !in_npc_pmem(addr) || addr > NPC_PMEM_BASE + NPC_PMEM_SIZE - len) return false;
  host_write(pmem + addr - NPC_PMEM_BASE, len, data);
  return true;
}

void platform_out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [0x%08x, 0x%08x] at pc = " FMT_WORD,
      addr, NPC_PMEM_BASE, NPC_PMEM_BASE + NPC_PMEM_SIZE - 1, cpu.pc);
}

static const char *platform_device_name(uint32_t addr) {
  if (addr >= 0x10000000u && addr <= 0x10000fffu) return "UART";
  return NULL;
}

#ifdef CONFIG_MTRACE
static const char *platform_memory_name(uint32_t addr) {
  return in_npc_pmem(addr) ? "PMEM" : NULL;
}
#endif

bool platform_in_comparable_mem(paddr_t addr) {
  return in_npc_pmem(addr);
}

void platform_trace_read(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
  const char *mem = platform_memory_name(addr);
  if ((MTRACE_COND) && mem != NULL) {
    mtrace_write(FMT_WORD " R %d " FMT_WORD " [%s]\n", addr, len, data, mem);
  }
#endif
  const char *name = platform_device_name(addr);
  if (name != NULL) {
    IFDEF(CONFIG_DTRACE, dtrace_write(FMT_WORD " R %d " FMT_WORD " [%s]\n", addr, len, data, name));
  }
}

void platform_trace_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
  const char *mem = platform_memory_name(addr);
  if ((MTRACE_COND) && mem != NULL) {
    mtrace_write(FMT_WORD " W %d " FMT_WORD " [%s]\n", addr, len, data, mem);
  }
#endif
  const char *name = platform_device_name(addr);
  if (name != NULL) {
    IFDEF(CONFIG_DTRACE, dtrace_write(FMT_WORD " W %d " FMT_WORD " [%s]\n", addr, len, data, name));
  }
}

void platform_difftest_memcpy(void (*ref_memcpy)(paddr_t, void *, size_t, bool), bool direction) {
  Assert(ref_memcpy != NULL,
      "platform_difftest_memcpy with null callback: direction=%d img_size=%ld",
      direction, img_size);
  Assert(direction == DIFFTEST_TO_DUT || direction == DIFFTEST_TO_REF,
      "platform_difftest_memcpy with bad direction: direction=%d img_size=%ld",
      direction, img_size);
  Assert(img_size >= 0 && img_size <= NPC_PMEM_SIZE,
      "platform_difftest_memcpy with bad image size: img_size=%ld capacity=%u",
      img_size, NPC_PMEM_SIZE);
  if (img_size > 0) ref_memcpy(NPC_PMEM_BASE, pmem, (size_t)img_size, direction);
}

void platform_enable_ref_paddr(void (*enable_ysyxsoc_paddr)(void)) { (void)enable_ysyxsoc_paddr; }

extern "C" int pmem_read(int raddr) {
  word_t data = 0;
  uint32_t aligned = (uint32_t)raddr & ~0x3u;
  if (!platform_read(aligned, 4, &data)) return 0;
  return (int)data;
}

extern "C" void pmem_write(int waddr, int wdata, unsigned char wmask) {
  uint32_t aligned = (uint32_t)waddr & ~0x3u;
  Assert((wmask & 0xf0u) == 0 && (wmask & 0x0fu) != 0,
      "DPI pmem_write with bad mask: waddr=0x%08x wdata=0x%08x wmask=0x%02x pc=" FMT_WORD,
      (uint32_t)waddr, (uint32_t)wdata, wmask, cpu.pc);
  Assert(in_npc_pmem(aligned) && aligned <= NPC_PMEM_BASE + NPC_PMEM_SIZE - 4,
      "DPI pmem_write out of range: waddr=0x%08x aligned=0x%08x wmask=0x%02x pc=" FMT_WORD,
      (uint32_t)waddr, aligned, wmask, cpu.pc);
  uint8_t *p = pmem + aligned - NPC_PMEM_BASE;
  for (int i = 0; i < 4; i++) {
    if (wmask & (1u << i)) p[i] = (uint8_t)((uint32_t)wdata >> (i * 8));
  }
}
