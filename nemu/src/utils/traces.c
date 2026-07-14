#include "utils.h"


// ----------- iringbuf -----------
IringbufEntry iringbuf[IRINGBUF_SIZE];
int iringbuf_index;

void iringbuf_push(word_t pc, word_t inst, int ilen)
{
  iringbuf[iringbuf_index].pc = pc;
  iringbuf[iringbuf_index].inst = inst;
  iringbuf[iringbuf_index].ilen = ilen;
  iringbuf[iringbuf_index].valid = true;

  iringbuf_index = (iringbuf_index + 1) % IRINGBUF_SIZE;
}

void iringbuf_display()
{
#ifdef CONFIG_ITRACE

  int last_index = (iringbuf_index - 1 + IRINGBUF_SIZE) % IRINGBUF_SIZE;
  int old_index = iringbuf_index;
  int i = old_index;
  for (int cnt = 0; cnt < IRINGBUF_SIZE; cnt++)
  {
    if (!iringbuf[i].valid)
    {
      i = (i + 1) % IRINGBUF_SIZE;
      continue;
    }

    if (i == last_index)
      printf("--> ");

    char asmstr[128];

    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    disassemble(asmstr, sizeof(asmstr) - 1, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, iringbuf[i].ilen);

    printf(FMT_WORD ": " FMT_WORD " %s\n", iringbuf[i].pc, iringbuf[i].inst, asmstr);
    if (i == last_index)
      return;

    i = (i + 1) % IRINGBUF_SIZE;
  }

  printf("No valid instruction in the ring buffer.\n");

  return;
  #endif
}

// ----------- mtrace & dtrace -----------

char mtrace_buf[256];
static int mtrace_buf_pos = 0;
void mtrace_buf_write(bool is_write, word_t addr, int len, word_t data)
{
  mtrace_buf_pos += sprintf(mtrace_buf + mtrace_buf_pos, " [%s paddr=" FMT_WORD " len=%d data=" FMT_WORD "]", is_write ? "W" : "R", addr, len, data);
}
void dtrace_buf_write(bool is_write, vaddr_t addr, int len, word_t data, const char *name)
{
  mtrace_buf_pos += sprintf(mtrace_buf + mtrace_buf_pos, " {%s vaddr=" FMT_WORD " len=%d data=" FMT_WORD " name=%s}", is_write ? "W" : "R", addr, len, data, name);
}
void mtrace_buf_clear()
{
  mtrace_buf_pos = 0;
  mtrace_buf[0] = '\0';
}

// ----------- ftrace -----------
FuncSymbol *func_symbols = NULL;
int func_sym_count = 0;
char default_func[] = "???";
char *curr_func = default_func;
int indent_level = 0;

static char *ftrace_log_file = NULL;
bool ftrace_enabled = false;

// static void print_func_symbols()
// {
//   printf("Function Symbols:\n");
//   for (int i = 0; i < func_sym_count; i++)
//   {
//     printf("  %s: [" FMT_WORD ", " FMT_WORD ")\n", func_symbols[i].name, func_symbols[i].addr_begin, func_symbols[i].addr_end);
//   }
// }

static void *read_section_data(FILE *fp, Elf32_Shdr *shdr)
{
  void *data = malloc(shdr->sh_size);
  fseek(fp, shdr->sh_offset, SEEK_SET);
  size_t bytes_read = fread(data, 1, shdr->sh_size, fp);
  if (bytes_read != shdr->sh_size)
  {
    printf("Failed to read section data.\n");
    free(data);
    return NULL;
  }
  return data;
}

