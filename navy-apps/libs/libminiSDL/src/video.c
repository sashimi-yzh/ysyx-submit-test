#include <NDL.h>
#include <assert.h>
#include <sdl-video.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst,
                     SDL_Rect *dstrect) {
  if (src == NULL || dst == NULL || src->format == NULL || dst->format == NULL ||
      src->pixels == NULL || dst->pixels == NULL) {
    return;
  }
  if (src->w <= 0 || src->h <= 0 || dst->w <= 0 || dst->h <= 0) {
    return;
  }

  int src_rect_x = (srcrect == NULL ? 0 : srcrect->x);
  int src_rect_y = (srcrect == NULL ? 0 : srcrect->y);
  int src_rect_w = (srcrect == NULL ? src->w : srcrect->w);
  int src_rect_h = (srcrect == NULL ? src->h : srcrect->h);

  int dst_rect_x = (dstrect == NULL ? 0 : dstrect->x);
  int dst_rect_y = (dstrect == NULL ? 0 : dstrect->y);
  int copy_w = src_rect_w;
  int copy_h = src_rect_h;

  if (copy_w <= 0 || copy_h <= 0) {
    return;
  }

  if (src_rect_x < 0) {
    int shift = -src_rect_x;
    src_rect_x = 0;
    dst_rect_x += shift;
    copy_w -= shift;
  }
  if (src_rect_y < 0) {
    int shift = -src_rect_y;
    src_rect_y = 0;
    dst_rect_y += shift;
    copy_h -= shift;
  }
  if (dst_rect_x < 0) {
    int shift = -dst_rect_x;
    dst_rect_x = 0;
    src_rect_x += shift;
    copy_w -= shift;
  }
  if (dst_rect_y < 0) {
    int shift = -dst_rect_y;
    dst_rect_y = 0;
    src_rect_y += shift;
    copy_h -= shift;
  }

  if (src_rect_x + copy_w > src->w)
    copy_w = src->w - src_rect_x;
  if (src_rect_y + copy_h > src->h)
    copy_h = src->h - src_rect_y;
  if (dst_rect_x + copy_w > dst->w)
    copy_w = dst->w - dst_rect_x;
  if (dst_rect_y + copy_h > dst->h)
    copy_h = dst->h - dst_rect_y;

  if (copy_w <= 0 || copy_h <= 0) {
    return;
  }

  if (src->format->BytesPerPixel == 4 && dst->format->BytesPerPixel == 4) {
    if (src->pitch < src->w * 4 || dst->pitch < dst->w * 4) {
      return;
    }
    uint32_t *dst_pix = (uint32_t *)dst->pixels;
    uint32_t *src_pix = (uint32_t *)src->pixels;
    int src_pitch = src->pitch / 4;
    int dst_pitch = dst->pitch / 4;
    int step = 1;
    int start = 0;
    int end = copy_h;
    if (src == dst && dst_rect_y > src_rect_y) {
      // Overlapped blit on the same surface must copy bottom-up.
      step = -1;
      start = copy_h - 1;
      end = -1;
    }
    for (int i = start; i != end; i += step) {
      memmove(dst_pix + (dst_rect_y + i) * dst_pitch + dst_rect_x,
              src_pix + (src_rect_y + i) * src_pitch + src_rect_x,
              sizeof(uint32_t) * copy_w);
    }
  } else if (src->format->BytesPerPixel == 1 &&
             dst->format->BytesPerPixel == 1) {
    if (src->pitch < src->w || dst->pitch < dst->w) {
      return;
    }
    uint8_t *dst_pix = dst->pixels;
    uint8_t *src_pix = src->pixels;
    int step = 1;
    int start = 0;
    int end = copy_h;
    if (src == dst && dst_rect_y > src_rect_y) {
      // Overlapped blit on the same surface must copy bottom-up.
      step = -1;
      start = copy_h - 1;
      end = -1;
    }
    for (int i = start; i != end; i += step) {
      memmove(dst_pix + (dst_rect_y + i) * dst->pitch + dst_rect_x,
              src_pix + (src_rect_y + i) * src->pitch + src_rect_x, copy_w);
    }
  } else {
    assert(0);
  }
}

void SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, uint32_t color) {
  int dst_rect_x = (dstrect == NULL ? 0 : dstrect->x);
  int dst_rect_y = (dstrect == NULL ? 0 : dstrect->y);
  int dst_rect_w = (dstrect == NULL ? dst->w : dstrect->w);
  int dst_rect_h = (dstrect == NULL ? dst->h : dstrect->h);

  uint32_t *dst_pix = (uint32_t *)dst->pixels;

  assert(dst->format->BytesPerPixel == 4);

  for (int i = 0; i < dst_rect_h; i++) {
    for (int j = 0; j < dst_rect_w; j++) {
      dst_pix[(dst_rect_y + i) * dst->w + dst_rect_x + j] = color;
    }
  }
}

