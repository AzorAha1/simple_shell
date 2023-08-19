#include "main.h"
char **printenv(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		write(1, env[i], strlen(env[i]));
		putchar('\n');
	}
	return (env);
}
