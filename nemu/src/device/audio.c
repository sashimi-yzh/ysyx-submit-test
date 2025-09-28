/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

static int freq, channels, samples;
static int count = 0;
static int sbuf_p = 0;

#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>
static SDL_AudioSpec s = {};

void audio_callback(void *userdata, Uint8 *stream, int len) {
  while (count > 0 && len > 0) {
    --count;
    --len;
    *stream++ = sbuf[sbuf_p];
    sbuf_p = (sbuf_p + 1) % CONFIG_SB_SIZE;
  }
  while (len--) {
    *stream++ = 0;
  }
}

static void audio_dev_init() {
  SDL_InitSubSystem(SDL_INIT_AUDIO);
  s.format = AUDIO_S16SYS;
  s.userdata = NULL;
  s.callback = audio_callback;
}

static void audio_dev_open() {
  s.freq = freq;
  s.channels = channels;
  s.samples = samples;
  SDL_CloseAudio();
  SDL_OpenAudio(&s, NULL);
  SDL_PauseAudio(0);
}

static void sbuf_io_handler(uint32_t offset, int len, bool is_write) {
  assert(is_write);
  count += len;
  SDL_UnlockAudio();
}

#else
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
static void audio_dev_init() {
  assert(io_read(AM_AUDIO_CONFIG).present);
}

static void audio_dev_open() {
  io_write(AM_AUDIO_CTRL, freq, channels, samples);
}

static void sbuf_io_handler(uint32_t offset, int len, bool is_write) {
  assert(is_write);
  count += len;
  int n = MIN(4096, CONFIG_SB_SIZE - sbuf_p);
  if (count >= n) {
    Area buf;
    buf.start = sbuf + sbuf_p;
    buf.end = buf.start + n;
    io_write(AM_AUDIO_PLAY, buf);
    sbuf_p = (sbuf_p + n) % CONFIG_SB_SIZE;
    count -= n;
  }
}
#endif

static void sbuf_io_handler_r(uint32_t offset, int len, bool is_write) {
  IFNDEF(CONFIG_TARGET_AM, SDL_LockAudio());
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  assert((offset & 0b11) == 0);
  switch (offset >> 2) {
    case reg_freq:
      assert(is_write);
      freq = audio_base[reg_freq];
      break;
    case reg_channels:
      assert(is_write);
      channels = audio_base[reg_channels];
      break;
    case reg_samples:
      assert(is_write);
      samples = audio_base[reg_samples];
      break;
    case reg_sbuf_size:
      assert(!is_write);
      audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
      break;
    case reg_init:
      assert(is_write);
      audio_dev_open();
      audio_base[reg_init] = 0;
      break;
    case reg_count:
      assert(!is_write);
      audio_base[reg_count] = count;
      break;
    default:
      assert(0);
      break;
  }
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler, NULL);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, sbuf_io_handler, sbuf_io_handler_r);

  IFDEF(CONFIG_HAS_AUDIO, audio_dev_init());
}
