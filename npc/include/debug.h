#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "common.h"
#include <stdio.h>
#include "utils.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

// // 如果定义了NDEBUG，则debug宏为空，否则输出调试信息
// #ifdef NDEBUG
// #define debug(M, ...)
// #else
// #define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
// #endif

// // 获取当前errno的描述
// #define clean_errno() (errno == 0 ? "None" : strerror(errno))

// // 输出错误信息
// #define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// // 输出警告信息
// #define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// // 输出普通信息
// #define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// // 检查条件A是否为真，如果不为真则输出错误信息并跳转到error标签
// #define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// // 直接输出错误信息并跳转到error标签
// #define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// // 检查内存分配是否成功
// #define check_mem(A) check((A), "Out of memory.")

// // 检查条件A是否为真，如果不为真则输出调试信息并跳转到error标签
// #define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }



// 输出带颜色的日志信息
#define Log(format, ...) \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

// 断言条件cond是否为真，如果不为真则输出错误信息并终止程序
// #define Assert(cond, format, ...) \
//   do { \
//     if (!(cond)) { \
//       MUXDEF(CONFIG_TARGET_AM, printf(ANSI_FMT(format, ANSI_FG_RED) "\n", ## __VA_ARGS__), \
//         (fflush(stdout), fprintf(stderr, ANSI_FMT(format, ANSI_FG_RED) "\n", ##  __VA_ARGS__))); \
//       IFNDEF(CONFIG_TARGET_AM, extern FILE* log_fp; fflush(log_fp)); \
//       extern void assert_fail_msg(); \
//       assert_fail_msg(); \
//       assert(cond); \
//     } \
//   } while (0)
#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      printf(ANSI_FMT(format, ANSI_FG_RED) "\n", ## __VA_ARGS__), \
      assert(cond); \
    } \
  } while (0)
  
// 触发断言失败
#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

// 用于标记未实现的功能
#define TODO() panic("please implement me")

#endif
