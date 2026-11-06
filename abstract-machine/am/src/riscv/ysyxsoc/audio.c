#include <am.h>
#include <riscv/riscv.h>

#define DEVICE_BASE 0xa0000000
#define MMIO_BASE 0xa0000000
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)
#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)
#define AUDIO_WP_ADDR     (AUDIO_ADDR + 0x18)
#define AUDIO_RP_ADDR     (AUDIO_ADDR + 0x1c)
#define AUDIO_BUF_SIZE 0x10000


static uint32_t app_wp = 0;



void __am_audio_init() {
  outl(AUDIO_INIT_ADDR, 1);

  app_wp = 0;
  outl(AUDIO_WP_ADDR, app_wp);

}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  if (ctrl->freq) {
    outl(AUDIO_FREQ_ADDR, ctrl->freq);
  }
  if (ctrl->channels) {
    outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  }
  if (ctrl->samples) {
    outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  }
  
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
  //printf("%d\n", audio_count);
  //outl(AUDIO_COUNT_ADDR, audio_count);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  Area *area = &ctl->buf;
    uint8_t *src = (uint8_t *)area->start;
    uint32_t len = (uint8_t *)area->end - src;
    
    if (len == 0) {
    // 更新写指针
    outl(AUDIO_WP_ADDR, app_wp);
    return;
  }
    
    // 获取当前缓冲区使用情况
    uint32_t total_size = inl(AUDIO_SBUF_SIZE_ADDR);
    uint32_t used = inl(AUDIO_COUNT_ADDR);
    uint32_t free_space = total_size - used;

    if (len > free_space) {
    len = free_space;
  }
    if (len == 0) return;
    
    uint8_t *hw_buf = (uint8_t *)(uintptr_t)AUDIO_SBUF_ADDR;
    if (app_wp + len <= total_size) {
    // 情况1: 不需要回绕
    for (uint32_t i = 0; i < len; i++) {
      hw_buf[app_wp + i] = src[i];
    }
    app_wp += len;
  } else {
    // 情况2: 需要回绕
    uint32_t part1 = total_size - app_wp;
    for (uint32_t i = 0; i < part1; i++) {
      hw_buf[app_wp + i] = src[i];
    }
    
    uint32_t part2 = len - part1;

    for (uint32_t i = 0; i < part2; i++) {
      hw_buf[i] = src[part1 + i];
    }
    app_wp = part2;
  }
    
    // 更新已使用空间计数
  outl(AUDIO_WP_ADDR, app_wp);
  
  // 设置返回区域
  ctl->buf.start = (void *)(hw_buf + app_wp);
  ctl->buf.end = (void *)(hw_buf + app_wp + len);
}
