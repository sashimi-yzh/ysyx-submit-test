#include <am.h>
#include <nemu.h>
#include <stdint.h>

enum {
  DISK_CMD_NONE = 0,
  DISK_CMD_WRITE = 1,
  DISK_CMD_READ = 2,
};

#define DISK_PRESENT_ADDR ((volatile uint32_t *)(DISK_ADDR + 0x00))
#define DISK_BLKSZ_ADDR   ((volatile uint32_t *)(DISK_ADDR + 0x04))
#define DISK_BLKCNT_ADDR  ((volatile uint32_t *)(DISK_ADDR + 0x08))
#define DISK_READY_ADDR   ((volatile uint32_t *)(DISK_ADDR + 0x0c))

#define DISK_CMD_ADDR     ((volatile uint32_t *)(DISK_ADDR + 0x00))
#define DISK_BUF_ADDR     ((volatile uint32_t *)(DISK_ADDR + 0x04))
#define DISK_BLKNO_ADDR   ((volatile uint32_t *)(DISK_ADDR + 0x08))
#define DISK_REQCNT_ADDR  ((volatile uint32_t *)(DISK_ADDR + 0x0c))
#define DISK_VALID_ADDR   ((volatile uint32_t *)(DISK_ADDR + 0x10))

void __am_disk_config(AM_DISK_CONFIG_T *cfg) {
  cfg->present = *DISK_PRESENT_ADDR;
  cfg->blksz = *DISK_BLKSZ_ADDR;
  cfg->blkcnt = *DISK_BLKCNT_ADDR;
}

void __am_disk_status(AM_DISK_STATUS_T *stat) {
  stat->ready = *DISK_READY_ADDR;
}

void __am_disk_blkio(AM_DISK_BLKIO_T *io) {
  uintptr_t buf = (uintptr_t)io->buf;
  panic_on((uint32_t)buf != buf, "disk buffer address exceeds MMIO width");

  *DISK_CMD_ADDR = io->write ? DISK_CMD_WRITE : DISK_CMD_READ;
  *DISK_BUF_ADDR = (uint32_t)buf;
  *DISK_BLKNO_ADDR = io->blkno;
  *DISK_REQCNT_ADDR = io->blkcnt;
  *DISK_VALID_ADDR = 1;
}
