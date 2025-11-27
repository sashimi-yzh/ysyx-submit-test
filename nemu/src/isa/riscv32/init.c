/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>

#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img [] = {
  0x00000297,  // auipc t0,0
  0x00028823,  // sb  zero,16(t0)
  0x0102c503,  // lbu a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  0xdeadbeef,  // some data
};


typedef struct ftrace_data
{
  paddr_t start;
  paddr_t end;
  char* name;

  struct ftrace_data* next;

} ftrace_d;

ftrace_d* func_info = NULL;

static void restart() {
  /* Set the initial program counter. */
  cpu.pc = 0x80000000;// RESET_VECTOR;

  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
}

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  /* Initialize this virtual computer system. */
  restart();
}


void init_elf(const char* elf_file)
{
  if (elf_file == NULL) return;
  printf("[elf file] %s\n", elf_file);

  int fd = open(elf_file, O_RDONLY);
  assert(fd >= 0);

  struct stat st; 
  int ret = fstat(fd, &st);
  assert(ret >= 0);

  // 映射整个 ELF 文件到内存
  void *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  assert(map != MAP_FAILED);

  Elf32_Ehdr *ehdr = (Elf32_Ehdr *)map;

  if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0)
  {
    printf("[elf file] not a valid elf file.\n");
    munmap(map, st.st_size);
    close(fd);
    return;
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
  // p = func_info;
  // while (p != NULL)
  // {
  //   printf("[ftrace] %s : Value=0x%x, Size=0x%x\n",
  //     p->name, p->start, p->end);
  //     p = p->next;
  // }

  // 清理资源
  munmap(map, st.st_size);
  close(fd);
}


const char* ftrace_get_name(vaddr_t addr)
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