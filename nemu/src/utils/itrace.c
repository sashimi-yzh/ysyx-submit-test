#include <common.h>
#include <elf.h>
#include <device/map.h>

// ITRACE
#define MAX_IRINGBUF 16

typedef struct {
  word_t pc;
  uint32_t inst;
} ItraceNode;

ItraceNode iringbuf[MAX_IRINGBUF];
int p_cur = 0;
bool full = false;

void trace_inst(word_t pc, uint32_t inst) {
  iringbuf[p_cur].pc = pc;
  iringbuf[p_cur].inst = inst;
  p_cur = (p_cur + 1) % MAX_IRINGBUF;
  full = full || p_cur == 0;
}

void trace_dread(paddr_t addr, int len, IOMap *map) {
	Log("dtrace: read %10s at " FMT_PADDR ",%d\n",
		map->name, addr, len);
}

void trace_dwrite(paddr_t addr, int len, word_t data, IOMap *map) {
	Log("dtrace: write %10s at " FMT_PADDR ",%d with " FMT_WORD "\n",
		map->name, addr, len, data);
}

IFDEF(CONFIG_ITRACE, 
void display_inst() {
  if (!full && !p_cur) return;

  int end = p_cur;
  int i = full?p_cur:0;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  char buf[128]; // 128 should be enough!
  char *p;
  // Statement("Most recently executed instructions");
  do {
    p = buf;
    p += sprintf(buf, "%s" FMT_WORD ": %08x ", (i+1)%MAX_IRINGBUF==end?" --> ":"     ", iringbuf[i].pc, iringbuf[i].inst);
    disassemble(p, buf+sizeof(buf)-p, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, 4);

    if ((i+1)%MAX_IRINGBUF==end) printf(ANSI_FG_RED);
    puts(buf);
  } while ((i = (i+1)%MAX_IRINGBUF) != end);
  puts(ANSI_NONE);
}

);


// MTRACE
// void display_pread(paddr_t addr, int len) {
//   printf("pread at " FMT_PADDR " len=%d\n", addr, len);
// }

// void display_pwrite(paddr_t addr, int len, word_t data) {
//   printf("pwrite at " FMT_PADDR " len=%d, data=" FMT_WORD "\n", addr, len, data);
// }

// FTRACE
/* ELF64 as default */

//symbol header
typedef struct 
{
  uint32_t  addr;
  uint32_t  size;
  char      name[20];
}Symbol;

Symbol *symbol  = NULL;
size_t sym_count;
uint8_t call_depth = 0;

void parse_elf(const char *elf_file) {
    if(elf_file == NULL) {
      Log("No elf_file is given. do not parse_elf\n");
      return;
    }

    FILE *fp;
    fp = fopen(elf_file,"rb"); //read binary

    //ELF header
    Elf32_Ehdr edhr;
    if(fread(&edhr, sizeof(Elf32_Ehdr), 1, fp) <= 0)//fp读1个sizeof(Elf32 header)大小，然后写入edhr中（edhr = ELF header)
    {
        printf("fail to read the elf_head!\n");
        exit(0);
    }

    //section header
    Elf32_Shdr shdr;
    char *string_table  = NULL;
    fseek(fp, edhr.e_shoff,SEEK_SET);
    for (int i = 0; i < edhr.e_shnum; i++){
          if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0){
              printf("fail to read the shdr\n");
              exit(0);
          }
          if(shdr.sh_type == SHT_STRTAB)        //读取type =STRTAB的字符串表
          {
              string_table = malloc(shdr.sh_size);
              fseek(fp,shdr.sh_offset,SEEK_SET);  //修改fp指针在SEEK_SET的sh_offset处
              if(fread(string_table,shdr.sh_size,1,fp) <=0 ){
                  printf("fail to read the shrd");
              };//从fp位置读，读section size，存入string_table中
              break;
          }
    }
    
    uint8_t func_num = 0;
    fseek(fp,edhr.e_shoff,SEEK_SET); //回到elf开头的e_shoff处
    //开始遍历寻找符号表
    for (int i = 0; i < edhr.e_shnum; i++)
    {
        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            printf("fail to read the shdr\n");
            exit(0);
        }
        if(shdr.sh_type == SHT_SYMTAB)
        {
            fseek(fp,shdr.sh_offset,SEEK_SET);//修改fp指针到symbol_table处准备写入
            Elf32_Sym sym; //Symbol类
            sym_count = shdr.sh_size / shdr.sh_entsize ;
            symbol = malloc(sizeof(Symbol) * sym_count);
            for (int  j = 0; j < sym_count; j++)
            {
                if(fread(&sym, sizeof(Elf32_Sym), 1, fp) <= 0)
                {
                    printf("fail to read the symtab\n");
                    exit(0);
                }
               if(ELF32_ST_TYPE(sym.st_info)==STT_FUNC)
                {
                    const char *name = string_table + sym.st_name;
                    strncpy(symbol[func_num].name,name,sizeof(symbol[func_num].name) - 1);
                    symbol[func_num].addr = sym.st_value; //value赋值给addr
                    symbol[func_num].size = sym.st_size;
                    // printf("%20s\t0x%08x\t%x\n", symbol[func_num].name, symbol[func_num].addr, symbol[func_num].size);
                    func_num++;
                }
            }
            break;
        }
    }
    fclose(fp);
    free(string_table);
}

static int find_symbol_func(paddr_t target, bool is_call) {
	uint8_t i;
	for (i = 0; i < sym_count; i++) {
			if (is_call) {
				if (symbol[i].addr == target) break;
			} else {
				if (symbol[i].addr <= target && target < symbol[i].addr + symbol[i].size) break;
			}
	}
	return i< sym_count ? i : -1;
}

void trace_func_call(paddr_t pc, paddr_t target) {
	if (symbol == NULL) return;

	++call_depth;

	// if (call_depth <= 2) return; // ignore _trm_init & main

	int i = find_symbol_func(target, true);
	Log(FMT_PADDR ": %*scall [%s@" FMT_PADDR "]\n",
		pc,
		(call_depth)*2, "",
		i>=0?symbol[i].name:"???",
		target
	);
}

void trace_func_ret(paddr_t pc) {
	if (symbol == NULL) return;
	
	// if (call_depth <= 2) return; // ignore _trm_init & main

	int i = find_symbol_func(pc, false);
	Log(FMT_PADDR ": %*sret [%s]\n",
		pc,
		(call_depth)*2, "",
		i>=0?symbol[i].name:"???"
	);
	
	--call_depth;
}

