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
/*
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

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
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
*/
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

static uint32_t head = 0;
static bool audio_inited = false;

static void audio_callback(void *userdata, uint8_t *stream, int len) {
  uint32_t count = audio_base[reg_count];
  uint32_t sbuf_size = audio_base[reg_sbuf_size];

  int nread = (count < (uint32_t)len) ? count : (uint32_t)len;

  for (int i = 0; i < nread; i++) {
    stream[i] = sbuf[head];
    head = (head + 1) % sbuf_size;
  }

  audio_base[reg_count] -= nread;

  if (nread < len) {
    memset(stream + nread, 0, len - nread);
  }
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if (!is_write) return;

  switch (offset) {
    case reg_init * sizeof(uint32_t): {
      if (audio_inited) break;

      SDL_AudioSpec s;
      memset(&s, 0, sizeof(s));

      s.freq = audio_base[reg_freq];
      s.channels = audio_base[reg_channels];
      s.samples = audio_base[reg_samples];
      s.format = AUDIO_S16SYS;
      s.callback = audio_callback;
      s.userdata = NULL;

      audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
      audio_base[reg_count] = 0;
      head = 0;

      SDL_InitSubSystem(SDL_INIT_AUDIO);
      if (SDL_OpenAudio(&s, NULL) < 0) {
        panic("SDL_OpenAudio failed: %s", SDL_GetError());
      }
      SDL_PauseAudio(0);

      audio_inited = true;

      Log("Audio initialized: freq=%d channels=%d samples=%d",
          s.freq, s.channels, s.samples);
      break;
    }
    default:
      break;
  }
}

static void audio_sbuf_handler(uint32_t offset, int len, bool is_write) {
  if (is_write) {
    audio_base[reg_count] += len;
    Assert(audio_base[reg_count] <= CONFIG_SB_SIZE, "audio count overflow");
  }
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
  memset(audio_base, 0, space_size);

  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  audio_base[reg_count] = 0;

#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  memset(sbuf, 0, CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, audio_sbuf_handler);

  head = 0;
  audio_inited = false;
}