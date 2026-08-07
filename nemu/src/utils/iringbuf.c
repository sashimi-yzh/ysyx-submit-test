#include "common.h"
#include <lib/ring_buffer.h>
#include <stdbool.h>
#include <utils.h>

static ring_buffer *iringbuf;
void iringbuf_init(void) {
  iringbuf = malloc(sizeof(ring_buffer));
  ring_buffer_init(iringbuf, sizeof(iringbuf_elem), 8);
}
void iringbuf_push(word_t pc, word_t inst) {
  iringbuf_elem elem;
  elem.pc = pc;
  elem.inst = inst;
  if (ring_buffer_isFull(iringbuf)) {
    ring_buffer_pop(iringbuf);
  }
  ring_buffer_push(iringbuf, &elem);
}

bool iringbuf_pop(iringbuf_elem *pc) {
  if (ring_buffer_isEmpty(iringbuf))
    return false;
  ring_buffer_peek(iringbuf, pc);
  ring_buffer_pop(iringbuf);
  return true;
}

int iringbuf_elem_size() { return ring_buffer_size(iringbuf); }