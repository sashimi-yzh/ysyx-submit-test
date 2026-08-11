#include<am.h>
#include<nemu.h>
#include<stdint.h>
void __am_input_config(AM_INPUT_CONFIG_T *cfg) { 
      cfg->present = true;  
}
// 这个kdb数据结构如下：
/*
  typedef struct{
    bool keydown;
    int keycode;
  };
*/
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd){
      uint32_t key=inl(KBD_ADDR+0);
      kbd->keydown=(key&0x8000)!=0;
      kbd->keycode=(key&0x7fff);
}