static void get_init_func_symbols()
{
  for (int i = 0; i < func_sym_count; i++)
  {
    if(cpu.pc >= func_symbols[i].addr_begin && cpu.pc < func_symbols[i].addr_end)
    {
      curr_func = func_symbols[i].name;
      break;
    }
  }
}
bool init_ftrace(char *elf_path)
{
  
  Elf32_Ehdr eh;
  FILE *fp = fopen(elf_path, "rb");
  if (fp == NULL)
  {
    printf("Failed to open ELF file: %s\n", elf_path);
    return false;
  }

  size_t bytes_read = fread(&eh, sizeof(Elf32_Ehdr), 1, fp);
  if (bytes_read != 1)
  {
    printf("Failed to read ELF header from file: %s\n", elf_path);
    fclose(fp);
    return false;
  }
  if (eh.e_ident[0] != 0x7f || eh.e_ident[1] != 'E' || eh.e_ident[2] != 'L' || eh.e_ident[3] != 'F')
  {
    printf("Invalid ELF file: %s\n", elf_path);
    fclose(fp);
    return false;
  }

  if (eh.e_ident[EI_CLASS] == ELFCLASS32)
  {
    fseek(fp, eh.e_shoff, SEEK_SET);
    Elf32_Shdr *shdr = malloc(sizeof(Elf32_Shdr) * eh.e_shnum); // section header table
    assert(sizeof(Elf32_Shdr) == eh.e_shentsize);
    size_t bytes_read = fread(shdr, sizeof(Elf32_Shdr), eh.e_shnum, fp);
    if (bytes_read != eh.e_shnum)
    {
      printf("Failed to read section headers from file: %s\n", elf_path);
      free(shdr);
      fclose(fp);
      return false;
    }

    int shstrtab_index = eh.e_shstrndx;
    assert(shstrtab_index < eh.e_shnum);
    char *shstrtab_data = read_section_data(fp, &shdr[shstrtab_index]);

    int symtab_index = -1;
    for (int i = 0; i < eh.e_shnum; i++)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
      {
        if (strcmp(shstrtab_data + shdr[i].sh_name, ".symtab") == 0)
        {
          symtab_index = i;
          break;
        }
      }
    }
    assert(symtab_index != -1);
    int strtab_index = shdr[symtab_index].sh_link;

    Elf32_Sym *symtab_data = read_section_data(fp, &shdr[symtab_index]);

    char *strtab_data = read_section_data(fp, &shdr[strtab_index]);

    for (int i = 0; i < shdr[symtab_index].sh_size / sizeof(Elf32_Sym); i++)
    {
      if (ELF32_ST_TYPE(symtab_data[i].st_info) == STT_FUNC)
      {
        func_sym_count++;
      }
    }
    func_symbols = malloc(sizeof(FuncSymbol) * func_sym_count);
    int func_sym_index = 0;
    for (int i = 0; i < shdr[symtab_index].sh_size / sizeof(Elf32_Sym); i++)
    {
      if (ELF32_ST_TYPE(symtab_data[i].st_info) == STT_FUNC)
      {
        assert(func_sym_index < func_sym_count);
        func_symbols[func_sym_index].name = strtab_data + symtab_data[i].st_name;
        func_symbols[func_sym_index].addr_begin = symtab_data[i].st_value;
        func_symbols[func_sym_index].addr_end = symtab_data[i].st_value + symtab_data[i].st_size;
        func_sym_index++;
      }
    }
    free(shstrtab_data);
    free(symtab_data);
    //free(strtab_data);
    free(shdr);
    // print_func_symbols();
    get_init_func_symbols();
    return true;
  }
  else if (eh.e_ident[EI_CLASS] == ELFCLASS64)
  {
    printf("ELF64 is not supported yet.\n");
    fclose(fp);
    return false;
  }
  else
  {
    printf("Unsupported ELF class: %d\n", eh.e_ident[EI_CLASS]);
    fclose(fp);
    return false;
  }
  fclose(fp);
  return false;
}

void init_ftrace_log(char *log_file)
{
  char *dot = strrchr(log_file, '.');
  size_t base_len = dot - log_file;
  const char *insert = "-ftrace";
  size_t new_len = base_len + strlen(insert) + strlen(dot) + 1;
  char *new_str = malloc(new_len);
  if (new_str)
  {
    strncpy(new_str, log_file, base_len);
    new_str[base_len] = '\0';
    strcat(new_str, insert);
    strcat(new_str, dot);
    ftrace_log_file = new_str;
  }
  FILE *fp = fopen(ftrace_log_file, "w");
  if (fp != NULL)
  {
    fclose(fp);
  }
}


static int write_count=0;
static void write_ftrace_log(const char *format, ...)
{
  if(write_count++ > 5000) {
    return;
  }

  if (ftrace_log_file == NULL || format == NULL)
  {
    printf("Ftrace log file is not initialized or format string is NULL.\n");
    return;
  }

  FILE *fp = fopen(ftrace_log_file, "a");
  if (fp == NULL)
  {
    printf("Failed to open ftrace log file: %s\n", ftrace_log_file);
    return;
  }

  va_list args;
  va_start(args, format);
  vfprintf(fp, format, args);
  va_end(args);

  fclose(fp);
}

char *get_elf_path(const char *bin_path)
{
  if (bin_path == NULL)
  {
    return NULL;
  }

  size_t len = strlen(bin_path);
  char *elf_path = (char *)malloc(len + 1);
  if (elf_path == NULL)
  {
    return NULL;
  }
  strcpy(elf_path, bin_path);

  // 查找最后一个点号（扩展名分隔符）
  char *dot = strrchr(elf_path, '.');
  if (dot == NULL)
  {
    // 没有扩展名，无法处理
    free(elf_path);
    return NULL;
  }

  // 检查点号后是否为 "bin" 且为字符串结尾
  if (dot[1] == 'b' && dot[2] == 'i' && dot[3] == 'n' && dot[4] == '\0')
  {
    // 替换为 ".elf"
    dot[1] = 'e';
    dot[2] = 'l';
    dot[3] = 'f';
    return elf_path;
  }
  else
  {
    // 扩展名不是 .bin 或后面还有多余字符
    free(elf_path);
    return NULL;
  }
}

static bool is_link_reg(int reg) {
    return (reg == 1 || reg == 5); 
}
void ftrace_record(word_t pc ,word_t dnpc, int rd,int rs1,bool is_jal) //这里目前是isa相关的 (rv32)
{
  for (int i = 0; i < func_sym_count; i++)
  {
    if (dnpc < func_symbols[i].addr_begin || dnpc >= func_symbols[i].addr_end)
      continue;

    if (strcmp(curr_func, func_symbols[i].name) == 0)
      return;

    curr_func = func_symbols[i].name;
    if (!is_jal && !is_link_reg(rd) && is_link_reg(rs1)) // return 
    {
      indent_level--;
      if (indent_level < 0)
        indent_level = 0;
      write_ftrace_log("" FMT_WORD " |%*s return <%s>\n", pc, indent_level * 2, "", curr_func);
    }
    else if(is_link_reg(rd))// call
    {
      write_ftrace_log("" FMT_WORD " |%*s call <%s> @" FMT_WORD "\n", pc, indent_level * 2, "", curr_func, func_symbols[i].addr_begin);
      indent_level++;
    }
  }
}