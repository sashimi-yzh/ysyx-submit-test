#include "tpdef.h"

#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct ftrace_data
{
  paddr_t start;
  paddr_t end;
  char* name;

  struct ftrace_data* next;

} ftrace_d;

ftrace_d* func_info = NULL;


// ftrace elf file infomation initialize
bool init_elf(const char* elf_file)
{
  if (elf_file == NULL) return false;
  printf(ANSI_FMT("[elf file] %s\n", ANSI_FG_BLUE), elf_file);

  int fd = open(elf_file, O_RDONLY);
  if (fd < 0) return false;

  struct stat st; 
  int ret = fstat(fd, &st);
  if (ret < 0) 
  {
    close(fd);
    return false;
  }

  // 映射整个 ELF 文件到内存
  void *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (map == MAP_FAILED)
  {
    close(fd);
    return false;
  }

  Elf32_Ehdr *ehdr = (Elf32_Ehdr *)map;

  if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0)
  {
    printf("[elf file] not a valid elf file.\n");
    munmap(map, st.st_size);
    close(fd);
    return false;
  }

  // 获取节区头表和节区名表
  Elf32_Shdr *shdrs = (Elf32_Shdr *)((char *)map + ehdr->e_shoff);
  const char *shstrtab = (char *)map + shdrs[ehdr->e_shstrndx].sh_offset;
  
  Elf32_Shdr *symtab_hdr = NULL;
  Elf32_Shdr *strtab_hdr = NULL;

  // 遍历所有节区，找到 .symtab 和 .strtab
  for (int i = 0; i < ehdr->e_shnum; ++i) 
  {
      const char *section_name = shstrtab + shdrs[i].sh_name;
      if (strcmp(section_name, ".symtab") == 0)
          symtab_hdr = &shdrs[i];
      else if (strcmp(section_name, ".strtab") == 0)
          strtab_hdr = &shdrs[i];
  }

  // 获取符号表和字符串表数据
  Elf32_Sym *symtab = (Elf32_Sym *)((char *)map + symtab_hdr->sh_offset);
  const char *strtab = (char *)map + strtab_hdr->sh_offset;
  int sym_count = symtab_hdr->sh_size / sizeof(Elf32_Sym);

  ftrace_d* p = NULL;
  for (int i = 0; i < sym_count; ++i) 
  {
      const char *sym_name = strtab + symtab[i].st_name;
      if (ELF64_ST_TYPE(symtab[i].st_info) == 2)
      {
        p = DNEW(ftrace_d);
        p->start = symtab[i].st_value;
        p->end = symtab[i].st_value + symtab[i].st_size;
        p->name = strdup(sym_name);
        p->next = func_info;
        func_info = p;
        
        // debug
        // printf("[%d] %s : Value=0x%x, Size=%u\n",
        //   i, sym_name, symtab[i].st_value, symtab[i].st_size);
      }
  }

    // debug
    //   p = func_info;
    //   while (p != NULL)
    //   {
    //     printf("[ftrace] %s : Start=0x%x, End=0x%x\n",
    //       p->name, p->start, p->end);
    //       p = p->next;
    //   }

  // 清理资源
  munmap(map, st.st_size);
  close(fd);
  return true;
}


// get function name
const char* ftrace_get_name(paddr_t addr)
{
  ftrace_d* p =func_info;
  while (p != NULL)
  {
    if (addr >= p->start && addr < p->end)
    {
      return p->name;
    }
    p = p->next;
  }

  return "???";
}