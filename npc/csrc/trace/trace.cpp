#include "../../include/common.h"
#include <elf.h>
// itrace
char itrace_buf[128] = {0};

struct
{
  uint8_t now_p;
  uint8_t p;
  char iringbuf[IRINGBUF_DEEPTH][128];
} IRINGBUF = {0};

void print_iringbuf()
{
  printf(ANSI_FMT("iringbuf打印, --->执行过的最后一条指令\n", ANSI_FG_MAGENTA));
  for (int i = 0; i < IRINGBUF_DEEPTH; i++)
  {
    if (i == IRINGBUF.now_p)
      printf(ANSI_FMT("---> %s\n", ANSI_FG_MAGENTA), IRINGBUF.iringbuf[i]);
    else
      printf(">>>> %s\n", IRINGBUF.iringbuf[i]);
  }
}

static void Itrace(uint32_t inst_in, uint32_t pc_in)
{
  char *p = itrace_buf;
  p += snprintf(p, sizeof(itrace_buf), "0x%08x:", pc_in);
  int ilen = 4;
  int i;
  uint8_t *inst_s = (uint8_t *)&inst_in;
  for (i = ilen - 1; i >= 0; i--)
  {
    p += snprintf(p, 4, " %02x", inst_s[i]);
  }
  int ilen_max = 4;
  int space_len = ilen_max - ilen;
  if (space_len < 0)
    space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;
  disassemble(p, itrace_buf + sizeof(itrace_buf) - p, pc_in, inst_s, 4);
  // 这里也是IRINGBUF部分的代码
  // ===============================================
  IRINGBUF.now_p = IRINGBUF.p;
  strcpy(IRINGBUF.iringbuf[IRINGBUF.p], itrace_buf);
  if (IRINGBUF.p < IRINGBUF_DEEPTH - 1)
    IRINGBUF.p++;
  else
    IRINGBUF.p = 0;
  // ===============================================
}

void Itrace_log(uint32_t inst_in, uint32_t pc_in, uint32_t inst_num)
{
  Itrace(inst_in, pc_in);
  log_write("%s\n", itrace_buf);
  if (inst_num < PRINT_INST_NUM)
    printf("%s\n", itrace_buf);
}
// mtrace
char mtrace_buf[4][128] = {0};

void add_mtrace(uint32_t addr, int type, uint32_t data, int mask)
{
  static size_t ptr = 0;
  char *p = mtrace_buf[ptr];
  size_t buf_len = sizeof(mtrace_buf) / ARRLEN(mtrace_buf);
  p += snprintf(p, buf_len, "%ld  %08x:  ", ptr, SOC_NPC);
  p += snprintf(p, mtrace_buf[ptr] + buf_len - p, "%8x  ", addr);
  if (type == wen)
    p += snprintf(p, mtrace_buf[ptr] + buf_len - p, "write %08x %08x", data, mask);
  else if (type == ren)
    p += snprintf(p, mtrace_buf[ptr] + buf_len - p, "read  %08x %08x", data, mask);
  *p = '\0';
  if(ptr == ARRLEN(mtrace_buf) - 1) 
    ptr = 0;
  else
    ptr += 1; 
}

void printf_mtrace()
{
  printf(ANSI_FMT("mtrace 访存出错报告\n", ANSI_FG_MAGENTA));
  printf(ANSI_FMT("PC值         访存地址  操作  写入数据/读出数据 \n", ANSI_FG_MAGENTA));
  for(int i = 0; i < ARRLEN(mtrace_buf); i++) 
  {
    puts(mtrace_buf[i]);
  }
}


// ftrace
FUNC_FTRACE ELF_FUNC_FTRACER[128] = {0};
FUNC_FTRACE USER_FUNC_FTRACER[16] = {
  {.addr = 0x800006a0, .func_name = "main"},
  {.addr = 0x80000474, .func_name = "video_init"},
  {.addr = 0x800000e4, .func_name = "game_logic_update"},
  {.addr = 0x80000010, .func_name = "new_char"},
  {.addr = 0x800001b0, .func_name = "render"},
  {.addr = 0x80000c9c, .func_name = "printf"},
  {.addr = 0x800003a8, .func_name = "check_hit"},
  {.addr = 0x800008b0, .func_name = "halt"},
};
FUNC_FTRACE *FUNC_FTRACER = ELF_FUNC_FTRACER;
int FUNC_nums = ARRLEN(ELF_FUNC_FTRACER);
bool use_user_func = false;

