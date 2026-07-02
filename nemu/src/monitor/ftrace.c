#include <isa.h>

#ifdef CONFIG_FTRACE

#include <elf.h>
#include <stdio.h>

typedef struct {
  vaddr_t start;
  vaddr_t end;
  char *name;
} FuncSymbol;

static FuncSymbol *func_symbols = NULL;
static size_t nr_func_symbols = 0;
static size_t cap_func_symbols = 0;
static bool ftrace_ready = false;
static int ftrace_depth = 0;

static void *load_section(FILE *fp, const Elf32_Shdr *shdr) {
  if (shdr->sh_size == 0) return NULL;

  void *buf = malloc(shdr->sh_size);
  Assert(buf != NULL, "ftrace: failed to allocate %u bytes", shdr->sh_size);

  Assert(fseek(fp, shdr->sh_offset, SEEK_SET) == 0,
      "ftrace: failed to seek to section offset 0x%x", shdr->sh_offset);
  size_t nread = fread(buf, 1, shdr->sh_size, fp);
  Assert(nread == shdr->sh_size,
      "ftrace: failed to read section (read %zu, expect %u)", nread, shdr->sh_size);

  return buf;
}

static void append_func_symbol(vaddr_t start, uint32_t size, const char *name) {
  if (name == NULL || name[0] == '\0') return;

  if (nr_func_symbols == cap_func_symbols) {
    size_t new_cap = (cap_func_symbols == 0 ? 64 : cap_func_symbols * 2);
    FuncSymbol *new_buf = realloc(func_symbols, new_cap * sizeof(FuncSymbol));
    Assert(new_buf != NULL, "ftrace: failed to expand symbol table to %zu entries", new_cap);
    func_symbols = new_buf;
    cap_func_symbols = new_cap;
  }

  size_t len = strlen(name);
  char *name_copy = malloc(len + 1);
  Assert(name_copy != NULL, "ftrace: failed to allocate symbol name");
  memcpy(name_copy, name, len + 1);

  func_symbols[nr_func_symbols].start = start;
  func_symbols[nr_func_symbols].end = start + (vaddr_t)size;
  func_symbols[nr_func_symbols].name = name_copy;
  nr_func_symbols ++;
}

static const char *lookup_func(vaddr_t addr) {
  const char *range_match = NULL;
  for (size_t i = 0; i < nr_func_symbols; i ++) {
    if (func_symbols[i].start == addr) {
      return func_symbols[i].name;
    }
    if (range_match == NULL &&
        func_symbols[i].end > func_symbols[i].start &&
        addr >= func_symbols[i].start && addr < func_symbols[i].end) {
      range_match = func_symbols[i].name;
    }
  }

  return range_match ? range_match : "???";
}

void init_ftrace(const char *elf_file) {
  if (elf_file == NULL) {
    Log("ftrace: no ELF file is given, ftrace will be disabled");
    return;
  }

  FILE *fp = fopen(elf_file, "rb");
  Assert(fp != NULL, "ftrace: can not open ELF file '%s'", elf_file);

  Elf32_Ehdr ehdr;
  size_t nread = fread(&ehdr, 1, sizeof(ehdr), fp);
  Assert(nread == sizeof(ehdr), "ftrace: failed to read ELF header from '%s'", elf_file);

  Assert(memcmp(ehdr.e_ident, ELFMAG, SELFMAG) == 0,
      "ftrace: '%s' is not a valid ELF file", elf_file);
  Assert(ehdr.e_ident[EI_CLASS] == ELFCLASS32,
      "ftrace: only ELF32 is supported currently (file: %s)", elf_file);

  Assert(fseek(fp, ehdr.e_shoff, SEEK_SET) == 0,
      "ftrace: failed to seek section headers in '%s'", elf_file);

  size_t shdr_bytes = ehdr.e_shnum * sizeof(Elf32_Shdr);
  Elf32_Shdr *shdr = malloc(shdr_bytes);
  Assert(shdr != NULL, "ftrace: failed to allocate section header table");

  nread = fread(shdr, 1, shdr_bytes, fp);
  Assert(nread == shdr_bytes,
      "ftrace: failed to read section headers from '%s'", elf_file);

  for (int i = 0; i < ehdr.e_shnum; i ++) {
    if (shdr[i].sh_type != SHT_SYMTAB) continue;
    if (shdr[i].sh_entsize != sizeof(Elf32_Sym)) continue;
    if (shdr[i].sh_link >= (Elf32_Word)ehdr.e_shnum) continue;

    Elf32_Shdr *strtab_shdr = &shdr[shdr[i].sh_link];
    if (strtab_shdr->sh_type != SHT_STRTAB) continue;

    Elf32_Sym *symtab = (Elf32_Sym *)load_section(fp, &shdr[i]);
    char *strtab = (char *)load_section(fp, strtab_shdr);
    if (symtab == NULL || strtab == NULL) {
      free(symtab);
      free(strtab);
      continue;
    }

    size_t nr_sym = shdr[i].sh_size / sizeof(Elf32_Sym);
    for (size_t j = 0; j < nr_sym; j ++) {
      if (ELF32_ST_TYPE(symtab[j].st_info) != STT_FUNC) continue;
      if (symtab[j].st_name >= strtab_shdr->sh_size) continue;
      append_func_symbol((vaddr_t)symtab[j].st_value, symtab[j].st_size, strtab + symtab[j].st_name);
    }

    free(symtab);
    free(strtab);
  }

  free(shdr);
  fclose(fp);

  if (nr_func_symbols > 0) {
    ftrace_ready = true;
    Log("ftrace: loaded %zu function symbols from %s", nr_func_symbols, elf_file);
  } else {
    Log("ftrace: no function symbols found in %s, ftrace will be disabled", elf_file);
  }
}

void ftrace_call(vaddr_t pc, vaddr_t target) {
  if (!ftrace_ready) return;

  const char *name = lookup_func(target);
  ftrace_write(FMT_WORD ": %*scall [%s@" FMT_WORD "]\n",
      pc, ftrace_depth * 2, "", name, target);
  ftrace_depth ++;
}

void ftrace_ret(vaddr_t pc) {
  if (!ftrace_ready) return;

  if (ftrace_depth > 0) ftrace_depth --;
  const char *name = lookup_func(pc);
  ftrace_write(FMT_WORD ": %*sret  [%s]\n", pc, ftrace_depth * 2, "", name);
}

#else

void init_ftrace(const char *elf_file) { (void)elf_file; }
void ftrace_call(vaddr_t pc, vaddr_t target) { (void)pc; (void)target; }
void ftrace_ret(vaddr_t pc) { (void)pc; }

#endif
