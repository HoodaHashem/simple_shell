#include "main.h"
/**
 * pathhandle - normal function
 * @command: normal command
 * Return: gustavo
 */
char *pathhandle(char *command)
{
	char *gustavo, *pathg, *pathcpyg, *pathtokeng, *filepathg, *cmdcpyg;

	gustavo = NULL;
	pathg = NULL;
	pathcpyg = NULL;
	pathtokeng = NULL;
	filepathg = NULL;
	cmdcpyg = NULL;

	cmdcpyg = forbetty(command);
	if (cmdcpyg != NULL)
		return (cmdcpyg);
	pathg = getenvvars("PATH");
	gustavo = betty2(command, pathg, pathcpyg, pathtokeng, filepathg, cmdcpyg);
	if (gustavo != NULL)
		return (gustavo);
	return (NULL);
}
/**
 * forbetty - duuh the name!!
 * @lol: normal lol
 * Return: gustavo
 */

char *forbetty(char *lol)
{
	struct stat buf;

	if (lol[0] == '/' || lol[0] == '.')
	{
		if (stat(lol, &buf) == 0)
		{
			return (_strdup(lol));
		}
	}
	return (NULL);
}
