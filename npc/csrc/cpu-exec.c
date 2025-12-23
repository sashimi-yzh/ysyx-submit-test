#include <common.h>
//#include <cpu.h>
#include <locale.h>
#include <paddr.h>
#include <config.h>
#include <elf.h>
#define MAX_INST_TO_PRINT 30

typedef struct {
    char name[64];
    paddr_t addr;      //the function head address
    Elf32_Xword size;
} Symbol;

Symbol *symbol = NULL;  //dynamic allocate memory  or direct allocate memory (Symbol symbol[NUM])
int func_num = 0;
void parse_elf(const char *elf_file)
{
    
    if(elf_file == NULL) return;
    
    FILE *fp;
    fp = fopen(elf_file, "rb");
    
    if(fp == NULL)
    {
        printf("failed to open the elf file!\n");
        exit(0);
    }
	
    Elf32_Ehdr edhr;
	//读取elf头
    if(fread(&edhr, sizeof(Elf32_Ehdr), 1, fp) <= 0)
    {
        printf("fail to read the elf_head!\n");
        exit(0);
    }

    
    
    fseek(fp, edhr.e_shoff, SEEK_SET);

    Elf32_Shdr shdr;
    char *string_table = NULL;
    //寻找字符串表
    for(int i = 0; i < edhr.e_shnum; i++)
    {
        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            printf("fail to read the shdr\n");
            exit(0);
        }
        
        if(shdr.sh_type == SHT_STRTAB)
        {
          
            string_table = (char*)malloc(shdr.sh_size);
            fseek(fp, shdr.sh_offset, SEEK_SET);
            if(fread(string_table, shdr.sh_size, 1, fp) <= 0)
            {
                printf("fail to read the strtab\n");
                exit(0);
            }
        }
    }
    
    //寻找符号表
    fseek(fp, edhr.e_shoff, SEEK_SET);
    
    for(int i = 0; i < edhr.e_shnum; i++)
    {
        if(fread(&shdr, sizeof(Elf32_Shdr), 1, fp) <= 0)
        {
            printf("fail to read the shdr\n");
            exit(0);
        }

        if(shdr.sh_type == SHT_SYMTAB)
        {
            fseek(fp, shdr.sh_offset, SEEK_SET);

            Elf32_Sym sym;

            size_t sym_count = shdr.sh_size / shdr.sh_entsize;
            symbol = (Symbol*)malloc(sizeof(Symbol) * sym_count);
	     
            for(size_t j = 0; j < sym_count; j++)
            {
                if(fread(&sym, sizeof(Elf32_Sym), 1, fp) <= 0)
                {
                    printf("fail to read the symtab\n");
                    exit(0);
                }

                if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC)
                {
                    const char *name = string_table + sym.st_name;
                    strncpy(symbol[func_num].name, name, sizeof(symbol[func_num].name) - 1);
                    symbol[func_num].addr = sym.st_value;
                    symbol[func_num].size = sym.st_size;
                    func_num++;
                }
            }
        }
    }
    fclose(fp);
    free(string_table);
}
int depth = 0;
void call(word_t pc , word_t dnpc){
	 
	int i = 0;
	for ( ;i<func_num;i++){
		if(dnpc >= symbol[i].addr && dnpc < symbol[i].addr + symbol[i].size) break;
	}
	printf("0x%08x:",pc);
	for(int j=0;j<depth;j++)printf(" ");
	depth++;
	
	printf("call [%s@0x%08x]\n",symbol[i].name,dnpc);
}
void ret(word_t pc ){
	
	int i = 0;
	for ( ;i<func_num;i++){
		if(pc >= symbol[i].addr && pc < symbol[i].addr + symbol[i].size) break;
	}
	printf("0x%08x:",pc);
	for(int j=0;j<depth;j++)printf(" ");
	depth--;
	
	printf("ret [%s@0x%08x]\n",symbol[i].name,pc);
}


CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

NPCState npc_state = { .state = NPC_STOP };

void difftest_step(vaddr_t pc, vaddr_t npc);
uint64_t get_time();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc,bool difftest) {
   
   log_write("%s\n", _this->logbuf);
  if( g_print_step ) { puts(_this->logbuf); }

#ifdef CONFIG_DIFFTEST
   if(difftest){
    difftest_step(_this->pc, dnpc);
   }
#endif
}

void run_step(Decode *s, CPU_state *cpu,bool *difftest);
//bool difftest;
static void exec_once(Decode *s, vaddr_t pc,bool *difftest){

  s->pc = pc;
  s->snpc = pc;
  
  
  
        
  run_step(s, &cpu,difftest);
 
  cpu.pc = s->dnpc;
  char *p = s->logbuf;
  
  //record the pc
  p += snprintf(p, sizeof(s->logbuf), "0x%08x" ":", s->pc);
   

  int ilen = s->snpc - s->pc;
  int i;


  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }

  int ilen_max = 4;
  int space_len = ilen_max - ilen;

  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  
  memset(p, ' ', space_len);
  p += space_len;
   
  //record the disassemble information in s->logbuf
  
   void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      s->snpc, (uint8_t *)&s->isa.inst.val, ilen);
  
} 
 
static void execute(uint64_t n) {
  Decode s;
  bool difftest = false;
  for(; n>0; n--) {
    exec_once(&s,cpu.pc,&difftest);
    
    g_nr_guest_inst ++;
  
    trace_and_difftest(&s, cpu.pc,difftest);
  
    if(npc_state.state != NPC_RUNNING) {
      break;
    }
    
  }
}

void npc_trap(int state, vaddr_t pc, int halt_ret) {
  npc_state.state = state;
  npc_state.halt_pc = pc;
  npc_state.halt_ret = halt_ret;
}

void npc_quit() {
  npc_state.state = NPC_QUIT;
}

static void statistic() {
  setlocale(LC_NUMERIC, "");
#define NUMBERIC_FMT "%'ld"
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");

}

extern void isa_reg_display();
void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

void cpu_exec(uint64_t n) {
  g_print_step = ( n < MAX_INST_TO_PRINT ) ;
  switch (npc_state.state) {
    case NPC_END : case NPC_ABORT:
      printf( "Program execution has ended. To restart the program, exit NPC and run again.\n" );
      return ;
    default : npc_state.state = NPC_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      Log("npc: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FMT_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FMT_GREEN) :
             ANSI_FMT("HIT BAD TRAP", ANSI_FMT_RED))),
          npc_state.halt_pc);
    case NPC_QUIT: statistic();
  }
}


int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
     (npc_state.state == NPC_QUIT);
  return !good;
}

