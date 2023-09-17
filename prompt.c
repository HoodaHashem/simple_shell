#include "main.h"

void prompt(int status)
{
	if (!status)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(STDIN_FILENO);
			write(STDOUT_FILENO, "$ ", 2);
		}
	}
	else if (status == 6000)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(STDIN_FILENO);
			write(STDOUT_FILENO, "$ ", 2);
		}
	}
	else if (status == 2000)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
	}
	else
	{
		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
			fflush(STDIN_FILENO);
		}
	}
}