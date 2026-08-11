#include <isa.h>
#include <npc/diagnostics.h>

#ifdef CONFIG_FTRACE

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  vaddr_t entry;
  vaddr_t limit;
  char *name;
} TraceFunction;

typedef struct {
  TraceFunction *functions;
  size_t count;
  size_t capacity;
  unsigned int depth;
  bool enabled;
} FunctionTrace;

static FunctionTrace trace = {0};

static void read_exact(FILE *file, void *buffer, size_t size, const char *what) {
  Assert(fread(buffer, 1, size, file) == size, "ftrace: cannot read %s", what);
}

static void seek_to(FILE *file, long offset, const char *what) {
  Assert(fseek(file, offset, SEEK_SET) == 0, "ftrace: cannot seek %s", what);
}

static void *load_section(FILE *file, const Elf32_Shdr *section) {
  if (section->sh_size == 0) return NULL;
  void *content = malloc(section->sh_size);
  Assert(content != NULL, "ftrace: out of memory while loading ELF section");
  seek_to(file, (long)section->sh_offset, "ELF section");
  read_exact(file, content, section->sh_size, "ELF section");
  return content;
}

static void reserve_function() {
  if (trace.count < trace.capacity) return;
  size_t next_capacity = trace.capacity == 0 ? 32 : trace.capacity * 2;
  void *expanded = realloc(trace.functions, next_capacity * sizeof(TraceFunction));
  Assert(expanded != NULL, "ftrace: cannot grow function index");
  trace.functions = (TraceFunction *)expanded;
  trace.capacity = next_capacity;
}

static void record_function(const Elf32_Sym *symbol, const char *string_table) {
  const char *source_name = string_table + symbol->st_name;
  if (*source_name == '\0') return;

  reserve_function();
  size_t name_size = strlen(source_name) + 1;
  char *owned_name = (char *)malloc(name_size);
  Assert(owned_name != NULL, "ftrace: cannot store function name");
  memcpy(owned_name, source_name, name_size);

  TraceFunction *function = &trace.functions[trace.count ++];
  function->entry = (vaddr_t)symbol->st_value;
  function->limit = function->entry + (vaddr_t)symbol->st_size;
  function->name = owned_name;
}

static void import_symbol_table(
    FILE *file, const Elf32_Shdr *sections, size_t section_count, size_t index) {
  const Elf32_Shdr *symbols_header = &sections[index];
  if (symbols_header->sh_type != SHT_SYMTAB ||
      symbols_header->sh_entsize != sizeof(Elf32_Sym) ||
      symbols_header->sh_link >= section_count) return;

  const Elf32_Shdr *strings_header = &sections[symbols_header->sh_link];
  if (strings_header->sh_type != SHT_STRTAB) return;

  Elf32_Sym *symbols = (Elf32_Sym *)load_section(file, symbols_header);
  char *strings = (char *)load_section(file, strings_header);
  if (symbols == NULL || strings == NULL) {
    free(symbols);
    free(strings);
    return;
  }

  size_t count = symbols_header->sh_size / sizeof(*symbols);
  for (size_t item = 0; item < count; item ++) {
    const Elf32_Sym *symbol = &symbols[item];
    bool is_function = ELF32_ST_TYPE(symbol->st_info) == STT_FUNC;
    bool valid_name = symbol->st_name < strings_header->sh_size;
    if (is_function && valid_name) record_function(symbol, strings);
  }

  free(strings);
  free(symbols);
}

static int compare_function_entry(const void *left, const void *right) {
  vaddr_t a = ((const TraceFunction *)left)->entry;
  vaddr_t b = ((const TraceFunction *)right)->entry;
  return a < b ? -1 : a > b ? 1 : 0;
}

static const TraceFunction *lookup_function(vaddr_t address) {
  size_t lower = 0;
  size_t upper = trace.count;
  while (lower < upper) {
    size_t middle = lower + (upper - lower) / 2;
    if (trace.functions[middle].entry <= address) {
      lower = middle + 1;
    } else {
      upper = middle;
    }
  }
  if (lower == 0) return NULL;

  const TraceFunction *candidate = &trace.functions[lower - 1];
  bool exact_entry = candidate->entry == address;
  bool inside_range = candidate->limit > candidate->entry && address < candidate->limit;
  return exact_entry || inside_range ? candidate : NULL;
}

static const char *function_name(vaddr_t address) {
  const TraceFunction *function = lookup_function(address);
  return function == NULL ? "???" : function->name;
}

void init_ftrace(const char *elf_path) {
  if (elf_path == NULL) {
    Log("ftrace disabled: no ELF image");
    return;
  }

  FILE *file = fopen(elf_path, "rb");
  Assert(file != NULL, "ftrace: cannot open '%s'", elf_path);

  Elf32_Ehdr header;
  read_exact(file, &header, sizeof(header), "ELF header");
  bool valid_magic = memcmp(header.e_ident, ELFMAG, SELFMAG) == 0;
  bool is_elf32 = header.e_ident[EI_CLASS] == ELFCLASS32;
  Assert(valid_magic && is_elf32, "ftrace: '%s' is not an ELF32 file", elf_path);
  Assert(header.e_shentsize == sizeof(Elf32_Shdr),
      "ftrace: unsupported section header size in '%s'", elf_path);

  size_t table_size = (size_t)header.e_shnum * sizeof(Elf32_Shdr);
  Elf32_Shdr *sections = (Elf32_Shdr *)malloc(table_size);
  Assert(sections != NULL, "ftrace: cannot allocate section table");
  seek_to(file, (long)header.e_shoff, "section table");
  read_exact(file, sections, table_size, "section table");

  for (size_t index = 0; index < header.e_shnum; index ++) {
    import_symbol_table(file, sections, header.e_shnum, index);
  }
  free(sections);
  fclose(file);

  qsort(trace.functions, trace.count, sizeof(TraceFunction), compare_function_entry);
  trace.enabled = trace.count != 0;
  if (trace.enabled) {
    Log("ftrace indexed %zu functions from %s", trace.count, elf_path);
  } else {
    Log("ftrace disabled: no function symbols in %s", elf_path);
  }
}

void ftrace_trace(vaddr_t pc, uint32_t instruction, vaddr_t next_pc) {
  if (!trace.enabled) return;

  uint32_t opcode = instruction & 0x7f;
  int rd = BITS(instruction, 11, 7);
  int rs1 = BITS(instruction, 19, 15);

  if (opcode == 0x6f && (rd == 1 || rd == 5)) {
    trace_write(TRACE_FTRACE, FMT_WORD ": %*scall [%s@" FMT_WORD "]\n", pc, (int)(trace.depth * 2), "", function_name(next_pc), next_pc);
    trace.depth++;
  } else if (opcode == 0x67) {
    if (rd == 0 && rs1 == 1) {
      if (trace.depth != 0) trace.depth--;
      trace_write(TRACE_FTRACE, FMT_WORD ": %*sret  [%s]\n", pc, (int)(trace.depth * 2), "", function_name(pc));
    } else if (rd == 1 || rd == 5) {
      trace_write(TRACE_FTRACE, FMT_WORD ": %*scall [%s@" FMT_WORD "]\n", pc, (int)(trace.depth * 2), "", function_name(next_pc), next_pc);
      trace.depth++;
    }
  }
}

#else

void init_ftrace(const char *elf_path) { (void)elf_path; }
void ftrace_trace(vaddr_t pc, uint32_t instruction, vaddr_t next_pc) {
  (void)pc;
  (void)instruction;
  (void)next_pc;
}

#endif
