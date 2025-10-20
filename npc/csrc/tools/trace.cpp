#include <elf.h>
#include "../include/common.h"
#include "../include/trace.h"

static int ringbuf_index = 0;

char ringbuf[RINGBUF_MAX][128];

void init_ringbuf() {
    memset(ringbuf, 0, sizeof(ringbuf));
}

void iringbuf(uint32_t thispc, uint32_t inst) {
    uint32_t pc = thispc;
    char logbuf[128];

    uint8_t code[4];
    //char buffer[20];
    code[0] = (uint8_t)(inst & 0xFF);
    code[1] = (uint8_t)((inst >> 8) & 0xFF);
    code[2] = (uint8_t)((inst >> 16) & 0xFF);
    code[3] = (uint8_t)((inst >> 24) & 0xFF);

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


typedef struct {
    char name[20];
    paddr_t addr;
    Elf32_Xword size;
} Symbol;

Symbol *symbol = NULL;
size_t func_sum = 0;

void parse_elf(char *elf_file)
{

    FILE *fp;
    fp = fopen(elf_file, "rb");
    if (fp == NULL) {
        printf("Failed to open the ELF file: %s\n", elf_file);
        exit(1);
    }
	
    Elf32_Ehdr edhr;
    
    if(fread(&edhr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        printf("fread error\n");
        fclose(fp);
        exit(1);
    }

    if(edhr.e_ident[0] != 0x7f || edhr.e_ident[1] != 'E' || edhr.e_ident[2] != 'L' ||edhr.e_ident[3] != 'F'){
        printf("The opened file isn't an elf file!\n");
        fclose(fp);
        exit(1);
    }
    
    fseek(fp, edhr.e_shoff, SEEK_SET);

    Elf32_Shdr shdr;
    char *string_table = NULL;
    
    for(int i = 0; i < edhr.e_shnum; i++){

        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) != 1) {
            printf("fread error\n");
            fclose(fp);
            exit(1);
        }
        if(shdr.sh_type == SHT_STRTAB)
        {
            string_table = (char*)malloc(shdr.sh_size);
            fseek(fp, shdr.sh_offset, SEEK_SET);
            if(fread(string_table, shdr.sh_size, 1, fp) != 1) {
                printf("fread error\n");
                fclose(fp);
                exit(1);
            }
        }
    }
    
    
    fseek(fp, edhr.e_shoff, SEEK_SET);
    
    for(int i = 0; i < edhr.e_shnum; i++){

        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) != 1) {
                printf("fread error\n");
                fclose(fp);
                exit(1);
            }

        if(shdr.sh_type == SHT_SYMTAB){
            fseek(fp, shdr.sh_offset, SEEK_SET);

            Elf32_Sym sym;

            size_t sym_count = shdr.sh_size / shdr.sh_entsize;
            symbol = (Symbol*)malloc(sizeof(Symbol) * sym_count);

            for(size_t j = 0; j < sym_count; j++){
                if(fread(&sym, sizeof(Elf32_Sym), 1, fp) != 1) {
                    printf("fread error\n");
                    fclose(fp);
                    exit(1);
                }
                if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC){
                    const char *name = string_table + sym.st_name;
                    strncpy(symbol[func_sum].name, name, sizeof(symbol[func_sum].name) - 1);
                    symbol[func_sum].name[sizeof(symbol[func_sum].name) - 1] = '\0';
                    symbol[func_sum].addr = sym.st_value;
                    symbol[func_sum].size = sym.st_size;
                    func_sum++;
                }
            }
        }
    }
    fclose(fp);
    free(string_table);
}

int depth = 1;
extern "C" void call_func(uint32_t pc, uint32_t dnpc){
    int i = 0;
    while(i < func_sum){
        if(dnpc >= symbol[i].addr && dnpc < (symbol[i].addr + symbol[i].size)) break;
        i++;
    }
    printf("\033[37m0x%08x:", pc);
    for (int k = 0; k < depth; k++) {       //彩色缩进
        if (k % 7 == 0) printf("\033[31m |"); 
        else if (k % 7 == 1) printf("\033[32m |"); 
        else if (k % 7 == 2) printf("\033[33m |"); 
        else if (k % 7 == 3) printf("\033[34m |"); 
        else if (k % 7 == 4) printf("\033[36m |"); 
    }
    printf("call  [%s@0x%08x]\n", symbol[i].name, dnpc);
    depth++;
}

extern "C" void ret_func(uint32_t pc){
    int i = 0;
    for(; i < func_sum; i++){
        if(pc >= symbol[i].addr && pc < (symbol[i].addr + symbol[i].size)) break;
    }

    depth--;

    printf("\033[37m0x%08x:", pc);
    for (int k = 0; k < depth; k++) {       //彩色缩进
        if (k % 7 == 0) printf("\033[31m |"); 
        else if (k % 7 == 1) printf("\033[32m |"); 
        else if (k % 7 == 2) printf("\033[33m |"); 
        else if (k % 7 == 3) printf("\033[34m |"); 
        else if (k % 7 == 4) printf("\033[36m |"); 
    }
    printf("ret  [%s]\n", symbol[i].name);
}



