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
    cfg->bufsize=inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
    outl(AUDIO_FREQ_ADDR,ctrl->freq);
    outl(AUDIO_CHANNELS_ADDR,ctrl->channels);
    outl(AUDIO_SAMPLES_ADDR,ctrl->samples);
    outl(AUDIO_INIT_ADDR,1);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count=inl(AUDIO_COUNT_ADDR);
}
static int write_ptr;
void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
    int len=(uintptr_t)ctl->buf.end-(uintptr_t)ctl->buf.start;
    uint8_t *data=(uint8_t*)ctl->buf.start;
    int buf_size=io_read(AM_AUDIO_CONFIG).bufsize;
    while(len>buf_size-io_read(AM_AUDIO_STATUS).count);
    uint8_t *audio_buf=(uint8_t*)(uintptr_t)AUDIO_SBUF_ADDR;
    int i;
    for(i=0;i<len;i++){
        audio_buf[(write_ptr+i)%buf_size]=data[i];
    }
    write_ptr=(write_ptr+len)%buf_size;
    int count=io_read(AM_AUDIO_STATUS).count;
    outl(AUDIO_COUNT_ADDR,count+len);
}
