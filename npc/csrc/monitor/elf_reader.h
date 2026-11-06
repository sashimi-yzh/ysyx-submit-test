#ifndef ELF_READER_H
#define ELF_READER_H

#include <stdint.h>

// 函数表结构定义
typedef struct functab {
    uint32_t value;
    char func_name[32];
} Functab;

// 全局函数表（外部可访问）
extern Functab* functab;

// 全局函数计数（外部可访问）
extern int functab_count;

// 函数声明
void extract_functions(const char* elf_path);

#endif
