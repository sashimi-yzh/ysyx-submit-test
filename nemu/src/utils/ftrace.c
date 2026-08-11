#include <utils/ftrace.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

static int call_depth = 0;

static inline int32_t sext(int32_t x, int bits) {
  int32_t m = 1 << (bits - 1);
  return (x ^ m) - m;
}

static inline int32_t jal_imm(uint32_t inst) {
  int32_t imm =
      ((inst >> 31) & 0x1) << 20 |
      ((inst >> 21) & 0x3ff) << 1 |
      ((inst >> 20) & 0x1) << 11 |
      ((inst >> 12) & 0xff) << 12;
  return sext(imm, 21);
}

static inline int rd(uint32_t inst)   { return (inst >> 7)  & 0x1f; }
static inline int rs1(uint32_t inst)  { return (inst >> 15) & 0x1f; }
static inline uint32_t opcode(uint32_t inst) { return inst & 0x7f; }
static inline uint32_t funct3(uint32_t inst) { return (inst >> 12) & 0x7; }

static inline int32_t jalr_imm(uint32_t inst) {
  return (int32_t)inst >> 20; 
}

typedef struct {
  uint32_t addr;   
  uint32_t size;   
  char    *name;  
} FuncSym;

static FuncSym *g_syms   = NULL;
static size_t   g_nsyms  = 0;
static int      g_has_sym = 0;

static void free_syms(void) {
  if (!g_syms) return;
  for (size_t i = 0; i < g_nsyms; i++) free(g_syms[i].name);
  free(g_syms);
  g_syms = NULL;
  g_nsyms = 0;
  g_has_sym = 0;
}

static int cmp_sym_addr(const void *a, const void *b) {
  const FuncSym *x = (const FuncSym *)a;
  const FuncSym *y = (const FuncSym *)b;
  if (x->addr < y->addr) return -1;
  if (x->addr > y->addr) return 1;
  return 0;
}

static const FuncSym *find_func_by_addr(uint32_t addr) {
  if (!g_has_sym || g_nsyms == 0) return NULL;

  size_t l = 0, r = g_nsyms; // [l, r)
  while (l + 1 < r) {
    size_t m = (l + r) / 2;
    if (g_syms[m].addr <= addr) l = m;
    else r = m;
  }
  if (g_syms[l].addr > addr) return NULL;

  uint32_t lo = g_syms[l].addr;
  uint32_t hi = 0;

  if (g_syms[l].size != 0) {
    hi = lo + g_syms[l].size;
    if (addr >= lo && addr < hi) return &g_syms[l];
    return &g_syms[l];
  }

  // size == 0: use next symbol as upper bound
  hi = (l + 1 < g_nsyms) ? g_syms[l + 1].addr : 0xffffffffu;
  if (addr >= lo && addr < hi) return &g_syms[l];

  return NULL;
}

static void add_func_sym(uint32_t addr, uint32_t size, const char *name) {
  if (!name || name[0] == '\0') return;

  FuncSym *p = (FuncSym *)realloc(g_syms, (g_nsyms + 1) * sizeof(FuncSym));
  if (!p) return;
  g_syms = p;

  g_syms[g_nsyms].addr = addr;
  g_syms[g_nsyms].size = size;
  g_syms[g_nsyms].name = strdup(name);
  if (!g_syms[g_nsyms].name) return;

  g_nsyms++;
}

static void extract_funcs_from_symtab(
    const uint8_t *base,
    const Elf32_Shdr *sym_sh,
    const Elf32_Shdr *str_sh) {

  const Elf32_Sym *syms = (const Elf32_Sym *)(base + sym_sh->sh_offset);
  size_t n = sym_sh->sh_size / sizeof(Elf32_Sym);
  const char *strs = (const char *)(base + str_sh->sh_offset);

  for (size_t i = 0; i < n; i++) {
    const Elf32_Sym *s = &syms[i];
    if (ELF32_ST_TYPE(s->st_info) != STT_FUNC) continue;
    if (s->st_value == 0) continue;
    const char *name = strs + s->st_name;
    add_func_sym((uint32_t)s->st_value, (uint32_t)s->st_size, name);
  }
}

