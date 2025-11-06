#include <proc.h>
#include <elf.h>
#include <fs.h>
#include <stdio.h>

#define ELF_MAGIC "\x7f" "ELF"

extern uint8_t ramdisk_start;
extern uint8_t ramdisk_end;

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
# define Elf_Word Elf64_Word
# define Elf_Addr Elf64_Addr
# define Elf_Off  Elf64_Off
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
# define Elf_Word Elf32_Word
# define Elf_Addr Elf32_Addr
# define Elf_Off  Elf32_Off
#endif

// 这里不是通过fopen打开文件进行操作，而是通过ramdisk_read和ramdisk_write函数来进行操作
static uintptr_t loader(PCB *pcb, const char *filename) {

  // 打印文件长度
  printf("文件长度为 0x%x\n",((&ramdisk_end) - (&ramdisk_start)));
  // 检查ELF文件头
  Elf_Ehdr elf_header;
  ramdisk_read(&elf_header, 0, sizeof(Elf_Ehdr));
  
  // check valid elf
  assert((*(uint32_t *)elf_header.e_ident == 0x464c457f));

  // 获取program header的信息
  Elf_Phdr *phdr = (Elf_Phdr*)malloc(elf_header.e_phnum * sizeof(Elf_Phdr));

  ramdisk_read(phdr, elf_header.e_phoff, sizeof(Elf_Phdr)*elf_header.e_phnum);
  //循环遍历LOAD类型并加载到内存中
  //加载区间     [VirtAddr, VirtAddr + MemSiz)
  //.bss清零区间 [VirtAddr + FileSiz, VirtAddr + MemSiz)
  int program_headers_num = elf_header.e_phnum;
  for(int i = 0;i < program_headers_num;i++){
    if (phdr[i].p_type == PT_LOAD) {
      ramdisk_read((void*)phdr[i].p_vaddr, phdr[i].p_offset, phdr[i].p_memsz);
      // set .bss with zeros
      memset((void*)(phdr[i].p_vaddr+phdr[i].p_filesz), 0, phdr[i].p_memsz - phdr[i].p_filesz);
    }
  }

  return elf_header.e_entry;
}


void naive_uload(PCB *pcb, const char *filename) {;
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %d", entry);
  ((void(*)())entry) ();
}

