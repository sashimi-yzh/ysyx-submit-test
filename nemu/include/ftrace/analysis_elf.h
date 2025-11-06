#ifndef __ANALYSIS_ELF_H__
#define __ANALYSIS_ELF_H__

#include <common.h>
#include <elf.h>
#define MAX_FUNC 40960

typedef struct analysis_elf
{
    // char* name;
    char name[100];
    Elf32_Addr addr;
    unsigned char info;
    Elf64_Xword size;
} Func_Name_Collation;


void analysis_elf(Func_Name_Collation* func_name,char* elf_file);

extern size_t symbol_table_entry_count;
extern Func_Name_Collation func_name[MAX_FUNC];

#endif