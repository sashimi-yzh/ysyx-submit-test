#include <common.h>
#include <trace.h>
FILE *mtrace_fp = NULL;
FILE *dtrace_fp = NULL;
char *TRACE_DIR = NULL;
FILE *etrace_fp = NULL;
FILE *icachesim_fp = NULL;

void init_icachesim(const char *file) {
  if (file == NULL) return;
  // 二进制：顺序执行段记录（每段 8 字节 {start_pc, end_pc}），
  // 比逐指令文本小两个数量级以上（microbench 全量约 25GB 文本 -> 数百 MB 段记录）
  icachesim_fp = fopen(file, "wb");
  Assert(icachesim_fp, "Can not open '%s'", file);
  Log("icachesim-itrace is written to %s", file);
}

// 顺序执行段状态：当前段的起始/结束 PC
static uint32_t seg_start = 0;
static uint32_t seg_end = 0;
static bool seg_active = false;

void flush_icachesim() {
  if (icachesim_fp != NULL && seg_active) {
    fwrite(&seg_start, 4, 1, icachesim_fp);
    fwrite(&seg_end, 4, 1, icachesim_fp);
    seg_active = false;
  }
}

void record_icachesim(uint32_t pc) {
  if (icachesim_fp == NULL) return;
  if (!seg_active) {
    seg_start = seg_end = pc;
    seg_active = true;
  } else if (pc == seg_end + 4) {
    seg_end = pc;
  } else {
    // 顺序段结束（分支/跳转），记录并开始新段
    fwrite(&seg_start, 4, 1, icachesim_fp);
    fwrite(&seg_end, 4, 1, icachesim_fp);
    seg_start = seg_end = pc;
  }
}

bool mtrace_enable(paddr_t addr) {
  return MUXDEF(CONFIG_MTRACE, (addr >= CONFIG_MTRACE_START_ADDR) &&
      (addr <= CONFIG_MTRACE_END_ADDR), false);
}

void record_mtrace(RECORD_MODE mode,paddr_t addr,int len,word_t data){
#ifdef CONFIG_MTRACE
    if (mtrace_enable(addr) && mtrace_fp != NULL) { 
        if(mode == READ_TRACE)
            fprintf(mtrace_fp,"read memory: raddr=%u rlen=%u rdata=%u \n",addr,len, data); 
        else
            fprintf(mtrace_fp,"write memory: waddr=%u wlen=%u wdata=%u \n",addr,len, data); 
        fflush(mtrace_fp); 
    } 

#endif
}

#include <elf.h>

// 保存函数信息
typedef struct {
    char name[64];       
    uint32_t start_addr; 
    uint32_t end_addr;   
    uint32_t size;       
} ElfFunction;
ElfFunction *funcs = NULL;
int funcs_count = 0;

