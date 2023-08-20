#include "main.h"
char **printenv(char **env)
{
	int i;
	(void)env;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		putchar('\n');
	}
	return (environ);
}
