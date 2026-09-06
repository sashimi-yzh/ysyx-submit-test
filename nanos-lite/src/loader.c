#include "common.h"
#include "debug.h"
#include "fs.h"
#include "memory.h"
#include <elf.h>
#include <proc.h>
#include <stdint.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static uintptr_t loader(PCB *pcb, const char *filename) {
  int fd = fs_open(filename, 0, 0);

  Elf32_Ehdr ehdr;
  size_t size = fs_read(fd, &ehdr, sizeof(Elf32_Ehdr));
  if (size != sizeof(Elf32_Ehdr)) {
    panic("loader read szie not equ to size of ehdr");
  }

  // Check ELF magic number: 0x7f 'E' 'L' 'F'
  if (ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' ||
      ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F' ||
      ehdr.e_type != ET_EXEC) {
    panic("the file format isnot elf execuable file");
  }

  Elf32_Phdr phdr;
  uint32_t e_phoff = ehdr.e_phoff;
  uint32_t e_phnum = ehdr.e_phnum;
  uint32_t e_entry = ehdr.e_entry;

  Log("ELF header: e_phoff = 0x%x, e_phnum = %d, e_entry = 0x%x", e_phoff,
      e_phnum, e_entry);

  for (int i = 0; i < e_phnum; i++) {
    uint32_t offset = i * sizeof(Elf32_Phdr);
    size = fs_lseek(fd, e_phoff + offset, SEEK_SET);
    size = fs_read(fd, &phdr, sizeof(Elf32_Phdr));
    if (size != sizeof(Elf32_Phdr)) {
      panic("loader read size not equ to size of phdr");
    }

    // Log("phdr: p_type = 0x%x, p_offset = 0x%x, p_vaddr = 0x%x, p_paddr =
    // 0x%x, p_filesz = 0x%x, p_memsz = 0x%x, p_flags = 0x%x", phdr.p_type,
    // phdr.p_offset, phdr.p_vaddr, phdr.p_paddr, phdr.p_filesz, phdr.p_memsz,
    // phdr.p_flags);

    if (phdr.p_type == PT_LOAD) {
      uintptr_t seg_start = phdr.p_vaddr;
      size_t filesize = phdr.p_filesz;
      size_t memsize = phdr.p_memsz;
      uintptr_t seg_end = seg_start + memsize;

      Log("Loading segment: p_type=0x%x p_offset=0x%x p_vaddr=0x%x "
          "p_filesz=0x%x p_memsz=0x%x p_flags=0x%x",
          phdr.p_type, phdr.p_offset, phdr.p_vaddr, phdr.p_filesz, phdr.p_memsz,
          phdr.p_flags);

      assert(memsize >= filesize);

      uintptr_t file_end = seg_start + filesize;
      uintptr_t vaddr_min = ROUNDDOWN(seg_start, PGSIZE);
      uintptr_t vaddr_max = ROUNDUP(seg_end, PGSIZE);
      int prot = 0;
      if (phdr.p_flags & PF_R)
        prot |= PTE_R;
      if (phdr.p_flags & PF_W)
        prot |= PTE_W;
      if (phdr.p_flags & PF_X)
        prot |= PTE_X;
      prot |= PTE_U;
      prot |= PTE_A;
      prot |= PTE_D;

      fs_lseek(fd, phdr.p_offset, SEEK_SET);

      for (uintptr_t va = vaddr_min; va < vaddr_max; va += PGSIZE) {
        void *pa = new_page(1);
        memset(pa, 0, PGSIZE);
        map(&pcb->as, (void *)va, pa, prot);

        Log("  Map va = 0x%x to pa = %p (flags = 0x%x)", va, pa, prot);

        // Copy only the file-backed region in this virtual page.
        uintptr_t page_start = va;
        uintptr_t page_end = va + PGSIZE;
        uintptr_t copy_start = MAX(page_start, seg_start);
        uintptr_t copy_end = MIN(page_end, file_end);
        if (copy_start < copy_end) {
          size_t read_sz = copy_end - copy_start;
          size_t page_off = copy_start - page_start;
          fs_read(fd, (char *)pa + page_off, read_sz);
        }
      }
    }
  }
  fs_close(fd);
  return e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  Log("naive uload %s", filename);
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %d", entry);
  ((void (*)())entry)();
}

uintptr_t uload(PCB *pcb, const char *filename) {
  return loader(pcb, filename);
}

Context *syscall_execve(const char *filename, char *argv[], char *envp[]) {
  Log("syscall execve:[%s]", filename);

  if (fs_exist(filename)) {
    context_uload(current, filename, argv, envp);
    return current->cp;
  }

  return NULL;
}
