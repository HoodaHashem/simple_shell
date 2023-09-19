#include "main.h"

/**
 * is_delimiter - split the string into tokens
 *@c: charcter
 *@d:pointer
 *Return:0 or 1
 *
 */

int is_delimiter(char c, char *d)
{

	while (*d != '\0')	
	{
	      
	if (c == *d)
	{
	return (1);
	}
	d++;
	}
	return (0);
}


/**
 * *_strtok - function handling the tokens
 *@string: string
 *@d: delemiter
 *
 *Return:token
 *
 */


char *_strtok(char *string, char *d)
{
	static char *in;
	char *token;
	int i = 0;

	while (skip[i])

           {
        if (skip[i][0] == '#' && skip[i][1] == '\0')
        {
        break;
        }
              i++;
      skip[i] = _strtok(NULL, " \n");
           }

	if (string != NULL)
	{
	in = string;
	}
	if (in == NULL)
	{
	return (NULL);
	}
	while (is_delimiter(in[0], d) && in[0] != '\0')
	{
	in++;
	}
	if (in[0] == '\0')
	{
	return (NULL);
	}
	token = in;
	for (i = 0; in[i] != '\0'; i++)
	{
	if (is_delimiter(in[i], d))
	{
	in[i] = '\0';
	in = &in[i + 1];
	while (is_delimiter(in[0], d) && in[0] != '\0')
	{
	in++;
	}
	return (token);
	}

	}

	in = NULL;
	return (token);
}
