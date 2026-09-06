/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "debug.h"
#include <device/map.h>
#include <memory/paddr.h>

#define DISK_BLOCK_SIZE 512

enum {
  DISK_CMD_NONE = 0,
  DISK_CMD_WRITE = 1,
  DISK_CMD_READ = 2,
};

enum {
  DISK_REG_CMD = 0,
  DISK_REG_BUF,
  DISK_REG_BLKNO,
  DISK_REG_BLKCNT,
  DISK_REG_VALID,
  DISK_REG_NR,
};

typedef union {
  struct {
    uint32_t present;
    uint32_t blksz;
    uint32_t blkcnt;
    uint32_t ready;
    uint32_t reserved;
  } state;

  struct {
    uint32_t cmd;
    uint32_t buf;
    uint32_t blkno;
    uint32_t blkcnt;
    uint32_t valid;
  } req;

  uint32_t raw[DISK_REG_NR];
} disk_mmio_t;

static disk_mmio_t disk_mmio = {};
static FILE *img_fd = NULL;
static const char *diskimg_path = NULL;
static bool disk_present = false;
static bool disk_ready = false;
static uint32_t disk_blkcnt = 0;

void set_diskimg_path(const char *filepath) { diskimg_path = filepath; }

static void disk_update_state(void) {
  disk_mmio.state.present = disk_present;
  disk_mmio.state.blksz = DISK_BLOCK_SIZE;
  disk_mmio.state.blkcnt = disk_blkcnt;
  disk_mmio.state.ready = disk_ready;
  disk_mmio.state.reserved = 0;
}

static size_t disk_transfer_size(uint32_t blkcnt) {
  uint64_t bytes = (uint64_t)blkcnt * DISK_BLOCK_SIZE;
  Assert(bytes <= (uint64_t)SIZE_MAX, "disk transfer is too large: " FMT_WORD,
         blkcnt);
  return (size_t)bytes;
}

static long disk_file_offset(uint32_t blkno) {
  uint64_t offset = (uint64_t)blkno * DISK_BLOCK_SIZE;
  long host_offset = (long)offset;
  Assert((uint64_t)host_offset == offset,
         "disk offset overflow: blkno = " FMT_WORD, blkno);
  return host_offset;
}

static void *disk_guest_buf(uint32_t buf_addr, size_t len) {
  paddr_t start = (paddr_t)buf_addr;
  if (len == 0) {
    return guest_to_host(start);
  }

  paddr_t end = start + len - 1;
  Assert(in_pmem(start) && in_pmem(end),
         "disk buffer [" FMT_PADDR ", " FMT_PADDR "] is outside pmem", start,
         end);
  return guest_to_host(start);
}

static void disk_do_io(bool is_write, uint32_t buf_addr, uint32_t blkno,
                       uint32_t blkcnt) {
  Assert(disk_present && img_fd != NULL, "disk image is not available");
  Assert(blkno <= disk_blkcnt && blkcnt <= disk_blkcnt - blkno,
         "disk request out of range: blkno = " FMT_WORD ", blkcnt = " FMT_WORD
         ", total = " FMT_WORD,
         blkno, blkcnt, disk_blkcnt);

  size_t len = disk_transfer_size(blkcnt);
  if (len == 0) {
    return;
  }

  void *buf = disk_guest_buf(buf_addr, len);
  int ret = fseek(img_fd, disk_file_offset(blkno), SEEK_SET);
  Assert(ret == 0, "seek disk image failed");

  disk_ready = false;
  if (is_write) {
    size_t nwritten = fwrite(buf, len, 1, img_fd);
    Assert(nwritten == 1, "write disk image failed");
    fflush(img_fd);
  } else {
    size_t nread = fread(buf, len, 1, img_fd);
    Assert(nread == 1, "read disk image failed");
#ifdef CONFIG_DIFFTEST
    if (ref_difftest_memcpy != NULL) {
      ref_difftest_memcpy((paddr_t)buf_addr, buf, len, DIFFTEST_TO_REF);
    } else {
      Assert(false, "should not reach here");
    }
#endif
  }
  disk_ready = true;
}

static void disk_submit_request(void) {
  uint32_t cmd = disk_mmio.req.cmd;
  uint32_t buf = disk_mmio.req.buf;
  uint32_t blkno = disk_mmio.req.blkno;
  uint32_t blkcnt = disk_mmio.req.blkcnt;

  if (disk_mmio.req.valid == 0) {
    return;
  }

  switch (cmd) {
  case DISK_CMD_NONE:
    break;
  case DISK_CMD_WRITE:
    disk_do_io(true, buf, blkno, blkcnt);
    break;
  case DISK_CMD_READ:
    disk_do_io(false, buf, blkno, blkcnt);
    break;
  default:
    panic("invalid disk cmd = " FMT_WORD, cmd);
  }

  disk_mmio.req.cmd = DISK_CMD_NONE;
  disk_mmio.req.valid = 0;
}

void disk_io_handler(uint32_t offset, int len, bool is_write) {
  Assert(offset + len <= sizeof(disk_mmio), "invalid disk mmio access");

  if (!is_write) {
    // The same MMIO window is reused for config/status on reads.
    disk_update_state();
    return;
  }

  if (offset == DISK_REG_VALID * sizeof(uint32_t)) {
    disk_submit_request();
  }
}

void init_disk() {
  if (diskimg_path == NULL || diskimg_path[0] == '\0') {
    Log("no disk image specified, expose an empty disk controller");
  } else {
    img_fd = fopen(diskimg_path, "r+b");
    if (img_fd == NULL) {
      Log("can not open disk image: %s", diskimg_path);
    } else {
      int ret = fseek(img_fd, 0, SEEK_END);
      Assert(ret == 0, "seek disk image failed during init");
      long img_size = ftell(img_fd);
      Assert(img_size >= 0, "get disk image size failed");
      rewind(img_fd);

      disk_blkcnt =
          ((uint64_t)img_size + DISK_BLOCK_SIZE - 1) / DISK_BLOCK_SIZE;
      disk_present = true;
      disk_ready = true;
      Log("disk init successfully, img path: %s, blocks: " FMT_WORD,
          diskimg_path, disk_blkcnt);
    }
  }

  disk_update_state();
  add_mmio_map("disk", CONFIG_DISK_CTL_MMIO, &disk_mmio, sizeof(disk_mmio),
               disk_io_handler);
}
