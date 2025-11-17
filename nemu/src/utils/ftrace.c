#include <ftrace.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <isa.h>

#ifdef CONFIG_FTRACE
#include <elf.h>
#define NUM_STRTB 4
#define ST_FUNC 18      //elf symtable type for func
#define SEG_STR_SYM 3
#define SEG_STR 2
#define SEG_SYM 1

#define IN_RANGE(BEGIN,END,VAL) (((BEGIN)<(VAL))&&((END)>(VAL)))

int elf_check_file(Elf32_Ehdr *header){
    return memcmp(header->e_ident,ELFMAG, 4);
}
static int space_len = 1;
char* read_string_table (uint32_t offset, uint32_t size,FILE *fp);
Elf32_Sym* read_symbol_table (uint32_t offset, uint32_t size, uint32_t entsize, FILE *fp);
FtraceMeta* read_func_meta(Elf32_Ehdr* ehdr,FILE *fp);


FtraceMeta *ftrace_meta = NULL;

void init_ftrace(char* elf_file){
    FILE *fp = fopen(elf_file, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open '%s': %s\n", elf_file, strerror(errno));
        return;
    }

    Elf32_Ehdr ehdr;
    if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1) {
        fprintf(stderr, "fread: %s\n", strerror(errno));
        fclose(fp);
        return;
    }

    if (elf_check_file(&ehdr)) {
        fprintf(stderr, "'%s' is not an ELF file\n", elf_file);
        fclose(fp);
        return;
    }
    /* Parse the rest of the ELF file here. */
    ftrace_meta = read_func_meta(&ehdr,fp);
    #ifdef CONFIG_FTRACE_DEBUG
    for(int i =0;i<ftrace_meta->size;i++){
        func_meta fm = ftrace_meta->fm_entries[i];
        printf("name: %s \t %x \n",fm.name,fm.addr);
    }
    #endif
    /* Don't forget to close the file. */
    fclose(fp);
    return;
}

FtraceMeta* read_func_meta(Elf32_Ehdr* ehdr,FILE *fp){
    if(fseek(fp,ehdr->e_shoff,SEEK_SET)==-1) {
        fprintf(stderr, "segment table offset is invalid\n");
        return NULL;
    }
    Elf32_Shdr * shdr = calloc(ehdr->e_shnum,ehdr->e_shentsize);
    size_t num = fread(shdr,ehdr->e_shentsize,ehdr->e_shnum,fp);
    if(num!=ehdr->e_shnum){
        fprintf(stderr, "segment table is invalid, expect %d items, but got %ld \n", 
                ehdr->e_shnum,num);
    }
    uint32_t symtb_offset = 0; 
    uint32_t symtb_size = 0;
    uint32_t symtb_entsize = 0;     // symbol table each entry size;
    char seg_flag = 0;                  // 000x for symtab, 00x0 for strtab
    char* strtb_contents=""; 

    for(int i=0;i<num;i++){
        if (seg_flag==SEG_STR_SYM){
            break;
        }
        if(shdr[i].sh_type == SHT_SYMTAB){
            symtb_offset = shdr[i].sh_offset; 
            symtb_size = shdr[i].sh_size;
            symtb_entsize = shdr[i].sh_entsize;
            seg_flag|=SEG_SYM;
        }

        if (shdr[i].sh_type == SHT_STRTAB){
            // filter shstrtable
            if (ehdr->e_shstrndx != SHN_UNDEF && i == ehdr->e_shstrndx){
                continue;
            }
            char *content = read_string_table(shdr[i].sh_offset,shdr[i].sh_size,fp);
            if (!content) {
                fprintf(stderr, "read string table %d failed.\n",shdr[i].sh_name);
                return NULL;
            }
            strtb_contents = malloc(shdr[i].sh_size);
            memcpy(strtb_contents,content,shdr[i].sh_size);
            // printf("string table in %d, content: %s size %d\n",
            //     shdr[i].sh_name,content+1,shdr[i].sh_size);
            free(content);
            seg_flag|=SEG_STR;
        }
    }

    Elf32_Sym *sym_entries = read_symbol_table(symtb_offset,symtb_size,symtb_entsize,fp);
    if (!sym_entries) return NULL;
    uint32_t n_symbol = symtb_size/symtb_entsize; 
    func_meta *func_entries = calloc(sizeof(func_meta),n_symbol);
    
    
    /* read symbol name from string table, address from symbol table */
    int fm_index = 0;
    for(int i=0;i<n_symbol;i++){
        Elf32_Sym entry = sym_entries[i];
        if (entry.st_info == ST_FUNC){
            func_meta fm;
            char* name = malloc(128);
            strcpy(name,strtb_contents+entry.st_name);
            fm.addr = entry.st_value;
            fm.name = name;
            fm.size = entry.st_size;
            func_entries[fm_index] = fm;
            fm_index++;
        }
    }
    FtraceMeta * ft = malloc(sizeof(ftrace_meta));
    ft->fm_entries = func_entries;
    ft->size = fm_index;
    free(sym_entries);
    free(shdr);
    return ft;
}

