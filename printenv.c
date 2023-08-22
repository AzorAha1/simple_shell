#include "main.h"
/***
 * printenv - function name
 * @void: void argument
 * Description - function to print environment
 * Return: returns enviroment
*/
char **printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		print_char('\n');
	}
	return (environ);
}
