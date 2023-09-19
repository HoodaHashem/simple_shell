#include "main.h"
/**
 * pathhandle - normal function
 * @command: normal command
 * Return: gustavo
 */
char *pathhandle(char *command)
{
	char *pathg, *pathcpyg, *pathtokeng, *filepathg, *cmdcpyg;
	struct stat buffer;

	cmdcpyg = forbetty(command);
	if (cmdcpyg != NULL)
		return (cmdcpyg);
	pathg = getenvvars("PATH");
	if (pathg)
	{
		pathcpyg = _strdup(pathg);
		if (pathcpyg == NULL)
			return (NULL);
		pathtokeng = strtok(pathcpyg, ":");
		while (pathtokeng != NULL)
		{
			filepathg = malloc(_strlen(pathtokeng) + _strlen(command) + 2);
			if (filepathg == NULL)
			{
				free(pathcpyg);
				return (NULL);
			}
			compathandcmd(filepathg, command, pathtokeng);
			if (stat(filepathg, &buffer) == 0)
			{
				cmdcpyg = _strdup(filepathg);
				free(pathcpyg);
				free(filepathg);
				return (cmdcpyg);
			}
			free(filepathg);
			filepathg = NULL;
			pathtokeng = strtok(NULL, ":");
		}
		free(pathcpyg);
		pathcpyg = NULL;
	}
	if (stat(command, &buffer) == 0)
	{
		cmdcpyg = _strdup(command);
		return (cmdcpyg);
	}
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
