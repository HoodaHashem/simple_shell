#include "main.h"
/**
 * bltin - normal function
 * @cmd: the cmd
 * @f:the intger
 * @buffer: the buffer
 * Return:gustavo
 */

int bltin(char *cmd[], int *f, char *buffer)
{
	int exitstatus;
	int childstatus = 0;

	if (_strcmp(cmd[0], "clear") == 0)
	{
		prompt(2000);
		*f = *f + 1;
		return (0);
	}
	if (_strcmp(cmd[0], "exit") == 0)
	{
		free(buffer), exit(exitstatus);
	}
	if (_strcmp(cmd[0], "env") == 0 || _strcmp(cmd[0], "printenv") == 0)
	{
		int i = 0;

		while (environ[i] != NULL)
		{
			if (i)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			i++;
		}
		return (0);
	}
	return (1);
}