static void load_elf_symbols(const char *elf_file) {
  free_syms();

  FILE *fp = fopen(elf_file, "rb");
  if (!fp) {
    printf("[ftrace] failed to open elf: %s\n", elf_file);
    return;
  }

  fseek(fp, 0, SEEK_END);
  long fsz = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  if (fsz <= 0) { fclose(fp); return; }

  uint8_t *buf = (uint8_t *)malloc((size_t)fsz);
  if (!buf) { fclose(fp); return; }

  if (fread(buf, 1, (size_t)fsz, fp) != (size_t)fsz) {
    free(buf);
    fclose(fp);
    return;
  }
  fclose(fp);

  if ((size_t)fsz < sizeof(Elf32_Ehdr)) {
    free(buf);
    return;
  }

  const Elf32_Ehdr *eh = (const Elf32_Ehdr *)buf;

  if (memcmp(eh->e_ident, ELFMAG, SELFMAG) != 0 ||
      eh->e_ident[EI_CLASS] != ELFCLASS32 ||
      eh->e_ident[EI_DATA]  != ELFDATA2LSB) {
    printf("[ftrace] not a supported ELF32 LSB: %s\n", elf_file);
    free(buf);
    return;
  }

  if (eh->e_shoff == 0 || eh->e_shentsize != sizeof(Elf32_Shdr) || eh->e_shnum == 0) {
    printf("[ftrace] no section header in elf: %s\n", elf_file);
    free(buf);
    return;
  }
  if ((size_t)eh->e_shoff + (size_t)eh->e_shnum * sizeof(Elf32_Shdr) > (size_t)fsz) {
    free(buf);
    return;
  }

  const Elf32_Shdr *shdrs = (const Elf32_Shdr *)(buf + eh->e_shoff);

  const Elf32_Shdr *chosen_sym = NULL;
  const Elf32_Shdr *chosen_str = NULL;

  // prefer SYMTAB
  for (int i = 0; i < eh->e_shnum; i++) {
    if (shdrs[i].sh_type == SHT_SYMTAB) {
      chosen_sym = &shdrs[i];
      if (shdrs[i].sh_link < eh->e_shnum) chosen_str = &shdrs[shdrs[i].sh_link];
      break;
    }
  }
  // fallback DYNSYM
  if (!chosen_sym) {
    for (int i = 0; i < eh->e_shnum; i++) {
      if (shdrs[i].sh_type == SHT_DYNSYM) {
        chosen_sym = &shdrs[i];
        if (shdrs[i].sh_link < eh->e_shnum) chosen_str = &shdrs[shdrs[i].sh_link];
        break;
      }
    }
  }

  if (!chosen_sym || !chosen_str || chosen_str->sh_type != SHT_STRTAB) {
    printf("[ftrace] no symtab/dynsym found (maybe stripped): %s\n", elf_file);
    free(buf);
    return;
  }

  if ((size_t)chosen_sym->sh_offset + (size_t)chosen_sym->sh_size > (size_t)fsz ||
      (size_t)chosen_str->sh_offset + (size_t)chosen_str->sh_size > (size_t)fsz) {
    free(buf);
    return;
  }

  extract_funcs_from_symtab(buf, chosen_sym, chosen_str);

  if (g_nsyms > 0) {
    qsort(g_syms, g_nsyms, sizeof(FuncSym), cmp_sym_addr);
    g_has_sym = 1;
    printf("[ftrace] loaded %zu function symbols from %s\n", g_nsyms, elf_file);
  } else {
    printf("[ftrace] symtab exists but no function symbols found: %s\n", elf_file);
  }

  free(buf);
}

/* -------------------- call stack (for accurate ret name) -------------------- */
typedef struct {
  const FuncSym *callee;  // function entered by call
  uint32_t ret_addr;      // expected return address (pc+4)
} Frame;

#define FTRACE_STACK_MAX 1024
static Frame g_stack[FTRACE_STACK_MAX];
static int   g_sp = 0;

static inline void push_frame(const FuncSym *callee, uint32_t ret_addr) {
  if (g_sp < FTRACE_STACK_MAX) {
    g_stack[g_sp++] = (Frame){ .callee = callee, .ret_addr = ret_addr };
  } else {
    // stack overflow: ignore (avoid crash)
  }
}

static inline const Frame *pop_frame(void) {
  if (g_sp > 0) return &g_stack[--g_sp];
  return NULL;
}

static inline void indent(void) {
  for (int i = 0; i < call_depth; i++) putchar(' ');
}

/* -------------------- public APIs -------------------- */
void ftrace_init(const char *elf_file) {
  call_depth = 0;
  g_sp = 0;
  printf("[ftrace] ftrace_init called, elf_file=%s\n", elf_file ? elf_file : "(null)");

  if (elf_file && elf_file[0]) {
    load_elf_symbols(elf_file);
    if (!g_has_sym) {
      printf("[ftrace] init with elf: %s (symbol unavailable)\n", elf_file);
    }
  } else {
    free_syms();
    printf("[ftrace] init (no elf)\n");
  }
}

void ftrace_trace(uint32_t pc, uint32_t inst, uint32_t dnpc) {
  uint32_t op = opcode(inst);

  // ---------------- call: JAL rd, imm ----------------
  if (op == 0x6f) { // JAL
    int _rd = rd(inst);
    int32_t off = jal_imm(inst);
    uint32_t target = pc + (uint32_t)off;

    // treat "write ra" as call
    if (_rd == 1) {
      indent();

      const FuncSym *fs = find_func_by_addr(target);
      if (fs) {
        printf("0x%08" PRIx32 ": call [%s@0x%08" PRIx32 "]\n", pc, fs->name, fs->addr);
      } else {
        printf("0x%08" PRIx32 ": call [0x%08" PRIx32 "]\n", pc, target);
      }

      push_frame(fs, pc + 4);
      call_depth++;
    }
    return;
  }

  // ---------------- JALR (call/ret) ----------------
  if (op == 0x67 && funct3(inst) == 0x0) { // JALR
    int _rd = rd(inst);
    int _rs1 = rs1(inst);
    int32_t imm = jalr_imm(inst);

    // ---- ret: jalr x0, ra, 0 ----
    if (_rd == 0 && _rs1 == 1 && imm == 0) {
      if (call_depth > 0) call_depth--;
      indent();

      const Frame *fr = pop_frame();
      if (fr && fr->callee) {
        printf("0x%08" PRIx32 ": ret  [%s] -> 0x%08" PRIx32 "\n",
               pc, fr->callee->name, dnpc);
      } else {
        printf("0x%08" PRIx32 ": ret  -> 0x%08" PRIx32 "\n", pc, dnpc);
      }
      return;
    }

    // ---- call: jalr ra, rs1, imm ----
    // treat "write ra" as call (indirect call)
    if (_rd == 1) {
      uint32_t target = dnpc; // nemu already calculated the actual next pc
      indent();

      const FuncSym *fs = find_func_by_addr(target);
      if (fs) {
        printf("0x%08" PRIx32 ": call [%s@0x%08" PRIx32 "]\n", pc, fs->name, fs->addr);
      } else {
        printf("0x%08" PRIx32 ": call [0x%08" PRIx32 "]\n", pc, target);
      }

      push_frame(fs, pc + 4);
      call_depth++;
      return;
    }

    return;
  }

  (void)dnpc;
}