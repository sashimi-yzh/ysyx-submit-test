#include <riscv/riscv.h>
#include <am.h>

extern uint32_t _SSBL_lma_start;
extern uint32_t _SSBL_start;
extern uint32_t _SSBL_end;

void first_stage_bootloader() __attribute__((section(".FSBL")));

void first_stage_bootloader(){
  uint32_t *dst = &_SSBL_start;
  uint32_t *src = &_SSBL_lma_start;
  uint32_t *end = &_SSBL_end;

  while(dst < end){
    *dst = *src;
    dst++;
    src++; 
  }
}

extern uint32_t _bss_start;
extern uint32_t _bss_end;

extern uint32_t _text_lma_start;
extern uint32_t _text_vma_start;
extern uint32_t _text_vma_end;
extern uint32_t _data_lma_start;
extern uint32_t _data_vma_start;
extern uint32_t _data_vma_end;

void second_stage_bootloader() __attribute__((section(".SSBL")));

int main();

void second_stage_bootloader(){
  uint32_t *dst = &_text_vma_start;
  uint32_t *src = &_text_lma_start;
  uint32_t *end = &_text_vma_end;

  while(dst < end){
    *dst = *src;
    dst++;
    src++;
  }

  dst = &_data_vma_start;
  src = &_data_lma_start;
  end = &_data_vma_end;

  while(dst < end){
    *dst = *src;
    dst++;
    src++;
  }

  // .bss 是 NOLOAD 段，必须由软件清零（不能假设存储器初值为 0）
  for(dst = &_bss_start; dst < &_bss_end; dst++){
    *dst = 0;
  }

  asm volatile("fence.i;");
}