#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *lineptr = NULL, *fullpath, *string_token;
	size_t buffersize = 0, len, numalloc = 200;
	char **av;
	char convert;
	int count, mode = isatty(0), c_process, line, status = 0, ex = 0, set = 0, counter = 0;
	(void)argc;

	for (;;)
	{
		counter++;
		if (mode == 1)
			write(1, "$ ", 2);
		line = getline(&lineptr, &buffersize, stdin);
		if (line == -1)
		{
			free(lineptr);
			exit(ex);
		}
		handle_comment(lineptr);	
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
				free(lineptr);
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
				set = 1;
			}
		
			if (fullpath)
			{
				c_process = fork();
				if (c_process == 0)
				{
					if (execve(fullpath, av, env) == -1)
					{
						convert = (counter + '0');
						errorm(argv[0], convert, av[0]);	
						free(av);	
						exit(2);
					}
				}
				else
				{
					wait(&status);
					if (WIFEXITED(status))
					{
						status = WEXITSTATUS(status);
					}
					free(av);
					if (set == 1)
						free(fullpath);
				}
			}
			else
			{
				convert = (counter + '0');
				errorm(argv[0], convert, av[0]);
				ex = 127;
				errno = 2;
				free(av);
			}
		}
	}
	return (ex);
}
