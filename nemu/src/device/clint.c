
#include <common.h>
#include <device/soc.h>
#include <utils.h>

#define CLINT_SIZE 0x02000000

const uint32_t mtime       =  CLINT_SIZE + 0XBFF8;
const uint32_t mtime_high  =  CLINT_SIZE + 0XBFFC;

uint64_t read_mtime(){
    return get_time();
}
word_t clint_read(paddr_t addr, int len){
    uint64_t t = read_mtime();
    word_t result = 0; 
    if (addr == mtime) result = (word_t)t;
    else if (addr == mtime_high) result = (word_t)(t>>32);

    return result;
}

