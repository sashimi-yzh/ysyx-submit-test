#include <memory/mtrace.h>

char mtrace_file_path[] = "./mtrace.log"; 
char dtrace_file_path[] = "./dtrace.log";

void init_mtrace_log(){

#ifdef CONFIG_MTRACE

    FILE *file = fopen(mtrace_file_path, "w");
    if(file == NULL){
        panic("打开或创建文件时出错");
    }

    fclose(file);
#endif

}

void mtrace_log_write(paddr_t addr, int len, char operate,word_t data){

#ifdef CONFIG_MTRACE

    FILE *file = fopen(mtrace_file_path, "a+");
    if(file == NULL){
        panic("打开文件时出错");
    }
    
    if(operate == 'r'){
        fprintf(file, "This has read addr : 0x%x, len : %d\n", addr, len);
    }else if(operate == 'w'){
        fprintf(file, "This has wrote addr : 0x%x, len : %d, the data is %x\n", addr, len, data);
    }
    fclose(file);

#endif

}

void init_dtrace_log(){

#ifdef CONFIG_DTRACE

    FILE *file = fopen(dtrace_file_path, "w");
    if(file == NULL){
        panic("打开或创建文件时出错");
    }

    fclose(file);
#endif

}

void dtrace_log_write(paddr_t addr, int len, char operate,IOMap *map,word_t data){

#ifdef CONFIG_DTRACE

    FILE *file = fopen(dtrace_file_path, "a+");
    if(file == NULL){
        panic("打开文件时出错");
    }
    
    if(operate == 'r'){
        fprintf(file, "device %s read addr : 0x%x, len : %d\n", map->name, addr, len);
    }else if(operate == 'w'){
        fprintf(file, "device %s has wrote addr : 0x%x, len : %d, the data is %x\n", map->name, addr, len, data);
    }
    fclose(file);

#endif

}