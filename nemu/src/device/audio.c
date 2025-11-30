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
#include <device/mmio.h>
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
//uint8_t *audio_pos;
static int pos = 0;

static void audio_callback(void *udata, uint8_t *stream, int len) {
	SDL_LockAudio();
	SDL_memset(stream, 0, len);
	len = len > audio_base[reg_count] ? audio_base[reg_count] : len;
	if(audio_base[reg_count] == 0)
		return;
	if((pos + len) < CONFIG_SB_SIZE) {
		memcpy(stream, sbuf + pos, len);
		//SDL_MixAudio(stream, sbuf + pos, len, SDL_MIX_MAXVOLUME);
		pos += len;
	}
	else {
		memcpy(stream, sbuf + pos, (CONFIG_SB_SIZE - pos));
		pos = CONFIG_SB_SIZE - pos;
		memcpy(stream + pos, sbuf, len - pos);
		pos = len - pos;
	}
	SDL_UnlockAudio();
	audio_base[reg_count] -= len;
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
	if(offset == 0x10 && is_write) {
		SDL_AudioSpec audio = {};
		audio.freq = audio_base[reg_freq];
		audio.format = AUDIO_S16SYS;
		audio.channels = audio_base[reg_channels];
		audio.samples = audio_base[reg_samples];
		audio.callback = audio_callback;

		SDL_OpenAudio(&audio, NULL);
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
  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
	
	audio_base[reg_init] = 0;
	audio_base[reg_count] = 0;
	audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
	SDL_InitSubSystem(SDL_INIT_AUDIO);
/***audio play***
	mmio_write(0xa000020c, 4, CONFIG_SB_SIZE);//AUDIO_SBUF_SIZE_ADDR写入sbsize
  SDL_AudioSpec s = {};
  s.format = AUDIO_S1SYS;  // 系统中音频数据的格式使用16位有符号数来表示
  s.userdata = NULL;	// 不使用
  s.freq = 44100;//mmio_read(0xa0000200, 4);
  s.channels = 1;//mmio_read(0xa0000204, 4);
  s.samples = 1024;//mmio_read(0xa0000208, 4);
	s.callback = audio_callback;
  SDL_InitSubSystem(SDL_INIT_AUDIO);
  if(SDL_OpenAudio(&s, NULL) < 0) {
		printf("open audio fail!\n");
		assert(0);
	}
	audio_pos = sbuf;
	***/
}

/***
void audio_callback(void* userdata, uint8_t *stream, int len) {
	uint32_t count = mmio_read(0xa0000214, 4);
	mmio_write(0xa0000214, 4, count - len);
	SDL_memset(stream, 0, len);
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);
	//memset(audio_pos, 0, len);
	if((audio_pos - sbuf + len) == CONFIG_SB_SIZE) {
		audio_pos = sbuf;
	}
	else {
		audio_pos += len;
	}
}
***/
