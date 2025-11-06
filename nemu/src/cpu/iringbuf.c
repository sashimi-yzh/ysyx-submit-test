/**
 * 实现指令的环形缓存
 */
#include <cpu/iringbuf.h>

static INST_BUFFER inst_buf;

void init_inst_buffer(){
    inst_buf.start = 0;
    inst_buf.end = 0;
    inst_buf.store = false;
}

void write_inst_buffer(char* inst){
    if(inst_buf.end == inst_buf.start && inst_buf.store){
        inst_buf.start = (inst_buf.start+1)%MAX_INST_BUFFER;
    }
    inst_buf.store = true;
    strcpy(inst_buf.inst[inst_buf.end], inst);
    inst_buf.end = (inst_buf.end+1)%MAX_INST_BUFFER;
}

void print_inst_buffer(){
    int end = (inst_buf.store && inst_buf.start == inst_buf.end) ? (inst_buf.end+MAX_INST_BUFFER) : inst_buf.end;
    for(int i = inst_buf.start;i < end - 1;i++){
        printf("\t%s\n",inst_buf.inst[i%MAX_INST_BUFFER]);
    }
    if(inst_buf.start != inst_buf.end || (inst_buf.start == inst_buf.end && inst_buf.store == true)){
        printf("-->\t%s\n",inst_buf.inst[(end-1)%MAX_INST_BUFFER]);
    }
}