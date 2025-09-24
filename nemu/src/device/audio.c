/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <SDL2/SDL.h>
#include <common.h>
#include <device/map.h>

enum {
  reg_freq,      // 0
  reg_channels,  // 1
  reg_samples,   // 2
  reg_sbuf_size, // 3
  reg_init,      // 4
  reg_count,     // 5
  reg_w,         // 6
  reg_r,         // 7
  nr_reg
};

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static void callback(void *userdata, Uint8 *stream, int len) {
  uint32_t *r_ptr = audio_base + reg_r;
  uint32_t *buf_size = audio_base + reg_sbuf_size;
  uint32_t *count = audio_base + reg_count;

  for (int i = 0; i < len; i++) {
    // 使用count判断，就无需判断读写指针相同的情况
    if (*count != 0) {
      stream[i] = sbuf[(*r_ptr)++];
      *r_ptr %= *buf_size;
      (*count)--;
    } else {
      stream[i] = 0;
    }
  }
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if (audio_base[reg_init] == 1) {
    SDL_AudioSpec s = {};
    s.format = AUDIO_S16SYS; // 假设系统中音频数据的格式总是使用16位有符号数来表示
    s.userdata = NULL; // 不使用
    s.freq = audio_base[reg_freq];
    s.channels = audio_base[reg_channels];
    s.samples = audio_base[reg_samples];
    s.callback = callback;

    SDL_InitSubSystem(SDL_INIT_AUDIO);
    SDL_OpenAudio(&s, NULL);
    SDL_PauseAudio(0);

    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
    audio_base[reg_init] = 0;
    audio_base[reg_count] = 0;
    audio_base[reg_w] = 0;
    audio_base[reg_r] = 0;
  }
}

static void audio_count(uint32_t offset, int len, bool is_write) {
  uint32_t *count = audio_base + reg_count;
  (*count)++;
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size,
              audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size,
               audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, audio_count);
}
