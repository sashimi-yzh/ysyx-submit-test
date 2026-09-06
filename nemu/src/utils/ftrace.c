#include "cpu/cpu.h"
#include "cpu/decode.h"
#include "isa.h"
#include <elf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef CONFIG_FTRACE
typedef struct Node {
  char *name;
  uint32_t addr;
  struct Node *next;
} Node;

Node *functbl_head = NULL;
Node *functbl_tail = NULL;
Node *func_stack = NULL;

void ftrace_init(char *elf_path) {
  FILE *fp = fopen(elf_path, "r");
  if (fp == NULL) {
    printf("cannot open the file\n");
    assert(0);
  }
  Elf32_Ehdr ehdr;
  Elf32_Shdr shdr;
  Elf32_Shdr *shdr_sym = NULL;
  Elf32_Sym sym_sym;
  long pos = 0;
  char *content = NULL;
  char *checker = ".shstrtab";
  size_t readlen = 0;

  // find the pos of symble table
  readlen = fread(&ehdr, sizeof(ehdr), 1, fp);
  if (readlen == 0) {
    printf("failure to read ehdr\n");
    assert(0);
  }
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  size_t ehdr_num = ehdr.e_shnum;
  for (size_t i = 0; i < ehdr_num; i++) {
    readlen = fread(&shdr, sizeof(Elf32_Shdr), 1, fp);
    if (readlen == 0) {
      printf("failure to read shdr\n");
      assert(0);
    }
    if (shdr.sh_type == SHT_SYMTAB) {
      shdr_sym = (Elf32_Shdr *)malloc(sizeof(Elf32_Shdr));
      *shdr_sym = shdr;
    }
    if (shdr.sh_type == SHT_STRTAB && content == NULL) {
      pos = ftell(fp);
      fseek(fp, shdr.sh_offset, SEEK_SET);
      content = (char *)malloc(sizeof(char) * (shdr.sh_size) + 1);
      readlen = fread(content, shdr.sh_size, 1, fp);
      if (readlen == 0) {
        printf("failure to read shdr\n");
        assert(0);
      }
      if (strcmp(content + shdr.sh_name, checker) == 0) {
        free(content);
        content = NULL;
      }
      fseek(fp, pos, SEEK_SET);
    }
  }

  // here the sym_sym is the symble section
  // and the content is the strtab
  // init the linkedlist of func name and addr
  fseek(fp, shdr_sym->sh_offset, SEEK_SET);
  size_t len = shdr_sym->sh_size / sizeof(Elf32_Sym);
  free(shdr_sym);
  shdr_sym = NULL;
  for (int i = 0; i < len; i++) {
    readlen = fread(&sym_sym, sizeof(Elf32_Sym), 1, fp);
    if (readlen == 0) {
      printf("failure to read sym\n");
      assert(0);
    }
    if (sym_sym.st_info == 18) {
      Node *func_node = (Node *)malloc(sizeof(Node));
      func_node->addr = sym_sym.st_value;
      size_t str_lenth = strlen(content + sym_sym.st_name);
      func_node->name = (char *)malloc(sizeof(char) * str_lenth);
      strcpy(func_node->name, content + sym_sym.st_name);
      func_node->next = NULL;
      // judge the state of functbl and insert the new func
      if (functbl_head == NULL) {
        functbl_head = func_node;
        functbl_tail = func_node;
      } else {
        functbl_tail->next = func_node;
        functbl_tail = functbl_tail->next;
      }
    }
  }
}

int func_stack_deep = -1;

void dealftrace(Decode *s) {
  Node *tmp = functbl_head;
  if (tmp == NULL) {
    printf("the ftrace encounter a NULL func linkedlist\n");
    assert(0);
  }
  if (func_stack != NULL && func_stack->addr == s->dnpc) {
    func_stack_deep--;
    if (func_stack_deep > 0) {
      for (int i = 1; i < func_stack_deep; i++)
        printf("  ");
      printf("[ret]%s\n", func_stack->name);
    }
    Node *p = func_stack;
    func_stack = p->next;
    free(p->name);
    free(p);
  }
  while (tmp != NULL) {
    if (tmp->addr == s->dnpc) {
      if (func_stack_deep > 0) {
        for (int i = 1; i < func_stack_deep; i++)
          printf("  ");
        printf("%x: [call]%s\n", tmp->addr, tmp->name);
      }
      func_stack_deep++;
      Node *func_node = (Node *)malloc(sizeof(Node));
      func_node->addr = s->snpc;
      size_t str_len = strlen(tmp->name);
      func_node->name = (char *)malloc(sizeof(char) * str_len + 1);
      strcpy(func_node->name, tmp->name);
      func_node->next = NULL;
      if (func_stack == NULL) {
        func_stack = func_node;
      } else {
        func_node->next = func_stack;
        func_stack = func_node;
      }
    }
    tmp = tmp->next;
  }
}

#endif
