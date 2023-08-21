#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int _strcmp(const char *s1, const char *s2);
char **printenv(char **env);
size_t _strlen(const char *c);
extern char **environ;
char *getpath(char *input);
void print_char(char ch);
char *_strcpy(const char *s1, const char *s2);
char *_strcat(const char *s1, const char *s2);

#endif
