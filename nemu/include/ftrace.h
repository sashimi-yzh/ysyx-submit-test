#ifndef __FTRACE_H__
#define __FTRACE_H__

#include<stdint.h>

typedef struct func_meta{
    uint32_t addr;
    char*   name;
    uint32_t size;
}func_meta;

typedef struct string_table{
    uint32_t name;
    char*   contents;
} string_table;

typedef struct FtraceMeta 
{   
    func_meta   *fm_entries;
    uint32_t    size;
}FtraceMeta;

void init_ftrace(char* elf_file);

void ftrace_message(uint32_t pc,uint32_t dnpc,char* inst_name);

#endif