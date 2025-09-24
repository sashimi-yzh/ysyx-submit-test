#include "ftrace.h"
#include <elf.h>
#include <map>
#include <memory>
#include <string.h>

#define FILE_NAME_MAXLEN 256
#define MAX_FUNCTION_NUM 65536

#define Elf_Ehdr MUXDEF(RV64IM, Elf64_Ehdr, Elf32_Ehdr)
#define Elf_Off MUXDEF(RV64IM, Elf64_Off, Elf32_Off)
#define Elf_Half MUXDEF(RV64IM, Elf64_Half, Elf32_Half)
#define Elf_Shdr MUXDEF(RV64IM, Elf64_Shdr, Elf32_Shdr)
#define Elf_Xword MUXDEF(RV64IM, Elf64_Xword, Elf32_Xword)
#define Elf_Word MUXDEF(RV64IM, Elf64_Word, Elf32_Word)
#define Elf_Sym MUXDEF(RV64IM, Elf64_Sym, Elf32_Sym)

typedef struct {
  char fun_name[FILE_NAME_MAXLEN];
  word_t begin;
  word_t end;
} function_message;

static function_message funs[MAX_FUNCTION_NUM];
static int fun_num = 0;

static std::map<int, paddr_t> breakpoint;

FILE *ftrace_log = NULL;

static void add_elf(const std::string &elf_file) {
  FILE *fp = fopen(elf_file.c_str(), "r");
  ASSERT(fp, "open elf file failed");

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  char *buff = (char *)malloc(file_size);
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
    ASSERT(sym_section_hdr && str_section_hdr,
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

void init_elf(const std::vector<std::string> &elf_files) {
  for (auto &file : elf_files) {
    add_elf(file);
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

static bool is_call(word_t addr) {
  for (int i = 0; i < fun_num; i++) {
    if (addr == funs[i].begin) {
      return true;
    }
  }
  return false;
}

#define MAX_DEEP 4096
static char call_chain[MAX_DEEP][FILE_NAME_MAXLEN];
static int indent = 0;

void ftrace(word_t pc, word_t addr, uint32_t inst) {
  if (fun_num == 0) {
    return;
  }
  bool jalr = BITS(inst, 14, 12) == 0 && BITS(inst, 6, 0) == 0b1100111;
  bool jal = BITS(inst, 6, 0) == 0b1101111;
  if (!jal && !jalr) {
    return;
  }
  char *fun_name = get_fun_name(addr);
  ASSERT_IN_RUNTIME(fun_name,
         "ftrace get function name failed, pc:" FMT_PADDR " addr:" FMT_PADDR
         " inst:0x%08x",
         pc, addr, inst);
  if (is_call(addr)) {
    fprintf(ftrace_log, "[" FMT_PADDR "]", pc);
    for (int i = 0; i < indent; i++) {
      fprintf(ftrace_log, "  ");
    }
    fprintf(ftrace_log, "call %s [" FMT_PADDR "]\n", fun_name, addr);
    strcpy(call_chain[indent], fun_name);
    indent++;
    ASSERT_IN_RUNTIME(indent <= MAX_DEEP, "too deep function call nesting");
    return;
  }
  int rs1 = BITS(inst, 19, 15);
  int rd = BITS(inst, 11, 7);
  if (jalr && (rs1 == 1) && rd == 0) {
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

paddr_t get_function_addr(char *fun_name) {
  for (int i = 0; i < fun_num; i++) {
    if (strcmp(fun_name, funs[i].fun_name) == 0) {
      return funs[i].begin;
    }
  }
  return -1;
}

void add_breakpoint(char *fun_name) {
  static int index = 0;
  auto function_addr = get_function_addr(fun_name);
  if (function_addr != -1) {
    printf("breakpoint %d, %x in %s\n", index, function_addr, fun_name);
    breakpoint[index++] = function_addr;
  } else {
    printf("add break point failed, please check the address\n");
  }
}

void delete_breakpoint(int index) {
  if (breakpoint.count(index))
    breakpoint.erase(index);
  else
    printf("can not delete breakpoint %d\n", index);
}

void display_breakpoint() {
  for (auto &[k, v] : breakpoint) {
    printf("breakpoint %d %x %s\n", k, v, get_fun_name(v));
  }
}

bool check_breakpoint(paddr_t function_addr) {
  for (auto &[k, v] : breakpoint) {
    if (v == function_addr) {
      printf("breakpoint %d, %x in %s\n", k, v, get_fun_name(v));
      return true;
    }
  }
  return false;
}