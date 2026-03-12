#ifndef __UTILS_H__
#define __UTILS_H__


#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_END "\033[0m"

enum { NPC_RUNNING, NPC_STOP, NPC_ABORT, NPC_END, NPC_QUIT };

typedef struct {
    int state;
    int halt_pc;
    int halt_ret;
} NPCState;

extern NPCState npc_state;

#define PRINTF_RED(fmt, ...) \
    do { \
        printf(COLOR_RED fmt COLOR_END, ##__VA_ARGS__); \
        fflush(stdout); \
    } while (0)

#define PRINTF_BLUE(fmt, ...) \
    do { \
        printf(COLOR_BLUE fmt COLOR_END, ##__VA_ARGS__); \
        fflush(stdout); \
    } while (0)

#define PRINTF_GREEN(fmt, ...) \
    do { \
        printf(COLOR_GREEN fmt COLOR_END, ##__VA_ARGS__); \
        fflush(stdout); \
    } while (0)

#define log_write(...) \
    do { \
        extern FILE* log_fp; \
        extern bool log_enable(); \
        if (log_enable() && log_fp != NULL) { \
            fprintf(log_fp, __VA_ARGS__); \
            fflush(log_fp); \
        } \
    } while (0) \

#endif