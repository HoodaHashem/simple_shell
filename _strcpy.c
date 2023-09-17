#include "main.h"

char *_strcpy(char *clone, char *source)
{
    while (*source!= '\0')
    {
        *clone = *source;
        clone++;
        source++;
    }
    *clone = '\0';
    return clone;
}