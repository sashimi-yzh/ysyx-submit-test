#include <fs.h>

typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
} Finfo;

// 文件结构体列表
enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB};

//调试用 方便打印函数的操作
const char* const fs_lseek_whence[] = {"SEEK_SET", "SEEK_CUR", "SEEK_END"};
const char* const fs_fs_write[]     = {"FD_STDIN", "FD_STDOUT", "FD_STDERR", "FD_FB"};
const char* const fs_fs_read[]     =  {"FD_EVENTS", "FD_DISPINFO"};

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
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, invalid_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, invalid_write},
#include "files.h"
};

void init_fs() {
  // TODO: initialize the size of /dev/fb
}
// TODO：自己实现fs_open函数


size_t fs_write(int fd, const void *buf, size_t len){
  
  assert(buf != NULL);

  size_t ret_len = 0;

  switch (fd)
  {
    case FD_STDOUT :case FD_STDERR:  //写串口
      ret_len = len;
      // Log("sys_write %s.buf *= %lx,len = %lx",fs_fs_write[FD_STDOUT],buf,len); // 只是调试使用
      for (uint16_t i=0;i<len;++i)
      {
        putch(((char *)buf)[i]);
      }
      return ret_len;
      break;
    default:
      break;
  }

  return ret_len;
}
