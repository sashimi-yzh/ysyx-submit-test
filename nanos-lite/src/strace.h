#ifndef STRACE_H
#define STRACE_H
// #define STRACE
#ifdef STRACE
#define CASE_LOG(fmt, ...)       \
	do                           \
	{                            \
		Log(fmt, ##__VA_ARGS__); \
	} while (0)
#else
#define CASE_LOG(fmt, ...) ((void)0)
#endif

#endif