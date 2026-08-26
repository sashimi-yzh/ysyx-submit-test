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

#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>
#endif

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

#ifndef CONFIG_TARGET_AM
static SDL_AudioSpec s;
void callback_audio_SDL(void *userData, Uint8 * stream, int len){
  SDL_memset(stream, 0, len);
	if(audio_base[reg_count]==0)
			return; 
	len=(len>audio_base[reg_count]?audio_base[reg_count]:len);
	SDL_MixAudio(stream,sbuf,len,SDL_MIX_MAXVOLUME);
  SDL_memmove(sbuf, sbuf + len, CONFIG_SB_SIZE - len);
  audio_base[reg_count]-=len;
}

static void init_audio_SDL(){
  Log("INIT AUDIO DEVICE!");
  s.freq=audio_base[reg_freq];
  s.format=AUDIO_S16SYS;
  s.channels=audio_base[reg_channels];
  s.silence=0;
  s.samples=audio_base[reg_samples];
  s.callback=callback_audio_SDL;
  s.userdata=NULL;
  SDL_InitSubSystem(SDL_INIT_AUDIO);
  SDL_OpenAudio(&s, NULL);
  SDL_PauseAudio(0);
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if(audio_base[reg_init]==0){
    init_audio_SDL();
    audio_base[reg_init]=1;
  }
}
static void audio_buf_io_handler(uint32_t offset, int len, bool is_write){
}
#else
int flag=0;
static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if(offset==0x10 && is_write && audio_base[reg_init]==0){
    if(flag==0){
      io_write(AM_AUDIO_CTRL,audio_base[reg_freq],audio_base[reg_channels],audio_base[reg_samples]);
      flag=1;
    }
  }
  if(offset==0x14 && is_write){
    int count_s=((uint32_t *)CONFIG_AUDIO_CTL_MMIO)[reg_count];
    int count_new=audio_base[reg_count];
    int len=count_new-count_s;
    if(len>CONFIG_SB_SIZE-count_s) len=CONFIG_SB_SIZE-count_s;
    memcpy((uint8_t*)CONFIG_SB_ADDR + count_s,sbuf,len);
    memmove(sbuf,sbuf+len,CONFIG_SB_SIZE-len);
    ((uint32_t *)CONFIG_AUDIO_CTL_MMIO)[reg_count]=count_new;
    audio_base[reg_count] = count_new;
  }else if(offset==0x14 && !is_write){
    audio_base[reg_count] = ((uint32_t *)CONFIG_AUDIO_CTL_MMIO)[reg_count];
  }else if(offset==0x10 && !is_write){
    audio_base[reg_init] = io_read(AM_AUDIO_CONFIG).present;
  }
}
static void audio_buf_io_handler(uint32_t offset, int len, bool is_write){
}
#endif
void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;//24 Bytes
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, audio_buf_io_handler);
  memset(sbuf,0,CONFIG_SB_SIZE);

  audio_base[reg_freq] = 0;
  audio_base[reg_channels] = 0;
  audio_base[reg_samples] = 0;
  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  audio_base[reg_init] = 1;
  audio_base[reg_count] = 0;
}