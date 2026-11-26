/***************************************************************************************
* NPC Log System
* 日志系统实现
***************************************************************************************/

#include "log.h"
#include "console.h"
#include "../core/npc.h"
#include "../core/perf.h"
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <ctime>
#include <cerrno>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

FILE *log_fp = NULL;

static int log_level = LOG_INFO;
static bool log_color_stdout = false;
static char log_buffer[1 << 20];
static const char *level_names[] = {"ERROR", "WARN", "INFO", "DEBUG"};
static const char *level_colors[] = {
  ANSI_FG_RED, ANSI_FG_YELLOW, ANSI_FG_BLUE, ANSI_FG_MAGENTA
};

static char g_run_dir[PATH_MAX] = {0};
static char g_trace_path[PATH_MAX + 32] = {0};
static char g_console_path[PATH_MAX + 32] = {0};
static char g_perf_path[PATH_MAX + 32] = {0};
static bool g_run_active = false;

void log_set_level(int level) {
  log_level = level;
}

int log_get_level() {
  return log_level;
}

bool log_color_enabled() {
  return log_color_stdout;
}

static bool make_dir(const char *path) {
  if (path == NULL || path[0] == '\0') return false;

  char tmp[PATH_MAX];
  size_t len = strlen(path);
  if (len >= sizeof(tmp)) return false;
  memcpy(tmp, path, len + 1);

  if (len > 1 && tmp[len - 1] == '/') {
    tmp[len - 1] = '\0';
  }

  for (char *p = tmp + 1; *p != '\0'; p++) {
    if (*p == '/') {
      *p = '\0';
      if (mkdir(tmp, 0755) != 0 && errno != EEXIST) {
        return false;
      }
      *p = '/';
    }
  }

  if (mkdir(tmp, 0755) != 0 && errno != EEXIST) {
    return false;
  }
  return true;
}

static bool make_run_dir(const char *root, char *out, size_t out_size) {
  if (root == NULL || root[0] == '\0') return false;
  if (!make_dir(root)) {
    fprintf(stderr, "Cannot create log root '%s': %s\n", root, strerror(errno));
    return false;
  }

  time_t now = time(NULL);
  struct tm tmv;
  localtime_r(&now, &tmv);
  char stamp[32];
  strftime(stamp, sizeof(stamp), "%Y%m%d-%H%M%S", &tmv);

  for (int i = 0; i < 1000; i++) {
    int ret;
    if (i == 0) {
      ret = snprintf(out, out_size, "%s/%s", root, stamp);
    } else {
      ret = snprintf(out, out_size, "%s/%s-%d", root, stamp, i);
    }
    if (ret < 0 || static_cast<size_t>(ret) >= out_size) {
      fprintf(stderr, "Log path is too long: %s\n", root);
      return false;
    }

    if (mkdir(out, 0755) == 0) {
      return true;
    }
    if (errno != EEXIST) {
      fprintf(stderr, "Cannot create run log directory '%s': %s\n",
              out, strerror(errno));
      return false;
    }
  }

  fprintf(stderr, "Cannot allocate a unique run log directory under '%s'\n", root);
  return false;
}

bool log_run_init(const char *trace_override) {
#ifdef ENABLE_LOG
  if (g_run_active) return true;

  const char *root = getenv("NPC_LOG_DIR");
  if (root == NULL || root[0] == '\0') {
    root = "log";
  }

  if (!make_run_dir(root, g_run_dir, sizeof(g_run_dir))) {
    return false;
  }

  snprintf(g_console_path, sizeof(g_console_path), "%s/npc.log", g_run_dir);
  snprintf(g_perf_path, sizeof(g_perf_path), "%s/perf.log", g_run_dir);
  if (trace_override != NULL && trace_override[0] != '\0') {
    snprintf(g_trace_path, sizeof(g_trace_path), "%s", trace_override);
  } else {
    snprintf(g_trace_path, sizeof(g_trace_path), "%s/trace.log", g_run_dir);
  }

  if (!console_capture_start(g_console_path)) {
    fprintf(stderr, "Cannot capture console output to '%s'\n", g_console_path);
    return false;
  }

  printf("\n==== NPC console log: %s ====\n", g_run_dir);
  init_log(g_trace_path);
  perf_log_open(g_perf_path);

  g_run_active = true;
  Log("Logs saved to %s", g_run_dir);
  atexit(log_close_run);
  return true;
#else
  (void)trace_override;
  return false;
#endif
}

