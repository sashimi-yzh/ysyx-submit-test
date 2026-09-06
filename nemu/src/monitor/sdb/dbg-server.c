#include "cpu/cpu.h"
#include "isa.h"
#include <memory/paddr.h>
#include <common.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#include "sdb.h"

// dbg command
void dbg_step(int n) {
    cpu_exec(n);
}

void dbg_continue() {
    cpu_exec(-1);
}

void dbg_read_reg(const char *regname, bool *success, word_t *result) {
    *result = isa_reg_str2val(regname, success);
}

void dbg_read_mem(paddr_t addr, void *buf, size_t n, size_t len) {
    uint32_t *dst = (uint32_t *)buf;
    for (size_t i = 0; i < n; i++) {
        word_t data = paddr_read(addr + i * len, (int)len);
        dst[i] = data;
    }
}

void dbg_write_mem(paddr_t addr, void *buf, size_t n, size_t len) {
    uint8_t *src = (uint8_t *)buf;
    for (size_t i = 0; i < n; i++) {
        word_t data = 0;
        memcpy(&data, src + i * len, len);
        paddr_write(addr + i * len, (int)len, data);
    }
}

bool dbg_is_over() {
    int state = get_nemu_state();
    return (state == NEMU_END || state == NEMU_ABORT);
}

void dbg_quit() {
    set_state_quit();
}

void finish_probe_task();
void start_probe_task();
// socket
typedef bool (*dbg_cmd_handler_t)(char *args[], int arg_num, char *reply);

typedef struct {
    const char *name;
    dbg_cmd_handler_t handler;
    bool not_probe;
} dbg_command_t;

static bool cmd_set_mode(char *args[], int arg_num, char *reply);
static bool cmd_step(char *args[], int arg_num, char *reply);
static bool cmd_is_over(char *args[], int arg_num, char *reply);
static bool cmd_quit(char *args[], int arg_num, char *reply);
static bool cmd_read_mem(char *args[], int arg_num, char *reply);
static bool cmd_write_mem(char *args[], int arg_num, char *reply);
static bool cmd_read_reg(char *args[], int arg_num, char *reply);
static bool cmd_finish(char *args[], int arg_num, char *reply);

static const dbg_command_t dbg_cmd_table[] = {
    // execution control
    { "step", cmd_step, true},
    { "continue", NULL, true},
    // registers/memory
    { "read_reg", cmd_read_reg, false},
    {"write_reg", NULL, false},
    { "read_mem", cmd_read_mem, false },
    { "write_mem", cmd_write_mem, false }, // allow probe_only to change memory
    // state control
    { "is_over", cmd_is_over, false},
    { "quit", cmd_quit, true},
    // mode
    { "set_mode", cmd_set_mode, false},
    {"finish", cmd_finish, false},
};

static const size_t dbg_cmd_table_size = sizeof(dbg_cmd_table) / sizeof(dbg_cmd_table[0]);

static const dbg_command_t *find_command(const char *name) {
    for (size_t i = 0; i < dbg_cmd_table_size; i++) {
        if (strcmp(name, dbg_cmd_table[i].name) == 0) {
            return &dbg_cmd_table[i];
        }
    }
    return NULL;
}

static bool cmd_set_mode(char *args[], int arg_num, char *reply) {
    if(arg_num < 1 || args[0] == NULL) {
        sprintf(reply, "ERR:the mode cannot be null\n");
        set_dbg_mode(INVALID);
        return false;
    }

    char *mode_str = args[0];
    if (strcmp(mode_str, "probe") == 0) {
        set_dbg_mode(PROBE_ONLY);
        start_probe_task();
        dbg_mark_ready_pending();
    } else if(strcmp(mode_str, "auto") == 0) {
        set_dbg_mode(AUTOMATIC);
    } else {
        sprintf(reply, "ERR:invalid mode %s\n", mode_str);
        set_dbg_mode(INVALID);
        return false;
    }
    sprintf(reply, "OK:mode set to %s\n", mode_str);
    return true;
}

static bool cmd_step(char *args[], int arg_num, char *reply) {
    int n = 0;
    if (arg_num < 1 || args[0] == NULL || args[0][0] == '\0') {
        n = 1;
    } else {
        n = atoi(args[0]);
    }
    if (n <= 0) {
        sprintf(reply, "ERR:step count must be positive\n");
        return false;
    }
    
    dbg_step(n);
    sprintf(reply, "OK:stepped %d\n", n);
    return true;
}

