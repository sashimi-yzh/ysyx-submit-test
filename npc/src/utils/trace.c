#include <stdlib.h>
#include <stdio.h>
#include <verilated.h>
#include <elf.h>

#include "config.h"

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

// pc trace
FILE* f_pc;

void parse_pc_trace_file(const char *log_file) {
    if(log_file == NULL) {
      printf("log_file is not exist\n");
      return;
    }

    f_pc = fopen(log_file,"w+"); //read binary
}

void close_pc_trace_file() {
    fclose(f_pc);
}

extern "C" void trace_pc(uint32_t pc) {
#ifdef pc_trace
	fprintf(f_pc, "%08x\n", pc);
#endif
}

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

extern "C" void npc_itrace(uint32_t pc, uint32_t inst) {
#ifdef itrace

	printf("0x%08x: ", pc);
	printf("%02x ", (inst >> 24) & 0xff);
	printf("%02x ", (inst >> 16) & 0xff);
	printf("%02x ", (inst >> 8) & 0xff);
	printf("%02x ", (inst >> 0) & 0xff);

	char p[128];
    disassemble(p, 128, pc, (uint8_t *)&inst, 4);
	printf("%s\n", p);
    // itrace
#endif
}

void parse_elf(const char *elf_file) {
    if(elf_file == NULL) {
      printf("No elf_file is given. do not parse_elf\n");
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
              string_table = (char *)malloc(shdr.sh_size);
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
            symbol = (Symbol *)malloc(sizeof(Symbol) * sym_count);
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
                    printf("%20s\t0x%08x\t%x\n", symbol[func_num].name, symbol[func_num].addr, symbol[func_num].size);
                    func_num++;
                }
            }
            break;
        }
    }
    fclose(fp);
    free(string_table);
}

static int find_symbol_func(uint32_t target, bool is_call) {
	uint32_t i;
	for (i = 0; i < sym_count; i++) {
			if (is_call) {
				if (symbol[i].addr == target) break;
                // printf("%d\n\n", i);
			} else {
				if (symbol[i].addr <= target && target < symbol[i].addr + symbol[i].size) break;
			}
	}
	return i< sym_count ? i : -1;
}

extern "C" void trace_func_call(uint32_t pc, uint32_t target) {
#ifdef ftrace
    // printf("pc == 0x%x, target == 0x%x\n", pc, target);
	if (symbol == NULL) return;

	// if (call_depth <= 2) return; // ignore _trm_init & main

	int i = find_symbol_func(target, true);
    if(i != -1)
        ++call_depth;

	printf("0x%08x : %*scall [%s@0x%08x]\n",
		pc,
		(call_depth)*2, "",
		i>=0?symbol[i].name:"???",
		target
	);
#endif
}

extern "C" void trace_func_ret(uint32_t pc) {
#ifdef ftrace
	if (symbol == NULL) return;
	
	// if (call_depth <= 2) return; // ignore _trm_init & main

	int i = find_symbol_func(pc, false);
	printf("0x%08x : %*sret [%s]\n",
		pc,
		(call_depth)*2, "",
		i>=0?symbol[i].name:"???"
	);
	
	--call_depth;
#endif
}

