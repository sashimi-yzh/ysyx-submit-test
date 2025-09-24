#include "common.h"
#include <elf.h>

#define FILE_NAME_MAXLEN 256
#define MAX_FUNCTION_NUM 65536

#define Elf_Ehdr MUXDEF(CONFIG_ISA64, Elf64_Ehdr, Elf32_Ehdr)
#define Elf_Off MUXDEF(CONFIG_ISA64, Elf64_Off, Elf32_Off)
#define Elf_Half MUXDEF(CONFIG_ISA64, Elf64_Half, Elf32_Half)
#define Elf_Shdr MUXDEF(CONFIG_ISA64, Elf64_Shdr, Elf32_Shdr)
#define Elf_Xword MUXDEF(CONFIG_ISA64, Elf64_Xword, Elf32_Xword)
#define Elf_Word MUXDEF(CONFIG_ISA64, Elf64_Word, Elf32_Word)
#define Elf_Sym MUXDEF(CONFIG_ISA64, Elf64_Sym, Elf32_Sym)

typedef struct {
  char fun_name[FILE_NAME_MAXLEN];
  word_t begin;
  word_t end;
} function_message;

static function_message funs[MAX_FUNCTION_NUM];
static int fun_num = 0;

FILE *ftrace_log = NULL;

void add_elf(const char *elf_file) {
  FILE *fp = fopen(elf_file, "r");
  Assert(fp, "open elf file failed");

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  char *buff = malloc(file_size);
  fseek(fp, 0, SEEK_SET);
  if (fread(buff, 1, file_size, fp)) {
    Elf_Ehdr *elf_header = (Elf_Ehdr *)buff;
    // section header offset
    Elf_Off shoff = elf_header->e_shoff;
    // section header num
    Elf_Half shnum = elf_header->e_shnum;
    // symbol table section header
    Elf_Shdr *sym_section_hdr = NULL;
    // str table section header
    Elf_Shdr *str_section_hdr = NULL;
    for (Elf_Half i = 0; i < shnum; i++) {
      Elf_Shdr *section_header =
          (Elf_Shdr *)&buff[shoff + i * sizeof(Elf_Shdr)];
      if (section_header->sh_type == SHT_SYMTAB) {
        sym_section_hdr = section_header;
      } else if (section_header->sh_type == SHT_STRTAB &&
                 i != elf_header->e_shstrndx) {
        str_section_hdr = section_header;
      }
    }
    Assert(sym_section_hdr && str_section_hdr,
           "get symtab or strtab header failed");
    Elf_Off str_offset = str_section_hdr->sh_offset;
    Elf_Off sym_offset = sym_section_hdr->sh_offset;
    Elf_Xword sym_size = sym_section_hdr->sh_size;
    Elf_Xword section_entry_size = sym_section_hdr->sh_entsize;
    // iterate symblo table
    for (Elf_Xword begin = 0; begin < sym_size; begin += section_entry_size) {
      Elf_Sym *symbol = (Elf_Sym *)&buff[sym_offset + begin];
      if ((symbol->st_info & 0x0f) == SYMINFO_NUM) {
        Elf_Word str_index = symbol->st_name;
        strcpy(funs[fun_num].fun_name, &buff[str_offset + str_index]);
        funs[fun_num].begin = symbol->st_value;
        funs[fun_num].end = symbol->st_value + symbol->st_size;
        if (++fun_num >= MAX_FUNCTION_NUM) {
          printf("can't not save more function message\n");
          break;
        }
      }
    }
  }
  free(buff);
  fclose(fp);
}

void init_elf(const char *elf_files[], int num) {
  for (int i = 0; i < num; i++) {
    add_elf(elf_files[i]);
  }
}

char *get_fun_name(word_t addr) {
  for (int i = 0; i < fun_num; i++) {
    if (addr >= funs[i].begin && addr < funs[i].end) {
      return funs[i].fun_name;
    }
  }
  return NULL;
}

bool is_call(word_t addr) {
  for (int i = 0; i < fun_num; i++) {
    if (addr == funs[i].begin) {
      return true;
    }
  }
  return false;
}

#define MAX_DEEP 128
static char call_chain[MAX_DEEP][FILE_NAME_MAXLEN];
static int indent = 0;

void ftrace(word_t pc, word_t addr, uint32_t inst, bool jalr, bool mret) {
  char *current_fun_name = get_fun_name(pc);
  char *fun_name = get_fun_name(addr);
  Assert(current_fun_name && fun_name,
         "ftrace get function name failed, pc:" FMT_PADDR " addr:" FMT_PADDR
         " inst:0x%08x",
         pc, addr, inst);
  if (strcmp(current_fun_name, fun_name) == 0) {
    return;
  }
  if (is_call(addr)) {
    fprintf(ftrace_log, "[" FMT_PADDR "]", pc);
    for (int i = 0; i < indent; i++) {
      fprintf(ftrace_log, "  ");
    }
    fprintf(ftrace_log, "call %s [" FMT_PADDR "]\n", fun_name, addr);
    strcpy(call_chain[indent], fun_name);
    indent++;
    return;
  }
  int rs1 = BITS(inst, 19, 15);
  int rd = BITS(inst, 11, 7);
  if (mret || (jalr && (rs1 == 1) && rd == 0)) {
    indent -= 1;
    while (indent >= 0) {
      if (strcmp(call_chain[indent - 1], fun_name) != 0) {
        indent -= 1;
      } else {
        fprintf(ftrace_log, "[" FMT_PADDR "]", pc);
        for (int i = 0; i < indent; i++) {
          fprintf(ftrace_log, "  ");
        }
        fprintf(ftrace_log, "ret to %s [" FMT_PADDR "]\n", fun_name, addr);
        break;
      }
    }
  }
}