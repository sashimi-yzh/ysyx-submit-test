#ifndef __ELFREAD_H_
#define __ELFREAD_H_

#include <elf.h>
#include <stdio.h>

#define NBIT 32       //64位
#if(NBIT == 32)
//#error "32位的还未实现好, 和gcc的readelf还有不同"
//#error "32位的实现的部分也未经测试!"
#endif 

#if(NBIT == 64)
typedef Elf64_Shdr ElfN_Shdr;
typedef Elf64_Ehdr ElfN_Ehdr;
typedef uint64_t uintN_t;
typedef Elf64_Sym ElfN_Sym;
typedef Elf64_Word ElfN_Word;
typedef Elf64_Half ElfN_Half;
#elif(NBIT == 32)
typedef Elf32_Shdr ElfN_Shdr;
typedef Elf32_Ehdr ElfN_Ehdr;
typedef uint32_t uintN_t;
typedef Elf32_Sym ElfN_Sym;
typedef Elf32_Word ElfN_Word;
typedef Elf32_Half ElfN_Half;
#else
#error "Only Support 32-bit and 64-bit ELF"
#endif 

#define ELFN_ST_TYPE ELF64_ST_TYPE
#define ELFN_ST_BIND ELF64_ST_BIND
#define ELFN_ST_VISIBILITY ELF32_ST_VISIBILITY

ElfN_Ehdr* read_elf_header(FILE* fp, ElfN_Ehdr* dest);
ElfN_Shdr* read_section_header(FILE* fp,  ElfN_Shdr* dest, const ElfN_Ehdr* elf_header, int index);
ElfN_Sym* read_symtab(FILE* fp, ElfN_Sym* dest, const ElfN_Shdr* symtab_hdr);


void print_elf_header(ElfN_Ehdr elf_header);
void print_section_headers(FILE* fp, const ElfN_Ehdr* elf_header, const ElfN_Shdr* section_headers, int sh_num);
void print_symtab(FILE* fp, const ElfN_Sym* symtab, const ElfN_Shdr* strtab_hdr, int symtab_size);


char* get_section_header_name(FILE *fp, char *dest, const ElfN_Ehdr* elf_header, const ElfN_Shdr *section_headers, int index);
char* get_section_flag_name(char *dest, uintN_t sh_flags);
char* get_symtab_entry_name(FILE *fp, char *dest, const ElfN_Shdr *strtab_hdr, const ElfN_Sym *symtab);
char* get_symtab_entry_ndx_name(char* buf, uint16_t st_shndx);


const char* get_elf_type(ElfN_Half e_type);
const char* get_elf_osabi(const unsigned char* e_ident);
const char* get_elf_machine(ElfN_Half e_machine);
const char* get_section_type_name(ElfN_Word sh_type);
const char* get_symtab_entry_type_name(unsigned char st_info);
const char* get_symtab_entry_bind_name(unsigned char st_info);
const char* get_symtab_entry_vis_name(unsigned char st_other);


#endif
