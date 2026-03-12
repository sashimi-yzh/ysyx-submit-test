#include <am.h>
#include <klib.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR (AUDIO_ADDR + 0x14)

static uint32_t sbuf_size = 0;
static uint32_t wpos = 0;


void __am_audio_init()
{
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg)
{
    // cfg->present = (sbuf_size != 0);
    sbuf_size = inl(AUDIO_SBUF_SIZE_ADDR);
    cfg->present = false;
    cfg->bufsize = sbuf_size;
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl)
{
    outl(AUDIO_FREQ_ADDR, ctrl->freq);
    outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
    outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
    outl(AUDIO_INIT_ADDR, 1);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat)
{
    stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl)
{
    if (ctl->buf.start == NULL)
        return;
    
    uintptr_t start = (uintptr_t)ctl->buf.start;
    uintptr_t end = (uintptr_t)ctl->buf.end;

    uint32_t wlen_all = end - start;
    while (wlen_all) {
        uint32_t wlen = wlen_all > 4096 ? 4096: wlen_all;
        // printf("Audio play wlen_all: %x, start: %p, end: %p\n", wlen_all, start, end);
        while (inl(AUDIO_COUNT_ADDR) + wlen > sbuf_size) {
            // printf("Audio wait... times: %d\r", ++times);
        };

        // assert(wpos+wlen <= sbuf_size);

        uint8_t *src = (uint8_t *)ctl->buf.start;
        wpos = wpos % sbuf_size;
        // printf("Audio play 2 wlen: %x, wpos: %x\n", wlen, wpos);
        uint8_t *dst = (uint8_t *)AUDIO_SBUF_ADDR;

        uint32_t first = sbuf_size - wpos;
        if (first > wlen)
            first = wlen;
        memcpy(dst + wpos, src, first);
        uint32_t remain = wlen - first;
        if (remain)
            memcpy(dst, src + first, remain);
        wpos += wlen;

        outl(AUDIO_COUNT_ADDR, inl(AUDIO_COUNT_ADDR) + wlen);

        wlen_all -= wlen;
        // printf("wpos: %d, wlen: %d\n", wpos, wlen);
        // printf("start addr: %p, end addr: %p\n", ctl->buf.start, ctl->buf.end);
    }
}
