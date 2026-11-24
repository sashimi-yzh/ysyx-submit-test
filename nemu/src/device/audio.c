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
#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>

#define AUDIO_FREQ_OFFSET       0x00
#define AUDIO_CHANNELS_OFFSET   0x04
#define AUDIO_SAMPLES_OFFSET    0x08
#define AUDIO_SBUF_SIZE_OFFSET  0x0c
#define AUDIO_INIT_OFFSET       0x10
#define AUDIO_COUNT_OFFSET      0x14

SDL_AudioSpec wav_spec;
#define SBUF_SIZE 0x10000;  //64K

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
static int rfd = -1, wfd = -1, fds[2];
static volatile int count = 0;

static void audio_play(void *userdata, Uint8 *stream, int len) {
  int nread = len;
  if (count < len) nread = count;
  int b = 0;
  while (b < nread) {
    int n = read(rfd, stream, nread);
    if (n > 0) b += n;
  }

  count -= nread;
  if (len > nread) {
    memset(stream + nread, 0, len - nread);
  }
}

static void audio_write(uint8_t *buf, int len) {
  int nwrite = 0;
  while (nwrite < len) {
    int n = write(wfd, buf, len);
    if (n == -1) n = 0;
    count += n;
    nwrite += n;
  }
}

void audio_init() {
  int ret;
  ret = pipe2(fds, O_NONBLOCK);
  assert(ret == 0);
  rfd = fds[0];
  wfd = fds[1];
  ret = SDL_InitSubSystem(SDL_INIT_AUDIO);
  assert(ret == 0);
  wav_spec.format = AUDIO_S16SYS;
  wav_spec.callback = audio_play;
  wav_spec.userdata = NULL;
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  uint8_t index = offset / sizeof(uint32_t);
  switch (index) {
    case reg_freq:
      if (is_write)
        wav_spec.freq = audio_base[index];
      break;
    case reg_channels:
      if (is_write)
        wav_spec.channels = audio_base[index];
      break;
    case reg_samples:
      if (is_write)
        wav_spec.samples = audio_base[index];
      break;
    case reg_sbuf_size:
      if (is_write)
        audio_base[index] = fcntl(rfd, F_GETPIPE_SZ);
      break;
    case reg_init:
      if (is_write) {
          SDL_OpenAudio(&wav_spec, NULL);
          SDL_PauseAudio(0);
        }
      break;
    case reg_count:
      if (!is_write) {
        audio_base[index] = count;
      }
      break;
    default:
      panic("Unknown audio register access at offset 0x%x", offset);
  }
}

static void audio_play_handler(uint32_t offset, int len, bool is_write) {
  audio_write(sbuf + offset, len);
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
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, audio_play_handler);
  audio_init();
}
