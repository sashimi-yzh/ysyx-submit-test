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
static int front = 0, tail = 0;
static SDL_AudioSpec s = {};
void work(uint32_t x);

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  int index = offset / sizeof(uint32_t);
  switch (index) {
  case reg_freq: assert(is_write);
    s.freq = audio_base[reg_freq];
    break;
  case reg_channels: assert(is_write);
    s.channels = audio_base[reg_channels];
    break;
  case reg_samples: assert(is_write);
    s.samples = audio_base[reg_samples];
    break;
  case reg_sbuf_size: assert(!is_write);
    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
    break;
  case reg_count:
    if (is_write) tail = audio_base[reg_count];
    else audio_base[reg_count] = tail;
    assert(tail <= CONFIG_SB_SIZE);
    break;
  case reg_init:
    assert(is_write); work(audio_base[reg_init]); break;
  default: printf("%d\n", index);
  }
}

static void audio_play(void *userdata, uint8_t *stream, int len) {
  int nread = len;
  if (tail - front < len) nread = tail - front;
  memcpy(stream, sbuf + front, nread);
  front += nread;
  if (len > nread) memset(stream + nread, 0, len - nread);
  if (front == tail) front = tail = 0;
  return;
}


void work(uint32_t inited) {
  if (!inited) return;
  if (inited) {
    int ret = SDL_InitSubSystem(SDL_INIT_AUDIO);
    if (!ret) {
      SDL_OpenAudio(&s, NULL);
      SDL_PauseAudio(0);
    }
  }
  return;
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
  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  s.format = AUDIO_S16SYS;
  s.userdata = NULL;
  s.callback = audio_play;
  SDL_InitSubSystem(SDL_INIT_AUDIO);
}
