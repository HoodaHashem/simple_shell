#include "main.h"

/**
 * *_strdup - function creates a duplicate of the string
 * @str:string to duplicate
 * Return: a pointer
 * Description: function duplicate of the string
 */


char *_strdup(char *str)
{
	char *new_str = malloc(_strlen(str) + 1);

	if (new_str == NULL)
	{
	free(new_str);
	return (NULL);
	}
	_strcpy(new_str, str);
	return (new_str);
}
