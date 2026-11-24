#include <fcntl.h>
#include <unistd.h>
#include <common.h>
#include <elf.h>

typedef struct {
    Elf32_Sym *symtab;   // symbol table
    char *strtab;        // string table
    int num_symbols;     // size of symbol tables
} ElfSymbols;

ElfSymbols *symbol_cache;

void load_elf_symbols(const char *elf_file) {
    if (elf_file == NULL) {
        printf("No ELF file provided for symbol loading.\n");
        return;
    }

    int fd = open(elf_file, O_RDONLY);
    if (fd < 0) {
        perror("open failed for elf file\n");
        exit(EXIT_FAILURE);
    }

    // read elf header
    Elf32_Ehdr ehdr = {0};
    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
        perror("read ELF header");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // read section headers
    Elf32_Shdr shdr = {0};
    lseek(fd, ehdr.e_shoff, SEEK_SET);

    Elf32_Shdr symtab = {0}, strtab = {0};
    int found_symtab = 0, found_strtab = 0;
    for (int i = 0; i < ehdr.e_shnum; i++) {
        if (read(fd, &shdr, sizeof(shdr)) != sizeof(shdr)) {
            perror("read section header");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // find `.symtab`
        if (shdr.sh_type == SHT_SYMTAB) {
            symtab = shdr;
            found_symtab = 1;
        }
        // find `.strtab`
        if (shdr.sh_type == SHT_STRTAB && i != ehdr.e_shstrndx) {
            strtab = shdr;
            found_strtab = 1;
        }
    }

    if (!found_symtab || !found_strtab) {
        fprintf(stderr, "No symbol table found in %s\n", elf_file);
        close(fd);
        return;
    }

    // read `.strtab`
    char *strtab_data = malloc(strtab.sh_size);
    lseek(fd, strtab.sh_offset, SEEK_SET);
    if(read(fd, strtab_data, strtab.sh_size) != strtab.sh_size) {
        perror("read strtab");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // read `.symtab`
    Elf32_Sym *symtab_data = malloc(symtab.sh_size);
    lseek(fd, symtab.sh_offset, SEEK_SET);
    if(read(fd, symtab_data, symtab.sh_size) != symtab.sh_size) {
        perror("read symtab");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    // populate symbol_cache
    symbol_cache = malloc(sizeof(ElfSymbols));
    symbol_cache->symtab = symtab_data;
    symbol_cache->strtab = strtab_data;
    symbol_cache->num_symbols = symtab.sh_size / sizeof(Elf32_Sym);
}

const char* find_symbol_by_address(vaddr_t address) {
    const char *best_match = NULL;
    unsigned long best_addr = 0;

    for (int i = 0; i < symbol_cache->num_symbols; i++) {
        Elf32_Sym *sym = &symbol_cache->symtab[i];
        
        // the address is always bigger than start address of the function
        if (ELF32_ST_TYPE(sym->st_info) == STT_FUNC) {
            if (sym->st_value <= address && sym->st_value > best_addr) {
                best_addr = sym->st_value;
                best_match = symbol_cache->strtab + sym->st_name;
            }
        }
    }
    
    return best_match ? best_match : "Unknown";
}

void init_elf(char *elf_file) {
    load_elf_symbols(elf_file);
}