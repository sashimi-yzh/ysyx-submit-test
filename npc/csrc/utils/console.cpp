#include "console.h"

#include <atomic>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <mutex>
#include <thread>
#include <unistd.h>

namespace {

int g_file_fd = -1;
int g_orig_stdout = -1;
int g_orig_stderr = -1;
int g_pipe_out[2] = {-1, -1};
int g_pipe_err[2] = {-1, -1};
std::thread g_thread_out;
std::thread g_thread_err;
std::mutex g_write_mutex;
std::atomic<bool> g_active(false);
bool g_stdout_is_tty = false;

bool write_all(int fd, const char *data, size_t len) {
    while (len > 0) {
        ssize_t n = ::write(fd, data, len);
        if (n > 0) {
            data += n;
            len -= static_cast<size_t>(n);
        } else if (n < 0 && errno == EINTR) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void close_fd(int &fd) {
    if (fd >= 0) {
        ::close(fd);
        fd = -1;
    }
}

void close_pipe(int pipefd[2]) {
    close_fd(pipefd[0]);
    close_fd(pipefd[1]);
}

void write_file_filtered(const char *data, size_t len) {
    if (g_file_fd < 0) return;

    // Strip terminal control sequences from the transcript file.  The terminal
    // itself gets the raw bytes, so colors/readline still work there.
    static thread_local int esc_state = 0;
    char out[8192];
    size_t out_len = 0;

    for (size_t i = 0; i < len; i++) {
        unsigned char c = static_cast<unsigned char>(data[i]);
        bool emit = true;

        switch (esc_state) {
            case 0:
                if (c == 0x1b) {
                    esc_state = 1;
                    emit = false;
                }
                break;
            case 1:
                emit = false;
                if (c == '[') {
                    esc_state = 2;
                } else if (c == ']') {
                    esc_state = 3;
                } else {
                    esc_state = 0;
                }
                break;
            case 2:
                emit = false;
                if (c >= 0x40 && c <= 0x7e) {
                    esc_state = 0;
                }
                break;
            case 3:
                emit = false;
                if (c == 0x07) {
                    esc_state = 0;
                } else if (c == 0x1b) {
                    esc_state = 4;
                }
                break;
            case 4:
                emit = false;
                if (c == '\\') {
                    esc_state = 0;
                } else {
                    esc_state = 3;
                }
                break;
            default:
                esc_state = 0;
                break;
        }

        if (emit) {
            out[out_len++] = static_cast<char>(c);
            if (out_len == sizeof(out)) {
                std::lock_guard<std::mutex> lock(g_write_mutex);
                write_all(g_file_fd, out, out_len);
                out_len = 0;
            }
        }
    }

    if (out_len > 0) {
        std::lock_guard<std::mutex> lock(g_write_mutex);
        write_all(g_file_fd, out, out_len);
    }
}

void reader_loop(int read_fd, int terminal_fd) {
    char buf[8192];
    for (;;) {
        ssize_t n = ::read(read_fd, buf, sizeof(buf));
        if (n > 0) {
            if (terminal_fd >= 0) {
                write_all(terminal_fd, buf, static_cast<size_t>(n));
            }
            write_file_filtered(buf, static_cast<size_t>(n));
        } else if (n == 0) {
            break;
        } else if (errno == EINTR) {
            continue;
        } else {
            break;
        }
    }
}

void cleanup_failed_start() {
    // Restore stdout/stderr if they were already redirected.
    if (g_orig_stdout >= 0) {
        ::dup2(g_orig_stdout, STDOUT_FILENO);
    }
    if (g_orig_stderr >= 0) {
        ::dup2(g_orig_stderr, STDERR_FILENO);
    }

    close_pipe(g_pipe_out);
    close_pipe(g_pipe_err);
    close_fd(g_orig_stdout);
    close_fd(g_orig_stderr);
    close_fd(g_file_fd);
    g_active.store(false);
}

}  // namespace

bool console_capture_start(const char *path) {
    if (g_active.load()) return true;
    if (path == nullptr || path[0] == '\0') return false;

    g_file_fd = ::open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (g_file_fd < 0) {
        std::fprintf(stderr, "Cannot open console log '%s': %s\n",
                     path, std::strerror(errno));
        return false;
    }

    if (::pipe(g_pipe_out) != 0 || ::pipe(g_pipe_err) != 0) {
        std::fprintf(stderr, "Cannot create console capture pipe: %s\n",
                     std::strerror(errno));
        cleanup_failed_start();
        return false;
    }

    // Remember the original terminal state before stdout is replaced by a pipe.
    g_stdout_is_tty = ::isatty(STDOUT_FILENO) != 0;

    g_orig_stdout = ::dup(STDOUT_FILENO);
    g_orig_stderr = ::dup(STDERR_FILENO);
    if (g_orig_stdout < 0 || g_orig_stderr < 0) {
        std::fprintf(stderr, "Cannot duplicate stdio fd: %s\n",
                     std::strerror(errno));
        cleanup_failed_start();
        return false;
    }

    // Flush pending stdio output before switching the underlying fd.
    std::fflush(stdout);
    std::fflush(stderr);

    if (::dup2(g_pipe_out[1], STDOUT_FILENO) < 0 ||
        ::dup2(g_pipe_err[1], STDERR_FILENO) < 0) {
        std::fprintf(stderr, "Cannot redirect stdio to capture pipe: %s\n",
                     std::strerror(errno));
        cleanup_failed_start();
        return false;
    }

    // fd 1/2 now hold the write ends; the temporary copies are no longer needed.
    close_fd(g_pipe_out[1]);
    close_fd(g_pipe_err[1]);

    // The original stdout may have been a terminal (line buffered).  The pipe
    // is not a TTY, so force line buffering to keep console output timely.
    std::setvbuf(stdout, nullptr, _IOLBF, 0);
    std::setvbuf(stderr, nullptr, _IONBF, 0);

    g_active.store(true);
    try {
        g_thread_out = std::thread(reader_loop, g_pipe_out[0], g_orig_stdout);
        g_thread_err = std::thread(reader_loop, g_pipe_err[0], g_orig_stderr);
    } catch (...) {
        console_capture_stop();
        return false;
    }

    std::atexit(console_capture_stop);
    return true;
}

void console_capture_stop() {
    if (!g_active.exchange(false)) return;

    // Flush stdio while the capture pipes are still active, otherwise the last
    // lines can be written back to the terminal and never reach npc.log.
    std::fflush(stdout);
    std::fflush(stderr);

    if (g_orig_stdout >= 0) {
        if (::dup2(g_orig_stdout, STDOUT_FILENO) < 0) {
            ::close(STDOUT_FILENO);
        }
    }
    if (g_orig_stderr >= 0) {
        if (::dup2(g_orig_stderr, STDERR_FILENO) < 0) {
            ::close(STDERR_FILENO);
        }
    }

    // Restoring fd 1/2 closes the pipe write ends, so the reader threads see EOF.
    if (g_thread_out.joinable()) g_thread_out.join();
    if (g_thread_err.joinable()) g_thread_err.join();

    close_pipe(g_pipe_out);
    close_pipe(g_pipe_err);
    close_fd(g_orig_stdout);
    close_fd(g_orig_stderr);
    close_fd(g_file_fd);

    std::setvbuf(stdout, nullptr, _IOLBF, 0);
    std::setvbuf(stderr, nullptr, _IONBF, 0);
}

bool console_capture_active() {
    return g_active.load();
}

bool console_stdout_is_tty() {
    if (g_active.load()) return g_stdout_is_tty;
    return ::isatty(STDOUT_FILENO) != 0;
}
