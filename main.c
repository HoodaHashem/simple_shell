#include "main.h"

int main(__attribute__((unused)) int argc, char *argv[])
{   
    int childstatus = 0, looping = 1, c, b = 1;
    size_t buffersize = BUFSIZ;
    char *command[20], *buffer = NULL, *cmd;
    ssize_t getlineread;

    signal(SIGINT, signalhandle);
    for (b = 1; looping; looping++)
    {
        if (!childstatus)
            prompt(0);
        else
            prompt(6000);
        getlineread = getline(&buffer, &buffersize, stdin);
        if (getlineread == EOF)
        {
            prompt(1);
            break;
        }
        buffer[getlineread - 1] = '\0', cmd = strtok(buffer, " \n");
        if (cmd != NULL)
        {
            c = 0;
            command[c++] = cmd;
            for(;c < 20; c++)
            {
                command[c] = strtok(NULL, "\n ");
                if (command[c] == NULL)
                    break;
            }
            if (_strcmp(command[0], "exit") == 0)
                free(buffer),exit(childstatus);
            b = bltin(command, buffer, argv[0], &looping);
            childstatus = b;
            command[c] = NULL;
            if (b)
                childstatus = _execve(command, buffer, argv[0], looping);
        }
    }
    free(buffer);
    return (childstatus);
}
