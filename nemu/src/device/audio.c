/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>

enum {
  reg_freq,
  reg_channels,
  reg_samples,
  reg_sbuf_size,
  reg_init,
  reg_count,
  nr_reg
};

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;
// static uint32_t sbuf_wpos = 0;
static uint32_t sbuf_rpos = 0;
static SDL_AudioSpec s;
static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  offset /= 4;
  if (is_write) {
    switch (offset) {
    case reg_freq: {
      s.freq = audio_base[reg_freq];
      SDL_CloseAudio();
      SDL_OpenAudio(&s, NULL);
      SDL_PauseAudio(0);
      break;
    }
    case reg_channels: {
      s.channels = audio_base[reg_channels];
      SDL_CloseAudio();
      SDL_OpenAudio(&s, NULL);
      SDL_PauseAudio(0);
      break;
    }
    case reg_samples: {
      s.samples = audio_base[reg_samples];
      SDL_CloseAudio();
      SDL_OpenAudio(&s, NULL);
      SDL_PauseAudio(0);
      break;
    }
    default:
      break;
    }
  }
}
static void sdl_audio_callback(void *userdata, Uint8 *stream, int len) {
  // 引用缓冲区信息
  const int bufsize = audio_base[reg_sbuf_size];
  uint32_t *count = &audio_base[reg_count];
  // 计算可播放长度
  int avail = *count < len ? *count : len;
  for (int i = 0; i < avail; i++) {
    stream[i] = sbuf[(sbuf_rpos + i) % bufsize];
  }
  sbuf_rpos = (sbuf_rpos + avail) % bufsize;
  // 更新缓冲区状态寄存器
  *count -= avail;
  // 静音填充剩余部分
  for (int i = avail; i < len; i++)
    stream[i] = 0;
}
void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  SDL_Init(SDL_INIT_AUDIO);
  SDL_zero(s);
  s.freq = 8000;
  s.format = AUDIO_S16LSB;
  s.channels = 1;
  s.samples = 1024;
  s.callback = sdl_audio_callback;
  SDL_OpenAudio(&s, NULL);
  SDL_PauseAudio(0);
}
