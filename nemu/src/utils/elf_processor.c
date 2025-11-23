#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

Elf32_Shdr *symtab = NULL;
Elf32_Shdr *strtab = NULL;
FILE *file = NULL;

char* find_function_name(uint32_t addr) {
    if (fseek(file, symtab->sh_offset, SEEK_SET) != 0) {
        perror("fseek");
        return NULL;
    }

    int num_symbols = symtab->sh_size / symtab->sh_entsize;
    Elf32_Sym *symbols = malloc(symtab->sh_size);
    if (!symbols) {
        perror("malloc");
        return NULL;
    }

    if (fread(symbols, symtab->sh_size, 1, file) != 1) {
        perror("fread");
        free(symbols);
        return NULL;
    }

    char *strtab_data = malloc(strtab->sh_size);
    if (!strtab_data) {
        perror("malloc");
        free(symbols);
        return NULL;
    }

    if (fseek(file, strtab->sh_offset, SEEK_SET) != 0) {
        perror("fseek");
        free(symbols);
        free(strtab_data);
        return NULL;
    }

    if (fread(strtab_data, strtab->sh_size, 1, file) != 1) {
        perror("fread");
        free(symbols);
        free(strtab_data);
        return NULL;
    }

    char *result = NULL;
    for (int i = 0; i < num_symbols; i++) {
        if (ELF32_ST_TYPE(symbols[i].st_info) == STT_FUNC) {
            Elf32_Addr start = symbols[i].st_value;
            Elf32_Addr end = start + symbols[i].st_size;
            if (addr >= start && addr < end) {
                result = strdup(&strtab_data[symbols[i].st_name]);
                break;
            }
        }
    }

    free(symbols);
    free(strtab_data);
    return result;
}

void init_elf(const char *elf_file){
    file = fopen(elf_file, "rb");
    if (!file) {
        perror("fopen");
    }

    Elf32_Ehdr ehdr;
    if(fread(&ehdr, sizeof(ehdr), 1, file) != 1){
        //perror("fread");
    }
    

    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file\n");
        fclose(file);
    }

    fseek(file, ehdr.e_shoff, SEEK_SET);
    Elf32_Shdr *shdrs = malloc(ehdr.e_shentsize * ehdr.e_shnum);

    if(fread(shdrs, ehdr.e_shentsize, ehdr.e_shnum, file) != 1){
        //perror("fread");
    }

    for (int i = 0; i < ehdr.e_shnum; i++) {
        if (shdrs[i].sh_type == SHT_SYMTAB) {
            symtab = &shdrs[i];
        } else if (shdrs[i].sh_type == SHT_STRTAB && i != ehdr.e_shstrndx) {
            strtab = &shdrs[i];
        }
    }
}
