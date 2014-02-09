#include <sys/types.h>

pid_t _getpid()
{
	return 0;
}

void _exit(int status)
{
	(void) status;
	while (1)
		;
}

int _kill(int pid, int sig)
{
	(void) pid;
	(void) sig;
	return -1;
}

int _open_r(void *reent, const char *file, int flags, int mode)
{
	(void) reent;
	(void) file;
	(void) flags;
	(void) mode;
	return -1;
}

int __cxa_end_cleanup()
{
	return -1;
}

void __gxx_personality_v0()
{

}

void *__dso_handle = NULL;
