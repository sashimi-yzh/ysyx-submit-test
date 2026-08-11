#include <isa.h>
#include <npc/cpu.h>
#include <npc/memory.h>
#include <npc/runtime.h>
#include <readline/history.h>
#include <readline/readline.h>

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sdb.h"

void init_regex();
void init_wp_pool();

typedef int (*CommandHandler)(char *arguments);

typedef struct {
  const char *name;
  const char *usage;
  const char *summary;
  CommandHandler run;
} Command;

static bool run_without_prompt = false;

static char *skip_spaces(char *text) {
  while (text != NULL && isspace((unsigned char)*text)) text ++;
  return text != NULL && *text != '\0' ? text : NULL;
}

static char *take_word(char **text) {
  char *word = skip_spaces(*text);
  if (word == NULL) {
    *text = NULL;
    return NULL;
  }

  char *end = word;
  while (*end != '\0' && !isspace((unsigned char)*end)) end ++;
  if (*end == '\0') {
    *text = NULL;
  } else {
    *end = '\0';
    *text = end + 1;
  }
  return word;
}

static bool parse_number(const char *text, uint64_t *value) {
  if (text == NULL) return false;
  errno = 0;
  char *end = NULL;
  unsigned long long parsed = strtoull(text, &end, 0);
  while (end != NULL && isspace((unsigned char)*end)) end ++;
  if (errno != 0 || end == text || (end != NULL && *end != '\0')) return false;
  *value = parsed;
  return true;
}

static int cmd_c(char *arguments) {
  (void)arguments;
  cpu_exec(UINT64_MAX);
  return 0;
}

static int cmd_q(char *arguments) {
  (void)arguments;
  npc_state.state = NPC_QUIT;
  return -1;
}

static int cmd_si(char *arguments) {
  uint64_t count = 1;
  if (arguments != NULL && !parse_number(arguments, &count)) {
    puts("[sdb] usage: si [N]");
    return 0;
  }
  cpu_exec(count);
  return 0;
}

static int cmd_info(char *arguments) {
  char *kind = take_word(&arguments);
  if (kind == NULL || take_word(&arguments) != NULL) {
    puts("[sdb] usage: info r|w");
  } else if (strcmp(kind, "r") == 0) {
    isa_reg_display();
  } else if (strcmp(kind, "w") == 0) {
    display_watchpoints();
  } else {
    printf("[sdb] unknown info group '%s'\n", kind);
  }
  return 0;
}

static int cmd_x(char *arguments) {
  char *count_text = take_word(&arguments);
  char *expression = skip_spaces(arguments);
  uint64_t count = 0;
  if (!parse_number(count_text, &count) || expression == NULL) {
    puts("[sdb] usage: x <N> <EXPR>");
    return 0;
  }

  bool valid = false;
  vaddr_t address = expr(expression, &valid);
  if (!valid) {
    printf("[sdb] invalid expression: %s\n", expression);
    return 0;
  }

  for (uint64_t index = 0; index < count; index ++) {
    vaddr_t current = address + (vaddr_t)(index * sizeof(word_t));
    printf(ANSI_FG_GREEN FMT_WORD ANSI_NONE "  " ANSI_FG_BLUE FMT_WORD ANSI_NONE "\n",
        current, vaddr_read(current, sizeof(word_t)));
  }
  return 0;
}

static int cmd_p(char *arguments) {
  char *expression = skip_spaces(arguments);
  if (expression == NULL) {
    puts("[sdb] usage: p <EXPR>");
    return 0;
  }

  bool valid = false;
  word_t value = expr(expression, &valid);
  if (valid) {
    printf(ANSI_FG_GREEN "[expr] dec=%" PRIu32 " hex=0x%08" PRIx32 ANSI_NONE "\n",
        value, value);
  } else {
    printf(ANSI_FG_RED "[sdb] invalid expression: %s" ANSI_NONE "\n", expression);
  }
  return 0;
}

static int cmd_w(char *arguments) {
  char *expression = skip_spaces(arguments);
  if (expression == NULL) {
    puts("[sdb] usage: w <EXPR>");
    return 0;
  }

  int number = new_wp(expression);
  if (number < 0) {
    puts("[watch] no free slot");
  } else {
    printf("[watch] #%d set: %s\n", number, expression);
  }
  return 0;
}

static int cmd_d(char *arguments) {
  uint64_t number = 0;
  if (!parse_number(skip_spaces(arguments), &number)) {
    puts("[sdb] usage: d <NO>");
    return 0;
  }

  if (free_wp((int)number)) {
    printf("[watch] #%" PRIu64 " removed\n", number);
  } else {
    printf("[watch] #%" PRIu64 " not found\n", number);
  }
  return 0;
}

static int cmd_help(char *arguments);

static const Command commands[] = {
  { "help", "help [COMMAND]", "show command documentation", cmd_help },
  { "c",    "c",              "continue until the program stops", cmd_c },
  { "q",    "q",              "leave NPC", cmd_q },
  { "si",   "si [N]",         "execute one or N instructions", cmd_si },
  { "info", "info r|w",       "display registers or watchpoints", cmd_info },
  { "x",    "x <N> <EXPR>",   "read N words from memory", cmd_x },
  { "p",    "p <EXPR>",       "evaluate an expression", cmd_p },
  { "w",    "w <EXPR>",       "create a watchpoint", cmd_w },
  { "d",    "d <NO>",         "remove a watchpoint", cmd_d },
};

static const Command *find_command(const char *name) {
  for (int index = 0; index < ARRLEN(commands); index ++) {
    if (strcmp(commands[index].name, name) == 0) return &commands[index];
  }
  return NULL;
}

static int cmd_help(char *arguments) {
  char *name = take_word(&arguments);
  if (name != NULL) {
    const Command *command = find_command(name);
    if (command == NULL) {
      printf("[sdb] unknown command '%s'\n", name);
    } else {
      printf("%-18s %s\n", command->usage, command->summary);
    }
    return 0;
  }

  for (int index = 0; index < ARRLEN(commands); index ++) {
    printf("%-18s %s\n", commands[index].usage, commands[index].summary);
  }
  return 0;
}

static int dispatch_line(char *line) {
  char *remaining = line;
  char *name = take_word(&remaining);
  if (name == NULL) return 0;

  const Command *command = find_command(name);
  if (command == NULL) {
    printf("[sdb] unknown command '%s'\n", name);
    return 0;
  }
  return command->run(skip_spaces(remaining));
}

void sdb_mainloop() {
  if (run_without_prompt) {
    cmd_c(NULL);
    return;
  }

  while (true) {
    char *line = readline("npc> ");
    if (line == NULL) break;
    if (*line != '\0') add_history(line);
    int status = dispatch_line(line);
    free(line);
    if (status < 0) break;
  }
}

void init_sdb() {
  init_regex();
  init_wp_pool();
}

void sdb_set_batch_mode() {
  run_without_prompt = true;
}
