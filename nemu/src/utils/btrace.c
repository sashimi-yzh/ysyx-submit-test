#include <common.h>
#include <fmt-def.h>
#include <zlib.h>

static gzFile btrace_fp;

void btrace_init(){
    // printf("BTRACE: %s\n", ANSI_FMT("ON", ANSI_FG_GREEN));
  char buf[100];
  Log("Branch Trace: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  sprintf(buf, "%s/build/btrace.bin.gz", getenv("NEMU_HOME"));
  btrace_fp = gzopen(buf, "wb");
  Log("PC TRACE: %s", buf);
}

void btrace(word_t pc, uint32_t inst, uint8_t taken){
//   static bool isfirst = true;
//   if(isfirst){ isfirst = false; btrace_init(); return;}
#ifdef CONFIG_BTRACE
    gzwrite(btrace_fp, (char*)&pc, sizeof(pc));
    gzwrite(btrace_fp, (char*)&inst, sizeof(inst));
    gzwrite(btrace_fp, (char*)&taken, sizeof(taken));
#endif 
}

void btrace_close(){
#ifdef CONFIG_BTRACE
    gzclose(btrace_fp);
#endif 
}