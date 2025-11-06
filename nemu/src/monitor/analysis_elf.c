#include <isa.h>
#include <ftrace/ftrace.h>
#include <ftrace/analysis_elf.h>

#define ELF_MAGIC "\x7f" "ELF"

// Func_Name_Collation func_name[MAX_FUNC];
size_t symbol_table_entry_count;

void analysis_elf(Func_Name_Collation* func_name,char* elf_file){
    FILE *file = fopen(elf_file, "rb");
    if(!file){
        panic("cannot open file");
    }

    // 检查ELF文件头
    Elf32_Ehdr elf_header;
    if (fread(&elf_header, sizeof(elf_header), 1, file) != 1) {
        fclose(file);
        panic("cannot read ELF file");
    }
    if (memcmp(elf_header.e_ident, ELF_MAGIC, 4) != 0) {
        fclose(file);
        panic("Not an ELF file\n");
    }

    // section header table中每个元素的大小
    //Elf32_Half e_shentsize = elf_header.e_shentsize;

    // 获取section_headers段的所有信息
    Elf32_Shdr *section_headers = (Elf32_Shdr*)malloc(elf_header.e_shnum * sizeof(Elf32_Shdr));
    fseek(file, elf_header.e_shoff, SEEK_SET);
    if (fread(section_headers, sizeof(Elf32_Shdr), elf_header.e_shnum, file) != elf_header.e_shnum) {
        free(section_headers);
        fclose(file);
        panic("cannot read 获取section_headers段的所有信息 file");
    }

    int strtab_index = 0, symtab_index = 0;
    for (int i = 0; i < elf_header.e_shnum; ++i) {
        if (section_headers[i].sh_type == SHT_STRTAB && strtab_index == 0) {
            strtab_index = i;
        } else if (section_headers[i].sh_type == SHT_SYMTAB && symtab_index == 0) {
            symtab_index = i;
        }
    }


    // 找到.strtab段的入口地址
    char* strtab = (char *)malloc(section_headers[strtab_index].sh_size);
    size_t strtab_size = section_headers[strtab_index].sh_size;
    Elf32_Off strtab_offset = section_headers[strtab_index].sh_offset;
    fseek(file, strtab_offset, SEEK_SET);
    if(fread(strtab, 1, strtab_size, file) != strtab_size) {
        free(section_headers);
        free(strtab);
        fclose(file);
        panic("cannot read .strtab file");
    }

    // 找到.symtab段
    Elf32_Off symtab_offset = section_headers[symtab_index].sh_offset;
    size_t symtab_size = section_headers[symtab_index].sh_size;
    symbol_table_entry_count = symtab_size / sizeof(Elf32_Sym);

    Elf32_Sym *symtab = (Elf32_Sym*)malloc(symtab_size);
    fseek(file, symtab_offset, SEEK_SET);
    if (fread(symtab, sizeof(Elf32_Sym), symbol_table_entry_count, file) != symbol_table_entry_count) {
        free(section_headers);
        free(strtab);
        free(symtab);
        fclose(file);
        panic("cannot read .symtab file");
    }

    int count = 0;
    // 解析符号表项
    for (int i = 0; i < symbol_table_entry_count; ++i) {
        Elf32_Sym symbol = symtab[i];
        // 判断是否为FUNC
        if(ELF32_ST_TYPE(symbol.st_info) == STT_FUNC){
            // 计算符号名称的长度
            size_t name_length = strlen(strtab + symbol.st_name) + 1;

            // 为符号名称分配内存
            // func_name[count].name = (char *)malloc(name_length);
            // if (!func_name[count].name) {
            //     // 处理内存分配失败
            //     panic("malloc");
            //     exit(1);
            // }

            // 拷贝符号名称
            strncpy(func_name[count].name, strtab + symbol.st_name, name_length);

            func_name[count].addr = symbol.st_value;
            func_name[count].size = symbol.st_size;
            func_name[count].info = symbol.st_info;
            count++;

            // 打印符号信息
            // printf("Symbol %d: %s, value: %x, size: %d\n", i, func_name[count - 1].name, symbol.st_value, symbol.st_size);
        }
    }
    free(section_headers);
    free(strtab);
    free(symtab);
    fclose(file);
}