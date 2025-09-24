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
static SDL_AudioSpec s;

static void audioCallback(void *userdata, uint8_t *stream, int len) {
  static int index = 0;
  int real_len = len;
  if (audio_base[5] < len)
    real_len = audio_base[5];

  SDL_memcpy(stream, sbuf + index, real_len);
  if (len > real_len)
    SDL_memset(stream + real_len, 0, len - real_len);

  audio_base[5] -= real_len;
  index = (index + len) % CONFIG_SB_SIZE;
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if (is_write) {
    if (offset == 0) {
      s.freq = audio_base[0];
    } else if (offset == 4) {
      s.channels = audio_base[1];
    } else if (offset == 8) {
      s.samples = audio_base[2];
    } else if (offset == 16) {
      if (audio_base[4]) {
        SDL_InitSubSystem(SDL_INIT_AUDIO);
        s.format = AUDIO_S16SYS;
        s.callback = audioCallback;
        Assert(SDL_OpenAudio(&s, NULL) == 0, "%s", SDL_GetError());
        SDL_PauseAudio(0);
      }
    } else if (offset == 20) {
    } else {
      Assert(0, "can not write this addr");
    }
  } else {
    if (offset == 12) {
      audio_base[3] = CONFIG_SB_SIZE;
    } else if (offset == 20) {
    } else {
      Assert(0, "can not read this addr");
    }
  }
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
