#include<monitor/sdb.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<stdlib.h>
#include "memory/pmem.h"
#include "cpu/cpu.h"
#include "isa/reg.h"
static int is_batch_mode=false;
void sdb_set_batch_mode(){
    is_batch_mode=true;
}
static char* rl_gets(){
    static char * line_read=NULL;
    if(line_read){
        free(line_read);
        line_read=NULL; 
    }
    line_read=readline("(npc) ");
    if(line_read&&*line_read){
        add_history(line_read);
    }
    return line_read;
}
static int cmd_q(char *args){
    npc_state.state=NPC_QUIT;
    return -1;
}
static int cmd_c(char *args){
    cpu_exec(-1);
    return 0;
}
static int cmd_si(char *args){
    char *arg=strtok(NULL," ");
    if(arg==NULL){
        cpu_exec(1);
    }else{
        int i=atoi(arg);
        cpu_exec(i);
    }
    return 0;
}
static int cmd_info(char*args){
    char *arg=strtok(NULL," ");
    if(arg==NULL){
        printf("Input info r or info w\n");
    }else{
        if(strcmp(arg,"r")==0){
            get_cpu_state(&cpu_dut);
            isa_reg_display(&cpu_dut);
        }else if(strcmp(arg,"f")==0){
            ftrace_print();            
        }
    }
    return 0;
}
static int cmd_x(char *args){
    int i;uint32_t p;
    int ret=sscanf(args,"%d %x",&i,&p);
    if(ret!=2){
        printf("please input: x n expr\n");
    }
    int j;uint32_t value;
    for(j=0;j<i;j++){
        if((p+j*4)>=MROM_START&&((p+j*4)<(MROM_START+MROM_SIZE)))
            mrom_read(p+j*4,(int32_t*)&value);
        if((p+j*4)>=PSRAM_START&&((p+j*4)<(PSRAM_START+PSRAM_SIZE)))
            paddr_read(p+j*4,(int32_t*)&value);
        else
            flash_read((p+j*4)&0x00ffffff,(int32_t*)&value);
        printf("%02X %02X %02X %02X\n",(value>>24)&0xff,(value>>16)&0xff,(value>>8)&0xff,value&0xff);
    }
    return 0;
}
static struct{
    const char*name;
    const char *description;
    int (*handler)(char*);
}cmd_table[]={
    {"c","Continue the execution of the program",cmd_c},
    {"si","Execute the program n times",cmd_si},
    {"info","Print registers",cmd_info},
    {"x","Scan the memory",cmd_x},
    {"q","Exit NPC",cmd_q},
};
#define NR_CMD (int)(sizeof(cmd_table)/sizeof(cmd_table[0]))


void sdb_main_loop(){
    if(is_batch_mode){
        cmd_c(NULL);
        return ;
    }
    for(char *str;(str=rl_gets())!=NULL;){
        char *str_end=str+strlen(str);
        char* cmd=strtok(str," ");
        if(cmd==NULL)continue;
        char *args=cmd+strlen(cmd)+1;
        if(args>=str_end){
            args=NULL;
        }
        int i;
        for(i=0;i<NR_CMD;i++){
            if(strcmp(cmd,cmd_table[i].name)==0){
                if(cmd_table[i].handler(args)<0){return ;}
                break;
            }
        }
        if(i==NR_CMD){printf("Unknown command '%s'\n",cmd);}
    }

}
