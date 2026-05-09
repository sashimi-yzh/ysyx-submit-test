
#include <cpu/cpu.h>
// #include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

#define BUF_DEPTH 20

static char iring_buf[BUF_DEPTH][50] = {};

static int i = 0;

void init_iringbuf(){
    memset(iring_buf, '\0', sizeof(iring_buf));
}

void ring_write(char *s){
    if(i >= BUF_DEPTH){
        i = 0;
    }
    strcpy(iring_buf[i], s);
    i ++;
}

void ring_print(){
    // log_write("iringbuf_trace\n");
    for(int a = 0; a < BUF_DEPTH; a++){
        if(iring_buf[a][0] != '\0'){
            if(i-1 != a){
                log_write("    %s\n", iring_buf[a]);
            }
            else{
                log_write("--->%s\n", iring_buf[a]);
            }
        }
    }
}

void ring_show(){
    // printf("iringbuf_trace\n");
    for(int a = 0; a < BUF_DEPTH; a++){
        if(iring_buf[a][0] != '\0'){
            if(i - 1 != a){
                printf("    %s\n", iring_buf[a]);
            }
            else{
                printf("--->%s\n", iring_buf[a]);
            }
        }
    }
}

