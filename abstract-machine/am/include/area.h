#ifndef AREA_H__
#define AREA_H__

// Memory area for [@start, @end)
typedef struct {
  void *start, *end;
} Area;
#endif