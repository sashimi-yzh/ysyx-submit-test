#pragma once
#include <csignal>
#include <fcntl.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

class StatusPipe {
private:
  const char *path;
  int fd = -1;

  static void initSignal() {
    static bool done = false;
    if (!done) {
      signal(SIGPIPE, SIG_IGN);
      done = true;
    }
  }

  void ensureOpen() {
    if (fd >= 0)
      return;
    fd = open(path, O_WRONLY | O_NONBLOCK);
  }

public:
  StatusPipe(const char *fifoPath) : path(fifoPath) {
    initSignal();
    mkfifo(path, 0666);
  }

  ~StatusPipe() {
    if (fd >= 0)
      close(fd);
  }

  template <typename F>
  void write(F &&getLine) {
    ensureOpen();
    if (fd < 0)
      return;
    std::string line = getLine();
    ssize_t ret = ::write(fd, line.c_str(), line.size());
    if (ret < 0) {
      close(fd);
      fd = -1;
    }
  }

  bool isOpen() const { return fd >= 0; }
};
