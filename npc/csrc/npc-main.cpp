#include <wave.h>
#include <common.h>
#include <circuit.h>
#include <mem.h>
#include <utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <timer.h>
#include <lightsss.h>

extern LightSSS lightsss;

void init_monitor(int, char *[]);
void sdb_mainloop();

const char *npc_home_path = NULL;
void init_env_vars(void) {
    npc_home_path = getenv("NPC_HOME");
    if (npc_home_path == NULL) {
        fprintf(stderr, "错误：环境变量 NPC_HOME 未定义！\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {\
    /*初始化一些东西*/
    init_env_vars();
    get_time();
#ifdef NPCCONFIG_DUMPWAVE
    char wave_path[1024];
    snprintf(wave_path, sizeof(wave_path), "%s/build/wave_father.fst", npc_home_path);
    init_wave(wave_path);
#endif
    init_monitor(argc, argv);

    Verilated::commandArgs(argc, argv);
    reset(10);
    sdb_mainloop();
    close_wave(0);
#ifdef NPCCONFIG_LIGHTSSS
    lightsss.do_clear(); // 在正常退出时清理子进程
#endif
}