void SDL_UpdateRect(SDL_Surface *s, int x, int y, int w, int h) {
  if (s == NULL || s->format == NULL || s->pixels == NULL) {
    return;
  }
  if (s->w <= 0 || s->h <= 0) {
    return;
  }

  int update_x = (x < 0 ? 0 : x);
  int update_y = (y < 0 ? 0 : y);
  if (update_x >= s->w || update_y >= s->h) {
    return;
  }

  int update_w = (w <= 0 ? s->w - update_x : w);
  int update_h = (h <= 0 ? s->h - update_y : h);
  if (update_w > s->w - update_x)
    update_w = s->w - update_x;
  if (update_h > s->h - update_y)
    update_h = s->h - update_y;
  if (update_w <= 0 || update_h <= 0) {
    return;
  }

  if (s->format->BytesPerPixel == 1) {
    if (s->pitch < s->w || s->format->palette == NULL ||
        s->format->palette->colors == NULL) {
      return;
    }
    uint8_t *pixels_8 = s->pixels;

    // 分配32位像素缓冲区
    uint32_t *pixels_32 = malloc(sizeof(uint32_t) * update_w * update_h);
    assert(pixels_32);

    // 转换8位像素到32位（使用 pitch 作为行步长，确保偏移计算正确）
    for (int i = 0; i < update_h; i++) {
      for (int j = 0; j < update_w; j++) {
        uint8_t index = pixels_8[(update_y + i) * s->pitch + update_x + j];
        SDL_Color color = s->format->palette->colors[index];
        pixels_32[i * update_w + j] = (color.r << 16) | (color.g << 8) | color.b;
      }
    }

    NDL_DrawRect(pixels_32, update_x, update_y, update_w, update_h);

    free(pixels_32);
  } else if (s->format->BytesPerPixel == 4) {
    if (s->pitch < s->w * 4) {
      return;
    }
    uint32_t *pixels = (uint32_t *)s->pixels;
    int pitch_pixels = s->pitch / 4;
    if (update_x == 0 && update_y == 0 && update_w == s->w && update_h == s->h) {
      NDL_DrawRect(pixels, 0, 0, update_w, update_h);
    } else {
      uint32_t *region = malloc(sizeof(uint32_t) * update_w * update_h);
      assert(region);
      for (int i = 0; i < update_h; i++) {
        memcpy(region + i * update_w,
               pixels + (update_y + i) * pitch_pixels + update_x,
               sizeof(uint32_t) * update_w);
      }
      NDL_DrawRect(region, update_x, update_y, update_w, update_h);
      free(region);
    }
  } else {
    printf("invalid s->format->BytesPerPixel");
    assert(0);
  }
}

// APIs below are already implemented.

