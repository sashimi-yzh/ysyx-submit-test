#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  //kbd->keydown = 0;
  //kbd->keycode = AM_KEY_NONE;
  int k = inl(KBD_ADDR); 
  kbd->keydown = (k & KEYDOWN_MASK ? true : false); //keydown=1表示按下 为0松开
  kbd->keycode = k & ~KEYDOWN_MASK; 
  // if(k!=0) printf("k=%x keydown=%d keycode=%d\n", k, kbd->keydown, kbd->keycode);
}

//naitve
// void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
//   int k = AM_KEY_NONE;

//   SDL_LockMutex(key_queue_lock);
//   if (key_f != key_r) {
//     k = key_queue[key_f];
//     key_f = (key_f + 1) % KEY_QUEUE_LEN;
//   }
//   SDL_UnlockMutex(key_queue_lock);

//   kbd->keydown = (k & KEYDOWN_MASK ? true : false);//第15位是true时表示按下按键
//   kbd->keycode = k & ~KEYDOWN_MASK;//低15位按键信息，按键码
// }