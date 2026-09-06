#include <common.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "sdb.h"

void start_probe_task();

static bool dbg_is_on_ = false;
static int dbg_port = 0;
static int dbg_mode = INVALID;
static int probe_task_on = false;
static bool pending_ready = false;

static void dbg_disable(void) {
  dbg_is_on_ = false;
}

void set_dbg_port(int port) {
    dbg_port = port;
    dbg_is_on_ = true;
}

int get_dbg_mode() {
    return dbg_mode;
}

bool dbg_is_on() { 
    return dbg_is_on_;
}

void set_dbg_mode(dbg_mode_t mode) {
    dbg_mode = mode;
}

void dbg_mark_ready_pending(void) {
  pending_ready = true;
}

static ssize_t read_line(int fd, char *buf, size_t cap) {
  if (cap == 0) return -1;
  size_t i = 0;
  while (i + 1 < cap) {
    char c = 0;
    ssize_t n = read(fd, &c, 1);
    if (n == 0) break;           // EOF
    if (n < 0) {
      if (errno == EINTR) continue;
      return -1;
    }
    buf[i++] = c;
    if (c == '\n') break;
  }
  buf[i] = '\0';
  return (ssize_t)i;
}

static void write_best_effort(int fd, const char *buf, size_t len) {
  while (len > 0) {
    ssize_t n = write(fd, buf, len);
    if (n < 0) {
      if (errno == EINTR) continue;
      return;
    }
    buf += (size_t)n;
    len -= (size_t)n;
  }
}

// ---- socket global state (minimal, single-connection) ----
static int dbg_server_fd = -1;
static int dbg_client_fd = -1;

static void dbg_drop_client(void) {
  if (dbg_client_fd >= 0) {
    close(dbg_client_fd);
    dbg_client_fd = -1;
  }
}

static void dbg_socket_reset(void) {
  dbg_drop_client();
  if (dbg_server_fd >= 0) {
    close(dbg_server_fd);
    dbg_server_fd = -1;
  }
}

static bool dbg_has_client(void) {
  return dbg_client_fd >= 0;
}

static bool dbg_has_server(void) {
  return dbg_server_fd >= 0;
}

// Initialize server socket and block until a client connects.
// On success: dbg_server_fd/dbg_client_fd are valid and ready for I/O.
// On failure: prints error and resets fds.
bool dbg_init_and_wait_connection(void) {
    if (!dbg_is_on()) return true;
    if (dbg_port <= 0) {
        printf("dbg-server: invalid dbg_port=%d\n", dbg_port);
        return false;
    }

    if (dbg_has_client()) return true;

    if (!dbg_has_server()) {
        dbg_server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (dbg_server_fd < 0) {
            perror("dbg-server: socket");
            dbg_socket_reset();
            return false;
        }

        int yes = 1;
        if (setsockopt(dbg_server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
            perror("dbg-server: setsockopt(SO_REUSEADDR)");
            dbg_socket_reset();
            return false;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons((uint16_t)dbg_port);

        if (bind(dbg_server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("dbg-server: bind");
            dbg_socket_reset();
            return false;
        }
        if (listen(dbg_server_fd, 1) < 0) {
            perror("dbg-server: listen");
            dbg_socket_reset();
            return false;
        }
    }

    struct sockaddr_in cli;
    socklen_t cli_len = sizeof(cli);
    dbg_client_fd = accept(dbg_server_fd, (struct sockaddr *)&cli, &cli_len);
    if (dbg_client_fd < 0) {
        perror("dbg-server: accept");
        dbg_drop_client();
        return false;
    }

    // Protocol handshake: first command must be "set_mode <probe|auto>".
    char line[256];
    ssize_t n = read_line(dbg_client_fd, line, sizeof(line));
    if (n <= 0) {
        set_dbg_mode(INVALID);
        dbg_socket_reset();
        dbg_disable();
        return false;
    }

    char *save = NULL;
    char *cmd = strtok_r(line, " \t\r\n", &save);
    char *args = strtok_r(NULL, " \t\r\n", &save);
    if (cmd == NULL || strcmp(cmd, "set_mode") != 0 || args == NULL) {
        set_dbg_mode(INVALID);
        dbg_socket_reset();
        dbg_disable();
        return false;
    }

    bool ok = true;
    if (strcmp(args, "probe") == 0) {
        set_dbg_mode(PROBE_ONLY);
        start_probe_task();
    } else if(strcmp(args, "auto") == 0) {
        set_dbg_mode(AUTOMATIC);
    } else {
        printf("invlaid mode %s, dbg-server quit\n", args);
        set_dbg_mode(INVALID);
        ok = false;
    }
    if (ok) {
        write_best_effort(dbg_client_fd, "OK\n", 3);
        if (get_dbg_mode() == PROBE_ONLY) {
          // ready must come after the reply; mark it pending and let dbg_listen flush it.
          dbg_mark_ready_pending();
        }
    } else {
        write_best_effort(dbg_client_fd, "ERR\n", 4);
        set_dbg_mode(INVALID);
        dbg_socket_reset();
        dbg_disable();
        return false;
    }

    return true;
}

void finish_probe_task() {
  if(probe_task_on == false) {
    printf("the probe_taks_on is false, should not reach here\n");
    return ;
  }

  if(dbg_mode != PROBE_ONLY) {
    printf("the finish_task_on is valid only when the mode set to probe_only\n");
    return ;
  }

  probe_task_on = false;
}

void start_probe_task() {
  if (probe_task_on) {
    printf("Error: Cannot start probe task - task is already running\n");
    return ;
  }

  if (dbg_mode != PROBE_ONLY) {
    printf("Error: start_probe_task() is only valid when mode is PROBE_ONLY\n");
    return ;
  }

  probe_task_on = true;
}

void dbg_listen(void) {
  if (!dbg_is_on() || !dbg_has_client()) {
    return;
  }
  
  if (get_dbg_mode() == PROBE_ONLY) {
    if (!probe_task_on) {
      start_probe_task();
    }
    dbg_mark_ready_pending();
  }

  char cmd_buffer[256];
  char response_buffer[4096];  /* read_mem can produce ~11 chars per element */

  while (1) {
    if (pending_ready && get_dbg_mode() == PROBE_ONLY) {
      write_best_effort(dbg_client_fd, "ready\n", 6);
      pending_ready = false;
    }

    response_buffer[0] = '\0';    
    
    // Read command from client
    ssize_t n = read_line(dbg_client_fd, cmd_buffer, sizeof(cmd_buffer));
    
    if (n <= 0) {
      if (dbg_mode == INVALID) {
        return;
      }
      continue;
    }

    bool success = dbg_process_one_command(cmd_buffer, response_buffer, sizeof(response_buffer));
    
    if (strlen(response_buffer) > 0) {
      write_best_effort(dbg_client_fd, response_buffer, strlen(response_buffer));
    } else {
      const char *fallback = success ? "OK\n" : "ERR\n";
      write_best_effort(dbg_client_fd, fallback, strlen(fallback));
    }

    // Flush any post-reply events (e.g., ready after set_mode probe).
    if (pending_ready && get_dbg_mode() == PROBE_ONLY) {
      write_best_effort(dbg_client_fd, "ready\n", 6);
      pending_ready = false;
    }

    if(dbg_mode == PROBE_ONLY && probe_task_on ==  false) {
      return ;
    }  

    if (dbg_mode == INVALID || dbg_mode == DBG_QUIT) {
      return;
    }
  }
}