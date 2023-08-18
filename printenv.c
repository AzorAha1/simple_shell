#include <stdio.h>
#include <unistd.h>
char **printenv(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
	return env;
}
