#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
int _strcmp(char *s1, char *s2);
void error_message(char *ar, int line_counter, char *current_argument, char *found_error);
char **printenv(char **env);
#endif
