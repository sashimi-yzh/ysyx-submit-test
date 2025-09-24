#include <common.h>
#include <utils.h>
#include <elf.h>

static FILE *elf_fp = NULL;
static Elf32_Sym  *sym  = NULL;
static uint32_t symsize = 0;
static char *str = NULL;
static uint32_t strsize = 0;

void init_ftrace(const char *elf_file) {
  // open elf file
  if (elf_file != NULL) {
    FILE *fp = fopen(elf_file, "r");
    Assert(fp, "Can not open '%s'", elf_file);
    elf_fp = fp;
  } else return;

  // variable
  size_t fn;
  Elf32_Ehdr *ehdr = malloc(sizeof(Elf32_Ehdr));
  Elf32_Shdr *shdr = malloc(sizeof(Elf32_Shdr));
  uint32_t symoff  = 0;
  uint32_t stroff  = 0;

  // seek section header
  fn = fread(ehdr, sizeof(Elf32_Ehdr), 1, elf_fp);
  assert(fn);
  uint32_t shoff = ehdr->e_shoff;

  // seek sym and str
  int i = 0;
  while(1) {
    fseek(elf_fp, shoff + i++*sizeof(Elf32_Shdr), SEEK_SET);
    fn = fread(shdr, sizeof(Elf32_Shdr), 1, elf_fp);
    assert(fn);
    if (shdr->sh_type == SHT_SYMTAB) {
      symoff = shdr->sh_offset;
      symsize = shdr->sh_size;
    }
    if (shdr->sh_type == SHT_STRTAB) {
      stroff = shdr->sh_offset;
      strsize = shdr->sh_size;
      break;
    }
  }

  // save symtab
  sym = malloc(symsize);
  fseek(elf_fp, symoff, SEEK_SET);
  fn = fread(sym, 1, symsize, elf_fp);
  assert(fn);
  // save strtab
  str = malloc(strsize);
  fseek(elf_fp, stroff, SEEK_SET);
  fn = fread(str, 1, strsize, elf_fp);
  assert(fn);

  free(ehdr);
  free(shdr);
  fclose(elf_fp);
}

static int n = 0;
void ftrace(word_t pc, word_t npc, bool call) {
  int symnum = symsize / sizeof(Elf32_Sym);
  char funcname[128] = {};
  word_t fpc = call ? npc : pc;

  for (int i = 0; i < symnum; i++) {
    Elf32_Sym *sym_ptr = sym + i;
    if (sym_ptr->st_info == STT_FUNC + 16) {
      if (fpc >= sym_ptr->st_value && fpc <= sym_ptr->st_value + sym_ptr->st_size - 1) {
        strcpy(funcname, str + sym_ptr->st_name);
        break;
      }
    }
  }

  trace_write("0x%.8x: ", pc);

  if(!call) n--;
  for (int i = 0; i < n; i++) 
    trace_write(" ");
  if (call) n++;

  if (call)
    trace_write("call [%s @ 0x%.8x]\n", funcname, fpc);
  else
    trace_write("ret [%s]\n", funcname);
}

void ftrace_free() {
  free(sym);
  free(str);
}
