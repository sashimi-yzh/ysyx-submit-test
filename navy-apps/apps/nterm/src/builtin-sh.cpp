#include <nterm.h>
#include <stdarg.h>
#include <unistd.h>
#include <SDL.h>
#include <fcntl.h>
char handle_key(SDL_Event *ev);
static void sh_printf(const char *format, ...)
{
	static char buf[256] = {};
	va_list ap;
	va_start(ap, format);
	int len = vsnprintf(buf, 256, format, ap);
	va_end(ap);
	term->write(buf, len);
}

static void sh_banner()
{
	sh_printf("Built-in Shell in NTerm (NJU Terminal)\n\n");
}

static void sh_prompt()
{
	sh_printf("sh> ");
}

static void sh_handle_cmd(const char *cmd)
{
	char n_cmd[256] = {};
	memcpy(n_cmd, cmd, 256);
	char *argv[8] = {};
	char *null_ptr[1] = {NULL}; // For execve to use the environment variables
	int argc = 0;
	argv[argc++] = n_cmd; // First argument is the command itself
	for (int i = 0; n_cmd[i] != '\0'; i++)
	{
		if (n_cmd[i] == '\n' || n_cmd[i] == ' ')
		{
			n_cmd[i] = '\0';
			if (n_cmd[i + 1] != '\0' && n_cmd[i + 1] != ' ')
				argv[argc++] = &n_cmd[i + 1]; // Next argument starts after the null terminator
		}
	}
	argv[argc] = NULL; // Null-terminate the argument list
	if (n_cmd[0] == '/')
		execve(n_cmd, argv, null_ptr);
	else
	{
		printf("Executing command: %s\n", n_cmd);
		execvp(n_cmd, argv);
	}
}

void builtin_sh_run()
{
	sh_banner();
	sh_prompt();
	setenv("PATH", "/bin:/usr/bin", 1);
	while (1)
	{
		SDL_Event ev;
		if (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_KEYUP || ev.type == SDL_KEYDOWN)
			{
				const char *res = term->keypress(handle_key(&ev));
				if (res)
				{
					sh_handle_cmd(res);
					sh_prompt();
				}
			}
		}
		refresh_terminal();
	}
}
