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
static uint32_t read_ptr=0;
void mysdl_handler(void* userdata,uint8_t *stream,int len){
    int nread=len;
    if(audio_base[reg_count]<len) nread=audio_base[reg_count];
    int first_len=nread;
    int second_len=0;
    if(read_ptr+first_len>CONFIG_SB_SIZE){
        first_len=CONFIG_SB_SIZE-read_ptr;
        second_len=nread-first_len;
    }
    memcpy(stream,sbuf+read_ptr,first_len);
    if(second_len>0)memcpy(stream+first_len,sbuf,second_len);
    read_ptr=(read_ptr+nread)%CONFIG_SB_SIZE;
    audio_base[reg_count]-=nread;
    if(len>nread){
        memset(stream+nread,0,len-nread);
    }
}
static void audio_io_handler(uint32_t offset, int len, bool is_write) {
    if(is_write&&offset==16){
        SDL_AudioSpec s = {};
        s.format = AUDIO_S16SYS;  // 假设系统中音频数据的格式总是使用16位有符号数来表示
        s.userdata = NULL;        // 不使用
        s.freq=audio_base[reg_freq];
        s.channels=audio_base[reg_channels];
        s.samples=audio_base[reg_samples];
        s.silence=0;
        s.callback=mysdl_handler;
        SDL_InitSubSystem(SDL_INIT_AUDIO);
        SDL_OpenAudio(&s, NULL);
        SDL_PauseAudio(0);
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
    audio_base[reg_sbuf_size]=CONFIG_SB_SIZE;
  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