static inline int maskToShift(uint32_t mask) {
  switch (mask) {
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

SDL_Surface *SDL_CreateRGBSurface(uint32_t flags, int width, int height,
                                  int depth, uint32_t Rmask, uint32_t Gmask,
                                  uint32_t Bmask, uint32_t Amask) {
  assert(depth == 8 || depth == 32);
  SDL_Surface *s = malloc(sizeof(SDL_Surface));
  assert(s);
  s->flags = flags;
  s->format = malloc(sizeof(SDL_PixelFormat));
  assert(s->format);
  if (depth == 8) {
    s->format->palette = malloc(sizeof(SDL_Palette));
    assert(s->format->palette);
    s->format->palette->colors = malloc(sizeof(SDL_Color) * 256);
    assert(s->format->palette->colors);
    memset(s->format->palette->colors, 0, sizeof(SDL_Color) * 256);
    s->format->palette->ncolors = 256;
  } else {
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

  if (!(flags & SDL_PREALLOC)) {
    s->pixels = malloc(s->pitch * height);
    assert(s->pixels);
  }

  return s;
}

SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height,
                                      int depth, int pitch, uint32_t Rmask,
                                      uint32_t Gmask, uint32_t Bmask,
                                      uint32_t Amask) {
  SDL_Surface *s = SDL_CreateRGBSurface(SDL_PREALLOC, width, height, depth,
                                        Rmask, Gmask, Bmask, Amask);
  assert(pitch == s->pitch);
  s->pixels = pixels;
  return s;
}

void SDL_FreeSurface(SDL_Surface *s) {
  if (s != NULL) {
    if (s->format != NULL) {
      if (s->format->palette != NULL) {
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

SDL_Surface *SDL_SetVideoMode(int width, int height, int bpp, uint32_t flags) {
  if (flags & SDL_HWSURFACE)
    NDL_OpenCanvas(&width, &height);
  return SDL_CreateRGBSurface(flags, width, height, bpp, DEFAULT_RMASK,
                              DEFAULT_GMASK, DEFAULT_BMASK, DEFAULT_AMASK);
}

void SDL_SoftStretch(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst,
                     SDL_Rect *dstrect) {
  assert(src && dst);
  assert(dst->format->BitsPerPixel == src->format->BitsPerPixel);
  assert(dst->format->BitsPerPixel == 8);

  int x = (srcrect == NULL ? 0 : srcrect->x);
  int y = (srcrect == NULL ? 0 : srcrect->y);
  int w = (srcrect == NULL ? src->w : srcrect->w);
  int h = (srcrect == NULL ? src->h : srcrect->h);

  assert(dstrect);
  if (w == dstrect->w && h == dstrect->h) {
    /* The source rectangle and the destination rectangle
     * are of the same size. If that is the case, there
     * is no need to stretch, just copy. */
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_BlitSurface(src, &rect, dst, dstrect);
  } else {
    assert(0);
  }
}

void SDL_SetPalette(SDL_Surface *s, int flags, SDL_Color *colors,
                    int firstcolor, int ncolors) {
  assert(s);
  assert(s->format);
  assert(s->format->palette);
  assert(firstcolor == 0);

  s->format->palette->ncolors = ncolors;
  memcpy(s->format->palette->colors, colors, sizeof(SDL_Color) * ncolors);

  if (s->flags & SDL_HWSURFACE) {
    assert(ncolors == 256);
    for (int i = 0; i < ncolors; i++) {
      uint8_t r = colors[i].r;
      uint8_t g = colors[i].g;
      uint8_t b = colors[i].b;
    }
    SDL_UpdateRect(s, 0, 0, 0, 0);
  }
}

// clang-format off
static void ConvertPixelsARGB_ABGR(void *dst, void *src, int len) {
  int i;
  uint8_t (*pdst)[4] = dst;
  uint8_t (*psrc)[4] = src;
  union {
    uint8_t val8[4];
    uint32_t val32;
  } tmp;
  int first = len & ~0xf;
  for (i = 0; i < first; i += 16) {
#define macro(i) \
    tmp.val32 = *((uint32_t *)psrc[i]); \
    *((uint32_t *)pdst[i]) = tmp.val32; \
    pdst[i][0] = tmp.val8[2]; \
    pdst[i][2] = tmp.val8[0];

    macro(i + 0); macro(i + 1); macro(i + 2); macro(i + 3);
    macro(i + 4); macro(i + 5); macro(i + 6); macro(i + 7);
    macro(i + 8); macro(i + 9); macro(i +10); macro(i +11);
    macro(i +12); macro(i +13); macro(i +14); macro(i +15);
  }

  for (; i < len; i ++) {
    macro(i);
  }
}
// clang-format on

SDL_Surface *SDL_ConvertSurface(SDL_Surface *src, SDL_PixelFormat *fmt,
                                uint32_t flags) {
  assert(src->format->BitsPerPixel == 32);
  assert(src->w * src->format->BytesPerPixel == src->pitch);
  assert(src->format->BitsPerPixel == fmt->BitsPerPixel);

  SDL_Surface *ret =
      SDL_CreateRGBSurface(flags, src->w, src->h, fmt->BitsPerPixel, fmt->Rmask,
                           fmt->Gmask, fmt->Bmask, fmt->Amask);

  assert(fmt->Gmask == src->format->Gmask);
  assert(fmt->Amask == 0 || src->format->Amask == 0 ||
         (fmt->Amask == src->format->Amask));
  ConvertPixelsARGB_ABGR(ret->pixels, src->pixels, src->w * src->h);

  return ret;
}

inline uint32_t abs_diff(uint8_t a, uint8_t b) { return a > b ? a - b : b - a; }

inline uint32_t color_distance(uint8_t r0, uint8_t r1, uint8_t g0, uint8_t g1,
                               uint8_t b0, uint8_t b1) {
  return abs_diff(r0, r1) + abs_diff(g0, g1) + abs_diff(b0, b1);
}

int closest_color_idx(SDL_Palette *pa, uint8_t r, uint8_t g, uint8_t b) {
  uint32_t min_distance = -1;
  int min_idx = -1;
  for (int i = 0; i < pa->ncolors; i++) {
    SDL_Color *color = pa->colors + i;
    uint32_t diff = color_distance(color->r, r, color->g, g, color->b, b);
    if (min_idx == -1) {
      min_idx = i;
      min_distance = diff;
    } else if (diff < min_distance) {
      min_idx = i;
      min_distance = diff;
    }
  }
  return min_idx;
}

uint32_t SDL_MapRGBA(SDL_PixelFormat *fmt, uint8_t r, uint8_t g, uint8_t b,
                     uint8_t a) {
  int bytes_per_pixel = fmt->BytesPerPixel;
  int bits_per_pixel = fmt->BitsPerPixel;
  assert(bits_per_pixel != 0 || bytes_per_pixel != 0);
  
  if (bytes_per_pixel == 1) {
    assert(fmt->palette);
    return closest_color_idx(fmt->palette, r, g, b);
  } else if(bytes_per_pixel == 2) {
    assert(0 && "unsupport fmt");
  } else if(bytes_per_pixel == 3) {
    assert(0 && "unsupport fmt");
  } else {
    assert(fmt->BytesPerPixel == 4);
    uint32_t p = (r << fmt->Rshift) | (g << fmt->Gshift) | (b << fmt->Bshift);
    if (fmt->Amask)
      p |= (a << fmt->Ashift);
    return p;
  }
}

int SDL_LockSurface(SDL_Surface *s) { return 0; }

void SDL_UnlockSurface(SDL_Surface *s) {}
