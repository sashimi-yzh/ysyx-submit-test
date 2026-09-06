#include "common.h"
#include <fs.h>

#define FDMAPSIZE 32

typedef size_t (*ReadFn)(void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn)(const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
} Finfo;

enum { FD_STDIN, FD_STDOUT, FD_STDERR };
enum { DEV_EVENTS = 3, DEV_FB = 4 };

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("[fs.c invalid_read] should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("[fs.c invalid_write] should not reach here");
  return 0;
}

int fs_open(const char *filename, int flags, int mode);
size_t fs_read(int fd, void *buf, size_t len);
size_t fs_write(int fd, const void *buf, size_t len);
size_t fs_lseek(int fd, size_t offset, int whence);
int fs_close(int fd);

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
    [FD_STDIN] = {"stdin", 0, 0, invalid_read, invalid_write},
    [FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
    [FD_STDERR] = {"stderr", 0, 0, invalid_read, serial_write},
    {"/dev/events", 0, 0, events_read, invalid_write},
    {"/dev/fb", 0, 0, invalid_read, fb_write},
    {"/proc/dispinfo", 0, 0, dispinfo_read, invalid_write},
#include "files.h"
};

static struct fd_mapping {
  int sys_fs;
  size_t fs_offset;
  int valid;
} fd_maping[FDMAPSIZE];

int get_fs_map() {
  for (int i = 3; i < FDMAPSIZE; i++) {
    if (fd_maping[i].valid == false) {
      return i;
    }
  }

  panic("the fs_maping has run out");
}

int fs_str_cmp(const char *str1, const char *str2) {
  uint32_t counter = 0;
  while (str1[counter] != '\0' && str2[counter] != '\0') {
    if (str1[counter] != str2[counter]) {
      return false;
    }
    counter++;
  }
  return str1[counter] == str2[counter];
}

int fs_exist(const char *filename) {
  int file_table_size = sizeof(file_table) / sizeof(file_table[0]);
  for (int i = 3; i < file_table_size; i++) {
    if (fs_str_cmp(filename, file_table[i].name)) {
      return true;
    }
  }

  return false;
}

bool fs_should_schedule(int fd, bool is_write) {
  if (fd < 0 || fd >= FDMAPSIZE || fd_maping[fd].valid == false) {
    return false;
  }

  int sys_fd = fd_maping[fd].sys_fs;
  switch (sys_fd) {
  case FD_STDOUT:
  case FD_STDERR:
  case DEV_FB:
    return is_write;
  case DEV_EVENTS:
    return !is_write;
  default:
    return false;
  }
}

int fs_open(const char *filename, int flags, int mode) {
  int file_table_size = sizeof(file_table) / sizeof(file_table[0]);
  for (int i = 3; i < file_table_size; i++) {
    if (fs_str_cmp(filename, file_table[i].name)) {
      int u_fd = get_fs_map();
      fd_maping[u_fd].valid = true;
      fd_maping[u_fd].fs_offset = 0;
      fd_maping[u_fd].sys_fs = i;
      // Log("[fs_open] open file %s, diskoffset 0x%x, set fd is %d", filename,
      //     file_table[i].disk_offset, u_fd);
      return u_fd;
    }
  }
  panic("invalid filename %s", filename);
}

static int fs_call_is_valid(int sys_fd, int is_write) {
  if (is_write) {
    return file_table[sys_fd].write != NULL &&
           file_table[sys_fd].write != invalid_write;
  } else {
    return file_table[sys_fd].read != NULL &&
           file_table[sys_fd].read != invalid_read;
  }
}

size_t fs_read(int fd, void *buf, size_t len) {
  if (fd_maping[fd].valid == false) {
    panic("fsread meet a invalid fd");
  }
  int sys_fd = fd_maping[fd].sys_fs;
  size_t file_offset = fd_maping[fd].fs_offset;

  if (fs_call_is_valid(sys_fd, 0)) {
    return file_table[sys_fd].read(buf, file_offset, len);
  }

  size_t disk_offset = file_table[sys_fd].disk_offset;
  size_t file_size = file_table[sys_fd].size;

  size_t empty_len = file_size - file_offset;
  size_t final_len = (empty_len > len) ? len : empty_len;

  // Log("fs_read final_len is %d, empty_len is %d, sys_fd is %d", final_len,
  // empty_len, sys_fd);

  if (empty_len == 0) {
    return 0;
  }

  size_t res = ramdisk_read(buf, disk_offset + file_offset, final_len);
  fd_maping[fd].fs_offset = file_offset + res;
  return res;
}

size_t fs_write(int fd, const void *buf, size_t len) {
  if (fd_maping[fd].valid == false) {
    panic("fswrite meet a invalid rd");
  }
  int sys_fd = fd_maping[fd].sys_fs;
  size_t file_offset = fd_maping[fd].fs_offset;

  if (fs_call_is_valid(sys_fd, 1)) {
    return file_table[sys_fd].write(buf, file_offset, len);
  }

  size_t disk_offset = file_table[sys_fd].disk_offset;
  size_t file_size = file_table[sys_fd].size;

  size_t empty_len = file_size - file_offset;
  size_t final_len = (empty_len > len) ? len : empty_len;
  if (empty_len == 0) {
    return 0;
  }

  size_t res = ramdisk_write(buf, disk_offset + file_offset, final_len);
  fd_maping[fd].fs_offset = file_offset + res;
  return res;
  return 0;
}

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
size_t fs_lseek(int fd, size_t offset, int whence) {
  if (fd < 0 || fd >= FDMAPSIZE || fd_maping[fd].valid == false) {
    panic("fs_lseek: invalid fd=%d (valid range 0..%d, fd not open)", fd, FDMAPSIZE - 1);
  }
  int sys_fd = fd_maping[fd].sys_fs;
  switch (whence) {
  case SEEK_SET:
    if (offset > file_table[sys_fd].size) {
      return -1;
    }
    fd_maping[fd].fs_offset = offset;
    // Log("[fs_lseek] set file %s pointer to 0x%x", file_table[sys_fd].name,
    // file_table[sys_fd].disk_offset + offset);
    break;
  case SEEK_CUR: {
    size_t file_offset = fd_maping[fd].fs_offset;
    size_t final_offset = file_offset + offset;
    if (final_offset > file_table[sys_fd].size) {
      return -1;
    }
    fd_maping[fd].fs_offset = final_offset;
    break;
  }
  case SEEK_END: {
    size_t file_size = file_table[sys_fd].size;
    if (offset > file_size) {
      return -1;
    }
    fd_maping[fd].fs_offset = file_size - offset;
    break;
  }
  }
  return fd_maping[fd].fs_offset;
}

int fs_close(int fd) {
  if (fd == 0 || fd == 1 || fd == 2) {
    return 0;
  }

  // Log("close the opened file, fd is %d", fd);

  fd_maping[fd].valid = 0;
  fd_maping[fd].sys_fs = 0;
  fd_maping[fd].fs_offset = 0;

  return 0;
}

void init_fs() {
  // TODO: initialize the size of /dev/fb
  for (int i = 0; i < FDMAPSIZE; i++) {
    fd_maping[i].valid = false;
  }
  fd_maping[0].valid = true;
  fd_maping[0].sys_fs = 0;
  fd_maping[1].valid = true;
  fd_maping[1].sys_fs = 1;
  fd_maping[2].valid = true;
  fd_maping[2].sys_fs = 2;

  AM_GPU_CONFIG_T cfg;
  ioe_read(AM_GPU_CONFIG, &cfg);
  file_table[4].size = sizeof(uint32_t) * cfg.height * cfg.width;
}
