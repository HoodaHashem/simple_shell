#include "main.h"

char *getenvvars(char *path)
{
    size_t l = _strlen(path);
	int i;
    
    for (i = 0; environ[i] != NULL; i++)
    {
        if (_strncmp(path, environ[i], l) == 0 && environ[i][l] == '=')
        {
            return (environ[i] + l + 1);
        }
    }
    return (NULL);
}
