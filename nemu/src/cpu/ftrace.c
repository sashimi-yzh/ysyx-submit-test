#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>
#include <string.h>
#include <common.h>

#define NR_FL  2048
#define RET "00008067"

typedef struct func_list
{
    char func_name[512];
    uint32_t start_addr;
    uint32_t end_addr;
}FL;

static Elf32_Sym *syms = NULL;
static char *strs = NULL;
static int sym_count = 0;

static FL fl_pool[NR_FL] = {};
static int fl_lenth = 0;

static char space_str[4] = {};
static int space_len = 0;

const char* get_symbol_type(unsigned char type) {
    switch(type) {
        case STT_NOTYPE: return "NOTYPE";
        case STT_OBJECT: return "OBJECT";
        case STT_FUNC: return "FUNC";
        case STT_SECTION: return "SECTION";
        case STT_FILE: return "FILE";
        case STT_COMMON: return "COMMON";
        case STT_TLS: return "TLS";
        default: return "UNKNOWN";
    }
}

int init_ftrace(const char *path) { // 只运行一次

    if (!path) {
        fprintf(stderr, "Path is NULL\n");
        return 1;
    }

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    void *map = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    unsigned char *e_ident = (unsigned char *)map;
    if (e_ident[EI_MAG0] != ELFMAG0 || 
        e_ident[EI_MAG1] != ELFMAG1 || 
        e_ident[EI_MAG2] != ELFMAG2 || 
        e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Not an ELF file\n");
        munmap(map, size);
        close(fd);
        return 1;
    }

    Elf32_Ehdr *ehdr = (Elf32_Ehdr *)map;
    
    Elf32_Shdr *shdr = (Elf32_Shdr *)((char *)map + ehdr->e_shoff);
    
    Elf32_Shdr *symtab = NULL, *strtab = NULL;
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            symtab = &shdr[i];
            strtab = &shdr[symtab->sh_link];
            break;
        }
    }
    
    if (!symtab || !strtab) {
        printf("No symbol table found in the file\n");
        munmap(map, size);
        close(fd);
        return 0;
    }

    syms = malloc(symtab->sh_size);
    strs = malloc(strtab->sh_size);

    memcpy(syms, (char *)map + symtab->sh_offset, symtab->sh_size);
    sym_count = symtab->sh_size / sizeof(Elf32_Sym);
    
    memcpy(strs, (char *)map + strtab->sh_offset, strtab->sh_size);

    int j = 0;

    for (int i = 0; i < sym_count; i++) {
        Elf32_Sym *sym = &syms[i];
        const char *name = strs + sym->st_name;
        
        if (*name == '\0' || sym->st_shndx == SHN_UNDEF) {
            continue;
        }
        
        unsigned char type = ELF32_ST_TYPE(sym->st_info);
        
        if(type == STT_FUNC && j < NR_FL){
            strcpy(fl_pool[j].func_name, name);
            fl_pool[j].start_addr = sym->st_value;
            fl_pool[j].end_addr = sym->st_value + sym->st_size;
            j++;
        }

    }

    fl_lenth = j;
    munmap(map, size);
    close(fd);
    return 0;
}


// int main(int argc, char *argv[]){
    
//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
//         return 1;
//     }

//     init_trace(argv[1]);

//     // // 打印表头
//     printf("%-8s %-8s %s\n", "Value", "Type", "Name");
//     printf("---------------- ------- ----------------------------\n");
    
//     for(int i = 0; i < fl_lenth; i++){

//         printf("%08x %-10s %08x\n", 
//             fl_pool[i].start_addr,
//             fl_pool[i].func_name,
//             fl_pool[i].end_addr);
//     }
// }


void ftrace_call(vaddr_t pc, vaddr_t dnpc, uint32_t inst) {

    uint32_t jarl_func = inst & 0x0000707F;
    uint32_t jal_func = inst & 0x0000007F;

    if(jarl_func == 0x00000067 || jal_func == 0x0000006F){
        for(int i = 0; i < fl_lenth; i++){
            if(fl_pool[i].start_addr == dnpc){
                log_write("%08x: %scall [%s@%08x]\n", pc, space_str, fl_pool[i].func_name, dnpc);
                space_str[space_len] = ' ';
                space_len = 1;
                break;
            }
        }
    }
}


void ftrace_ret(uint32_t inst, vaddr_t pc){

    if(inst == 0x00008067){
        for(int i = 0; i < fl_lenth; i++){
            if(pc < fl_pool[i].end_addr && pc > fl_pool[i].start_addr){
                space_str[space_len] = '\0';
                space_len = 0;
                log_write("%08x: %sret %s\n", pc, space_str, fl_pool[i].func_name);
            }
        }
    }
}

