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
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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

static uint32_t audio_rd_pos;
static uint32_t audio_wt_pos;
static uint32_t count;
static bool overflow = false;

void audio_callback(void *userdata, uint8_t *stream, int len) {
  SDL_memset(stream ,0,len);
  if (count == 0)
    return;
  int write_len = (len > count) ? count : len;
  if(audio_rd_pos + write_len >= CONFIG_SB_SIZE){
    size_t len1 = CONFIG_SB_SIZE - audio_rd_pos;
    size_t len2 = write_len - len1;
    SDL_memcpy(stream, sbuf+audio_rd_pos, len1);
    SDL_memcpy(stream+len1 ,sbuf,len2);
    audio_rd_pos = len2;
  }else{
    SDL_memcpy(stream, sbuf+audio_rd_pos, write_len);
    audio_rd_pos += write_len;
  }
  count -= write_len;
}

SDL_AudioSpec s = {
    .freq = 0,                    // 采样率：44.1 kHz (CD音质)
    .format = AUDIO_S16SYS,           // 格式：16 位有符号整数，采用系统字节序
    .channels = 0,                  // 声道数：单声道 (如果是立体声就是 2)
    .samples = 0,                  // 缓冲区大小：4096 个采样点 (影响延迟，越小延迟越低但越卡)
    .callback = audio_callback,     // 注册回调函数！
    .userdata = NULL,                // 传给回调函数的参数

};

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)


static void audio_reg_init(){
  if(audio_base[4] == 1){
    SDL_PauseAudio(1);
    SDL_CloseAudio();
    audio_rd_pos = 0;
    audio_wt_pos = 0;
    count = 0;
    SDL_OpenAudio(&s,NULL);
    SDL_PauseAudio(0);
    audio_base[reg_init] = 0;
  }
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  // assert(is_write);
  switch (offset)
  {
  case 0:
    if(is_write)
      s.freq = audio_base[reg_freq];
    break;
  case 4:
    if(is_write)
      s.channels = audio_base[reg_channels];
    break;
  case 8:
    if(is_write)
      s.samples = audio_base[reg_samples];
    break;
  case 12:
    if(!is_write)
      audio_base[reg_sbuf_size] = 64*1024;
    break;
  case 16:
    audio_reg_init();
    break;
  case 20:
    if(is_write){ // write len
      SDL_LockAudio();
      if(count + audio_base[reg_count] > CONFIG_SB_SIZE){
        overflow = true;
      }
      count += audio_base[reg_count];
      audio_wt_pos = (audio_wt_pos + audio_base[reg_count]) % CONFIG_SB_SIZE;
      if(overflow) audio_rd_pos = (audio_wt_pos + 1) % CONFIG_SB_SIZE;
      overflow = false;
      SDL_UnlockAudio();
    }else{ // read count 
      SDL_LockAudio();
      audio_base[reg_count] = count;
      SDL_UnlockAudio();
    }
    break;
  default:
    fprintf(stderr,"audio write offset error, offset:%d\n",offset);
    assert(0);
    break;
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
  audio_rd_pos = 0;
  audio_wt_pos = 0;
  count = 0;
  if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
      fprintf(stderr,"SDL initiate failed: %s\n", SDL_GetError());
      assert(0);
  }
  s.freq = audio_base[reg_freq];
  s.channels = audio_base[reg_channels];
  s.samples = audio_base[reg_samples];
  SDL_OpenAudio(&s, NULL);
  SDL_PauseAudio(0);

}
