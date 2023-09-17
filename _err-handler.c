#include "main.h"

int err_handl(char *av, int ac, char *cmd)
{
    char *count = inttostr(ac);

    write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count, _strlen(count));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	free(count);
	return (127);
}
