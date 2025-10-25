#include <NDL.h>
#include <sdl-video.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect)
{
	assert(dst && src);
	assert(dst->format->BitsPerPixel == src->format->BitsPerPixel);
	// 步骤 1: 计算实际复制的源区域和目标位置
	SDL_Rect src_rect, dst_rect;
	if (srcrect)
	{
		src_rect = *srcrect;
	}
	else
	{
		src_rect.x = 0;
		src_rect.y = 0;
		src_rect.w = src->w;
		src_rect.h = src->h;
	}

	if (dstrect)
	{
		dst_rect = *dstrect;
	}
	else
	{
		dst_rect.x = 0;
		dst_rect.y = 0;
		// dstrect 的 w/h 会被忽略，使用源矩形大小
	}

	// 步骤 2: 裁剪源区域（确保不超出源表面边界）
	if (src_rect.x < 0)
	{
		src_rect.w += src_rect.x; // 减少宽度
		dst_rect.x -= src_rect.x; // 调整目标位置
		src_rect.x = 0;
	}
	if (src_rect.y < 0)
	{
		src_rect.h += src_rect.y;
		dst_rect.y -= src_rect.y;
		src_rect.y = 0;
	}
	if (src_rect.x + src_rect.w > src->w)
	{
		src_rect.w = src->w - src_rect.x;
	}
	if (src_rect.y + src_rect.h > src->h)
	{
		src_rect.h = src->h - src_rect.y;
	}

	// 步骤 3: 裁剪目标区域（确保不超出目标表面边界）
	if (dst_rect.x < 0)
	{
		src_rect.w += dst_rect.x; // 减少复制的宽度
		src_rect.x -= dst_rect.x; // 移动源起始位置
		dst_rect.x = 0;
	}
	if (dst_rect.y < 0)
	{
		src_rect.h += dst_rect.y;
		src_rect.y -= dst_rect.y;
		dst_rect.y = 0;
	}
	if (dst_rect.x + src_rect.w > dst->w)
	{
		src_rect.w = dst->w - dst_rect.x;
	}
	if (dst_rect.y + src_rect.h > dst->h)
	{
		src_rect.h = dst->h - dst_rect.y;
	}

	// 检查裁剪后区域是否有效
	if (src_rect.w <= 0 || src_rect.h <= 0)
	{
		return;
	}
	int bytes_per_pixel = src->format->BytesPerPixel;

	uint8_t *src_pixels = (uint8_t *)src->pixels;
	uint8_t *dst_pixels = (uint8_t *)dst->pixels;

	for (int y = 0; y < src_rect.h; y++)
	{
		uint8_t *src_row = src_pixels +
						   (src_rect.y + y) * src->pitch +
						   src_rect.x * bytes_per_pixel;

		uint8_t *dst_row = dst_pixels +
						   (dst_rect.y + y) * dst->pitch +
						   dst_rect.x * bytes_per_pixel;
		memmove(dst_row, src_row, src_rect.w * bytes_per_pixel);
	}
}

void SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, uint32_t color)
{
	assert(dst && dst->pixels);
	assert(dst->format->BitsPerPixel == 8 || dst->format->BitsPerPixel == 32);

	SDL_Rect rect;
	if (dstrect)
		rect = *dstrect;
	else
	{
		rect.x = 0;
		rect.y = 0;
		rect.w = dst->w;
		rect.h = dst->h;
	}

	// 更严谨的边界检查（含整数溢出防护）
	if (rect.w <= 0 || rect.h <= 0)
		return;
	if (rect.x < 0 || rect.y < 0)
		return;
	if ((rect.x > dst->w - rect.w) || (rect.y > dst->h - rect.h))
		return;

	if (dst->format->BitsPerPixel == 8)
	{
		// 8-bit: color 必须是调色板索引 (0-255)
		uint8_t index = (uint8_t)color;
		uint8_t *pixels = (uint8_t *)dst->pixels;
		for (int y = rect.y; y < rect.y + rect.h; y++)
		{
			uint8_t *row = pixels + y * dst->pitch; // 使用 pitch
			for (int x = rect.x; x < rect.x + rect.w; x++)
			{
				row[x] = index;
			}
		}
	}
	else
	{ // 32-bit
		uint8_t *pixels = (uint8_t *)dst->pixels;
		for (int y = rect.y; y < rect.y + rect.h; y++)
		{
			uint32_t *row = (uint32_t *)(pixels + y * dst->pitch); // 使用 pitch
			for (int x = rect.x; x < rect.x + rect.w; x++)
			{
				row[x] = color; // 注意：color 必须与表面格式匹配！
			}
		}
	}
}
void SDL_UpdateRect(SDL_Surface *s, int x, int y, int w, int h)
{
	// 参数验证
	assert(s && s->pixels);
	assert(s->format->BitsPerPixel == 8 || s->format->BitsPerPixel == 32);

	// 处理 w/h=0 的情况
	if (w <= 0 || h <= 0)
	{
		x = 0;
		y = 0;
		w = s->w;
		h = s->h;
	}

	// 裁剪矩形到表面范围内
	if (x < 0)
	{
		w += x;
		x = 0;
	}
	if (y < 0)
	{
		h += y;
		y = 0;
	}
	if (x + w > s->w)
		w = s->w - x;
	if (y + h > s->h)
		h = s->h - y;
	if (w <= 0 || h <= 0)
		return; // 裁剪后矩形无效

	if (s->format->BitsPerPixel == 32)
	{
		// 32位：使用 pitch 计算行偏移
		uint8_t *pixels = (uint8_t *)s->pixels;
		uint8_t *rect_start = pixels + y * s->pitch + x * 4;

		// 若 pitch 无填充且绘制整个表面，可免复制
		if (s->pitch == s->w * 4 && x == 0 && y == 0 && w == s->w && h == s->h)
		{
			NDL_DrawRect((uint32_t *)rect_start, x, y, w, h);
		}
		else
		{
			// 复制子矩形到连续内存
			uint32_t *converted_pixels = malloc(w * h * sizeof(uint32_t));
			if (!converted_pixels)
				return;

			for (int j = 0; j < h; j++)
			{
				uint32_t *src = (uint32_t *)(rect_start + j * s->pitch);
				memcpy(&converted_pixels[j * w], src, w * 4);
			}
			NDL_DrawRect(converted_pixels, x, y, w, h);
			free(converted_pixels);
		}
	}
	else
	{
		// 8位：使用 pitch 访问像素
		uint8_t *pixels = (uint8_t *)s->pixels;
		uint32_t *converted_pixels = malloc(w * h * sizeof(uint32_t));
		if (!converted_pixels)
			return;

		SDL_Palette *palette = s->format->palette;
		assert(palette && palette->ncolors > 0);

		for (int j = 0; j < h; j++)
		{
			uint8_t *src_row = pixels + (y + j) * s->pitch + x; // 使用 pitch
			for (int i = 0; i < w; i++)
			{
				uint8_t index = src_row[i];
				converted_pixels[j * w + i] = palette->colors[index].val;
			}
		}
		NDL_DrawRect(converted_pixels, x, y, w, h);
		free(converted_pixels);
	}
}

// APIs below are already implemented.

static inline int maskToShift(uint32_t mask)
{
	switch (mask)
	{
	case 0x000000ff:
		return 0;
	case 0x0000ff00:
		return 8;
	case 0x00ff0000:
		return 16;
	case 0xff000000:
		return 24;
	case 0x00000000:
		return 24; // hack
	default:
		assert(0);
	}
}

SDL_Surface *SDL_CreateRGBSurface(uint32_t flags, int width, int height, int depth,
								  uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask)
{
	assert(depth == 8 || depth == 32);
	SDL_Surface *s = malloc(sizeof(SDL_Surface));
	assert(s);
	s->flags = flags;
	s->format = malloc(sizeof(SDL_PixelFormat));
	assert(s->format);
	if (depth == 8)
	{
		s->format->palette = malloc(sizeof(SDL_Palette));
		assert(s->format->palette);
		s->format->palette->colors = malloc(sizeof(SDL_Color) * 256);
		assert(s->format->palette->colors);
		memset(s->format->palette->colors, 0, sizeof(SDL_Color) * 256);
		s->format->palette->ncolors = 256;
	}
	else
	{
		s->format->palette = NULL;
		s->format->Rmask = Rmask;
		s->format->Rshift = maskToShift(Rmask);
		s->format->Rloss = 0;
		s->format->Gmask = Gmask;
		s->format->Gshift = maskToShift(Gmask);
		s->format->Gloss = 0;
		s->format->Bmask = Bmask;
		s->format->Bshift = maskToShift(Bmask);
		s->format->Bloss = 0;
		s->format->Amask = Amask;
		s->format->Ashift = maskToShift(Amask);
		s->format->Aloss = 0;
	}

	s->format->BitsPerPixel = depth;
	s->format->BytesPerPixel = depth / 8;

	s->w = width;
	s->h = height;
	s->pitch = width * depth / 8;
	assert(s->pitch == width * s->format->BytesPerPixel);

	if (!(flags & SDL_PREALLOC))
	{
		s->pixels = malloc(s->pitch * height);
		assert(s->pixels);
	}

	return s;
}

SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height, int depth,
									  int pitch, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask)
{
	SDL_Surface *s = SDL_CreateRGBSurface(SDL_PREALLOC, width, height, depth,
										  Rmask, Gmask, Bmask, Amask);
	assert(pitch == s->pitch);
	s->pixels = pixels;
	return s;
}

