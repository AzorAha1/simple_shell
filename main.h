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
void error_message(char *argv, int counter, char *arr);

#endif
