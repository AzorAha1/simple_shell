#include "main.h"
char **printenv(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		write(1, env[i], _strlen(env[i]));
		putchar('\n');
	}
	return (env);
}
