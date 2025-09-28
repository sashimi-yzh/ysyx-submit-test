#include <common.h>
#include <elf.h>

#ifdef CONFIG_ISA64
#define ElfN(type) Elf64_ ## type
#define ELFN(macro) ELF64_ ## macro
#else
#define ElfN(type) Elf32_ ## type
#define ELFN(macro) ELF32_ ## macro
#endif

#ifndef CONFIG_TARGET_AM
static FILE *fp = NULL;

static ElfN(Ehdr) eh;

#define STRTAB_BUF_SIZE 2048
#define MAX_SYMBOL 256

static char strtab[STRTAB_BUF_SIZE];
static char *elf_no_name = "<anonymous symbol>";
ElfSymbol elf_symbol_list[MAX_SYMBOL];
word_t elf_symbol_list_size = 0;

static void read_symbols() {
  ElfN(Shdr) shent;

  /* Read section header string table */
  fseek(fp, eh.e_shoff + eh.e_shstrndx * eh.e_shentsize, SEEK_SET);
  Assert(fread(&shent, sizeof(shent), 1, fp) == 1,
         "Error when reading section header string table entry");
  Assert(shent.sh_type == SHT_STRTAB, "Reading wrong section header string table entry");
  char shstrtab[shent.sh_size];
  fseek(fp, shent.sh_offset, SEEK_SET);
  Assert(fread(shstrtab, shent.sh_size, 1, fp) == 1,
         "Error when reading section header string table buffer");
  
  /* Read section table, find '.strtab' and '.symtab' */
  ElfN(Shdr) strtab_ent = { .sh_offset = 0 }, symtab_ent = { .sh_offset = 0 };

  fseek(fp, eh.e_shoff, SEEK_SET);
  Assert(fread(&shent, sizeof(shent), 1, fp) == 1, "Error when reading section table entry 0");
  size_t shnum = eh.e_shnum ? eh.e_shnum : shent.sh_size;
  for (size_t i = 1; i < shnum; ++i) {
    fseek(fp, eh.e_shoff + i * eh.e_shentsize, SEEK_SET);
    Assert(fread(&shent, sizeof(shent), 1, fp) == 1, "Error when reading section table entry %lu", i);
    // printf("%lu %u %u %u %u %u\n", i, shent.sh_name, shent.sh_type, shent.sh_addr, shent.sh_offset, shent.sh_size);
    if (shent.sh_type == SHT_STRTAB && !strcmp(shstrtab + shent.sh_name, ".strtab")) { // find .strtab entry
      strtab_ent = shent;
    } else if (shent.sh_type == SHT_SYMTAB && !strcmp(shstrtab + shent.sh_name, ".symtab")) { // find .symtab entry
      symtab_ent = shent;
    }
  }

  Assert(strtab_ent.sh_offset, "No .strtab section in elf file");
  Assert(symtab_ent.sh_offset, "No .symtab section in elf file");

  // Read string table
  fseek(fp, strtab_ent.sh_offset, SEEK_SET);
  Assert(fread(strtab, strtab_ent.sh_size, 1, fp) == 1,
         "Error when reading symbol string table buffer");
  
  // reorgnize symbols
  size_t symtab_size = symtab_ent.sh_size / symtab_ent.sh_entsize;
  Assert(symtab_ent.sh_entsize == sizeof(ElfN(Sym)), "Incompatible size of symbol table entry");
  ElfN(Sym) symtab[symtab_size];
  fseek(fp, symtab_ent.sh_offset, SEEK_SET);
  Assert(fread(symtab, symtab_ent.sh_entsize, symtab_size, fp) == symtab_size, "Error when reading symbol table");
  for (size_t i = 0; i < symtab_size; ++i) {
    // printf("%lu %s %d %u %u\n", i, strtab + symtab[i].st_name, (int)symtab[i].st_info, symtab[i].st_value, symtab[i].st_size);
    unsigned char st_type = ELFN(ST_TYPE)(symtab[i].st_info);
    if (st_type == STT_FUNC) {
      elf_symbol_list[elf_symbol_list_size++] = (ElfSymbol) {
        symtab[i].st_name ? strtab + symtab[i].st_name : elf_no_name, // name
        symtab[i].st_value, // addr
        symtab[i].st_size, // size
        ELF_SYM_FUNC
      };
    } else if (st_type == STT_OBJECT) {
      elf_symbol_list[elf_symbol_list_size++] = (ElfSymbol) {
        symtab[i].st_name ? strtab + symtab[i].st_name : elf_no_name, // name
        symtab[i].st_value, // addr
        symtab[i].st_size, // size
        ELF_SYM_OBJECT
      };
    }
  }

  // for (word_t i = 0; i < elf_symbol_list_size; ++i) {
  //   printf("%s %x %u %s\n",
  //     elf_symbol_list[i].name,
  //     elf_symbol_list[i].addr,
  //     elf_symbol_list[i].size,
  //     elf_symbol_list[i].type == ELF_SYM_FUNC ? "FUNC" : "OBJECT"
  //   );
  // }
}

void init_elf(const char *elf_file) {
  if (elf_file == NULL) return;
  fp = fopen(elf_file, "rb");
  Assert(fp, "Can not open '%s'", elf_file);

  /* Read elf header */
  Assert(fread(&eh, sizeof(eh), 1, fp) == 1, "Error when reading elf header");

  Assert(eh.e_ident[EI_MAG0] == ELFMAG0 &&
         eh.e_ident[EI_MAG1] == ELFMAG1 &&
         eh.e_ident[EI_MAG2] == ELFMAG2 &&
         eh.e_ident[EI_MAG3] == ELFMAG3, 
         "Invalid elf file '%s'", elf_file);
  
  Assert(eh.e_ident[EI_CLASS] == MUXDEF(CONFIG_ISA64, ELFCLASS64, ELFCLASS32),
         "Elf file architecture(32/64-bit) incompatible.");
  
  Assert(eh.e_shoff, "Elf file has no section header.");

  read_symbols();

  Log("ELF file loaded from %s", elf_file);
}

#endif