int extract_elf_functions(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Failed to open ELF file");
        return -1;
    }

    Elf32_Ehdr ehdr;
    if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        perror("Failed to read ELF header");
        fclose(fp);
        return -1;
    }

    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: Not a valid ELF file\n");
        fclose(fp);
        return -1;
    }

    if (ehdr.e_ident[EI_CLASS] != ELFCLASS32) {
        fprintf(stderr, "Error: Not a 32-bit ELF file\n");
        fclose(fp);
        return -1;
    }

    //读取节区头表
    Elf32_Shdr *shdrs = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
    if (!shdrs) { fclose(fp); return -1; }
    
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    if (fread(shdrs, sizeof(Elf32_Shdr), ehdr.e_shnum, fp) != ehdr.e_shnum) {
        perror("Failed to read section headers");
        free(shdrs); fclose(fp); return -1;
    }

    Elf32_Shdr *symtab_shdr = NULL;
    Elf32_Shdr *strtab_shdr = NULL;

    for (int i = 0; i < ehdr.e_shnum; i++) {
        if (shdrs[i].sh_type == SHT_SYMTAB) {
            symtab_shdr = &shdrs[i];
            // 符号表头中的 sh_link 指向对应的字符串表
            strtab_shdr = &shdrs[shdrs[i].sh_link];
            break;
        }
    }

    if (!symtab_shdr || !strtab_shdr) {
        fprintf(stderr, "Error: Could not find .symtab or .strtab (File might be stripped)\n");
        free(shdrs); fclose(fp); return -1;
    }

    char *strtab = malloc(strtab_shdr->sh_size);
    if (!strtab) { free(shdrs); fclose(fp); return -1; }
    
    fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
    size_t len = fread(strtab, 1, strtab_shdr->sh_size, fp);
    if(len <=0 ) return -1;

    int sym_count = symtab_shdr->sh_size / symtab_shdr->sh_entsize;
    Elf32_Sym *syms = malloc(symtab_shdr->sh_size);
    if (!syms) { free(strtab); free(shdrs); fclose(fp); return -1; }

    fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
    len = fread(syms, symtab_shdr->sh_entsize, sym_count, fp);
    if(len <=0 ) return -1;
    
    for (int i = 0; i < sym_count; i++) {
        // 判断是否为函数 (STT_FUNC) 且 有实际地址 (st_value != 0)
        if (ELF32_ST_TYPE(syms[i].st_info) == STT_FUNC && syms[i].st_value != 0) {
            funcs_count++;
        }
    }

    funcs = malloc(funcs_count * sizeof(ElfFunction));
    if (!funcs) { free(syms); free(strtab); free(shdrs); fclose(fp); return -1; }

    int idx = 0;
    for (int i = 0; i < sym_count; i++) {
        if (ELF32_ST_TYPE(syms[i].st_info) == STT_FUNC && syms[i].st_value != 0) {
            funcs[idx].start_addr = syms[i].st_value;
            funcs[idx].size = syms[i].st_size;
            funcs[idx].end_addr = syms[i].st_value + syms[i].st_size;
            
            // 从字符串表提取名字，注意防止越界
            const char *name_ptr = strtab + syms[i].st_name;
            strncpy(funcs[idx].name, name_ptr, 63);
            funcs[idx].name[63] = '\0';
            
            idx++;
        }
    }
    // for(int i = 0;i<funcs_count;i++){
    //     printf("%s\n",funcs[i].name);
    // }
    free(syms);
    free(strtab);
    free(shdrs);
    fclose(fp);

    return funcs_count;
}

FILE *ftrace_fp = NULL;


#define FTRACE_STACK_MAX_DEPTH 1024

typedef struct {
    int func_idx;       // 保存 funcs 数组的下标，-1 表示未知函数
    uint32_t ret_addr;  // 记录预期的返回地址，用于识别尾调用
} FtraceFrame;

FtraceFrame ftrace_stack[FTRACE_STACK_MAX_DEPTH];
int ftrace_top = -1;

//根据 PC 获取函数在 funcs 数组中的下标
int get_func_idx(uint32_t pc) {
    if (!funcs || funcs_count == 0) return -1;
    for (int i = 0; i < funcs_count; i++) {
        if (pc >= funcs[i].start_addr && pc < funcs[i].end_addr) {
            return i;
        }
    }
    return -1;
}


