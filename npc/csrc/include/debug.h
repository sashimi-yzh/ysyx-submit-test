#ifndef __DEBUG_H__
#define __DEBUG_H__

#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_NONE       "\33[0m"
#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

#define Log(format, ...) \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
    __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#define _Log(...) \
    do { \
        printf(__VA_ARGS__); \
        } while (0)

#endif
