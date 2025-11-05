#include <utils.h>
#include <stdio.h>
#include <common.h>
#include <fmt-def.h>
#include <zlib.h>

IFDEF(CONFIG_PC_TRACE, static 
MUXDEF(CONFIG_PC_TRACE_COMPRESS, gzFile, FILE*) pc_trace_fp;)

int gz_printf(gzFile log_file, char *format, ...) {
    static char buffer[512];
    va_list args;
    va_start(args, format);
    int len = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (len < 0) {
        return -1;
    }

    if (gzwrite(log_file, buffer, len) != len) {
        return -1;
    }
    return 0;
}

void init_pc_trace(){
  char buf[100];
  Log("PC Trace: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  MUXDEF(CONFIG_PC_TRACE_BINARY,
  sprintf(buf, "%s/build/pc_trace.bin", getenv("NEMU_HOME")),
  sprintf(buf, "%s/build/pc_trace.txt", getenv("NEMU_HOME")));
#ifdef CONFIG_PC_TRACE
#ifdef CONFIG_PC_TRACE_COMPRESS
  strcat(buf, ".gz");
  pc_trace_fp = gzopen(buf, "wb");
#else 
  pc_trace_fp = fopen(buf, "wb");
#endif 
  Log("PC TRACE: %s", buf);
#endif
}

void pc_trace(word_t pc){
#ifdef CONFIG_PC_TRACE
#ifdef CONFIG_PC_TRACE_COMPRESS
  MUXDEF(CONFIG_PC_TRACE_BINARY, 
  gzwrite(pc_trace_fp, (char*)&pc, sizeof(word_t)),
  gz_printf(pc_trace_fp, "%lx\n", pc));
#else  
  MUXDEF(CONFIG_PC_TRACE_BINARY,
  fwrite(&pc, sizeof(word_t), 1, pc_trace_fp),
  fprintf(pc_trace_fp, FMT_WORD_HEX "\n", pc));
#endif
#endif 
}
void pc_trace_close(){
#ifdef CONFIG_PC_TRACE
#ifdef CONFIG_PC_TRACE_COMPRESS
  gzclose(pc_trace_fp);
#else 
  fclose(pc_trace_fp);
#endif
#endif 
}
