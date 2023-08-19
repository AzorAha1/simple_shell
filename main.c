#include "main.h"
int main(int argc, char **argv, char **env)
{
	char *lineptr = NULL;
	size_t buffersize = 0, len;
	int line, status;
	char **av;
	char *string_token;
	int count, mode = isatty(0), counter = 0;
	pid_t c_process;
	(void)argc;

	for(;;)
	{
		counter++;
		if (mode == 1)
			write(1, "$ ", 2);
	line = getline(&lineptr, &buffersize, stdin);
		lineptr[line - 1]  = '\0';
		if (line == -1)
		{
			free(lineptr);
			exit(0);
		}
		
		len = _strlen(lineptr);

		while (len > 0 && (lineptr[len - 1] == ' ' || lineptr[len - 1] == '\t'))
				lineptr[--len] = '\0';
		if (len == 0)
			continue;
		if (lineptr[0] != '\0')
		{
			av = (char **)malloc(sizeof(char *) * 1000);
			if (!av)
			{
				continue;
			}
			string_token = strtok(lineptr, " \n\t\r");
			for (count = 0; string_token != NULL; count++)
			{
				av[count] = string_token;
				string_token = strtok(NULL, " \n\t\r");
			}
			av[count] = NULL;
			if (_strcmp(av[0], "exit") == 0)
			{
				free(av);
				exit(2);
			}
			if (_strcmp(av[0], "env") == 0)
			{
				printenv(env);
				free(av);
				continue;
			}
			if (access(av[0], F_OK) == 0)
			{
				c_process = fork();
				if (c_process == 0)
				{
					if (execve(av[0], av, NULL) == -1)
					{
						perror(argv[0]);
						errno = 2;
						free(av);
						exit(1);
					}
				}
				else
				{
					wait(&status);
					free(av);
				}
			}
			else
			{
				perror(argv[0]);
				errno = 2;
				free(av);
			}
		}
	}
	return (0);
}
