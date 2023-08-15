#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	char *lineptr = NULL;
	size_t buffersize = 0;
	int line;
	char *av[1024];
	char *string_token;
	int count;
	pid_t c_process;

	for(;;)
	{
		printf("$ ");
		line = getline(&lineptr, &buffersize, stdin);
		if (line == -1)
		{
			perror("Error");
			return (-1);
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
			if ((execute = 0))
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
