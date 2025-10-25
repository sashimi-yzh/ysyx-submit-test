#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;
static struct timeval start_time;
uint32_t NDL_GetTicks()
{
	// return ms since NDL_Init
	struct timeval now;
	gettimeofday(&now, NULL);
	uint64_t elapsed = (now.tv_sec - start_time.tv_sec) * 1000 + (now.tv_usec - start_time.tv_usec) / 1000;
	return (uint32_t)elapsed;
}

int NDL_PollEvent(char *buf, int len)
{
	int fd = open("/dev/events", O_RDONLY);
	char event_buf[64] = {0};
	read(fd, event_buf, sizeof(event_buf) - 1);
	close(fd);
	int len_event = strlen(event_buf);
	if (len_event + 1 >= len)
	{
		printf("NDL_PollEvent: buffer too small, need %d bytes, got %d bytes\n", len_event, len);
	}
	strcpy(buf, event_buf);
	return len_event;
}

void NDL_OpenCanvas(int *w, int *h)
{

	int whole_w = 0, whole_h = 0;
	int fd = open("/proc/dispinfo", O_RDONLY);
	char buf[256] = {0};
	read(fd, buf, sizeof(buf) - 1);
	close(fd);
	sscanf(buf, "WIDTH:%d\nHEIGHT:%d\n", &whole_w, &whole_h);
	if (*w == 0 && *h == 0)
	{
		*w = whole_w;
		*h = whole_h;
	}
	if (*w > whole_w || *h > whole_h)
	{
		printf("NDL_OpenCanvas: requested size (%d, %d) exceeds screen size (%d, %d)\n", *w, *h, whole_w, whole_h);
	}
	screen_h = *h;
	screen_w = *w;
	if (getenv("NWM_APP"))
	{
		int fbctl = 4;
		fbdev = 5;
		screen_w = *w;
		screen_h = *h;
		char buf[64];
		int len = sprintf(buf, "%d %d", screen_w, screen_h);
		// let NWM resize the window and create the frame buffer
		write(fbctl, buf, len);
		while (1)
		{
			// 3 = evtdev
			int nread = read(3, buf, sizeof(buf) - 1);
			if (nread <= 0)
				continue;
			buf[nread] = '\0';
			if (strcmp(buf, "mmap ok") == 0)
				break;
		}
		close(fbctl);
	}
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h)
{
	int whole_w = 0, whole_h = 0;
	int fd = open("/proc/dispinfo", O_RDONLY);
	char buf[256] = {0};
	read(fd, buf, sizeof(buf) - 1);
	close(fd);
	sscanf(buf, "WIDTH:%d\nHEIGHT:%d\n", &whole_w, &whole_h);
	// 转换xy，使得图像绘制在主屏幕坐标系中心
	x += (whole_w - screen_w) / 2;
	y += (whole_h - screen_h) / 2;
	int offset = (y * whole_w + x) * 4; // 每个像素4字节
	// 循环写入，一次一行
	fd = open("/dev/fb", O_WRONLY);

	for (int i = 0; i < h; i++)
	{
		lseek(fd, offset, SEEK_SET);
		write(fd, pixels, w * 4);
		pixels += w;		   // 移动到下一行
		offset += whole_w * 4; // 移动到下一行的起始
	}
	close(fd);
}

void NDL_OpenAudio(int freq, int channels, int samples)
{
}

void NDL_CloseAudio()
{
}

int NDL_PlayAudio(void *buf, int len)
{
	return 0;
}

int NDL_QueryAudio()
{
	return 0;
}

int NDL_Init(uint32_t flags)
{
	if (getenv("NWM_APP"))
	{
		evtdev = 3;
	}
	gettimeofday(&start_time, NULL);
	return 0;
}

void NDL_Quit()
{
}
