#ifndef __CONSOLE_H__
#define __CONSOLE_H__

// Console transcript capture.
//
// When LOG=1, stdout/stderr are teed into npc.log while still being shown on
// the original terminal.  readline echoes interactive commands to stdout, so
// they are captured as part of the same transcript.
bool console_capture_start(const char *path);
void console_capture_stop();
bool console_capture_active();
bool console_stdout_is_tty();

#endif
