#include <common.h>
#include <elf.h>
FILE *elf_fp = NULL;
#define MAX_FUNC_DEPTH 1900
#define MAX_FUNC_NAME 128
typedef struct {
  vaddr_t addr;
  uint32_t funcsize;
  char funcname[MAX_FUNC_NAME];
} Addr2funcname;
int func_num = 0;
Addr2funcname addr2funcname[MAX_FUNC_DEPTH]; 
void init_ftrace(const char *elf_file) {
  if(elf_file == NULL) return ;
  elf_fp = fopen(elf_file, "rb");
  assert(elf_fp);

  // 先读取 ELF Header
  Elf32_Ehdr ehdr;
  int ret = fread(&ehdr, sizeof(Elf32_Ehdr), 1, elf_fp);
  assert(ret == 1);
  Elf32_Shdr shdr[ehdr.e_shnum];
  fseek(elf_fp, ehdr.e_shoff, SEEK_SET);
  ret = fread(&shdr, ehdr.e_shentsize, ehdr.e_shnum, elf_fp);
  assert(ret == ehdr.e_shnum);
  char *shstrtab = (char *)malloc(shdr[ehdr.e_shstrndx].sh_size);
  assert(shstrtab != NULL);
  fseek(elf_fp, shdr[ehdr.e_shstrndx].sh_addr + shdr[ehdr.e_shstrndx].sh_offset, SEEK_SET);
  ret = fread(shstrtab, sizeof(char), shdr[ehdr.e_shstrndx].sh_size, elf_fp);
  assert(ret == shdr[ehdr.e_shstrndx].sh_size);
  
  // 遍历 shstrtab
  Elf32_Off shstr_off = 1;
  char symtab_str[8] = ".symtab";
  uint32_t symtab_name = 0;
  char strtab_str[8] = ".strtab";
  uint32_t strtab_name = 0;
  while((symtab_name == 0) || (strtab_name == 0)) {
    if(shstrtab[shstr_off] == '\0') break;
    if(strcmp(shstrtab + shstr_off, symtab_str) == 0) {
      symtab_name = shstr_off;
    }
    if(strcmp(shstrtab + shstr_off, strtab_str) == 0) {
      strtab_name = shstr_off;
    }
    // printf("%s\n", shstrtab + shstr_off);
    shstr_off += strlen(shstrtab + shstr_off) + 1;
  }
  free(shstrtab);
  assert(symtab_name != 0 && strtab_name != 0);
  // 读取 Section Headers 获取符号表Off
  Elf32_Off symtab_off = 0;
  uint32_t symtab_size = 0;
  Elf32_Off strtab_off = 0;
  uint32_t strtab_size = 0;
  int shidx = 0;
  while((symtab_off == 0) || (strtab_off == 0)) {
    if(shidx == ehdr.e_shnum) break;
    if(shdr[shidx].sh_name == symtab_name) {
      symtab_off = shdr[shidx].sh_addr + shdr[shidx].sh_offset;
      symtab_size = shdr[shidx].sh_size;
    }
    if(shdr[shidx].sh_name == strtab_name) {
      strtab_off = shdr[shidx].sh_addr + shdr[shidx].sh_offset;
      strtab_size = shdr[shidx].sh_size;
    }
    shidx++;
  }
  // printf("symtab_off: 0x%08x\nstrtab_off: 0x%08x\n", symtab_off, strtab_off);
  assert(symtab_off != 0 && strtab_off != 0);
  // 筛选 TYPE == func 的符号，获取每个函数的地址、大小和名字
  const int symtab_num = symtab_size / sizeof(Elf32_Sym);
  Elf32_Sym symtab[symtab_num];
  fseek(elf_fp, symtab_off, SEEK_SET);
  ret = fread(symtab, symtab_size, 1, elf_fp);
  assert(ret == 1);
  char *strtab = (char *)malloc(strtab_size);
  assert(strtab != NULL);
  fseek(elf_fp, strtab_off, SEEK_SET);
  ret = fread(strtab, strtab_size, 1, elf_fp);
  assert(ret == 1);
  int i = 0;
  for(; i < symtab_num; i++) {
    if(ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC) {
      addr2funcname[func_num].addr = symtab[i].st_value;
      addr2funcname[func_num].funcsize = symtab[i].st_size  ;
      // printf("0x%08x\n", strtab_off + symtab[i].st_name);
      assert(strlen(strtab + symtab[i].st_name) < MAX_FUNC_NAME);
      strcpy(addr2funcname[func_num].funcname, strtab + symtab[i].st_name);
      // printf("%s\n", addr2funcname[func_num].funcname);
      func_num++;
    }
  }
  free(strtab);
}
static int space_width = 0;
void ftrace_call(int pc, int dnpc){
  #ifdef FTRACE_COND
  int i = 0;
  for(; i < func_num; i++) {
    if(dnpc == addr2funcname[i].addr) {
      printf("0x%08x: %*scall [%s@0x%08x]\n", pc, space_width, "", addr2funcname[i].funcname, addr2funcname[i].addr);
      space_width+=2;
      return ;
    }
  }
  #endif
}

void ftrace_ret(int pc){
  #ifdef FTRACE_COND
  int i = 0;
  for(; i < func_num; i++) {
    if(pc >= addr2funcname[i].addr && pc < (addr2funcname[i].addr + addr2funcname[i].funcsize)){
      space_width-=2;
      printf("0x%08x: %*sret  [%s]\n", pc, space_width, "", addr2funcname[i].funcname);
      return ;
    }
  }
  #endif
}