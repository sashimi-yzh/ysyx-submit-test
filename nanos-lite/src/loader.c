#include <proc.h>
#include <elf.h>
#include <fs.h>
// 从ramdisk中`offset`偏移处的`len`字节读入到`buf`中
size_t ramdisk_read(void *buf, size_t offset, size_t len);

// 把`buf`中的`len`字节写入到ramdisk中`offset`偏移处
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

// 返回ramdisk的大小, 单位为字节
size_t get_ramdisk_size();


#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

#if defined(__ISA_AM_NATIVE__)
# define EXPECT_TYPE EM_X86_64
#elif defined(__ISA_X86__)
# define EXPECT_TYPE EM_X86_64  // see /usr/include/elf.h to get the right type
#elif defined(__ISA_RISCV32__) || defined(__ISA_RISCV64__)
# define EXPECT_TYPE EM_RISCV
#else
# error Unsupported ISA
#endif



static uintptr_t loader(PCB *pcb, const char *filename) {
  int fd = fs_open(filename, 0, 0);
  Elf_Ehdr elf;
  //ramdisk_read(&elf, 0, sizeof(Elf_Ehdr));
  fs_read(fd, &elf, sizeof(Elf_Ehdr));
  assert(*(uint32_t *)(&elf)->e_ident == 0x464c457f);
  assert(elf.e_machine == EXPECT_TYPE);

  Elf_Phdr ph[elf.e_phnum];
  //ramdisk_read(ph, elf.e_phoff, sizeof(Elf_Phdr)*elf.e_phnum);
  fs_lseek(fd, elf.e_phoff, SEEK_SET);
  fs_read(fd, ph, sizeof(Elf_Phdr)*elf.e_phnum);

  for(int i=0; i< elf.e_phnum; i++){
  	if(ph[i].p_type == PT_LOAD){
		//ramdisk_read((void*)ph[i].p_vaddr, ph[i].p_offset, ph[i].p_memsz);
    fs_lseek(fd, ph[i].p_offset, SEEK_SET);
    fs_read(fd, (void*)ph[i].p_vaddr, ph[i].p_memsz);
		memset((void*)(ph[i].p_vaddr+ph[i].p_filesz), 0, ph[i].p_memsz - ph[i].p_filesz);
	}
  }
  fs_close(fd);
  return elf.e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

