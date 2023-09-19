#include "main.h"
/**
 * main - main entery point
 * @argv: normal argv
 * @argc: unused argc
 * Return: gustavo
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	int childstatus = 0, looping = 1, c, b = 1;
	size_t buffersize = BUFSIZ;
	char *command[20], *buffer = NULL, *cmd;
	ssize_t getlineread;

	signal(SIGINT, signalhandle);
	for (b = 1; looping; looping++)
	{
		if (!childstatus)
			prompt(0);
		else
			prompt(6000);
		getlineread = _getline(&buffer, &buffersize, stdin);
		if (getlineread == EOF)
		{
			prompt(1);
			break;
		}
		buffer[getlineread - 1] = '\0', cmd = _strtok(buffer, " \n");
		if (cmd != NULL)
		{
			c = 0;
			command[c++] = cmd;
			for (; c < 20; c++)
			{
				command[c] = _strtok(NULL, "\n ");
				if (command[c] == NULL)
					break;
			}
			b = bltin(command, &looping, buffer);
			childstatus = b;
			command[c] = NULL;
			if (b)
				childstatus = _execve(command, argv[0], looping);
		}
	}
	free(buffer);
	return (childstatus);
}
