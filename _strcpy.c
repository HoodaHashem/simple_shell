#include "main.h"

/**
 * *_strcpy -  function copies the string pointed
 *@clone:pointer
 *@source:pointer
 *Return:clone
 */

char *_strcpy(char *clone, char *source)
{
	while (*source != '\0')
	{
	*clone = *source;
	clone++;
	source++;
	}
	*clone = '\0';
	return (clone);
}
