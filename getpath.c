#include "main.h"
char *getpath(char *input)
{
	int i;
	char *pathstrk;
	(void)input;

	for (i = 0; environ[i]; i++)
	{
		char *str_tok = strtok(environ[i], "=");
		if (_strcmp(str_tok, "PATH") == 0)
		{
			str_tok = strtok(NULL, "=");
			pathstrk = strtok(str_tok, ":");

			while(pathstrk != NULL)
			{
				printf("%s\n", pathstrk);
				pathstrk = strtok(NULL, ":");
			}
		}
	}
	return (NULL);
}
