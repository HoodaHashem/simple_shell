#include "main.h"

char* pathhandle(char* command) {

  char* path, *path_copy, *path_token, *file_path, *cmd_copy;

  struct stat buffer;

  if((cmd_copy = forbetty(command)) != NULL) {
    return cmd_copy;
  }

  path = getenvvars("PATH");

  if(path) {

    path_copy = _strdup(path);
    if(path_copy == NULL) {
      return NULL;
    }

    path_token = strtok(path_copy, ":");

    while(path_token != NULL) {

      file_path = malloc(strlen(path_token) + strlen(command) + 2);
      if(file_path == NULL) {
        free(path_copy);
        return NULL; 
      }

      compathandcmd(file_path, command, path_token);

      if(stat(file_path, &buffer) == 0) {

        cmd_copy = _strdup(file_path);
        free(path_copy);
        free(file_path);
        return cmd_copy;

      }

      free(file_path);
      file_path = NULL;

      path_token = strtok(NULL, ":");

    }

    free(path_copy);
    path_copy = NULL;

  }

  if(stat(command, &buffer) == 0) {
    
    cmd_copy = _strdup(command);
    return cmd_copy;

  }

  return NULL;

}

char* forbetty(char* cmd) {

  struct stat buf;

  if(cmd[0] == '/' || cmd[0] == '.') {

    if(stat(cmd, &buf) == 0) {
    
      return _strdup(cmd);

    }

  }

  return NULL;

}
