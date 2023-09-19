#include "main.h"
/**
 * signalhandle - normal function
 * @owrsignal: normal owrsignal
 */
void signalhandle(int owrsignal)
{
	if (owrsignal == SIGINT)
	{
		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, "\n$ ", 3);

			fflush(STDIN_FILENO);
		}
	}
}
