#include "main.h"

char *_strcat(char *destenation, char *source)
{
	int i, x;

	i = 0;
	while (destenation[i] != '\0')
	{
		i++;
	}
	x = 0;
	while (source[x] != '\0')
	{
		destenation[x + i] = source[x];
		x++;
	}
	destenation[i + x] = '\0';
	return (destenation);
}