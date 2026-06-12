#include "debug.h"
#include "utils.h"
#include <common.h>
#include <elf.h>
#include <stdio.h>
#include <string.h>

typedef MUXDEF(CONFIG_ISA64, Elf64_Ehdr, Elf32_Ehdr) elf_ehdr_t;
typedef MUXDEF(CONFIG_ISA64, Elf64_Phdr, Elf32_Phdr) elf_phdr_t;
typedef MUXDEF(CONFIG_ISA64, Elf64_Shdr, Elf32_Shdr) elf_shdr_t;
typedef MUXDEF(CONFIG_ISA64, Elf64_Sym, Elf32_Sym) elf_sym_t;

#define ELF_ST_TYPE MUXDEF(CONFIG_ISA64, ELF64_ST_TYPE, ELF32_ST_TYPE)
#define SH_MAX 64
#define SH_NAME_MAX 128
#define SYM_MAX 524288
#define SYM_NAME_MAX 128

static elf_ehdr_t eh;
static elf_shdr_t sh[SH_MAX];
static char sh_name[SH_MAX][SH_NAME_MAX];
static word_t nr_sh = 0;
static elf_sym_t sym[SYM_MAX];
static char sym_name[SYM_MAX][SYM_NAME_MAX];
static word_t nr_sym = 0;

static size_t fread_assert(void *ptr, size_t byte, FILE *stream) {
  size_t ret = fread(ptr, 1, byte, stream);
  Assert(ret == byte, "fread fail: expect %lu bytes but %lu byte", byte, ret);
  return byte;
}

static char *fstrncpy(char *dest, FILE *stream, unsigned long n) {
  int i;
  for (i = 0; i < n; i++) {
    fread_assert(dest, 1, stream);
    if (*dest++ == '\0') {
      break;
    }
  }
  *dest = '\0';
  return dest;
}

static void parse_elf_header(FILE *elf) {
  fread_assert(&eh, sizeof(eh), elf);
  Log("ELF header: off: %u  size: %u  num: %u  strndx: %u\n", 
      eh.e_shoff, eh.e_shentsize, eh.e_shnum, eh.e_shstrndx);
}

static void parse_section_header(FILE *elf) {
  nr_sh = eh.e_shnum;
  Assert(nr_sh <= SH_MAX, "SH_MAX is not enough. At least %u", nr_sh);
  int i;
  fseek(elf, eh.e_shoff, SEEK_SET);
  for (i = 0; i < nr_sh; i++) {
    elf_shdr_t *s = sh + i;
    fread_assert(s, eh.e_shentsize, elf);
  }

  // Section header name
  word_t shstrtab;
  if (eh.e_shstrndx == SHN_XINDEX) {
    Assert(sh[0].sh_link != 0, "Invalid shstrtab");
    shstrtab = sh[0].sh_link;
  } else {
    shstrtab = sh[eh.e_shstrndx].sh_offset;
  }
  for (i = 0; i < nr_sh; i++) {
    fseek(elf, shstrtab + sh[i].sh_name, SEEK_SET);
    fstrncpy(sh_name[i], elf, SH_NAME_MAX);
    log_write("Section header %d: "
        "name: %s  addr: %#x  off: %#x  size: %u  entsize: %u\n", 
        i, sh_name[i], sh[i].sh_addr, sh[i].sh_offset, 
        sh[i].sh_size, sh[i].sh_entsize);
  }
}

static void parse_symbol_table(FILE *elf) {
  int i;
  word_t sh_symtab = 0;
  for (i = 0; i < nr_sh; i++) {
    if (sh[i].sh_type == SHT_SYMTAB) {
      sh_symtab = i;
      break;
    }
  }
  Assert(i < nr_sh, "symtab is not found");
  nr_sym = sh[sh_symtab].sh_size / sh[sh_symtab].sh_entsize;
  Assert(nr_sym <= SYM_MAX, "SYM_MAX is not enough. At least %u", nr_sym);
  fseek(elf, sh[sh_symtab].sh_offset, SEEK_SET);
  for (i = 0; i < nr_sym; i++) {
    elf_sym_t *s = sym + i;
    fread_assert(s, sh[sh_symtab].sh_entsize, elf);
  } 

  // Symbol table name
  word_t sh_strtab = sh[sh_symtab].sh_link;
  word_t strtab = sh[sh_strtab].sh_offset;
  for (i = 0; i < nr_sym; i++) {
    fseek(elf, strtab + sym[i].st_name, SEEK_SET);
    fstrncpy(sym_name[i], elf, SYM_NAME_MAX);
    log_write("Symbol %d: name: %s  info: %u  value: %#x  size: %u\n", 
        i, sym_name[i], ELF_ST_TYPE(sym[i].st_info), sym[i].st_value, sym[i].st_size);
  } 
}

void init_elf(const char *elf_file) {
  if (elf_file == NULL) {
    Log("No ELF file");
    return;
  }
  FILE *elf = fopen(elf_file, "r");
  Assert(elf, "Cant open ELF file");
  Log("ELF file: %s", elf_file);

  // ELF header
  parse_elf_header(elf);

  // Section header
  parse_section_header(elf);

  // Symbol table
  parse_symbol_table(elf);
}

const char *get_function_name(paddr_t addr) {
  int i;
  for (i = 0; i < nr_sym; i++) {
    if (ELF_ST_TYPE(sym[i].st_info) == STT_FUNC &&
        sym[i].st_size > 0 &&
        addr >= sym[i].st_value && 
        addr < (sym[i].st_value + sym[i].st_size)) {
      return sym_name[i];
    }
  }
  return NULL;
}
