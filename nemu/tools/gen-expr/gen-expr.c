/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
***************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

static char buf[65536] = {0};

static void gen_space(void) {
  int k = rand() % 2; // 0~1 个空格
  for (int i = 0; i < k; i++) strcat(buf, " ");
}

static void gen_u32_lit(uint32_t x) {
  char tmp[64];
  // 用无符号常量，避免 int 参与运算造成 UB
  sprintf(tmp, "%uu", (unsigned)x);
  strcat(buf, tmp);
}

static uint32_t gen_rand_expr_val(int depth) {
  // 防止过长导致 buf 溢出
  // 这里宁可提前收敛成常量，保证一定可生成
  if (strlen(buf) > 200 || depth > 12) {
    uint32_t x = (uint32_t)(rand() % 100);
    gen_space();
    gen_u32_lit(x);
    gen_space();
    return x;
  }

  // 三种形式：NUM, (EXPR), (EXPR OP EXPR)
  switch (rand() % 3) {
    case 0: { // NUM
      uint32_t x = (uint32_t)(rand() % 100);
      gen_space();
      gen_u32_lit(x);
      gen_space();
      return x;
    }

    case 1: { // (EXPR)
      gen_space();
      strcat(buf, "(");
      gen_space();
      uint32_t v = gen_rand_expr_val(depth + 1);
      gen_space();
      strcat(buf, ")");
      gen_space();
      return v;
    }

    default: { // (EXPR OP EXPR)
      const char ops[] = "+-*/";
      char op = ops[rand() % 4];

      gen_space();
      strcat(buf, "(");
      gen_space();

      uint32_t lhs = gen_rand_expr_val(depth + 1);

      gen_space();
      size_t len = strlen(buf);
      buf[len] = op;
      buf[len + 1] = '\0';
      gen_space();

      uint32_t rhs = 0;
      if (op == '/') {
        // 生成一个“保证值非零”的右操作数，避免除 0
        // 如果递归生成出来是 0，就重来（确保一定不会 0）
        do {
          // 为了更稳，这里直接用非零字面量，也可以换成递归但要循环确保非零
          rhs = (uint32_t)((rand() % 99) + 1); // 1..99
        } while (rhs == 0);

        gen_u32_lit(rhs);
      } else {
        rhs = gen_rand_expr_val(depth + 1);
      }

      gen_space();
      strcat(buf, ")");
      gen_space();

      // 全程用 uint32_t 计算：溢出按 2^32 取模，行为定义良好
      switch (op) {
        case '+': return (uint32_t)(lhs + rhs);
        case '-': return (uint32_t)(lhs - rhs);
        case '*': return (uint32_t)(lhs * rhs);
        case '/': return (uint32_t)(lhs / rhs); // rhs 保证非 0
        default:  assert(0); return 0;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  srand((unsigned)time(NULL));

  int loop = 1;
  const char *expr_path = "expr.txt";
  const char *res_path  = "result.txt";

  if (argc > 1) sscanf(argv[1], "%d", &loop);
  if (argc > 2) expr_path = argv[2];
  if (argc > 3) res_path  = argv[3];

  FILE *fexpr = fopen(expr_path, "w");
  FILE *fres  = fopen(res_path, "w");
  assert(fexpr && fres);

  for (int i = 0; i < loop; i++) {
    buf[0] = '\0';
    uint32_t val = gen_rand_expr_val(0);

    // 分别保存：同一行号对应同一条样本
    fprintf(fexpr, "%s\n", buf);
    fprintf(fres,  "%u\n", (unsigned)val);

    // 终端也打印一份，方便你看（可按需删掉）
    printf("%u %s\n", (unsigned)val, buf);
  }

  fclose(fexpr);
  fclose(fres);
  return 0;
}
