#include "main.h"
/**
 * _getline - normal function
 * @buffer: normal lineptr
 * @n: normal n
 * @stream: normal stream
 * Return: gustavo
 */
ssize_t _getline(char **buffer, size_t *n, FILE *stream)
{
	ssize_t lol;

	lol = getline(buffer, n, stream);
	return (lol);
}
