/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
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
#include <SDL2/SDL_audio.h>
#include <common.h>
#include <device/map.h>
#include <stdio.h>
#include <stdlib.h>

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

static void fill_audio_callback(void *udata, Uint8 *stream, int len) {
  SDL_memset(stream, 0, len);
  static int last_pos = 0;
  if (len == 0) {
    return;
  }
  if (len > audio_base[reg_count])
    len = audio_base[reg_count];
  if (last_pos + len <= CONFIG_SB_SIZE) {
    SDL_MixAudio(stream, udata + last_pos, len, SDL_MIX_MAXVOLUME);
    last_pos += len;
  } else {
    SDL_MixAudio(stream, udata + last_pos, CONFIG_SB_SIZE - last_pos,
                 SDL_MIX_MAXVOLUME);
    SDL_MixAudio(stream + CONFIG_SB_SIZE - last_pos, udata,
                 len - CONFIG_SB_SIZE + last_pos, SDL_MIX_MAXVOLUME);
    last_pos = len - CONFIG_SB_SIZE + last_pos;
  }

  audio_base[reg_count] -= len;
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if (audio_base[reg_init] && is_write) {
    if (SDL_InitSubSystem(SDL_INIT_AUDIO)) {
      fprintf(stderr, "Could not initialize SDL - %s\n", SDL_GetError());
      exit(-1);
    }
    SDL_CloseAudio();
    SDL_AudioSpec sdlAudioSpec = {.freq = audio_base[reg_freq],
                                  .format = AUDIO_S16SYS,
                                  .channels = audio_base[reg_channels],
                                  .silence = 0,
                                  .samples = audio_base[reg_samples],
                                  .callback = fill_audio_callback,
                                  .userdata = sbuf};
    if (SDL_OpenAudio(&sdlAudioSpec, NULL) < 0) {
      fprintf(stderr, "Can't open audio - %s\n", SDL_GetError());
      exit(-1);
    }
    audio_base[reg_init] = 0;
    SDL_PauseAudio(0);
  }
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
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
}
