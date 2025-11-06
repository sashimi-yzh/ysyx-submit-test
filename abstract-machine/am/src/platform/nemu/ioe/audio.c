#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

void __am_audio_init() {
}

/**
 * AM声卡控制器信息, 可读出存在标志present以及流缓冲区的大小bufsize
 */
void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = false;
  /*cfg->present = true;
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR); // Stream buffer*/
}

/**
 * AM声卡控制寄存器, 可根据写入的freq, channels和samples对声卡进行初始化.
 */
void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  /*outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);*/
}

/**
 * AM声卡状态寄存器, 可读出当前流缓冲区已经使用的大小count.
 */
void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = 0;
  //stat->count = inl(AUDIO_COUNT_ADDR);
}

/**
 * M声卡播放寄存器, 可将[buf.start, buf.end)区间的内容作为音频数据写入流缓冲区. 
 * 若当前流缓冲区的空闲空间少于即将写入的音频数据, 此次写入将会一直等待, 直到有足够的空闲空间将音频数据完全写入流缓冲区才会返回.
 */
void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  /*int len = ctl->buf.end - ctl->buf.start;
  // 若当前流缓冲区的空闲空间少于即将写入的音频数据, 此次写入将会一直等待,
  while(inl(AUDIO_SBUF_SIZE_ADDR) - inl(AUDIO_COUNT_ADDR) <= len) ;
  int count = inl(AUDIO_COUNT_ADDR);
  uintptr_t buf_write_addr = AUDIO_SBUF_ADDR + count;
  uintptr_t *buf_data_start = (uintptr_t*)ctl->buf.start;*/
  // write data to mem
  
}
