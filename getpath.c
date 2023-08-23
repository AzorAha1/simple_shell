#include "main.h"
/**
 * getpath - getpath function
 * @input: this takes the command input argument
 * Description - function to get path from enviroment
 * Return: returns path
*/
char *getpath(char *input)
{
	int i;
	char *pathstrk, *str_tok, *fullpath, *env_cpy;

	for (i = 0; environ[i]; i++)
	{
		env_cpy = _strdup(environ[i]);
		str_tok = strtok(env_cpy, "=");
		if (_strcmp(str_tok, "PATH") == 0)
		{
			str_tok = strtok(NULL, "=");
			pathstrk = strtok(str_tok, ":");
			fullpath = (char *)malloc(sizeof(pathstrk) + sizeof(input) + 2);
			strcpy(fullpath, pathstrk);
			strcat(fullpath, "/");
			strcat(fullpath, input);

			while (pathstrk != NULL)
			{
				fullpath = (char *)malloc(sizeof(pathstrk) + sizeof(input) + 2);
				if (pathstrk)
				{
					strcpy(fullpath, pathstrk);
					strcat(fullpath, "/");
					strcat(fullpath, input);
					if (access(fullpath, F_OK) == 0)
					{
						free(env_cpy);
						return (fullpath);
					}
					free(fullpath);
					pathstrk = strtok(NULL, ":");
				}
			}
			free(pathstrk);
		}
		free(env_cpy);
	}
	return (NULL);
}