void SDL_FreeSurface(SDL_Surface *s)
{
	if (s != NULL)
	{
		if (s->format != NULL)
		{
			if (s->format->palette != NULL)
			{
				if (s->format->palette->colors != NULL)
					free(s->format->palette->colors);
				free(s->format->palette);
			}
			free(s->format);
		}
		if (s->pixels != NULL && !(s->flags & SDL_PREALLOC))
			free(s->pixels);
		free(s);
	}
}

SDL_Surface *SDL_SetVideoMode(int width, int height, int bpp, uint32_t flags)
{
	if (flags & SDL_HWSURFACE)
		NDL_OpenCanvas(&width, &height);
	return SDL_CreateRGBSurface(flags, width, height, bpp,
								DEFAULT_RMASK, DEFAULT_GMASK, DEFAULT_BMASK, DEFAULT_AMASK);
}

void SDL_SoftStretch(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect)
{
	assert(src && dst);
	assert(dst->format->BitsPerPixel == src->format->BitsPerPixel);
	assert(dst->format->BitsPerPixel == 8);

	int x = (srcrect == NULL ? 0 : srcrect->x);
	int y = (srcrect == NULL ? 0 : srcrect->y);
	int w = (srcrect == NULL ? src->w : srcrect->w);
	int h = (srcrect == NULL ? src->h : srcrect->h);

	assert(dstrect);
	if (w == dstrect->w && h == dstrect->h)
	{
		/* The source rectangle and the destination rectangle
		 * are of the same size. If that is the case, there
		 * is no need to stretch, just copy. */
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		SDL_BlitSurface(src, &rect, dst, dstrect);
	}
	else
	{
		assert(0);
	}
}

void SDL_SetPalette(SDL_Surface *s, int flags, SDL_Color *colors, int firstcolor, int ncolors)
{
	assert(s);
	assert(s->format);
	assert(s->format->palette);
	assert(firstcolor == 0);

	s->format->palette->ncolors = ncolors;
	memcpy(s->format->palette->colors, colors, sizeof(SDL_Color) * ncolors);

	if (s->flags & SDL_HWSURFACE)
	{
		assert(ncolors == 256);
		for (int i = 0; i < ncolors; i++)
		{
			uint8_t r = colors[i].r;
			uint8_t g = colors[i].g;
			uint8_t b = colors[i].b;
		}
		SDL_UpdateRect(s, 0, 0, 0, 0);
	}
}

static void ConvertPixelsARGB_ABGR(void *dst, void *src, int len)
{
	int i;
	uint8_t (*pdst)[4] = dst;
	uint8_t (*psrc)[4] = src;
	union
	{
		uint8_t val8[4];
		uint32_t val32;
	} tmp;
	int first = len & ~0xf;
	for (i = 0; i < first; i += 16)
	{
#define macro(i)                        \
	tmp.val32 = *((uint32_t *)psrc[i]); \
	*((uint32_t *)pdst[i]) = tmp.val32; \
	pdst[i][0] = tmp.val8[2];           \
	pdst[i][2] = tmp.val8[0];

		macro(i + 0);
		macro(i + 1);
		macro(i + 2);
		macro(i + 3);
		macro(i + 4);
		macro(i + 5);
		macro(i + 6);
		macro(i + 7);
		macro(i + 8);
		macro(i + 9);
		macro(i + 10);
		macro(i + 11);
		macro(i + 12);
		macro(i + 13);
		macro(i + 14);
		macro(i + 15);
	}

	for (; i < len; i++)
	{
		macro(i);
	}
}

SDL_Surface *SDL_ConvertSurface(SDL_Surface *src, SDL_PixelFormat *fmt, uint32_t flags)
{
	assert(src->format->BitsPerPixel == 32);
	assert(src->w * src->format->BytesPerPixel == src->pitch);
	assert(src->format->BitsPerPixel == fmt->BitsPerPixel);

	SDL_Surface *ret = SDL_CreateRGBSurface(flags, src->w, src->h, fmt->BitsPerPixel,
											fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);

	assert(fmt->Gmask == src->format->Gmask);
	assert(fmt->Amask == 0 || src->format->Amask == 0 || (fmt->Amask == src->format->Amask));
	ConvertPixelsARGB_ABGR(ret->pixels, src->pixels, src->w * src->h);

	return ret;
}

uint32_t SDL_MapRGBA(SDL_PixelFormat *fmt, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	assert(fmt->BytesPerPixel == 4);
	uint32_t p = (r << fmt->Rshift) | (g << fmt->Gshift) | (b << fmt->Bshift);
	if (fmt->Amask)
		p |= (a << fmt->Ashift);
	return p;
}

int SDL_LockSurface(SDL_Surface *s)
{
	assert(0);
	return 0;
}

void SDL_UnlockSurface(SDL_Surface *s)
{
	assert(0);
}
