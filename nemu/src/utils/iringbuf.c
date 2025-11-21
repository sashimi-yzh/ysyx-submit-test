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

// --- 开始修改 ---

// 1. 将宏定义为相对路径
#define TRACE_FILE_RELATIVE "csrc/cachesim/itrace.bin"
#define COMPRESSED_FILE_RELATIVE "csrc/cachesim/itrace.bin.bz2"

// 2. 声明两个全局变量来存储完整路径
static char full_trace_path[1024];
static char full_compressed_path[1024];

// --- 修改结束 ---

static int ringbuf_index = 0;
char ringbuf[RINGBUF_MAX][128];
FILE *trace_fp = NULL;

// 用于记录连续PC的结构
typedef struct {
    uint32_t start_pc;
    uint32_t count;
} ContiguousPC;
static ContiguousPC current_contiguous = {0, 0};

static int get_full_path(const char *relative_path, char *output_path, size_t output_size) {
    const char *npc_home = getenv("NPC_HOME");
    if (npc_home == NULL) {
        fprintf(stderr, "[iringbuf] Error: Environment variable NPC_HOME is not set.\n");
        return -1;
    }

    int ret = snprintf(output_path, output_size, "%s/%s", npc_home, relative_path);
    if (ret < 0 || ret >= output_size) {
        fprintf(stderr, "[iringbuf] Error: Path too long: %s/%s\n", npc_home, relative_path);
        return -1;
    }
    return 0;
}

void init_ringbuf() {
    memset(ringbuf, 0, sizeof(ringbuf));
    if (get_full_path(TRACE_FILE_RELATIVE, full_trace_path, sizeof(full_trace_path)) != 0) {
        return;
    }
    trace_fp = fopen(full_trace_path, "wb");
    if (!trace_fp) {
        perror("Failed to open trace file");
        fprintf(stderr, "[iringbuf] Could not open file: %s\n", full_trace_path);
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
        fwrite(&current_contiguous, sizeof(ContiguousPC), 1, trace_fp);
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
    if (!trace_fp) return;

    if (current_contiguous.count > 0) {
        fwrite(&current_contiguous, sizeof(ContiguousPC), 1, trace_fp);
    }

    // 关闭文件
    fclose(trace_fp);
    trace_fp = NULL;

    if (get_full_path(COMPRESSED_FILE_RELATIVE, full_compressed_path, sizeof(full_compressed_path)) != 0) {
        return;
    }

    char cmd[2048];
    snprintf(cmd, sizeof(cmd), "bzip2 -f %s", full_trace_path);
    int ret = system(cmd);
    if (ret != 0) {
        fprintf(stderr, "[iringbuf] Failed to compress trace file. Command: %s\n", cmd);
    } else {
        printf("[iringbuf] Trace file generated and compressed successfully: %s.bz2\n", full_trace_path);
    }

}
