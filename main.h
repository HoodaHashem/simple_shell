#ifndef MAIN_H
#define MAIN_H


#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

#define READ_BUF_SIZE 1024
typedef struct {
	int descrip;
	char* str_buff;
	int type;
	int flag;
	int count_his;

} info_s;

extern char **environ;

char *forbetty2(char *cmd, char *p, char *pcpy, char *pk, char *fp, char *ccpy);
int _execve(char *arguments[], __attribute__((unused)) char *buffer, char *argv, int c);
int bltin(char *cmd[], int *f);
int err_handl(char *av, int ac, char *cmd);
void prompt(int status);
void signalhandle(int owrsignal);
char *inttostr(unsigned int n);
void arrayrev(char *s, int len);
int intlength(unsigned int n);
void sign_res(__attribute__((unused)) int sig_num);
void check_input(info_s *inf);
char* user_input(info_s *inf);
char *forbetty(char *cmd);
int _strncmp(const char *str1, const char *str2, size_t n);
int _strlen(char *str);
char *_strdup(char *str);
char *pathhandle(char *command);
char *_strcpy(char *clone, char *source);
int _strcmp(char *str1, char *str2);
char *_strcat(char *destenation, char *source);
void compathandcmd(char *filepath, char *cmd, char *token);
char *getenvvars(char *path);
int is_delimiter(char c, char *d);
char *_strtok(char *string, char *d);
ssize_t _getline(char **buffer, size_t *n, FILE *stream);
#endif
