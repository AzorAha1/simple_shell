#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void error_message(char *ar, int *line_counter, char *current_argument, char *found_error)
{
	printf("%s: %d %s %s\n", ar, line_counter, current_argument, found_error);
}
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t buffersize = 0;
	int line;
	char *av[1024];
	char *string_token;
	int count, mode = isatty(0), counter = 0;
	(void)argc;
	pid_t c_process;

	for(;;)
	{
		if (atty == 1)
			write(1, "$ ", 2);
		line = getline(&lineptr, &buffersize, stdin);
		if (line == -1)
		{
			error_message(argv[0], counter, lineptr, "not found");
			exit(0);
		}
		string_token = strtok(lineptr, " \n");
		for (count = 0; string_token != NULL; count++)
		{
			av[count] = string_token;
			string_token = strtok(NULL, " \n");
		}
		av[count] = NULL;
		c_process = fork();
		if (c_process == 0)
		{
			int execute = execve(av[0], av, NULL);
			if (execute == 0)
			{
				write(1, lineptr, sizeof(lineptr));
				return (0);
			}
			if ((execute == -1))
			{
				perror("Error");
				return (-1);
			}
		}
		else if ((c_process != 0))
		{
			wait(NULL);
		}
	}
	free(lineptr);
	return (1);
}
