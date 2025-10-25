#include <common.h>
uint32_t fg_pcb = 0;
#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
#define MULTIPROGRAM_YIELD() yield()
#else
#define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
	[AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
	[AM_KEY_NONE] = "NONE",
	AM_KEYS(NAME)};
size_t serial_write(const void *buf, size_t offset, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		putch(((const char *)buf)[i]);
	}
	return len;
}

size_t events_read(void *buf, size_t offset, size_t len)
{
	AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
	if (ev.keycode == AM_KEY_NONE)
		return 0;
	if (ev.keycode <= 4 && ev.keycode >= 2)
	{
		fg_pcb = ev.keycode - 2;
	}
	char p[64] = {0};
	if (ev.keydown)
		sprintf(p, "kd %s", keyname[ev.keycode]);
	else
		sprintf(p, "ku %s", keyname[ev.keycode]);
	size_t n = strlen(p);
	if (n > len)
		panic("events_read: buffer too small");
	memcpy(buf, p, n);
	return n;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len)
{
	AM_GPU_CONFIG_T gpu_config = io_read(AM_GPU_CONFIG);
	uint32_t width = gpu_config.width;
	uint32_t height = gpu_config.height;
	char p[256] = {0};
	sprintf(p, "WIDTH:%u\nHEIGHT:%u\n", width, height);
	size_t n = strlen(p);
	if (n + 1 > len)
	{
		panic("dispinfo_read: buffer too small");
	}
	memcpy(buf, p, n);
	return 0;
}

size_t fb_write(const void *buf, size_t offset, size_t len)
{
	// 认为x,y已经由画布转换至屏幕坐标系
	int w_screen = io_read(AM_GPU_CONFIG).width;
	int x, y;
	if (offset < 0)
	{
		panic("fb_write: offset out of bounds");
	}
	if (len % 4 != 0 || offset % 4 != 0)
	{
		panic("fb_write: len or offset not aligned to 4 bytes");
	}
	x = (offset / 4) % w_screen; // 每个像素4字节，所以offset/4是像素索引
	y = (offset / 4) / w_screen; // 计算y坐标
	// cal w，h to put in middle of the screen
	io_write(AM_GPU_FBDRAW, x, y, (void *)buf, len / 4, 1, true);
	return len; // 返回写入的字节数
}

void init_device()
{
	Log("Initializing devices...");
	ioe_init();
}
