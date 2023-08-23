#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *lineptr = NULL, *fullpath, *string_token;
	size_t buffersize = 0, len, numalloc = 200;
	char **av;
	int count, mode = isatty(0), c_process, line, status = 0, ex = 0;
	(void)argc;

	for (;;)
	{
		if (mode == 1)
			write(1, "$ ", 2);
		line = getline(&lineptr, &buffersize, stdin);
		if (line == -1)
		{
			free(lineptr);
			exit(127);
		}
		lineptr[line - 1] = '\0';
		len = _strlen(lineptr);
		while (len > 0 && (lineptr[len - 1] == ' ' || lineptr[len - 1] == '\t'))
		{
			lineptr[--len] = '\0';
		}
		if (len == 0)
			continue;
		if (lineptr[0] != '\0')
		{
			av = (char **)malloc(sizeof(char *) * (numalloc + 1));
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
				exit(ex);
			}
			if (_strcmp(av[0], "env") == 0)
			{
				printenv();
				free(av);
				continue;
			}
			if (access(av[0], F_OK) == 0)
			{
				fullpath = av[0];
			}
			else
			{
				fullpath = getpath(av[0]);
			}
		
			if (fullpath)
			{
				c_process = fork();
				if (c_process == 0)
				{
					if (execve(fullpath, av, env) == -1)
					{
						perror(argv[0]);
						free(av);	
						exit(2);
					}
				}
				else
				{
					wait(&status);
					if (WIFEXITED(status))
					{
						ex = WEXITSTATUS(status);
					}
					free(av);
				}
			}
			else
			{
				perror(argv[0]);
				ex = 127;
				free(av);
			}
		}
	}
	return (ex);
}
