#include <npc.h>
#include <common.h>
#include <elf.h>

typedef struct {
  char name[64];
  uint32_t start;
  uint32_t size;
} Symbol;

Symbol symbol_table[1024];
static int symbol_cnt = 0;

void init_ftrace(const char *elf_file) {
  int ret = 0;
  FILE *fp = fopen(elf_file, "rb");
  
  Elf32_Ehdr ehdr; //elf头
  ret = fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp);
  assert(ret == 1);

  Elf32_Shdr shdr[ehdr.e_shnum]; //节区头表
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  ret = fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
  assert(ret == ehdr.e_shnum);

  Elf32_Sym *symtab = NULL;
  char *strtab = NULL;
  int sym_cnt = 0;

  for (int i = 0; i < ehdr.e_shnum; i ++) {
    if (shdr[i].sh_type == SHT_SYMTAB) {
      symtab = (Elf32_Sym *)malloc(shdr[i].sh_size); //符号表
      fseek(fp, shdr[i].sh_offset, SEEK_SET);
      ret = fread(symtab, shdr[i].sh_size, 1, fp);
      assert (ret == 1);
      sym_cnt = shdr[i].sh_size / sizeof(Elf32_Sym);
  } else if (shdr[i].sh_type == SHT_STRTAB && i != ehdr.e_shstrndx) {
      strtab = (char *)malloc(shdr[i].sh_size); //字符串表
      fseek(fp, shdr[i].sh_offset, SEEK_SET);
      ret = fread(strtab, shdr[i].sh_size, 1, fp);
      assert(ret == 1);
    }
  }

  for (int i = 0; i < sym_cnt; i ++) {
    if (ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC && symtab[i].st_size > 0) {
      strncpy(symbol_table[symbol_cnt].name, &strtab[symtab[i].st_name], 63);
      // printf("symbol[%d]: %s\n", symbol_cnt, symbol_table[symbol_cnt].name);
      symbol_table[symbol_cnt].start = symtab[i].st_value;
      symbol_table[symbol_cnt].size = symtab[i].st_size;
      symbol_cnt ++;
    }
  }
  free(symtab);
}

static const char *get_func(uint32_t addr) {
  for (int i = 0; i < symbol_cnt; i ++) {
    // printf("addr: 0x%08x symbol[%d]: %s start: 0x%08x end: 0x%08x\n", addr, i, symbol_table[i].name, symbol_table[i].start, symbol_table[i].start + symbol_table[i].size);
    if (addr >= symbol_table[i].start && addr < symbol_table[i].start + symbol_table[i].size) return symbol_table[i].name;
  }
  return NULL;
}

int depth = 0;

void ftrace_print(uint32_t pc, uint32_t target, int rd, int rs1) {
  bool is_call = false;

  if (rd == 1) is_call = true;
  else if (rd == 0 && rs1 == 1) is_call = false;

  const char *funt_name = get_func(target);
  if (funt_name == NULL) return;

#ifdef CONFIG_FTRACE
  {
    if (is_call) {
      log_write("0x%08x: %*s call [%s@0x%08x]\n", pc, depth * 2, "", funt_name, target);
      depth ++;
    } else {
      depth --;
      if (depth < 0) depth = 0;
      log_write("0x%08x: %*s ret  [%s]\n", pc, depth * 2, "", funt_name);
    }
  }
#endif
}
