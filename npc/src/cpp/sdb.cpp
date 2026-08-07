#include <sdb.hpp>

Sdb::Sdb() : npc(Npc::getInstance()), ftrace(Ftrace::getInstance()) {
  initTerm();
  ref = nullptr;
  difftestOn = false;
  // if (std::ifstream("./riscv32-nemu-interpreter-so").good()) {
  //   ref = new Difftest("./riscv32-nemu-interpreter-so");
  //   ref->init(0);
  //   ref->loadMemory();
  //   difftestOn = true;
  // }
  commandMap = {{"c", &Sdb::cmdC},
                {"pc", &Sdb::cmdPC},
                {"si", &Sdb::cmdSi},
                {"ftrace", &Sdb::cmdFtrace},
                {"wtrace", &Sdb::cmdWtrace},
                {"performance", &Sdb::cmdPerformance},
                {"difftest", &Sdb::cmdDifftest},
                {"batch", &Sdb::cmdBatch}};
  struct sigaction sa;
  sa.sa_handler = sigintHandler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGINT, &sa, NULL);
  SDL_SetEventFilter(
      [](void *, SDL_Event *event) -> int {
        if (event->type == SDL_QUIT ||
            (event->type == SDL_WINDOWEVENT &&
             event->window.event == SDL_WINDOWEVENT_CLOSE)) {
          interrupted = 2;
          return 0;
        }
        return 1;
      },
      NULL);
}
