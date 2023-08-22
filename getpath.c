#include "main.h"
char *getpath(char *input)
{
	int i;
	char *pathstrk; 
	char *fullpath;
	char *env_cpy;
	char *str_tok;
	
	for (i = 0; environ[i]; i++)
	{
		/*str_tok = strtok(environ[i], "=");*/
		env_cpy = strdup(environ[i]);
		str_tok = strtok(env_cpy, "=");
		if (_strcmp(str_tok, "PATH") == 0)
		{
			str_tok = strtok(NULL, "=");
			pathstrk = strtok(str_tok, ":");
			fullpath = malloc(_strlen(pathstrk) + _strlen(input) + 2);
			_strcpy(fullpath, pathstrk);
			_strcat(fullpath, "/");
			_strcat(fullpath, input);

			while(pathstrk != NULL)
			{
				fullpath = malloc(_strlen(pathstrk) + _strlen(input) + 2);
				pathstrk = strtok(NULL, ":");

				if (pathstrk)
				{
					_strcpy(fullpath, pathstrk);
					_strcat(fullpath, "/");
					_strcat(fullpath, input);
					if (access(fullpath, F_OK) == 0)
					{
						free(env_cpy);
						return (fullpath);
					}
				}
			}
			free(pathstrk);
			free(fullpath);
		}
		free(env_cpy);	
	}
	return (NULL);
}



