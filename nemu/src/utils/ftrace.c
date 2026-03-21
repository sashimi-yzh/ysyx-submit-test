#include <ftrace.h>

#define MAX_FUNCTIONS 1000
#define MAX_CALL_DEPTH 200 

static FunctionSymbol *func_table = NULL;
static int func_count = 0;
static int call_depth = 0;
static bool ftrace_enabled = false;

void cleanup_ftrace(void) {
    if(func_table) {
        for(int i=0; i<func_count; i++) {
            if(func_table[i].name) {
                free(func_table[i].name);
            }
        }
        free(func_table);
        func_table = NULL;
    }
    func_count = 0;
    call_depth = 0;
    ftrace_enabled = false;
}

static const char *find_function_name(uint32_t addr) {
    for(int i=0; i<func_count; i++) {
        if(addr >= func_table[i].addr && addr < func_table[i].addr + func_table[i].size) {
            return func_table[i].name;
        }
    }

    return NULL;
}

void init_ftrace(char *elf_file) {
    if(elf_file == NULL) {
        printf("Ftrace: Disable Elf file\n");
        return ;
    }

    FILE *fp = fopen(elf_file, "rb");
    if(fp == NULL) {
        printf("Ftrace: Error to open elf file <%s>\n", elf_file);
        return ;
    }

    Elf32_Ehdr ehdr;
    if(fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        printf("Ftrace: Error to read elf header\n");
        fclose(fp);
        return ;
    }

    if(ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' || ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F') {
        printf("Ftrace: Invalid elf file\n");
        fclose(fp);
        return ;
    }

    // find section header
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    Elf32_Shdr *shdrs = malloc(ehdr.e_shnum * ehdr.e_shentsize);
    if(fread(shdrs, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum) {
        printf("Ftrace: Error to read section header\n");
        free(shdrs);
        fclose(fp);
        return ;
    }

    // read shstrtab
    Elf32_Shdr *shstrtab_shdr = &shdrs[ehdr.e_shstrndx];
    char *shstrtab = malloc(shstrtab_shdr->sh_size);
    fseek(fp, shstrtab_shdr->sh_offset, SEEK_SET);
    int res = fread(shstrtab, shstrtab_shdr->sh_size, 1, fp);
    assert(res == 1);

    // find symtab and strtab
    Elf32_Shdr *symtab_shdr = NULL, *strtab_shdr = NULL;
    for(int i=0; i<ehdr.e_shnum; i++) {
        char *name = &shstrtab[shdrs[i].sh_name]; // index of shstrtab
        if(strcmp(name, ".symtab") == 0) {
            symtab_shdr = &shdrs[i];
        } else if(strcmp(name, ".strtab") == 0) {
            strtab_shdr = &shdrs[i];
        }
    }

    if(!symtab_shdr || !strtab_shdr) {
        printf("Ftrace: Do not find symtab or strtab\n");
        free(shstrtab);
        free(shdrs);
        fclose(fp);
        return ;
    }

    // read strtab
    char *strtab = malloc(strtab_shdr->sh_size);
    fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
    res = fread(strtab, strtab_shdr->sh_size, 1, fp);
    assert(res == 1);

    // read symtab
    int num_syms = symtab_shdr->sh_size / sizeof(Elf32_Sym);
    Elf32_Sym *syms = malloc(symtab_shdr->sh_size);
    fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
    res = fread(syms, sizeof(Elf32_Sym), num_syms, fp);
    assert(res == num_syms);

    func_count = 0;
    for(int i=0; i<num_syms; i++) {
        unsigned char type = ELF32_ST_TYPE(syms[i].st_info);
        if(type == STT_FUNC && syms[i].st_name != 0 && syms[i].st_size > 0) {
            func_count++;
        }
    }

    if(func_count == 0) {
        printf("Ftrace: never find func sym\n");
        free(strtab);
        free(syms);
        free(shstrtab);
        free(shdrs);
        fclose(fp);
        return ;
    }

    func_table = malloc(func_count * sizeof(FunctionSymbol));
    int idx = 0;

    for(int i=0; i<num_syms; i++) {
        unsigned char type = ELF32_ST_TYPE(syms[i].st_info);
        if(type == STT_FUNC && syms[i].st_name != 0 && syms[i].st_size > 0) {
            func_table[idx].name = strdup(&strtab[syms[i].st_name]);
            func_table[idx].addr = syms[i].st_value;
            func_table[idx].size = syms[i].st_size;
            idx++;
        }
    }

    ftrace_enabled = true;
    printf("Ftrace: Load %d funcs from %s\n", func_count, elf_file);

    free(strtab);
    free(syms);
    free(shstrtab);
    free(shdrs);
    fclose(fp);
}

void ftrace_exec(uint32_t pc, uint32_t dnpc, uint32_t rs1, uint32_t rd, uint32_t imm, uint32_t op) { //op=1 jal, op=2 jalr
    if(!ftrace_enabled) return ;

    if(op == 2 && rs1 == 1 && rd == 0 && imm == 0 && call_depth > 0) {
        call_depth--;
        const char *current_func = find_function_name(pc);
        const char *ret_to_func = find_function_name(dnpc);

        printf("0x%08x:", pc);
        for(int i=0; i<call_depth; i++) printf("  ");
        if(current_func && ret_to_func) {
            printf("ret  [%s] (0x%08x)\n", ret_to_func, dnpc);
        } else if(current_func) {
            printf("ret  [0x%08x]\n", dnpc);
        } else {
            printf("ret  [0x%08x]\n", dnpc);
        }
    } else if((op == 1 || op == 2)) {
        const char *caller_name = find_function_name(pc);
        const char *callee_name = find_function_name(dnpc);

        if(call_depth < MAX_CALL_DEPTH) {
            call_depth++;
        }

        printf("0x%08x:", pc);
        for(int i=0; i<call_depth-1; i++) printf("  ");
        if(caller_name && callee_name) {
            printf("call [%s] (0x%08x)\n", callee_name, dnpc);
        } else if(callee_name) {
            printf("call [%s] (0x%08x)\n", callee_name, dnpc);
        } else {
            printf("call [0x%08x]\n", dnpc);
        }
        
    }
}
