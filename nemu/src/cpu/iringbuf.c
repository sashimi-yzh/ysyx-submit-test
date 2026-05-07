#include <cpu/iringbuf.h>

#define MAX_IRINGBUF 10

IRingBuffer iringbuf[MAX_IRINGBUF];
static int position=0;

void iringbuf_write(uint32_t pc, char* logbuf){
    iringbuf[position].pc = pc;
    strcpy(iringbuf[position].logbuf,logbuf);

    position = (position + 1) % MAX_IRINGBUF;

}

void iringbuf_print(){
#ifdef CONFIG_ITRACE
    int i;
    for(i=0;i<MAX_IRINGBUF;i++) {
        printf("%x : %s\n",iringbuf[i].pc,iringbuf[i].logbuf);
    }


#endif
}
