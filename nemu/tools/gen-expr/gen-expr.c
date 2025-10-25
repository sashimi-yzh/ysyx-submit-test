/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <readline/chardefs.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <sys/random.h>

// this should be enough
#define BUFLEN 65536
static char buf[BUFLEN] = {};
static char bufout[BUFLEN] = {};

int bufidx = 0;
int outidx = 0;

static char code_buf[BUFLEN + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static uint32_t choose(uint32_t n) 
{
  if (n == 0) return 0; 

    uint32_t random_value;
    
    if (getrandom(&random_value, sizeof(random_value), 0) != sizeof(random_value)) 
    {
        perror("getrandom failed");
        exit(1);
    }

    return random_value % n;
}

static void gen_num()
{
  if (bufidx >= BUFLEN) return;

  uint32_t randnum = choose(1000);
  char tmp[5] = {};
  int i = 0;

  sprintf(tmp, "%u", randnum);
  while (tmp[i]) buf[bufidx++] = tmp[i++];
  i = 0;
  while (tmp[i]) bufout[outidx++] = tmp[i++];
  buf[bufidx++] = 'u';
}

static void gen(char c)
{
  if (bufidx >= BUFLEN) return;

  buf[bufidx++] = c;
  bufout[outidx++] = c;
}

static void gen_rand_op()
{
  if (bufidx >= BUFLEN) return;

  static const char oprts[4] = {'+', '-', '*', '/'};
  uint32_t randnum = choose(4);

  buf[bufidx++] = oprts[randnum];
  bufout[outidx++] = oprts[randnum];
} 

static void gen_rand_expr() 
{
  if (bufidx >= BUFLEN) return;

  switch (choose(3)) 
  {
    case 0: gen_num(); break;
    case 1: gen('('); gen_rand_expr(); gen(')'); break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
  }
}

int main(int argc, char *argv[])
{
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }

  int i;
  for (i = 0; i < loop; i ++) 
  {
    bufidx = 0;
    memset(buf, 0, sizeof(buf));
    outidx = 0;
    memset(bufout, 0, sizeof(bufout));
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Wdiv-by-zero -Werror /tmp/.code.c -o /tmp/.expr > /dev/null 2>&1");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, bufout);
  }
  return 0;
}
