#include "main.h"
char *getpath(char *input)
{
	int i;
	char *pathstrk;
	char *fullpath;
	
	for (i = 0; environ[i]; i++)
	{
		char *str_tok = strtok(environ[i], "=");
		if (_strcmp(str_tok, "PATH") == 0)
		{
			str_tok = strtok(NULL, "=");
			pathstrk = strtok(str_tok, ":");
			fullpath = malloc(sizeof(pathstrk) + sizeof(input));
			strcpy(fullpath, pathstrk);
			strcat(fullpath, "/");
			strcat(fullpath, input);

			while(pathstrk != NULL)
			{
				printf("%s\n", fullpath);
				free(fullpath);
				fullpath = (char *)malloc(sizeof(pathstrk) + sizeof(input));
				pathstrk = strtok(NULL, ":");
				if (pathstrk)
				{
					strcpy(fullpath, pathstrk);
					strcat(fullpath, "/");
					strcat(fullpath, input);
				}
			}
			free(fullpath);	
		}
	}
	return (NULL);
}
