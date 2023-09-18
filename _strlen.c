#include "main.h"

/**
 * _strlen - function calculates the length of a string
 *@str:pointer
 *Return: i
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
	i++;
	}
	return (i);
}
