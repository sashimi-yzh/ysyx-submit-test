#ifndef __MEMORY_LRSC_H__
#define __MEMORY_LRSC_H__

#include <common.h>

typedef struct {
  paddr_t addr;
  int len;
  bool valid;
} lrsc_reservation_t;

word_t lrsc_load_reserved(lrsc_reservation_t *res, paddr_t addr, int len);
// SC clears the reservation whether it succeeds or fails.
bool lrsc_store_conditional(lrsc_reservation_t *res, paddr_t addr, int len,
                            word_t data);

// Must be called before every physical store becomes visible.
void lrsc_invalidate_store(paddr_t addr, int len);

#endif
