#include <isa.h>
#include <cpu/top.h>
#include <cpu/cpu.h>

void isa_reg_display(){
    printf("npc register: \n");
    for (int i=0;i<gpr_size;i++){
        printf("%4s:%.8x",regs[i],top_gpr(i));
        (i%3==0)?printf("\n"):printf(" ");
    }
    
    printf("\n%4s:%.8x\n","pc",top_pc());
    for (int i=0;i<csr_size;i++){
        printf("%4s:%.8x",csr_names[i],top_csr(i));
        (i%3==1)?printf("\n"):printf(" ");
    }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  word_t val;
  if(strstr(s,"$pc")){
    return top_pc();
  }
  for (int i = 0; i < csr_size; i++) {
    if (strstr(s, csr_names[i])) {
      val = top_csr(i);
      *success = true;
      return val;
    }
  }

  for (int i= 0;i<gpr_size;i++){
      if (strstr(s,regs[i])){
        val = top_gpr(i);
        *success = true;
        break;
      } 
  }
  return val;
}