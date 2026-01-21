#ifndef __TRACE_H__
#define __TRACE_H__

// itrace
#define IRINGBUF_DEEPTH 10
#define PRINT_INST_NUM 10
extern char itrace_buf[128];
void Itrace_log(uint32_t inst_in, uint32_t pc_in, uint32_t inst_num);
void print_iringbuf();
// mtrace
void add_mtrace(uint32_t addr, int type, uint32_t data, int mask);
void printf_mtrace();
// ftrace
typedef struct
{
    uint32_t addr;
    char func_name[32];
} FUNC_FTRACE;
extern FUNC_FTRACE ELF_FUNC_FTRACER[128];
extern FILE *ftracer_log_fp;

void load_elf(const std::string &elf_file);
void init_ftracer_log(const char *ftrace_log_file);
void ftracer_log(uint32_t inst_in, uint32_t pc_in);

#define ftracer_write(...)                        \
    do                                            \
    {                                             \
        if (ftracer_log_fp != NULL)               \
        {                                         \
            fprintf(ftracer_log_fp, __VA_ARGS__); \
            fflush(ftracer_log_fp);               \
        }                                         \
    } while (0)

#endif