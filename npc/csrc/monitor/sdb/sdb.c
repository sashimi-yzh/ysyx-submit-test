#include "sdb.h"
#include "utils.h"

void cpu_exec(uint64_t n);
word_t vaddr_read(vaddr_t raddr);
word_t eval_expr(char *e, bool *success);
void reg_display();
void init_regex();
void init_wp_pool();
void set_watchpoint(char *args);
void info_watchpoint();
void free_wp(uint32_t N);


static bool is_batch_mode = false;

static int cmd_help(char *args);
static int cmd_c(char *args);
static int cmd_q(char *args);
static int cmd_si(char *args);
static int cmd_info(char *args);
static int cmd_x(char *args);
static int cmd_p(char *args);
static int cmd_w(char *args);
static int cmd_d(char *args);

#define NR_CMD ARRLEN(cmd_table)

static struct {
    const char *name;
    const char *description;
    int (*handler)(char *);
} cmd_table[] = {
    { "help", "Display informations about all supported commands", cmd_help },
    { "c", "Continue the execution of the program", cmd_c },
    { "q", "Exit npc", cmd_q },
    { "si", "Execute inst step", cmd_si },
    { "info", "Print register or monitoring point information", cmd_info },
    { "x", "Find the value of the expression EXPR and use the result as the starting memory. The address is output in hexadecimal form as N consecutive 4-bytes", cmd_x },
    { "p", "Find the value of the expression EXPR", cmd_p },
    { "w", "Stop if EXPR changes", cmd_w },
    { "d", "Delete the monitor point with serial number N", cmd_d },
};

static char *rl_gets()
{
    static char *line_read = NULL;

    if (line_read) {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");

    if (line_read && *line_read) {
        add_history(line_read);
    }

    return line_read;
}

static int cmd_help(char *args)
{
    /* extract the first argument */
    char *arg = strtok(args, " ");
    int i;

    if (arg == NULL) {
        /* no argument given */
        for (i = 0; i < NR_CMD; i++) {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    } else {
        for (i = 0; i < NR_CMD; i++) {
            if (strcmp(arg, cmd_table[i].name) == 0) {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

static int cmd_c(char *args)
{
    // Continue the execution of the program
    cpu_exec(-1);
    return 0;
}

static int cmd_q(char *args)
{
    // Exit npc
    npc_state.state = NPC_QUIT;
    return -1;
}

static int cmd_si(char *args)
{
    char *arg = strtok(args, " ");
    if (arg == NULL) {
        cpu_exec(1);
    } else {
        for (char *p = arg; *p != '\0'; p++) {
            if (!isdigit(*p)) {
                printf("Error: need a number\n");
                return 0;
            }
        }

        int n = atoi(arg);
        if (n <= 0) {
            printf("Error: Must be a positive number\n");
            return 0;
        }

        cpu_exec((uint64_t)n);
    }

    return 0;
}

static void info_cmd_print()
{
    printf("info <subcommand>\n");
    printf(" r  - print Integer regs status\n");
    printf(" w  - print watching point status\n");
}

static int cmd_info(char *args)
{
    char *arg = strtok(args, " ");
    if (arg == NULL) {
        info_cmd_print();
    } else {
        char cmd_char = arg[0];
        if (arg[1] != '\0') {
            printf("Unknown subcommand '%s'\n", arg);
            info_cmd_print();
            return 0;
        } else {
            switch (cmd_char) {
            case 'r':
                reg_display();
                break;
            case 'w':
                info_watchpoint();
                break;
            default:
                printf("Unknown subcommand '%s'\n", arg);
                info_cmd_print();
                break;
            }
        }
    }

    return 0;
}

static int cmd_x(char *args)
{
    char *arg = strtok(args, " ");
    char *expr_arg = strtok(NULL, "");
    bool success = false;
    if(arg == NULL || expr_arg == NULL) {
        printf("Error: Please input: x <N> <EXPR>\n");
    } else {

        int n = atoi(arg);
        word_t expr_res = eval_expr(expr_arg, &success);
        // printf("expr_res: 0x%08x\n", expr_res);
        if(!success) {
            printf("expr error\n");
        }

        for(int i=0; i<n; i++) {
            printf("addr-0x%08x --> inst: %08x\n", expr_res+4*i, vaddr_read(expr_res+4*i));
        }
    }
    return 0;
}

static int cmd_p(char *args)
{
    if (args == NULL) {
        printf("p <expr>\n");
        printf("eg: p 1+2\n");
        return 0;
    }

    bool success;
    word_t result = eval_expr(args, &success);

    if (success) {
        printf("result: 0x%08x(%u)\n", result, result);
    } else {
        printf("Error to evaluate\n");
    }

    return success ? 0 : -1;
}

static int cmd_w(char *args)
{
    if (args == NULL) {
        printf("Need expr to be a wp\n");
        return 0;
    }

    set_watchpoint(args);
    return 0;
}

static int cmd_d(char *args)
{
    char *arg = strtok(args, " ");
    if (arg == NULL) {
        printf("Error: Please input: d <N>\n");
        return 0;
    }

    if(arg[0] < '0' || arg[0] > '9') {
        printf("Error: should input d <N>\n");
        printf("Error: Must be a num in [0,31]\n");
        return 0;
    }

    int n = atoi(arg);
    if (n < 0 || n >= 32) {
        printf("Error: Please input: d <N>\n");
        printf("Error: Must be a num in [0,31]\n");
        return 0;
    }

    free_wp(n);
    return 0;
}


void sdb_set_batch_mode()
{
    is_batch_mode = true;
}

void sdb_mainloop()
{
    if (is_batch_mode) {
        cmd_c(NULL);
        return;
    }
    for (char *str; (str = rl_gets()) != NULL;) {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL) {
            continue;
        }

        /* treat the remaining string as the arguments,
         * which may need further parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end) {
            args = NULL;
        }

#ifdef CONFIG_DEVICE
        extern void sdl_clear_event_queue();
        sdl_clear_event_queue();
#endif

        int i;
        for (i = 0; i < NR_CMD; i ++) {
          if (strcmp(cmd, cmd_table[i].name) == 0) {
            if (cmd_table[i].handler(args) < 0) { return; }
            break;
          }
        }
        if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
    }
}

void init_sdb()
{
    /* Compile the regular expressions. */
    init_regex();

    /* Initialize the watchpoint pool. */
    init_wp_pool();
}
