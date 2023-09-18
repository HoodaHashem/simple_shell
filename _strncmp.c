#include "main.h"

/**
 * _strncmp - compares up to n characters of the string
 *@str1:pointer
 *@str2:pointer
 *@n:value
 *Return:1
 *
 */


int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL)
		return (-1);
	for (i = 0; i < n && str2[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
	}
	return (0);
}