static bool cmd_is_over(char *args[], int arg_num, char *reply) {
    // is_over 命令不需要参数
    bool is_over = dbg_is_over();
    sprintf(reply, "OK:%s\n", is_over ? "true" : "false");
    return true;
}

static bool cmd_quit(char *args[], int arg_num, char *reply) {
    // quit 命令不需要参数
    dbg_quit();
    set_dbg_mode(DBG_QUIT);
    return true;
}


static bool cmd_finish(char *args[], int arg_num, char *reply) {
    finish_probe_task();
    sprintf(reply, "OK\n");
    return true;
}

// read_mem 0x80000000 3 4 -> 从0x80000000 开始读3个四字节
// reply format "OK:[data1,data2,data3]"
static bool cmd_read_mem(char *args[], int arg_num, char *reply) {
    if (arg_num < 3) {
        sprintf(reply, "ERR:arguments missing, need 3 arguments\n");
        return false;
    }

    char *str_addr = args[0];
    char *str_n = args[1];
    char *str_len = args[2];

    char *endptr = NULL;
    uint32_t addr = (uint32_t)strtoul(str_addr, &endptr, 0);
    if(*endptr != '\0') {
        sprintf(reply, "ERR:invalid address format\n");
        return false;
    }

    int n = (int)strtol(str_n, &endptr, 10);
    if (*endptr != '\0' || n <= 0) {
        sprintf(reply, "ERR:invalid count (must be positive integer)\n");
        return false;
    }
    /* Each element ~11 chars; keep total reply under 4K */
    if (n > 360) {
        sprintf(reply, "ERR:count %d exceeds max 360\n", n);
        return false;
    }

    int len = (int)strtol(str_len, &endptr, 10);
    if (*endptr != '\0' || (len != 1 && len != 2 && len != 4)) {
        sprintf(reply, "ERR:invalid length (must be 1, 2, or 4)\n");
        return false;
    }

    uint32_t *buffer = (uint32_t*)malloc(n * sizeof(uint32_t));
    if (buffer == NULL) {
        sprintf(reply, "ERR:memory allocation failed\n");
        return false;
    }
    
    dbg_read_mem(addr, (void *)buffer, n, len);

    char *p = reply;
    p += sprintf(p, "OK:[");
    
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            p += sprintf(p, ",");
        }
        
        if (len == 4) {
            p += sprintf(p, "0x%08x", buffer[i]);
        } else if (len == 2) {
            p += sprintf(p, "0x%04x", buffer[i] & 0xFFFF);
        } else { // len == 1
            p += sprintf(p, "0x%02x", buffer[i] & 0xFF);
        }
    }
    
    sprintf(p, "]\n");

    free(buffer);
    return true;
}

