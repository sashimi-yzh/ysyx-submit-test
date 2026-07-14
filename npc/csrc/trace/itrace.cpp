#include "include/common.h"
#include "config.h"
#include "include/CPU.h"

static char itrace_buf[512];
static char mtrace_buf[512];
static int itrace_buf_pos = 0;
static int mtrace_buf_pos = 0;
static std::string itrace_log_file = "";

static int safe_sprintf_append(char *buf, int *pos, int buf_size, const char *fmt, ...)
{
    int remaining = buf_size - *pos;
    if (remaining <= 0)
    {
        buf[buf_size - 1] = '\0';
        *pos = buf_size - 1;
        return -1;
    }

    va_list args;
    va_start(args, fmt);
    int written = vsnprintf(buf + *pos, remaining, fmt, args);
    va_end(args);

    if (written < 0)
    {
        buf[*pos] = '\0';
        return -1;
    }
    else if (written >= remaining)
    {
        *pos = buf_size - 1;
    }
    else
    {
        *pos += written;
    }
    return written;
}

void itrace_write(word_t pc, word_t inst)
{

    safe_sprintf_append(itrace_buf, &itrace_buf_pos, sizeof(itrace_buf),
                        "[pc]0x%08x: 0x%08x", pc, inst);

    if (mtrace_buf_pos > 0)
    {
        safe_sprintf_append(itrace_buf, &itrace_buf_pos, sizeof(itrace_buf),
                            " %s", mtrace_buf);
    }
    safe_sprintf_append(itrace_buf, &itrace_buf_pos, sizeof(itrace_buf),
                        " @cycle %llu", cpu->cycle_count);
}

void itrace_log_init(std::string build_dir)
{
    itrace_log_file = build_dir + "/itrace-log.txt";
    FILE *fp = fopen(itrace_log_file.c_str(), "w");
    if (fp != NULL)
    {
        fclose(fp);
    }
}

void mtrace_record(const char *msg)
{
    safe_sprintf_append(mtrace_buf, &mtrace_buf_pos, sizeof(mtrace_buf),
                        " %s", msg);
}

static void itrace_reset()
{
    itrace_buf_pos = 0;
    mtrace_buf_pos = 0;
    itrace_buf[0] = '\0';
    mtrace_buf[0] = '\0';
}

static int log_count = 0;
void trace_log()
{
#ifdef MTRACE_ONLY
    if (mtrace_buf_pos == 0)
    {
        itrace_reset();
        return;
    }
#endif
    if (log_count++ > ITRACE_MAX_LINES)
    {
        return;
        FILE *fp = fopen(itrace_log_file.c_str(), "w");
        if (fp != NULL)
        {
            fclose(fp);
        }
        log_count = 0;
    }
    FILE *fp = std::fopen(itrace_log_file.c_str(), "a");
    if (!fp)
        return;

    std::fwrite(itrace_buf, 1, (size_t)itrace_buf_pos, fp);
    std::fputc('\n', fp);
    std::fclose(fp);

    itrace_reset();
}