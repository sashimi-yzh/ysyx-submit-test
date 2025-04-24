#include <am.h>
#include <nemu.h>

#ifndef __ICS_EXPORT
#define DISK_SIZE_ADDR      (DISK_ADDR + 0x00)
#define DISK_CMD_ADDR       (DISK_ADDR + 0x04)
#define DISK_BUF_ADDR       (DISK_ADDR + 0x08)
#define DISK_START_ADDR     (DISK_ADDR + 0x0c)
#define DISK_COUNT_ADDR     (DISK_ADDR + 0x10)

void __am_disk_config(AM_DISK_CONFIG_T *cfg) {
  cfg->blksz = 512;
  cfg->blkcnt = inl(DISK_SIZE_ADDR);
  cfg->present = (cfg->blkcnt > 0);
}

void __am_disk_status(AM_DISK_STATUS_T *stat) {
  stat->ready = 1;
}

void __am_disk_blkio(AM_DISK_BLKIO_T *io) {
  outl(DISK_BUF_ADDR, (uintptr_t)io->buf);
  outl(DISK_START_ADDR, io->blkno);
  outl(DISK_COUNT_ADDR, io->blkcnt);
  outl(DISK_CMD_ADDR, io->write);
}

#else
void __am_disk_config(AM_DISK_CONFIG_T *cfg) {
  cfg->present = false;
}

void __am_disk_status(AM_DISK_STATUS_T *stat) {
}

void __am_disk_blkio(AM_DISK_BLKIO_T *io) {
}
#endif
