/***************************************************************************************
* NPC Log System
* 日志系统头文件
***************************************************************************************/

#ifndef __LOG_H__
#define __LOG_H__

#include <cstdio>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdlib>

// ANSI颜色定义
#define ANSI_FG_BLACK   "\33[1;30m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN    "\33[1;36m"
#define ANSI_FG_WHITE   "\33[1;37m"
#define ANSI_BG_BLACK   "\33[1;40m"
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_BG_GREEN   "\33[1;42m"
#define ANSI_BG_YELLOW  "\33[1;43m"
#define ANSI_BG_BLUE    "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;45m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_DIM        "\33[2m"
#define ANSI_BOLD       "\33[1m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

enum {
  LOG_ERROR = 0,
  LOG_WARN,
  LOG_INFO,
  LOG_DEBUG,
};

// 日志宏
#define Log(format, ...) \
    _Log(LOG_INFO, __FILE__, __LINE__, __func__, format, ## __VA_ARGS__)
#define LogWarn(format, ...) \
    _Log(LOG_WARN, __FILE__, __LINE__, __func__, format, ## __VA_ARGS__)
#define LogError(format, ...) \
    _Log(LOG_ERROR, __FILE__, __LINE__, __func__, format, ## __VA_ARGS__)
#define LogDebug(format, ...) \
    _Log(LOG_DEBUG, __FILE__, __LINE__, __func__, format, ## __VA_ARGS__)

// 失败时的统一快照（GPR/CSR/iringbuf/最近 trace）
void npc_dump_snapshot();

// 断言宏：失败时输出快照并终止，避免 NDEBUG 下 assert 失效
#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      fflush(stdout); \
      fprintf(stderr, ANSI_FMT(format, ANSI_FG_RED) "\n", ## __VA_ARGS__); \
      npc_dump_snapshot(); \
      log_flush(); \
      abort(); \
    } \
  } while (0)

#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

// 运行级日志目录管理（仅在 LOG=1 时启用）
bool log_run_init(const char *trace_override);
void log_close_run();
const char *log_run_dir();

// 日志函数
extern FILE* log_fp;
void init_log(const char *log_file);
void log_set_level(int level);
int log_get_level();
bool log_color_enabled();
void _Log(int level, const char *file, int line, const char *func,
          const char *format, ...);
void log_write(const char *format, ...);
void log_flush();
void log_trace_prefix_at(char *buf, size_t size, const char *tag,
                         uint32_t pc, uint64_t cycle, uint64_t commit, uint64_t time);
void assert_fail_msg();

#endif