char* read_string_table (uint32_t offset, uint32_t size,FILE *fp){
    char *content = calloc(size,1);
    if(fseek(fp,offset,SEEK_SET)==-1) {
        fprintf(stderr, "string table offset is invalid\n");
        return NULL;
    }
    char* res = fgets(content,size,fp);
    if (! res){
        fprintf(stderr, "string table is invalid\n");
        fclose(fp);
        free(content);
        return NULL;
    }
    return content;
}

Elf32_Sym* read_symbol_table (uint32_t offset, uint32_t size,uint32_t entsize, FILE *fp){
    if(fseek(fp,offset,SEEK_SET)==-1) {
        fprintf(stderr, "symbol table offset is invalid\n");
        return NULL;
    }

    Elf32_Sym* sym_entries = malloc(size);
    uint32_t num = fread(sym_entries,entsize,size/entsize,fp);
    if (num != size/entsize){
        fprintf(stderr, "symbol table is invalid,should be %d entries, but got %d\n",
                size/entsize,num);
        fclose(fp);
        free(sym_entries);
        return NULL;
    }
    return sym_entries;
}

int is_jrtype(char* inst){
    return strcmp(inst,"jalr")==0 || strcmp(inst,"jr")==0;
}


int is_jal(char* inst){
    return strcmp(inst,"jal")==0 ;
}

int is_ret(char* inst){
    return strcmp(inst,"ret")==0 ;
}

char* func_name( uint32_t addr ){
    for (int i=0;i<ftrace_meta->size;i++){
        func_meta entry = ftrace_meta->fm_entries[i];
        if (entry.addr == addr)
            return entry.name;
    }
    return NULL;
}

char* find_ret_name(uint32_t addr ){
    char *res = "";
    for (int i=0;i<ftrace_meta->size;i++){
        func_meta entry = ftrace_meta->fm_entries[i];
        if(IN_RANGE(entry.addr ,entry.addr+entry.size,addr)){
            res= entry.name;
            break;
        }
    }
    return res;
}

void ftrace_message(uint32_t pc, uint32_t dnpc,char* inst){
    char* name = "";
    char* spaces = malloc(space_len+1);
    memset(spaces,' ',space_len); 
    spaces[space_len] = '\0';
    if (is_jal(inst)){
        if ((name = func_name(dnpc))==NULL) return;
        log_write("0x%x: %s %s [%s@0x%x]\n",pc,spaces,inst,name,dnpc);
        space_len++;
    }else if (is_jrtype(inst)){
        if ((name = func_name(dnpc))==NULL) return;
        log_write("0x%x: %s %s[%s@0x%x]\n",pc,spaces,inst,name,dnpc);
        space_len++;
    }else if (is_ret(inst)){
        log_write("0x%x: %s %s[%s]\n",pc,spaces,inst,find_ret_name(dnpc));
        space_len = (space_len>0)?space_len-1:1;
    }
    free(spaces);
    
    
    return;
}

#endif