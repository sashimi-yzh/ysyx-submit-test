#include <proc.h>
#include <elf.h>
#include <ramdisk.h>
#include <fs.h>

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
# define Elf_Shdr Elf64_Shdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
# define Elf_Shdr Elf32_Shdr
#endif

#if defined(__ISA_NATIVE__)
#define EXPECT_EM EM_X86_64
#elif defined(__ISA_RISCV32__)
#define EXPECT_EM EM_RISCV
#endif

static uintptr_t mem_translate(PCB *pcb, uintptr_t vaddr) {
  // TEMP: Sv32 only
  uintptr_t vpn1 = (vaddr >> 22) & 0x3ff;
  uintptr_t pt1_addr = (uintptr_t)pcb->as.ptr;
  uintptr_t pte1_addr = pt1_addr | (vpn1 << 2);
  uintptr_t pte1 = *(uintptr_t *)pte1_addr;

  if ((pte1 & 1) == 0) return 0;

  uintptr_t vpn0 = (vaddr >> 12) & 0x3ff;
  uintptr_t pt0_addr = (pte1 << 2) & ~0xfff;
  uintptr_t pte0_addr = pt0_addr | (vpn0 << 2);
  uintptr_t pte0 = *(uintptr_t *)pte0_addr;

  if (pte0 & 1) {
    return ((pte0 << 2) & ~0xfff) | (vaddr & 0xfff);
  } else {
    return 0;
  }
}

static uintptr_t loader(PCB *pcb, const char *filename) {
  // open file
  int fd = fs_open(filename, 0, 0);

  // read ELF header
  Elf_Ehdr ehdr;
  assert(fs_read(fd, &ehdr, sizeof(ehdr)) == sizeof(ehdr));

  // check magic number
  assert(ehdr.e_ident[EI_MAG0] == ELFMAG0 &&
         ehdr.e_ident[EI_MAG1] == ELFMAG1 &&
         ehdr.e_ident[EI_MAG2] == ELFMAG2 &&
         ehdr.e_ident[EI_MAG3] == ELFMAG3);

  // check 32/64 
#ifdef __LP64__
  assert(ehdr.e_ident[EI_CLASS] == ELFCLASS64);
#else
  assert(ehdr.e_ident[EI_CLASS] == ELFCLASS32);
#endif

  // check ISA
  assert(ehdr.e_machine == EXPECT_EM);

  // read program header
  size_t phoff = ehdr.e_phoff;
  assert(phoff);
  size_t phentsize = ehdr.e_phentsize;

  size_t phnum = ehdr.e_phnum;
  if (phnum == PN_XNUM) {
    Elf_Shdr shdr;
    assert(ehdr.e_shoff);
    fs_lseek(fd, ehdr.e_shoff, SEEK_SET);
    assert(fs_read(fd, &shdr, sizeof(shdr)) == sizeof(shdr));
    phnum = shdr.sh_info;
  }
  assert(phnum);

  pcb->max_brk = 0;

  Elf_Phdr phdr;
  for (size_t i = 0; i < phnum; ++i) {
    fs_lseek(fd, phoff + i * phentsize, SEEK_SET);
    assert(fs_read(fd, &phdr, sizeof(phdr)) == sizeof(phdr));
    if (phdr.p_vaddr == 0) continue;
    fs_lseek(fd, phdr.p_offset, SEEK_SET);

    assert(phdr.p_filesz <= phdr.p_memsz);
    uintptr_t vaddr_end = phdr.p_vaddr + phdr.p_memsz;
    pcb->max_brk = MAX(pcb->max_brk, ROUNDUP(vaddr_end, PGSIZE));
    for (uintptr_t vaddr = ROUNDDOWN(phdr.p_vaddr, PGSIZE); vaddr < vaddr_end; vaddr += PGSIZE) {
      uintptr_t paddr = mem_translate(pcb, vaddr);
      if (!paddr) {
        paddr = (uintptr_t)new_page(1);
        map(&pcb->as, (void *)vaddr, (void *)paddr, PROT_RWX);
      }

      // fill file
      uintptr_t off = vaddr < phdr.p_vaddr ? phdr.p_vaddr - vaddr : 0;
      uintptr_t sz = MIN(PGSIZE - off, phdr.p_filesz);
      if (sz) {
        assert(fs_read(fd, (void *)(paddr + off), sz) == sz);
        phdr.p_filesz -= sz;
        phdr.p_memsz -= sz;
        off += sz;
      }

      // fill 0
      sz = MIN(PGSIZE - off, phdr.p_memsz);
      if (sz) {
        memset((void *)(paddr + off), 0, sz);
        phdr.p_memsz -= sz;
      }
    }
    assert(phdr.p_filesz == 0);
    assert(phdr.p_memsz == 0);
  }

  assert(ehdr.e_entry);
  fs_close(fd);
  return ehdr.e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

void context_uload(PCB *pcb, const char *filename, char *const argv[], char *const envp[]) {
  // create default memory map
  protect(&pcb->as);

  // map stack memory
  void *ustack_top = new_page(8);
  for (void *stack_vaddr = pcb->as.area.end - STACK_SIZE; stack_vaddr < pcb->as.area.end; stack_vaddr += PGSIZE) {
    map(&pcb->as, stack_vaddr, ustack_top, PROT_RW);
    ustack_top += PGSIZE;
  }

  // pass args
  int argc = 0, envc = 0, len = 0;
  for (; argv[argc]; ++argc) len += strlen(argv[argc]) + 1;
  for (; envp[envc]; ++envc) len += strlen(envp[envc]) + 1;
  len = ROUNDUP(len, sizeof(uintptr_t));

  char *strtab = ustack_top - len;
  char **sp = (char **)strtab;
  for (int i = envc; i >= 0; --i) {
    if (envp[i]) {
      strcpy(strtab, envp[i]);
      *--sp = strtab;
      strtab += strlen(envp[i]) + 1;
    } else {
      *--sp = NULL;
    }
  }
  for (int i = argc; i >= 0; --i) {
    if (argv[i]) {
      strcpy(strtab, argv[i]);
      *--sp = strtab;
      strtab += strlen(argv[i]) + 1;
    } else {
      *--sp = NULL;
    }
  }
  *(uintptr_t *)--sp = argc;

  // load program
  uintptr_t entry = loader(pcb, filename);
  Area kstack = { .start = pcb->stack, .end = pcb->stack + STACK_SIZE };
  Context *ctx = ucontext(&pcb->as, kstack, (void *)entry);
  // NOTE: 为什么不直接在用户栈上构造上下文呢？
  // 不过考虑到有从GPRx中读出栈指针的约定，还是就这么办吧。

  ctx->GPRx = (uintptr_t)pcb->as.area.end - ((uintptr_t)ustack_top - (uintptr_t)sp);
  pcb->cp = ctx;
}