void record_ftrace(uint32_t pc, uint32_t next_pc, uint32_t target_pc, int rd, int rs1) {
#ifdef CONFIG_FTRACE
    if (!ftrace_fp) return;

    if (rd == 1) {
        int idx = get_func_idx(target_pc);

        // 压栈，记录函数下标和返回地址
        if (ftrace_top < FTRACE_STACK_MAX_DEPTH - 1) {
            ftrace_top++;
            ftrace_stack[ftrace_top].func_idx = idx;
            ftrace_stack[ftrace_top].ret_addr = next_pc;
        }

        // 打印 call
        const char *name = (idx != -1) ? funcs[idx].name : "???";
        fprintf(ftrace_fp, "%*s0x%08x: call [%s@0x%08x]\n", 
                ftrace_top * 2, "", pc, name, target_pc);
    }
    else if (rd == 0) {
        if (ftrace_top >= 0) {
            if (target_pc == ftrace_stack[ftrace_top].ret_addr) {
                int idx = ftrace_stack[ftrace_top].func_idx;
                const char *name = (idx != -1) ? funcs[idx].name : "???";
                
                fprintf(ftrace_fp, "%*s0x%08x: ret  [%s]\n", 
                        (ftrace_top + 1) * 2, "", pc, name);
                ftrace_top--; // 弹栈
            } 
            else {
                int idx = get_func_idx(target_pc);
                if (idx != -1 && target_pc == funcs[idx].start_addr) {
                    // 尾调用。
                    if (ftrace_top < FTRACE_STACK_MAX_DEPTH - 1) {
                        uint32_t current_ret_addr = ftrace_stack[ftrace_top].ret_addr;
                        ftrace_top++;
                        ftrace_stack[ftrace_top].func_idx = idx;
                        ftrace_stack[ftrace_top].ret_addr = current_ret_addr; // 继承返回地址
                    }

                    const char *name = funcs[idx].name;
                    fprintf(ftrace_fp, "%*s0x%08x: call [%s@0x%08x]\n", 
                            ftrace_top * 2, "", pc, name, target_pc);
                }
            }
        }
    }
#endif
}

void record_dtrace(RECORD_MODE mode,paddr_t addr,int len,word_t data,const char *name){
#ifdef CONFIG_FTRACE
    if (dtrace_fp != NULL) { 
        if(mode == READ_TRACE)
            fprintf(dtrace_fp,"read device: raddr=%u rlen=%u rdata=%u name=%s\n",addr,len, data, name); 
        else
            fprintf(dtrace_fp,"write device: waddr=%u wlen=%u wdata=%u name=%s\n",addr,len, data, name); 
        fflush(dtrace_fp); 
    } 
#endif
}

void record_etrace(word_t NO, vaddr_t epc,word_t mtvec){
    #ifdef CONFIG_ETRACE
    if (etrace_fp != NULL) { 
        fprintf(etrace_fp,"mcause: 0x%x   mepc: 0x%x   mtvec: 0x%x\n",NO,epc, mtvec); 
        fflush(etrace_fp); 
    } 
#endif
}

void init_trace_file(const char *trace_dir , const char *file_name, FILE**fpp){
    char trace_path[1024*4];
    FILE *fp = NULL;
    if(trace_dir){
        strcpy(trace_path,trace_dir);
        strcat(trace_path,"/");
        strcat(trace_path,file_name);
    }else{
        strcpy(trace_path,file_name);
    }
    fp = fopen(trace_path, "w");
    Assert(fp, "Can not open '%s'", trace_path);
    *fpp = fp;
}


#ifdef CONFIG_FTRACE
void init_ftrace(const char *trace_dir,const char *elf_file){
    init_trace_file(trace_dir,"ftrace.txt",&ftrace_fp);
        // 初始化栈
    ftrace_top = -1; 

    extract_elf_functions(elf_file);
    Log("ftrace is written to %s (Found %d functions)", trace_dir, funcs_count);
}
#endif

void init_trace(const char *trace_dir,const char *elf_file){

    // init mtrace
#ifdef CONFIG_MTRACE
    init_trace_file(trace_dir,"mtrace.txt",&mtrace_fp);
#endif

#ifdef CONFIG_DTRACE
    init_trace_file(trace_dir,"dtrace.txt",&dtrace_fp);
#endif
    // init ftrace
#ifdef CONFIG_FTRACE
    init_ftrace(trace_dir,elf_file);
#endif
#ifdef CONFIG_ETRACE
    init_trace_file(trace_dir,"etrace.txt",&etrace_fp);
#endif
}