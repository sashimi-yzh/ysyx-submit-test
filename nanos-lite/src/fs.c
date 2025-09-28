#include <fs.h>
#include <ramdisk.h>
#include <device.h>

typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
  size_t open_offset;
} Finfo;

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]  = {"stdin", 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, serial_write},
  [FD_FB] = {"/dev/fb", 0, 0, invalid_read, fb_write},
  {"/dev/events", 0, 0, events_read, invalid_write},
  {"/proc/dispinfo", 0, 0, dispinfo_read, invalid_write},
  {"/dev/sb", 0, 0, invalid_read, sb_write},
  {"/dev/sbctl", 0, 0, sbctl_read, sbctl_write},
#include "files.h"
};

void init_fs() {
  // initialize the size of /dev/fb
  AM_GPU_CONFIG_T cfg;
  ioe_read(AM_GPU_CONFIG, &cfg);
  file_table[FD_FB].size = cfg.vmemsz;
}

const char *fs_get_filename(int fd) {
  return file_table[fd].name;
}

int fs_open(const char *pathname, int flags, int mode) {
  for (int i = 0; i < LENGTH(file_table); ++i) {
    if (!strcmp(pathname, file_table[i].name)) {
      file_table[i].open_offset = 0;
      return i;
    }
  }
  return -1;
}

size_t fs_lseek(int fd, size_t offset, int whence) {
  assert(0 <= fd && fd < LENGTH(file_table));
  switch (whence) {
    case SEEK_SET:
      file_table[fd].open_offset = offset;
    break;
    case SEEK_CUR:
      file_table[fd].open_offset += offset;
    break;
    case SEEK_END:
      file_table[fd].open_offset = file_table[fd].size + offset;
    break;
    default: assert(0);
  }
  return file_table[fd].open_offset;
}

size_t fs_read(int fd, void *buf, size_t len) {
  assert(0 <= fd && fd < LENGTH(file_table));
  size_t bytes_left = file_table[fd].size - file_table[fd].open_offset;
  size_t res = MIN(bytes_left, len);

  if (file_table[fd].read) {
    if (file_table[fd].size) { // virtual file with actual size
      res = file_table[fd].read(buf, file_table[fd].open_offset, res);
    } else {
      res = file_table[fd].read(buf, file_table[fd].open_offset, len);
    }
  } else {
    if (len == 0 || file_table[fd].open_offset >= file_table[fd].size) {
      res = 0;
    } else {
      ramdisk_read(buf, file_table[fd].disk_offset + file_table[fd].open_offset, res);
    }
  }
  file_table[fd].open_offset += res;
  return res;
}

size_t fs_write(int fd, const void *buf, size_t len) {
  assert(0 <= fd && fd < LENGTH(file_table));
  size_t bytes_left = file_table[fd].size - file_table[fd].open_offset;
  size_t res = MIN(bytes_left, len);
  
  if (file_table[fd].write) {
    if (file_table[fd].size) {
      res = file_table[fd].write(buf, file_table[fd].open_offset, res);
    } else {
      res = file_table[fd].write(buf, file_table[fd].open_offset, len);
    }
  } else {
    if (len == 0 || file_table[fd].open_offset >= file_table[fd].size) {
      res = 0;
    } else {
      ramdisk_write(buf, file_table[fd].disk_offset + file_table[fd].open_offset, res);
    }
  }
  file_table[fd].open_offset += res;
  return res;
}

int fs_close(int fd) {
  assert(0 <= fd && fd < LENGTH(file_table));
  return 0;
}
