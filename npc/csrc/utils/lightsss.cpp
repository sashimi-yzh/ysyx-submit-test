#include <lightsss.h>
#include <unistd.h>
#include <stdio.h>
#include <circuit.h>

pid_t LightSSS::p_pid = -1;
std::deque<pid_t> LightSSS::pidSlot = {};
ForkShareMemory LightSSS::forkshm;

ForkShareMemory::ForkShareMemory() {
  if ((key_n = ftok(".", 's') < 0)) {
    perror("Fail to ftok\n");
    FAIT_EXIT
  }

  if ((shm_id = shmget(key_n, 1024, 0666 | IPC_CREAT)) == -1) {
    perror("shmget failed...\n");
    FAIT_EXIT
  }

  void *ret = shmat(shm_id, NULL, 0);
  if (ret == (void *)-1) {
    perror("shmat failed...\n");
    FAIT_EXIT
  } else {
    info = (shinfo *)ret;
  }

  info->flag = false;
  info->notgood = false;
  info->endCycles = 0;
  info->oldest = 0;
}

ForkShareMemory::~ForkShareMemory() {
  if (shmdt(info) == -1) {
    perror("detach error\n");
  }
  shmctl(shm_id, IPC_RMID, NULL);
}

void ForkShareMemory::shwait() {
  while (true) {
    if (info->flag) {
    //   printf("Child %d info->flag is true. notgood: %d\n", getpid(), info->notgood);
      if (info->notgood)
        break;
      else
        exit(0);
    } else {
    //   printf("Child %d info->flag is false. is_p_dead: %d\n", getpid(), info->is_p_dead);
      if(info->is_p_dead){
        exit(0);
      }else{
        sleep(WAIT_INTERVAL);
      }
    }
  }
//   printf("Child %d exited shwait loop.\n", getpid());
}

void LightSSS::signal_handler(int signum){
    forkshm.info->is_p_dead = true;
    exit(EXIT_FAILURE);
}

void LightSSS::signal_handler_abort(int signum){
    if(p_pid != getpid()) return;
    if(pidSlot.empty()) return;
    // printf("handler abort signum: %d, pidSlot size: %ld\n", signum, pidSlot.size());
    forkshm.info->endCycles = -1;
    forkshm.info->oldest = pidSlot.back();

    for(auto pid = pidSlot.begin(); pid != pidSlot.end();) {
        if(*pid != forkshm.info->oldest) {
            kill(*pid, SIGKILL);
            waitpid(*pid, NULL, 0);
            pid = pidSlot.erase(pid);
        }else{
            pid++;
        }
    }
    fflush(stdout);
    fflush(stderr);

    forkshm.info->notgood = true;
    forkshm.info->flag = true;
    int status = -1;

    waitpid(pidSlot.back(), &status, 0);
    exit(EXIT_FAILURE);
}

int LightSSS::do_fork() {
  if(getpid() != p_pid) return 0;
  //kill the oldest blocked checkpoint process
  if (slotCnt == SLOT_SIZE) {
    pid_t temp = pidSlot.back();
    pidSlot.pop_back();
    kill(temp, SIGKILL);
    int status = 0;
    waitpid(temp, NULL, 0);
    slotCnt--;
    char old_filename[256];
  }
  // fork a new checkpoint process and block it
  if ((pid = fork()) < 0) {
    // printf("[%d]Error: could not fork process!\n", getpid());
    return FORK_ERROR;
  }
  // the original process
  else if (pid != 0) {
    slotCnt++;
    pidSlot.push_front(pid);
    return FORK_OK;
  }
  // for the fork child
  waitProcess = 1;
//   printf("Child %d: Entering shwait()...\n", getpid());
  forkshm.shwait();
//   printf("Child %d: Exited shwait(). Checking oldest status...\n", getpid());
  //checkpoint process wakes up
  //start wave dumping
  if (forkshm.info->oldest != getpid()) {
    // printf("Error, non-oldest process should not live. Parent Process should kill the process manually.\n");
    exit(0);
    return FORK_ERROR;
  }
  return FORK_CHILD;
}

int LightSSS::wakeup_child(uint64_t cycles) {
  forkshm.info->endCycles = cycles;
  forkshm.info->oldest = pidSlot.back();

  // only the oldest is wantted, so kill others by parent process.
  for (auto pid: pidSlot) {
    if (pid != forkshm.info->oldest) {
      kill(pid, SIGKILL);
      waitpid(pid, NULL, 0);
    }
  }
  // flush before wake up child.
  fflush(stdout);
  fflush(stderr);

  forkshm.info->notgood = true;
  forkshm.info->flag = true;
  int status = -1;
  waitpid(pidSlot.back(), &status, 0);
  return 0;
}

bool LightSSS::is_child() {
  return waitProcess;
}

int LightSSS::do_clear() {
//   printf("clear processes...\n");
  while (!pidSlot.empty()) {
    pid_t temp = pidSlot.back();
    pidSlot.pop_back();
    kill(temp, SIGKILL);
    waitpid(temp, NULL, 0);
    slotCnt--;
  }
  return 0;
}