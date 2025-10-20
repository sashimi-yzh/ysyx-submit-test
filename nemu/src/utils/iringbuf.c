#include <common.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include "iringbuf.h"
#include "disasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>
#include <unistd.h>

#define TRACE_FILE "/home/tanghongwei/ysyx-workbench/npc/csrc/cachesim/itrace.bin"
#define COMPRESSED_FILE "/home/tanghongwei/ysyx-workbench/npc/csrc/cachesim/itrace.bin.bz2"

static int ringbuf_index = 0;
char ringbuf[RINGBUF_MAX][128];
FILE *trace_fp = NULL;

// 用于记录连续PC的结构
typedef struct {
    uint32_t start_pc;
    uint32_t count;
} ContiguousPC;
static ContiguousPC current_contiguous = {0, 0};

void init_ringbuf() {
  memset(ringbuf, 0, sizeof(ringbuf));
  trace_fp = fopen(TRACE_FILE, "wb");
  if (!trace_fp) {
    fprintf(stderr, "Failed to open trace file: %s\n", TRACE_FILE);
  }
  // 初始化连续PC结构
  current_contiguous.start_pc = 0;
  current_contiguous.count = 0;
}

void iringbuf(uint32_t thispc) {
    uint32_t pc = thispc;
    uint32_t inst = inst_fetch(&pc, 4);
    char logbuf[128];

    // 处理连续PC
    if (current_contiguous.count == 0) {
        current_contiguous.start_pc = thispc;
        current_contiguous.count = 1;
    } else if (thispc == current_contiguous.start_pc + current_contiguous.count * 4) {
        current_contiguous.count++;
    } else {
        // 写入连续PC信息到二进制文件
        if (trace_fp) {
            fwrite(&current_contiguous, sizeof(ContiguousPC), 1, trace_fp);
        }
        current_contiguous.start_pc = thispc;
        current_contiguous.count = 1;
    }

#ifdef CONFIG_ITRACE
    char buffer[20];
    uint8_t code[4];
    code[0] = (uint8_t)(inst & 0xFF);
    code[1] = (uint8_t)((inst >> 8) & 0xFF);
    code[2] = (uint8_t)((inst >> 16) & 0xFF);
    code[3] = (uint8_t)((inst >> 24) & 0xFF);
    disassemble(buffer, sizeof(buffer), pc, code, sizeof(code));
    sprintf(logbuf, "0x%08x: %-30s", thispc, buffer);
#endif
    sprintf(logbuf, "0x%08x: ", thispc);
    strcat(logbuf, "\t");

    for(int i = 3; i >= 0; i--) {
      char byte[4];
      sprintf(byte, " %02x", (inst >> (i * 8)) & 0xFF);
      strcat(logbuf, byte);
    }

    strcpy(ringbuf[ringbuf_index % RINGBUF_MAX], logbuf);
    ringbuf_index++;
}

void iringbuf_printf() {
  for (int i = 0; i < RINGBUF_MAX; i++) {
  printf("%s", (((ringbuf_index - 1) % RINGBUF_MAX) == i) ? "-->" : "   ");
  puts(ringbuf[i]);
  }
}

void close_ringbuf() {
    // 写入最后一段连续PC信息
    if (trace_fp && current_contiguous.count > 0) {
        fwrite(&current_contiguous, sizeof(ContiguousPC), 1, trace_fp);
    }

    // 关闭文件并压缩
    if (trace_fp) {
        fclose(trace_fp);
        // 使用bzip2压缩文件
        char cmd[128];
        sprintf(cmd, "bzip2 -f %s", TRACE_FILE);
        int ret = system(cmd);
        if (ret != 0) {
            fprintf(stderr, "Failed to compress trace file: %s\n", cmd);
        }
    }
}
