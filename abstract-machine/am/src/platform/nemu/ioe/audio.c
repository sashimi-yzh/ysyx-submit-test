#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

void __am_audio_init() {
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
	cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
	outl(AUDIO_FREQ_ADDR, ctrl->freq);
	outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
	outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
	outl(AUDIO_INIT_ADDR, 1);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

static uint32_t pos = 0;
static void audio_write(uint8_t *buf, int len) {
	while(len > 0) {
		if(pos >= 65536)
			pos = 0;
		outb((AUDIO_SBUF_ADDR + pos), *(unsigned *)buf);
		buf++;
		pos++;
		len--;
	}
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
	int len = ctl->buf.end - ctl->buf.start;
	len = len >= 65536 ? 65536 : len;
	audio_write(ctl->buf.start, len);
	int count = inl(AUDIO_COUNT_ADDR);
	outl(AUDIO_COUNT_ADDR, len + count);
}


/***
uint32_t *sbuf = (uint32_t *)(uintptr_t)AUDIO_SBUF_ADDR;
void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
	uint32_t *ctlbuf = ctl->buf.start;
	for(uint32_t *p = ctl->buf.start; p != (ctl->buf.end); p ++) {
		if(sbuf - (uint32_t *)(uintptr_t)AUDIO_SBUF_ADDR >= (inl(AUDIO_SBUF_SIZE_ADDR)/4)) {
		  sbuf = (uint32_t *)(uintptr_t)AUDIO_SBUF_ADDR;
		}
		*sbuf ++ = *ctlbuf ++;
	}
	uint32_t count = sbuf - (uint32_t *)(uintptr_t)AUDIO_SBUF_ADDR;
	outl(0xa0000214, count);
}
***/
