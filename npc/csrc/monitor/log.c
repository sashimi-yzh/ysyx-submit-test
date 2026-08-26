#include "common.h"

FILE* log_fp = NULL;
void init_log(const char *log_file){
    log_fp = stdout;
    if (log_file != NULL) {
        FILE *fp = fopen(log_file, "w");
        Assert(fp, "Can not open '%s'", log_file);
        log_fp = fp;
    }
    Log("Log is written to %s", log_file ? log_file : "stdout");
    log_fp = fopen(CONFIG_LOG_PATH,"w");
	Assert(log_fp, "Cannot open log file!");
}
bool log_enable(){
    return true;
}