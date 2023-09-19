#include "main.h"
/**
 * compathandcmd - normal function
 * @cmd: normal cmd
 * @token: normal token
 * @filepath: normal file path
 */
void compathandcmd(char *filepath, char *cmd, char *token)
{
	 _strcpy(filepath, token);
	_strcat(filepath, "/");
	_strcat(filepath, cmd);
}
