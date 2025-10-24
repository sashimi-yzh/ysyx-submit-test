#include "../include/common.h"
#include "../include/debug.h"
#include "../include/conf.h"

/***************************** ITRACE *****************************/
#ifdef CONFIG_ITRACE
#define MAX_iringbuf_size 20
struct IRINGBUF
{
    char inst_buf[MAX_iringbuf_size][64];
    int head, tail;
};

static struct IRINGBUF iringbuf = {
    .inst_buf = {""},
    .head = 0,
    .tail = 0
};

void append_iringbuf(char *s)
{
    // if(iringbuf.inst_buf[iringbuf.head] != NULL)
    if(strcmp(iringbuf.inst_buf[iringbuf.head], ""))    //the iringbuf is not currently empty
    {
        iringbuf.tail = (iringbuf.tail + 1) % MAX_iringbuf_size;  
        if(iringbuf.head == iringbuf.tail)                //the iringbuf is currently full
        iringbuf.head = (iringbuf.head + 1) % MAX_iringbuf_size;
    }

    strcpy(iringbuf.inst_buf[iringbuf.tail], s);
}

void display_iringbuf(void)
{
    int i = iringbuf.head;
    if(iringbuf.inst_buf[i] == NULL)
        return;

    _Log(ANSI_FG_BLUE "Display inst iringbuf:\n" ANSI_NONE);
    while(i != iringbuf.tail)
    {
        printf(ANSI_FG_YELLOW "[ITRACE] " ANSI_NONE "      %s\n", iringbuf.inst_buf[i]);
        log_write("[ITRACE]       %s\n", iringbuf.inst_buf[i]); 
        i = (i + 1) % MAX_iringbuf_size;
    }
    printf(ANSI_FG_YELLOW "[ITRACE] " ANSI_NONE ANSI_FG_RED "---->" ANSI_NONE " %s\n", 
           iringbuf.inst_buf[iringbuf.tail]);
    log_write("[ITRACE] ----> %s\n", iringbuf.inst_buf[iringbuf.tail]); 
}
#endif
/******************************************************************/