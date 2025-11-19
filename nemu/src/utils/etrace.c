#include <utils.h>

void etrace(word_t NO, vaddr_t epc){
  #ifdef CONFIG_ETRACE
  char s[20];
  switch (NO)
  {
  case 11:
    sprintf(s ,"EVENT_YIELD  ");
    break;
  case 0 :
    sprintf(s ,"EVENT_SYSCALL");
    break;
  default:
    sprintf(s ,"UNKOWN EVENT id = %d",NO);
    break;
  }
  printf("ETRACE: %s   pc = %#x\n",s,epc); //if you convert printf to log_write,you can write trace to log.
  #endif
}