// write_mem 0x80000000 2 [data1,data2,data3]
static bool cmd_write_mem(char *args[], int arg_num, char *reply) {
    if (arg_num < 3) {
        sprintf(reply, "ERR:arguments missing, need 3 arguments\n");
        return false;
    }

    char *str_addr = args[0];
    char *str_len = args[1];
    char *str_data = args[2];

    char *endptr = NULL;
    uint32_t addr = (uint32_t)strtoul(str_addr, &endptr, 0);
    if(*endptr != '\0') {
        sprintf(reply, "ERR:invalid address format\n");
        return false;
    }

    int len = (int)strtol(str_len, &endptr, 10);
    if (*endptr != '\0' || (len != 1 && len != 2 && len != 4)) {
        sprintf(reply, "ERR:invalid length (must be 1, 2, or 4)\n");
        return false;
    }

    if (str_data[0] != '[') {
        sprintf(reply, "ERR:data must start with '['\n");
        return false;
    }

    // 跳过开头的'['
    str_data++;

    // 计算数据个数
    int n = 0;
    const char *p = str_data;
    while (*p && *p != ']') {
        if (*p == ',') {
            n++;
        }
        p++;
    }
    n++; // 最后一个数据

    if (*p != ']') {
        sprintf(reply, "ERR:data must end with ']'\n");
        return false;
    }

    // 分配缓冲区存储解析后的数据
    uint8_t *buffer = (uint8_t *)malloc(n * len);
    if (buffer == NULL) {
        sprintf(reply, "ERR:memory allocation failed\n");
        return false;
    }

    // 解析数据
    p = str_data;
    char token[32];
    for(int i = 0; i<n; i++) {
        while(*p == ',') p++;

        const char *start = p;

        while (*p && *p != ',' && *p != ']') p++;

        if(start == p) {
            free(buffer);
            sprintf(reply, "ERR:empty data at position %d\n", i);
            return false;
        }

        size_t token_len = p - start;
        if (token_len >= sizeof(token)) {
            free(buffer);
            sprintf(reply, "ERR:data token too long\n");
            return false;
        }

        strncpy(token, start, token_len);
        token[token_len] = '\0';
        
        char *token_endptr;
        uint32_t value = (uint32_t)strtoul(token, &token_endptr, 0);
        if (*token_endptr != '\0') {
            free(buffer);
            sprintf(reply, "ERR:invalid data format at position %d: %s\n", i, token);
            return false;
        }
        
        // 根据数据长度检查数值范围
        uint32_t max_value;
        switch(len) {
            case 1: max_value = 0xFF; break;
            case 2: max_value = 0xFFFF; break;
            case 4: max_value = 0xFFFFFFFF; break;
            default: max_value = 0xFFFFFFFF;
        }
        
        if (value > max_value) {
            free(buffer);
            sprintf(reply, "ERR:data value 0x%x exceeds %d-byte limit\n", value, len);
            return false;
        }
        
        memcpy(buffer + i * len, &value, len);
    }
    
    dbg_write_mem(addr, buffer, n, len);

    free(buffer);

    sprintf(reply, "OK\n");
    return true;
}

// read_reg pc -> OK:[data]
static bool cmd_read_reg(char *args[], int arg_num, char *reply) {
    bool success = true;
    word_t data = isa_reg_str2val(args[0], &success);
    if(success) {
        sprintf(reply, "OK:[%d]\n", data);
        return true;
    } else {
        sprintf(reply, "ERR\n");
        return false;
    }
}

#define DBG_MAXARG 5
bool dbg_process_one_command(char *cmd_line, char *replay, size_t replay_size) {
    dbg_mode_t dbg_mode = get_dbg_mode();
  
    if (cmd_line == NULL || strlen(cmd_line) == 0) {
        snprintf(replay, replay_size, "ERR empty_command\n");
        printf("dbg-server: empty command\n");
        return false;
    }

    char *tokens[DBG_MAXARG] = {0};
    char *saveptr = NULL;
    int argc = 0;

    char *token = strtok_r(cmd_line, " \t\r\n", &saveptr);
    while (token != NULL && argc < DBG_MAXARG) {
        tokens[argc++] = token;
        token = strtok_r(NULL, " \t\r\n", &saveptr);
    }
    char *cmd = tokens[0];
    char *argv[DBG_MAXARG] = {0};
    for(int i = 1; i<argc;i++) {
        argv[i-1] = tokens[i];
    }

    if (cmd == NULL) {
        snprintf(replay, replay_size, "ERR empty_command\n");
        printf("dbg-server: empty command after parsing\n");
        return false;
    }

    // Check mode validity
    if (dbg_mode == INVALID) {
        if (strcmp(cmd, "set_mode") != 0) {
            printf("dbg-server: mode invalid, only set_mode allowed as first command\n");
            snprintf(replay, replay_size, "ERR mode_invalid\n");
            return false;
        }
    }

    // Dispatch to handler
    const dbg_command_t *ent = find_command(cmd);
    if (ent == NULL) {
        set_dbg_mode(INVALID);
        printf("dbg-server: unknown command '%s', mode set to INVALID\n", cmd);
        snprintf(replay, replay_size, "ERR unknown_command\n");
        return false;
    }
    
    if (ent && ent->handler) {
        if (dbg_mode == PROBE_ONLY && ent->not_probe) {
            printf("dbg-server: command '%s' is forbidden in PROBE_ONLY mode\n", cmd);
            snprintf(replay, replay_size, "ERR forbidden_in_probe_only\n");
            return false;
        }
        
        ent->handler(argv, argc-1, replay);
    } else {
        snprintf(replay, replay_size, "ERR no_handler\n");
        return false;
    }

    return true;
}

