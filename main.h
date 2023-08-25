#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int _strcmp(const char *s1, const char *s2);
char **printenv();
size_t _strlen(const char *c);
extern char **environ;
char *getpath(char *input);
int print_char(char ch);
char *_strcpy(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
char *_strdup(char *str);
void _puts(char *ch);
void errorm(char *argv, int counter, char *ac)

#endif
