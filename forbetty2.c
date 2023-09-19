#include "main.h"
/**
 * forbetty2 - normal function
 * @p:gustavo
 * @pcpy:gustavo
 * @pk: gustavo
 * @fp: gustavo
 * @ccpy: gustavo
 * @cmd: gustavo
 * Return: gustavo
 */
char *forbetty2(char *cmd, char *p, char *pcpy, char *pk, char *fp, char *ccpy)
{
	struct stat buffer;

	if (p)
	{
		pcpy = _strdup(p);
		if (pcpy == NULL)
			return (NULL);
		pk = strtok(pcpy, ":");
		while (pk != NULL)
		{
			fp = malloc(_strlen(pk) + _strlen(cmd) + 2);
			if (fp == NULL)
			{
				free(pcpy);
				return (NULL);
			}
			compathandcmd(fp, cmd, pk);
			if (stat(fp, &buffer) == 0)
			{
				ccpy = _strdup(fp);
				free(pcpy);
				free(fp);
				return (ccpy);
			}
			free(fp);
			fp = NULL;
			pk = strtok(NULL, ":");
		}
		free(pcpy);
		pcpy = NULL;
	}
	if (stat(cmd, &buffer) == 0)
	{
		ccpy = _strdup(cmd);
		return (ccpy);
	}
	return (NULL);
}
