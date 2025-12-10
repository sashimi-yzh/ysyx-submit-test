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
static int sbuf_rpos = 0;

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static void audio_play(void *userdata, Uint8 *stream, int len) {
  int play_len = len;
  int count = audio_base[reg_count];
  if(play_len > count) play_len = count;
  memcpy(stream, sbuf + sbuf_rpos, play_len);
  if(len > play_len) memset(stream + play_len, 0, len - play_len);
  sbuf_rpos += play_len;
  if (sbuf_rpos >= CONFIG_SB_SIZE) sbuf_rpos -= CONFIG_SB_SIZE;
  audio_base[reg_count] -= play_len;
  // printf("len = %d, play_len = %d, len - play_len = %d\n", len, play_len, len - play_len);
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if(offset == 12) {
    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  }
  if(offset == 16 && is_write) {
    SDL_AudioSpec sound = {};
    sound.freq = audio_base[reg_freq];
    sound.channels = audio_base[reg_channels];
    sound.samples = audio_base[reg_samples];
    sound.format = AUDIO_S16SYS;
    sound.callback = audio_play;
    sound.userdata = NULL;

    int ret = SDL_InitSubSystem(SDL_INIT_AUDIO);
    if (ret == 0) {
      SDL_OpenAudio(&sound, NULL);
      SDL_PauseAudio(0);
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