// 读取elf文件
void load_elf(const std::string &elf_file)
{
  if (elf_file.empty())
  {
    Log("没有elf文件输入");
    return;
  }

  FILE *file = fopen(elf_file.c_str(), "rb");
  Assert(file, "无法打开elf文件");

  // 读取 ELF 文件头
  Elf32_Ehdr ehdr;
  if (fread(&ehdr, 1, sizeof(ehdr), file) != sizeof(ehdr))
  {
    printf("Failed to read ELF header\n");
    fclose(file);
    return;
  }

  // 检查 ELF 魔数
  if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0)
  {
    printf("Not a valid ELF file\n");
    fclose(file);
    return;
  }

  // 定位到节头表
  fseek(file, ehdr.e_shoff, SEEK_SET);

  // 使用 std::vector 替代 malloc
  std::vector<Elf32_Shdr> sh_table(ehdr.e_shnum);
  if (fread(sh_table.data(), ehdr.e_shentsize, ehdr.e_shnum, file) != ehdr.e_shnum)
  {
    printf("Failed to read section header table\n");
    fclose(file);
    return;
  }

  // 找到字符串表节（.strtab）
  std::string strtab;
  for (const auto &sh : sh_table)
  {
    if (sh.sh_type == SHT_STRTAB && &sh - sh_table.data() != ehdr.e_shstrndx)
    {
      strtab.resize(sh.sh_size);
      fseek(file, sh.sh_offset, SEEK_SET);
      if (fread(&strtab[0], 1, sh.sh_size, file) != sh.sh_size)
      {
        printf("Failed to read string table\n");
        fclose(file);
        return;
      }
      break;
    }
  }

  // 找到符号表节（.symtab）
  for (const auto &sh : sh_table)
  {
    if (sh.sh_type == SHT_SYMTAB)
    {
      size_t symtab_entry_count = sh.sh_size / sh.sh_entsize;

      // 使用 std::vector 替代 malloc
      std::vector<Elf32_Sym> symtab(symtab_entry_count);
      fseek(file, sh.sh_offset, SEEK_SET);
      if (fread(symtab.data(), sh.sh_entsize, symtab_entry_count, file) != symtab_entry_count)
      {
        printf("Failed to read symbol table\n");
        fclose(file);
        return;
      }

      // 遍历符号表,筛选各个函数名的入口地址
      for (size_t j = 0, k = 0; j < symtab_entry_count; j++)
      {
        if (ELF32_ST_TYPE(symtab[j].st_info) == STT_FUNC)
        {
          ELF_FUNC_FTRACER[k].addr = symtab[j].st_value;
          strncpy(ELF_FUNC_FTRACER[k].func_name, &strtab[symtab[j].st_name], sizeof(ELF_FUNC_FTRACER[k].func_name) - 1);
          ELF_FUNC_FTRACER[k].func_name[sizeof(ELF_FUNC_FTRACER[k].func_name) - 1] = '\0';
          k++;
        }
      }
      break;
    }
  }

  // 清理资源
  fclose(file);
  // 检查是否需要指定追踪的函数
  if(use_user_func) {
    FUNC_FTRACER = USER_FUNC_FTRACER;
    FUNC_nums = ARRLEN(USER_FUNC_FTRACER);
  }
}

FILE *ftracer_log_fp = NULL;
void init_ftracer_log(const char *ftrace_log_file)
{
  if (ftrace_log_file != NULL)
  {
    FILE *fp = fopen(ftrace_log_file, "w");
    Assert(fp, "无法打开日志文件 '%s'", ftrace_log_file);
    ftracer_log_fp = fp;
    Log("Ftracer 日志被输出到了 %s", ftrace_log_file);
  }
  else 
  {
    Log("Ftracer 日志没有输出");
  }
}

struct {
  uint32_t ret_addr;
  uint8_t num;
}FUNC_stack[8] = {0};

char repeat_buf[2][128] = {{0}};
char _buf[128] = {0};

void ftracer_log(uint32_t inst_in, uint32_t pc_in)
{
  static int repeat_count = 0;
  static uint32_t p_stack = 0;
  // 识别 call 调用函数
  if(is_jal(inst_in) || is_jalr(inst_in))
  {
    for(int i = 0; i < FUNC_nums; i++)
    {
      if(FUNC_FTRACER[i].addr == 0) break;
      if(SOC_NPC == FUNC_FTRACER[i].addr)
      {
        Assert(p_stack < ARRLEN(FUNC_stack), "调用太深, ftracer的堆栈溢出了");
        snprintf(_buf, sizeof(_buf), "0x%8x %u C [%s @ 0x%8x]\n", pc_in, p_stack, FUNC_FTRACER[i].func_name, SOC_NPC);
        if(!strcmp(_buf, repeat_buf[1])) {
          repeat_count++;
        } else {
          if(repeat_count) {
            ftracer_write("重复%d次, count = %d\n", repeat_count/2 + 1, repeat_count);
            repeat_count = 0;
          }
          ftracer_write("%s", _buf);
        }
        strcpy(repeat_buf[1], repeat_buf[0]);
        strcpy(repeat_buf[0], _buf);        
        FUNC_stack[p_stack].num = i;
        FUNC_stack[p_stack].ret_addr = pc_in + 4;
        p_stack++;
      }
    }
  }
  // 识别 ret 返回函数
  if(is_ret(inst_in))
  {
    if(p_stack <= ARRLEN(FUNC_stack)) {
      bool good_ret = false;
      uint32_t p_stack_init = p_stack;
      while (p_stack--)
      {
        if(get_reg(1) == FUNC_stack[p_stack].ret_addr) {
          good_ret = true;
          break;
        }
      }
      if(good_ret) {
        snprintf(_buf, sizeof(_buf), "0x%8x %u R [%s @ 0x%8x]\n",pc_in, p_stack, FUNC_FTRACER[FUNC_stack[p_stack].num].func_name, get_reg(1));
        if(!strcmp(_buf, repeat_buf[1])) {
          repeat_count++;
        } else {
          if(repeat_count) {
            ftracer_write("重复%d次, count = %d\n", repeat_count/2 + 1, repeat_count);
            repeat_count = 0;
          }
          ftracer_write("%s", _buf);
        }
        strcpy(repeat_buf[1], repeat_buf[0]);
        strcpy(repeat_buf[0], _buf);        
      } else {
        p_stack = p_stack_init;
      }
    }
  }
}