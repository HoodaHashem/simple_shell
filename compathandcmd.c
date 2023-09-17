#include "main.h"

void compathandcmd(char *filepath, char *cmd, char *token)
{
    _strcpy(filepath, token);
	_strcat(filepath, "/");
	_strcat(filepath, cmd);
}
