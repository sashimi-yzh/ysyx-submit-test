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

#include "debug.h"
#include "difftest-def.h"
#include <SDL2/SDL_audio.h>
#include <assert.h>
#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>
#include <stdint.h>
#include <string.h>

enum {
  reg_freq,
  reg_channels,
  reg_samples,
  reg_sbuf_size,
  reg_init,
  reg_count,
  reg_tail_offset,
  // reg_lock,
  nr_reg
};

static uint8_t *sbuf_start = NULL, *sbuf_end = NULL;
static uint32_t sbuf_head = 0, sbuf_tail = 0;
static uint32_t *audio_base = NULL;


static void sdlaudio_callback(void *userdata, uint8_t *stream, int len) {
  memset(stream, 0, len);
  uint32_t sbuf_used = (sbuf_tail - sbuf_head) % CONFIG_SB_SIZE;
  assert(audio_base[reg_count] == sbuf_used);
  if (sbuf_used > 0) {
    uint32_t length = sbuf_used < len ? sbuf_used : len;
    if (sbuf_head + length < CONFIG_SB_SIZE) {
      memcpy(stream, sbuf_start + sbuf_head, length); 
    } else {
      uint32_t len1 = CONFIG_SB_SIZE - sbuf_head;
      uint32_t len2 = length - len1;
      uint8_t *addr = mempcpy(stream, sbuf_start + sbuf_head, len1);
      memcpy(addr, sbuf_start, len2);
    }
    sbuf_head = (sbuf_head + length) % CONFIG_SB_SIZE;
    audio_base[reg_count] -= length;
  } 
}

static void init_sdlaudio(uint32_t freq, uint32_t channels, uint32_t samples) {
  SDL_AudioSpec s = {};
  s.format = AUDIO_S16SYS;
  s.userdata = NULL;
  int32_t sfreq;
  memcpy(&sfreq, &freq, 4);
  s.freq = sfreq;
  s.channels = channels;
  s.samples = samples;
  s.callback = sdlaudio_callback;
  SDL_InitSubSystem(SDL_INIT_AUDIO);
  SDL_OpenAudio(&s, NULL);
  SDL_PauseAudio(0);
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  assert(offset % 4 == 0);
  if (is_write) {
    switch (offset / 4) {
      case reg_init:
        if (audio_base[reg_init] != 0) {
          init_sdlaudio(audio_base[reg_freq], audio_base[reg_channels], 
                        audio_base[reg_samples]);
          audio_base[reg_init] = 0;
        }
        break;
      case reg_tail_offset:
        sbuf_tail = audio_base[reg_tail_offset];
        audio_base[reg_count] = (sbuf_tail - sbuf_head) % CONFIG_SB_SIZE;
        break;
      /*
      case reg_lock:
        if (audio_base[reg_lock]) {
          SDL_LockAudio();
        } else {
          SDL_UnlockAudio();
        }
        break;
      */
    }
  }
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
  audio_base[reg_count] = 0;
  audio_base[reg_tail_offset] = 0;
  // audio_base[reg_lock] = 0;
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler, true);
#endif

  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  sbuf_start = (uint8_t *)new_space(CONFIG_SB_SIZE);
  sbuf_end = sbuf_start + CONFIG_SB_SIZE;
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf_start, CONFIG_SB_SIZE, NULL, true);
}
