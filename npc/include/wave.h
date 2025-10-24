#ifndef __WAVE_H__
#define __WAVE_H__

/*初始化环境路径函数*/
extern const char *npc_home_path;
void init_env_vars(void);
/*初始化波形函数, dump波形函数, 结束关闭波形函数*/
void init_wave(const char* wave_path);
void dump_wave();
void close_wave(int i);

#endif
