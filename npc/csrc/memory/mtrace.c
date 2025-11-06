#include <mtrace.h>

const char* mtrace_log_file = "./mtrace.log";

void init_mtrace_log(){

#ifdef CONFIG_MTRACE

    FILE *file = fopen(mtrace_log_file, "w");
    if(file == NULL){
        panic("打开或创建文件时出错");
    }

    fclose(file);
#endif

}

void mtrace_log_write(paddr_t addr, int len, char operate,word_t data){

#ifdef CONFIG_MTRACE

    FILE *file = fopen(mtrace_log_file, "a+");
    if(file == NULL){
        panic("打开文件时出错");
    }
    
    if(operate == 'r'){
        fprintf(file, "This has read addr : %#x, len : %d\n", addr, len);
    }else if(operate == 'w'){
        fprintf(file, "This has wrote addr : %#x, len : %d, the data is %#x\n", addr, len, data);
    }
    fclose(file);

#endif

}