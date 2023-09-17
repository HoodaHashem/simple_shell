#include "main.h"

int _execve(char *arguments[], __attribute__((unused)) char *buffer, char *argv, int c)
{
    pid_t mypid;
    int childexit = 0;
    char *cmd;
    
    cmd = pathhandle(arguments[0]);
    if (cmd != NULL)
    {
        mypid = fork();
        if (mypid == -1)
        {
            perror("Error");
            _exit(-1);
        }
        if (mypid == 0)
        {
            if (execve(cmd, arguments, environ) == -1)
                perror("Error");
            _exit(127);
        }
        if (mypid > 0)
        {
            int status;

            waitpid(mypid, &status, 0);
            if (WIFEXITED(status))
                childexit = WEXITSTATUS(status);
        }
        free(cmd);
    }
    else
    {
        err_handl(argv, c, arguments[0]);
        childexit = 127;
    }
    return childexit;
}
