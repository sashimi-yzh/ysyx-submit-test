#include <memory/lrsc.h>
#include <memory/paddr.h>

static lrsc_reservation_t *active_reservation = NULL;

static inline bool range_overlap(paddr_t lhs, int lhs_len, paddr_t rhs,
                                 int rhs_len) {
  uint64_t lhs_end = (uint64_t)lhs + (uint64_t)lhs_len;
  uint64_t rhs_end = (uint64_t)rhs + (uint64_t)rhs_len;
  return !(lhs_end <= (uint64_t)rhs || rhs_end <= (uint64_t)lhs);
}

static inline void reservation_clear(lrsc_reservation_t *res) {
  if (res != NULL) {
    res->valid = false;
  }
  if (active_reservation == res) {
    active_reservation = NULL;
  }
}

word_t lrsc_load_reserved(lrsc_reservation_t *res, paddr_t addr, int len) {
  assert(res != NULL);
  assert(len > 0);

  if (active_reservation != NULL && active_reservation != res) {
    reservation_clear(active_reservation);
  }

  res->addr = addr;
  res->len = len;
  res->valid = true;
  active_reservation = res;

  return paddr_read(addr, len);
}

bool lrsc_store_conditional(lrsc_reservation_t *res, paddr_t addr, int len,
                            word_t data) {
  assert(res != NULL);
  assert(len > 0);

  bool success = active_reservation == res && res->valid && res->addr == addr &&
                 res->len == len;

  reservation_clear(res);

  if (!success) {
    return false;
  }

  paddr_write(addr, len, data);
  return true;
}

void lrsc_invalidate_store(paddr_t addr, int len) {
  assert(len > 0);

  if (active_reservation == NULL || !active_reservation->valid) {
    return;
  }

  if (range_overlap(active_reservation->addr, active_reservation->len, addr,
                    len)) {
    reservation_clear(active_reservation);
  }
}
