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

#include <SDL2/SDL.h>
#include <common.h>
#include <device/map.h>
#include <string.h>

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

static uint32_t wpos = 0; // 已播放字节
static uint32_t rpos = 0; // 环形读指针

static void sdl_audio_callback(void *ud, uint8_t *stream, int len)
{
    uint32_t remain_total = wpos < rpos ? wpos + CONFIG_SB_SIZE - rpos : wpos - rpos;
    int to_copy = (remain_total < (uint32_t)len) ? (int)remain_total : len;

    // 拷贝有效数据
    int left = to_copy, off = 0;
    // printf("Audio callback len: %d, to_copy: %d, wpos: %d, rpos: %d\n", len, to_copy, wpos, rpos);

    while (left) {
        int chunk = CONFIG_SB_SIZE - rpos;
        if (chunk > left)
            chunk = left;
        memcpy(stream + off, sbuf + rpos, chunk);
        rpos = (rpos + chunk) % CONFIG_SB_SIZE;
        off += chunk;
        left -= chunk;
    }
    // printf("wpos: %d rpos: %d to_copy: %d len:%d\n", wpos, rpos, to_copy, len);
    // 不足填静音
    if (to_copy < len) {
        memset(stream + to_copy, 0, len - to_copy);
        rpos += (len - to_copy) % CONFIG_SB_SIZE;

        audio_base[reg_count] = 0;
        return ;
    }

    audio_base[reg_count] = remain_total - len;

    // if (played >= produced) {
    // 播放结束后暂停音频线程
    // SDL_PauseAudio(1);
    // SDL_CloseAudio();
    // SDL_QuitSubSystem(SDL_INIT_AUDIO);
    // }
}

static void audio_start()
{
    SDL_AudioSpec want;
    memset(&want, 0, sizeof(want));
    want.freq = audio_base[reg_freq];
    want.channels = audio_base[reg_channels];
    want.samples = audio_base[reg_samples];
    want.format = AUDIO_S16SYS;
    want.callback = sdl_audio_callback;
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) == 0 && SDL_OpenAudio(&want, NULL) == 0) {
        SDL_PauseAudio(0);
    }
}

static void audio_io_handler(uint32_t offset, int len, bool is_write)
{
    uint32_t idx = offset >> 2;
    if (idx == reg_init && audio_base[reg_init] == 1)
        audio_start();
}

static void sbuf_io_handler(uint32_t offset, int len, bool is_write)
{
    if (is_write) {
        uint32_t end_off = offset + len;
        wpos = end_off; // 以最大写偏移作为长度
        // printf("write pos%%10000: %d\n", wpos%10000);
    }
}

void init_audio()
{
    uint32_t sz = sizeof(uint32_t) * nr_reg;
    audio_base = (uint32_t *)new_space(sz);
#ifdef CONFIG_HAS_PORT_IO
    add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, sz, audio_io_handler);
#else
    add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, sz, audio_io_handler);
#endif
    for (int i = 0; i < nr_reg; i++)
        audio_base[i] = 0;
    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
    audio_base[reg_count] = 0;

    sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
    add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, sbuf_io_handler);
}