void log_close_run() {
  if (!g_run_active) return;
  g_run_active = false;

  log_flush();
  console_capture_stop();
  log_flush();

  if (log_fp != NULL && log_fp != stdout) {
    fclose(log_fp);
  }
  log_fp = NULL;

  perf_log_close();
}

const char *log_run_dir() {
  return g_run_dir;
}

void init_log(const char *log_file) {
#ifdef ENABLE_LOG
  if (log_file != NULL && log_file[0] != '\0') {
    FILE *fp = fopen(log_file, "w");
    if (fp == NULL) {
      fprintf(stderr, "Can not open trace log '%s': %s; using stdout\n",
              log_file, strerror(errno));
      log_fp = stdout;
    } else {
      log_fp = fp;
      setvbuf(log_fp, log_buffer, _IOFBF, sizeof(log_buffer));
    }
  } else {
    log_fp = NULL;
  }
#else
  (void)log_file;
  log_fp = NULL;
#endif

  log_color_stdout = console_capture_active()
                         ? console_stdout_is_tty()
                         : (isatty(fileno(stdout)) != 0);

  const char *env_level = getenv("NPC_LOG_LEVEL");
  if (env_level != NULL) {
    if (strcmp(env_level, "error") == 0) log_level = LOG_ERROR;
    else if (strcmp(env_level, "warn") == 0) log_level = LOG_WARN;
    else if (strcmp(env_level, "debug") == 0) log_level = LOG_DEBUG;
    else log_level = LOG_INFO;
  }

  if (log_fp != NULL && log_fp != stdout) {
    time_t now = time(NULL);
    char tbuf[64] = {0};
    strftime(tbuf, sizeof(tbuf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(log_fp, "\n==================== NPC session start ==== %s ====================\n", tbuf);
    fflush(log_fp);
    Log("Trace log: %s", log_file);
  } else if (log_fp == NULL) {
    Log("File logging disabled (LOG=0)");
  } else {
    LogWarn("Trace log unavailable; trace output goes to stdout");
  }
}

void _Log(int level, const char *file, int line, const char *func,
          const char *format, ...) {
  if (level > log_level) return;

  char msg[4096];
  va_list args;
  va_start(args, format);
  vsnprintf(msg, sizeof(msg), format, args);
  va_end(args);

  const char *base = strrchr(file, '/');
  base = base ? base + 1 : file;

  uint64_t cyc = npc_get_cycle();
  uint64_t commit = npc_get_commit_count();
  uint64_t time = npc_get_time();

  const char *lvl = (level >= 0 && level <= LOG_DEBUG) ? level_names[level] : "INFO";

  if (log_fp != NULL && log_fp != stdout) {
    fprintf(log_fp, "[%s] [cyc=%llu commit=%llu time=%llu] [%s:%d %s] %s\n",
            lvl, (unsigned long long)cyc, (unsigned long long)commit,
            (unsigned long long)time, base, line, func, msg);
  }

  if (log_color_stdout) {
    const char *level_color =
        (level >= 0 && level <= LOG_DEBUG) ? level_colors[level] : ANSI_FG_BLUE;
    printf("%s[%s]%s %s[cyc=%llu commit=%llu time=%llu]%s %s[%s:%d %s]%s %s\n",
           level_color, lvl, ANSI_NONE,
           ANSI_DIM, (unsigned long long)cyc, (unsigned long long)commit,
           (unsigned long long)time, ANSI_NONE,
           ANSI_DIM, base, line, func, ANSI_NONE, msg);
  } else {
    printf("[%s] [cyc=%llu commit=%llu time=%llu] [%s:%d %s] %s\n",
           lvl, (unsigned long long)cyc, (unsigned long long)commit,
           (unsigned long long)time, base, line, func, msg);
  }
}

// 只写入日志文件，不输出到stdout；flush 由 log_flush() 统一完成
void log_write(const char *format, ...) {
  if (log_fp == NULL) return;
  va_list args;
  va_start(args, format);
  vfprintf(log_fp, format, args);
  va_end(args);
}

void log_flush() {
  if (log_fp != NULL) fflush(log_fp);
}

void log_trace_prefix_at(char *buf, size_t size, const char *tag,
                         uint32_t pc, uint64_t cycle, uint64_t commit, uint64_t time) {
  snprintf(buf, size, "[%s] cyc=%llu commit=%llu time=%llu pc=0x%08x ",
           tag, (unsigned long long)cycle, (unsigned long long)commit,
           (unsigned long long)time, pc);
}

void assert_fail_msg() {
  fprintf(stderr, ANSI_FMT("Assertion failed!\n", ANSI_FG_RED));
  fflush(stderr);
  log_flush();
}
