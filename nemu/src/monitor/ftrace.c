#include <common.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>


typedef struct {
    char name[20];
    paddr_t addr;
    unsigned char info;
    Elf64_Xword size;
}SymElf;

SymElf *symbol_tbl;
int symbol_tbl_size = 0;
int call_depth = 0;

void parse_elf(const char * elf_file){
    if(elf_file == NULL) return;
    //Log("elf file is :%s",elf_file);
    // 读取ELF header
    
    FILE *fp;
    fp = fopen(elf_file, "rb");
    
    
    if(fp == NULL)
    {
        printf("failed to open the elf file!\n");
        assert(0);
    }
    


    Elf32_Ehdr elf_header;
    if (fread(&elf_header, sizeof(Elf32_Ehdr), 1, fp) <= 0) {
        fclose(fp);
        assert(0);
    }

    // 检查文件是否为ELF文件
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file\n");
        fclose(fp);
        assert(0);
    }

    // 移动到Section header table,寻找字符表节
    fseek(fp, elf_header.e_shoff, SEEK_SET);
    Elf32_Shdr strtab_header;
    while (1) {
        if (fread(&strtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0) {
            fclose(fp);
            assert(0);
        }
        if (strtab_header.sh_type == SHT_STRTAB) {
            break;
        }
    }

    // 读取字符串表内容
    char *string_table = malloc(strtab_header.sh_size);
    fseek(fp, strtab_header.sh_offset, SEEK_SET);
    if (fread(string_table, strtab_header.sh_size, 1, fp) <= 0) {
        fclose(fp);
        assert(0);
    }

    // 寻找符号表节
    Elf32_Shdr symtab_header;
    fseek(fp, elf_header.e_shoff, SEEK_SET);
    while (1) {
        if (fread(&symtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0) {
            fclose(fp);
            assert(0);
        }
        if (symtab_header.sh_type == SHT_SYMTAB) {
            break;
        }
    }

    /* 读取符号表中的每个符号项 */ 

    fseek(fp, symtab_header.sh_offset, SEEK_SET);
    Elf32_Sym symbol;
    // 确定符号表的条数
    size_t num_symbols = symtab_header.sh_size / symtab_header.sh_entsize;
    // 分配内存用于存储符号表
    symbol_tbl = malloc(num_symbols * sizeof(SymElf));

    Log("%d",(int)num_symbols);

    for (size_t i = 0; i < num_symbols; ++i) {
        if (fread(&symbol, sizeof(Elf32_Sym), 1, fp) <= 0 ) {
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        // 判断符号是否为函数，并且函数的大小不为零
        if (ELF64_ST_TYPE(symbol.st_info) == STT_FUNC && symbol.st_size != 0) {
            // 从字符串表中获取符号名称
            const char *name = string_table  + symbol.st_name;
            // 存储符号信息到 symbol_table 结构体数组
            strncpy(symbol_tbl[i].name, name, sizeof(symbol_tbl[i].name) - 1);
            symbol_tbl[i].addr = symbol.st_value;
            symbol_tbl[i].info = symbol.st_info;
            symbol_tbl[i].size = symbol.st_size;
            //printf("%s,%x,%x,%d\n",symbol_tbl[i].name,symbol_tbl[i].addr,symbol_tbl[i].info,(int)symbol_tbl[i].size);
        }
        symbol_tbl_size = num_symbols;
    }

    // 关闭文件并释放内存
    fclose(fp);
    free(string_table);


    

}

int find_symbol_func(paddr_t target, bool is_call){
    int i;
    for (i=0;i<symbol_tbl_size;i++) {
        if(ELF64_ST_TYPE(symbol_tbl[i].info)==STT_FUNC) {
            if(is_call) {
                if(symbol_tbl[i].addr == target) break;
            }
            else {
                if(symbol_tbl[i].addr <= target && target < symbol_tbl[i].addr + symbol_tbl[i].size) 
                    break;
            }

        }
    }
    return i<symbol_tbl_size?i:-1;

}

void trace_call(paddr_t pc, paddr_t target){
    if(symbol_tbl == NULL) {
        printf("no table\n");
        return ;
    }

    ++call_depth;

    if(call_depth <= 2) return;

    int i = find_symbol_func(target,true);
    log_write(FMT_PADDR ": %*scall [%s@" FMT_PADDR "]\n",
		pc,
		(call_depth-3)*2, "",
		i>=0?symbol_tbl[i].name:"???",
		target
	);

    i=i;
    
}

void trace_ret(paddr_t pc) {
    if(symbol_tbl == NULL) return;

    if(call_depth <= 2) return;

    int i = find_symbol_func(pc,false);
    log_write(FMT_PADDR ": %*sret [%s]\n",
		pc,
		(call_depth-3)*2, "",
		i>=0?symbol_tbl[i].name:"???"
	);
    
    i=i;

    --call_depth;

}