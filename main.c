#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
	char *lineptr = NULL;
	size_t buffersize = 0;
	int line;
	char *av[1024];
	char *string_token;
	int count;
	pid_t execute;

	for(;;)
	{
		printf("$ ");
		line = getline(&lineptr, &buffersize, stdin);
		if (line == -1)
		{
			perror("Error");
		}
		string_token = strtok(lineptr, " \n");
		for (count = 0; string_token != NULL; count++)
		{
			av[count] = string_token;
			string_token = strtok(NULL, " \n");
		}
		av[count] = NULL;
		execute = execve(av[0], av, NULL);
		if (execute == -1)
		{
			perror("Error");
		}	
	}
}
