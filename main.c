#include <stdio.h>
int main()
{
	char *lineptr = NULL;
	size_t buffersize = 0;
	int line;

	for(;;)
	{
		printf("$ ");
		line = getline(&lineptr, &buffersize, stdin);
		if (line == -1)
		{
			perror("Error");
		}
	}
}
