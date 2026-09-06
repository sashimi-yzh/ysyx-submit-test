#include "common.h"
#include "cpu/cpu.h"
#include "cpu/difftest.h"
#include "difftest-def.h"
#include "isa.h"
#include "memory/paddr.h"
#include "memory/vaddr.h"
#include <stdint.h>
#include <stdio.h>

typedef struct memguarder {
  vaddr_t addr;
  struct memguarder *next;
} memguarder_t;

static memguarder_t *guard_list = NULL;

static bool probe_dut(vaddr_t addr, difftest_mem_probe_t *result) {
  word_t data = 0;
  word_t cause = 0;

  assert(result != NULL);
  result->success = vaddr_read_safe(addr, 4, &data, &cause);
  result->data = (uint32_t)data;
  result->cause = (uint32_t)cause;
  return true;
}

static bool probe_ref(vaddr_t addr, difftest_mem_probe_t *result) {
  if (ref_difftest_probe_mem == NULL) {
    printf("[error] the current ref does not support memguard probing\n");
    return false;
  }

  ref_difftest_probe_mem(addr, result, 4);
  return true;
}

static bool memguard_match(const difftest_mem_probe_t *dut,
                           const difftest_mem_probe_t *ref) {
  if (dut->success != ref->success) {
    return false;
  }
  if (dut->success) {
    return dut->data == ref->data;
  }
  return dut->cause == ref->cause;
}

static void print_probe(const char *tag, const difftest_mem_probe_t *probe) {
  if (probe->success) {
    printf("%s value=0x%x", tag, probe->data);
    return;
  }

  printf("%s fault(cause=0x%x)", tag, probe->cause);
}

int add_memguard(vaddr_t addr) {
  if (!isa_difftest_is_attach()) {
    printf("[error] the memguarder rely on the difftest\n");
    return -1;
  }

  if (ref_difftest_probe_mem == NULL) {
    printf("[error] the current ref does not support memguard probing\n");
    return -1;
  }

  memguarder_t **cur = &guard_list;
  memguarder_t *new_node = NULL;
  while (*cur) {
    if ((*cur)->addr == addr)
      return 0;
    cur = &(*cur)->next;
  }

  difftest_mem_probe_t ref_probe = {0};
  difftest_mem_probe_t dut_probe = {0};
  if (!probe_ref(addr, &ref_probe)) {
    return -1;
  }
  probe_dut(addr, &dut_probe);

  if (!memguard_match(&dut_probe, &ref_probe)) {
    printf("[error] memguard probe mismatch at 0x%x: ", addr);
    print_probe("dut", &dut_probe);
    printf(", ");
    print_probe("ref", &ref_probe);
    printf("\n");
    printf("\tconsider resyncing difftest or checking the mapping context\n");
    return -1;
  }

  new_node = (memguarder_t *)malloc(sizeof(memguarder_t));
  if (!new_node) {
    printf("[error] malloc failed\n");
    return -1;
  }
  new_node->addr = addr;
  new_node->next = NULL;
  *cur = new_node;

  return 0;
}

void info_memguard() {
  memguarder_t *cur = guard_list;
  int i = 0;
  while (cur != NULL) {
    difftest_mem_probe_t dut_probe = {0};
    probe_dut(cur->addr, &dut_probe);
    printf("memguard[%d] watching addr 0x%x: ", i, cur->addr);
    print_probe("dut", &dut_probe);
    if (ref_difftest_probe_mem != NULL) {
      difftest_mem_probe_t ref_probe = {0};
      if (probe_ref(cur->addr, &ref_probe)) {
        printf(", ");
        print_probe("ref", &ref_probe);
      }
    }
    printf("\n");
    cur = cur->next;
    i++;
  }

  return;
}

void del_memguard(int idx) {
  int counter = 0;
  memguarder_t **cur = &guard_list;
  while (*cur != NULL) {
    if (counter == idx) {
      vaddr_t addr = (*cur)->addr;
      memguarder_t *to_del = *cur;
      *cur = (*cur)->next;
      free(to_del);
      printf("delete memguard[%d] watching on addr 0x%x successfully\n", idx,
             addr);
      return;
    }

    counter++;
    cur = &(*cur)->next;
  }

  printf("cannot found memguard[%d]\n", idx);
  return;
}

void exec_memguard() {
  memguarder_t *cur = guard_list;
  bool failed = false;
  int idx = 0;
  while (cur != NULL) {
    difftest_mem_probe_t ref_probe = {0};
    difftest_mem_probe_t dut_probe = {0};
    if (!probe_ref(cur->addr, &ref_probe)) {
      set_state_stop();
      return;
    }
    probe_dut(cur->addr, &dut_probe);

    if (!memguard_match(&dut_probe, &ref_probe)) {
      failed = true;
      printf("[memguard failed] guard[%d] addr=0x%x: ", idx, cur->addr);
      print_probe("dut", &dut_probe);
      printf(", ");
      print_probe("ref", &ref_probe);
      printf("\n");
    }

    cur = cur->next;
    idx++;
  }

  if (failed) {
    set_state_stop();
  }

  return;
}
