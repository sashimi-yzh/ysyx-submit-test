#include <fs.h>


size_t ramdisk_read (void *buf, size_t offset, size_t len);
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

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

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB, FD_DISPINFO};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t serial_write(const void *buf, size_t offset, size_t len);
size_t dispinfo_read(void *buf, size_t offset, size_t len);
size_t fb_write(const void *buf, size_t offset, size_t len);

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]  = {"stdin", 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, serial_write},
  [FD_FB]     = {"/dev/fb", 0, 0, invalid_read, fb_write},
  [FD_DISPINFO] = {"/proc/dispinfo", 0, 0, dispinfo_read, invalid_write},
#include "files.h"
};

void init_fs() {
  AM_GPU_CONFIG_T config;
  ioe_read(AM_GPU_CONFIG, &config);
  if (config.present) {
    file_table[FD_FB].size= config.height * config.width*4;
  }
}

// void fs_strace(const char* sys_call, int a1, int a2, int a3) {
//   Log("SYSCALL(%s, %s, %d, %d)", sys_call, file_table[a1].name, a2, a3);
// }


const char* fs_get_file_name(int fd) {
  return file_table[fd].name;
}

int fs_open(const char *pathname, int flags, int mode) {
  for (int i = 0; i < sizeof(file_table) / sizeof(Finfo); i++) {
    if (strcmp(pathname, file_table[i].name) == 0) {
      file_table[i].open_offset = 0;
      Log("Open file: %s, fp: %d", pathname, i);
      return i;
    }
  }
  panic("Open file failed: No such file!");
  return -1;
}

size_t fs_read(int fd, void *buf, size_t len) {
  if(file_table[fd].read !=0){
    size_t dev_ret = file_table[fd].read(buf, file_table[fd].disk_offset + file_table[fd].open_offset, len);
    file_table[fd].open_offset += dev_ret;
    return dev_ret;
  }


  size_t offset = file_table[fd].open_offset;
  
  if(offset + len > file_table[fd].size) {
    len = file_table[fd].size - offset; // read to the end of file
  }

  size_t ret = ramdisk_read(buf, file_table[fd].disk_offset + offset, len);
               
  file_table[fd].open_offset += ret;
  return ret;
}

size_t fs_write(int fd, const void *buf, size_t len) {
  if(file_table[fd].write != 0) {
    size_t dev_ret = file_table[fd].write(buf, file_table[fd].disk_offset + file_table[fd].open_offset, len);
    file_table[fd].open_offset += dev_ret;
    return dev_ret;
  }

  size_t offset = file_table[fd].open_offset;
  if(offset + len > file_table[fd].size) {
    panic("Write failed: Write beyond the end of file!");
  }
  size_t ret =  ramdisk_write(buf, file_table[fd].disk_offset + offset, len);
  file_table[fd].open_offset += ret;
  return ret;
}

size_t fs_lseek(int fd, size_t offset, int whence) {
  size_t new_offset = 0;
  switch(whence) {
    case SEEK_SET:
      new_offset = offset;
      break;
    case SEEK_CUR:
      new_offset = file_table[fd].open_offset + offset;
      break;
    case SEEK_END:
      new_offset = file_table[fd].size + offset;
      break;
    default:
      panic("Invalid whence!");
  }
  if(new_offset > file_table[fd].size) {
    panic("Seek failed: Seek beyond the end of file!");
  }
  file_table[fd].open_offset = new_offset;
  return new_offset;
}

size_t fs_close(int fd) {
  file_table[fd].open_offset = 0;
  return 0;
}

// according to linux syscalls  "include/linux/syscalls.h"
long sys_write(int fd, const void *buf, size_t len) {
  return (long)fs_write(fd, buf, len);
}

long sys_read(int fd, void *buf, size_t len) {
  return (long)fs_read(fd, buf, len);
}


long sys_lseek(int fd, size_t offset, int whence) {
  return (long)fs_lseek(fd, offset, whence);
}

long sys_close(int fd){
  return (long)fs_close(fd);
}

long sys_open(const char *pathname, int flags, int mode) {
  return (long)fs_open(pathname, flags, mode);
}